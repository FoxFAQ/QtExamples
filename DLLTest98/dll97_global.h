#ifndef DLL97_GLOBAL_H
#define DLL97_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DLL97_LIBRARY)
#  define DLL97SHARED_EXPORT Q_DECL_EXPORT
#else
#  define DLL97SHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // DLL97_GLOBAL_H
