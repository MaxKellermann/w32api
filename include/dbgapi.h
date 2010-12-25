#ifndef __DBGAPI_H_
#define __DBGAPI_H_

#if __GNUC__ >= 3
#pragma GCC system_header
#endif

#ifdef  __cplusplus
extern "C" {
#endif

#if _WIN32_WCE >= 0x0200

/*
 * Macros that should behave differently depending on production or debug build.
 *
 * This implementation only provides for production build behaviour, for now.
 */
#define	DEBUGREGISTER(x)	/* ?? */
#define	RETAILREGISTERZONES(x)	/* ?? */
#define	DEBUGCHK(x)		/* ?? */
#define	RETAILMSG(x,y)		/* ?? */
#define	ASSERT(x)		/* ?? */

#endif	/* _WIN32_WCE */

#ifdef  __cplusplus
}
#endif

#endif	/* __DBGAPI_H_ */
