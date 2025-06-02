#pragma once
#include "afxdialogex.h"
#include "MFCApplication1Dlg.h"


// CAN 对话框

class CAN : public CDialogEx
{
    DECLARE_DYNAMIC(CAN)

public:
    CAN(CWnd* pParent = nullptr);   // 标准构造函数
    virtual ~CAN();

// 对话框数据
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_DIALOG_CAN };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
    virtual BOOL OnInitDialog();
    DECLARE_MESSAGE_MAP()
public:
    CMFCApplication1Dlg* father = NULL;
    CString baud;
    CString bs1;
    CString bs2;
    CString sjw;
    CString id_;
    CString len;
    CString data_;
    CString receive;
    afx_msg void OnTimer(UINT_PTR nIDEvent);
    afx_msg void OnClose();
    CString baud_com;
    CString bits;
    CString parity;
    CString stop;
    BOOL send_hex;
    BOOL receive_hex;
    CString send_com;
    CString receive_com;
    afx_msg void OnBnClickedCanSet();
    afx_msg void OnBnClickedCanSend();
    afx_msg void OnBnClickedCanReceiveClear();
    afx_msg void OnBnClickedComSet();
    afx_msg void OnBnClickedComSendClear();
    afx_msg void OnBnClickedComSend();
    afx_msg void OnBnClickedComReceiveClear();
    CEdit idc_receive_com;
};

