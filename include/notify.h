/*
 * The notify component supports the Windows CE event notification system.
 */
#ifndef _NOTIFY_H_
#define _NOTIFY_H_

#if __GNUC__ >= 3
#pragma GCC system_header
#endif

#ifdef  __cplusplus
extern "C" {
#endif

#ifdef	_WIN32_WCE	/* Valid from Windows CE 1.01 and later */

typedef struct UserNotificationType {
	DWORD		ActionFlags;
	wchar_t		*pwszDialogTitle;
	wchar_t		*pwszDialogText;
	wchar_t		*pwszSound;
	DWORD		nMaxSound;
	DWORD		dwReserved;
} CE_USER_NOTIFICATION, *PCE_USER_NOTIFICATION;

typedef struct UserNotificationTrigger {
	DWORD		dwSize;
	DWORD		dwType;
	DWORD		dwEvent;
	WCHAR		*lpszApplication;
	WCHAR		*lpszArguments;
	SYSTEMTIME	stStartTime;
	SYSTEMTIME	stEndTime;
} CE_NOTIFICATION_TRIGGER, *PCE_NOTIFICATION_TRIGGER;

/* Flags for ActionFlags. Values from forums.microsoft.com. */
#define	PUN_LED		1	/* ? */
#define	PUN_VIBRATE	2	/* ? */
#define	PUN_DIALOG	4	/* ? */
#define	PUN_SOUND	8	/* ? */
#define	PUN_REPEAT	16	/* ? */
#define	PUN_PRIVATE	32	/* ? */

/* Values for lWhichEvent in CeRunAppAtEvent */
#define	NOTIFICATION_EVENT_NONE			0	/* ? */
#define	NOTIFICATION_EVENT_TIME_CHANGE		1	/* ? */
#define	NOTIFICATION_EVENT_SYNC_END		2	/* ? */
#define	NOTIFICATION_EVENT_ON_AC_POWER		3	/* ? */
#define	NOTIFICATION_EVENT_OFF_AC_POWER		4	/* ? */
#define	NOTIFICATION_EVENT_NET_CONNECT		5	/* ? */
#define	NOTIFICATION_EVENT_NET_DISCONNECT	6	/* ? */
#define	NOTIFICATION_EVENT_DEVICE_CHANGE	7	/* ? */
#define	NOTIFICATION_EVENT_IR_DISCOVERED	8	/* ? */
#define	NOTIFICATION_EVENT_RS232_DETECTED	9	/* ? */
#define	NOTIFICATION_EVENT_RESTORE_END		10	/* ? */
#define	NOTIFICATION_EVENT_WAKEUP		11	/* ? */
#define	NOTIFICATION_EVENT_TZ_CHANGE		12	/* ? */
#define	NOTIFICATION_EVENT_MACHINE_NAME_CHANGE	13	/* ? */

/* Command line values */
#define APP_RUN_AFTER_EXTENDED_EVENT	L"AppRunAfterExtendedEvent"
#define APP_RUN_AFTER_SYNC		L"AppRunAfterSync"
#define APP_RUN_AFTER_TZ_CHANGE		L"AppRunAfterTzChange"
#define APP_RUN_AFTER_WAKEUP		L"AppRunAfterWakeup"
#define APP_RUN_AT_AC_POWER_ON		L"AppRunAtAcPowerOn"
#define APP_RUN_AT_AC_POWER_OFF		L"AppRunAtAcPowerOff"
#define APP_RUN_AT_NET_CONNECT		L"AppRunAtNetConnect"
#define APP_RUN_AT_NET_DISCONNECT	L"AppRunAtNetDisconnect"
#define APP_RUN_AT_DEVICE_CHANGE	L"AppRunDeviceChange"
#define APP_RUN_AT_IR_DISCOVERY		L"AppRunAtIrDiscovery"
#define APP_RUN_AT_RS232_DETECT		L"AppRunAtRs232Detect"
#define APP_RUN_AFTER_RESTORE		L"AppRunAfterRestore"

BOOL CeClearUserNotification (HANDLE hNotification); 
BOOL CeGetUserNotification (HANDLE hNotification,
		DWORD cBufferSize,
		LPDWORD pcBytesNeeded,
		LPBYTE pBuffer);
BOOL CeGetUserNotificationHandles (HANDLE* rghNotifications,
		DWORD cHandles,
		LPDWORD pcHandlesNeeded);
BOOL CeGetUserNotificationPreferences (HWND hWndParent,
		PCE_USER_NOTIFICATION lpNotification); 
BOOL CeHandleAppNotifications (wchar_t *pwszAppName); 
BOOL CeRunAppAtEvent (wchar_t *pwszAppName, LONG lWhichEvent); 
BOOL CeRunAppAtTime (wchar_t *pwszAppName, SYSTEMTIME* lpTime); 
HANDLE CeSetUserNotification (HANDLE hNotification,
		wchar_t *pwszAppName,
		SYSTEMTIME* lpTime,
		PCE_USER_NOTIFICATION lpUserNotification); 
HANDLE CeSetUserNotificationEx (HANDLE hNotification,
		CE_NOTIFICATION_TRIGGER *pcnt,
		CE_USER_NOTIFICATION* pceun);

#endif	/* _WIN32_WCE */

#ifdef  __cplusplus
}
#endif

#endif	/* _NOTIFY_H_ */
