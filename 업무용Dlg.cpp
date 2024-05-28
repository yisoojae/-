
// 업무용Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "업무용.h"
#include "업무용Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C업무용Dlg 대화 상자




void CALLBACK macroCallback(HWND hwnd, UINT a, UINT_PTR b, DWORD c){
	mouse_event(MOUSEEVENTF_MOVE, 2, 0, 0, NULL);
	mouse_event(MOUSEEVENTF_MOVE, -1, 0, 0, NULL);
}

C업무용Dlg::C업무용Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C업무용Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	lastIndex = -1;
}

C업무용Dlg::~C업무용Dlg()
{
	DeleteObject(a_BRUSH);
}

void C업무용Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C업무용Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(jobKind_ID, &C업무용Dlg::jobKindSet)
	ON_BN_CLICKED(convertBtn01_ID, &C업무용Dlg::convertBtn01Click)
	ON_BN_CLICKED(copyBtn01_ID, &C업무용Dlg::copyBtn01Click)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// C업무용Dlg 메시지 처리기

BOOL C업무용Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	RECT a = {30, 10, 200, 30};
	jobKind.Create(WS_VISIBLE | WS_CHILD | WS_VSCROLL | CBS_DROPDOWNLIST, a, this, jobKind_ID);
	jobKind.AddString(_T("대량 권한코드 등록"));
	jobKind.AddString(_T("열을 행으로 변환"));
	jobKind.AddString(_T("화면 보호기 방지"));
	jobKind.AddString(_T("코스콤 자동 답변"));
	//jobKind.SetCurSel(0);
	//jobKindSet();
	
	a_RGB = RGB(238,238,238);
	a_BRUSH = CreateSolidBrush(a_RGB);
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
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
	if(lastIndex == jobKind.GetCurSel())
		return;
	switch(lastIndex)
	{
	case 0:
		word01.DestroyWindow();
		source01.DestroyWindow();
		result01.DestroyWindow();
		convertBtn01.DestroyWindow();
		break;
	case 1:
		source01.DestroyWindow();
		result01.DestroyWindow();
		convertBtn01.DestroyWindow();
		copyBtn01.DestroyWindow();
		break;
	case 2:
		label01.DestroyWindow();
		word01.DestroyWindow();
		convertBtn01.DestroyWindow();
		copyBtn01.DestroyWindow();
		break;
	case 3:
		label01.DestroyWindow();
		word01.DestroyWindow();
		source01.DestroyWindow();
		convertBtn01.DestroyWindow();
		break;
	}

	CRect rc;
	GetWindowRect(&rc);
	RECT a = {20, 50, 300, 70};

	switch(jobKind.GetCurSel())
	{
	case 0:
		lastIndex = 0;

		MoveWindow(rc.left, rc.top, 730, 750);
		word01.Create(WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL, a, this, word01_ID);
		//a.left = 310; a.right = 700;
		//label01.Create(_T("[값이 들어갈 자리]"), WS_VISIBLE, a, this, label01_ID);
		//a.left = 450; a.right = 700;
		//word02.Create(WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL, a, this, word02_ID);
		a.left = 20; a.right = 370; a.top = 80; a.bottom = 700;
		source01.Create(WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL | ES_MULTILINE | ES_WANTRETURN | ES_AUTOVSCROLL, a, this, source01_ID);
		source01.ShowScrollBar(SB_VERT);
		a.left = 380; a.right = 700;
		result01.Create(WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL | ES_MULTILINE | ES_WANTRETURN | ES_AUTOVSCROLL, a, this, result01_ID);
		result01.ShowScrollBar(SB_VERT);
		a.left = 260; a.right = 500; a.top = 10; a.bottom = 40;
		convertBtn01.Create(_T("변  환"), WS_VISIBLE | WS_CHILD, a, this, convertBtn01_ID);

		break;
	case 1:
		lastIndex = 1;

		MoveWindow(rc.left, rc.top, 650, 710);
		a.left = 20; a.right = 370; a.top = 50; a.bottom = 600;
		source01.Create(WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL | ES_MULTILINE | ES_WANTRETURN | ES_AUTOVSCROLL, a, this, source01_ID);
		source01.ShowScrollBar(SB_VERT);
		a.left = 20; a.right = 600; a.top = 610; a.bottom = 660;
		result01.Create(WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL | ES_MULTILINE | ES_WANTRETURN | ES_AUTOVSCROLL, a, this, result01_ID);
		result01.ShowScrollBar(SB_HORZ);
		a.left = 260; a.right = 500; a.top = 10; a.bottom = 40;
		convertBtn01.Create(_T("변  환"), WS_VISIBLE | WS_CHILD, a, this, convertBtn01_ID);
		a.left = 390; a.right = 550; a.top = 260; a.bottom = 550;
		copyBtn01.Create(_T("결과를\n클립보드에\n복사"), WS_VISIBLE | WS_CHILD | BS_MULTILINE, a, this, copyBtn01_ID);

		break;
	case 2:
		lastIndex = 2;

		MoveWindow(rc.left, rc.top, 600, 300);
		a.left = 10; a.right = 600; a.top = 40; a.bottom = 150;
		label01.Create(_T("설정한 시간마다 마우스를 오른쪽으로 1픽셀 움직입니다.\n화면 보호기는 2분마다 작동하기 때문에\n1분 50초 이내에서 설정하기 바랍니다.\n\n기본값 : 50"), WS_VISIBLE, a, this, label01_ID);
		a.left = 100; a.right = 230; a.top = 160; a.bottom = 180;
		word01.Create(WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL | ES_NUMBER, a, this, word01_ID);
		word01.SetWindowTextW(L"50");
		a.left = 50; a.right = 150; a.top = 200; a.bottom = 230;
		convertBtn01.Create(_T("실 행"), WS_VISIBLE | WS_CHILD, a, this, convertBtn01_ID);
		a.left = 180; a.right = 280;
		copyBtn01.Create(_T("취 소"), WS_VISIBLE | WS_CHILD, a, this, copyBtn01_ID);

		break;
	case 3:
		lastIndex = 3;

		GetWindowRect(&rc);
		MoveWindow(rc.left, rc.top, 600, 600);
		a.left = 10; a.right = 600; a.top = 40; a.bottom = 100;
		label01.Create(_T("이 기능은 실험 기능입니다.\n정상 작동하지 않을 수 있으며\n편의 기능은 피드백 이후에 추가될 예정입니다."), WS_VISIBLE, a, this, label01_ID);
		a.left = 100; a.right = 230; a.top = 110; a.bottom = 130;
		word01.Create(WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL, a, this, word01_ID);
		a.left = 20; a.right = 370; a.top = 150; a.bottom = 550;
		source01.Create(WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL | ES_MULTILINE | ES_WANTRETURN | ES_AUTOVSCROLL, a, this, source01_ID);
		source01.ShowScrollBar(SB_VERT);
		source01.SetWindowTextW(L"네~~");
		a.left = 240; a.right = 350; a.top = 100; a.bottom = 140;
		convertBtn01.Create(_T("전 송"), WS_VISIBLE | WS_CHILD, a, this, convertBtn01_ID);

		break;
	}
}

void C업무용Dlg::convertBtn01Click()
{
	LPTSTR a/*, b*/, c, c_p, c_p2;
	CString d;
	CWnd* fwnd;
	switch(lastIndex)
	{
	case 0:
		a = (LPTSTR)malloc((word01.GetWindowTextLengthW() + 1) * sizeof(LPTSTR));
		word01.GetWindowTextW(a, word01.GetWindowTextLengthW() + 1);
		//b = (LPTSTR)malloc((word02.GetWindowTextLengthW() + 1) * sizeof(LPTSTR));
		//word02.GetWindowTextW(b, word02.GetWindowTextLengthW() + 1);
		c = (LPTSTR)malloc((source01.GetWindowTextLengthW() + 1) * sizeof(LPTSTR));
		source01.GetWindowTextW(c, source01.GetWindowTextLengthW() + 1);
		d.Format(_T("%s\r\n\r\n(\r\n"), a);

		c_p2 = c_p = c;
		if(*c_p != '\0')
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

			d.Format(_T("%s'%s'\r\n"), d, c_p2);
			c_p2 = c_p;
		}
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

			d.Format(_T("%s,'%s'\r\n"), d, c_p2);
			c_p2 = c_p;
		}
		d.Format(_T("%s\r\n\r\n\r\n)"), d);
		result01.SetWindowTextW(d);

		free(a); /*free(b);*/ free(c);

		break;
	case 1:
		c = (LPTSTR)malloc((source01.GetWindowTextLengthW() + 1) * sizeof(LPTSTR));
		source01.GetWindowTextW(c, source01.GetWindowTextLengthW() + 1);
		d.Format(_T(""));

		c_p2 = c_p = c;
		if(*c_p != '\0')
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

			d.Format(_T("%s"), c_p2);
			c_p2 = c_p;
		}
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

			d.Format(_T("%s, %s"), d, c_p2);
			c_p2 = c_p;
		}
		result01.SetWindowTextW(d);

		free(c);

		break;
	case 2:
		KillTimer(timer01_ID);
		a = (LPTSTR)malloc((word01.GetWindowTextLengthW() + 1) * sizeof(LPTSTR));
		word01.GetWindowTextW(a, word01.GetWindowTextLengthW() + 1);
		SetTimer(timer01_ID, _wtoi(a) * 1000, macroCallback);
		a_RGB = RGB(238,190,195);
		DeleteObject(a_BRUSH);
		a_BRUSH = a_BRUSH = CreateSolidBrush(a_RGB);
		InvalidateRect(NULL, true);

		free(a);

		break;
	case 3:
		a = (LPTSTR)malloc((word01.GetWindowTextLengthW() + 1) * sizeof(LPTSTR));
		word01.GetWindowTextW(a, word01.GetWindowTextLengthW() + 1);
		c = (LPTSTR)malloc((source01.GetWindowTextLengthW() + 1) * sizeof(LPTSTR));
		source01.GetWindowTextW(c, source01.GetWindowTextLengthW() + 1);
		fwnd = FindWindow(L"TFM_chat", a);
		HWND h_fwnd;
		if(fwnd)
		{
			h_fwnd = ::GetWindow(fwnd->GetSafeHwnd(), GW_CHILD);
			h_fwnd = ::GetNextWindow(h_fwnd, GW_HWNDNEXT);
			h_fwnd = ::GetWindow(h_fwnd, GW_CHILD);
			h_fwnd = ::GetWindow(h_fwnd, GW_CHILD);
			h_fwnd = ::GetNextWindow(h_fwnd, GW_HWNDNEXT);
			h_fwnd = ::GetWindow(h_fwnd, GW_CHILD);
			h_fwnd = ::GetWindow(h_fwnd, GW_CHILD);
			::SendMessage(h_fwnd, WM_SETTEXT, NULL, (LPARAM)c);
			::PostMessage(h_fwnd, WM_KEYDOWN, VK_RETURN, NULL);
			::PostMessage(h_fwnd, WM_KEYUP, VK_RETURN, NULL);
		}


		free(a); free(c);

		break;
	}
}

void C업무용Dlg::copyBtn01Click()
{
	char *txt_multibyte, *P_data;
	HGLOBAL h_data;
	LPTSTR txt_org;

	USES_CONVERSION;
	
	switch(lastIndex)
	{
	case 1:
		//LPCSTR은 멀티바이트, 클립보드에 복사하면 멀티바이트로 저장됨.
		txt_org = (LPTSTR)malloc((result01.GetWindowTextLengthW() + 1) * sizeof(LPTSTR));
		if(!txt_org) return;
		result01.GetWindowTextW(txt_org, result01.GetWindowTextLengthW() + 1);
		txt_multibyte = W2A(txt_org);

		free(txt_org);

		h_data = ::GlobalAlloc(GMEM_MOVEABLE|GMEM_DDESHARE, strlen(txt_multibyte) + 1);
		P_data = (char*)::GlobalLock(h_data);
		if(NULL != P_data)
		{
			memcpy((void*)P_data, txt_multibyte, strlen(txt_multibyte) + 1);
			::GlobalUnlock(h_data);
			if(::OpenClipboard(m_hWnd))
			{
				::EmptyClipboard();
				::SetClipboardData(CF_TEXT, h_data);
				::CloseClipboard();
			}
		}
		break;
	case 2:
		KillTimer(timer01_ID);
		a_RGB = RGB(238,238,238);
		DeleteObject(a_BRUSH);
		a_BRUSH = a_BRUSH = CreateSolidBrush(a_RGB);
		InvalidateRect(NULL, true);
		break;
	}
}

BOOL C업무용Dlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rect;
	GetClientRect(rect);
	pDC->FillSolidRect(rect,a_RGB);
	return TRUE;
	return CDialogEx::OnEraseBkgnd(pDC);
}


HBRUSH C업무용Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.
	switch(pWnd->GetDlgCtrlID())
	{
	case label01_ID:
		pDC->SetBkColor(a_RGB);
		return a_BRUSH;
		break;
	}
	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}
