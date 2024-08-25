
// ������Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "������.h"
#include "������Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C������Dlg ��ȭ ����




void CALLBACK macroCallback(HWND hwnd, UINT a, UINT_PTR b, DWORD c){
	mouse_event(MOUSEEVENTF_MOVE, 2, 0, 0, NULL);
	mouse_event(MOUSEEVENTF_MOVE, -1, 0, 0, NULL);
}

C������Dlg::C������Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C������Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	lastIndex = -1;
}

C������Dlg::~C������Dlg()
{
	DeleteObject(a_BRUSH);
}

void C������Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C������Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(jobKind_ID, &C������Dlg::jobKindSet)
	ON_BN_CLICKED(convertBtn01_ID, &C������Dlg::convertBtn01Click)
	ON_BN_CLICKED(copyBtn01_ID, &C������Dlg::copyBtn01Click)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// C������Dlg �޽��� ó����

BOOL C������Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	RECT a = {30, 10, 200, 30};
	jobKind.Create(WS_VISIBLE | WS_CHILD | WS_VSCROLL | CBS_DROPDOWNLIST, a, this, jobKind_ID);
	jobKind.AddString(_T("�뷮 �����ڵ� ���"));
	jobKind.AddString(_T("���� ������ ��ȯ"));
	jobKind.AddString(_T("ȭ�� ��ȣ�� ����"));
	jobKind.AddString(_T("�ڽ��� �ڵ� �亯"));
	//jobKind.SetCurSel(0);
	//jobKindSet();
	
	a_RGB = RGB(238,238,238);
	a_BRUSH = CreateSolidBrush(a_RGB);
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
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
		//label01.Create(_T("[���� �� �ڸ�]"), WS_VISIBLE, a, this, label01_ID);
		//a.left = 450; a.right = 700;
		//word02.Create(WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL, a, this, word02_ID);
		a.left = 20; a.right = 370; a.top = 80; a.bottom = 700;
		source01.Create(WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL | ES_MULTILINE | ES_WANTRETURN | ES_AUTOVSCROLL, a, this, source01_ID);
		source01.ShowScrollBar(SB_VERT);
		a.left = 380; a.right = 700;
		result01.Create(WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL | ES_MULTILINE | ES_WANTRETURN | ES_AUTOVSCROLL, a, this, result01_ID);
		result01.ShowScrollBar(SB_VERT);
		a.left = 260; a.right = 500; a.top = 10; a.bottom = 40;
		convertBtn01.Create(_T("��  ȯ"), WS_VISIBLE | WS_CHILD, a, this, convertBtn01_ID);

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
		convertBtn01.Create(_T("��  ȯ"), WS_VISIBLE | WS_CHILD, a, this, convertBtn01_ID);
		a.left = 390; a.right = 550; a.top = 260; a.bottom = 550;
		copyBtn01.Create(_T("�����\nŬ�����忡\n����"), WS_VISIBLE | WS_CHILD | BS_MULTILINE, a, this, copyBtn01_ID);

		break;
	case 2:
		lastIndex = 2;

		MoveWindow(rc.left, rc.top, 600, 300);
		a.left = 10; a.right = 600; a.top = 40; a.bottom = 150;
		label01.Create(_T("������ �ð����� ���콺�� ���������� 1�ȼ� �����Դϴ�.\nȭ�� ��ȣ��� 2�и��� �۵��ϱ� ������\n1�� 50�� �̳����� �����ϱ� �ٶ��ϴ�.\n\n�⺻�� : 50"), WS_VISIBLE, a, this, label01_ID);
		a.left = 100; a.right = 230; a.top = 160; a.bottom = 180;
		word01.Create(WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL | ES_NUMBER, a, this, word01_ID);
		word01.SetWindowTextW(L"50");
		a.left = 50; a.right = 150; a.top = 200; a.bottom = 230;
		convertBtn01.Create(_T("�� ��"), WS_VISIBLE | WS_CHILD, a, this, convertBtn01_ID);
		a.left = 180; a.right = 280;
		copyBtn01.Create(_T("�� ��"), WS_VISIBLE | WS_CHILD, a, this, copyBtn01_ID);

		break;
	case 3:
		lastIndex = 3;

		GetWindowRect(&rc);
		MoveWindow(rc.left, rc.top, 600, 600);
		a.left = 10; a.right = 600; a.top = 40; a.bottom = 100;
		label01.Create(_T("�� ����� ���� ����Դϴ�.\n���� �۵����� ���� �� ������\n���� ����� �ǵ�� ���Ŀ� �߰��� �����Դϴ�."), WS_VISIBLE, a, this, label01_ID);
		a.left = 100; a.right = 230; a.top = 110; a.bottom = 130;
		word01.Create(WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL, a, this, word01_ID);
		a.left = 20; a.right = 370; a.top = 150; a.bottom = 550;
		source01.Create(WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL | ES_MULTILINE | ES_WANTRETURN | ES_AUTOVSCROLL, a, this, source01_ID);
		source01.ShowScrollBar(SB_VERT);
		source01.SetWindowTextW(L"��~~");
		a.left = 240; a.right = 350; a.top = 100; a.bottom = 140;
		convertBtn01.Create(_T("�� ��"), WS_VISIBLE | WS_CHILD, a, this, convertBtn01_ID);

		break;
	}
}

void C������Dlg::convertBtn01Click()
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

void C������Dlg::copyBtn01Click()
{
	char *txt_multibyte, *P_data;
	HGLOBAL h_data;
	LPTSTR txt_org;

	USES_CONVERSION;
	
	switch(lastIndex)
	{
	case 1:
		//LPCSTR�� ��Ƽ����Ʈ, Ŭ�����忡 �����ϸ� ��Ƽ����Ʈ�� �����.
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

BOOL C������Dlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CRect rect;
	GetClientRect(rect);
	pDC->FillSolidRect(rect,a_RGB);
	return TRUE;
	return CDialogEx::OnEraseBkgnd(pDC);
}


HBRUSH C������Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  ���⼭ DC�� Ư���� �����մϴ�.
	switch(pWnd->GetDlgCtrlID())
	{
	case label01_ID:
		pDC->SetBkColor(a_RGB);
		return a_BRUSH;
		break;
	}
	// TODO:  �⺻���� �������� ������ �ٸ� �귯�ø� ��ȯ�մϴ�.
	return hbr;
}
