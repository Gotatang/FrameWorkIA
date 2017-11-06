/*Documentation												*/
/*@author	:	Quentin Ladevie								*/
/*@file		:	Font.hpp									*/
/*@date		:	30/12/2015									*/
/*@brief	:	Fichier d'en-tête des polices abstraites	*/
#ifndef __FONT_H_
#define __FONT_H_

#define FONTS_PATH "../Resources/Fonts/"

#include "ExportSFML.hpp"


namespace DadEngine
{
	class DADENGINE_SFMLAPI Font
	{

	public:

		Font() {};

		virtual ~Font() {};

		// Get a copy
		virtual Font* GetClone() = 0;
	};
}

#endif // __FONT_H_