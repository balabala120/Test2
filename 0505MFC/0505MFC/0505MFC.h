
// 0505MFC.h : 0505MFC Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy0505MFCApp:
// �йش����ʵ�֣������ 0505MFC.cpp
//

class CMy0505MFCApp : public CWinApp
{
public:
	CMy0505MFCApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy0505MFCApp theApp;
