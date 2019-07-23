// CFrameWorkDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "CFrameWorkDlg.h"
#include "CAboutDlg.h"
#include "afxdialogex.h"

const UINT16 wCRC16Table[] = {
	0x0000, 0xC0C1, 0xC181, 0x0140, 0xC301, 0x03C0, 0x0280, 0xC241,
	0xC601, 0x06C0, 0x0780, 0xC741, 0x0500, 0xC5C1, 0xC481, 0x0440,
	0xCC01, 0x0CC0, 0x0D80, 0xCD41, 0x0F00, 0xCFC1, 0xCE81, 0x0E40,
	0x0A00, 0xCAC1, 0xCB81, 0x0B40, 0xC901, 0x09C0, 0x0880, 0xC841,
	0xD801, 0x18C0, 0x1980, 0xD941, 0x1B00, 0xDBC1, 0xDA81, 0x1A40,
	0x1E00, 0xDEC1, 0xDF81, 0x1F40, 0xDD01, 0x1DC0, 0x1C80, 0xDC41,
	0x1400, 0xD4C1, 0xD581, 0x1540, 0xD701, 0x17C0, 0x1680, 0xD641,
	0xD201, 0x12C0, 0x1380, 0xD341, 0x1100, 0xD1C1, 0xD081, 0x1040,
	0xF001, 0x30C0, 0x3180, 0xF141, 0x3300, 0xF3C1, 0xF281, 0x3240,
	0x3600, 0xF6C1, 0xF781, 0x3740, 0xF501, 0x35C0, 0x3480, 0xF441,
	0x3C00, 0xFCC1, 0xFD81, 0x3D40, 0xFF01, 0x3FC0, 0x3E80, 0xFE41,
	0xFA01, 0x3AC0, 0x3B80, 0xFB41, 0x3900, 0xF9C1, 0xF881, 0x3840,
	0x2800, 0xE8C1, 0xE981, 0x2940, 0xEB01, 0x2BC0, 0x2A80, 0xEA41,
	0xEE01, 0x2EC0, 0x2F80, 0xEF41, 0x2D00, 0xEDC1, 0xEC81, 0x2C40,
	0xE401, 0x24C0, 0x2580, 0xE541, 0x2700, 0xE7C1, 0xE681, 0x2640,
	0x2200, 0xE2C1, 0xE381, 0x2340, 0xE101, 0x21C0, 0x2080, 0xE041,
	0xA001, 0x60C0, 0x6180, 0xA141, 0x6300, 0xA3C1, 0xA281, 0x6240,
	0x6600, 0xA6C1, 0xA781, 0x6740, 0xA501, 0x65C0, 0x6480, 0xA441,
	0x6C00, 0xACC1, 0xAD81, 0x6D40, 0xAF01, 0x6FC0, 0x6E80, 0xAE41,
	0xAA01, 0x6AC0, 0x6B80, 0xAB41, 0x6900, 0xA9C1, 0xA881, 0x6840,
	0x7800, 0xB8C1, 0xB981, 0x7940, 0xBB01, 0x7BC0, 0x7A80, 0xBA41,
	0xBE01, 0x7EC0, 0x7F80, 0xBF41, 0x7D00, 0xBDC1, 0xBC81, 0x7C40,
	0xB401, 0x74C0, 0x7580, 0xB541, 0x7700, 0xB7C1, 0xB681, 0x7640,
	0x7200, 0xB2C1, 0xB381, 0x7340, 0xB101, 0x71C0, 0x7080, 0xB041,
	0x5000, 0x90C1, 0x9181, 0x5140, 0x9301, 0x53C0, 0x5280, 0x9241,
	0x9601, 0x56C0, 0x5780, 0x9741, 0x5500, 0x95C1, 0x9481, 0x5440,
	0x9C01, 0x5CC0, 0x5D80, 0x9D41, 0x5F00, 0x9FC1, 0x9E81, 0x5E40,
	0x5A00, 0x9AC1, 0x9B81, 0x5B40, 0x9901, 0x59C0, 0x5880, 0x9841,
	0x8801, 0x48C0, 0x4980, 0x8941, 0x4B00, 0x8BC1, 0x8A81, 0x4A40,
	0x4E00, 0x8EC1, 0x8F81, 0x4F40, 0x8D01, 0x4DC0, 0x4C80, 0x8C41,
	0x4400, 0x84C1, 0x8581, 0x4540, 0x8701, 0x47C0, 0x4680, 0x8641,
	0x8201, 0x42C0, 0x4380, 0x8341, 0x4100, 0x81C1, 0x8081, 0x4040 };

AFX_API_EXPORT UINT16 WINAPI  calculate_CRC16(BYTE* pDataIn, int start, int len)
{
	UINT16 wResult = 0xFFFF;
	UINT16 wTableNo = 0;
	for (int i = start; i < start + len; i++)
	{
		wTableNo = (UINT16)((wResult & 0xff) ^ (pDataIn[i] & 0xff));
		wResult = (UINT16)(((wResult >> 8) & 0xff) ^ wCRC16Table[wTableNo]);
	}
	return wResult;
}
AFX_API_EXPORT UINT16 WINAPI calculate_CRC16(CByteArray* pDataIn, int start, int len)
{
	UINT16 wResult = 0xFFFF;
	UINT16 wTableNo = 0;
	for (int i = start; i < start + len; i++)
	{
		wTableNo = (UINT16)((wResult & 0xff) ^ ((BYTE)(*pDataIn)[i] & 0xff));
		wResult = (UINT16)(((wResult >> 8) & 0xff) ^ wCRC16Table[wTableNo]);
	}
	return wResult;
}

// CFrameWorkDlg 对话框

IMPLEMENT_DYNAMIC(CFrameWorkDlg, CDialogEx)

CFrameWorkDlg::CFrameWorkDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_FW, pParent)
{

}

CFrameWorkDlg::~CFrameWorkDlg()
{
}

void CFrameWorkDlg::SetIconHandle(HICON hIcon)
{
	m_hIcon = hIcon;
}

void CFrameWorkDlg::SetTitle(CString title)
{
	m_title = title;
}

//int CFrameWorkDlg::writeData(const char * data, int maxSize)
//{
//	return m_SerialPort.writeData(data, maxSize);
//}

void CFrameWorkDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFrameWorkDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(MU_DISCONNECT, &CFrameWorkDlg::OnDisconnect)
	ON_COMMAND(MU_ABOUT, &CFrameWorkDlg::OnAbout)
	ON_COMMAND(MU_REFRESH, &CFrameWorkDlg::OnCOMPortRefresh)
	ON_COMMAND_RANGE(WM_USER + 0x100, WM_USER + 0x100+15, &CFrameWorkDlg::OnConnect)
	ON_COMMAND_RANGE(WM_USER + 0x200, WM_USER + 0x300, &CFrameWorkDlg::OnCommandTransmission)
END_MESSAGE_MAP()


// CFrameWorkDlg 消息处理程序


void CFrameWorkDlg::OnPaint()
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
		__super::OnPaint();
	}
}


HCURSOR CFrameWorkDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


BOOL CFrameWorkDlg::OnInitDialog()
{
	__super::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	SetWindowText(m_title);
	HWND hChild = CreateChildDlg();
	if (hChild != nullptr)
	{
		m_pChild = FromHandle(hChild);
		CRect rs;
		m_pChild->GetClientRect(&rs);
		rs.bottom += 54;
		rs.right += 14;
		this->MoveWindow(&rs);		//根据子窗口刷新 英文大小调节母窗口
		m_pChild->MoveWindow(&rs);
		m_pChild->ShowWindow(TRUE);
		m_SerialPort.readReady.connect(this, &CFrameWorkDlg::OnSerialPortReceive);
		EnableChildDlg(FALSE);
	}
	else
	{
		AfxMessageBox(_T("Create Dialog Error!"), MB_ICONERROR);
		return FALSE;
	}

	OnCOMPortRefresh();


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CFrameWorkDlg::OnConnect(UINT uID)
{
	CString csPortName= m_SerialPortList[uID - WM_USER - 0x100].strPortName;

	if (m_SerialPort.isOpened())
	{
		m_SerialPort.close();
	}
	string sPortName = CW2A(csPortName.GetString());
	m_SerialPort.init(sPortName, 9600, ParityNone, DataBits8, StopOne, FlowNone, 512);
	m_SerialPort.open();
	if (m_SerialPort.isOpened())
	{
		CMenu *pmenu = AfxGetMainWnd()->GetMenu();
		pmenu->ModifyMenu(0, MF_BYPOSITION | MF_DISABLED, 0, _T("已连接(") + csPortName + _T(")"));
		pmenu->ModifyMenu(1, MF_BYPOSITION, MU_DISCONNECT, _T("断开"));
		pmenu->Detach();
		DrawMenuBar();
		EnableChildDlg(TRUE);	
	}
	else
	{
		AfxMessageBox(_T("连接失败!"), MB_ICONERROR);
	}
}


void CFrameWorkDlg::OnDisconnect()
{
	if (m_SerialPort.isOpened() == true)
	{
		m_SerialPort.close();
		CMenu *pmenu = AfxGetMainWnd()->GetMenu();
		pmenu->ModifyMenu(0, MF_BYPOSITION, 0, _T("串口"));
		pmenu->ModifyMenu(1, MF_BYPOSITION | MF_DISABLED, MU_DISCONNECT, _T("断开"));
		pmenu->Detach();
		DrawMenuBar();
		EnableChildDlg(FALSE);
	}
}


void CFrameWorkDlg::OnAbout()
{
	CAboutDlg dlg(this);
	dlg.DoModal();
}


BOOL CFrameWorkDlg::OnCommand(WPARAM wParam, LPARAM lParam)
{
	UINT uMsg = LOWORD(wParam);

	if (uMsg == MU_CONNECT)
	{

	}

	return __super::OnCommand(wParam, lParam);
}


void CFrameWorkDlg::OnCOMPortRefresh()
{
	CMenu *menu;
	CMenu* menuMain = AfxGetMainWnd()->GetMenu();
	menu = menuMain->GetSubMenu(0);
	for (UINT i = 0; i < 20; i++)
	{
		if (menu->RemoveMenu(0, MF_BYPOSITION) == FALSE)
			break;
	}
	//menu->CreateMenu();
	menu->AppendMenu(MF_STRING, MU_REFRESH, _T("刷新"));
	menu->AppendMenu(MF_SEPARATOR);
	//	//获取串口号
	//list<string> m_portsList = CSerialPortInfo::availablePorts();
	//list<string>::iterator itor;
	//UINT i = 0;
	//for (itor = m_portsList.begin(); itor != m_portsList.end() && i < 15; ++itor, i++)
	//{
	//	CString m_portname((*itor).c_str());
	//	menu->AppendMenu(0, WM_USER + 0x100 + i, m_portname);
	//}
	EnumSerialPorts(m_SerialPortList, FALSE/*include all*/);
	for (INT ii = 0; ii < m_SerialPortList.GetSize(); ii++)
	{
		CString show;
		show.Format(_T("%-8s %s"), m_SerialPortList[ii].strPortName, (m_SerialPortList[ii].strPortDesc.GetLength() > 24) ? (m_SerialPortList[ii].strPortDesc.Left(24) + _T("...")) : m_SerialPortList[ii].strPortDesc);
		menu->AppendMenu(0, WM_USER + 0x100 + ii, show);
	}
}

void CFrameWorkDlg::OnCommandTransmission(UINT uID)
{
	m_pChild->SendMessage(WM_COMMAND, uID);
}


