#ifndef _SIPAPI_H
#define _SIPAPI_H
#if __GNUC__ >= 3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if _WIN32_WCE >= 0x0201

/*
 * Query the SIP state
 */
typedef struct SIPINFO {
	DWORD	cbSize;
	DWORD	fdwFlags;
	RECT	rcVisibleDesktop;
	RECT	rcSipRect;
	DWORD	dwImDataSize;
	VOID*	pvImData;
} SIPINFO, *PSIPINFO;

#define	SPI_SETCOMPLETIONINFO	223
#define	SPI_SETSIPINFO		224
#define	SPI_GETSIPINFO		225
#define	SPI_SETCURRENTIM	226
#define	SPI_GETCURRENTIM	227
#define	SPI_APPBUTTONCHANGE	228
#define	SPI_RESERVED		229
#define	SPI_SYNCSETTINGSCHANGE	230

#define SIPF_OFF 0
#define SIPF_ON 1
#define SIPF_DOCKED 2
#define SIPF_LOCKED 4

BOOL WINAPI SipGetInfo(SIPINFO*);
BOOL WINAPI SipSetInfo(SIPINFO*);

typedef struct tagIMENUMINFO
{
	WCHAR	szName[MAX_PATH];
	CLSID	clsid;
} IMENUMINFO, *PIMENUMINFO;

typedef int (*IMENUMPROC)(IMENUMINFO *);

int WINAPI SipEnumIM(IMENUMPROC);

BOOL WINAPI SipShowIM(DWORD);
BOOL WINAPI SipGetCurrentIM(CLSID *);
BOOL WINAPI SipSetCurrentIM(CLSID *);

#endif	/* _WIN32_WCE >= 0x0201 */

#ifdef __cplusplus
}
#endif

#endif /* _SIPAPI_H */
