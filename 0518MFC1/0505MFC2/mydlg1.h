#pragma once


// mydlg1 �Ի���

class mydlg1 : public CDialogEx
{
	DECLARE_DYNAMIC(mydlg1)

public:
	mydlg1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~mydlg1();

	CString filename;
	void getFilename(CString file);
	void foo(CImage &img, int &sx, int &sy, int &w, int &h);
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
