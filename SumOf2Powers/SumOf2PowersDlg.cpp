// SumOf2PowersDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SumOf2Powers.h"
#include "SumOf2PowersDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSumOf2PowersDlg dialog




CSumOf2PowersDlg::CSumOf2PowersDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSumOf2PowersDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSumOf2PowersDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSumOf2PowersDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDCANCEL, &CSumOf2PowersDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &CSumOf2PowersDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSumOf2PowersDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CSumOf2PowersDlg message handlers

BOOL CSumOf2PowersDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSumOf2PowersDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSumOf2PowersDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CSumOf2PowersDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	OnCancel();
}

void CSumOf2PowersDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
char a_ValC[22];
GetDlgItem(IDC_EDIT2)->GetWindowText(a_ValC, 22);
if (a_ValC[0]==0)
{
GetDlgItem(IDC_STATIC1)->SetWindowText("Please enter a value!!!");
return;
}

char b_ValC[22];
GetDlgItem(IDC_EDIT3)->GetWindowText(b_ValC, 22);
if (b_ValC[0]==0)
{
GetDlgItem(IDC_STATIC1)->SetWindowText("Please enter b value!!!");
return;
}

char a_PowC[22];
GetDlgItem(IDC_EDIT4)->GetWindowText(a_PowC, 22);
if (a_PowC[0]==0)
{
GetDlgItem(IDC_STATIC1)->SetWindowText("Please enter a's 2 power!!!");
return;
}

char b_PowC[22];
GetDlgItem(IDC_EDIT5)->GetWindowText(b_PowC, 22);
if (b_PowC[0]==0)
{
GetDlgItem(IDC_STATIC1)->SetWindowText("Please enter b's 2 power!!!");
return;
}

char * pEnd;
long a_Val = strtol(a_ValC,&pEnd,10);
long b_Val = strtol(b_ValC,&pEnd,10);
long a_Pow = strtol(a_PowC,&pEnd,10);
long b_Pow = strtol(b_PowC,&pEnd,10);

long SumResult = (a_Val<<a_Pow)+(b_Val<<b_Pow);
char buf[4*2+1] = {0}; // one extra byte for null
sprintf(buf,"%ld", SumResult);

GetDlgItem(IDC_EDIT1)->SetWindowText(buf);

}

void CSumOf2PowersDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
char Sum_resultC[22];
GetDlgItem(IDC_EDIT1)->GetWindowText(Sum_resultC, 22);
if (Sum_resultC[0]==0)
{
GetDlgItem(IDC_STATIC1)->SetWindowText("Please enter sum result!!!");
return;
}

char a_PowC[22];
GetDlgItem(IDC_EDIT4)->GetWindowText(a_PowC, 22);
if (a_PowC[0]==0)
{
GetDlgItem(IDC_STATIC1)->SetWindowText("Please enter a's 2 power!!!");
return;
}

char b_PowC[22];
GetDlgItem(IDC_EDIT5)->GetWindowText(b_PowC, 22);
if (b_PowC[0]==0)
{
GetDlgItem(IDC_STATIC1)->SetWindowText("Please enter b's 2 power!!!");
return;
}

char * pEnd;
long Sum_Val = strtol(Sum_resultC,&pEnd,10);
long a_Pow = strtol(a_PowC,&pEnd,10);
long b_Pow = strtol(b_PowC,&pEnd,10);

bool SwitchResult = false;

long Min,Max = 0;
if (a_Pow>=b_Pow)
{
Min = b_Pow;
Max = a_Pow;
SwitchResult = false;
}
else
{
Min = a_Pow;
Max = b_Pow;
SwitchResult = true;
}

if ((Sum_Val%(1<<Min))!=0)  // Sum should be divisible to 2^Min
{
GetDlgItem(IDC_STATIC1)->SetWindowText("Sum result invalid!!!");
return;
}

// Updated values:
long NewSum = Sum_Val>>Min;  // we divide Sum with 2^Min
Max = Max-Min;
long New_a_Pow = a_Pow-Min;
long New_b_Pow = b_Pow-Min;

long StartOf_a = NewSum>>Max;
long Current_a = StartOf_a;
long a_multiplied = 0;
long Current_b = 0;
int Count = 0;
char Joined[2000] = {0};
long a_switched = 0;
long b_switched = 0;

while (Count<20&&Current_a!=0)
{
a_multiplied = Current_a<<Max;
Current_b = NewSum-a_multiplied;

a_switched = Current_a;
b_switched = Current_b;

if (SwitchResult)
{
a_switched = Current_b;
b_switched = Current_a;
}

sprintf (Joined, "%s(%ld,%ld); ", Joined, a_switched, b_switched);

Current_a--;
Count++;
}

GetDlgItem(IDC_EDIT6)->SetWindowText(Joined);

}
