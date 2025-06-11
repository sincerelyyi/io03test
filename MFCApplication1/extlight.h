#pragma once
#include "afxdialogex.h"
#include "MFCApplication1Dlg.h"


// extLight 对话框

class extLight : public CDialogEx
{
	DECLARE_DYNAMIC(extLight)

public:
	extLight(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~extLight();

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
	CString colorTable;
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
	CString soft_version;
	CString hard_version;
	BOOL receive_hex;
	BOOL check_newline;
	CString receive_com;
	afx_msg void OnBnClickedComReceiveClear2();
	CEdit idc_receive_com;
	CString port_input;
	CString segment_input;
	CString input_len;
	CString input_cnt;
	CString input_src;
	afx_msg void OnBnClickedInput();
	afx_msg void OnNMCustomdrawSliderSrc(NMHDR* pNMHDR, LRESULT* pResult);
	CSliderCtrl slider_src;
	CEdit edit_src;
	CString edit_err;
};
