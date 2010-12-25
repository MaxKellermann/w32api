#ifndef	_PHONE_H
#define	_PHONE_H

#if __GNUC__ >= 3
#pragma GCC system_header
#endif

#ifdef	__cplusplus
extern "C" {
#endif

#if _WIN32_WCE >= 0x0500

#include <windows.h>

typedef struct tagPHONEMAKECALLINFO{
	DWORD cbSize;		/* Size of this structure */
	DWORD dwFlags;
	PCWSTR pszDestAddress;	/* Phone number, max length TAPIMAXDESTADDRESSSIZE */
	PCWSTR pszAppName;	/* Res for future use, NULL */
	PCWSTR pszCalledParty;	/* Name of party to be called, max length TAPIMAXCALLEDPARTYSIZE */
	PCWSTR pszComment;	/* Res for future use, NULL */
} PHONEMAKECALLINFO, *PPHONEMAKECALLINFO;

/* Values for dwFlags, see http://msdn.microsoft.com/en-us/library/aa446543.aspx */
#define	PMCF_DEFAULT			1
#define PMCF_PROMPTBEFORECALLING	2

LONG PhoneMakeCall(PHONEMAKECALLINFO *ppmci);
#endif /* _WIN32_WCE >= 0x0400 */

#ifdef	__cplusplus
}
#endif

#endif	/* _PHONE_H */
