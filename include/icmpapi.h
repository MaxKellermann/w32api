/*
 * icmpapi.h
 */
#ifndef	_ICMPAPI_H_
#define	_ICMPAPI_H_

#ifdef	__cplusplus
extern "C" {
#endif

HANDLE WINAPI IcmpCreateFile(void);
DWORD WINAPI IcmpSendEcho(HANDLE IcmpHandle, 
		IPAddr DestinationAddress,
		LPVOID RequestData, 
		WORD RequestSize, 
		PIP_OPTION_INFORMATION RequestOptions, 
		LPVOID ReplyBuffer,
		DWORD ReplySize, 
		DWORD Timeout); 
BOOL WINAPI IcmpCloseHandle(HANDLE IcmpHandle); 

#ifdef	__cplusplus
}
#endif
#endif	/* _ICMPAPI_H_ */
