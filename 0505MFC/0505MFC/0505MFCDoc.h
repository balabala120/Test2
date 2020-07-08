
// 0505MFCDoc.h : CMy0505MFCDoc 类的接口
//


#pragma once
#include "0505MFCSet.h"


class CMy0505MFCDoc : public CDocument
{
protected: // 仅从序列化创建
	CMy0505MFCDoc();
	DECLARE_DYNCREATE(CMy0505MFCDoc)

// 特性
public:
	CMy0505MFCSet m_My0505MFCSet;

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CMy0505MFCDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
