#pragma once


// sort_dlg 对话框

class sort_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(sort_dlg)

public:
	sort_dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~sort_dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SORT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString sort_criteria;
};
