#pragma once


// sort_dlg �Ի���

class sort_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(sort_dlg)

public:
	sort_dlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~sort_dlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SORT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString sort_criteria;
};
