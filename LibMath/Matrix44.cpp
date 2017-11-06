/*Documentation															*/
/*@author	:	Quentin Ladevie											*/
/*@file		:	Matrix44.hpp											*/
/*@date		:	03/12/2015												*/
/*@brief	:	Fichier source des matrices carré de dimension 4		*/
#include "stdafx.h"
#include "Matrix44.hpp"



namespace DadEngine
{
	// constructor and destructor
	Matrix44::Matrix44()
	{
		*this = MATRIX44ZERO;
	}

	Matrix44::Matrix44(float _afM[16])
	{
		// Row 0
		m_af[0][0] = _afM[0];
		m_af[0][1] = _afM[1];
		m_af[0][2] = _afM[2];
		m_af[0][3] = _afM[3];

		// Row 1
		m_af[1][0] = _afM[4];
		m_af[1][1] = _afM[5];
		m_af[1][2] = _afM[6];
		m_af[1][3] = _afM[7];

		// Row 2
		m_af[2][0] = _afM[8];
		m_af[2][1] = _afM[9];
		m_af[2][2] = _afM[10];
		m_af[2][3] = _afM[11];

		// Row 4
		m_af[3][0] = _afM[12];
		m_af[3][1] = _afM[13];
		m_af[3][2] = _afM[14];
		m_af[3][3] = _afM[15];
	}

	Matrix44::Matrix44(float _fM11, float _fM12, float _fM13, float _fM14,
					   float _fM21, float _fM22, float _fM23, float _fM24,
					   float _fM31, float _fM32, float _fM33, float _fM34,
					   float _fM41, float _fM42, float _fM43, float _fM44)
	{
		// Row 0
		m_af[0][0] = _fM11;
		m_af[0][1] = _fM12;
		m_af[0][2] = _fM13;
		m_af[0][3] = _fM14;

		// Row 1
		m_af[1][0] = _fM21;
		m_af[1][1] = _fM22;
		m_af[1][2] = _fM23;
		m_af[1][3] = _fM24;

		// Row 2
		m_af[2][0] = _fM31;
		m_af[2][1] = _fM32;
		m_af[2][2] = _fM33;
		m_af[2][3] = _fM34;

		// Row 4
		m_af[3][0] = _fM41;
		m_af[3][1] = _fM42;
		m_af[3][2] = _fM43;
		m_af[3][3] = _fM44;
	}

	Matrix44::Matrix44(const Matrix33 &_mat, const Vector3& _v)
	{
		float fX = _v.GetX();
		float fY = _v.GetY();
		float fZ = _v.GetZ();

		// Column 0
		m_af[0][0] = _mat(0, 0);
		m_af[1][0] = _mat(1, 0);
		m_af[2][0] = _mat(2, 0);
		m_af[3][0] = 0.f;

		// Column 1
		m_af[0][1] = _mat(0, 1);
		m_af[1][1] = _mat(1, 1);
		m_af[2][1] = _mat(2, 1);
		m_af[3][1] = 0.f;

		// Column 2
		m_af[0][2] = _mat(0, 2);
		m_af[1][2] = _mat(1, 2);
		m_af[2][2] = _mat(2, 2);
		m_af[3][2] = 0.f;

		// Column 3
		m_af[0][3] = fX;
		m_af[1][3] = fY;
		m_af[2][3] = fZ;
		m_af[3][3] = 1.f;
	}


	// set/get
	void Matrix44::SetTranslation(Vector3& _v)
	{
		float fX = _v.GetX();
		float fY = _v.GetY();
		float fZ = _v.GetZ();

		*this = Matrix44(1.f, 0.f, 0.f, fX,
						 0.f, 1.f, 0.f, fY,
						 0.f, 0.f, 1.f, fZ,
						 0.f, 0.f, 0.f, 1.f);
	}

	void Matrix44::SetRotation(Matrix33& _m)
	{
		*this = Matrix44(_m(0, 0), _m(0, 1), _m(0, 2), 0.f,
						 _m(0, 0), _m(0, 1), _m(0, 2), 0.f,
						 _m(0, 0), _m(0, 1), _m(0, 2), 0.f,
						 0.f	 , 0.f	   , 0.f	 , 1.f);
	}

	void Matrix44::SetScale(Vector3& _v)
	{
		float fX = _v.GetX();
		float fY = _v.GetY();
		float fZ = _v.GetZ();

		*this = Matrix44(fX, 0.f, 0.f, 0.f,
						 0.f, fY, 0.f, 0.f,
						 0.f, 0.f, fZ, 0.f,
						 0.f, 0.f, 0.f, 1.f);
	}

	void Matrix44::SetIdentity()
	{
		*this = MATRIX44IDENTITY;
	}

	void Matrix44::SetZero()
	{
		*this = MATRIX44ZERO;
	}


	// assignment operators
	Matrix44& Matrix44::operator*= (const Matrix44 &_mat)
	{
		// Row 0
		m_af[0][0] = m_af[0][0] * _mat.m_af[0][0] + m_af[0][1] * _mat.m_af[1][0] + m_af[0][2] * _mat.m_af[2][0] + m_af[0][3] * _mat.m_af[3][0];
		m_af[0][1] = m_af[0][0] * _mat.m_af[0][1] + m_af[0][1] * _mat.m_af[1][1] + m_af[0][2] * _mat.m_af[2][1] + m_af[0][3] * _mat.m_af[3][1];
		m_af[0][2] = m_af[0][0] * _mat.m_af[0][2] + m_af[0][1] * _mat.m_af[1][2] + m_af[0][2] * _mat.m_af[2][2] + m_af[0][3] * _mat.m_af[3][2];
		m_af[0][3] = m_af[0][0] * _mat.m_af[0][3] + m_af[0][1] * _mat.m_af[1][3] + m_af[0][2] * _mat.m_af[2][3] + m_af[0][3] * _mat.m_af[3][3];

		// Row 1
		m_af[1][0] = m_af[1][0] * _mat.m_af[0][0] + m_af[1][1] * _mat.m_af[1][0] + m_af[1][2] * _mat.m_af[2][0] + m_af[1][3] * _mat.m_af[3][0];
		m_af[1][1] = m_af[1][0] * _mat.m_af[0][1] + m_af[1][1] * _mat.m_af[1][1] + m_af[1][2] * _mat.m_af[2][1] + m_af[1][3] * _mat.m_af[3][1];
		m_af[1][2] = m_af[1][0] * _mat.m_af[0][2] + m_af[1][1] * _mat.m_af[1][2] + m_af[1][2] * _mat.m_af[2][2] + m_af[1][3] * _mat.m_af[3][2];
		m_af[1][3] = m_af[1][0] * _mat.m_af[0][3] + m_af[1][1] * _mat.m_af[1][3] + m_af[1][2] * _mat.m_af[2][3] + m_af[1][3] * _mat.m_af[3][3];

		// Row 2
		m_af[2][0] = m_af[2][0] * _mat.m_af[0][0] + m_af[2][1] * _mat.m_af[1][0] + m_af[2][2] * _mat.m_af[2][0] + m_af[2][3] * _mat.m_af[3][0];
		m_af[2][1] = m_af[2][0] * _mat.m_af[0][1] + m_af[2][1] * _mat.m_af[1][1] + m_af[2][2] * _mat.m_af[2][1] + m_af[2][3] * _mat.m_af[3][1];
		m_af[2][2] = m_af[2][0] * _mat.m_af[0][2] + m_af[2][1] * _mat.m_af[1][2] + m_af[2][2] * _mat.m_af[2][2] + m_af[2][3] * _mat.m_af[3][2];
		m_af[2][3] = m_af[2][0] * _mat.m_af[0][3] + m_af[2][1] * _mat.m_af[1][3] + m_af[2][2] * _mat.m_af[2][3] + m_af[2][3] * _mat.m_af[3][3];

		// Row 4
		m_af[3][0] = m_af[3][0] * _mat.m_af[0][0] + m_af[3][1] * _mat.m_af[1][0] + m_af[3][2] * _mat.m_af[2][0] + m_af[3][3] * _mat.m_af[3][0];
		m_af[3][1] = m_af[3][0] * _mat.m_af[0][1] + m_af[3][1] * _mat.m_af[1][1] + m_af[3][2] * _mat.m_af[2][1] + m_af[3][3] * _mat.m_af[3][1];
		m_af[3][2] = m_af[3][0] * _mat.m_af[0][2] + m_af[3][1] * _mat.m_af[1][2] + m_af[3][2] * _mat.m_af[2][2] + m_af[3][3] * _mat.m_af[3][2];
		m_af[3][3] = m_af[3][0] * _mat.m_af[0][3] + m_af[3][1] * _mat.m_af[1][3] + m_af[3][2] * _mat.m_af[2][3] + m_af[3][3] * _mat.m_af[3][3];

		return *this;
	}

	Matrix44& Matrix44::operator+= (const Matrix44 &_mat)
	{
		// Row 0
		m_af[0][0] += _mat.m_af[0][0];
		m_af[0][1] += _mat.m_af[0][1];
		m_af[0][2] += _mat.m_af[0][2];
		m_af[0][3] += _mat.m_af[0][3];

		// Row 1
		m_af[1][0] += _mat.m_af[1][0];
		m_af[1][1] += _mat.m_af[1][1];
		m_af[1][2] += _mat.m_af[1][2];
		m_af[1][3] += _mat.m_af[1][3];

		// Row 2
		m_af[2][0] += _mat.m_af[2][0];
		m_af[2][1] += _mat.m_af[2][1];
		m_af[2][2] += _mat.m_af[2][2];
		m_af[2][3] += _mat.m_af[2][3];

		// Row 4
		m_af[3][0] += _mat.m_af[3][0];
		m_af[3][1] += _mat.m_af[3][1];
		m_af[3][2] += _mat.m_af[3][2];
		m_af[3][3] += _mat.m_af[3][3];

		return *this;
	}

	Matrix44& Matrix44::operator-= (const Matrix44 &_mat)
	{
		// Row 0
		m_af[0][0] -= _mat.m_af[0][0];
		m_af[0][1] -= _mat.m_af[0][1];
		m_af[0][2] -= _mat.m_af[0][2];
		m_af[0][3] -= _mat.m_af[0][3];

		// Row 1
		m_af[1][0] -= _mat.m_af[1][0];
		m_af[1][1] -= _mat.m_af[1][1];
		m_af[1][2] -= _mat.m_af[1][2];
		m_af[1][3] -= _mat.m_af[1][3];

		// Row 2
		m_af[2][0] -= _mat.m_af[2][0];
		m_af[2][1] -= _mat.m_af[2][1];
		m_af[2][2] -= _mat.m_af[2][2];
		m_af[2][3] -= _mat.m_af[2][3];

		// Row 4
		m_af[3][0] -= _mat.m_af[3][0];
		m_af[3][1] -= _mat.m_af[3][1];
		m_af[3][2] -= _mat.m_af[3][2];
		m_af[3][3] -= _mat.m_af[3][3];

		return *this;
	}

	Matrix44& Matrix44::operator*= (float _f)
	{
		// Row 0
		m_af[0][0] *= _f;
		m_af[0][1] *= _f;
		m_af[0][2] *= _f;
		m_af[0][3] *= _f;

		// Row 1
		m_af[1][0] *= _f;
		m_af[1][1] *= _f;
		m_af[1][2] *= _f;
		m_af[1][3] *= _f;

		// Row 2
		m_af[2][0] *= _f;
		m_af[2][1] *= _f;
		m_af[2][2] *= _f;
		m_af[2][3] *= _f;

		// Row 3
		m_af[3][0] *= _f;
		m_af[3][1] *= _f;
		m_af[3][2] *= _f;
		m_af[3][3] *= _f;


		return *this;
	}

	Matrix44& Matrix44::operator/= (float _f)
	{
		// Row 0
		m_af[0][0] /= _f;
		m_af[0][1] /= _f;
		m_af[0][2] /= _f;
		m_af[0][3] /= _f;

		// Row 1
		m_af[1][0] /= _f;
		m_af[1][1] /= _f;
		m_af[1][2] /= _f;
		m_af[1][3] /= _f;

		// Row 2
		m_af[2][0] /= _f;
		m_af[2][1] /= _f;
		m_af[2][2] /= _f;
		m_af[2][3] /= _f;

		// Row 3
		m_af[3][0] /= _f;
		m_af[3][1] /= _f;
		m_af[3][2] /= _f;
		m_af[3][3] /= _f;


		return *this;
	}


	// unary operators
	Matrix44 Matrix44::operator+ () const
	{
		Matrix44 result;

		// Row 0
		result.m_af[0][0] = abs(m_af[0][0]);
		result.m_af[0][1] = abs(m_af[0][1]);
		result.m_af[0][2] = abs(m_af[0][2]);
		result.m_af[0][3] = abs(m_af[0][3]);

		// Row 1
		result.m_af[1][0] = abs(m_af[1][0]);
		result.m_af[1][1] = abs(m_af[1][1]);
		result.m_af[1][2] = abs(m_af[1][2]);
		result.m_af[1][3] = abs(m_af[1][3]);

		// Row 2
		result.m_af[2][0] = abs(m_af[2][0]);
		result.m_af[2][1] = abs(m_af[2][1]);
		result.m_af[2][2] = abs(m_af[2][2]);
		result.m_af[2][3] = abs(m_af[2][3]);

		// Row 4
		result.m_af[3][0] = abs(m_af[3][0]);
		result.m_af[3][1] = abs(m_af[3][1]);
		result.m_af[3][2] = abs(m_af[3][2]);
		result.m_af[3][3] = abs(m_af[3][3]);

		return result;
	}

	Matrix44 Matrix44::operator- () const
	{
		Matrix44 result;

		// Row 0
		result.m_af[0][0] = -m_af[0][0];
		result.m_af[0][1] = -m_af[0][1];
		result.m_af[0][2] = -m_af[0][2];
		result.m_af[0][3] = -m_af[0][3];

		// Row 1
		result.m_af[1][0] = -m_af[1][0];
		result.m_af[1][1] = -m_af[1][1];
		result.m_af[1][2] = -m_af[1][2];
		result.m_af[1][3] = -m_af[1][3];

		// Row 2
		result.m_af[2][0] = -m_af[2][0];
		result.m_af[2][1] = -m_af[2][1];
		result.m_af[2][2] = -m_af[2][2];
		result.m_af[2][3] = -m_af[2][3];

		// Row 4
		result.m_af[3][0] = -m_af[3][0];
		result.m_af[3][1] = -m_af[3][1];
		result.m_af[3][2] = -m_af[3][2];
		result.m_af[3][3] = -m_af[3][3];

		return result;
	}


	// binary operators
	Matrix44 Matrix44::operator* (const Matrix44 &_mat) const
	{
		Matrix44 result;

		// Row 0
		result.m_af[0][0] = m_af[0][0] * _mat.m_af[0][0] + m_af[0][1] * _mat.m_af[1][0] + m_af[0][2] * _mat.m_af[2][0] + m_af[0][3] * _mat.m_af[3][0];
		result.m_af[0][1] = m_af[0][0] * _mat.m_af[0][1] + m_af[0][1] * _mat.m_af[1][1] + m_af[0][2] * _mat.m_af[2][1] + m_af[0][3] * _mat.m_af[3][1];
		result.m_af[0][2] = m_af[0][0] * _mat.m_af[0][2] + m_af[0][1] * _mat.m_af[1][2] + m_af[0][2] * _mat.m_af[2][2] + m_af[0][3] * _mat.m_af[3][2];
		result.m_af[0][3] = m_af[0][0] * _mat.m_af[0][3] + m_af[0][1] * _mat.m_af[1][3] + m_af[0][2] * _mat.m_af[2][3] + m_af[0][3] * _mat.m_af[3][3];

		// Row 1
		result.m_af[1][0] = m_af[1][0] * _mat.m_af[0][0] + m_af[1][1] * _mat.m_af[1][0] + m_af[1][2] * _mat.m_af[2][0] + m_af[1][3] * _mat.m_af[3][0];
		result.m_af[1][1] = m_af[1][0] * _mat.m_af[0][1] + m_af[1][1] * _mat.m_af[1][1] + m_af[1][2] * _mat.m_af[2][1] + m_af[1][3] * _mat.m_af[3][1];
		result.m_af[1][2] = m_af[1][0] * _mat.m_af[0][2] + m_af[1][1] * _mat.m_af[1][2] + m_af[1][2] * _mat.m_af[2][2] + m_af[1][3] * _mat.m_af[3][2];
		result.m_af[1][3] = m_af[1][0] * _mat.m_af[0][3] + m_af[1][1] * _mat.m_af[1][3] + m_af[1][2] * _mat.m_af[2][3] + m_af[1][3] * _mat.m_af[3][3];

		// Row 2
		result.m_af[2][0] = m_af[2][0] * _mat.m_af[0][0] + m_af[2][1] * _mat.m_af[1][0] + m_af[2][2] * _mat.m_af[2][0] + m_af[2][3] * _mat.m_af[3][0];
		result.m_af[2][1] = m_af[2][0] * _mat.m_af[0][1] + m_af[2][1] * _mat.m_af[1][1] + m_af[2][2] * _mat.m_af[2][1] + m_af[2][3] * _mat.m_af[3][1];
		result.m_af[2][2] = m_af[2][0] * _mat.m_af[0][2] + m_af[2][1] * _mat.m_af[1][2] + m_af[2][2] * _mat.m_af[2][2] + m_af[2][3] * _mat.m_af[3][2];
		result.m_af[2][3] = m_af[2][0] * _mat.m_af[0][3] + m_af[2][1] * _mat.m_af[1][3] + m_af[2][2] * _mat.m_af[2][3] + m_af[2][3] * _mat.m_af[3][3];

		// Row 4
		result.m_af[3][0] = m_af[3][0] * _mat.m_af[0][0] + m_af[3][1] * _mat.m_af[1][0] + m_af[3][2] * _mat.m_af[2][0] + m_af[3][3] * _mat.m_af[3][0];
		result.m_af[3][1] = m_af[3][0] * _mat.m_af[0][1] + m_af[3][1] * _mat.m_af[1][1] + m_af[3][2] * _mat.m_af[2][1] + m_af[3][3] * _mat.m_af[3][1];
		result.m_af[3][2] = m_af[3][0] * _mat.m_af[0][2] + m_af[3][1] * _mat.m_af[1][2] + m_af[3][2] * _mat.m_af[2][2] + m_af[3][3] * _mat.m_af[3][2];
		result.m_af[3][3] = m_af[3][0] * _mat.m_af[0][3] + m_af[3][1] * _mat.m_af[1][3] + m_af[3][2] * _mat.m_af[2][3] + m_af[3][3] * _mat.m_af[3][3];

		return result;
	}

	Matrix44 Matrix44::operator+ (const Matrix44 &_mat) const
	{
		Matrix44 result;

		// Row 0
		result.m_af[0][0] = m_af[0][0] + _mat.m_af[0][0];
		result.m_af[0][1] = m_af[0][1] + _mat.m_af[0][1];
		result.m_af[0][2] = m_af[0][2] + _mat.m_af[0][2];
		result.m_af[0][3] = m_af[0][3] + _mat.m_af[0][3];

		// Row 1
		result.m_af[1][0] = m_af[1][0] + _mat.m_af[1][0];
		result.m_af[1][1] = m_af[1][1] + _mat.m_af[1][1];
		result.m_af[1][2] = m_af[1][2] + _mat.m_af[1][2];
		result.m_af[1][3] = m_af[1][3] + _mat.m_af[1][3];

		// Row 2
		result.m_af[2][0] = m_af[2][0] + _mat.m_af[2][0];
		result.m_af[2][1] = m_af[2][1] + _mat.m_af[2][1];
		result.m_af[2][2] = m_af[2][2] + _mat.m_af[2][2];
		result.m_af[2][3] = m_af[2][3] + _mat.m_af[2][3];

		// Row 4
		result.m_af[3][0] = m_af[3][0] + _mat.m_af[3][0];
		result.m_af[3][1] = m_af[3][1] + _mat.m_af[3][1];
		result.m_af[3][2] = m_af[3][2] + _mat.m_af[3][2];
		result.m_af[3][3] = m_af[3][3] + _mat.m_af[3][3];

		return result;
	}

	Matrix44 Matrix44::operator- (const Matrix44 &_mat) const
	{
		Matrix44 result;

		// Row 0
		result.m_af[0][0] = m_af[0][0] - _mat.m_af[0][0];
		result.m_af[0][1] = m_af[0][1] - _mat.m_af[0][1];
		result.m_af[0][2] = m_af[0][2] - _mat.m_af[0][2];
		result.m_af[0][3] = m_af[0][3] - _mat.m_af[0][3];

		// Row 1
		result.m_af[1][0] = m_af[1][0] - _mat.m_af[1][0];
		result.m_af[1][1] = m_af[1][1] - _mat.m_af[1][1];
		result.m_af[1][2] = m_af[1][2] - _mat.m_af[1][2];
		result.m_af[1][3] = m_af[1][3] - _mat.m_af[1][3];

		// Row 2
		result.m_af[2][0] = m_af[2][0] - _mat.m_af[2][0];
		result.m_af[2][1] = m_af[2][1] - _mat.m_af[2][1];
		result.m_af[2][2] = m_af[2][2] - _mat.m_af[2][2];
		result.m_af[2][3] = m_af[2][3] - _mat.m_af[2][3];

		// Row 4
		result.m_af[3][0] = m_af[3][0] - _mat.m_af[3][0];
		result.m_af[3][1] = m_af[3][1] - _mat.m_af[3][1];
		result.m_af[3][2] = m_af[3][2] - _mat.m_af[3][2];
		result.m_af[3][3] = m_af[3][3] - _mat.m_af[3][3];

		return result;
	}

	Matrix44 Matrix44::operator* (float _f) const
	{
		Matrix44 result;

		// Row 0
		result.m_af[0][0] = m_af[0][0] * _f;
		result.m_af[0][1] = m_af[0][1] * _f;
		result.m_af[0][2] = m_af[0][2] * _f;
		result.m_af[0][3] = m_af[0][3] * _f;

		// Row 1
		result.m_af[1][0] = m_af[1][0] * _f;
		result.m_af[1][1] = m_af[1][1] * _f;
		result.m_af[1][2] = m_af[1][2] * _f;
		result.m_af[1][3] = m_af[1][3] * _f;

		// Row 2
		result.m_af[2][0] = m_af[2][0] * _f;
		result.m_af[2][1] = m_af[2][1] * _f;
		result.m_af[2][2] = m_af[2][2] * _f;
		result.m_af[2][3] = m_af[2][3] * _f;

		// Row 3
		result.m_af[3][0] = m_af[3][0] * _f;
		result.m_af[3][1] = m_af[3][1] * _f;
		result.m_af[3][2] = m_af[3][2] * _f;
		result.m_af[3][3] = m_af[3][3] * _f;


		return result;
	}

	Matrix44 Matrix44::operator/ (float _f) const
	{
		Matrix44 result;

		// Row 0
		result.m_af[0][0] = m_af[0][0] / _f;
		result.m_af[0][1] = m_af[0][1] / _f;
		result.m_af[0][2] = m_af[0][2] / _f;
		result.m_af[0][3] = m_af[0][3] / _f;

		// Row 1
		result.m_af[1][0] = m_af[1][0] / _f;
		result.m_af[1][1] = m_af[1][1] / _f;
		result.m_af[1][2] = m_af[1][2] / _f;
		result.m_af[1][3] = m_af[1][3] / _f;

		// Row 2
		result.m_af[2][0] = m_af[2][0] / _f;
		result.m_af[2][1] = m_af[2][1] / _f;
		result.m_af[2][2] = m_af[2][2] / _f;
		result.m_af[2][3] = m_af[2][3] / _f;

		// Row 3
		result.m_af[3][0] = m_af[3][0] / _f;
		result.m_af[3][1] = m_af[3][1] / _f;
		result.m_af[3][2] = m_af[3][2] / _f;
		result.m_af[3][3] = m_af[3][3] / _f;


		return result;
	}


	// Comparison operators
	bool Matrix44::operator== (const Matrix44 &_mat) const
	{
		return (m_af[0][0] == _mat.m_af[0][0] && m_af[0][1] == _mat.m_af[0][1] && m_af[0][2] == _mat.m_af[0][2] && m_af[0][3] == _mat.m_af[0][3]		// Row 0
			&& m_af[1][0] == _mat.m_af[1][0] && m_af[1][1] == _mat.m_af[1][1] && m_af[1][2] == _mat.m_af[1][2] && m_af[1][3] == _mat.m_af[1][3]		// Row 1
			&& m_af[2][0] == _mat.m_af[2][0] && m_af[2][1] == _mat.m_af[2][1] && m_af[2][2] == _mat.m_af[2][2] && m_af[2][3] == _mat.m_af[2][3]		// Row 2
			&& m_af[3][0] == _mat.m_af[3][0] && m_af[3][1] == _mat.m_af[3][1] && m_af[3][2] == _mat.m_af[3][2] && m_af[3][3] == _mat.m_af[3][3]);	// Row 3
	}

	bool Matrix44::operator!= (const Matrix44 &_mat) const
	{
		return !(m_af[0][0] == _mat.m_af[0][0] && m_af[0][1] == _mat.m_af[0][1] && m_af[0][2] == _mat.m_af[0][2] && m_af[0][3] == _mat.m_af[0][3]		// Row 0
			&& m_af[1][0] == _mat.m_af[1][0] && m_af[1][1] == _mat.m_af[1][1] && m_af[1][2] == _mat.m_af[1][2] && m_af[1][3] == _mat.m_af[1][3]		// Row 1
			&& m_af[2][0] == _mat.m_af[2][0] && m_af[2][1] == _mat.m_af[2][1] && m_af[2][2] == _mat.m_af[2][2] && m_af[2][3] == _mat.m_af[2][3]		// Row 2
			&& m_af[3][0] == _mat.m_af[3][0] && m_af[3][1] == _mat.m_af[3][1] && m_af[3][2] == _mat.m_af[3][2] && m_af[3][3] == _mat.m_af[3][3]);		// Row 3
	}

	Vector4 Matrix44::operator* (const Vector4& _v)
	{
		Vector4 result;

		float fX = _v.GetX();
		float fY = _v.GetY();
		float fZ = _v.GetZ();
		float fW = _v.GetW();

		result.SetX(m_af[0][0] * fX + m_af[0][1] * fY + m_af[0][2] * fZ + m_af[0][3] * fW);
		result.SetY(m_af[1][0] * fX + m_af[1][1] * fY + m_af[1][2] * fZ + m_af[1][3] * fW);
		result.SetZ(m_af[2][0] * fX + m_af[2][1] * fY + m_af[2][2] * fZ + m_af[2][3] * fW);
		result.SetW(m_af[3][0] * fX + m_af[3][1] * fY + m_af[3][2] * fZ + m_af[3][3] * fW);

		return result;
	}


	// accessor
	float& Matrix44::operator () (int _iRow, int _iCol)
	{
		return m_af[_iRow][_iCol];
	}

	float Matrix44::operator () (int _iRow, int _iCol) const
	{
		return m_af[_iRow][_iCol];
	}


	// matrix operation
	void Matrix44::Transpose()
	{
		Matrix44 tempMat44 = *this;

		// Swap Row 0 & Column 0
		m_af[0][1] = tempMat44.m_af[1][0];
		m_af[0][2] = tempMat44.m_af[2][0];
		m_af[0][3] = tempMat44.m_af[3][0];

		// Swap Row 1 & Column 1
		m_af[1][0] = tempMat44.m_af[0][1];
		m_af[1][2] = tempMat44.m_af[2][1];
		m_af[1][3] = tempMat44.m_af[3][1];

		// Swap Row 2 & Column 2
		m_af[2][0] = tempMat44.m_af[0][2];
		m_af[2][1] = tempMat44.m_af[1][2];
		m_af[2][3] = tempMat44.m_af[3][2];

		// Swamp Row 3 & Column 3
		m_af[3][0] = tempMat44.m_af[0][3];
		m_af[3][1] = tempMat44.m_af[1][3];
		m_af[3][2] = tempMat44.m_af[2][3];
	}

	bool Matrix44::Inverse()
	{
		float fDeterminant = 0.f;
		float fCofactor00 = ( m_af[1][1] * (m_af[2][2] * m_af[3][3] - m_af[2][3] * m_af[3][2])
							- m_af[1][2] * (m_af[2][1] * m_af[3][3] - m_af[2][3] * m_af[3][1])
							+ m_af[1][3] * (m_af[2][1] * m_af[3][2] - m_af[2][2] * m_af[3][1]));

		float fCofactor01 = -(m_af[1][0] * (m_af[2][2] * m_af[3][3] - m_af[2][3] * m_af[3][2])
							- m_af[1][2] * (m_af[2][0] * m_af[3][3] - m_af[2][3] * m_af[3][0])
							+ m_af[1][3] * (m_af[2][0] * m_af[3][2] - m_af[2][2] * m_af[3][0]));

		float fCofactor02 = ( m_af[1][0] * (m_af[2][1] * m_af[3][3] - m_af[2][3] * m_af[3][1])
							- m_af[1][1] * (m_af[2][0] * m_af[3][3] - m_af[2][3] * m_af[3][0])
							+ m_af[1][3] * (m_af[2][0] * m_af[3][1] - m_af[2][1] * m_af[3][0]));

		float fCofactor03 = -(m_af[1][0] * (m_af[2][1] * m_af[3][2] - m_af[2][2] * m_af[3][1])
							- m_af[1][1] * (m_af[2][0] * m_af[3][2] - m_af[2][2] * m_af[3][0])
							+ m_af[1][2] * (m_af[2][0] * m_af[3][1] - m_af[2][1] * m_af[3][0]));

		fDeterminant = m_af[0][0] * fCofactor00 + m_af[0][1] * fCofactor01 + m_af[0][2] * fCofactor02 + m_af[0][3] * fCofactor03;


		if (fDeterminant != 0.f)
		{
			Matrix44 cofactorMatrix;

			// Compute cofactors matrix

			// Row 0
			cofactorMatrix.m_af[0][0] = fCofactor00;
			cofactorMatrix.m_af[0][1] = fCofactor01;
			cofactorMatrix.m_af[0][2] = fCofactor02;
			cofactorMatrix.m_af[0][3] = fCofactor03;

			// Row 1
			cofactorMatrix.m_af[1][0] = -(m_af[0][1] * (m_af[2][2] * m_af[3][3] - m_af[2][3] * m_af[3][2])
										- m_af[0][2] * (m_af[2][1] * m_af[3][3] - m_af[2][3] * m_af[3][1])
										+ m_af[0][3] * (m_af[2][1] * m_af[3][2] - m_af[2][2] * m_af[3][1]));
			cofactorMatrix.m_af[1][1] = ( m_af[0][0] * (m_af[2][2] * m_af[3][3] - m_af[2][3] * m_af[3][2])
										- m_af[0][2] * (m_af[2][0] * m_af[3][3] - m_af[2][3] * m_af[3][0])
										+ m_af[0][3] * (m_af[2][0] * m_af[3][2] - m_af[2][2] * m_af[3][0]));
			cofactorMatrix.m_af[1][2] = -(m_af[0][0] * (m_af[2][1] * m_af[3][3] - m_af[2][3] * m_af[3][1])
										- m_af[0][1] * (m_af[2][0] * m_af[3][3] - m_af[2][3] * m_af[3][0])
										+ m_af[0][3] * (m_af[2][0] * m_af[3][1] - m_af[2][1] * m_af[3][0]));
			cofactorMatrix.m_af[1][3] = ( m_af[0][0] * (m_af[2][1] * m_af[3][2] - m_af[2][2] * m_af[3][1])
										- m_af[0][1] * (m_af[2][0] * m_af[3][2] - m_af[2][2] * m_af[3][0])
										+ m_af[0][2] * (m_af[2][0] * m_af[3][1] - m_af[2][1] * m_af[3][0]));
			
			// Row 2
			cofactorMatrix.m_af[2][0] = ( m_af[0][1] * (m_af[1][2] * m_af[3][3] - m_af[1][3] * m_af[3][2])
										- m_af[0][2] * (m_af[1][1] * m_af[3][3] - m_af[1][3] * m_af[3][1])
										+ m_af[0][3] * (m_af[1][1] * m_af[3][2] - m_af[1][2] * m_af[3][1]));
			cofactorMatrix.m_af[2][1] = -(m_af[0][0] * (m_af[1][2] * m_af[3][3] - m_af[1][3] * m_af[3][2])
										- m_af[0][2] * (m_af[1][0] * m_af[3][3] - m_af[1][3] * m_af[3][0])
										+ m_af[0][3] * (m_af[1][0] * m_af[3][2] - m_af[1][2] * m_af[3][0]));
			cofactorMatrix.m_af[2][2] = ( m_af[0][0] * (m_af[1][1] * m_af[3][3] - m_af[1][3] * m_af[3][1])
										- m_af[0][1] * (m_af[1][0] * m_af[3][3] - m_af[1][3] * m_af[3][0])
										+ m_af[0][3] * (m_af[1][0] * m_af[3][1] - m_af[1][1] * m_af[3][0]));
			cofactorMatrix.m_af[2][3] = -(m_af[0][0] * (m_af[1][1] * m_af[3][2] - m_af[1][2] * m_af[3][1])
										- m_af[0][1] * (m_af[1][0] * m_af[3][2] - m_af[1][2] * m_af[3][0])
										+ m_af[0][2] * (m_af[1][0] * m_af[3][1] - m_af[1][1] * m_af[3][0]));

			// Row 3
			cofactorMatrix.m_af[3][0] = -(m_af[0][1] * (m_af[1][2] * m_af[2][3] - m_af[1][3] * m_af[2][2])
										- m_af[0][2] * (m_af[1][1] * m_af[2][3] - m_af[1][3] * m_af[2][1])
										+ m_af[0][3] * (m_af[1][1] * m_af[2][2] - m_af[1][2] * m_af[2][1]));
			cofactorMatrix.m_af[3][1] = ( m_af[0][0] * (m_af[1][2] * m_af[2][3] - m_af[1][3] * m_af[2][2])
										- m_af[0][2] * (m_af[1][0] * m_af[2][3] - m_af[1][3] * m_af[2][0])
										+ m_af[0][3] * (m_af[1][0] * m_af[2][2] - m_af[1][2] * m_af[2][0]));
			cofactorMatrix.m_af[3][2] = -(m_af[0][0] * (m_af[1][1] * m_af[2][3] - m_af[1][3] * m_af[2][1])
										- m_af[0][1] * (m_af[1][0] * m_af[2][3] - m_af[1][3] * m_af[2][0])
										+ m_af[0][3] * (m_af[1][0] * m_af[2][1] - m_af[1][1] * m_af[2][0]));
			cofactorMatrix.m_af[3][3] = ( m_af[0][0] * (m_af[1][1] * m_af[2][2] - m_af[1][2] * m_af[2][1])
										- m_af[0][1] * (m_af[1][0] * m_af[2][2] - m_af[1][2] * m_af[2][0])
										+ m_af[0][2] * (m_af[1][0] * m_af[2][1] - m_af[1][1] * m_af[2][0]));

			cofactorMatrix.Transpose();

			// Compute inverse matrix
			*this = (1.f / fDeterminant) * cofactorMatrix;

			return EXIT_SUCCESS;
		}

		return EXIT_FAILURE;
	}


	// DADENGINE_MATHAPI friend function
	Vector4 operator* (const Vector4& _v, const Matrix44 &_mat)
	{
		Vector4 result;
		float fX = _v.GetX();
		float fY = _v.GetY();
		float fZ = _v.GetZ();
		float fW = _v.GetW();

		result.SetX(_mat.m_af[0][0] * fX + _mat.m_af[0][1] * fY + _mat.m_af[0][2] * fZ + _mat.m_af[0][3] * fW);
		result.SetY(_mat.m_af[1][0] * fX + _mat.m_af[1][1] * fY + _mat.m_af[1][2] * fZ + _mat.m_af[1][3] * fW);
		result.SetZ(_mat.m_af[2][0] * fX + _mat.m_af[2][1] * fY + _mat.m_af[2][2] * fZ + _mat.m_af[2][3] * fW);
		result.SetW(_mat.m_af[3][0] * fX + _mat.m_af[3][1] * fY + _mat.m_af[3][2] * fZ + _mat.m_af[3][3] * fW);

		return result;
	}

	Matrix44 operator* (float _f, const Matrix44 &_mat)
	{
		Matrix44 result;

		// Row 0
		result.m_af[0][0] = _mat.m_af[0][0] * _f;
		result.m_af[0][1] = _mat.m_af[0][1] * _f;
		result.m_af[0][2] = _mat.m_af[0][2] * _f;
		result.m_af[0][3] = _mat.m_af[0][3] * _f;

		// Row 1
		result.m_af[1][0] = _mat.m_af[1][0] * _f;
		result.m_af[1][1] = _mat.m_af[1][1] * _f;
		result.m_af[1][2] = _mat.m_af[1][2] * _f;
		result.m_af[1][3] = _mat.m_af[1][3] * _f;

		// Row 2
		result.m_af[2][0] = _mat.m_af[2][0] * _f;
		result.m_af[2][1] = _mat.m_af[2][1] * _f;
		result.m_af[2][2] = _mat.m_af[2][2] * _f;
		result.m_af[2][3] = _mat.m_af[2][3] * _f;

		// Row 3
		result.m_af[3][0] = _mat.m_af[3][0] * _f;
		result.m_af[3][1] = _mat.m_af[3][1] * _f;
		result.m_af[3][2] = _mat.m_af[3][2] * _f;
		result.m_af[3][3] = _mat.m_af[3][3] * _f;


		return result;
	}


	// debug function
	ostream &operator<< (ostream& _out, const Matrix44 &_v)
	{
		// Row 0
		_out << "La valeur du composant 11 de la matrice est " << _v.m_af[0][0] << endl << endl;
		_out << "La valeur du composant 12 de la matrice est " << _v.m_af[0][1] << endl << endl;
		_out << "La valeur du composant 13 de la matrice est " << _v.m_af[0][2] << endl << endl;
		_out << "La valeur du composant 14 de la matrice est " << _v.m_af[0][3] << endl << endl;

		// Row 1
		_out << "La valeur du composant 21 de la matrice est " << _v.m_af[1][0] << endl << endl;
		_out << "La valeur du composant 22 de la matrice est " << _v.m_af[1][1] << endl << endl;
		_out << "La valeur du composant 23 de la matrice est " << _v.m_af[1][2] << endl << endl;
		_out << "La valeur du composant 24 de la matrice est " << _v.m_af[1][3] << endl << endl;

		// Row 2
		_out << "La valeur du composant 31 de la matrice est " << _v.m_af[2][0] << endl << endl;
		_out << "La valeur du composant 32 de la matrice est " << _v.m_af[2][1] << endl << endl;
		_out << "La valeur du composant 33 de la matrice est " << _v.m_af[2][2] << endl << endl;
		_out << "La valeur du composant 34 de la matrice est " << _v.m_af[2][3] << endl << endl;

		// Row 3
		_out << "La valeur du composant 41 de la matrice est " << _v.m_af[3][0] << endl << endl;
		_out << "La valeur du composant 42 de la matrice est " << _v.m_af[3][1] << endl << endl;
		_out << "La valeur du composant 43 de la matrice est " << _v.m_af[3][2] << endl << endl;
		_out << "La valeur du composant 44 de la matrice est " << _v.m_af[3][3] << endl << endl;

		return _out;
	}

	istream &operator>> (istream& _in, Matrix44 &_v)
	{
		// Row 0
		cout << "Entrez une valeur pour le composant 11 de la matrice :" << endl << endl;
		_in.clear();
		_in.sync();
		_in >> _v.m_af[0][0];

		cout << "Entrez une valeur pour le composant 12 de la matrice :" << endl << endl;
		_in.clear();
		_in.sync();
		_in >> _v.m_af[0][1];

		cout << "Entrez une valeur pour le composant 13 de la matrice :" << endl << endl;
		_in.clear();
		_in.sync();
		_in >> _v.m_af[0][2];

		cout << "Entrez une valeur pour le composant 14 de la matrice :" << endl << endl;
		_in.clear();
		_in.sync();
		_in >> _v.m_af[0][3];


		// Row 1
		cout << "Entrez une valeur pour le composant 21 de la matrice :" << endl << endl;
		_in.clear();
		_in.sync();
		_in >> _v.m_af[1][0];

		cout << "Entrez une valeur pour le composant 22 de la matrice :" << endl << endl;
		_in.clear();
		_in.sync();
		_in >> _v.m_af[1][1];

		cout << "Entrez une valeur pour le composant 23 de la matrice :" << endl << endl;
		_in.clear();
		_in.sync();
		_in >> _v.m_af[1][2];

		cout << "Entrez une valeur pour le composant 24 de la matrice :" << endl << endl;
		_in.clear();
		_in.sync();
		_in >> _v.m_af[1][3];


		// Row 2
		cout << "Entrez une valeur pour le composant 31 de la matrice :" << endl << endl;
		_in.clear();
		_in.sync();
		_in >> _v.m_af[2][0];

		cout << "Entrez une valeur pour le composant 32 de la matrice :" << endl << endl;
		_in.clear();
		_in.sync();
		_in >> _v.m_af[2][1];

		cout << "Entrez une valeur pour le composant 33 de la matrice :" << endl << endl;
		_in.clear();
		_in.sync();
		_in >> _v.m_af[2][2];

		cout << "Entrez une valeur pour le composant 34 de la matrice :" << endl << endl;
		_in.clear();
		_in.sync();
		_in >> _v.m_af[2][3];


		// Row 3
		cout << "Entrez une valeur pour le composant 41 de la matrice :" << endl << endl;
		_in.clear();
		_in.sync();
		_in >> _v.m_af[3][0];

		cout << "Entrez une valeur pour le composant 42 de la matrice :" << endl << endl;
		_in.clear();
		_in.sync();
		_in >> _v.m_af[3][1];

		cout << "Entrez une valeur pour le composant 43 de la matrice :" << endl << endl;
		_in.clear();
		_in.sync();
		_in >> _v.m_af[3][2];

		cout << "Entrez une valeur pour le composant 44 de la matrice :" << endl << endl;
		_in.clear();
		_in.sync();
		_in >> _v.m_af[3][3];

		return _in;
	}

	void Matrix44::Display() const
	{
		cout << "Ligne 1 :" << endl;
		cout << m_af[0][0] << "\t" << m_af[0][1] << "\t" << m_af[0][2] << "\t" << m_af[0][3] << endl << endl;

		cout << "Ligne 2 :" << endl;
		cout << m_af[1][0] << "\t" << m_af[1][1] << "\t" << m_af[0][2] << "\t" << m_af[1][3] << endl << endl;

		cout << "Ligne 3 :" << endl;
		cout << m_af[2][0] << "\t" << m_af[2][1] << "\t" << m_af[2][2] << "\t" << m_af[2][3] << endl << endl;

		cout << "Ligne 4 :" << endl;
		cout << m_af[3][0] << "\t" << m_af[3][1] << "\t" << m_af[3][2] << "\t" << m_af[3][3] << endl << endl;
	}
}