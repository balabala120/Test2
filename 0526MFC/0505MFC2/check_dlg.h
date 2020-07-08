#pragma once




#pragma once


// check_dlg 对话框

class check_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(check_dlg)

public:
	check_dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~check_dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CHECK };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString query_criteria;
};
