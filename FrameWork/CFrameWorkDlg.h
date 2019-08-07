#pragma once

#include "SerialPortLib/SerialPort.h"
#include "SerialPortLib/SerialPortInfo.h"
#include "EnumSerial.h"

using namespace std;
using namespace itas109;

// CFrameWorkDlg 对话框

class AFX_EXT_CLASS CFrameWorkDlg : public CDialogEx, public has_slots<>
{
	DECLARE_DYNAMIC(CFrameWorkDlg)

public:
	CFrameWorkDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CFrameWorkDlg();
	virtual void OnSerialPortReceive() = 0;
	virtual HWND CreateChildDlg()=0;
	virtual void EnableChildDlg(BOOL Enable = TRUE) = 0;
	void SetIconHandle(HICON hIcon);
	void SetTitle(CString title);

	CArray<SSerInfo, SSerInfo&> m_SerialPortList;

	CSerialPort m_SerialPort;
	HICON m_hIcon;
	CWnd *m_pChild;
	CString m_title;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_FW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	BOOL isConnect=FALSE;

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual BOOL OnInitDialog();
	afx_msg void OnConnect(UINT uID);
	afx_msg void OnDisconnect();
	afx_msg void OnAbout();
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	afx_msg void OnCOMPortRefresh();
	afx_msg void OnCommandTransmission(UINT uID);
	afx_msg void OnLangChn();
	afx_msg void OnLangEn();
};
AFX_API_EXPORT UINT16 WINAPI calculate_CRC16(BYTE* pDataIn, int start, int len);
AFX_API_EXPORT UINT16 WINAPI calculate_CRC16(CByteArray* pDataIn, int start, int len);
