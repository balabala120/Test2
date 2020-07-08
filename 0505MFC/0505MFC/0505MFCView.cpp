
// 0505MFCView.cpp : CMy0505MFCView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0505MFC.h"
#endif

#include "0505MFCSet.h"
#include "0505MFCDoc.h"
#include "0505MFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0505MFCView

IMPLEMENT_DYNCREATE(CMy0505MFCView, CRecordView)

BEGIN_MESSAGE_MAP(CMy0505MFCView, CRecordView)
	ON_EN_CHANGE(IDC_EDIT4, &CMy0505MFCView::OnEnChangeEdit4)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy0505MFCView::OnBnClickedButton1)
END_MESSAGE_MAP()

// CMy0505MFCView ����/����

CMy0505MFCView::CMy0505MFCView()
	: CRecordView(IDD_MY0505MFC_FORM)
	, num(0)
	, name(_T(""))
	, id(_T(""))
	, gender(_T(""))
	, major(_T(""))
	, birth(_T(""))
	, phone(_T(""))
	, address(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CMy0505MFCView::~CMy0505MFCView()
{
}

void CMy0505MFCView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column4);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT7, m_pSet->column5);
	DDX_Text(pDX, IDC_EDIT8, m_pSet->column6);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->column7);
}

BOOL CMy0505MFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMy0505MFCView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_My0505MFCSet;
	CRecordView::OnInitialUpdate();

}


// CMy0505MFCView ���

#ifdef _DEBUG
void CMy0505MFCView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMy0505MFCView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMy0505MFCDoc* CMy0505MFCView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0505MFCDoc)));
	return (CMy0505MFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy0505MFCView ���ݿ�֧��
CRecordset* CMy0505MFCView::OnGetRecordset()
{
	return m_pSet;
}



// CMy0505MFCView ��Ϣ�������


void CMy0505MFCView::OnEnChangeEdit4()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CRecordView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMy0505MFCView::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString filename;
	m_pSet->GetFieldValue(short(8), filename);//�Ӽ�¼����ǰ��¼����ȡ��8���ֶ�ֵ����Ƭ·��(��һ����0)������filename
	CImage img;
	img.Load(filename);
	if (!img.IsNull())
	{
		int sx, sy, w, h;
		foo(img, sx, sy, w, h);
		CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();//IDC_STATIC1ΪͼƬ�ؼ���ID
		pDC->SetStretchBltMode(HALFTONE);      //ͼ��ʧ��
		img.Draw(pDC->m_hDC,sx, sy, w, h);
		ReleaseDC(pDC);
	}
	else
	{
		MessageBox(_T("Load Error"));
	}
}


void CMy0505MFCView::foo(CImage &img, int &sx, int &sy, int &w, int &h)
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