/*Documentation											*/
/*@author	:	Quentin Ladevie							*/
/*@file		:	Text.hpp								*/
/*@date		:	29/12/2015								*/
/*@brief	:	Fichier d'en-tête des text abstraits	*/
#ifndef __TEXT_H_
#define __TEXT_H_

#include "ExportSFML.hpp"


namespace DadEngine
{
	class DADENGINE_SFMLAPI Text
	{

	public:

		Text() {};

		virtual ~Text() {};


		// Get a copy
		virtual Text* GetClone() = 0;
	};
}

#endif // __TEXT_H_