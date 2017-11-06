#ifndef __EXPORTSFML_H_
#define __EXPORTSFML_H_

#ifdef DADENGINE_EXPORT
#		define DADENGINE_SFMLAPI __declspec(dllexport)
#else
#		define DADENGINE_SFMLAPI __declspec(dllimport)
#endif // DADENGINE_EXPORT

#endif // __EXPORTSFML_H_
