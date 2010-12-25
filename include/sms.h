#ifndef	_SMS_H
#define	_SMS_H

#if __GNUC__ >= 3
#pragma GCC system_header
#endif

#ifdef	__cplusplus
extern "C" {
#endif

#if _WIN32_WCE >= 0x0600
#include <windows.h>

#define SMS_MAX_ADDRESS_LENGTH	256	/* ?? */

typedef enum SMS_ADDRESS_TYPE {
	SMSAT_UNKNOWN=0,
	SMSAT_INTERNATIONAL,
	SMSAT_NATIONAL,
	SMSAT_NETWORKSPECIFIC,
	SMSAT_SUBSCRIBER,
	SMSAT_ALPHANUMERIC,
	SMSAT_ABBREVIATED
} SMS_ADDRESS_TYPE;

typedef struct sms_address_tag {
	SMS_ADDRESS_TYPE smsatAddressType;
	TCHAR ptsAddress[SMS_MAX_ADDRESS_LENGTH];
} SMS_ADDRESS, *LPSMS_ADDRESS;

HRESULT SmsGetPhoneNumber(const SMS_ADDRESS *psmsaAddress);

/* Error values, see http://msdn.microsoft.com/en-us/library/aa923113.aspx */
#define	SMS_E_TOOMUCHDATA			0x0100
#define	SMS_E_INVALIDDATA			0x0101
#define	SMS_E_BUFFERTOOSMALL			0x0102
#define	SMS_E_PROVIDERSPECIFICBUFFERWRONGSIZE	0x0103
#define	SMS_E_TIMEUNAVAILABLE			0x0104
#define	SMS_E_RECEIVEHANDLEALREADYOPEN		0x0105
#define	SMS_E_DESTINATIONOUTOFSVC		0x0106
#define	SMS_E_INVALIDADDRESS			0x0107
#define	SMS_E_MSGBARREDBYOPERATOR		0x0108
#define	SMS_E_MSGCALLBARRED			0x0109
#define	SMS_E_NOSCSUBSCRIPTION			0x010a
#define	SMS_E_SCBUSY				0x010b
#define	SMS_E_SVCNOTSUBSCRIBED			0x010c
#define	SMS_E_UNASSIGNEDNUMBER			0x010d
#define	SMS_E_UNKNOWNSCADDRESS			0x010e
#define	SMS_E_UNIDENTIFIEDSUBCRIBER		0x010f
#define	SMS_E_FDNRESTRICT			0x0110

#endif /* _WIN32_WCE >= 0x0600 */

#ifdef	__cplusplus		0	/* ? */
}
#endif		0	/* ? */

#endif	/* _SMS_H */		0	/* ? */
