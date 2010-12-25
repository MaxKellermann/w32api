#ifndef	_PIMSTORE_H
#define	_PIMSTORE_H

#if __GNUC__ >= 3
#pragma GCC system_header
#endif

#ifdef	__cplusplus
extern "C" {
#endif

#include <windows.h>
#include <basetyps.h>	/* Make sure we have a CLSID definition */
#include <mapidefs.h>

/*
* http://msdn.microsoft.com/en-us/library/aa917573.aspx
* http://msdn.microsoft.com/en-us/library/bb446009.aspx
* http://msdn.microsoft.com/en-us/library/bb415504.aspx
*/

#define CEVT_PIM_STREAM                  (100)
#define CEVT_PIM_AUTO_I4                 (102)



#define PIMPR_ACCOUNT_NAME                    PROP_TAG( CEVT_LPWSTR,   0x00AB)
#define PIMPR_ANNIVERSARY                     PROP_TAG( CEVT_FILETIME, 0x00F1)
#define PIMPR_ASSISTANT_NAME                  PROP_TAG( CEVT_LPWSTR,   0x008F)
#define PIMPR_ASSISTANT_TELEPHONE_NUMBER      PROP_TAG( CEVT_LPWSTR,   0x00A1) 
#define PIMPR_BIRTHDAY                        PROP_TAG( CEVT_FILETIME, 0x00F0) 
#define PIMPR_BUSINESS_ADDRESS                PROP_TAG( CEVT_LPWSTR,   0x10C0) 
#define PIMPR_BUSINESS_ADDRESS_CITY           PROP_TAG( CEVT_LPWSTR,   0x00C2)
#define PIMPR_BUSINESS_ADDRESS_COUNTRY        PROP_TAG( CEVT_LPWSTR,   0x00C5)
#define PIMPR_BUSINESS_ADDRESS_POSTAL_CODE    PROP_TAG( CEVT_LPWSTR,   0x00C4)
#define PIMPR_BUSINESS_ADDRESS_STATE          PROP_TAG( CEVT_LPWSTR,   0x00C3)
#define PIMPR_BUSINESS_ADDRESS_STREET         PROP_TAG( CEVT_LPWSTR,   0x00C1)
#define PIMPR_BUSINESS_FAX_NUMBER             PROP_TAG( CEVT_LPWSTR,   0x009B)
#define PIMPR_BUSINESS_TELEPHONE_NUMBER       PROP_TAG( CEVT_LPWSTR,   0x0097) 
#define PIMPR_BUSINESS2_TELEPHONE_NUMBER      PROP_TAG( CEVT_LPWSTR,   0x0098) 
#define PIMPR_CAR_TELEPHONE_NUMBER            PROP_TAG( CEVT_LPWSTR,   0x009E) 
#define PIMPR_CHILDREN                        PROP_TAG( CEVT_LPWSTR,   0x00A6) 
#define PIMPR_COMPANY_NAME                    PROP_TAG( CEVT_LPWSTR,   0x008A) 
#define PIMPR_COMPANY_TELEPHONE_NUMBER        PROP_TAG( CEVT_LPWSTR,   0x00A0)
#define PIMPR_CONTACT_TYPE                    PROP_TAG( CEVT_UI4,      0x0102)
#define PIMPR_CUSTOMERID                      PROP_TAG( CEVT_LPWSTR,   0x00A9) 
#define PIMPR_DEPARTMENT                      PROP_TAG( CEVT_LPWSTR,   0x008B) 
#define PIMPR_DISPLAY_NAME                    PROP_TAG( CEVT_LPWSTR,   0x10A4) 
#define PIMPR_EMAIL1_ADDRESS                  PROP_TAG( CEVT_LPWSTR,   0x0090)  
#define PIMPR_EMAIL2_ADDRESS                  PROP_TAG( CEVT_LPWSTR,   0x0091)  
#define PIMPR_EMAIL3_ADDRESS                  PROP_TAG( CEVT_LPWSTR,   0x0092) 
#define PIMPR_FILEAS                          PROP_TAG( CEVT_LPWSTR,   0x0080) 
#define PIMPR_FIRST_NAME                      PROP_TAG( CEVT_LPWSTR,   0x0082) 
#define PIMPR_GOVERNMENTID                    PROP_TAG( CEVT_LPWSTR,   0x00AA) 
#define PIMPR_HOME_ADDRESS                    PROP_TAG( CEVT_LPWSTR,   0x10D0) 
#define PIMPR_HOME_ADDRESS_CITY               PROP_TAG( CEVT_LPWSTR,   0x00D2) 
#define PIMPR_HOME_ADDRESS_COUNTRY            PROP_TAG( CEVT_LPWSTR,   0x00D5) 
#define PIMPR_HOME_ADDRESS_POSTAL_CODE        PROP_TAG( CEVT_LPWSTR,   0x00D4) 
#define PIMPR_HOME_ADDRESS_STATE              PROP_TAG( CEVT_LPWSTR,   0x00D3) 
#define PIMPR_HOME_ADDRESS_STREET             PROP_TAG( CEVT_LPWSTR,   0x00D1) 
#define PIMPR_HOME_FAX_NUMBER                 PROP_TAG( CEVT_LPWSTR,   0x009C)
#define PIMPR_HOME_TELEPHONE_NUMBER           PROP_TAG( CEVT_LPWSTR,   0x0099) 
#define PIMPR_HOME2_TELEPHONE_NUMBER          PROP_TAG( CEVT_LPWSTR,   0x009A) 
#define PIMPR_IM1_ADDRESS                     PROP_TAG( CEVT_LPWSTR,   0x0093)  
#define PIMPR_IM2_ADDRESS                     PROP_TAG( CEVT_LPWSTR,   0x0094)  
#define PIMPR_IM3_ADDRESS                     PROP_TAG( CEVT_LPWSTR,   0x0095)
#define PIMPR_JOB_TITLE                       PROP_TAG( CEVT_LPWSTR,   0x008C) 
#define PIMPR_LAST_NAME                       PROP_TAG( CEVT_LPWSTR,   0x0084) 
#define PIMPR_MANAGER                         PROP_TAG( CEVT_LPWSTR,   0x008D) 
#define PIMPR_MIDDLE_NAME                     PROP_TAG( CEVT_LPWSTR,   0x0083) 
#define PIMPR_MMS                             PROP_TAG( CEVT_LPWSTR,   0x10A3) 
#define PIMPR_MOBILE_TELEPHONE_NUMBER         PROP_TAG( CEVT_LPWSTR,   0x0096)
#define PIMPR_NICKNAME                        PROP_TAG( CEVT_LPWSTR,   0x0086) 
#define PIMPR_OFFICE_LOCATION                 PROP_TAG( CEVT_LPWSTR,   0x008E) 
#define PIMPR_OTHER_ADDRESS                   PROP_TAG( CEVT_LPWSTR,   0x10E0) 
#define PIMPR_OTHER_ADDRESS_CITY              PROP_TAG( CEVT_LPWSTR,   0x00E2)
#define PIMPR_OTHER_ADDRESS_COUNTRY           PROP_TAG( CEVT_LPWSTR,   0x00E5)
#define PIMPR_OTHER_ADDRESS_POSTAL_CODE       PROP_TAG( CEVT_LPWSTR,   0x00E4) 
#define PIMPR_OTHER_ADDRESS_STATE             PROP_TAG( CEVT_LPWSTR,   0x00E3)
#define PIMPR_OTHER_ADDRESS_STREET            PROP_TAG( CEVT_LPWSTR,   0x00E1) 
#define PIMPR_PAGER_NUMBER                    PROP_TAG( CEVT_LPWSTR,   0x009D)
#define PIMPR_PICTURE                         PROP_TAG( CEVT_PIM_STREAM,0x00FF)
#define PIMPR_RADIO_TELEPHONE_NUMBER          PROP_TAG( CEVT_LPWSTR,   0x009F)
#define PIMPR_RINGTONE                        PROP_TAG( CEVT_LPWSTR,   0x00A8)
#define PIMPR_SIM_PHONE                       PROP_TAG( CEVT_LPWSTR,   0x0003) 
#define PIMPR_SMARTPROP                       PROP_TAG( CEVT_UI4,      0x00F8)
#define PIMPR_SMS                             PROP_TAG( CEVT_LPWSTR,   0x10A2)
#define PIMPR_SPOUSE                          PROP_TAG( CEVT_LPWSTR,   0x00A5) 
#define PIMPR_SUFFIX                          PROP_TAG( CEVT_LPWSTR,   0x0085) 
#define PIMPR_TITLE                           PROP_TAG( CEVT_LPWSTR,   0x0081)
#define PIMPR_WEB_PAGE                        PROP_TAG( CEVT_LPWSTR,   0x00A7)  
#define PIMPR_YOMI_COMPANY                    PROP_TAG( CEVT_LPWSTR,   0x0089) 
#define PIMPR_YOMI_FILEAS                     PROP_TAG( CEVT_LPWSTR,   0x0101)
#define PIMPR_YOMI_FIRSTNAME                  PROP_TAG( CEVT_LPWSTR,   0x0087) 
#define PIMPR_YOMI_LASTNAME                   PROP_TAG( CEVT_LPWSTR,   0x0088)




#ifdef	__cplusplus
}
#endif

#endif	/* _PIMSTORE_H */
