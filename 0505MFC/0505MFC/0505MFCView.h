
// 0505MFCView.h : CMy0505MFCView ��Ľӿ�
//

#pragma once

class CMy0505MFCSet;

class CMy0505MFCView : public CRecordView
{
protected: // �������л�����
	CMy0505MFCView();
	DECLARE_DYNCREATE(CMy0505MFCView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY0505MFC_FORM };
#endif
	CMy0505MFCSet* m_pSet;

// ����
public:
	CMy0505MFCDoc* GetDocument() const;
	void foo(CImage &img, int &sx, int &sy, int &w, int &h);
// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CMy0505MFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	int num;
	CString name;
	CString id;
	CString gender;
	CString major;
	afx_msg void OnEnChangeEdit4();
	CString birth;
	CString phone;
	CString address;
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // 0505MFCView.cpp �еĵ��԰汾
inline CMy0505MFCDoc* CMy0505MFCView::GetDocument() const
   { return reinterpret_cast<CMy0505MFCDoc*>(m_pDocument); }
#endif

