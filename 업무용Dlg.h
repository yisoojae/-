
// ������Dlg.h : ��� ����
//

#pragma once

#define jobKind_ID 1001
#define word01_ID 1002
#define word02_ID 1003
#define source01_ID 1004
#define label01_ID 1005
#define result01_ID 1006
#define convertBtn01_ID 1007

// C������Dlg ��ȭ ����
class C������Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	C������Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	CComboBox jobKind;
	void jobKindSet();

	CEdit word01, word02, source01, result01;
	CStatic label01;

	CButton convertBtn01;
	void convertBtn01Click();

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
