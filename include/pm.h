/*
 * pm.h
 */
#ifndef	_PM_H_
#define	_PM_H_

#if __GNUC__ >= 3
#pragma GCC system_header
#endif

#ifdef  __cplusplus
extern "C" {
#endif

#if defined(_WIN32_WCE) && (_WIN32_WCE >= 0x0400)

#define POWER_NAME              (DWORD)(0x00000001)
#define POWER_FORCE             (DWORD)(0x00001000)

typedef enum _CEDEVICE_POWER_STATE {
	PwrDeviceUnspecified = -1,
	D0 = 0,
	D1,
	D2,
	D3,
	D4,
	PwrDeviceMaximum
} CEDEVICE_POWER_STATE, *PCEDEVICE_POWER_STATE;

typedef struct _POWER_CAPABILITIES {
	UCHAR DeviceDx;
	UCHAR WakeFromDx;
	UCHAR InrushDx;
	DWORD Power[5];
	DWORD Latency[5];
	DWORD Flags;
} POWER_CAPABILITIES, *PPOWER_CAPABILITIES;

typedef struct {
	DWORD Message;
	DWORD Flags;
	DWORD Length;
	WCHAR SystemPowerState[1];
} POWER_BROADCAST, *PPOWER_BROADCAST;

typedef struct _POWER_BROADCAST_POWER_INFO {
	DWORD dwBatteryLifeTime;
	DWORD dwBatteryFullLifeTime;
	DWORD dwBackupBatteryLifeTime;
	DWORD dwBackupBatteryFullLifeTime;
	BYTE bACLineStatus;
	BYTE bBatteryFlag;
	BYTE bBatteryLifePercent;
	BYTE bBackupBatteryFlag;
	BYTE bBackupBatteryLifePercent;
} POWER_BROADCAST_POWER_INFO, *PPOWER_BROADCAST_POWER_INFO;

/* Power broadcast values are guessed by experimentation */
#define	PBT_RESUME		2

HANDLE SetPowerRequirement(
	PVOID pvDevice,
	CEDEVICE_POWER_STATE DeviceState,
	ULONG DeviceFlags,
	PVOID pvSystemState,
	ULONG StateFlags);

DWORD ReleasePowerRequirement(HANDLE hPowerReq);

#define POWER_STATE(f)           ((f) &  0xFFFF0000)        // power state mask
#define POWER_STATE_ON           (DWORD)(0x00010000)        // on state
#define POWER_STATE_OFF          (DWORD)(0x00020000)        // no power, full off
#define POWER_STATE_CRITICAL     (DWORD)(0x00040000)        // critical off
#define POWER_STATE_BOOT         (DWORD)(0x00080000)        // boot state
#define POWER_STATE_IDLE         (DWORD)(0x00100000)        // idle state
#define POWER_STATE_SUSPEND      (DWORD)(0x00200000)        // suspend state
#define POWER_STATE_UNATTENDED   (DWORD)(0x00400000)        // Unattended state.
#define POWER_STATE_RESET        (DWORD)(0x00800000)        // reset state
#define POWER_STATE_USERIDLE     (DWORD)(0x01000000)        // user idle state
#define POWER_STATE_PASSWORD     (DWORD)(0x10000000)        // This state is password protected.

HANDLE RequestPowerNotifications(HANDLE hMsgQ, DWORD Flags);
BOOL StopPowerNotifications(HANDLE h);

DWORD DevicePowerNotify(PVOID,CEDEVICE_POWER_STATE,DWORD);
DWORD GetDevicePower(PVOID,DWORD,PCEDEVICE_POWER_STATE);
DWORD GetSystemPowerState(LPWSTR,DWORD,PDWORD);
HANDLE RegisterPowerRelationship(PVOID,PVOID,PPOWER_CAPABILITIES,DWORD);
DWORD ReleasePowerRelationship(HANDLE);
DWORD SetDevicePower(PVOID,DWORD,CEDEVICE_POWER_STATE);
DWORD SetSystemPowerState(LPCWSTR,DWORD,DWORD);


#endif	/* _WIN32_WCE */

#ifdef  __cplusplus
}
#endif

#endif  /* _PM_H_ */

