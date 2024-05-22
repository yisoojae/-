
// 업무용Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "업무용.h"
#include "업무용Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	// 구현입니다.
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


// C업무용Dlg 대화 상자



C업무용Dlg::C업무용Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C업무용Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C업무용Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(jobKind_ID, &C업무용Dlg::jobKindSet)
	ON_BN_CLICKED(convertBtn01_ID, &C업무용Dlg::convertBtn01Click)
END_MESSAGE_MAP()


// C업무용Dlg 메시지 처리기

BOOL C업무용Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	RECT a = {30, 10, 200, 30};
	jobKind.Create(WS_VISIBLE | WS_CHILD | WS_VSCROLL | CBS_DROPDOWNLIST, a, this, jobKind_ID);
	jobKind.AddString(_T("대량 권한코드 등록"));
	jobKind.SetCurSel(0);
	jobKindSet();
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void C업무용Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void C업무용Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR C업무용Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



BOOL C업무용Dlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
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

void C업무용Dlg::jobKindSet()
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
		label01.Create(_T("[값이 들어갈 자리]"), WS_VISIBLE, a, this, label01_ID);
		a.left = 450; a.right = 700;
		word02.Create(WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL, a, this, word02_ID);
		a.left = 20; a.right = 370; a.top = 80; a.bottom = 700;
		source01.Create(WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL | ES_MULTILINE | ES_WANTRETURN | ES_AUTOVSCROLL, a, this, source01_ID);
		source01.ShowScrollBar(SB_VERT);
		a.left = 380; a.right = 700;
		result01.Create(WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL | ES_MULTILINE | ES_WANTRETURN | ES_AUTOVSCROLL, a, this, result01_ID);
		result01.ShowScrollBar(SB_VERT);
		a.left = 260; a.right = 500; a.top = 10; a.bottom = 40;
		convertBtn01.Create(_T("변  환"), WS_VISIBLE | WS_CHILD, a, this, convertBtn01_ID);

		break;
	}
}

void C업무용Dlg::convertBtn01Click()
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