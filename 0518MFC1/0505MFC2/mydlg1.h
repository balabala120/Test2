#pragma once


// mydlg1 对话框

class mydlg1 : public CDialogEx
{
	DECLARE_DYNAMIC(mydlg1)

public:
	mydlg1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~mydlg1();

	CString filename;
	void getFilename(CString file);
	void foo(CImage &img, int &sx, int &sy, int &w, int &h);
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
