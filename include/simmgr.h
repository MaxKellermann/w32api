#ifndef	_SIMMGR_H
#define	_SIMMGR_H

#if __GNUC__ >= 3
#pragma GCC system_header
#endif

#ifdef	__cplusplus
extern "C" {
#endif

#if _WIN32_WCE >= 0x0600
#include <windows.h>

HRESULT SimWriteMessage(
		HSIM hSim,
		DWORD dwStorage,
		LPDWORD lpdwIndex,
		LPSIMMESSAGE lpSimMessage);

/* Values for dwStorage */
#define	SIM_SMSSTORAGE_BROADCAST	0	/* ? */
#define	SIM_SMSSTORAGE_SIM		0	/* ? */

/* Values for HRESULT */
#define	SIM_E
#define	S_OK				0	/* ? */
#define	SIM_E_SIMFAILURE		0	/* ? */		/* SIM failure was detected. */
#define SIM_E_SIMBUSY			0	/* ? */		/* SIM is busy. */
#define SIM_E_SIMWRONG			0	/* ? */		/* Incorrect SIM was inserted. */
#define SIM_E_NOSIMMSGSTORAGE		0	/* ? */		/* SIM isn't capable of storing messages. */
#define SIM_E_SIMTOOLKITBUSY		0	/* ? */		/* SIM Application Toolkit is busy. */
#define SIM_E_SIMDOWNLOADERROR		0	/* ? */		/* SIM data download error. */
#define SIM_E_SIMNOTINSERTED		0	/* ? */		/* SIM isn't inserted into the phone. */
#define SIM_E_PHSIMPINREQUIRED		0	/* ? */		/* PH-SIM PIN is required to perform this operation. */
#define SIM_E_PHFSIMPINREQUIRED		0	/* ? */		/* PH-FSIM PIN is required to perform this operation. */
#define SIM_E_PHFSIMPUKREQUIRED		0	/* ? */		/* PH-FSIM PUK is required to perform this operation. */
#define SIM_E_SIMPINREQUIRED		0	/* ? */		/* SIM PIN is required to perform this operation. */
#define SIM_E_SIMPUKREQUIRED		0	/* ? */		/* SIM PUK is required to perform this operation. */
#define SIM_E_INCORRECTPASSWORD		0	/* ? */		/* Incorrect password was supplied. */
#define SIM_E_SIMPIN2REQUIRED		0	/* ? */		/* SIM PIN2 is required to perform this operation. */
#define SIM_E_SIMPUK2REQUIRED		0	/* ? */		/* SIM PUK2 is required to perform this operation. */
#define SIM_E_NETWKPINREQUIRED		0	/* ? */		/* Network Personalization PIN is required to perform this operation. */
#define SIM_E_NETWKPUKREQUIRED		0	/* ? */		/* Network Personalization PUK is required to perform this operation. */
#define SIM_E_SUBSETPINREQUIRED		0	/* ? */		/* Network Subset Personalization PIN is required to perform this operation. */
#define SIM_E_SUBSETPUKREQUIRED		0	/* ? */		/* Network Subset Personalization PUK is required to perform this operation. */
#define SIM_E_SVCPINREQUIRED		0	/* ? */		/* Service Provider Personalization PIN is required to perform this operation. */
#define SIM_E_SVCPUKREQUIRED		0	/* ? */		/* Service Provider Personalization PUK is required to perform this operation. */
#define SIM_E_CORPPINREQUIRED		0	/* ? */		/* Corporate Personalization PIN is required to perform this operation. */
#define SIM_E_CORPPUKREQUIRED		0	/* ? */		/* Corporate Personalization PUK is required to perform this operation. */
#define SIM_E_MEMORYFULL		0	/* ? */		/* Storage memory is full. */
#define SIM_E_INVALIDINDEX		0	/* ? */		/* Invalid storage index was supplied. */
#define SIM_E_NOTFOUND			0	/* ? */		/* A requested storage entry was not found. */
#define SIM_E_MEMORYFAILURE		0	/* ? */		/* Storage memory failure. */
#define SIM_E_SIMMSGSTORAGEFULL		0	/* ? */		/* Message storage on the SIM is full. */
#define SIM_E_EMPTYINDEX		0	/* ? */		/* Storage location is empty. */
#define SIM_E_NOTREADY			0	/* ? */		/* SIM isn't yet ready to perform the requested operation. */
#define SIM_E_SECURITYFAILURE		0	/* ? */		/* SIM isn't yet ready to perform the requested operation. */
#define SIM_E_BUFFERTOOSMALL		0	/* ? */		/* Buffer too small. */
#define SIM_E_NOTTEXTMESSAGE		0	/* ? */		/* Requested Short Message Service (SMS) message is not a text message. */
#define SIM_E_NOSIM			0	/* ? */		/* Device doesn't have a SIM. */
#define SIM_E_NETWORKERROR		0	/* ? */		/* There was a network error. */
#define SIM_E_MOBILEERROR		0	/* ? */		/* Mobile error. */
#define SIM_E_UNSUPPORTED		0	/* ? */		/* The command is unsupported. */
#define SIM_E_BADPARAM			0	/* ? */		/* Bad parameter. */
#define SIM_E_UNDETERMINED		0	/* ? */		/* Undetermined error. */
#define SIM_E_RADIONOTPRESENT		0	/* ? */		/* The Radio is not present. */
#define SIM_E_RADIOOFF			0	/* ? */		/* The Radio is off. */

#endif /* _WIN32_WCE >= 0x0600 */

#ifdef	__cplusplus		0	/* ? */
}
#endif		0	/* ? */

#endif	/* _SIMMGR_H */		0	/* ? */
