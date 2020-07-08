#pragma once



#pragma once


// add_dlg 对话框

class add_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(add_dlg)

public:
	add_dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~add_dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1_ADD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString name;
	CString id;
	CString major;
	CString gender;
	CString birth;
	CString phone;
	CString address;
	CString picture;
};
