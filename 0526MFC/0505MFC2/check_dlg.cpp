// check_dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "0505MFC2.h"

#include "afxdialogex.h"

// check_dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "0505MFC2.h"
#include "check_dlg.h"
#include "afxdialogex.h"


// check_dlg 对话框

IMPLEMENT_DYNAMIC(check_dlg, CDialogEx)

check_dlg::check_dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_CHECK, pParent)
	, query_criteria(_T(""))
{

}

check_dlg::~check_dlg()
{
}

void check_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, query_criteria);
}


BEGIN_MESSAGE_MAP(check_dlg, CDialogEx)
END_MESSAGE_MAP()


// check_dlg 消息处理程序
