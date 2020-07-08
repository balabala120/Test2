
// 0505MFC2View.h : CMy0505MFC2View 类的接口
//

#pragma once

class CMy0505MFC2Set;

class CMy0505MFC2View : public CRecordView
{
protected: // 仅从序列化创建
	CMy0505MFC2View();
	DECLARE_DYNCREATE(CMy0505MFC2View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY0505MFC2_FORM };
#endif
	CMy0505MFC2Set* m_pSet;
	CRect  pic_rect;
// 特性
public:
	CMy0505MFC2Doc* GetDocument() const;
	void foo(CImage &img, int &sx, int &sy, int &w, int &h);
// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMy0505MFC2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // 0505MFC2View.cpp 中的调试版本
inline CMy0505MFC2Doc* CMy0505MFC2View::GetDocument() const
   { return reinterpret_cast<CMy0505MFC2Doc*>(m_pDocument); }
#endif

