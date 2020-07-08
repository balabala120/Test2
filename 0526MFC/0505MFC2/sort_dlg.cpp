// sort_dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "0505MFC2.h"
#include "sort_dlg.h"
#include "afxdialogex.h"


// sort_dlg 对话框

IMPLEMENT_DYNAMIC(sort_dlg, CDialogEx)

sort_dlg::sort_dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_SORT, pParent)
	, sort_criteria(_T(""))
{

}

sort_dlg::~sort_dlg()
{
}

void sort_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, sort_criteria);
}


BEGIN_MESSAGE_MAP(sort_dlg, CDialogEx)
END_MESSAGE_MAP()


// sort_dlg 消息处理程序
