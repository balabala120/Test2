// recordset_dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "0505MFC2.h"
#include "recordset_dlg.h"
#include "afxdialogex.h"


// recordset_dlg 对话框

IMPLEMENT_DYNAMIC(recordset_dlg, CDialogEx)

recordset_dlg::recordset_dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_RECORDSET, pParent)
{

}

recordset_dlg::~recordset_dlg()
{
}

void recordset_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(recordset_dlg, CDialogEx)
END_MESSAGE_MAP()


// recordset_dlg 消息处理程序
