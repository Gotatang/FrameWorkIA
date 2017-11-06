/*Documentation																	*/
/*@author	:	Quentin Ladevie													*/
/*@file		:	Constants.hpp													*/
/*@date		:	09/12/2015														*/
/*@brief	:	Fichier d'en-tête contenants les constantes de la bibliothèque	*/
#ifndef __CONSTANTS_H_
#define __CONSTANTS_H_

namespace DadEngine
{
	const float C_2PI =		6.28318530718f;
	const float C_PI =		3.14159265359f;
	const float C_PI2 =		1.57079632679f;
	const float e =			2.718281828f;
	const float EPSILON =	0.0001f;

	inline float LERP(float _f1, float _f2, float _step)
	{
		return ((1 - _step) * _f1) + (_step * _f2);
	}
}

#endif // __CONSTANTS_H_