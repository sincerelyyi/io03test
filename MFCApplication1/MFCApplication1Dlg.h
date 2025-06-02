
// MFCApplication1Dlg.h: 头文件
//

#pragma once


// CMFCApplication1Dlg 对话框
class CMFCApplication1Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	DECLARE_MESSAGE_MAP()
public:
	CProgressCtrl progress1;
	CProgressCtrl progress2;
	CProgressCtrl progress3;
	CProgressCtrl progress4;
	CProgressCtrl progress5;
	CProgressCtrl progress6;
	CProgressCtrl progress7;
	CProgressCtrl progress8;
	CButton check1;
	CButton check2;
	CButton check3;
	CButton check4;
	CButton check5;
	CButton check6;
	CButton check7;
	CButton check8;
	CButton check9;
	CButton check10;
	CButton check11;
	CButton check12;
	CButton check13;
	CButton check14;
	CButton check15;
	CButton check16;
	CButton check17;
	CButton check18;
	CSliderCtrl slider1;
	CSliderCtrl slider2;
	CSliderCtrl slider3;
	CSliderCtrl slider4;
	CSliderCtrl slider5;
	CSliderCtrl slider6;
	CSliderCtrl slider7;
	CSliderCtrl slider8;
	CSliderCtrl slider9;
	CSliderCtrl slider10;
	CSliderCtrl slider11;
	CSliderCtrl slider12;
	CSliderCtrl slider13;
	CSliderCtrl slider14;
	CSliderCtrl slider15;
	CSliderCtrl slider16;
	CSliderCtrl slider17;
	CSliderCtrl slider18;
	CSliderCtrl slider19;
	CSliderCtrl slider20;
	CSliderCtrl slider21;
	CSliderCtrl slider22;
	CSliderCtrl slider23;
	CSliderCtrl slider24;
	CSliderCtrl slider25;
	CSliderCtrl slider26;
	CSliderCtrl slider27;
	CSliderCtrl slider28;
	CSliderCtrl slider29;
	CSliderCtrl slider30;
	CSliderCtrl slider31;
	CSliderCtrl slider32;
	CSliderCtrl slider33;
	CSliderCtrl slider34;
	CSliderCtrl slider35;
	CSliderCtrl slider36;
	CSliderCtrl slider41;
	CSliderCtrl slider42;
	CSliderCtrl slider43;
	CSliderCtrl slider44;
	CSliderCtrl slider45;
	CSliderCtrl slider46;
	CSliderCtrl slider47;
	CSliderCtrl slider48;
	BOOL out0;
	BOOL out1;
	BOOL out2;
	BOOL out3;
	BOOL out4;
	BOOL out5;
	BOOL out6;
	BOOL out7;
	BOOL out8;
	BOOL out9;
	BOOL out10;
	BOOL out11;
	BOOL out12;
	BOOL out13;
	BOOL out14;
	BOOL out15;
	BOOL out16;
	BOOL out17;
	BOOL out18;
	BOOL out19;
	BOOL out20;
	BOOL out21;
	BOOL out22;
	BOOL out23;
	BOOL in0;
	BOOL in1;
	BOOL in2;
	BOOL in3;
	BOOL in4;
	BOOL in5;
	BOOL in6;
	BOOL in7;
	BOOL in8;
	BOOL in9;
	BOOL in10;
	BOOL in11;
	BOOL in12;
	BOOL in13;
	BOOL in14;
	BOOL in15;
	BOOL in16;
	BOOL in17;
	BOOL in18;
	BOOL in19;
	BOOL in20;
	BOOL in21;
	BOOL in22;
	BOOL in23;
	BOOL radio1;
	BOOL radio7;
	CString edit1;
	CString edit2;
	CString edit3;
	CString edit4;
	CString edit5;
	CString edit6;
	CString edit7;
	CString edit8;
	CString edit9;
	CString edit10;
	CString edit11;
	CString edit12;
	CString edit13;
	CString edit14;
	CString edit15;
	CString edit16;
	CString edit17;
	CString edit18;
	CString edit19;
	CString edit20;
	CString edit21;
	CString edit22;
	CString edit23;
	CString edit24;
	CString edit25;
	CString edit26;
	CString edit27;
	CString edit28;
	CString edit29;
	CString edit30;


	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedRadio6();
	afx_msg void OnBnClickedRadio7();
	afx_msg void OnBnClickedRadio8();
	afx_msg void OnBnClickedRadio9();
	afx_msg void OnBnClickedRadio10();
	afx_msg void OnBnClickedRadio11();
	afx_msg void OnBnClickedRadio12();
	afx_msg void OnNMCustomdrawSlider41(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMCustomdrawSlider42(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMCustomdrawSlider43(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMCustomdrawSlider44(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMCustomdrawSlider45(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMCustomdrawSlider46(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMCustomdrawSlider47(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMCustomdrawSlider48(NMHDR* pNMHDR, LRESULT* pResult);

	void  steering0_command(void);
	void  steering1_command(void);
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedExtlightOpen();
};
