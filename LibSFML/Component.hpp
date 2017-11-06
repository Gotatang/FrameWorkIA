/*Documentation														*/
/*@author	:	Quentin Ladevie										*/
/*@file		:	Component.hpp										*/
/*@date		:	22/12/2015											*/
/*@brief	:	Fichier d'en-tête de la classe abstraite composant	*/
#ifndef __COMPONENT_H_
#define __COMPONENT_H_

#include "ExportSFML.hpp"


namespace DadEngine
{
	class DADENGINE_SFMLAPI Component
	{
	public:

		Component() {};

		virtual ~Component() {};


		virtual bool Update() = 0;
		virtual bool Draw() = 0;
	};
}

#endif // __COMPONENT_H_