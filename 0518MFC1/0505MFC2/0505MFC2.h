
// 0505MFC2.h : 0505MFC2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy0505MFC2App:
// �йش����ʵ�֣������ 0505MFC2.cpp
//

class CMy0505MFC2App : public CWinApp
{
public:
	CMy0505MFC2App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy0505MFC2App theApp;
