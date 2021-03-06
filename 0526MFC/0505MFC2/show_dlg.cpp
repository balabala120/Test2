// show_dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "0505MFC2.h"
#include "show_dlg.h"
#include "afxdialogex.h"


// show_dlg 对话框

IMPLEMENT_DYNAMIC(show_dlg, CDialogEx)

show_dlg::show_dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_SHOW, pParent)
{

}
void show_dlg::getfilepath(CString file)
{
	filename = file;
}
show_dlg::~show_dlg()
{
}

void show_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(show_dlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// show_dlg 消息处理程序


void show_dlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	CRect pic_rect2;
	GetDlgItem(IDC_STATIC_PIC1)->GetClientRect(&pic_rect2);//取得图片控件区域
	CImage img;
	img.Load(filename);
	if (!img.IsNull())
	{
		int sx, sy, w, h;
		foo(img, sx, sy, w, h);
		CDC *pDC = GetDlgItem(IDC_STATIC_PIC1)->GetDC();//IDC_STATIC_PIC1为图片控件的ID
		pDC->SetStretchBltMode(HALFTONE);      //图像不失真
		img.Draw(pDC->m_hDC, sx, sy, w, h);
		ReleaseDC(pDC);
	}
	else
	{
		MessageBox(_T("Load Error"));
	}
}

void show_dlg::foo(CImage &img, int &sx, int &sy, int &w, int &h)
{
	CRect rect;
	GetDlgItem(IDC_STATIC_PIC1)->GetClientRect(&rect);            //取得客户区,IDC_STATIC_PIC1为图片控件的ID
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
