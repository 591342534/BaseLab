
// -*- C++ -*-
// $Id: minizip_export.h 80826 2008-03-04 14:51:23Z wotte $
// Definition for Win32 Export directives.

#ifndef MINIZIP_EXPORT_H
#define MINIZIP_EXPORT_H

#if defined (MINIZIP_AS_STATIC_LIBS)
#  if !defined (MINIZIP_HAS_DLL)
#    define MINIZIP_HAS_DLL 0
#  endif /* ! MINIZIP_HAS_DLL */
#else
# if !defined (MINIZIP_HAS_DLL)
#   define MINIZIP_HAS_DLL 1
# endif /* ! MINIZIP_HAS_DLL */
#endif /* MINIZIP_AS_STATIC_LIBS */

#if defined (MINIZIP_HAS_DLL) 
#  if (MINIZIP_HAS_DLL == 1) && defined (_WINDOWS)
#    if defined (MINIZIP_BUILD_DLL)
#      define MINIZIP_EXPORT  __declspec(dllexport)
#    else /* MINIZIP_BUILD_DLL */
#      define MINIZIP_EXPORT __declspec(dllimport)
#    endif /* MINIZIP_BUILD_DLL */
#  else /* MINIZIP_HAS_DLL == 1 */
#      define MINIZIP_EXPORT
#  endif /* MINIZIP_HAS_DLL == 1 */
#endif /* MINIZIP_HAS_DLL */

# define MINIZIP_UNUSED_ARG(a) do {/* null */} while (&a == 0)

#endif /* MINIZIP_EXPORT_H */
