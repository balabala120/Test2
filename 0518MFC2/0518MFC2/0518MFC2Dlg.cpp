
// 0518MFC2Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "0518MFC2.h"
#include "0518MFC2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy0518MFC2Dlg 对话框



CMy0518MFC2Dlg::CMy0518MFC2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY0518MFC2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy0518MFC2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy0518MFC2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CMy0518MFC2Dlg 消息处理程序

BOOL CMy0518MFC2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy0518MFC2Dlg::foo(CImage &img, int &sx, int &sy, int &w, int &h)
{
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);            //取得客户区,IDC_STATIC1为图片控件的ID
	float rect_ratio = 1.0*rect.Width() / rect.Height();     //计算客户区的宽高比
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();   //计算图片的宽高比
	if (rect_ratio > img_ratio)                             //如果客户区宽高比更大（同样高度时图片控件更宽）
	{
		h = rect.Height();                                 //以客户区高度为高度
		w = img_ratio*h;                                   //按比例缩放图片的宽度
		sx = (rect.Width() - w) / 2;                      //左上角坐标计算
		sy = 0;                                          //相对于客户区来讲   y=0
	}
	else
	{
		w = rect.Width();                             //以客户区宽度为宽度
		h = w / img_ratio;                             //按比例缩放图片的高度
		sx = 0;                                     //相对于客户区来讲   x=0
		sy = (rect.Height() - h) / 2;                //左上角坐标计算
	}

}



void CMy0518MFC2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMy0518MFC2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}

	CString filename;
	filename = "C:\\Users\\MI\\Pictures\\001刘一.jpg";
	CImage img;
	img.Load(filename);
	if (!img.IsNull())
	{
		int sx, sy, w, h;
		foo(img, sx, sy, w, h);
		CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();//IDC_STATIC为图片控件的ID
		pDC->SetStretchBltMode(HALFTONE);      //图像不失真
		img.Draw(pDC->m_hDC, sx, sy, w, h);
		ReleaseDC(pDC);
	}
	else
	{
		MessageBox(_T("Load Error"));
	}

}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMy0518MFC2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

