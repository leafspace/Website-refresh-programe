
// 网页刷新软件Dlg.h : 头文件
//

#pragma once
#include "explorer1.h"
#include <windows.h>

// C网页刷新软件Dlg 对话框
class C网页刷新软件Dlg : public CDialogEx
{
// 构造
public:
	C网页刷新软件Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_DIALOG };
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
	afx_msg void OnSize(UINT, int, int);
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	HANDLE hThreadRefresh;
public:
	CExplorer1 linkWebsite;
	CRect rect;
	double ratio[10][4];
	void OnOK();
	BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};

extern CString webSite;
extern int second;
extern CExplorer1 *explorerTemp;
DWORD WINAPI RefreshWebsite(LPVOID lpparameter);
DWORD WINAPI GetStatus(LPVOID lpparameter);