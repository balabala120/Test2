// mydlg1.cpp : 实现文件
//

#include "stdafx.h"
#include "0505MFC2.h"
#include "mydlg1.h"
#include "afxdialogex.h"


// mydlg1 对话框

IMPLEMENT_DYNAMIC(mydlg1, CDialogEx)

mydlg1::mydlg1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
	filename = "";

}

void mydlg1::getFilename(CString file)
{
	filename = file;
}

mydlg1::~mydlg1()
{
}

void mydlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(mydlg1, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// mydlg1 消息处理程序


void mydlg1::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	CRect pic_rect2;
	GetDlgItem(IDC_STATIC2)->GetClientRect(&pic_rect2);//取得图片控件区域
	CImage img;
	img.Load(filename);
	if (!img.IsNull())
	{
		int sx, sy, w, h;
		foo(img, sx, sy, w, h);
		CDC *pDC = GetDlgItem(IDC_STATIC2)->GetDC();//IDC_STATIC1为图片控件的ID
		pDC->SetStretchBltMode(HALFTONE);      //图像不失真
		img.Draw(pDC->m_hDC, sx, sy, w, h);
		ReleaseDC(pDC);
	}
	else
	{
		MessageBox(_T("Load Error"));
	}
}

void mydlg1::foo(CImage &img, int &sx, int &sy, int &w, int &h)
{
	CRect rect;
	GetDlgItem(IDC_STATIC2)->GetClientRect(&rect);            //取得客户区,IDC_STATIC2为图片控件的ID
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