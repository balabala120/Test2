
// 0518MFC2.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy0518MFC2App: 
// �йش����ʵ�֣������ 0518MFC2.cpp
//

class CMy0518MFC2App : public CWinApp
{
public:
	CMy0518MFC2App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy0518MFC2App theApp;