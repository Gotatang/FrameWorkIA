/*Documentation													*/
/*@author	:	Quentin Ladevie									*/
/*@file		:	Vector2.cpp										*/
/*@date		:	19/11/2015										*/
/*@brief	:	Fichier source des vecteurs à 2 Dimensions		*/
#include "stdafx.h"
#include "Vector2.hpp"


namespace DadEngine
{
	Vector2::Vector2()
	{
		*this = VECTOR2ZERO;
	}

	Vector2::Vector2(const Vector2& _copy)
	{
		*this = _copy;
	}

	Vector2::Vector2(float _fX, float _fY)
	{
		m_fX = _fX;
		m_fY = _fY;
	}

	Vector2::~Vector2()
	{}


	// Set/Get functions
	inline void Vector2::SetX(float _fX)
	{
		m_fX = _fX;
	}

	inline void Vector2::SetY(float _fY)
	{
		m_fY = _fY;
	}

	inline float Vector2::GetX() const
	{
		return m_fX;
	}

	inline float Vector2::GetY() const
	{
		return m_fY;
	}


	// Handling functions
	Vector2 Vector2::Lerp(const Vector2 _from, const Vector2 _to, float _step)
	{
		Vector2 result;

		result.SetX(_from.m_fX + _step * (_to.GetX() - _from.m_fX));
		result.SetY(_from.m_fY + _step * (_to.GetY() - _from.m_fY));

		return result;
	}

	void Vector2::Scale(float _fScaleFactor)
	{
		m_fX *= _fScaleFactor;
		m_fY *= _fScaleFactor;
	}

	void Vector2::Translate(float _fX, float _fY)
	{
		m_fX += _fX;
		m_fY += _fY;
	}

	void Vector2::Display() const
	{
		cout << "X : " << m_fX << endl << "Y : " << m_fY << endl;
	}

	float Vector2::Length() const
	{
		return sqrt(m_fX * m_fX + m_fY * m_fY);
	}

	bool Vector2::IsNullByEpsilon() const
	{
		return Length() < EPSILON;
	}

	bool Vector2::IsUnitByEpsilon() const
	{
		float fLength = this->Length();

		bool IsNullByEpsilon = false;

		if (fLength < 1.f + EPSILON && fLength > 1.f - EPSILON)
		{
			IsNullByEpsilon = true;
		}

		return IsNullByEpsilon;
	}

	bool Vector2::Normalize()
	{
		float fLength = this->Length();

		if (fLength)
		{
			m_fX /= fLength;
			m_fY /= fLength;

			return EXIT_SUCCESS;
		}

		return EXIT_FAILURE;
	}

	float Vector2::Dot(const Vector2 &_vector1) const
	{
		return m_fX * _vector1.GetX() + m_fY * _vector1.GetY();
	}

	float Vector2::Angle(const Vector2 &_vector1) const
	{
		return acos(Dot(_vector1) / (Length() * _vector1.Length()));
	}


	// Assignement operators
	Vector2& Vector2::operator+= (const Vector2& _v)
	{
		m_fX += _v.m_fX;
		m_fY += _v.m_fY;

		return *this;
	}

	Vector2& Vector2::operator-= (const Vector2& _v)
	{
		m_fX -= _v.m_fX;
		m_fY -= _v.m_fY;

		return *this;
	}

	Vector2& Vector2::operator*= (float _f)
	{
		m_fX *= _f;
		m_fY *= _f;

		return *this;
	}

	Vector2& Vector2::operator/= (float _f)
	{
		m_fX /= _f;
		m_fY /= _f;

		return *this;
	}


	// Unary operators
	Vector2 Vector2::operator+ () const
	{
		Vector2 result(abs(m_fX), abs(m_fY));

		return result;
	}

	Vector2 Vector2::operator- () const
	{
		Vector2 result(-m_fX, -m_fY);

		return result;
	}


	// Binary operators
	Vector2 Vector2::operator+ (const Vector2& _v) const
	{
		Vector2 result(m_fX + _v.m_fX, m_fY + _v.m_fY);

		return result;
	}

	Vector2 Vector2::operator- (const Vector2& _v) const
	{
		Vector2 result(m_fX - _v.m_fX, m_fY - _v.m_fY);

		return result;
	}

	Vector2 Vector2::operator* (float _f) const
	{
		Vector2 result(m_fX * _f, m_fY * _f);

		return result;
	}

	Vector2 Vector2::operator/ (float _f) const
	{
		Vector2 result(m_fX / _f, m_fY / _f);

		return result;
	}


	bool Vector2::operator== (const Vector2& _v) const
	{
		return (m_fX == _v.m_fX && m_fY == _v.m_fY);
	}

	bool Vector2::operator!= (const Vector2& _v) const
	{
		return (m_fX != _v.m_fX || m_fY != _v.m_fY);
	}


	// DADENGINE_MATHAPI friends operators
	Vector2 operator* (float _f, const Vector2& _v)
	{
		Vector2 result(_v * _f);

		return result;
	}

	ostream& operator <<(ostream& _o, const Vector2& _v)
	{
		_o << "X : " << _v.m_fX << endl << "Y : " << _v.m_fY << endl << endl;

		return _o;
	}

	istream& operator >>(istream& _i, Vector2& _v)
	{
		cout << "X : ";
		_i.clear();
		_i.sync();
		_i >> _v.m_fX;
		cout << endl;

		cout << "Y : ";
		_i.clear();
		_i.sync();
		_i >> _v.m_fY;
		cout << endl;

		return _i;
	}
}