#pragma once


// show_dlg �Ի���

class show_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(show_dlg)

public:
	show_dlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~show_dlg();
	CString filename;
	void getfilepath(CString path);
	void foo(CImage &img, int &sx, int &sy, int &w, int &h);
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SHOW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
