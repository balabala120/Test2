#pragma once




#pragma once


// check_dlg �Ի���

class check_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(check_dlg)

public:
	check_dlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~check_dlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CHECK };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString query_criteria;
};
