
// ������Dlg.h: ��� ����
//

#pragma once

#define jobKind_ID 1001
#define word01_ID 1002
#define word02_ID 1003
#define source01_ID 1004
#define label01_ID 1005
#define result01_ID 1006
#define convertBtn01_ID 1007
#define copyBtn01_ID 1008
#define timer01_ID 9624956

// C������Dlg ��ȭ ����
class C������Dlg : public CDialogEx
{
	// �����Դϴ�.
public:
	C������Dlg(CWnd* pParent = nullptr);	// ǥ�� �������Դϴ�.
	~C������Dlg();

	// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


	// �����Դϴ�.
protected:
	HICON m_hIcon;

	int lastIndex;

	COLORREF a_RGB;
	HBRUSH a_BRUSH;

	CComboBox jobKind;
	void jobKindSet();

	CEdit word01, word02, source01, result01;
	CStatic label01;

	CButton convertBtn01, copyBtn01;
	void convertBtn01Click();
	void copyBtn01Click();

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
