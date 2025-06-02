#pragma once
#include "afxdialogex.h"
#include "MFCApplication1Dlg.h"


// extlight 对话框

class extlight : public CDialogEx
{
	DECLARE_DYNAMIC(extlight)

public:
	extlight(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~extlight();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXTLIGHT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CMFCApplication1Dlg* father = NULL;
	afx_msg void OnClose();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CString isconnect;
	CString port_init;
	CString port_enable;
	CString port_disable;
	CString port_mode;
	CString port_flashread;
	CString lednum;
	CString segmentnum;
	CString bright;
	CString colortable;
	CString segment;
	CString ledstart;
	CString ledend;
	CString speed;
	CString block_flashread;
	CString block_flashwrite;
	CString flamenum;
	CString linenum;
	CString ledtype;
	CString mode;
	CString color1;
	CString color2;
	CString color3;
	CString option;
	CString columnnum;
	CString colorbuff;
	afx_msg void OnBnClickedInit();
	afx_msg void OnBnClickedEnable();
	afx_msg void OnBnClickedDisable();
	afx_msg void OnBnClickedColortable();
	afx_msg void OnBnClickedModeSet();
	afx_msg void OnBnClickedFlashRead();
	afx_msg void OnBnClickedFlashRead2();
};
