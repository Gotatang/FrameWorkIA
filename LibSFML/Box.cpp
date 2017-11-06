/*Documentation								*/
/*@author	:	Quentin Ladevie				*/
/*@file		:	Box.cpp						*/
/*@date		:	09/12/2015					*/
/*@brief	:	Fichier source des cubes	*/
#include "stdafx.h"
#include "Box.hpp"


namespace DadEngine
{
	Box::Box(float _fWidth, float _fheight, float _fDepth) : m_fWidth(_fWidth), m_fHeight(_fheight), m_fDepth(_fDepth)
	{}

	Box::Box(const Point3& _pOrigin, const Point3& _pPosition, const Matrix33& _mDirection, float _fWidth, float _fheight, float _fDepth) : Shape3D(_pOrigin, _pPosition, _mDirection), m_fWidth(_fWidth), m_fHeight(_fheight), m_fDepth(_fDepth)
	{}


	Box::~Box()
	{}


	// Get/Set
	Point3 Box::GetPoint(int _iIndex) const
	{
		if (_iIndex < BOX_POINT_COUNT)
		{
			Point3 pSeekedPoint;

			pSeekedPoint.SetX(m_pPosition.GetX() + ((_iIndex & 1) * m_fWidth));
			pSeekedPoint.SetY(m_pPosition.GetY() + (((_iIndex & 010) >> 1) * m_fHeight));
			pSeekedPoint.SetZ(m_pPosition.GetZ() + ((_iIndex >> 2) * m_fDepth));

			return pSeekedPoint;
		}

		return Point3();
	}

	int Box::GetPointCount()
	{
		return BOX_POINT_COUNT;
	}


	float Box::GetWidth() const
	{
		return m_fWidth;
	}

	float Box::GetHeight() const
	{
		return m_fHeight;
	}

	float Box::GetDepth() const
	{
		return m_fDepth;
	}


	void Box::SetWidth(float _fNewWidth)
	{
		m_fWidth = _fNewWidth;
	}

	void Box::SetHeight(float _fNewHeight)
	{
		m_fHeight = _fNewHeight;
	}

	void Box::SetDepth(float _fNewDepth)
	{
		m_fDepth = _fNewDepth;
	}


	// Display
	void Box::Draw(sf::RenderWindow* _wnd)
	{

	}


	// Debug
	void Box::Display() const
	{
		cout << *this;
	}

	ostream& operator<< (ostream& _out, const Box& _b)
	{
		Shape3D* s = (Shape3D*)&_b;

		_out << "Membres Shape 3D : " << *s << endl;
		_out << "Largeur :" << _b.m_fWidth << endl;
		_out << "Hauteur :" << _b.m_fHeight << endl;
		_out << "Profondeur :" << _b.m_fDepth << endl;

		return _out;
	}
}