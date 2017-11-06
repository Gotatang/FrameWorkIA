/*Documentation												*/
/*@author	:	Quentin Ladevie								*/
/*@file		:	Texture.hpp									*/
/*@date		:	22/12/2015									*/
/*@brief	:	Fichier d'en-tête des textures abstraites	*/
#ifndef __TEXTURE_H_
#define __TEXTURE_H_

#define TEXTURES_PATH "../Resources/Textures/"

#include "ExportSFML.hpp"


namespace DadEngine
{
	class DADENGINE_SFMLAPI Texture
	{

	public:

		Texture() {};

		virtual ~Texture() {};

		
		// Get a copy
		virtual Texture* GetClone() = 0;
	};
}

#endif // __TEXTURE_H_