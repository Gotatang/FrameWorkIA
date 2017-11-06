/*Documentation												*/
/*@author	:	Quentin Ladevie								*/
/*@file		:	Shape2D.cpp									*/
/*@date		:	08/12/2015									*/
/*@brief	:	Fichier source des shapes en 2 dimensions	*/
#include "stdafx.h"
#include "Shape2D.hpp"


namespace DadEngine
{
	Shape2D::Shape2D() : m_pOrigin(), m_pPosition(), m_mDirection()
	{}

	Shape2D::Shape2D(const Point2& _pOrigin, const Point2& _pPosition, const Matrix22& _mDirection) : m_pOrigin(_pOrigin), m_pPosition(_pPosition), m_mDirection(_mDirection)
	{}


	Shape2D::~Shape2D()
	{}


	// Get/Set
	Point2 Shape2D::GetOrigin() const
	{
		return m_pOrigin;
	}

	Point2 Shape2D::GetPosition() const
	{
		return m_pPosition;
	}

	Matrix22 Shape2D::GetDirection() const
	{
		return m_mDirection;
	}


	void Shape2D::SetOrigin(Point2& _pNewOrigin)
	{
		m_pOrigin = _pNewOrigin;
	}

	void Shape2D::SetPosition(Point2& _pNewPosition)
	{
		m_pPosition = _pNewPosition;
	}

	void Shape2D::SetDirection(Matrix22& _mNewDirection)
	{
		m_mDirection = _mNewDirection;
	}


	// Debug
	ostream& operator<< (ostream& _out, const Shape2D& _s)
	{
		_out << "Origin : " << _s.m_pOrigin << endl;
		_out << "Position : " << _s.m_pPosition << endl;
		_out << "Direction : " << _s.m_mDirection << endl;

		return _out;
	}
}