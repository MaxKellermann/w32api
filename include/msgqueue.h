/*
 * msgqueue.h
 */
#ifndef	_MSGQUEUE_H_
#define	_MSGQUEUE_H_

#if __GNUC__ >= 3
#pragma GCC system_header
#endif

#ifdef  __cplusplus
extern "C" {
#endif

typedef struct MSGQUEUEOPTIONS_OS {
	DWORD dwSize;
	DWORD dwFlags;
	DWORD dwMaxMessages;
	DWORD cbMaxMessage;
	BOOL bReadAccess;
} MSGQUEUEOPTIONS, *LPMSGQUEUEOPTIONS, *PMSGQUEUEOPTIONS;

typedef struct MSGQUEUEINFO {
	DWORD dwSize;
	DWORD dwFlags;
	DWORD dwMaxMessages;
	DWORD cbMaxMessage;
	DWORD dwCurrentMessages;
	DWORD dwMaxQueueMessages;
	WORD wNumReaders;
	WORD wNumWriters;
} MSGQUEUEINFO, *PMSGQUEUEINFO, *LPMSGQUEUEINFO;

HANDLE CreateMsgQueue(LPCWSTR lpszName, LPMSGQUEUEOPTIONS lpOptions);
BOOL CloseMsgQueue(HANDLE hMsgQ);
BOOL ReadMsgQueue(HANDLE hMsgQ, LPVOID lpBuffer,
		DWORD cbBufferSize, LPDWORD lpNumberOfBytesRead,
		DWORD dwTimeout, DWORD *pdwFlags);

#define	MSGQUEUE_NOPRECOMMIT	1	/* ?? */
#define	MSGQUEUE_ALLOW_BROKEN	2	/* ?? */


#ifdef  __cplusplus
}
#endif

#endif  /* _MSGQUEUE_H_ */
