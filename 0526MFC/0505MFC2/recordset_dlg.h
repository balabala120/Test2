#pragma once


// recordset_dlg �Ի���

class recordset_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(recordset_dlg)

public:
	recordset_dlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~recordset_dlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_RECORDSET };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
