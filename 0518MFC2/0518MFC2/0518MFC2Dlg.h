
// 0518MFC2Dlg.h : ͷ�ļ�
//

#pragma once


// CMy0518MFC2Dlg �Ի���
class CMy0518MFC2Dlg : public CDialogEx
{
// ����
public:
	CMy0518MFC2Dlg(CWnd* pParent = NULL);	// ��׼���캯��
	void foo(CImage &img, int &sx, int &sy, int &w, int &h);
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY0518MFC2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
