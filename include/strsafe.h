#ifndef _STRSAFE_H 
#define _STRSAFE_H 
#if __GNUC__ >= 3 
#pragma GCC system_header 
#endif 
        
#ifdef __cplusplus 
extern "C" {
#endif 

/*http://msdn.microsoft.com/en-us/library/ms860410.aspx*/
HRESULT StringCchCatA(LPSTR pszDest, size_t cchDest, LPCSTR pszSrc);
HRESULT StringCchCatW(LPWSTR pszDest, size_t cchDest, LPCWSTR pszSrc);

#ifdef UNICODE 
#define StringCchCat StringCchCatW
#else 
#define StringCchCat StringCchCatA
#endif

#ifdef __cplusplus 
}
#endif 
#endif 
