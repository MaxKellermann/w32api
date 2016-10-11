/*
 * Definition of File and Application Management API.
 * These are the APIs for finding flash cards and project files.
 *
 * You'll need to link -lnote_prj for this.
 */
#ifndef	_PROJECT_H_
#define _PROJECT_H_

#if __GNUC__ >= 3
#pragma GCC system_header
#endif

#ifdef  __cplusplus
extern "C" {
#endif

#if _WIN32_WCE >= 300

#include <windows.h>

#define PA_MAX_PATHNAME 96 

typedef enum EFileIDType {
	FILE_ID_TYPE_OID  = 0,
	FILE_ID_TYPE_PATH = 1,
	FILE_ID_LAST      = 2
} EFileIDType;

typedef struct PAstruct {
	EFileIDType m_IDtype;
	union {
		/* CEOID m_fileOID; */
		TCHAR m_szPathname[PA_MAX_PATHNAME];
	};
} PAstruct;

typedef BOOL (CALLBACK *EnumProjectsCallback)(DWORD dwOid, LPARAM lParam); 
typedef BOOL (CALLBACK *EnumProjectsFilesExCallback)(PAstruct * pPA, LPARAM lParam);
typedef BOOL (CALLBACK *EnumProjectsExCallback)(PAstruct* pPA, LPARAM lParam);

BOOL FindNextFlashCard(HANDLE hFlashCard,
		LPWIN32_FIND_DATA lpFindFlashData);
HANDLE FindFirstFlashCard(LPWIN32_FIND_DATA lpFindFlashData);
int EnumProjects(EnumProjectsCallback lpEnumProc,
		DWORD dwOidFlash,
		DWORD dwFlags,
		LPARAM lParam);
int EnumProjectsEx(EnumProjectsExCallback pfnEnumProc,
		DWORD dwOidFlash,
		DWORD dwFlags,
		LPARAM lParam);
int EnumProjectsFiles(EnumProjectsCallback lpEnumProc,
		DWORD dwOidFlash,
		DWORD dwFlags,
		LPTSTR lpszProj,
		LPTSTR lpszFileName,
		LPARAM lParam);
int EnumProjectsFilesEx (EnumProjectsFilesExCallback pfnEnumProc,
		DWORD dwOidFlash,
		DWORD dwFlags,
		LPTSTR szProj,
		LPTSTR szFileName,
		LPARAM lParam);
HANDLE FindFirstProjectFile(LPCTSTR lpFileName,
		LPWIN32_FIND_DATA lpFindFileData,
		DWORD dwOidFlash,
		LPTSTR lpszProj);
BOOL FindNextProjectFile(HANDLE hHandle, LPWIN32_FIND_DATA lpFindProjData);

#define	PRJ_ENUM_MEMORY		0x1
#define	PRJ_ENUM_FLASH		0x2
#define	PRJ_ENUM_ALL_DEVICES	0x4
#define	PRJ_ENUM_ALL_PROJ	0x10
#define	PRJ_ENUM_HOME_PROJ	0x100

#endif	/* _WIN32_WCE */

#ifdef __cplusplus
}
#endif
#endif	/* _PROJECT_H_ */
