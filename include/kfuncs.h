/*
 * The implementation is from the WCE library
 * The description that this is supposed to be "kfuncs.h" is from pages
 * such as :
 *
 * http://msdn.microsoft.com/library/default.asp?url=/library/en-us/wcekernl/html/_wcesdk_win32_exitthread.asp
 * http://msdn.microsoft.com/library/default.asp?url=/library/en-us/wcesdkr/html/_wcesdk_win32_pulseevent.asp
 */
#ifndef	_W32API_KFUNCS_H_
#define	_W32API_KFUNCS_H_

#ifndef _WIN32_WCE
#error "_WIN32_WCE is not defined."
#endif

/*
 * http://hubpages.com/hub/hackingwindowsce :
 *	"The value of PUserKData is fixed as 0xFFFFC800 on the ARM processor,
 *	and 0x00005800 on other CPUs."
 * http://www.ddj.com/architect/184405459
 * http://andy-embed.blogspot.com/
 * http://arsouyes.org/phrack/phrack63/phrack63_0x06.html
 */
#if defined(__arm__)
#define	PUserKData		((LPBYTE)0xFFFFC800)
#else
#define	PUserKData		((LPBYTE)0x00005800)
#endif

#define	SYSHANDLE_OFFSET	0x004
#define	SYS_HANDLE_BASE		64
#define SH_WIN32                0
#define SH_CURTHREAD            1
#define SH_CURPROC              2

/* Process/Thread ID Methods */
static inline HANDLE GetCurrentProcess()
{
  return ((HANDLE)(SH_CURPROC+SYS_HANDLE_BASE));

}

static inline HANDLE GetCurrentThread()
{
  return ((HANDLE)(SH_CURTHREAD+SYS_HANDLE_BASE));
}

static inline DWORD GetCurrentThreadId()
{
  return ((DWORD)(((HANDLE *)(PUserKData+SYSHANDLE_OFFSET))[SH_CURTHREAD]));
}

static inline DWORD GetCurrentProcessId()
{
  return ((DWORD)(((HANDLE *)(PUserKData+SYSHANDLE_OFFSET))[SH_CURPROC]));
}

/* EventModify signature hinted on:
   http://msdn.microsoft.com/library/default.asp?url=/library/en-us/wcehardware5/html/wce50lrfCeLogImportTable.asp

   Event Constants and EventModify signature in the c# example at:
   http://msdn.microsoft.com/library/default.asp?url=/library/en-us/dnnetcomp/html/PISAPICF.asp  */
WINBASEAPI BOOL WINAPI EventModify(HANDLE h, DWORD e);

#define	EVENT_PULSE	1
#define	EVENT_RESET	2
#define	EVENT_SET	3

static inline BOOL PulseEvent (HANDLE x)
{
  return EventModify(x, EVENT_PULSE);
}

static inline BOOL ResetEvent (HANDLE x)
{
  return EventModify(x, EVENT_RESET);
}

static inline BOOL SetEvent (HANDLE x)
{
  return EventModify(x, EVENT_SET);
}

/* TLS Constants and Constructs */
#define TLS_FUNCALLOC   0
#define TLS_FUNCFREE    1

WINBASEAPI DWORD WINAPI TlsCall(DWORD func, DWORD val);

static inline DWORD TlsAlloc (void)
{
  return (TlsCall(TLS_FUNCALLOC, 0));
}

static inline BOOL WINAPI TlsFree(DWORD x)
{
  return (TlsCall(TLS_FUNCFREE, x));
}

/*
 * Take the special cases out of winbase.h
 */
#if defined (__arm__)
# define DebugBreak() __asm__( ".word 0xe6000010" )
#elif defined (__i386__) || defined (__x86_64__)
# define DebugBreak() __asm__( ".byte 0xcc" )
#else
  /* externally supplied for an unsupported architecture */
  extern void DebugBreak(void);
#endif
#endif
