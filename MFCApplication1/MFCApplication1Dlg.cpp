
// MFCApplication1Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include "fangli_io03.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

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
public:
	afx_msg void OnBnClickedOk();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
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
	DDX_Check(pDX, IDC_CHECK19, out0);
	DDX_Check(pDX, IDC_CHECK20, out1);
	DDX_Check(pDX, IDC_CHECK21, out2);
	DDX_Check(pDX, IDC_CHECK22, out3);
	DDX_Check(pDX, IDC_CHECK23, out4);
	DDX_Check(pDX, IDC_CHECK24, out5);
	DDX_Check(pDX, IDC_CHECK25, out6);
	DDX_Check(pDX, IDC_CHECK26, out7);
	DDX_Check(pDX, IDC_CHECK27, out8);
	DDX_Check(pDX, IDC_CHECK28, out9);
	DDX_Check(pDX, IDC_CHECK29, out10);
	DDX_Check(pDX, IDC_CHECK30, out11);
	DDX_Check(pDX, IDC_CHECK31, out12);
	DDX_Check(pDX, IDC_CHECK32, out13);
	DDX_Check(pDX, IDC_CHECK33, out14);
	DDX_Check(pDX, IDC_CHECK34, out15);
	DDX_Check(pDX, IDC_CHECK35, out16);
	DDX_Check(pDX, IDC_CHECK36, out17);
	DDX_Check(pDX, IDC_CHECK37, out18);
	DDX_Check(pDX, IDC_CHECK38, out19);
	DDX_Check(pDX, IDC_CHECK39, out20);
	DDX_Check(pDX, IDC_CHECK40, out21);
	DDX_Check(pDX, IDC_CHECK41, out22);
	DDX_Check(pDX, IDC_CHECK42, out23);
	DDX_Check(pDX, IDC_CHECK44, in0);
	DDX_Check(pDX, IDC_CHECK45, in1);
	DDX_Check(pDX, IDC_CHECK46, in2);
	DDX_Check(pDX, IDC_CHECK47, in3);
	DDX_Check(pDX, IDC_CHECK48, in4);
	DDX_Check(pDX, IDC_CHECK49, in5);
	DDX_Check(pDX, IDC_CHECK50, in6);
	DDX_Check(pDX, IDC_CHECK51, in7);
	DDX_Check(pDX, IDC_CHECK52, in8);
	DDX_Check(pDX, IDC_CHECK53, in9);
	DDX_Check(pDX, IDC_CHECK54, in10);
	DDX_Check(pDX, IDC_CHECK55, in11);
	DDX_Check(pDX, IDC_CHECK56, in12);
	DDX_Check(pDX, IDC_CHECK57, in13);
	DDX_Check(pDX, IDC_CHECK58, in14);
	DDX_Check(pDX, IDC_CHECK59, in15);
	DDX_Check(pDX, IDC_CHECK60, in16);
	DDX_Check(pDX, IDC_CHECK61, in17);
	DDX_Check(pDX, IDC_CHECK62, in18);
	DDX_Check(pDX, IDC_CHECK63, in19);
	DDX_Check(pDX, IDC_CHECK64, in20);
	DDX_Check(pDX, IDC_CHECK65, in21);
	DDX_Check(pDX, IDC_CHECK66, in22);
	DDX_Check(pDX, IDC_CHECK67, in23);


	DDX_Text(pDX, IDC_EDIT1, edit1);
	DDX_Text(pDX, IDC_EDIT2, edit2);
	DDX_Text(pDX, IDC_EDIT3, edit3);
	DDX_Text(pDX, IDC_EDIT4, edit4);
	DDX_Text(pDX, IDC_EDIT5, edit5);
	DDX_Text(pDX, IDC_EDIT6, edit6);
	DDX_Text(pDX, IDC_EDIT7, edit7);
	DDX_Text(pDX, IDC_EDIT8, edit8);
	DDX_Text(pDX, IDC_EDIT9, edit9);
	DDX_Text(pDX, IDC_EDIT10, edit10);
	DDX_Text(pDX, IDC_EDIT11, edit11);
	DDX_Text(pDX, IDC_EDIT12, edit12);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication1Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication1Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication1Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication1Dlg::OnBnClickedButton4)
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
	slider1.SetRange(0, 100);
	slider2.SetRange(0, 100);
	slider3.SetRange(0, 100);
	slider4.SetRange(0, 100);
	slider5.SetRange(0, 100);
	slider6.SetRange(0, 100);
	slider7.SetRange(0, 100);
	slider8.SetRange(0, 100);
	slider9.SetRange(0, 100);
	slider10.SetRange(0, 100);
	slider11.SetRange(0, 100);
	slider12.SetRange(0, 100);
	slider13.SetRange(0, 100);
	slider14.SetRange(0, 100);
	slider15.SetRange(0, 100);
	slider16.SetRange(0, 100);
	slider17.SetRange(0, 100);
	slider18.SetRange(0, 100);
	slider19.SetRange(0, 255);
	slider20.SetRange(0, 255);
	slider21.SetRange(0, 255);
	slider22.SetRange(0, 255);
	slider23.SetRange(0, 255);
	slider24.SetRange(0, 255);
	slider25.SetRange(0, 255);
	slider26.SetRange(0, 255);
	slider27.SetRange(0, 255);
	slider28.SetRange(0, 255);
	slider29.SetRange(0, 255);
	slider30.SetRange(0, 255);
	slider31.SetRange(0, 255);
	slider32.SetRange(0, 255);
	slider33.SetRange(0, 255);
	slider34.SetRange(0, 255);
	slider35.SetRange(0, 255);
	slider36.SetRange(0, 255);
	if (connect_state() < 1)
	{
		MessageBox(TEXT("没有连接上IO板！"), TEXT("Error"), MB_OK | MB_ICONINFORMATION);
	}
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
		UpdateData(TRUE);

		progress1.SetPos(get_adc(0));
		progress2.SetPos(get_adc(1));
		progress3.SetPos(get_adc(2));
		progress4.SetPos(get_adc(3));
		progress5.SetPos(get_adc(4));
		progress6.SetPos(get_adc(5));
		progress7.SetPos(get_adc(6));
		progress8.SetPos(get_adc(7));
		if (slider1.GetPos() == 100)
		{
			set_pwm_normal(0,255 - slider19.GetPos());
		}
		else
		{
			if (check1.GetCheck())
			{
				set_pwm_blink(0,100 - slider1.GetPos(), 255 - slider19.GetPos());
			}
			else
			{
				set_pwm_breathe(0, 100 - slider1.GetPos(), 255 - slider19.GetPos());
			}
		}

		if (slider2.GetPos() == 100)
		{
			set_pwm_normal(1, 255 - slider20.GetPos());
		}
		else
		{
			if (check2.GetCheck())
			{
				set_pwm_blink(1, 100 - slider2.GetPos(), 255 - slider20.GetPos());
			}
			else
			{
				set_pwm_breathe(1, 100 - slider2.GetPos(), 255 - slider20.GetPos());
			}
		}

		if (slider3.GetPos() == 100)
		{
			set_pwm_normal(2, 255 - slider21.GetPos());
		}
		else
		{
			if (check3.GetCheck())
			{
				set_pwm_blink(2, 100 - slider3.GetPos(), 255 - slider21.GetPos());
			}
			else
			{
				set_pwm_breathe(2, 100 - slider3.GetPos(), 255 - slider21.GetPos());
			}
		}

		if (slider4.GetPos() == 100)
		{
			set_pwm_normal(3, 255 - slider20.GetPos());
		}
		else
		{
			if (check4.GetCheck())
			{
				set_pwm_blink(3, 100 - slider4.GetPos(), 255 - slider22.GetPos());
			}
			else
			{
				set_pwm_breathe(3, 100 - slider4.GetPos(), 255 - slider22.GetPos());
			}
		}

		if (slider5.GetPos() == 100)
		{
			set_pwm_normal(4, 255 - slider23.GetPos());
		}
		else
		{
			if (check5.GetCheck())
			{
				set_pwm_blink(4, 100 - slider5.GetPos(), 255 - slider23.GetPos());
			}
			else
			{
				set_pwm_breathe(4, 100 - slider5.GetPos(), 255 - slider23.GetPos());
			}
		}

		if (slider6.GetPos() == 100)
		{
			set_pwm_normal(5, 255 - slider24.GetPos());
		}
		else
		{
			if (check6.GetCheck())
			{
				set_pwm_blink(5, 100 - slider6.GetPos(), 255 - slider24.GetPos());
			}
			else
			{
				set_pwm_breathe(5, 100 - slider6.GetPos(), 255 - slider24.GetPos());
			}
		}

		if (slider7.GetPos() == 100)
		{
			set_pwm_normal(6, 255 - slider25.GetPos());
		}
		else
		{
			if (check7.GetCheck())
			{
				set_pwm_blink(6, 100 - slider7.GetPos(), 255 - slider25.GetPos());
			}
			else
			{
				set_pwm_breathe(6, 100 - slider7.GetPos(), 255 - slider25.GetPos());
			}
		}

		if (slider8.GetPos() == 100)
		{
			set_pwm_normal(7, 255 - slider26.GetPos());
		}
		else
		{
			if (check8.GetCheck())
			{
				set_pwm_blink(7, 100 - slider8.GetPos(), 255 - slider26.GetPos());
			}
			else
			{
				set_pwm_breathe(7, 100 - slider8.GetPos(), 255 - slider26.GetPos());
			}
		}

		if (slider9.GetPos() == 100)
		{
			set_pwm_normal(8, 255 - slider27.GetPos());
		}
		else
		{
			if (check9.GetCheck())
			{
				set_pwm_blink(8, 100 - slider9.GetPos(), 255 - slider27.GetPos());
			}
			else
			{
				set_pwm_breathe(8, 100 - slider9.GetPos(), 255 - slider27.GetPos());
			}
		}

		if (slider10.GetPos() == 100)
		{
			set_pwm_normal(9, 255 - slider28.GetPos());
		}
		else
		{
			if (check10.GetCheck())
			{
				set_pwm_blink(9, 100 - slider10.GetPos(), 255 - slider28.GetPos());
			}
			else
			{
				set_pwm_breathe(9, 100 - slider10.GetPos(), 255 - slider28.GetPos());
			}
		}

		if (slider11.GetPos() == 100)
		{
			set_pwm_normal(10, 255 - slider29.GetPos());
		}
		else
		{
			if (check11.GetCheck())
			{
				set_pwm_blink(10, 100 - slider11.GetPos(), 255 - slider29.GetPos());
			}
			else
			{
				set_pwm_breathe(10, 100 - slider11.GetPos(), 255 - slider29.GetPos());
			}
		}

		if (slider12.GetPos() == 100)
		{
			set_pwm_normal(11, 255 - slider30.GetPos());
		}
		else
		{
			if (check12.GetCheck())
			{
				set_pwm_blink(11, 100 - slider12.GetPos(), 255 - slider30.GetPos());
			}
			else
			{
				set_pwm_breathe(11, 100 - slider12.GetPos(), 255 - slider30.GetPos());
			}
		}

		if (slider13.GetPos() == 100)
		{
			set_pwm_normal(12, 255 - slider31.GetPos());
		}
		else
		{
			if (check13.GetCheck())
			{
				set_pwm_blink(12, 100 - slider13.GetPos(), 255 - slider31.GetPos());
			}
			else
			{
				set_pwm_breathe(12, 100 - slider13.GetPos(), 255 - slider31.GetPos());
			}
		}

		if (slider14.GetPos() == 100)
		{
			set_pwm_normal(13, 255 - slider32.GetPos());
		}
		else
		{
			if (check14.GetCheck())
			{
				set_pwm_blink(13, 100 - slider14.GetPos(), 255 - slider32.GetPos());
			}
			else
			{
				set_pwm_breathe(13, 100 - slider14.GetPos(), 255 - slider32.GetPos());
			}
		}

		if (slider15.GetPos() == 100)
		{
			set_pwm_normal(14, 255 - slider33.GetPos());
		}
		else
		{
			if (check15.GetCheck())
			{
				set_pwm_blink(14, 100 - slider15.GetPos(), 255 - slider33.GetPos());
			}
			else
			{
				set_pwm_breathe(14, 100 - slider15.GetPos(), 255 - slider33.GetPos());
			}
		}

		if (slider16.GetPos() == 100)
		{
			set_pwm_normal(15, 255 - slider34.GetPos());
		}
		else
		{
			if (check16.GetCheck())
			{
				set_pwm_blink(15, 100 - slider16.GetPos(), 255 - slider34.GetPos());
			}
			else
			{
				set_pwm_breathe(15, 100 - slider16.GetPos(), 255 - slider34.GetPos());
			}
		}

		if (slider17.GetPos() == 100)
		{
			set_pwm_normal(16, 255 - slider35.GetPos());
		}
		else
		{
			if (check17.GetCheck())
			{
				set_pwm_blink(16, 100 - slider17.GetPos(), 255 - slider35.GetPos());
			}
			else
			{
				set_pwm_breathe(16, 100 - slider17.GetPos(), 255 - slider35.GetPos());
			}
		}

		if (slider18.GetPos() == 100)
		{
			set_pwm_normal(17, 255 - slider36.GetPos());
		}
		else
		{
			if (check18.GetCheck())
			{
				set_pwm_blink(17, 100 - slider18.GetPos(), 255 - slider36.GetPos());
			}
			else
			{
				set_pwm_breathe(17, 100 - slider18.GetPos(), 255 - slider36.GetPos());
			}
		}

		in0 = get_key(0);
		in1 = get_key(1);
		in2 = get_key(2);
		in3 = get_key(3);
		in4 = get_key(4);
		in5 = get_key(5);
		in6 = get_key(6);
		in7 = get_key(7);
		in8 = get_key(8);
		in9 = get_key(9);
		in10 = get_key(10);
		in11 = get_key(11);
		in12 = get_key(12);
		in13 = get_key(13);
		in14 = get_key(14);
		in15 = get_key(15);
		in16 = get_key(16);
		in17 = get_key(17);
		in18 = get_key(18);
		in19 = get_key(19);
		in20 = get_key(20);
		in21 = get_key(21);
		in22 = get_key(22);
		in23 = get_key(23);

		set_outPin(0, out0);
		set_outPin(1, out1);
		set_outPin(2, out2);
		set_outPin(3, out3);
		set_outPin(4, out4);
		set_outPin(5, out5);
		set_outPin(6, out6);
		set_outPin(7, out7);
		set_outPin(8, out8);
		set_outPin(9, out9);
		set_outPin(10, out10);
		set_outPin(11, out11);
		set_outPin(12, out12);
		set_outPin(13, out13);
		set_outPin(14, out14);
		set_outPin(15, out15);
		set_outPin(16, out16);
		set_outPin(17, out17);
		set_outPin(18, out18);
		set_outPin(19, out19);
		set_outPin(20, out20);
		set_outPin(21, out21);
		set_outPin(22, out22);
		set_outPin(23, out23);
		edit1.Format(_T("%u"), get_coin());
		edit2.Format(_T("%d℃"), get_mcu_temperature());
		edit3.Format(_T("%.1fV"), (float)get_mcu_voltage() / 10);
		edit4.Format(_T("%.1fV"), (float)get_battery_voltage() / 10);
		edit5.Format(_T("%u"), get_counter(COUNTER_COIN));
		edit6.Format(_T("%u"), get_counter(COUNTER_1));
		edit7 = get_hardware();
		edit8 = get_software();
		edit9 = get_production_date();
		edit10 = get_uid();
		edit11 = get_lib();
		if (connect_state() < 0)
		{
			edit12.Format(_T("没有连接上IO板!"));
		}
		else
		{
			edit12.Format(_T("IO板连接到COM%d，115200."), connect_state());
		}
		UpdateData(FALSE);
		
	}

	CDialogEx::OnTimer(nIDEvent); // 调用基类版本以进行默认处理（如果需要的话）  
}







void CAboutDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}



void CMFCApplication1Dlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	decrease_coin(1);
}


void CMFCApplication1Dlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	clear_coin();
}


void CMFCApplication1Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	if(get_counter(COUNTER_COIN) + 100 < 0xffffffff)
		set_counter(COUNTER_COIN, get_counter(COUNTER_COIN) + 100);
	else
		set_counter(COUNTER_COIN, 0xfffffffe);
}


void CMFCApplication1Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	set_counter(COUNTER_COIN,0);
}


void CMFCApplication1Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	if(get_counter(COUNTER_1) + 100 < 0xffffffff)
		set_counter(COUNTER_1, get_counter(COUNTER_1) + 100);
	else
		set_counter(COUNTER_1, 0xfffffffe);
}


void CMFCApplication1Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	set_counter(COUNTER_1, 0);
}
