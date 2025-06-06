// extLight.cpp: 实现文件
//

#include "pch.h"
#include "afxdialogex.h"
#include "extLight.h"
#include "resource.h"
#include "fangli_io03.h"
#include "MFCApplication1Dlg.h"


// extLight 对话框
extern CMFCApplication1Dlg dlg;
IMPLEMENT_DYNAMIC(extLight, CDialogEx)



extLight::extLight(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_EXTLIGHT, pParent)
    , isconnect(_T("断开连接"))

    , port_init(_T("Port1"))
    , lednum(_T("20"))
    , ledtype(_T("NEO_RGB"))
    , segmentnum(_T("4"))
    , bright(_T("255"))

    , port_enable(_T("Port1"))

    , port_disable(_T("Port1"))

    , colorTable(_T("00 00 ff 00 00 ff 00 00 ff 00 00 00 ff ff ff 00 00 00 00 00 00 ff ff 00 ff ff 00 00 ff 00 ff 00 80 ff 40 00 00 30 ff 00 93 14 ff 00 10 10 10 00"))

    , port_mode(_T("Port1"))
    , segment(_T("0"))
    , ledstart(_T("0"))
    , ledend(_T("19"))
    , mode(_T("FX_MODE_STATIC"))
    , color1(_T("RED"))
    , color2(_T("GREEN"))
    , color3(_T("BLUE"))
    , speed(_T("1"))
    , option(_T("NO_OPTIONS"))

    , port_flashread(_T("Port1"))
    , block_flashread(_T("0"))

    , block_flashwrite(_T("0"))
    , flamenum(_T("2"))
    , linenum(_T("3"))
    , columnnum(_T("2"))
    , colorbuff(_T("00 00 ff 00 00 ff 00 00 ff 00 00 00 ff ff ff 00 00 00 00 00 00 ff ff 00 ff ff 00 00 ff 00 ff 00 80 ff 40 00 00 30 ff 00 93 14 ff 00 10 10 10 00"))
    , soft_version(_T(""))
    , hard_version(_T(""))
    , receive_hex(TRUE)
    , check_newline(TRUE)
{

}

extLight::~extLight()
{
}

void extLight::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, EDIT_CONNECT_STATUS, isconnect);
    DDX_CBString(pDX, COMBO_PORT_INIT, port_init);
    DDX_CBString(pDX, COMBO_PORT_ENABLE, port_enable);
    DDX_CBString(pDX, COMBO_PORT_DISABLE, port_disable);
    DDX_CBString(pDX, COMBO_PORT_MODE, port_mode);
    DDX_Text(pDX, EDIT_LEDNUM_INIT, lednum);
    DDX_Text(pDX, EDIT_SEGMENTNUM_INIT, segmentnum);
    DDX_Text(pDX, EDIT_BRIGHT_INIT, bright);
    DDX_Text(pDX, EDIT_COLORTABLE, colorTable);
    DDV_MaxChars(pDX, colorTable, 144);
    DDX_Text(pDX, EDIT_SEGMENT, segment);
    DDX_Text(pDX, EDIT_LEDSTART, ledstart);
    DDX_Text(pDX, EDIT_LEDEND, ledend);
    DDX_Text(pDX, EDIT_SPEED, speed);
    DDX_Text(pDX, EDIT_BLOCK_FLASHREAD, block_flashread);
    DDX_Text(pDX, EDIT_BLOCK_FLASHWRITE, block_flashwrite);
    DDX_Text(pDX, EDIT_FLAMENUM, flamenum);
    DDX_Text(pDX, EDIT_LINE, linenum);
    DDX_CBString(pDX, COMBO_LEDTYPE_INIT, ledtype);
    DDX_CBString(pDX, COMBO_MODE_MODE, mode);
    DDX_CBString(pDX, COMBO_COLOR1, color1);
    DDX_CBString(pDX, COMBO_COLOR2, color2);
    DDX_CBString(pDX, COMBO_COLOR3, color3);
    DDX_CBString(pDX, COMBO_OPTION, option);
    DDX_Text(pDX, EDIT_COLUMN, columnnum);
    DDX_Text(pDX, EDIT_COLORBUFF, colorbuff);
    DDV_MaxChars(pDX, colorTable, _ttoi(flamenum) * _ttoi(linenum) * _ttoi(columnnum) * 4 * 3);
    DDX_CBString(pDX, COMBO_PORT_FLASHREAD, port_flashread);
    DDX_Text(pDX, EDIT_SOFT, soft_version);
    DDX_Text(pDX, EDIT_HARD, hard_version);
    DDX_Check(pDX, IDC_CHECK_RECEIVE_HEX, receive_hex);
    DDX_Check(pDX, IDC_CHECK_NEWLINE2, check_newline);
    DDX_Control(pDX, IDC_RECEIVE_COM, idc_receive_com);
}

BOOL extLight::OnInitDialog()
{
    CDialogEx::OnInitDialog();
    SetTimer(3, 10, NULL); // 启动定时器1（1秒间隔）
    return TRUE;
}

void extLight::OnTimer(UINT_PTR nIDEvent)
{
    // TODO: 在此添加消息处理程序代码和/或调用默认值
    static int connect_old = 0;
    int connect = extLight_connect_state();

    if (nIDEvent == 3) // 替换YOUR_TIMER_ID为你的定时器ID
    {
        UpdateData(TRUE);
        if (connect_old != connect)
        {
            connect_old = connect;
            if (extLight_connect_state())
            {
                isconnect = _T("已经连接");
            }
            else
            {
                isconnect = _T("断开连接");
            } 
            UpdateData(FALSE);
            //idc_receive_com.SendMessage(WM_VSCROLL, SB_BOTTOM, 0);
            idc_receive_com.LineScroll(idc_receive_com.GetLineCount());
        }

        wchar_t wideStr[4096] = { 0 };
        size_t done_len;        
        static CString software_old = soft_version;
        static CString hardware_old = hard_version;
        mbstowcs_s(&done_len, wideStr, (char*)exLight_software_version(), 100);
        soft_version = wideStr;
        if (software_old != soft_version)
        {
            software_old = soft_version;
            UpdateData(FALSE);
        }
        mbstowcs_s(&done_len, wideStr, (char*)exLight_hardware_version(), 100);
        hard_version = wideStr;
        if (hardware_old != hard_version)
        {
            hardware_old = hard_version;
            UpdateData(FALSE);
        }

        // com转发接收数据
        static uint32_t no_data_count = 100;
        uint8_t com_buff[4096] = { 0 };
        uint16_t com_len = 0;
        CString temp;
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
            idc_receive_com.LineScroll(idc_receive_com.GetLineCount()-1);
        }
        else
        {
            no_data_count++;
            if (check_newline && (no_data_count == 5))
            {
                receive_com += _T("\r\n");
                //idc_receive_com.SetSel(-1, -1);                     // 移动光标到末尾
                idc_receive_com.SetWindowTextW(receive_com);
                idc_receive_com.LineScroll(idc_receive_com.GetLineCount()-1);
            }
        }
    }
    CDialogEx::OnTimer(nIDEvent);
}

void extLight::OnClose()
{
    // TODO: 在此添加消息处理程序代码和/或调用默认值
    father->ShowWindow(SW_SHOW);        // 隐藏窗口
    KillTimer(1);
    DestroyWindow(); // 销毁窗口
    CDialogEx::OnClose();
}

BEGIN_MESSAGE_MAP(extLight, CDialogEx)
    ON_WM_TIMER()
    ON_WM_CLOSE()
    ON_BN_CLICKED(BUTTON_INIT, &extLight::OnBnClickedInit)
    ON_BN_CLICKED(BUTTON_ENABLE, &extLight::OnBnClickedEnable)
    ON_BN_CLICKED(BUTTON_DISABLE, &extLight::OnBnClickedDisable)
    ON_BN_CLICKED(BUTTON_COLORTABLE, &extLight::OnBnClickedColortable)
    ON_BN_CLICKED(BUTTON_MODE_SET, &extLight::OnBnClickedModeSet)
    ON_BN_CLICKED(BUTTON_FLASH_READ, &extLight::OnBnClickedFlashRead)
    ON_BN_CLICKED(BUTTON_FLASH_READ2, &extLight::OnBnClickedFlashRead2)
    ON_BN_CLICKED(IDC_COM_RECEIVE_CLEAR2, &extLight::OnBnClickedComReceiveClear2)
END_MESSAGE_MAP()


// extLight 消息处理程序

void extLight::OnBnClickedInit()
{
    // TODO: 在此添加控件通知处理程序代码
    CString string;
    extLight_portEnum _port;
    uint8_t _lednum;
    uint8_t _ledtype;
    uint8_t _segmentnum;
    uint8_t _bright;

    string = port_init;
    if (string == _T("Port1"))
    {
        _port = Port1;
    }
    else if (string == _T("Port2"))
    { 
        _port = Port2;
    }
    else if (string == _T("Port3"))
    {
        _port = Port3;
    }
    else if (string == _T("Port4"))
    {
        _port = Port4;
    }
    else if (string == _T("Port5"))
    {
        _port = Port5;
    }
    else if (string == _T("Port6"))
    {
        _port = Port6;
    }
    else if (string == _T("Port7"))
    {
        _port = Port7;
    }
    else
    {
        return;
    }

    _lednum = _ttoi(lednum);

    string = ledtype;
    if (string == _T("NEO_RGB"))
    {
        _ledtype = NEO_RGB;
    }
    else if (string == _T("NEO_RBG"))
    {
        _ledtype = NEO_RBG;
    }
    else if (string == _T("NEO_GRB"))
    {
        _ledtype = NEO_GRB;
    }
    else if (string == _T("NEO_GBR"))
    {
        _ledtype = NEO_GBR;
    }
    else if (string == _T("NEO_BRG"))
    {
        _ledtype = NEO_BRG;
    }
    else if (string == _T("NEO_BGR"))
    {
        _ledtype = NEO_BGR;
    }
    else if (string == _T("NEO_WRGB"))
    {
        _ledtype = NEO_WRGB;
    }
    else if (string == _T("NEO_WRBG"))
    {
        _ledtype = NEO_WRBG;
    }
    else if (string == _T("NEO_WGRB"))
    {
        _ledtype = NEO_WGRB;
    }
    else if (string == _T("NEO_WGBR"))
    {
        _ledtype = NEO_WGBR;
    }
    else if (string == _T("NEO_WBRG"))
    {
        _ledtype = NEO_WBRG;
    }
    else if (string == _T("NEO_WBGR"))
    {
        _ledtype = NEO_WBGR;
    }
    else if (string == _T("NEO_RWGB"))
    {
        _ledtype = NEO_RWGB;
    }
    else if (string == _T("NEO_RWBG"))
    {
        _ledtype = NEO_RWBG;
    }
    else if (string == _T("NEO_RGWB"))
    {
        _ledtype = NEO_RGWB;
    }
    else if (string == _T("NEO_RGBW"))
    {
        _ledtype = NEO_RGBW;
    }
    else if (string == _T("NEO_RBWG"))
    {
        _ledtype = NEO_RBWG;
    }
    else if (string == _T("NEO_RBGW"))
    {
        _ledtype = NEO_RBGW;
    }
    else if (string == _T("NEO_GWRB"))
    {
        _ledtype = NEO_GWRB;
    }
    else if (string == _T("NEO_GWBR"))
    {
        _ledtype = NEO_GWBR;
    }
    else if (string == _T("NEO_GRWB"))
    {
        _ledtype = NEO_GRWB;
    }
    else if (string == _T("NEO_GRBW"))
    {
        _ledtype = NEO_GRBW;
    }
    else if (string == _T("NEO_GBWR"))
    {
        _ledtype = NEO_GBWR;

    }
    else if (string == _T("NEO_GBRW"))
    {
        _ledtype = NEO_GBRW;

    }
    else if (string == _T("NEO_BWRG"))
    {
        _ledtype = NEO_BWRG;

    }
    else if (string == _T("NEO_BWGR"))
    {
        _ledtype = NEO_BWGR;

    }
    else if (string == _T("NEO_BRWG"))
    {
        _ledtype = NEO_BRWG;

    }
    else if (string == _T("NEO_BRGW"))
    {
        _ledtype = NEO_BRGW;

    }
    else if (string == _T("NEO_BGWR"))
    {
        _ledtype = NEO_BGWR;

    }
    else if (string == _T("NEO_BGRW"))
    {
        _ledtype = NEO_BGRW;

    }
    else
    {
        return;
    }
    _segmentnum = _ttoi(segmentnum);
    _bright = _ttoi(bright);
    exLight_port_init(_port, _lednum, _ledtype, _segmentnum, _bright);
}

void extLight::OnBnClickedEnable()
{
    // TODO: 在此添加控件通知处理程序代码
    CString string;
    extLight_portEnum _port;
    string = port_enable;
    if (string == _T("Port1"))
    {
        _port = Port1;
    }
    else if (string == _T("Port2"))
    {
        _port = Port2;
    }
    else if (string == _T("Port3"))
    {
        _port = Port3;
    }
    else if (string == _T("Port4"))
    {
        _port = Port4;
    }
    else if (string == _T("Port5"))
    {
        _port = Port5;
    }
    else if (string == _T("Port6"))
    {
        _port = Port6;
    }
    else if (string == _T("Port7"))
    {
        _port = Port7;
    }
    else
    {
        return;
    }
    exLight_port_enable(_port);
}

void extLight::OnBnClickedDisable()
{
    // TODO: 在此添加控件通知处理程序代码
    CString string;
    extLight_portEnum _port;
    string = port_disable;
    if (string == _T("Port1"))
    {
        _port = Port1;
    }
    else if (string == _T("Port2"))
    {
        _port = Port2;
    }
    else if (string == _T("Port3"))
    {
        _port = Port3;
    }
    else if (string == _T("Port4"))
    {
        _port = Port4;
    }
    else if (string == _T("Port5"))
    {
        _port = Port5;
    }
    else if (string == _T("Port6"))
    {
        _port = Port6;
    }
    else if (string == _T("Port7"))
    {
        _port = Port7;
    }
    else
    {
        return;
    }
    exLight_port_disable(_port);
}

void extLight::OnBnClickedColortable()
{
    // TODO: 在此添加控件通知处理程序代码
    extLight_colorTableType _colorTable = { 0 };
    CString token;
    unsigned int value = 0;
    int pos = 0;
    int i = 0;
    while ((token = colorTable.Tokenize(_T(" "), pos)) != _T(""))
    {
        // 将字符串解析为十六进制整数
        if (swscanf_s(token, _T("%x"), &value) == 1) {
            if (value <= 0xFF) {
                ((uint8_t*)(&_colorTable))[i++] = static_cast<char>(value);
                if (i >= 48)
                {
                    break;
                }
            }
        }
    }
    extLight_colorTab_set(&_colorTable);
}

void extLight::OnBnClickedModeSet()
{
    // TODO: 在此添加控件通知处理程序代码
    extLight_portEnum _port;
    uint8_t _segment;
    uint8_t _ledstart;
    uint8_t _ledend;
    uint8_t _mode;
    uint8_t _color[3];
    uint8_t _speed;
    uint8_t _option;
    CString string;
    
    string = port_mode;
    if (string == _T("Port1"))
    {
        _port = Port1;
    }
    else if (string == _T("Port2"))
    {
        _port = Port2;
    }
    else if (string == _T("Port3"))
    {
        _port = Port3;
    }
    else if (string == _T("Port4"))
    {
        _port = Port4;
    }
    else if (string == _T("Port5"))
    {
        _port = Port5;
    }
    else if (string == _T("Port6"))
    {
        _port = Port6;
    }
    else if (string == _T("Port7"))
    {
        _port = Port7;
    }
    else
    {
        return;
    }
    _segment = _ttoi(segment);
    _ledstart = _ttoi(ledstart);
    _ledend = _ttoi(ledend);
    string = mode;
    if (string == _T("FX_MODE_STATIC"))
    {
        _mode = FX_MODE_STATIC;
    }
    else if (string == _T("FX_MODE_BLINK"))
    {
        _mode = FX_MODE_BLINK;
    }
    else if (string == _T("FX_MODE_BREATH"))
    {
        _mode = FX_MODE_BREATH;
    }
    else if (string == _T("FX_MODE_COLOR_WIPE"))
    {
        _mode = FX_MODE_COLOR_WIPE;
    }
    else if (string == _T("FX_MODE_COLOR_WIPE_INV"))
    {
        _mode = FX_MODE_COLOR_WIPE_INV;
    }
    else if (string == _T("FX_MODE_COLOR_WIPE_REV"))
    {
        _mode = FX_MODE_COLOR_WIPE_REV;
    }
    else if (string == _T("FX_MODE_COLOR_WIPE_REV_INV"))
    {
        _mode = FX_MODE_COLOR_WIPE_REV_INV;
    }
    else if (string == _T("FX_MODE_COLOR_WIPE_RANDOM"))
    {
        _mode = FX_MODE_COLOR_WIPE_RANDOM;
    }
    else if (string == _T("FX_MODE_RANDOM_COLOR"))
    {
        _mode = FX_MODE_RANDOM_COLOR;
    }
    else if (string == _T("FX_MODE_SINGLE_DYNAMIC"))
    {
        _mode = FX_MODE_SINGLE_DYNAMIC;
    }
    else if (string == _T("FX_MODE_MULTI_DYNAMIC"))
    {
        _mode = FX_MODE_MULTI_DYNAMIC;
    }
    else if (string == _T("FX_MODE_RAINBOW"))
    {
        _mode = FX_MODE_RAINBOW;
    }
    else if (string == _T("FX_MODE_RAINBOW_CYCLE"))
    {
        _mode = FX_MODE_RAINBOW_CYCLE;
    }
    else if (string == _T("FX_MODE_SCAN"))
    {
        _mode = FX_MODE_SCAN;
    }
    else if (string == _T("FX_MODE_DUAL_SCAN"))
    {
        _mode = FX_MODE_DUAL_SCAN;
    }
    else if (string == _T("FX_MODE_FADE"))
    {
        _mode = FX_MODE_FADE;
    }
    else if (string == _T("FX_MODE_THEATER_CHASE"))
    {
        _mode = FX_MODE_THEATER_CHASE;
    }
    else if (string == _T("FX_MODE_THEATER_CHASE_RAINBOW"))
    {
        _mode = FX_MODE_THEATER_CHASE_RAINBOW;
    }
    else if (string == _T("FX_MODE_RUNNING_LIGHTS"))
    {
        _mode = FX_MODE_RUNNING_LIGHTS;
    }
    else if (string == _T("FX_MODE_TWINKLE"))
    {
        _mode = FX_MODE_TWINKLE;
    }
    else if (string == _T("FX_MODE_TWINKLE_RANDOM"))
    {
        _mode = FX_MODE_TWINKLE_RANDOM;
    }
    else if (string == _T("FX_MODE_TWINKLE_FADE"))
    {
        _mode = FX_MODE_TWINKLE_FADE;
    }
    else if (string == _T("FX_MODE_TWINKLE_FADE_RANDOM"))
    {
        _mode = FX_MODE_TWINKLE_FADE_RANDOM;
    }
    else if (string == _T("FX_MODE_SPARKLE"))
    {
        _mode = FX_MODE_SPARKLE;
    }
    else if (string == _T("FX_MODE_FLASH_SPARKLE"))
    {
        _mode = FX_MODE_FLASH_SPARKLE;
    }
    else if (string == _T("FX_MODE_HYPER_SPARKLE"))
    {
    _mode = FX_MODE_HYPER_SPARKLE;
    }
    else if (string == _T("FX_MODE_STROBE"))
    {
    _mode = FX_MODE_STROBE;
    }
    else if (string == _T("FX_MODE_STROBE_RAINBOW"))
    {
        _mode = FX_MODE_STROBE_RAINBOW;
    }
    else if (string == _T("FX_MODE_MULTI_STROBE"))
    {
        _mode = FX_MODE_MULTI_STROBE;
    }
    else if (string == _T("FX_MODE_BLINK_RAINBOW"))
    {
        _mode = FX_MODE_BLINK_RAINBOW;
    }
    else if (string == _T("FX_MODE_CHASE_WHITE"))
    {
        _mode = FX_MODE_CHASE_WHITE;
    }
    else if (string == _T("FX_MODE_CHASE_COLOR"))
    {
        _mode = FX_MODE_CHASE_COLOR;
    }
    else if (string == _T("FX_MODE_CHASE_RANDOM"))
    {
        _mode = FX_MODE_CHASE_RANDOM;
    }
    else if (string == _T("FX_MODE_CHASE_RAINBOW"))
    {
        _mode = FX_MODE_CHASE_RAINBOW;
    }
    else if (string == _T("FX_MODE_CHASE_FLASH"))
    {
        _mode = FX_MODE_CHASE_FLASH;
    }
    else if (string == _T("FX_MODE_CHASE_FLASH_RANDOM"))
    {
        _mode = FX_MODE_CHASE_FLASH_RANDOM;
    }
    else if (string == _T("FX_MODE_CHASE_RAINBOW_WHITE"))
    {
        _mode = FX_MODE_CHASE_RAINBOW_WHITE;
    }
    else if (string == _T("FX_MODE_CHASE_BLACKOUT"))
    {
        _mode = FX_MODE_CHASE_BLACKOUT;
    }
    else if (string == _T("FX_MODE_CHASE_BLACKOUT_RAINBOW"))
    {
        _mode = FX_MODE_CHASE_BLACKOUT_RAINBOW;
    }
    else if (string == _T("FX_MODE_COLOR_SWEEP_RANDOM"))
    {
        _mode = FX_MODE_COLOR_SWEEP_RANDOM;
    }
    else if (string == _T("FX_MODE_RUNNING_COLOR"))
    {
        _mode = FX_MODE_RUNNING_COLOR;
    }
    else if (string == _T("FX_MODE_RUNNING_RED_BLUE"))
    {
        _mode = FX_MODE_RUNNING_RED_BLUE;
    }
    else if (string == _T("FX_MODE_RUNNING_RANDOM"))
    {
        _mode = FX_MODE_RUNNING_RANDOM;
    }
    else if (string == _T("FX_MODE_LARSON_SCANNER"))
    {
        _mode = FX_MODE_LARSON_SCANNER;
    }
    else if (string == _T("FX_MODE_COMET"))
    {
        _mode = FX_MODE_COMET;
    }
    else if (string == _T("FX_MODE_FIREWORKS"))
    {
        _mode = FX_MODE_FIREWORKS;
    }
    else if (string == _T("FX_MODE_FIREWORKS_RANDOM"))
    {
        _mode = FX_MODE_FIREWORKS_RANDOM;
    }
    else if (string == _T("FX_MODE_MERRY_CHRISTMAS"))
    {
        _mode = FX_MODE_MERRY_CHRISTMAS;
    }
    else if (string == _T("FX_MODE_FIRE_FLICKER"))
    {
        _mode = FX_MODE_FIRE_FLICKER;
    }
    else if (string == _T("FX_MODE_FIRE_FLICKER_SOFT"))
    {
        _mode = FX_MODE_FIRE_FLICKER_SOFT;
    }
    else if (string == _T("FX_MODE_FIRE_FLICKER_INTENSE"))
    {
        _mode = FX_MODE_FIRE_FLICKER_INTENSE;
    }
    else if (string == _T("FX_MODE_CIRCUS_COMBUSTUS"))
    {
        _mode = FX_MODE_CIRCUS_COMBUSTUS;
    }
    else if (string == _T("FX_MODE_HALLOWEEN"))
    {
        _mode = FX_MODE_HALLOWEEN;
    }
    else if (string == _T("FX_MODE_BICOLOR_CHASE"))
    {
        _mode = FX_MODE_BICOLOR_CHASE;
    }
    else if (string == _T("FX_MODE_TRICOLOR_CHASE"))
    {
        _mode = FX_MODE_TRICOLOR_CHASE;
    }
    else if (string == _T("FX_MODE_TWINKLEFOX"))
    {
        _mode = FX_MODE_TWINKLEFOX;
    }
    else if (string == _T("FX_MODE_BLOCK_DISSOLVE"))
    {
        _mode = FX_MODE_BLOCK_DISSOLVE;
    }
    else if (string == _T("FX_MODE_ICU"))
    {
        _mode = FX_MODE_ICU;
    }
    else if (string == _T("FX_MODE_DUAL_LARSON"))
    {
        _mode = FX_MODE_DUAL_LARSON;
    }
    else if (string == _T("FX_MODE_RUNNING_RANDOM2"))
    {
        _mode = FX_MODE_RUNNING_RANDOM2;
    }
    else if (string == _T("FX_MODE_FILLER_UP"))
    {
        _mode = FX_MODE_FILLER_UP;
    }
    else if (string == _T("FX_MODE_RAINBOW_LARSON"))
    {
        _mode = FX_MODE_RAINBOW_LARSON;
    }
    else if (string == _T("FX_MODE_TRIFADE"))
    {
        _mode = FX_MODE_TRIFADE;
    }
    else if (string == _T("FX_MODE_HEARTBEAT"))
    {
        _mode = FX_MODE_HEARTBEAT;
    }
    else if (string == _T("FX_MODE_VU_METER"))
    {
        _mode = FX_MODE_VU_METER;
    }
    else if (string == _T("FX_MODE_BITS"))
    {
        _mode = FX_MODE_BITS;
    }
    else if (string == _T("FX_MODE_MULTI_COMET"))
    {
        _mode = FX_MODE_MULTI_COMET;
    }
    else if (string == _T("FX_MODE_FLIPBOOK"))
    {
        _mode = FX_MODE_FLIPBOOK;
    }
    else if (string == _T("FX_MODE_POPCORN"))
    {
        _mode = FX_MODE_POPCORN;
    }
    else if (string == _T("FX_MODE_OSCILLATOR"))
    {
        _mode = FX_MODE_OSCILLATOR;
    }
    else if (string == _T("UFX_MODE_COMET1"))
    {
        _mode = UFX_MODE_COMET1;
    }
    else if (string == _T("UFX_MODE_COMET2"))
    {
        _mode = UFX_MODE_COMET2;
    }
    else if (string == _T("UFX_MODE_COMET3"))
    {
        _mode = UFX_MODE_COMET3;
    }
    else 
    {
        return;
    }
    
    CString* color[3] = { &color1,&color2,&color3 };
    for (uint8_t i = 0; i < 3; i++)
    {
        string = *color[i];
        if (string == _T("RED"))
        {
            _color[i] = RED;
        }
        else if (string == _T("GREEN"))
        {
            _color[i] = GREEN;
        }
        else if (string == _T("BLUE"))
        {
            _color[i] = BLUE;
        }
        else if (string == _T("WHITE"))
        {
            _color[i] = WHITE;
        }
        else if (string == _T("BLACK"))
        {
            _color[i] = BLACK;
        }
        else if (string == _T("YELLOW"))
        {
            _color[i] = YELLOW;
        }
        else if (string == _T("CYAN"))
        {
            _color[i] = CYAN;
        }
        else if (string == _T("MAGENTA"))
        {
            _color[i] = MAGENTA;
        }
        else if (string == _T("PURPLE"))
        {
            _color[i] = PURPLE;
        }
        else if (string == _T("ORANGE"))
        {
            _color[i] = ORANGE;
        }
        else if (string == _T("PINK"))
        {
            _color[i] = PINK;
        }
        else if (string == _T("GRAY"))
        {
            _color[i] = GRAY;
        }
        else
        {
            return;
        }
    }
    _speed = _ttoi(speed);
    string = option;
    if (string == _T("NO_OPTIONS"))
    {
        _option = NO_OPTIONS;
    }
    else if (string == _T("REVERSE"))
    {
        _option = REVERSE;
    }
    else if (string == _T("FADE_XFAST"))
    {
        _option = FADE_XFAST;
    }
    else if (string == _T("FADE_FAST"))
    {
        _option = FADE_FAST;
    }
    else if (string == _T("FADE_MEDIUM"))
    {
        _option = FADE_MEDIUM;
    }
    else if (string == _T("FADE_SLOW"))
    {
        _option = FADE_SLOW;
    }
    else if (string == _T("FADE_XSLOW"))
    {
        _option = FADE_XSLOW;
    }
    else if (string == _T("FADE_XXSLOW"))
    {
        _option = FADE_XXSLOW;
    }
    else if (string == _T("FADE_GLACIAL"))
    {
        _option = FADE_GLACIAL;
    }
    else if (string == _T("GAMMA"))
    {
        _option = GAMMA;
    }
    else if (string == _T("SIZE_SMALL"))
    {
        _option = SIZE_SMALL;
    }
    else if (string == _T("SIZE_MEDIUM"))
    {
        _option = SIZE_MEDIUM;
    }
    else if (string == _T("SIZE_LARGE"))
    {
        _option = SIZE_LARGE;
    }
    else if (string == _T("SIZE_XLARGE"))
    {
        _option = SIZE_XLARGE;
    }
    else 
    {
       return;
    }
    extLight_mode_set(_port, _segment, _ledstart, _ledend, _mode,
        _color[0], _color[1], _color[2], _speed, _option);
}

void extLight::OnBnClickedFlashRead()
{
    // TODO: 在此添加控件通知处理程序代码
    extLight_portEnum _port;
    uint8_t _block;
    CString string;

    string = port_flashread;
    if (string == _T("Port1"))
    {
        _port = Port1;
    }
    else if (string == _T("Port2"))
    {
        _port = Port2;
    }
    else if (string == _T("Port3"))
    {
        _port = Port3;
    }
    else if (string == _T("Port4"))
    {
        _port = Port4;
    }
    else if (string == _T("Port5"))
    {
        _port = Port5;
    }
    else if (string == _T("Port6"))
    {
        _port = Port6;
    }
    else if (string == _T("Port7"))
    {
        _port = Port7;
    }
    else
    {
        return;
    }
    _block = _ttoi(block_flashread);
    extLight_flash_read(_port, _block);
}

void extLight::OnBnClickedFlashRead2()
{
    // TODO: 在此添加控件通知处理程序代码
    uint8_t _block;
    uint8_t _flame;
    uint8_t _line;
    uint8_t _column;


    _block = _ttoi(block_flashwrite);
    _flame = _ttoi(flamenum);
    _line = _ttoi(linenum);
    _column = _ttoi(columnnum);

    uint32_t color_size = (uint32_t)_flame * _line * _column;
    if (color_size > 0xffff)
    {
        return;
    }
    extLight_colorType* _colorbuff = new extLight_colorType[color_size]{};

    CString token;
    unsigned int value = 0;
    int pos = 0;
    unsigned int i = 0;
    while ((token = colorbuff.Tokenize(_T(" "), pos)) != _T(""))
    {
        // 将字符串解析为十六进制整数
        if (swscanf_s(token, _T("%x"), &value) == 1) {
            if (value <= 0xFF) {
                ((char*)(_colorbuff))[i++] = static_cast<char>(value);
                if (i >= color_size * 4)
                {
                    break;
                }
            }
        }
    }
   extLight_flash_save(_block, _flame, _line, _column, _colorbuff);
   delete[] _colorbuff;
}

void extLight::OnBnClickedComReceiveClear2()
{
    // TODO: 在此添加控件通知处理程序代码
    receive_com = _T("");
    idc_receive_com.SetWindowTextW(receive_com);
}
