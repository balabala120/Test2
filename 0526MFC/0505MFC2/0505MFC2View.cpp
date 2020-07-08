
// 0505MFC2View.cpp : CMy0505MFC2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0505MFC2.h"
#endif

#include "0505MFC2Set.h"
#include "0505MFC2Doc.h"
#include "0505MFC2View.h"
#include "add_dlg.h"
#include "sort_dlg.h"
#include "check_dlg.h"
#include "show_dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0505MFC2View

IMPLEMENT_DYNCREATE(CMy0505MFC2View, CRecordView)

BEGIN_MESSAGE_MAP(CMy0505MFC2View, CRecordView)
	ON_WM_PAINT()
	ON_COMMAND(ID_RECORD_FIRST, &CMy0505MFC2View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMy0505MFC2View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMy0505MFC2View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMy0505MFC2View::OnRecordLast)
	ON_COMMAND(add, &CMy0505MFC2View::Onadd)
	ON_COMMAND(modify, &CMy0505MFC2View::Onmodify)
	ON_COMMAND(delete, &CMy0505MFC2View::Ondelete)
	ON_COMMAND(check, &CMy0505MFC2View::Oncheck)
	ON_COMMAND(sort, &CMy0505MFC2View::Onsort)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy0505MFC2View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CMy0505MFC2View 构造/析构

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
	// TODO: 在此处添加构造代码

}

CMy0505MFC2View::~CMy0505MFC2View()
{
}

void CMy0505MFC2View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
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
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMy0505MFC2View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_My0505MFC2Set;
	CRecordView::OnInitialUpdate();

}


// CMy0505MFC2View 诊断

#ifdef _DEBUG
void CMy0505MFC2View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMy0505MFC2View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMy0505MFC2Doc* CMy0505MFC2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0505MFC2Doc)));
	return (CMy0505MFC2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0505MFC2View 数据库支持
CRecordset* CMy0505MFC2View::OnGetRecordset()
{
	return m_pSet;
}



// CMy0505MFC2View 消息处理程序






void CMy0505MFC2View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()
	GetDlgItem(IDC_STATIC1)->GetClientRect(&pic_rect);//取得图片控件区域
	CString filename;
	m_pSet->GetFieldValue(short(8), filename);//从记录集当前记录，读取第8个字段值即相片路径，放入filename
	CImage img;
	img.Load(filename);
	if (!img.IsNull())
	{
		int sx, sy, w, h;
		foo(img, sx, sy, w, h);
		CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();//IDC_STATIC1为图片控件的ID
		pDC->SetStretchBltMode(HALFTONE);      //图像不失真
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


void CMy0505MFC2View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	InvalidateRect(&pic_rect, true);
}


void CMy0505MFC2View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	InvalidateRect(&pic_rect, true);
}


void CMy0505MFC2View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if(m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	InvalidateRect(&pic_rect, true);
}


void CMy0505MFC2View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	InvalidateRect(&pic_rect, true);
}

void CMy0505MFC2View::Onadd()
{
	// TODO: 在此添加命令处理程序代码
	add_dlg dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		m_pSet->AddNew();
		m_pSet->column1 = dlg.name;
		m_pSet->column2 = dlg.id;
		m_pSet->column3 = dlg.major;
		m_pSet->column4 = dlg.gender;
		m_pSet->column5 = dlg.birth;
		m_pSet->column6 = dlg.phone;
		m_pSet->column7 = dlg.address;
		m_pSet->column8 = dlg.picture;
		m_pSet->Update();
	}
}


void CMy0505MFC2View::Onmodify()
{
	// TODO: 在此添加命令处理程序代码
	add_dlg dlg;
	dlg.name = m_pSet->column1;
	dlg.id = m_pSet->column2;
	dlg.major = m_pSet->column3;
	dlg.gender = m_pSet->column4;
	dlg.birth = m_pSet->column5;
	dlg.phone = m_pSet->column6;
	dlg.address = m_pSet->column7;
	dlg.picture = m_pSet->column8;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		m_pSet->Edit();
		m_pSet->column1 = dlg.name;
		m_pSet->column2 = dlg.id;
		m_pSet->column3 = dlg.major;
		m_pSet->column4 = dlg.gender;
		m_pSet->column5 = dlg.birth;
		m_pSet->column6 = dlg.phone;
		m_pSet->column7 = dlg.address;
		m_pSet->column8 = dlg.picture;
		m_pSet->Update();
	}
}


void CMy0505MFC2View::Ondelete()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->Delete();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
}


void CMy0505MFC2View::Oncheck()
{
	// TODO: 在此添加命令处理程序代码
	check_dlg dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		m_pSet->m_strFilter = dlg.query_criteria;//查询条件
		m_pSet->Requery();
	}
}


void CMy0505MFC2View::Onsort()
{
	// TODO: 在此添加命令处理程序代码
	sort_dlg dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		m_pSet->m_strSort = dlg.sort_criteria;//排序条件
		m_pSet->Requery();
	}
}


void CMy0505MFC2View::OnBnClickedButton2()//放大显示相片
{
	// TODO: 在此添加控件通知处理程序代码
	CString filename;
	filename = "C:\\Users\\MI\\Pictures\\001刘一.jpg";
	m_pSet->GetFieldValue(short(8), filename);//从记录集当前记录，读取第8个字段值即相片路径，放入filename
	show_dlg *dlg = new show_dlg;
	dlg->Create(IDD_DIALOG_SHOW);
	dlg->getfilepath(filename);
	dlg->ShowWindow(1);

}
