#ifndef _AF_IRDA_H
#define _AF_IRDA_H

#include <winsock2.h>

typedef struct _SOCKADDR_IRDA {
  u_short irdaAddressFamily;
  u_char irdaDeviceID[4];
  char irdaServiceName[25];
} SOCKADDR_IRDA, *PSOCKADDR_IRDA, *LPSOCKADDR_IRDA;

typedef struct IRDA_DEVICE_INFO {
  u_char irdaDeviceID[4];
  char irdaDeviceName[22];
  u_char Reserved[2];
} _IRDA_DEVICE_INFO;
typedef _IRDA_DEVICE_INFO IRDA_DEVICE_INFO;

typedef struct DEVICELIST {
  ULONG numDevice;
  IRDA_DEVICE_INFO Device [1];
} _DEVICELIST, *PWCE_DEVICELIST;

typedef _DEVICELIST DEVICELIST;

typedef struct IAS_QUERY {
  u_char irdaDeviceID[4];
  char irdaClassName[61];
  char irdaAttribName[61];
  u_short irdaAttribType;
  union {
    int irdaAttribInt;
    struct {
      int Len;
      u_char OctetSeq[1];
      u_char Reserved[3];
    } irdaAttribOctetSeq;
    struct {
      int Len;
      u_char CharSet;
      u_char UsrStr[1];
      u_char Reserved[2];
    } irdaAttribUsrStr;
  } irdaAttribute; 
} _IAS_QUERY, *PIAS_QUERY;

typedef struct _IAS_SET {
  char irdaClassName[61];
  char irdaAttribName[61];
  u_short irdaAttribType;
  union {
    int irdaAttribInt;
    struct {
      int Len;
      u_char OctetSeq[1];
      u_char Reserved[3];
    } irdaAttribOctetSeq;
    struct {
      int Len;
      u_char CharSet;
      u_char UsrStr[1];
      u_char Reserved[2];
    } irdaAttribUsrStr;
  } irdaAttribute;
} _IAS_SET, *PIAS_SET;

#define IRLMP_ENUMDEVICES 0x00000010
#define SOL_IRLMP 0x00FF

#endif
