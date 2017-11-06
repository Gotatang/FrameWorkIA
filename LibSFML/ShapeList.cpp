/*Documentation														*/
/*@author	:	Quentin Ladevie										*/
/*@file		:	ShapeList.cpp										*/
/*@date		:	12/12/2015											*/
/*@brief	:	Fichier source de la liste des formes instancier	*/
#include "stdafx.h"
#include "ShapeList.hpp"


namespace DadEngine
{
	ShapeList::ShapeList()
	{}


	ShapeList::~ShapeList()
	{
		while (m_lShapeList.size())
		{
			m_lShapeList.pop_front();
		}

		m_lShapeList.clear();
	}


	// Get
	list <Shape*> ShapeList::GetList() const
	{
		return m_lShapeList;
	}


	// Handling
	void ShapeList::Add(Shape* _s)
	{
		m_lShapeList.push_front(_s);
	}

	void ShapeList::Delete(Shape* _s)
	{
		m_lShapeList.remove(_s);
	}

	void ShapeList::DeleteAll()
	{
		while (m_lShapeList.size())
		{
			m_lShapeList.pop_front();
		}

		m_lShapeList.clear();
	}


	// Debug
	void ShapeList::Display()
	{
		for (list<Shape*>::iterator iterator = m_lShapeList.begin(); iterator != m_lShapeList.end(); ++iterator)
		{
			cout << *iterator;
		}
	}
}