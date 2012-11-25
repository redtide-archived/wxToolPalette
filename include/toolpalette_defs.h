/*
    Name:        dllimpexp.h
    Purpose:     
    Author:      Andrea Zanellato
    Modified by: 
    Created:     2012/11/25
    Revision:    $Hash$
    Copyleft:    (ɔ) Andrea Zanellato
    Licence:     GNU General Public License Version 3
*/
#ifndef __WXTOOLPALETTE_DLLIMPEXP_H__
#define __WXTOOLPALETTE_DLLIMPEXP_H__

#include <wx/dlimpexp.h>

#if defined(WXMAKINGLIB)
  #define WXDLLIMPEXP_TOOLPALETTE
#elif defined(WXMAKINGDLL_TOOLPALETTE)
  #define WXDLLIMPEXP_TOOLPALETTE WXEXPORT
#elif defined(WXUSINGDLL)
  #define WXDLLIMPEXP_TOOLPALETTE WXIMPORT
#else // not making nor using DLL
  #define WXDLLIMPEXP_TOOLPALETTE
#endif

#endif // __WXTOOLPALETTE_DLLIMPEXP_H__
