/*
   service.h
  
   THIS SOFTWARE IS NOT COPYRIGHTED

   This source code is offered for use in the public domain.  You may use,
   modify or distribute it freely.

   This code is distributed in the hope that it will be useful but
   WITHOUT ANY WARRANTY.  ALL WARRANTIES, EXPRESS OR IMPLIED ARE HEREBY
   DISCLAIMED.  This includes but is not limited to warranties of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef  __SERVICE_H__
#define  __SERVICE_H__

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32_WCE) && (_WIN32_WCE >= 400)
typedef struct ServiceEnumInfo {
  WCHAR szPrefix[6];
  WCHAR szDllName;
  HANDLE hServiceHandle;
  DWORD dwServiceState;
} ServiceEnumInfo;

/* Values for dwServiceState */
#define SERVICE_STATE_OFF		0
#define SERVICE_STATE_ON		1
#define SERVICE_STATE_STARTING_UP	2
#define SERVICE_STATE_SHUTTING_DOWN	3
#define SERVICE_STATE_UNLOADING		4
#define SERVICE_STATE_UNINITIALIZED	5
#define SERVICE_STATE_UNKNOWN		0xffffffff

HANDLE RegisterService (LPCWSTR lpszType, DWORD dwIndex, LPCWSTR lpszLib,
			DWORD dwInfo);
HANDLE ActivateService (LPCWSTR lpszDevKey, DWORD dwClientInfo);
BOOL DeregisterService (HANDLE hDevice);
BOOL EnumServices (PBYTE pBuffer, DWORD *pdwServiceEntries, DWORD *pdwBufferLen);
HANDLE GetServiceHandle (LPWSTR szPrefix, LPWSTR szDllName, DWORD *pdwDllBuf);
BOOL ServiceAddPort (HANDLE hService, SOCKADDR *pSockAddr, INT cbSockAddr,
		     INT iProtocol, WCHAR *szRegWritePath);
BOOL ServiceClosePort (HANDLE hService, SOCKADDR *pSockAddr, int cbSockAddr, 
		       int iProtocol, BOOL fRemoveFromRegistry);
BOOL ServiceIoControl (HANDLE hService, DWORD dwIoControlCode, LPVOID lpInBuf,
		       DWORD nInBufSize, LPVOID lpOutBuf, DWORD nOutBufSize,
		       LPDWORD lpBytesReturned, LPOVERLAPPED lpOverlapped);
BOOL ServiceUnbindPorts (HANDLE hService);

#endif	/* _WIN32_WCE */

#ifdef __cplusplus
}
#endif

#endif	/* __SERVICE_H__ */
