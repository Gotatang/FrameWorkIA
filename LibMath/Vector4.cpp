/*Documentation													*/
/*@author	:	Quentin Ladevie									*/
/*@file		:	Vector4.cpp										*/
/*@date		:	19/11/2015										*/
/*@brief	:	Fichier source des vecteurs à 4 Dimensions		*/
#include "stdafx.h"
#include "Vector4.hpp"


namespace DadEngine
{
	Vector4::Vector4()
	{
		*this = VECTOR4ZERO;
	}

	Vector4::Vector4(const Vector4& _copy)
	{
		*this = _copy;
	}

	Vector4::Vector4(float _fX, float _fY, float _fZ, float _fW)
	{
		m_fX = _fX;
		m_fY = _fY;
		m_fZ = _fZ;
		m_fW = _fW;
	}

	Vector4:: ~Vector4()
	{}


	// Handling functions
	Vector4 Vector4::Lerp(const Vector4 _from, const Vector4 _to, float _step)
	{
		Vector4 result;

		result.m_fX = _from.m_fX + _step * (_to.m_fX - _from.m_fX);
		result.m_fY = _from.m_fY + _step * (_to.m_fY - _from.m_fY);
		result.m_fZ = _from.m_fZ + _step * (_to.m_fZ - _from.m_fZ);
		result.m_fW = _from.m_fW + _step * (_to.m_fW - _from.m_fW);

		return result;
	}

	void Vector4::Scale(float _fScaleFactor)
	{
		m_fX *= _fScaleFactor;
		m_fY *= _fScaleFactor;
		m_fZ *= _fScaleFactor;
		m_fW *= _fScaleFactor;
	}

	void Vector4::Translate(float _fX, float _fY, float _fZ, float _fW)
	{
		m_fX += _fX;
		m_fY += _fY;
		m_fZ += _fZ;
		m_fW += _fW;
	}

	void Vector4::Display() const
	{
		cout << "X : " << m_fX << endl << "Y : " << m_fY << endl << "Z : " << m_fZ << endl << "W : " << m_fW << endl;
	}

	float Vector4::Length() const
	{
		float fOneOverW = 1 / m_fW;

		return fOneOverW * sqrt(m_fX * m_fX + m_fY * m_fY + m_fZ * m_fZ);
	}

	bool Vector4::IsNullByEpsilon() const
	{
		return Length() < EPSILON;
	}

	bool Vector4::IsUnitByEpsilon() const
	{
		float fLength = this->Length();

		bool IsNullByEpsilon = false;

		if (fLength < 1.f + EPSILON && fLength > 1.f - EPSILON)
		{
			IsNullByEpsilon = true;
		}

		return IsNullByEpsilon;
	}

	bool Vector4::Normalize()
	{
		float fLength = Length();

		if (fLength > EPSILON)
		{
			m_fW *= fLength;

			return EXIT_SUCCESS;
		}

		return EXIT_FAILURE;
	}

	float Vector4::Dot(const Vector4 &_vector1) const
	{
		assert(m_fW * _vector1.m_fW);

		return (m_fX * _vector1.m_fX + m_fY * _vector1.m_fY + m_fZ * _vector1.m_fZ) / (m_fW * _vector1.m_fW);
	}

	float Vector4::Angle(const Vector4 &_vector1) const
	{
		return acos(Dot(_vector1) / (Length() * _vector1.Length()));
	}

	Vector4 Vector4::Cross(const Vector4 &_vector1) const
	{
		Vector4 result;

		result.m_fX = (m_fY * _vector1.m_fZ - m_fZ * _vector1.m_fY);
		result.m_fY = (m_fZ * _vector1.m_fX - m_fX * _vector1.m_fZ);
		result.m_fZ = (m_fX * _vector1.m_fY - m_fY * _vector1.m_fX);
		result.m_fW = m_fW * _vector1.m_fW;

		return result;
	}


	// DADENGINE_MATHAPI friend
	ostream& operator <<(ostream& _o, const Vector4& _v)
	{
		_o << "X : " << _v.m_fX << endl << "Y : " << _v.m_fY << endl << "Z : " << _v.m_fZ << endl << "W : " << _v.m_fW << endl << endl;

		return _o;
	}

	istream& operator >>(istream& _i, Vector4& _v)
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

		cout << "W :" << endl;
		_i.clear();
		_i.sync();
		_i >> _v.m_fW;

		return _i;
	}
}