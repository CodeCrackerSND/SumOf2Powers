// SumOf2Powers.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CSumOf2PowersApp:
// See SumOf2Powers.cpp for the implementation of this class
//

class CSumOf2PowersApp : public CWinApp
{
public:
	CSumOf2PowersApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CSumOf2PowersApp theApp;