
// ��ҳˢ�����Dlg.h : ͷ�ļ�
//

#pragma once
#include "explorer1.h"
#include <windows.h>

// C��ҳˢ�����Dlg �Ի���
class C��ҳˢ�����Dlg : public CDialogEx
{
// ����
public:
	C��ҳˢ�����Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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