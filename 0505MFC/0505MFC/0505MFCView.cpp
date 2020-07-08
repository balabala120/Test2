
// 0505MFCView.cpp : CMy0505MFCView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CMy0505MFCView 构造/析构

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
	// TODO: 在此处添加构造代码

}

CMy0505MFCView::~CMy0505MFCView()
{
}

void CMy0505MFCView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
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
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMy0505MFCView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_My0505MFCSet;
	CRecordView::OnInitialUpdate();

}


// CMy0505MFCView 诊断

#ifdef _DEBUG
void CMy0505MFCView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMy0505MFCView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMy0505MFCDoc* CMy0505MFCView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0505MFCDoc)));
	return (CMy0505MFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy0505MFCView 数据库支持
CRecordset* CMy0505MFCView::OnGetRecordset()
{
	return m_pSet;
}



// CMy0505MFCView 消息处理程序


void CMy0505MFCView::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CRecordView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMy0505MFCView::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString filename;
	m_pSet->GetFieldValue(short(8), filename);//从记录集当前记录，读取第8个字段值即相片路径(第一个是0)，放入filename
	CImage img;
	img.Load(filename);
	if (!img.IsNull())
	{
		int sx, sy, w, h;
		foo(img, sx, sy, w, h);
		CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();//IDC_STATIC1为图片控件的ID
		pDC->SetStretchBltMode(HALFTONE);      //图像不失真
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
	GetDlgItem(IDC_STATIC1)->GetClientRect(&rect);            //取得客户区,IDC_STATIC1为图片控件的ID
	float rect_ratio = 1.0*rect.Width() / rect.Height();     //计算客户区的宽高比
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();   //计算图片的宽高比
	if (rect_ratio > img_ratio)                             //如果客户区宽高比更大（同样高度时图片控件更宽）
	{
		h = rect.Height();                                 //以客户区高度为高度
		w = img_ratio*h;                                   //按比例缩放图片的宽度
		sx = (rect.Width() - w) / 2;                      //左上角坐标计算
		sy = 0;                                          //相对于客户区来讲   y=0
	}
	else
	{
		w = rect.Width();                             //以客户区宽度为宽度
		h = w / img_ratio;                             //按比例缩放图片的高度
		sx = 0;                                     //相对于客户区来讲   x=0
		sy = (rect.Height() - h) / 2;                //左上角坐标计算
	}

}