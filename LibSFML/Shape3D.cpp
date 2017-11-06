/*Documentation												*/
/*@author	:	Quentin Ladevie								*/
/*@file		:	Shape3D.cpp									*/
/*@date		:	08/12/2015									*/
/*@brief	:	Fichier source des shapes en 3 dimensions	*/
#include "stdafx.h"
#include "Shape3D.hpp"


namespace DadEngine
{
	Shape3D::Shape3D() : m_pOrigin(), m_pPosition(), m_mDirection()
	{}

	Shape3D::Shape3D(Point3 _pOrigin, Point3 _pPosition, Matrix33 _mDirection) : m_pOrigin(_pOrigin), m_pPosition(_pPosition), m_mDirection(_mDirection)
	{}


	Shape3D::~Shape3D()
	{}


	// Get/Set
	Point3 Shape3D::GetOrigin() const
	{
		return m_pOrigin;
	}

	Point3 Shape3D::GetPosition() const
	{
		return m_pPosition;
	}

	Matrix33 Shape3D::GetDirection() const
	{
		return m_mDirection;
	}


	void Shape3D::SetOrigin(Point3& _pNewOrigin)
	{
		m_pOrigin = _pNewOrigin;
	}

	void Shape3D::SetPosition(Point3& _pNewPosition)
	{
		m_pPosition = _pNewPosition;
	}

	void Shape3D::SetDirection(Matrix33& _mNewDirection)
	{
		m_mDirection = _mNewDirection;
	}


	// Debug
	ostream& operator<< (ostream& _out, const Shape3D& _s)
	{
		_out << "Origin : " << _s.m_pOrigin << endl;
		_out << "Position : " << _s.m_pPosition << endl;
		_out << "Direction : " << _s.m_mDirection << endl;

		return _out;
	}
}