// CAN.cpp: 实现文件
//

#include "pch.h"
#include "afxdialogex.h"
#include "CAN.h"
#include "resource.h"
#include "fangli_io03.h"
#include "MFCApplication1Dlg.h"


// CAN 对话框
extern CMFCApplication1Dlg dlg;
IMPLEMENT_DYNAMIC(CAN, CDialogEx)

CAN::CAN(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_DIALOG_CAN, pParent)
    , baud(_T("500000"))
    , bs1(_T("8"))
    , bs2(_T("3"))
    , sjw(_T("1"))
    , id_(_T("0"))
    , len(_T("8"))
    , data_(_T("a1 a2 a3 a4 01 02 03 04"))
    , receive(_T(""))
    , baud_com(_T("115200"))
    , bits(_T("8"))
    , parity(_T("none"))
    , stop(_T("1"))
    , send_hex(TRUE)
    , receive_hex(TRUE)
    , send_com(_T("a1 a2 a3 a4 01 02 03 04"))
    , check_newline(TRUE)
{

}

CAN::~CAN()
{

}

void CAN::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_BAUD, baud);
    DDV_MaxChars(pDX, baud, 7);
    DDX_Text(pDX, IDC_BS1, bs1);
    DDV_MaxChars(pDX, bs1, 2);
    DDX_Text(pDX, IDC_BS2, bs2);
    DDV_MaxChars(pDX, bs2, 1);
    DDX_Text(pDX, IDC_SJW, sjw);
    DDV_MaxChars(pDX, sjw, 1);
    DDX_Text(pDX, IDC_ID, id_);
    DDV_MaxChars(pDX, id_, 4);
    DDX_Text(pDX, IDC_LEN, len);
    DDV_MaxChars(pDX, len, 1);
    DDX_Text(pDX, IDC_DATA, data_);
    DDV_MaxChars(pDX, data_, 24);
    DDX_Text(pDX, IDC_EDIT8, receive);
    DDX_CBString(pDX, IDC_COMBO_BAUD, baud_com);
    DDV_MaxChars(pDX, baud_com, 6);
    DDX_CBString(pDX, IDC_COMBO_BITS, bits);
    DDX_CBString(pDX, IDC_COMBO_PARIT, parity);
    DDX_CBString(pDX, IDC_COMBO_STOP, stop);
    DDX_Check(pDX, IDC_CHECK_SEND_HEX, send_hex);
    DDX_Check(pDX, IDC_CHECK_RECEIVE_HEX, receive_hex);
    DDX_Text(pDX, IDC_SEND_COM, send_com);
    DDX_Control(pDX, IDC_RECEIVE_COM, idc_receive_com);
    DDX_Check(pDX, IDC_CHECK_NEWLINE, check_newline);
}

BOOL CAN::OnInitDialog()
{
    CDialogEx::OnInitDialog();
    SetTimer(1, 10, NULL); // 启动定时器1（1秒间隔）
    return TRUE;
}


BEGIN_MESSAGE_MAP(CAN, CDialogEx)
    ON_WM_TIMER()
    ON_WM_CLOSE()
    ON_BN_CLICKED(IDC_CAN_SET, &CAN::OnBnClickedCanSet)
    ON_BN_CLICKED(IDC_CAN_SEND, &CAN::OnBnClickedCanSend)
    ON_BN_CLICKED(IDC_CAN_RECEIVE_CLEAR, &CAN::OnBnClickedCanReceiveClear)
    ON_BN_CLICKED(IDC_COM_SET, &CAN::OnBnClickedComSet)
    ON_BN_CLICKED(IDC_COM_SEND_CLEAR, &CAN::OnBnClickedComSendClear)
    ON_BN_CLICKED(IDC_COM_SEND, &CAN::OnBnClickedComSend)
    ON_BN_CLICKED(IDC_COM_RECEIVE_CLEAR, &CAN::OnBnClickedComReceiveClear)
END_MESSAGE_MAP()

void CAN::OnTimer(UINT_PTR nIDEvent)
{
    // TODO: 在此添加消息处理程序代码和/或调用默认值
    static uint32_t no_data_count = 100;
    if (nIDEvent == 1) // 替换YOUR_TIMER_ID为你的定时器ID
    {
        UpdateData(TRUE);
        // can接收数据
        CAN_dataType data;
        CString temp, message;
        static uint32_t number = 0;
        while (can_receive(&data))
        {

            if (receive.GetLength() > 10 * 1024)
            {
                receive.Truncate(10 * 1024);
            }
            message.Format(_T("\r\n收到的第%d条信息:      ID:%d    LEN:%d    DATA:"), ++number, data.id, data.len);
            for (uint8_t i = 0; i < data.len; i++)
            {
                temp.Format(_T("%.2X "), data.data[i]);
                message += temp;
            }
            message += _T("\r\n");
            receive.Insert(0, message);
            UpdateData(FALSE);
        }
        // com转发接收数据
        wchar_t wideStr[4096] = { 0 };
        size_t done_len;
        uint8_t com_buff[4096] = { 0 };
        uint16_t com_len = 0;
        com_len = uartForward_receive(4096, com_buff);
        if (receive_com.GetLength() > 10 * 1024)
        {
            receive_com.Delete(0, receive_com.GetLength() - 10 * 1024);
        }
        if (com_len)
        {
            no_data_count = 0;
            if (receive_hex)
            {
                for (uint16_t i = 0; i < com_len; i++)
                {
                    temp.Format(_T("%.2X "), com_buff[i]);
                    receive_com += temp;
                }
            }
            else
            {
                mbstowcs_s(&done_len, wideStr, (char*)com_buff, com_len);
                receive_com += wideStr;
            }
            //idc_receive_com.SetSel(-1, -1);                     // 移动光标到末尾
            idc_receive_com.SetWindowTextW(receive_com);
            idc_receive_com.LineScroll(idc_receive_com.GetLineCount() - 1);
        }
        else
        {
            no_data_count++;
            if (check_newline && (no_data_count == 5))
            {
                receive_com += _T("\r\n");
                //idc_receive_com.SetSel(-1, -1);                     // 移动光标到末尾
                idc_receive_com.SetWindowTextW(receive_com);
                idc_receive_com.LineScroll(idc_receive_com.GetLineCount() - 1);
            }
        }
    }
    CDialogEx::OnTimer(nIDEvent);
}

void CAN::OnClose()
{
    // TODO: 在此添加消息处理程序代码和/或调用默认值
    father->ShowWindow(SW_SHOW);        // 隐藏窗口
    KillTimer(1);
    DestroyWindow(); // 销毁窗口
    CDialogEx::OnClose();
}

void CAN::OnBnClickedCanSet()
{
    // TODO: 在此添加控件通知处理程序代码
    uint32_t _baud;
    uint8_t _BS1, _BS2, _SJW;
    UpdateData(TRUE);
    _baud = _ttoi(baud);
    _BS1 = _ttoi(bs1);
    _BS2 = _ttoi(bs2);
    _SJW = _ttoi(sjw);
    baud.Format(_T(" %d"), set_can_init(_baud, _BS1, _BS2, _SJW));
    UpdateData(FALSE);

}

void CAN::OnBnClickedCanSend()
{
    // TODO: 在此添加控件通知处理程序代码
    uint32_t _ID;
    uint8_t _LEN;
    uint8_t _DATA[8] = { 0 };
    CString token;
    unsigned int value = 0;
    int pos = 0;
    unsigned int i = 0;
    UpdateData(TRUE);
    _ID = _ttoi(id_);
    _LEN = _ttoi(len);

    while ((token = data_.Tokenize(_T(" "), pos)) != _T(""))
    {
        // 将字符串解析为十六进制整数
        if (swscanf_s(token, _T("%x"),&value) == 1) {
            if (value <= 0xFF) {
                _DATA[i++] = static_cast<char>(value);
                if (i >= 8)
                {
                    break;
                }
            }
        }
    }
    can_send(_ID, _LEN, _DATA);
    UpdateData(FALSE);
}



void CAN::OnBnClickedCanReceiveClear()
{
    // TODO: 在此添加控件通知处理程序代码
    UpdateData(TRUE);
    receive = _T("");
    UpdateData(FALSE);
}


void CAN::OnBnClickedComSet()
{
    // TODO: 在此添加控件通知处理程序代码
    uint32_t _baud;
    uint8_t _bits, _parity, _stop;

    UpdateData(TRUE);
    _baud = _ttoi(baud_com);
    _bits = _ttoi(bits);
    _stop = _ttoi(stop);
    if (parity == _T("none"))
    {
        _parity = 0;
    }
    else if (parity == _T("even"))
    {
        _parity = 1;
    }
    else if (parity == _T("odd"))
    {
        _parity = 2;
    }
    else
    {
        _parity = 0;
    }
    set_uartForward_init(_baud, _bits, _parity, _stop);
    UpdateData(FALSE);
}

void CAN::OnBnClickedComSendClear()
{
    // TODO: 在此添加控件通知处理程序代码
    UpdateData(TRUE);
    send_com = _T("");
    UpdateData(FALSE);
}

void CAN::OnBnClickedComSend()
{
    // TODO: 在此添加控件通知处理程序代码
    uint8_t _DATA[4096] { 0 };
    CString token;
    unsigned int value = 0;
    int pos = 0;
    unsigned int i = 0;
    UpdateData(TRUE);
    if (send_hex)
    {
        while ((token = send_com.Tokenize(_T(" "), pos)) != _T(""))
        {
            // 将字符串解析为十六进制整数
            if (swscanf_s(token, _T("%x"), &value) == 1) {
                if (value <= 0xFF) {
                    _DATA[i++] = static_cast<char>(value);
                    if (i >= 4096)
                    {
                        break;
                    }
                }
            }
        }
        if (i > 4096)
        {
            i = 4096;
        }
        uartForward_send(i, _DATA);
    }
    else
    {
        i = send_com.GetLength();
        if (i > 4096)
        {
            i = 4096;
        }
        WideCharToMultiByte(CP_ACP, 0, send_com.GetString(), -1, (char *)_DATA, i, NULL, NULL);
        uartForward_send(i, _DATA);
    }

    UpdateData(FALSE);
}

void CAN::OnBnClickedComReceiveClear()
{
    // TODO: 在此添加控件通知处理程序代码
    receive_com = _T("");
    idc_receive_com.SetWindowTextW(receive_com);
}
