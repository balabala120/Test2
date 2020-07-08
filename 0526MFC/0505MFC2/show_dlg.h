#pragma once


// show_dlg 对话框

class show_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(show_dlg)

public:
	show_dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~show_dlg();
	CString filename;
	void getfilepath(CString path);
	void foo(CImage &img, int &sx, int &sy, int &w, int &h);
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SHOW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
