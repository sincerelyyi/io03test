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
	DDV_MaxChars(pDX, data_, 23);
	DDX_Text(pDX, IDC_EDIT8, receive);
}

BOOL CAN::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetTimer(1, 10, NULL); // 启动定时器1（1秒间隔）
	return TRUE;
}


BEGIN_MESSAGE_MAP(CAN, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CAN::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CAN::OnBnClickedButton2)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON3, &CAN::OnBnClickedButton3)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


void CAN::OnBnClickedButton1()
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



void CAN::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	uint32_t _ID;
	uint8_t _LEN;
	uint8_t _DATA[8] = { 0 };
	CString token;
	unsigned int value = 0;
	int pos = 0;
	int i = 0;
	UpdateData(TRUE);
	_ID = _ttoi(id_);
	_LEN = _ttoi(len);

	while ((token = data_.Tokenize(_T(" "), pos)) != _T(""))
	{
		// 将字符串解析为十六进制整数
		if (swscanf_s(token, _T("%x"),&value) == 1) {
			if (value <= 0xFF) {
				_DATA[i++] = static_cast<char>(value);
			}
		}
	}
	can_send(_ID, _LEN, _DATA);
	UpdateData(FALSE);
}

void CAN::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nIDEvent == 1) // 替换YOUR_TIMER_ID为你的定时器ID  
	{
		CAN_dataType data;
		CString temp,message;
		static uint32_t number = 0;
		while (can_receive(&data))
		{
			UpdateData(TRUE);
			if (receive.GetLength() > 10 * 1024)
			{
				receive.Truncate(10 * 1024);
			}
			message.Format(_T("\r\n收到的第%d条信息:      ID:%d    LEN:%d    DATA:"),++number, data.id, data.len);
			for (uint8_t i = 0; i < data.len; i++)
			{
				temp.Format(_T("%.2X "), data.data[i]);
				message += temp;
			}
			message += _T("\r\n");
			receive.Insert(0, message);
			UpdateData(FALSE);
		}

	}
	CDialogEx::OnTimer(nIDEvent);
}

void CAN::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	receive = _T("");
	UpdateData(FALSE);
}

void CAN::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	father->ShowWindow(SW_SHOW);        // 隐藏窗口
	KillTimer(1);
    DestroyWindow(); // 销毁窗口
	CDialogEx::OnClose();
}
