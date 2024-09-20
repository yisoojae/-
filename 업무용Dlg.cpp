
// ������Dlg.cpp: ���� ����
//

#include "pch.h"
#include "framework.h"
#include "������.h"
#include "������Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	// �����Դϴ�.
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


// C������Dlg ��ȭ ����



C������Dlg::C������Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C������Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C������Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(jobKind_ID, &C������Dlg::jobKindSet)
	ON_BN_CLICKED(convertBtn01_ID, &C������Dlg::convertBtn01Click)
END_MESSAGE_MAP()


// C������Dlg �޽��� ó����

BOOL C������Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	RECT a = {30, 10, 200, 30};
	jobKind.Create(WS_VISIBLE | WS_CHILD | WS_VSCROLL | CBS_DROPDOWNLIST, a, this, jobKind_ID);
	jobKind.AddString(_T("�뷮 �����ڵ� ���"));
	jobKind.SetCurSel(0);
	jobKindSet();
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void C������Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���ø����̼��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void C������Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR C������Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



BOOL C������Dlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	switch (pMsg->message)
	{
	case WM_KEYDOWN:
		switch (pMsg->wParam)
		{
		case VK_ESCAPE:
		case VK_RETURN:
			return false;
		}
		break;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}

void C������Dlg::jobKindSet()
{
	switch(jobKind.GetCurSel())
	{
	case 0:
		CRect rc;
		GetWindowRect(&rc);
		MoveWindow(rc.left, rc.top, 730, 750);
		RECT a = {20, 50, 300, 70};
		word01.Create(WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL, a, this, word01_ID);
		a.left = 310; a.right = 700;
		label01.Create(_T("[���� �� �ڸ�]"), WS_VISIBLE, a, this, label01_ID);
		a.left = 450; a.right = 700;
		word02.Create(WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL, a, this, word02_ID);
		a.left = 20; a.right = 370; a.top = 80; a.bottom = 700;
		source01.Create(WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL | ES_MULTILINE | ES_WANTRETURN | ES_AUTOVSCROLL, a, this, source01_ID);
		source01.ShowScrollBar(SB_VERT);
		a.left = 380; a.right = 700;
		result01.Create(WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL | ES_MULTILINE | ES_WANTRETURN | ES_AUTOVSCROLL, a, this, result01_ID);
		result01.ShowScrollBar(SB_VERT);
		a.left = 260; a.right = 500; a.top = 10; a.bottom = 40;
		convertBtn01.Create(_T("��  ȯ"), WS_VISIBLE | WS_CHILD, a, this, convertBtn01_ID);

		break;
	}
}

void C������Dlg::convertBtn01Click()
{
	LPTSTR a, b, c, c_p, c_p2;
	CString d;
	a = (LPTSTR)malloc((word01.GetWindowTextLengthW() + 1) * sizeof(LPTSTR));
	word01.GetWindowTextW(a, word01.GetWindowTextLengthW() + 1);
	b = (LPTSTR)malloc((word02.GetWindowTextLengthW() + 1) * sizeof(LPTSTR));
	word02.GetWindowTextW(b, word02.GetWindowTextLengthW() + 1);
	c = (LPTSTR)malloc((source01.GetWindowTextLengthW() + 1) * sizeof(LPTSTR));
	source01.GetWindowTextW(c, source01.GetWindowTextLengthW() + 1);
	d.Format(_T(""));

	c_p2 = c_p = c;
	while(*c_p != '\0')
	{
		while(*c_p != '\0' && *c_p != '\n')
		{
			++c_p;
		}
		if(*c_p != '\0')
		{
			if(*(c_p - 1) == '\r')
				*(c_p - 1) = '\0';
			else
				*c_p = '\0';
			++c_p;
		}

		d.Format(_T("%s%s%s%s\r\n"), d, a, c_p2, b);
		c_p2 = c_p;
	}
	result01.SetWindowTextW(d);

	free(a); free(b); free(c);
}