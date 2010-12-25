#ifndef _TODAYCMN_H_
#define _TODAYCMN_H_

#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif


/* wParam to TODAYM_GETCOLOR */
#define TODAYCOLOR_TEXT		    0x10000004
#define TODAYCOLOR_HIGHLIGHT	    0x10000022
#define TODAYCOLOR_HIGHLIGHTEDTEXT  0x10000023

/* lParam (by reference) to TODAYM_DRAWWATERMARK */
typedef struct {
  HDC   hdc;
  RECT  rc;
  HWND  hwnd;
} TODAYDRAWWATERMARKINFO;

#define TODAYM_GETCOLOR				(WM_USER+100)
#define TODAYM_DRAWWATERMARK			(WM_USER+101)
#define TODAYM_TOOKSELECTION			(WM_USER+102)

#define WM_TODAYCUSTOM_CLEARCACHE		(WM_USER+242)
#define WM_TODAYCUSTOM_QUERYREFRESHCACHE	(WM_USER+243)
#define WM_TODAYCUSTOM_RECEIVEDSELECTION	(WM_USER+244)
#define WM_TODAYCUSTOM_LOSTSELECTION		(WM_USER+245)
#define WM_TODAYCUSTOM_USERNAVIGATION		(WM_USER+246)
#define WM_TODAYCUSTOM_ACTION			(WM_USER+247)

/* Types of items on the Today screen */
typedef enum _TODAYLISTITEMTYPE{
  tlitOwnerInfo = 0,
  tlitAppointments,
  tlitMail,
  tlitTasks,
  tlitCustom,
  tlitNil
} TODAYLISTITEMTYPE;

/* Properties of a Today screen item */

#define MAX_ITEMNAME	32

typedef struct _TODAYLISTITEM {
  TCHAR             szName[MAX_ITEMNAME];
  TODAYLISTITEMTYPE tlit;
  DWORD             dwOrder;
  DWORD             cyp;
  BOOL              fEnabled;
  BOOL              fOptions;
  DWORD             grfFlags;
  TCHAR             szDLLPath[MAX_PATH];
  HINSTANCE         hinstDLL;
  HWND              hwndCustom;
  BOOL              fSizeOnDraw;
  BYTE *            prgbCachedData;
  DWORD             cbCachedData;
} TODAYLISTITEM;


#ifdef __cplusplus
}
#endif

#endif  /* !_TODAYCMN_H_ */
