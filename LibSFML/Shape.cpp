/*Documentation								*/
/*@author	:	Quentin Ladevie				*/
/*@file		:	Shape.cpp					*/
/*@date		:	08/12/2015					*/
/*@brief	:	Fichier source des shapes	*/
#include "stdafx.h"
#include "Shape.hpp"


namespace DadEngine
{
	Shape::Shape()
	{
		ShapeList::GetInstance()->Add(this);
	}

	Shape::~Shape()
	{
		ShapeList::GetInstance()->Delete(this);
	}


	ostream& operator<< (ostream& _out, const Shape& _s)
	{
		_s.Display();

		return _out;
	}
}