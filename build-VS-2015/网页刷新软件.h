
// ��ҳˢ�����.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C��ҳˢ�����App: 
// �йش����ʵ�֣������ ��ҳˢ�����.cpp
//

class C��ҳˢ�����App : public CWinApp
{
public:
	C��ҳˢ�����App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C��ҳˢ�����App theApp;