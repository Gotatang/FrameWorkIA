/*Documentation									*/
/*@author	:	Quentin Ladevie					*/
/*@file		:	Shape.hpp						*/
/*@date		:	08/12/2015						*/
/*@brief	:	Fichier d'en-tête des shapes	*/
#ifndef __SHAPE_H_
#define __SHAPE_H_

#include "ExportSFML.hpp"
#include "SFML\Graphics.hpp"
#include <iostream>

using std::ostream;


namespace DadEngine
{
	class DADENGINE_SFMLAPI Shape
	{

	public:

		Shape();

		~Shape();


		// Debug
		virtual void Display() const = 0;

		DADENGINE_SFMLAPI friend ostream& operator<< (ostream& _out, const Shape& _s);
	};
}

#endif // __SHAPE_H_