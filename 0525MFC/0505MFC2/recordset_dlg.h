#pragma once


// recordset_dlg 对话框

class recordset_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(recordset_dlg)

public:
	recordset_dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~recordset_dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_RECORDSET };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
