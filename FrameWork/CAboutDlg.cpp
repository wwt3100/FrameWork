// CAboutDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "CAboutDlg.h"
#include "CFrameWorkDlg.h"
#include "afxdialogex.h"


// CAboutDlg 对话框

IMPLEMENT_DYNAMIC(CAboutDlg, CDialogEx)

CAboutDlg::CAboutDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_ABOUT, pParent)
{

}

CAboutDlg::~CAboutDlg()
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CAboutDlg 消息处理程序


BOOL CAboutDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CFrameWorkDlg *pParent = (CFrameWorkDlg*)GetParent();
	SetIcon(pParent->m_hIcon, FALSE);
	((CStatic*)GetDlgItem(IDI_LOGO))->SetIcon(pParent->m_hIcon);
	GetDlgItem(IDS_APPNAME)->SetWindowText(pParent->m_title);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
