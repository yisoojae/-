
// 업무용Dlg.h : 헤더 파일
//

#pragma once

#define macroBtnMax 5

#define jobKind_ID 1001
#define word01_ID 1002
#define word02_ID 1003
#define source01_ID 1004
#define label01_ID 1005
#define result01_ID 1006
#define convertBtn01_ID 1007
#define copyBtn01_ID 1008
#define macroBtn_ID 2001
#define macroDelBtn_ID 3001
#define timer01_ID 9624956
#define dupSize 2000

// C업무용Dlg 대화 상자
class C업무용Dlg : public CDialogEx
{
// 생성입니다.
public:
	C업무용Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.
	~C업무용Dlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	int lastIndex, macroNum;

	COLORREF a_RGB;
	HBRUSH a_BRUSH;

	CComboBox jobKind;
	void jobKindSet();

	CEdit word01, word02, source01, result01;
	CStatic label01;

	CButton convertBtn01, copyBtn01;
	void convertBtn01Click();
	void copyBtn01Click();
	CButton** macroBtn;
	CButton** macroDelBtn;
	void macroBtnClick(UINT nID);
	void macroDelBtnClick(UINT nID);

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
