
// 0505MFC2Doc.h : CMy0505MFC2Doc ��Ľӿ�
//


#pragma once
#include "0505MFC2Set.h"


class CMy0505MFC2Doc : public CDocument
{
protected: // �������л�����
	CMy0505MFC2Doc();
	DECLARE_DYNCREATE(CMy0505MFC2Doc)

// ����
public:
	CMy0505MFC2Set m_My0505MFC2Set;

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
	virtual ~CMy0505MFC2Doc();
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
