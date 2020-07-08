
// 0505MFC2View.cpp : CMy0505MFC2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0505MFC2.h"
#endif

#include "0505MFC2Set.h"
#include "0505MFC2Doc.h"
#include "0505MFC2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0505MFC2View

IMPLEMENT_DYNCREATE(CMy0505MFC2View, CRecordView)

BEGIN_MESSAGE_MAP(CMy0505MFC2View, CRecordView)
	ON_EN_CHANGE(IDC_EDIT1, &CMy0505MFC2View::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CMy0505MFC2View::OnEnChangeEdit2)
	ON_WM_PAINT()
	ON_COMMAND(ID_RECORD_FIRST, &CMy0505MFC2View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMy0505MFC2View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMy0505MFC2View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMy0505MFC2View::OnRecordLast)
END_MESSAGE_MAP()

// CMy0505MFC2View ����/����

CMy0505MFC2View::CMy0505MFC2View()
	: CRecordView(IDD_MY0505MFC2_FORM)
	, num(0)
	, name(_T(""))
	, id(_T(""))
	, major(_T(""))
	, gender(_T(""))
	, birth(_T(""))
	, phone(_T(""))
	, address(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CMy0505MFC2View::~CMy0505MFC2View()
{
}

void CMy0505MFC2View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column4);
	DDX_Text(pDX, IDC_EDIT7, m_pSet->column5);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->column6);
	DDX_Text(pDX, IDC_EDIT8, m_pSet->column7);

}

BOOL CMy0505MFC2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMy0505MFC2View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_My0505MFC2Set;
	CRecordView::OnInitialUpdate();

}


// CMy0505MFC2View ���

#ifdef _DEBUG
void CMy0505MFC2View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMy0505MFC2View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMy0505MFC2Doc* CMy0505MFC2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0505MFC2Doc)));
	return (CMy0505MFC2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0505MFC2View ���ݿ�֧��
CRecordset* CMy0505MFC2View::OnGetRecordset()
{
	return m_pSet;
}



// CMy0505MFC2View ��Ϣ�������


void CMy0505MFC2View::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CRecordView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMy0505MFC2View::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CRecordView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMy0505MFC2View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()
	GetDlgItem(IDC_STATIC1)->GetClientRect(&pic_rect);//ȡ��ͼƬ�ؼ�����
	CString filename;
	m_pSet->GetFieldValue(short(8), filename);//�Ӽ�¼����ǰ��¼����ȡ��8���ֶ�ֵ����Ƭ·��������filename
	CImage img;
	img.Load(filename);
	if (!img.IsNull())
	{
		int sx, sy, w, h;
		foo(img, sx, sy, w, h);
		CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();//IDC_STATIC1ΪͼƬ�ؼ���ID
		pDC->SetStretchBltMode(HALFTONE);      //ͼ��ʧ��
		img.Draw(pDC->m_hDC, sx, sy, w, h);
		ReleaseDC(pDC);
	}
	else
	{
		MessageBox(_T("Load Error"));
	}
}

void CMy0505MFC2View::foo(CImage &img, int &sx, int &sy, int &w, int &h)
{
	CRect rect;
	GetDlgItem(IDC_STATIC1)->GetClientRect(&rect);            //ȡ�ÿͻ���,IDC_STATIC1ΪͼƬ�ؼ���ID
	float rect_ratio = 1.0*rect.Width() / rect.Height();     //����ͻ����Ŀ�߱�
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();   //����ͼƬ�Ŀ�߱�
	if (rect_ratio > img_ratio)                             //����ͻ�����߱ȸ���ͬ���߶�ʱͼƬ�ؼ�����
	{
		h = rect.Height();                                 //�Կͻ����߶�Ϊ�߶�
		w = img_ratio*h;                                   //����������ͼƬ�Ŀ��
		sx = (rect.Width() - w) / 2;                      //���Ͻ��������
		sy = 0;                                          //����ڿͻ�������   y=0
	}
	else
	{
		w = rect.Width();                             //�Կͻ������Ϊ���
		h = w / img_ratio;                             //����������ͼƬ�ĸ߶�
		sx = 0;                                     //����ڿͻ�������   x=0
		sy = (rect.Height() - h) / 2;                //���Ͻ��������
	}

}


void CMy0505MFC2View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
	InvalidateRect(&pic_rect, true);
}


void CMy0505MFC2View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	InvalidateRect(&pic_rect, true);
}


void CMy0505MFC2View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if(m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	InvalidateRect(&pic_rect, true);
}


void CMy0505MFC2View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);
	InvalidateRect(&pic_rect, true);
}
