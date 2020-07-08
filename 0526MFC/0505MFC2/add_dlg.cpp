// add_dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "0505MFC2.h"

#include "afxdialogex.h"


// add_dlg 对话框




// add_dlg 消息处理程序
// add_dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "0505MFC2.h"
#include "add_dlg.h"
#include "afxdialogex.h"


// add_dlg 对话框

IMPLEMENT_DYNAMIC(add_dlg, CDialogEx)

add_dlg::add_dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1_ADD, pParent)
	, name(_T(""))
	, id(_T(""))
	, major(_T(""))
	, gender(_T(""))
	, birth(_T(""))
	, phone(_T(""))
	, address(_T(""))
	, picture(_T(""))
{

}

add_dlg::~add_dlg()
{
}

void add_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, name);
	DDX_Text(pDX, IDC_EDIT2, id);
	DDX_Text(pDX, IDC_EDIT3, major);
	DDX_Text(pDX, IDC_EDIT4, gender);
	DDX_Text(pDX, IDC_EDIT5, birth);
	DDX_Text(pDX, IDC_EDIT6, phone);
	DDX_Text(pDX, IDC_EDIT7, address);
	DDX_Text(pDX, IDC_EDIT8, picture);
}


BEGIN_MESSAGE_MAP(add_dlg, CDialogEx)
END_MESSAGE_MAP()


// add_dlg 消息处理程序
