/*Documentation												*/
/*@author	:	Quentin Ladevie								*/
/*@file		:	Point3.cpp									*/
/*@date		:	19/11/2015									*/
/*@brief	:	Fichier source des points à 3 Dimensions	*/
#include "stdafx.h"
#include "Point3.hpp"


namespace DadEngine
{
	Point3::Point3()
	{
		*this = POINT3ORIGIN;
	}
	Point3::Point3(const Point3& _copy)
	{
		*this = _copy;
	}

	Point3::Point3(float _fX, float _fY, float _fZ)
	{
		m_fX = _fX;
		m_fY = _fY;
		m_fZ = _fZ;
	}


	Point3::~Point3()
	{}



	// Get/Set functions
	inline void Point3::SetX(float _fX)
	{
		m_fX = _fX;
	}

	inline void Point3::SetY(float _fY)
	{
		m_fY = _fY;
	}

	inline void Point3::SetZ(float _fZ)
	{
		m_fZ = _fZ;
	}


	inline float Point3::GetX() const
	{
		return m_fX;
	}

	inline float Point3::GetY() const
	{
		return m_fY;
	}

	inline float Point3::GetZ() const
	{
		return m_fZ;
	}



	// Handling functions
	Point3 Point3::Lerp(const Point3 _to, float _step) const
	{
		Point3 result;

		result.SetX(m_fX + _step * (_to.GetX() - m_fX));
		result.SetY(m_fY + _step * (_to.GetY() - m_fY));
		result.SetZ(m_fZ + _step * (_to.GetZ() - m_fZ));

		return result;
	}

	void Point3::Translate(float _fX, float _fY, float _fZ)
	{
		m_fX += _fX;
		m_fY += _fY;
		m_fZ += _fZ;
	}

	void Point3::Display() const
	{
		cout << "X : " << m_fX << endl << "Y : " << m_fY << endl << "Z : " << m_fZ << endl;
	}


	// Assignement operators
	Point3& Point3::operator+= (const Point3& _p)
	{
		m_fX += _p.m_fX;
		m_fY += _p.m_fY;
		m_fZ += _p.m_fZ;

		return *this;
	}

	Point3& Point3::operator-= (const Point3& _p)
	{
		m_fX -= _p.m_fX;
		m_fY -= _p.m_fY;
		m_fZ -= _p.m_fZ;

		return *this;
	}

	Point3& Point3::operator*= (float _f)
	{
		m_fX *= _f;
		m_fY *= _f;
		m_fZ *= _f;

		return *this;
	}

	Point3& Point3::operator/= (float _f)
	{
		m_fX /= _f;
		m_fY /= _f;
		m_fZ /= _f;

		return *this;
	}


	// Unary operators
	Point3 Point3::operator+ () const
	{
		Point3 result(abs(m_fX), abs(m_fY), abs(m_fZ));

		return result;
	}

	Point3 Point3::operator- () const
	{
		Point3 result(-m_fX, -m_fY, -m_fZ);

		return result;
	}


	// Binary operators
	Point3 Point3::operator+ (const Point3& _p) const
	{
		Point3 result(m_fX + _p.m_fX, m_fY + _p.m_fY, m_fZ + _p.m_fZ);

		return result;
	}

	Point3 Point3::operator- (const Point3& _p) const
	{
		Point3 result(m_fX - _p.m_fX, m_fY - _p.m_fY, m_fZ - _p.m_fZ);

		return result;
	}

	Point3 Point3::operator* (float _f) const
	{
		Point3 result(m_fX * _f, m_fY * _f, m_fZ * _f);

		return result;
	}

	Point3 Point3::operator/ (float _f) const
	{
		Point3 result(m_fX / _f, m_fY / _f, m_fZ / _f);

		return result;
	}


	bool Point3::operator== (const Point3& _p) const
	{
		return (m_fX == _p.m_fX && m_fY == _p.m_fY && m_fZ == _p.m_fZ);
	}

	bool Point3::operator!= (const Point3& _p) const
	{
		return (m_fX != _p.m_fX || m_fY != _p.m_fY || m_fZ != _p.m_fZ);
	}


	// DADENGINE_MATHAPI friends operators
	Point3 operator* (float _f, const Point3& _p)
	{
		Point3 result(_p * _f);

		return result;
	}

	ostream& operator <<(ostream& _o, const Point3& _p)
	{
		_o << "X : " << _p.m_fX << endl << "Y : " << _p.m_fY << endl << "Z : " << _p.m_fZ << endl << endl;

		return _o;
	}

	istream& operator >>(istream& _i, Point3& _p)
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

		cout << "Z : ";
		_i.clear();
		_i.sync();
		_i >> _p.m_fZ;
		cout << endl;

		return _i;
	}
}