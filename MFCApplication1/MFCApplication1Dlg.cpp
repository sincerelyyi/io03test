
// MFCApplication1Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include "SerialCom.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

SerialCom serialCom;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 对话框



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, progress1);
	DDX_Control(pDX, IDC_PROGRESS2, progress2);
	DDX_Control(pDX, IDC_PROGRESS3, progress3);
	DDX_Control(pDX, IDC_PROGRESS4, progress4);
	DDX_Control(pDX, IDC_PROGRESS5, progress5);
	DDX_Control(pDX, IDC_PROGRESS6, progress6);
	DDX_Control(pDX, IDC_PROGRESS7, progress7);
	DDX_Control(pDX, IDC_PROGRESS8, progress8);
	DDX_Control(pDX, IDC_CHECK1, check1);
	DDX_Control(pDX, IDC_CHECK2, check2);
	DDX_Control(pDX, IDC_CHECK3, check3);
	DDX_Control(pDX, IDC_CHECK4, check4);
	DDX_Control(pDX, IDC_CHECK5, check5);
	DDX_Control(pDX, IDC_CHECK6, check6);
	DDX_Control(pDX, IDC_CHECK7, check7);
	DDX_Control(pDX, IDC_CHECK8, check8);
	DDX_Control(pDX, IDC_CHECK9, check9);
	DDX_Control(pDX, IDC_CHECK10, check10);
	DDX_Control(pDX, IDC_CHECK11, check11);
	DDX_Control(pDX, IDC_CHECK12, check12);
	DDX_Control(pDX, IDC_CHECK13, check13);
	DDX_Control(pDX, IDC_CHECK14, check14);
	DDX_Control(pDX, IDC_CHECK15, check15);
	DDX_Control(pDX, IDC_CHECK16, check16);
	DDX_Control(pDX, IDC_CHECK17, check17);
	DDX_Control(pDX, IDC_CHECK18, check18);
	DDX_Control(pDX, IDC_SLIDER1, slider1);
	DDX_Control(pDX, IDC_SLIDER2, slider2);
	DDX_Control(pDX, IDC_SLIDER3, slider3);
	DDX_Control(pDX, IDC_SLIDER4, slider4);
	DDX_Control(pDX, IDC_SLIDER5, slider5);
	DDX_Control(pDX, IDC_SLIDER6, slider6);
	DDX_Control(pDX, IDC_SLIDER7, slider7);
	DDX_Control(pDX, IDC_SLIDER8, slider8);
	DDX_Control(pDX, IDC_SLIDER9, slider9);
	DDX_Control(pDX, IDC_SLIDER10, slider10);
	DDX_Control(pDX, IDC_SLIDER11, slider11);
	DDX_Control(pDX, IDC_SLIDER12, slider12);
	DDX_Control(pDX, IDC_SLIDER13, slider13);
	DDX_Control(pDX, IDC_SLIDER14, slider14);
	DDX_Control(pDX, IDC_SLIDER15, slider15);
	DDX_Control(pDX, IDC_SLIDER16, slider16);
	DDX_Control(pDX, IDC_SLIDER17, slider17);
	DDX_Control(pDX, IDC_SLIDER18, slider18);
	DDX_Control(pDX, IDC_SLIDER19, slider19);
	DDX_Control(pDX, IDC_SLIDER20, slider20);
	DDX_Control(pDX, IDC_SLIDER21, slider21);
	DDX_Control(pDX, IDC_SLIDER22, slider22);
	DDX_Control(pDX, IDC_SLIDER23, slider23);
	DDX_Control(pDX, IDC_SLIDER24, slider24);
	DDX_Control(pDX, IDC_SLIDER25, slider25);
	DDX_Control(pDX, IDC_SLIDER26, slider26);
	DDX_Control(pDX, IDC_SLIDER27, slider27);
	DDX_Control(pDX, IDC_SLIDER28, slider28);
	DDX_Control(pDX, IDC_SLIDER29, slider29);
	DDX_Control(pDX, IDC_SLIDER30, slider30);
	DDX_Control(pDX, IDC_SLIDER31, slider31);
	DDX_Control(pDX, IDC_SLIDER32, slider32);
	DDX_Control(pDX, IDC_SLIDER33, slider33);
	DDX_Control(pDX, IDC_SLIDER34, slider34);
	DDX_Control(pDX, IDC_SLIDER35, slider35);
	DDX_Control(pDX, IDC_SLIDER36, slider36);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	//ShowWindow(SW_MAXIMIZE);

	//ShowWindow(SW_MINIMIZE);

	// TODO: 在此添加额外的初始化代码
	// 设置定时器，假设定时器ID为1，时间间隔为100毫秒（1秒）  
	SetTimer(1, 100, NULL);
	progress1.SetRange(0, 255);
	progress2.SetRange(0, 255);
	progress3.SetRange(0, 255);
	progress4.SetRange(0, 255);
	progress5.SetRange(0, 255);
	progress6.SetRange(0, 255);
	progress7.SetRange(0, 255);
	progress8.SetRange(0, 255);
	slider1.SetRange(0, 7);
	slider2.SetRange(0, 7);
	slider3.SetRange(0, 7);
	slider4.SetRange(0, 7);
	slider5.SetRange(0, 7);
	slider6.SetRange(0, 7);
	slider7.SetRange(0, 7);
	slider8.SetRange(0, 7);
	slider9.SetRange(0, 7);
	slider10.SetRange(0, 7);
	slider11.SetRange(0, 7);
	slider12.SetRange(0, 7);
	slider13.SetRange(0, 7);
	slider14.SetRange(0, 7);
	slider15.SetRange(0, 7);
	slider16.SetRange(0, 7);
	slider17.SetRange(0, 7);
	slider18.SetRange(0, 7);
	slider19.SetRange(0, 15);
	slider20.SetRange(0, 15);
	slider21.SetRange(0, 15);
	slider22.SetRange(0, 15);
	slider23.SetRange(0, 15);
	slider24.SetRange(0, 15);
	slider25.SetRange(0, 15);
	slider26.SetRange(0, 15);
	slider27.SetRange(0, 15);
	slider28.SetRange(0, 15);
	slider29.SetRange(0, 15);
	slider30.SetRange(0, 15);
	slider31.SetRange(0, 15);
	slider32.SetRange(0, 15);
	slider33.SetRange(0, 15);
	slider34.SetRange(0, 15);
	slider35.SetRange(0, 15);
	slider36.SetRange(0, 15);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCApplication1Dlg::OnTimer(UINT_PTR nIDEvent)
{
	static int a;
	if (nIDEvent == 1) // 替换YOUR_TIMER_ID为你的定时器ID  
	{
		// 执行与定时器到期相关的操作 
		progress1.SetPos(serialCom.get_adc(0));
		progress2.SetPos(serialCom.get_adc(1));
		progress3.SetPos(serialCom.get_adc(2));
		progress4.SetPos(serialCom.get_adc(3));
		progress5.SetPos(serialCom.get_adc(4));
		progress6.SetPos(serialCom.get_adc(5));
		progress7.SetPos(serialCom.get_adc(6));
		progress8.SetPos(serialCom.get_adc(7));
		serialCom.set_pwm(0, check1.GetCheck(), 7 - slider1.GetPos(), 15 - slider19.GetPos());
		serialCom.set_pwm(1, check2.GetCheck(), 7 - slider2.GetPos(), 15 - slider20.GetPos());
		serialCom.set_pwm(2, check3.GetCheck(), 7 - slider3.GetPos(), 15 - slider21.GetPos());
		serialCom.set_pwm(3, check4.GetCheck(), 7 - slider4.GetPos(), 15 - slider22.GetPos());
		serialCom.set_pwm(4, check5.GetCheck(), 7 - slider5.GetPos(), 15 - slider23.GetPos());
		serialCom.set_pwm(5, check6.GetCheck(), 7 - slider6.GetPos(), 15 - slider24.GetPos());
		serialCom.set_pwm(6, check7.GetCheck(), 7 - slider7.GetPos(), 15 - slider25.GetPos());
		serialCom.set_pwm(7, check8.GetCheck(), 7 - slider8.GetPos(), 15 - slider26.GetPos());
		serialCom.set_pwm(8, check9.GetCheck(), 7 - slider9.GetPos(), 15 - slider27.GetPos());
		serialCom.set_pwm(9, check10.GetCheck(), 7 - slider10.GetPos(), 15 - slider28.GetPos());
		serialCom.set_pwm(10, check11.GetCheck(), 7 - slider11.GetPos(), 15 - slider29.GetPos());
		serialCom.set_pwm(11, check12.GetCheck(), 7 - slider12.GetPos(), 15 - slider30.GetPos());
		serialCom.set_pwm(12, check13.GetCheck(), 7 - slider13.GetPos(), 15 - slider31.GetPos());
		serialCom.set_pwm(13, check14.GetCheck(), 7 - slider14.GetPos(), 15 - slider32.GetPos());
		serialCom.set_pwm(14, check15.GetCheck(), 7 - slider15.GetPos(), 15 - slider23.GetPos());
		serialCom.set_pwm(15, check16.GetCheck(), 7 - slider16.GetPos(), 15 - slider34.GetPos());
		serialCom.set_pwm(16, check17.GetCheck(), 7 - slider17.GetPos(), 15 - slider35.GetPos());
		serialCom.set_pwm(17, check18.GetCheck(), 7 - slider18.GetPos(), 15 - slider36.GetPos());
	}

	CDialogEx::OnTimer(nIDEvent); // 调用基类版本以进行默认处理（如果需要的话）  
}





