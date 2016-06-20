
// ��ҳˢ�����Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ҳˢ�����.h"
#include "��ҳˢ�����Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CString webSite;
int second;
int flag;
int status;
CExplorer1 *explorerTemp;
HANDLE hThreadStatus = NULL;

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// C��ҳˢ�����Dlg �Ի���



C��ҳˢ�����Dlg::C��ҳˢ�����Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C��ҳˢ�����Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EXPLORER1, linkWebsite);
	
}

BEGIN_MESSAGE_MAP(C��ҳˢ�����Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BUTTON1, &C��ҳˢ�����Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &C��ҳˢ�����Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// C��ҳˢ�����Dlg ��Ϣ�������

BOOL C��ҳˢ�����Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//GetClientRect(&rect);

	CWnd*pWnd;
	CRect toolRect;
	CRect clientRect;
	GetClientRect(&clientRect);
	for (int i = 1000; i < 1009; ++i) {
		pWnd = GetDlgItem(i);
		pWnd->GetWindowRect(&toolRect);
		ratio[i - 1000][0] = (double)toolRect.left / clientRect.Width();
		ratio[i - 1000][1] = (double)toolRect.right / clientRect.Width();
		if (i == 1008 || i == 1007) {
			ratio[i - 1000][2] = (double)toolRect.top / clientRect.Height();
			ratio[i - 1000][3] = (double)toolRect.bottom / clientRect.Height();
		}
		else {
			ratio[i - 1000][2] = toolRect.top;
			ratio[i - 1000][3] = toolRect.bottom;
		}
	}

	GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C��ҳˢ�����Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void C��ҳˢ�����Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
		//OnSize(IDD_MY_DIALOG, 0, 0);
	}
}

void C��ҳˢ�����Dlg::OnSize(UINT nID, int cx, int cy)
{
	CDialog::OnSize(nID, cx, cy);
	CWnd*pWnd;
	CRect toolRect;
	CRect clientRect;
	/*
	double ratioWidth;
	double ratioHigh;
	GetClientRect(&clientRect);
	ratioWidth = (double)clientRect.Width() / rect.Width();
	ratioHigh = (double)clientRect.Height() / rect.Height();
	for (int i = 1000; i < 1008; ++i) {
		pWnd = GetDlgItem(i);
		if (pWnd) {
			pWnd->GetWindowRect(&toolRect);
			toolRect.left *= ratioWidth;
			toolRect.right *= ratioWidth;
			pWnd->MoveWindow(toolRect);
		}
	}
	pWnd = GetDlgItem(1008);
	if (pWnd) {
		pWnd->GetWindowRect(&toolRect);
		toolRect.top *= ratioHigh;
		toolRect.bottom *= ratioHigh;
		toolRect.left *= ratioWidth;
		toolRect.right *= ratioWidth;
		pWnd->MoveWindow(toolRect);
	}
	*/
	GetClientRect(&clientRect);
	if (GetDlgItem(1000)) {
		for (int i = 1000; i < 1009; ++i) {
			pWnd = GetDlgItem(i);
			pWnd->GetWindowRect(&toolRect);
			toolRect.left = clientRect.Width()*ratio[i - 1000][0];
			toolRect.right = clientRect.Width()*ratio[i - 1000][1];
			if (i == 1008 || i == 1007) {
				toolRect.top = clientRect.Height()*ratio[i - 1000][2];
				toolRect.bottom = clientRect.Height()*ratio[i - 1000][3];
			}else{
				toolRect.top = ratio[i - 1000][2];
				toolRect.bottom = ratio[i - 1000][3];
			}
			pWnd->MoveWindow(toolRect);
		}
	}
	GetClientRect(&rect);
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C��ҳˢ�����Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void C��ҳˢ�����Dlg::OnOK()
{
}

BOOL C��ҳˢ�����Dlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN&&pMsg->wParam == VK_ESCAPE) {
		pMsg->wParam = VK_RETURN;                  //��ESC������Ϣ�滻Ϊ�س�������Ϣ����������ESC��ʱ��
												   //Ҳ��ȥ����OnOK��������OnOKʲôҲ����������ESCҲ������
	}
	return CDialog::PreTranslateMessage(pMsg);
}
/*
BOOL C��ҳˢ�����Dlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN&&pMsg->wParam == VK_ESCAPE)
		return TRUE;
	if (pMsg->message == WM_KEYDOWN&&pMsg->wParam == VK_RETURN)
		return TRUE;
	else
		return CDialog::PreTranslateMessage(pMsg);
}*/

void C��ҳˢ�����Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	explorerTemp = &linkWebsite;
	char* msg = new char[500];
	GetDlgItemTextA((HWND)((CFrameWnd*)AfxGetApp()->m_pMainWnd->m_hWnd), IDC_EDIT1, msg, 500);
	webSite = msg;
	GetDlgItemTextA((HWND)((CFrameWnd*)AfxGetApp()->m_pMainWnd->m_hWnd), IDC_EDIT2, msg, 500);
	second = 0;
	for (int i = 0; msg[i] && msg[i] != '.'; ++i) {
		if (msg[i] >= '0'&&msg[i] <= '9') {
			second *= 10;
			second += msg[i] - '0';
		}
	}
	flag = ((CButton *)GetDlgItem(IDC_RADIO1))->GetCheck();

	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
	hThreadRefresh = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)RefreshWebsite, NULL, 0, NULL);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
	status = 1;
}

void C��ҳˢ�����Dlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	SuspendThread(hThreadRefresh);
	CloseHandle(hThreadRefresh);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
}

DWORD WINAPI RefreshWebsite(LPVOID lpparameter)
{
	explorerTemp->Navigate(webSite, NULL, NULL, NULL, NULL);
	if (flag) {
		hThreadStatus = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)GetStatus, NULL, 0, NULL);
	}
	while (true){
		if (flag) {
			if (!status) {
				SuspendThread(hThreadStatus);
				CloseHandle(hThreadStatus);
				//C��ҳˢ�����Dlg *pDlg = (C��ҳˢ�����Dlg *)lpparameter;
				//pDlg->OnBnClickedButton2();
				CWnd *pWnd = CWnd::FromHandle(AfxGetApp()->GetMainWnd()->GetSafeHwnd());
				pWnd->GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
				pWnd->GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
				break;
			}
		}
		else {
			Sleep(second);
			explorerTemp->Navigate(webSite, NULL, NULL, NULL, NULL);
		}
	}
	return 0;
}

DWORD WINAPI GetStatus(LPVOID lpparameter)
{
	while (true) {
		if (explorerTemp->get_Busy() == false) {
			break;
		}
	}
	status = 0;
	return 0;
}