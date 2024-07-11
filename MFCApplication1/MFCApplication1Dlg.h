
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
	afx_msg void OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMCustomdrawSlider19(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck3();
};
