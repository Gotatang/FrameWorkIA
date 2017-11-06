/*Documentation												*/
/*@author	:	Quentin Ladevie								*/
/*@file		:	Point2.cpp									*/
/*@date		:	19/11/2015									*/
/*@brief	:	Fichier source des points à 2 Dimensions	*/
#include "stdafx.h"
#include "Point2.hpp"


namespace DadEngine
{
	Point2::Point2()
	{
		*this = POINT2ORIGIN;
	}

	Point2::Point2(const Point2 &_copy)
	{
		*this = _copy;
	}

	Point2::Point2(float _x, float _y)
	{
		m_fX = _x;
		m_fY = _y;
	}


	Point2::~Point2()
	{}



	// Handling functions
	Point2 Point2::Lerp(const Point2 _to, float _fSteps) const
	{
		Point2 result;

		result.SetX(m_fX + _fSteps * (_to.m_fX - m_fX));
		result.SetY(m_fY + _fSteps * (_to.m_fY - m_fY));

		return result;
	}

	void Point2::Translate(float _x, float _y)
	{
		m_fX += _x;
		m_fY += _y;
	}

	void Point2::Display() const
	{
		cout << "X : " << m_fX << endl << "Y : " << m_fY << endl;
	}


	// Assignement operators
	Point2& Point2::operator+= (const Point2& _p)
	{
		m_fX += _p.m_fX;
		m_fY += _p.m_fY;

		return *this;
	}

	Point2& Point2::operator-= (const Point2& _p)
	{
		m_fX -= _p.m_fX;
		m_fY -= _p.m_fY;

		return *this;
	}

	Point2& Point2::operator*= (float _f)
	{
		m_fX *= _f;
		m_fY *= _f;

		return *this;
	}

	Point2& Point2::operator/= (float _f)
	{
		m_fX /= _f;
		m_fY /= _f;

		return *this;
	}


	// Unary operators
	Point2 Point2::operator+ () const
	{
		Point2 result(abs(m_fX), abs(m_fY));

		return result;
	}

	Point2 Point2::operator- () const
	{
		Point2 result(-m_fX, -m_fY);

		return result;
	}


	// Binary operators
	Point2 Point2::operator+ (const Point2& _p) const
	{
		Point2 result(m_fX + _p.m_fX, m_fY + _p.m_fY);

		return result;
	}

	Point2 Point2::operator- (const Point2& _p) const
	{
		Point2 result(m_fX - _p.m_fX, m_fY - _p.m_fY);

		return result;
	}

	Point2 Point2::operator* (float _f) const
	{
		Point2 result(m_fX * _f, m_fY * _f);

		return result;
	}

	Point2 Point2::operator/ (float _f) const
	{
		Point2 result(m_fX / _f, m_fY / _f);

		return result;
	}


	bool Point2::operator== (const Point2& _p) const
	{
		return (m_fX == _p.m_fX && m_fY == _p.m_fY);
	}

	bool Point2::operator!= (const Point2& _p) const
	{
		return (m_fX != _p.m_fX || m_fY != _p.m_fY);
	}


	// DADENGINE_MATHAPI friends operators
	Point2 operator* (float _f, const Point2& _p)
	{
		Point2 result(_p * _f);

		return result;
	}

	ostream& operator <<(ostream& _o, const Point2& _p)
	{
		_o << "X : " << _p.m_fX << endl << "Y : " << _p.m_fY << endl << endl;

		return _o;
	}

	istream& operator >>(istream& _i, Point2& _p)
	{
		cout << "X : ";
		_i.clear();
		_i.sync();
		_i >> _p.m_fX;
		cout << endl;

		cout << "Y : ";
		_i.clear();
		_i.sync();
		_i >> _p.m_fY;
		cout << endl;

		return _i;
	}
}