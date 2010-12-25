#ifndef _DEVLOAD_H
#define _DEVLOAD_H
#if __GNUC__ >= 3
#pragma GCC system_header
#endif

/* NOTE: This strictly does not belong in the Win32 API.  */

#include <windows.h>

#define DEVFLAGS_NONE              0x00000000
#define DEVFLAGS_UNLOAD            0x00000001
#define DEVFLAGS_LOADLIBRARY       0x00000002
#define DEVFLAGS_NOLOAD            0x00000004
#define DEVFLAGS_NAKEDENTRIES      0x00000008
#define DEVFLAGS_BOOTPHASE_1       0x00001000
#define DEVFLAGS_IRQ_EXCLUSIVE     0x00000100
#define DEVFLAGS_TRUSTEDCALLERONLY 0x00010000

#define DEVLOAD_CLIENTINFO_VALNAME L"ClientInfo"
#define DEVLOAD_HANDLE_VALNAME L"Hnd"
#define DEVLOAD_DEVNAME_VALNAME L"Name"
#define DEVLOAD_DEVKEY_VALNAME L"Key"

#endif
