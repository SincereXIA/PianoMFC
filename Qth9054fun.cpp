#include "stdafx.h"
#include "QTH9054fun.h"

HANDLE hDevice;
HANDLE hEvent;
DWORD	nRet;


LARGE_INTEGER config[8];
ULONG	         Length[8];
ULONG	         IRQ;

struct pci_cfg *pci;
struct Buffers *prd;
struct Start_adr *pstr;

UINT InterruptAttachThreadLocalInt(LPVOID pParam);
HWND hInterrputWnd;
int ThreadStatus;
CWinThread	*m_pWaitThread;

char *sLinkName="\\\\.\\QTH9054Device0";

BOOL Init9054()
{
	hDevice = CreateFile(
					sLinkName,
					GENERIC_READ | GENERIC_WRITE,
					FILE_SHARE_READ | FILE_SHARE_WRITE,
					NULL,
					OPEN_EXISTING,
					FILE_ATTRIBUTE_NORMAL,
					NULL
		);

	if (hDevice == INVALID_HANDLE_VALUE)
	{
		AfxMessageBox("请检查板卡和驱动程序",MB_ICONSTOP,MB_OK);
		return false;
	}

	hEvent=CreateEvent(NULL, FALSE, FALSE, NULL);
    prd=(Buffers*)malloc(sizeof(Buffers));
	pstr=(Start_adr*)malloc(sizeof(Start_adr));
	return true;
}

void RAM32bWrite(ULONG adr,ULONG dat)
{
	BOOL status;
	DWORD rc;

	prd->Address=adr;
	prd->Data =dat;
	status=DeviceIoControl(hDevice,IOCTL_MEM_WRITE,prd,sizeof(Buffers),NULL,0,&rc,NULL);
	if (!status)
		AfxMessageBox("无法写入!",MB_ICONSTOP,MB_OK);
}

ULONG RAM32bRead(ULONG adr)
{
	DWORD rc;

	prd->Address =adr;
	prd->Data=0;

	BOOL status=DeviceIoControl(hDevice,IOCTL_MEM_READ,prd,sizeof(Buffers),prd,sizeof(Buffers),&rc,NULL);
    if (hDevice==INVALID_HANDLE_VALUE)
	{
		AfxMessageBox("无法ON_SHOW!",MB_ICONSTOP,MB_OK);
	}
	return prd->Data ;
}

void IO32bWrite(ULONG adr,ULONG dat)
{
	BOOL status;
	DWORD rc;

	prd->Address=adr;
	prd->Data =dat;
	status=DeviceIoControl(hDevice,IOCTL_IO_WRITE,prd,sizeof(Buffers),NULL,0,&rc,NULL);
	if (!status)
		AfxMessageBox("无法写入!",MB_ICONSTOP,MB_OK);
}

ULONG IO32bRead(ULONG adr)
{
	DWORD rc;

	prd->Address =adr;

	BOOL status=DeviceIoControl(hDevice,IOCTL_IO_READ,prd,sizeof(Buffers),prd,sizeof(Buffers),&rc,NULL);
    if (hDevice==INVALID_HANDLE_VALUE)
	{
		AfxMessageBox("无法ON_SHOW!",MB_ICONSTOP,MB_OK);
	}
	return prd->Data;
}

void IO16bWrite(ULONG adr,USHORT dat)
{
	BOOL status;
	DWORD rc;

	prd->Address=adr;
	prd->Data =dat;
	status=DeviceIoControl(hDevice,IOCTL_IO16b_WRITE,prd,sizeof(Buffers),NULL,0,&rc,NULL);
	if (!status)
		AfxMessageBox("无法写入!",MB_ICONSTOP,MB_OK);
}

USHORT IO16bRead(ULONG adr)
{
	DWORD rc;

	prd->Address =adr;

	BOOL status=DeviceIoControl(hDevice,IOCTL_IO16b_READ,prd,sizeof(Buffers),prd,sizeof(Buffers),&rc,NULL);
    if (hDevice==INVALID_HANDLE_VALUE)
	{
		AfxMessageBox("无法ON_SHOW!",MB_ICONSTOP,MB_OK);
	}
	return (SHORT)prd->Data;
}

void IO8bWrite(ULONG adr,ULONG dat)
{
	BOOL status;
	DWORD rc;

	prd->Address=adr;
	prd->Data =dat;
	status=DeviceIoControl(hDevice,IOCTL_IO8b_WRITE,prd,sizeof(Buffers),NULL,0,&rc,NULL);
	if (!status)
		AfxMessageBox("无法写入!",MB_ICONSTOP,MB_OK);
}

UCHAR IO8bRead(ULONG adr)
{
	DWORD rc;

	prd->Address =adr;

	BOOL status=DeviceIoControl(hDevice,IOCTL_IO8b_READ,prd,sizeof(Buffers),prd,sizeof(Buffers),&rc,NULL);
    if (hDevice==INVALID_HANDLE_VALUE)
	{
		AfxMessageBox("无法ON_SHOW!",MB_ICONSTOP,MB_OK);
	}
	return (BYTE)prd->Data;
}


void RAM16bWrite(ULONG adr,ULONG dat)
{
	BOOL status;
	DWORD rc;

	prd->Address=adr;
	prd->Data =dat;
	status=DeviceIoControl(hDevice,IOCTL_MEM16b_WRITE,prd,sizeof(Buffers),NULL,0,&rc,NULL);
	if (!status)
		AfxMessageBox("无法写入!",MB_ICONSTOP,MB_OK);
}

USHORT RAM16bRead(ULONG adr)
{
	DWORD rc;

	prd->Address =adr;

	BOOL status=DeviceIoControl(hDevice,IOCTL_MEM16b_READ,prd,sizeof(Buffers),prd,sizeof(Buffers),&rc,NULL);
    if (hDevice==INVALID_HANDLE_VALUE)
	{
		AfxMessageBox("无法ON_SHOW!",MB_ICONSTOP,MB_OK);
	}
	return (SHORT)prd->Data ;
}

void RAM8bWrite(ULONG adr,ULONG dat)
{
	BOOL status;
	DWORD rc;

	prd->Address=adr;
	prd->Data =dat;
	status=DeviceIoControl(hDevice,IOCTL_MEM8b_WRITE,prd,sizeof(Buffers),NULL,0,&rc,NULL);
	if (!status)
		AfxMessageBox("无法写入!",MB_ICONSTOP,MB_OK);
}

UCHAR RAM8bRead(ULONG adr)
{
	DWORD rc;

	prd->Address =adr;

	BOOL status=DeviceIoControl(hDevice,IOCTL_MEM8b_READ,prd,sizeof(Buffers),prd,sizeof(Buffers),&rc,NULL);
    if (hDevice==INVALID_HANDLE_VALUE)
	{
		AfxMessageBox("无法ON_SHOW!",MB_ICONSTOP,MB_OK);
	}
	return (UCHAR)prd->Data ;
}

BOOL  OpenInt(void)
{
	BOOL status =  DeviceIoControl(hDevice, IOCTL_INT_OPEN, &hEvent, sizeof(hEvent),NULL,0, &nRet, NULL);
	if (!status)
	{
		AfxMessageBox("INT_OPEN失败!",MB_ICONSTOP,MB_OK);
		//CDialog::OnCancel();
	}
	return TRUE;
}

BOOL  CloseInt(void)
{
	BOOL status =  DeviceIoControl(hDevice, IOCTL_INT_CLOSE, &hEvent, sizeof(hEvent),NULL,0, &nRet, NULL);
	if (!status)
	{
		AfxMessageBox("INT_CLOSE失败!",MB_ICONSTOP,MB_OK);
	}
	return TRUE;
}

int StartIrqThread(HWND hWnd)
{   //HANDLE       ThreadHandle;
   // DWORD        pThreadId;
    hInterrputWnd=hWnd;

	if (ThreadStatus==0)
		m_pWaitThread = AfxBeginThread(InterruptAttachThreadLocalInt,hWnd);
	if (ThreadStatus==2)
		m_pWaitThread->ResumeThread();
    if (m_pWaitThread == NULL)
    {
       AfxMessageBox("创建线程失败",MB_ICONSTOP,MB_OK);
       return(FALSE);
    }
	ThreadStatus =1;
    // Delay to let thread start
    Sleep(500);
 	return(TRUE);
}

int StopIrqThread()
{
	ThreadStatus =0;
	m_pWaitThread->SuspendThread();
	Sleep(100);
	return (TRUE);
}

UINT InterruptAttachThreadLocalInt(LPVOID pParam)
{
    DWORD        EventStatus;
    //static HANDLE hEvent;
	//hEvent=CreateEvent(NULL, FALSE, FALSE, NULL);
	while(ThreadStatus)
	{
		// Wait for interrupt event
        //EventStatus = WaitForMultipleObjects(1,&hInterruptEvent,FALSE,INFINITE);
	    EventStatus = WaitForSingleObject(hEvent,INFINITE);
	    if (EventStatus== WAIT_OBJECT_0)	
		{	
			::PostMessage((HWND)pParam,WM_PCI9054_INTERRUPT,0,0);
			ResetEvent(hEvent);
		}
 	}   
	return 0;
}

void DMAWrite32(ULONG adr,ULONG len,ULONG dat)
{
	DWORD rc;

	ULONG	nWritten;
	
	pstr->address=adr;
	pstr->mode =1;
	BOOL status=DeviceIoControl(hDevice,IOCTL_STR_ADR,pstr,sizeof(Start_adr),NULL,0,&rc,NULL);

	unsigned int *buf;
	buf = (unsigned int *) malloc(sizeof(unsigned int)*len);
	if (buf == NULL)
	{
		AfxMessageBox("Failed to allocate buffer for write",MB_ICONSTOP,MB_OK);
	}
	for (int i=0; i<len; i++)
	{
		buf[i] =dat;
	}
	WriteFile(hDevice, buf, sizeof(unsigned long)*len, &nWritten, NULL);
}


void DMAWrite(ULONG adr,ULONG len,UINT * dat)
{
	DWORD rc;

	ULONG	nWritten;
	
	pstr->address=adr;
	pstr->mode =1;
	BOOL status=DeviceIoControl(hDevice,IOCTL_STR_ADR,pstr,sizeof(Start_adr),NULL,0,&rc,NULL);

	// Write data to driver
	WriteFile(hDevice, dat, sizeof(unsigned int)*len, &nWritten, NULL);

}

void DMARead(ULONG adr,ULONG len,UINT *buf)
{
	DWORD rc;
	ULONG	nRead;

	pstr->address=adr;
	pstr->mode =0;
	BOOL status=DeviceIoControl(hDevice,IOCTL_STR_ADR,pstr,sizeof(Start_adr),NULL,0,&rc,NULL);
	// Read data from driver
	ReadFile(hDevice, buf, sizeof(unsigned int)*len, &nRead, NULL);
}

void  MRAM8bWrite(int Seg,int dat)
{
	BOOL status;
	DWORD rc;
	int j;
	
	prd->Data =dat;
	for (j=0;j<=0x3ff;j++)
	{
		prd->Address =Seg+j;
		status=DeviceIoControl(hDevice,IOCTL_MEM8b_WRITE,prd,sizeof(Buffers),NULL,0,&rc,NULL);
	}
}

CString MRam8bRead(int Seg)
{
	BOOL status;
	CString str;
	CString msg;
	unsigned int i;
	DWORD rc;
	prd->Address =0;
	
	for (i=1;i<=0x00000400;i++)
	{
		prd->Address =Seg+i-1;
		status=DeviceIoControl(hDevice,IOCTL_MEM8b_READ,prd,sizeof(Buffers),prd,sizeof(Buffers),&rc,NULL);
		str.Format("%02x",prd->Data);
		str.MakeUpper();
		msg=msg+str+" ";
		if (i%16==0)
			msg+="\r\n";
	}
	return msg;
}

CString MRam8bDRead(int Seg)
{
	BOOL status;
	DWORD rc;
	unsigned int i,j;
	CString str;
	CString msg;
	for (j=0;j<=0x3ff;j++)
	{
		prd->Address =Seg+j;
		prd->Data = j;
		status=DeviceIoControl(hDevice,IOCTL_MEM8b_WRITE,prd,sizeof(Buffers),NULL,0,&rc,NULL);
	}

	for (i=1;i<=0x00000400;i++)
	{
		prd->Address =Seg+i-1;
		status=DeviceIoControl(hDevice,IOCTL_MEM8b_READ,prd,sizeof(Buffers),prd,sizeof(Buffers),&rc,NULL);
		str.Format("%02x",prd->Data);
		str.MakeUpper();
		msg=msg+str+" ";
		if (i%16==0)
			msg+="\r\n";
	}
	return msg;
}

void  MRAM32bWrite(int Seg,int dat)
{
	BOOL status;
	DWORD rc;
	int j;
	
	prd->Data =dat;
	for (j=0;j<=0x3ff;j++)
	{
		prd->Address =(Seg+j)<<2;
		status=DeviceIoControl(hDevice,IOCTL_MEM_WRITE,prd,sizeof(Buffers),NULL,0,&rc,NULL);
	}
}

CString MRam32bRead(int Seg)
{
	BOOL status;
	CString str;
	CString msg;
	unsigned int i;
	DWORD rc;
	prd->Address =0;
	
	for (i=1;i<=0x00000400;i++)
	{
		prd->Address =(Seg+i-1)<<2;
		status=DeviceIoControl(hDevice,IOCTL_MEM_READ,prd,sizeof(Buffers),prd,sizeof(Buffers),&rc,NULL);
		str.Format("%08x",prd->Data);
		str.MakeUpper();
		msg=msg+str+" ";
		if (i%4==0)
			msg+="\r\n";
	}
	return msg;
}

CString MRam32bDRead(int Seg)
{
	BOOL status;
	DWORD rc;
	unsigned int i,j;
	CString str;
	CString msg;
	for (j=0;j<=0x3ff;j++)
	{
		prd->Address =(Seg+j)<<2;
		prd->Data = j;
		status=DeviceIoControl(hDevice,IOCTL_MEM_WRITE,prd,sizeof(Buffers),NULL,0,&rc,NULL);
	}

	for (i=1;i<=0x00000400;i++)
	{
		prd->Address =(Seg+i-1)<<2;
		status=DeviceIoControl(hDevice,IOCTL_MEM_READ,prd,sizeof(Buffers),prd,sizeof(Buffers),&rc,NULL);
		str.Format("%08x",prd->Data);
		str.MakeUpper();
		msg=msg+str+" ";
		if (i%4==0)
			msg+="\r\n";
	}
	return msg;
}

void Cleanup()
{
	CloseHandle(hDevice);
}