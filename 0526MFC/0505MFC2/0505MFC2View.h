
// 0505MFC2View.h : CMy0505MFC2View ��Ľӿ�
//

#pragma once

class CMy0505MFC2Set;

class CMy0505MFC2View : public CRecordView
{
protected: // �������л�����
	CMy0505MFC2View();
	DECLARE_DYNCREATE(CMy0505MFC2View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY0505MFC2_FORM };
#endif
	CMy0505MFC2Set* m_pSet;
	CRect  pic_rect;
// ����
public:
	CMy0505MFC2Doc* GetDocument() const;
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
	virtual ~CMy0505MFC2View();
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
	CString major;
	CString gender;
	CString birth;
	CString phone;
	CString address;
	afx_msg void OnPaint();
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void Onadd();
	afx_msg void Onmodify();
	afx_msg void Ondelete();
	afx_msg void Oncheck();
	afx_msg void Onsort();
	afx_msg void OnBnClickedButton2();
};

#ifndef _DEBUG  // 0505MFC2View.cpp �еĵ��԰汾
inline CMy0505MFC2Doc* CMy0505MFC2View::GetDocument() const
   { return reinterpret_cast<CMy0505MFC2Doc*>(m_pDocument); }
#endif

