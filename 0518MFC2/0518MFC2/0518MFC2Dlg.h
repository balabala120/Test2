
// 0518MFC2Dlg.h : 头文件
//

#pragma once


// CMy0518MFC2Dlg 对话框
class CMy0518MFC2Dlg : public CDialogEx
{
// 构造
public:
	CMy0518MFC2Dlg(CWnd* pParent = NULL);	// 标准构造函数
	void foo(CImage &img, int &sx, int &sy, int &w, int &h);
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY0518MFC2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
