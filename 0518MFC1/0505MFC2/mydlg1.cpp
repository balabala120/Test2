// mydlg1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "0505MFC2.h"
#include "mydlg1.h"
#include "afxdialogex.h"


// mydlg1 �Ի���

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


// mydlg1 ��Ϣ�������


void mydlg1::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CRect pic_rect2;
	GetDlgItem(IDC_STATIC2)->GetClientRect(&pic_rect2);//ȡ��ͼƬ�ؼ�����
	CImage img;
	img.Load(filename);
	if (!img.IsNull())
	{
		int sx, sy, w, h;
		foo(img, sx, sy, w, h);
		CDC *pDC = GetDlgItem(IDC_STATIC2)->GetDC();//IDC_STATIC1ΪͼƬ�ؼ���ID
		pDC->SetStretchBltMode(HALFTONE);      //ͼ��ʧ��
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
	GetDlgItem(IDC_STATIC2)->GetClientRect(&rect);            //ȡ�ÿͻ���,IDC_STATIC2ΪͼƬ�ؼ���ID
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