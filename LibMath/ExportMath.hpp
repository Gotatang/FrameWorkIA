#ifndef __EXPORTMATH_H_
#define __EXPORTMATH_H_

#ifdef DADENGINE_EXPORT
#		define DADENGINE_MATHAPI __declspec(dllexport)
#else
#		define DADENGINE_MATHAPI __declspec(dllimport)
#endif // DADENGINE_EXPORT

#endif // __EXPORTMATH_H_
