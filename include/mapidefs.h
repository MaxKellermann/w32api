#ifndef _MAPIDEFS_H
#define _MAPIDEFS_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

/*
* http://msdn.microsoft.com/en-us/library/ms862955.aspx (PROP_ID)
* http://msdn.microsoft.com/en-us/library/ms862956.aspx (PROP_TAG)
* http://msdn.microsoft.com/en-us/library/ms862957.aspx (PROP_TYPE)
*/

#define PROP_TYPE(ulPropTag)    (((ULONG)(ulPropTag))& 0x0000FFFF)
#define PROP_ID(ulPropTag)      (((ULONG)(ulPropTag)) >> 16)
#define PROP_TAG(ulPropType,ulPropID)   ((((ULONG)(ulPropID)) << 16)|((ULONG)(ulPropType)))


#endif	/* Not _MAPIDEFS_H */