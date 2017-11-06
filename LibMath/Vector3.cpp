/*Documentation													*/
/*@author	:	Quentin Ladevie									*/
/*@file		:	Vector3.cpp										*/
/*@date		:	19/11/2015										*/
/*@brief	:	Fichier source des vecteurs à 3 Dimensions		*/
#include "stdafx.h"
#include "Vector3.hpp"


namespace DadEngine
{
	Vector3::Vector3()
	{
		*this = VECTOR3ZERO;
	}

	Vector3::Vector3(const Vector3& _copy)
	{
		*this = _copy;
	}

	Vector3::Vector3(float _fX, float _fY, float _fZ)
	{
		m_fX = _fX;
		m_fY = _fY;
		m_fZ = _fZ;
	}

	Vector3::Vector3(Vector2& _v)
	{
		m_fX = _v.GetX();
		m_fY = _v.GetY();
		m_fZ = 1.f;
	}


	Vector3::~Vector3()
	{}


	// Set/Get functions
	inline void Vector3::SetX(float _fX)
	{
		m_fX = _fX;
	}

	inline void Vector3::SetY(float _fY)
	{
		m_fY = _fY;
	}

	inline void Vector3::SetZ(float _fZ)
	{
		m_fZ = _fZ;
	}


	inline float Vector3::GetX() const
	{
		return m_fX;
	}

	inline float Vector3::GetY() const
	{
		return m_fY;
	}

	inline float Vector3::GetZ() const
	{
		return m_fZ;
	}


	// Handling functions
	Vector3 Vector3::Lerp(const Vector3 _from, const Vector3 _to, float _step)
	{
		Vector3 result;

		result.SetX(_from.m_fX + _step * (_to.m_fX - _from.m_fX));
		result.SetY(_from.m_fY + _step * (_to.m_fY - _from.m_fY));
		result.SetZ(_from.m_fZ + _step * (_to.m_fZ - _from.m_fZ));

		return result;
	}

	void Vector3::Scale(float _fScaleFactor)
	{
		m_fX *= _fScaleFactor;
		m_fY *= _fScaleFactor;
		m_fZ *= _fScaleFactor;
	}

	void Vector3::Translate(float _fX, float _fY, float _fZ)
	{
		m_fX += _fX;
		m_fY += _fY;
		m_fZ += _fZ;
	}

	void Vector3::Display() const
	{
		cout << "X : " << m_fX << endl << "Y : " << m_fY << endl << "Z : " << m_fZ << endl;
	}


	float Vector3::Length() const
	{
		return sqrt(m_fX * m_fX + m_fY * m_fY + m_fZ * m_fZ);
	}

	bool Vector3::IsNullByEpsilon() const
	{
		return Length() < EPSILON;
	}

	bool Vector3::IsUnitByEpsilon() const
	{
		float fLength = this->Length();

		bool IsNullByEpsilon = false;

		if (fLength < 1.f + EPSILON && fLength > 1.f - EPSILON)
		{
			IsNullByEpsilon = true;
		}

		return IsNullByEpsilon;
	}

	bool Vector3::Normalize()
	{
		float fLength = this->Length();

		if (fLength)
		{
			m_fX /= fLength;
			m_fY /= fLength;
			m_fZ /= fLength;

			return EXIT_SUCCESS;
		}

		return EXIT_FAILURE;
	}

	float Vector3::Dot(const Vector3 &_vector1) const
	{
		return m_fX * _vector1.GetX() + m_fY * _vector1.GetY() + m_fZ * _vector1.GetZ();
	}

	float Vector3::Angle(const Vector3 &_vector1) const
	{
		return acos(Dot(_vector1) / (Length() * _vector1.Length()));
	}

	Vector3 Vector3::Cross(const Vector3 &_vector1) const
	{
		Vector3 result;

		result.m_fX = (m_fY * _vector1.m_fZ - m_fZ * _vector1.m_fY);
		result.m_fY = (m_fZ * _vector1.m_fX - m_fX * _vector1.m_fZ);
		result.m_fZ = (m_fX * _vector1.m_fY - m_fY * _vector1.m_fX);

		return result;
	}


	// Assignement operators
	Vector3& Vector3::operator+= (const Vector3& _v)
	{
		m_fX += _v.m_fX;
		m_fY += _v.m_fY;
		m_fZ += _v.m_fZ;

		return *this;
	}

	Vector3& Vector3::operator-= (const Vector3& _v)
	{
		m_fX -= _v.m_fX;
		m_fY -= _v.m_fY;
		m_fZ -= _v.m_fZ;

		return *this;
	}

	Vector3& Vector3::operator*= (float _f)
	{
		m_fX *= _f;
		m_fY *= _f;
		m_fZ *= _f;

		return *this;
	}

	Vector3& Vector3::operator/= (float _f)
	{
		m_fX /= _f;
		m_fY /= _f;
		m_fZ /= _f;

		return *this;
	}


	// Unary operators
	Vector3 Vector3::operator+ () const
	{
		Vector3 result(abs(m_fX), abs(m_fY), abs(m_fZ));

		return result;
	}

	Vector3 Vector3::operator- () const
	{
		Vector3 result(-m_fX, -m_fY, -m_fZ);

		return result;
	}


	// Binary operators
	Vector3 Vector3::operator+ (const Vector3& _v) const
	{
		Vector3 result(m_fX + _v.m_fX, m_fY + _v.m_fY, m_fZ + _v.m_fZ);

		return result;
	}

	Vector3 Vector3::operator- (const Vector3& _v) const
	{
		Vector3 result(m_fX - _v.m_fX, m_fY - _v.m_fY, m_fZ - _v.m_fZ);

		return result;
	}

	Vector3 Vector3::operator* (float _f) const
	{
		Vector3 result(m_fX * _f, m_fY * _f, m_fZ * _f);

		return result;
	}

	Vector3 Vector3::operator/ (float _f) const
	{
		Vector3 result(m_fX / _f, m_fY / _f, m_fZ / _f);

		return result;
	}


	bool Vector3::operator== (const Vector3& _v) const
	{
		return (m_fX == _v.m_fX && m_fY == _v.m_fY && m_fZ == _v.m_fZ);
	}

	bool Vector3::operator!= (const Vector3& _v) const
	{
		return (m_fX != _v.m_fX || m_fY != _v.m_fY || m_fZ != _v.m_fZ);
	}


	// DADENGINE_MATHAPI friends operators
	Vector3 operator* (float _f, const Vector3& _v)
	{
		Vector3 result(_v * _f);

		return result;
	}

	ostream& operator <<(ostream& _o, const Vector3& _v)
	{
		_o << "X : " << _v.m_fX << endl << "Y : " << _v.m_fY << endl << "Z : " << _v.m_fZ << endl << endl;

		return _o;
	}

	istream& operator >>(istream& _i, Vector3& _v)
	{
		cout << "X :" << endl;
		_i.clear();
		_i.sync();
		_i >> _v.m_fX;

		cout << "Y :" << endl;
		_i.clear();
		_i.sync();
		_i >> _v.m_fY;

		cout << "Z :" << endl;
		_i.clear();
		_i.sync();
		_i >> _v.m_fZ;

		return _i;
	}
}