
// 0505MFCDoc.h : CMy0505MFCDoc ��Ľӿ�
//


#pragma once
#include "0505MFCSet.h"


class CMy0505MFCDoc : public CDocument
{
protected: // �������л�����
	CMy0505MFCDoc();
	DECLARE_DYNCREATE(CMy0505MFCDoc)

// ����
public:
	CMy0505MFCSet m_My0505MFCSet;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMy0505MFCDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
