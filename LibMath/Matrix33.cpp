/*Documentation															*/
/*@author	:	Quentin Ladevie											*/
/*@file		:	Matrix33.hpp											*/
/*@date		:	03/12/2015												*/
/*@brief	:	Fichier source des matrices carré de dimension 3		*/
#include "stdafx.h"
#include "Matrix33.hpp"
#include "Vector3.hpp"


namespace DadEngine
{
	// constructor and destructor
	Matrix33::Matrix33()
	{
		*this = MATRIX33ZERO;
	}

	Matrix33::Matrix33(float _afM[9])
	{
		// Row 0
		m_af[0][0] = _afM[0];
		m_af[0][1] = _afM[1];
		m_af[0][2] = _afM[2];

		// Row 1
		m_af[1][0] = _afM[3];
		m_af[1][1] = _afM[4];
		m_af[1][2] = _afM[5];

		// Row 2
		m_af[2][0] = _afM[6];
		m_af[2][1] = _afM[7];
		m_af[2][2] = _afM[8];
	}

	Matrix33::Matrix33( float _fM11, float _fM12, float _fM13,
						float _fM21, float _fM22, float _fM23,
						float _fM31, float _fM32, float _fM33)
	{
		// Row 0
		m_af[0][0] = _fM11;
		m_af[0][1] = _fM12;
		m_af[0][2] = _fM13;

		// Row 1
		m_af[1][0] = _fM21;
		m_af[1][1] = _fM22;
		m_af[1][2] = _fM23;

		// Row 2
		m_af[2][0] = _fM31;
		m_af[2][1] = _fM32;
		m_af[2][2] = _fM33;
	}

	Matrix33::Matrix33(const Vector3& _v1, const Vector3& _v2, const Vector3& _v3)
	{
		// Column 0
		m_af[0][0] = _v1.GetX();
		m_af[1][0] = _v1.GetY();
		m_af[2][0] = _v1.GetZ();

		// Column 1
		m_af[0][1] = _v2.GetX();
		m_af[1][1] = _v2.GetY();
		m_af[2][1] = _v2.GetZ();

		// Column 2
		m_af[0][2] = _v3.GetX();
		m_af[1][2] = _v3.GetY();
		m_af[2][2] = _v3.GetZ();
	}


	// set/get
	void Matrix33::SetTranslation(float _fX, float _fY)
	{
		*this = Matrix33(1.f, 0.f, _fX,
			0.f, 1.f, _fY,
			0.f, 0.f, 1.f);
	}

	void Matrix33::SetRotation(float _fAngle, Vector3& _axe)
	{
		float fCos = cos(_fAngle);
		float fSin = sin(_fAngle);

		float fAxeX = _axe.GetX();
		float fAxeY = _axe.GetY();
		float fAxeZ = _axe.GetZ();

		*this = Matrix33(fCos + (1 - fCos) * fAxeX * fAxeX, (1 - fCos) * fAxeX * fAxeY - (fSin * fAxeZ), (1 - fCos) * fAxeX * fAxeZ + fSin * fAxeY,
						(1 - fCos) * fAxeX * fAxeY + (fSin * fAxeZ), fCos + (1 - fCos) * fAxeY * fAxeY, (1 - fCos) * fAxeY * fAxeZ - (fSin * fAxeX),
						(1 - fCos) * fAxeX * fAxeZ - fSin * fAxeY, (1 - fCos) * fAxeY * fAxeZ + (fSin * fAxeX), fCos + (1 - fCos) * fAxeZ * fAxeZ);
	}

	void Matrix33::SetRotationX(float _fAngle)								// in radians
	{
		float fCos = cos(_fAngle);
		float fSin = sin(_fAngle);

		*this = Matrix33(1.f,  0.f,	 0.f,
						 0.f,  fCos, fSin,
						 0.f, -fSin, fCos);
	}

	void Matrix33::SetRotationY(float _fAngle)								// in radians
	{
		float fCos = cos(_fAngle);
		float fSin = sin(_fAngle);

		*this = Matrix33(fCos, 0.f, -fSin,
						 0.f,  1.f,	 0.f,
						 fSin, 0.f,  fCos);
	}

	void Matrix33::SetRotationZ(float _fAngle)								// in radians
	{
		float fCos = cos(_fAngle);
		float fSin = sin(_fAngle);

		*this = Matrix33(fCos, fSin, 0.f,
						-fSin, fCos, 0.f,
						 0.f, 0.f, 1.f);
	}

	void Matrix33::SetScale(float _fX, float _fY, float _fZ)
	{
		*this = Matrix33(_fX, 0.f, 0.f,
						 0.f, _fY, 0.f,
						 0.f, 0.f, _fZ);
	}

	void Matrix33::SetIdentity()
	{
		*this = MATRIX33IDENTITY;
	}

	void Matrix33::SetZero()
	{
		*this = MATRIX33ZERO;
	}


	// assignment operators
	Matrix33& Matrix33::operator*= (const Matrix33 &_mat)
	{
		// Row 0
		m_af[0][0] = m_af[0][0] * _mat.m_af[0][0] + m_af[0][1] * _mat.m_af[1][0] + m_af[0][2] * _mat.m_af[2][0];
		m_af[0][1] = m_af[0][0] * _mat.m_af[0][1] + m_af[0][1] * _mat.m_af[1][1] + m_af[0][2] * _mat.m_af[2][1];
		m_af[0][2] = m_af[0][0] * _mat.m_af[0][2] + m_af[0][1] * _mat.m_af[1][2] + m_af[0][2] * _mat.m_af[2][2];

		// Row 1
		m_af[1][0] = m_af[1][0] * _mat.m_af[0][0] + m_af[1][1] * _mat.m_af[1][0] + m_af[1][2] * _mat.m_af[2][0];
		m_af[1][1] = m_af[1][0] * _mat.m_af[0][1] + m_af[1][1] * _mat.m_af[1][1] + m_af[1][2] * _mat.m_af[2][1];
		m_af[1][2] = m_af[1][0] * _mat.m_af[0][2] + m_af[1][1] * _mat.m_af[1][2] + m_af[1][2] * _mat.m_af[2][2];

		// Row 2
		m_af[2][0] = m_af[2][0] * _mat.m_af[0][0] + m_af[2][1] * _mat.m_af[1][0] + m_af[2][2] * _mat.m_af[2][0];
		m_af[2][1] = m_af[2][0] * _mat.m_af[0][1] + m_af[2][1] * _mat.m_af[1][1] + m_af[2][2] * _mat.m_af[2][1];
		m_af[2][2] = m_af[2][0] * _mat.m_af[0][2] + m_af[2][1] * _mat.m_af[1][2] + m_af[2][2] * _mat.m_af[2][2];

		return *this;
	}

	Matrix33& Matrix33::operator+= (const Matrix33 &_mat)
	{
		// Row 0
		m_af[0][0] += _mat.m_af[0][0];
		m_af[0][1] += _mat.m_af[0][1];
		m_af[0][2] += _mat.m_af[0][2];

		// Row 1
		m_af[1][0] += _mat.m_af[1][0];
		m_af[1][1] += _mat.m_af[1][1];
		m_af[1][2] += _mat.m_af[1][2];

		// Row 2
		m_af[2][0] += _mat.m_af[2][0];
		m_af[2][1] += _mat.m_af[2][1];
		m_af[2][2] += _mat.m_af[2][2];

		return *this;
	}

	Matrix33& Matrix33::operator-= (const Matrix33 &_mat)
	{
		// Row 0
		m_af[0][0] -= _mat.m_af[0][0];
		m_af[0][1] -= _mat.m_af[0][1];
		m_af[0][2] -= _mat.m_af[0][2];

		// Row 1
		m_af[1][0] -= _mat.m_af[1][0];
		m_af[1][1] -= _mat.m_af[1][1];
		m_af[1][2] -= _mat.m_af[1][2];

		// Row 2
		m_af[2][0] -= _mat.m_af[2][0];
		m_af[2][1] -= _mat.m_af[2][1];
		m_af[2][2] -= _mat.m_af[2][2];

		return *this;
	}

	Matrix33& Matrix33::operator*= (float _f)
	{
		// Row 0
		m_af[0][0] *= _f;
		m_af[0][1] *= _f;
		m_af[0][2] *= _f;

		// Row 1
		m_af[1][0] *= _f;
		m_af[1][1] *= _f;
		m_af[1][2] *= _f;

		// Row 2
		m_af[2][0] *= _f;
		m_af[2][1] *= _f;
		m_af[2][2] *= _f;

		return *this;
	}

	Matrix33& Matrix33::operator/= (float _f)
	{
		// Row 0
		m_af[0][0] /= _f;
		m_af[0][1] /= _f;
		m_af[0][2] /= _f;

		// Row 1
		m_af[1][0] /= _f;
		m_af[1][1] /= _f;
		m_af[1][2] /= _f;

		// Row 2
		m_af[2][0] /= _f;
		m_af[2][1] /= _f;
		m_af[2][2] /= _f;

		return *this;
	}


	// unary operators
	Matrix33 Matrix33::operator+ () const
	{
		Matrix33 result;

		// Row 0
		result.m_af[0][0] = abs(m_af[0][0]);
		result.m_af[0][1] = abs(m_af[0][1]);
		result.m_af[0][2] = abs(m_af[0][2]);

		// Row 1
		result.m_af[1][0] = abs(m_af[1][0]);
		result.m_af[1][1] = abs(m_af[1][1]);
		result.m_af[1][2] = abs(m_af[1][2]);

		// Row 2
		result.m_af[2][0] = abs(m_af[2][0]);
		result.m_af[2][1] = abs(m_af[2][1]);
		result.m_af[2][2] = abs(m_af[2][2]);

		return result;
	}

	Matrix33 Matrix33::operator- () const
	{
		Matrix33 result;

		// Row 0
		result.m_af[0][0] = -m_af[0][0];
		result.m_af[0][1] = -m_af[0][1];
		result.m_af[0][2] = -m_af[0][2];

		// Row 1
		result.m_af[1][0] = -m_af[1][0];
		result.m_af[1][1] = -m_af[1][1];
		result.m_af[1][2] = -m_af[1][2];

		// Row 2
		result.m_af[2][0] = -m_af[2][0];
		result.m_af[2][1] = -m_af[2][1];
		result.m_af[2][2] = -m_af[2][2];

		return result;
	}


	// binary operators
	Matrix33 Matrix33::operator* (const Matrix33 &_mat) const
	{
		Matrix33 result;

		// Row 0
		result.m_af[0][0] = m_af[0][0] * _mat.m_af[0][0] + m_af[0][1] * _mat.m_af[1][0] + m_af[0][2] * _mat.m_af[2][0];
		result.m_af[0][1] = m_af[0][0] * _mat.m_af[0][1] + m_af[0][1] * _mat.m_af[1][1] + m_af[0][2] * _mat.m_af[2][1];
		result.m_af[0][2] = m_af[0][0] * _mat.m_af[0][2] + m_af[0][1] * _mat.m_af[1][2] + m_af[0][2] * _mat.m_af[2][2];

		// Row 1
		result.m_af[1][0] = m_af[1][0] * _mat.m_af[0][0] + m_af[1][1] * _mat.m_af[1][0] + m_af[1][2] * _mat.m_af[2][0];
		result.m_af[1][1] = m_af[1][0] * _mat.m_af[0][1] + m_af[1][1] * _mat.m_af[1][1] + m_af[1][2] * _mat.m_af[2][1];
		result.m_af[1][2] = m_af[1][0] * _mat.m_af[0][2] + m_af[1][1] * _mat.m_af[1][2] + m_af[1][2] * _mat.m_af[2][2];

		// Row 2
		result.m_af[2][0] = m_af[2][0] * _mat.m_af[0][0] + m_af[2][1] * _mat.m_af[1][0] + m_af[2][2] * _mat.m_af[2][0];
		result.m_af[2][1] = m_af[2][0] * _mat.m_af[0][1] + m_af[2][1] * _mat.m_af[1][1] + m_af[2][2] * _mat.m_af[2][1];
		result.m_af[2][2] = m_af[2][0] * _mat.m_af[0][2] + m_af[2][1] * _mat.m_af[1][2] + m_af[2][2] * _mat.m_af[2][2];

		return result;
	}

	Matrix33 Matrix33::operator+ (const Matrix33 &_mat) const
	{
		Matrix33 result;

		// Row 0
		result.m_af[0][0] = m_af[0][0] + _mat.m_af[0][0];
		result.m_af[0][1] = m_af[0][1] + _mat.m_af[0][1];
		result.m_af[0][2] = m_af[0][2] + _mat.m_af[0][2];

		// Row 1
		result.m_af[1][0] = m_af[1][0] + _mat.m_af[1][0];
		result.m_af[1][1] = m_af[1][1] + _mat.m_af[1][1];
		result.m_af[1][2] = m_af[1][2] + _mat.m_af[1][2];

		// Row 2
		result.m_af[2][0] = m_af[2][0] + _mat.m_af[2][0];
		result.m_af[2][1] = m_af[2][1] + _mat.m_af[2][1];
		result.m_af[2][2] = m_af[2][2] + _mat.m_af[2][2];

		return result;
	}

	Matrix33 Matrix33::operator- (const Matrix33 &_mat) const
	{
		Matrix33 result;

		// Row 0
		result.m_af[0][0] = m_af[0][0] - _mat.m_af[0][0];
		result.m_af[0][1] = m_af[0][1] - _mat.m_af[0][1];
		result.m_af[0][2] = m_af[0][2] - _mat.m_af[0][2];

		// Row 1
		result.m_af[1][0] = m_af[1][0] - _mat.m_af[1][0];
		result.m_af[1][1] = m_af[1][1] - _mat.m_af[1][1];
		result.m_af[1][2] = m_af[1][2] - _mat.m_af[1][2];

		// Row 2
		result.m_af[2][0] = m_af[2][0] - _mat.m_af[2][0];
		result.m_af[2][1] = m_af[2][1] - _mat.m_af[2][1];
		result.m_af[2][2] = m_af[2][2] - _mat.m_af[2][2];

		return result;
	}

	Matrix33 Matrix33::operator* (float _f) const
	{
		Matrix33 result;

		// Row 0
		result.m_af[0][0] = m_af[0][0] * _f;
		result.m_af[0][1] = m_af[0][1] * _f;
		result.m_af[0][2] = m_af[0][2] * _f;

		// Row 1
		result.m_af[1][0] = m_af[1][0] * _f;
		result.m_af[1][1] = m_af[1][1] * _f;
		result.m_af[1][2] = m_af[1][2] * _f;

		// Row 2
		result.m_af[2][0] = m_af[2][0] * _f;
		result.m_af[2][1] = m_af[2][1] * _f;
		result.m_af[2][2] = m_af[2][2] * _f;

		return result;
	}

	Matrix33 Matrix33::operator/ (float _f) const
	{
		Matrix33 result;

		// Row 0
		result.m_af[0][0] = m_af[0][0] / _f;
		result.m_af[0][1] = m_af[0][1] / _f;
		result.m_af[0][2] = m_af[0][2] / _f;

		// Row 1
		result.m_af[1][0] = m_af[1][0] / _f;
		result.m_af[1][1] = m_af[1][1] / _f;
		result.m_af[1][2] = m_af[1][2] / _f;

		// Row 2
		result.m_af[2][0] = m_af[2][0] / _f;
		result.m_af[2][1] = m_af[2][1] / _f;
		result.m_af[2][2] = m_af[2][2] / _f;

		return result;
	}

	bool Matrix33::operator== (const Matrix33 &_mat) const
	{
		return (m_af[0][0] == _mat.m_af[0][0] && m_af[0][1] == _mat.m_af[0][1] && m_af[0][2] == _mat.m_af[0][2]	// Row 0
			&& m_af[1][0] == _mat.m_af[1][0] && m_af[1][1] == _mat.m_af[1][1] && m_af[1][2] == _mat.m_af[1][2]	// Row 1
			&& m_af[2][0] == _mat.m_af[2][0] && m_af[2][1] == _mat.m_af[2][1] && m_af[2][2] == _mat.m_af[2][2]);	// Row 2
	}

	bool Matrix33::operator!= (const Matrix33 &_mat) const
	{
		return !(m_af[0][0] == _mat.m_af[0][0] && m_af[0][1] == _mat.m_af[0][1] && m_af[0][2] == _mat.m_af[0][2]	// Row 0
			&& m_af[1][0] == _mat.m_af[1][0] && m_af[1][1] == _mat.m_af[1][1] && m_af[1][2] == _mat.m_af[1][2]	// Row 1
			&& m_af[2][0] == _mat.m_af[2][0] && m_af[2][1] == _mat.m_af[2][1] && m_af[2][2] == _mat.m_af[2][2]);	// Row 2
	}

	Vector3 Matrix33::operator* (const Vector3& _v)
	{
		Vector3 result;

		float fX = _v.GetX();
		float fY = _v.GetY();
		float fZ = _v.GetZ();

		result.SetX(m_af[0][0] * fX + m_af[0][1] * fY + m_af[0][2] * fZ);
		result.SetY(m_af[1][0] * fX + m_af[1][1] * fY + m_af[1][2] * fZ);
		result.SetZ(m_af[2][0] * fX + m_af[2][1] * fY + m_af[2][2] * fZ);

		return result;
	}


	// accessor
	float& Matrix33::operator () (int _iRow, int _iCol)
	{
		return m_af[_iRow][_iCol];
	}

	float Matrix33::operator () (int _iRow, int _iCol) const
	{
		return m_af[_iRow][_iCol];
	}


	// matrix operation
	void Matrix33::Transpose()
	{
		Matrix33 tempMat33 = *this;

		// Swap Row 0 & Column 0
		m_af[0][1] = tempMat33.m_af[1][0];
		m_af[0][2] = tempMat33.m_af[2][0];

		// Swap Row 1 & Column 1
		m_af[1][0] = tempMat33.m_af[0][1];
		m_af[1][2] = tempMat33.m_af[2][1];

		// Swap Row 2 & Column 2
		m_af[2][0] = tempMat33.m_af[0][2];
		m_af[2][1] = tempMat33.m_af[1][2];
	}

	bool Matrix33::Inverse()
	{
		float fDeterminant = 0.f;
		float fCofactor00 = m_af[1][1] * m_af[2][2] - m_af[2][1] * m_af[1][2];
		float fCofactor01 = -(m_af[1][0] * m_af[2][2] - m_af[1][2] * m_af[2][0]);
		float fCofactor02 = m_af[1][0] * m_af[2][1] - m_af[1][1] * m_af[2][0];

		fDeterminant = m_af[0][0] * fCofactor00 + m_af[0][1] * fCofactor01 + m_af[0][2] * fCofactor02;

		if (fDeterminant != 0.f)
		{
			Matrix33 cofactorMatrix;

			// Compute cofactors matrix

			// Row 0
			cofactorMatrix.m_af[0][0] = fCofactor00;
			cofactorMatrix.m_af[0][1] = fCofactor01;
			cofactorMatrix.m_af[0][2] = fCofactor02;

			// Row 1
			cofactorMatrix.m_af[1][0] = -(m_af[0][1] * m_af[2][2] - m_af[0][2] * m_af[2][1]);
			cofactorMatrix.m_af[1][1] = m_af[0][0] * m_af[2][2] - m_af[0][2] * m_af[2][0];
			cofactorMatrix.m_af[1][2] = -(m_af[0][0] * m_af[2][1] - m_af[0][1] * m_af[2][0]);

			// Row 2
			cofactorMatrix.m_af[2][0] = m_af[0][1] * m_af[1][2] - m_af[0][2] * m_af[1][1];
			cofactorMatrix.m_af[2][1] = -(m_af[0][0] * m_af[1][2] - m_af[0][2] * m_af[1][0]);
			cofactorMatrix.m_af[2][2] = m_af[0][0] * m_af[1][1] - m_af[0][1] * m_af[1][0];

			cofactorMatrix.Transpose();

			// Compute inverse matrix
			*this = (1.f / fDeterminant) * cofactorMatrix;

			return EXIT_SUCCESS;
		}

		return EXIT_FAILURE;
	}


	// DADENGINE_MATHAPI friend function
	Vector3 operator* (const Vector3& _v, const Matrix33 &_mat)
	{
		Vector3 result;
		float fX = _v.GetX();
		float fY = _v.GetY();
		float fZ = _v.GetZ();

		result.SetX(_mat.m_af[0][0] * fX + _mat.m_af[0][1] * fY + _mat.m_af[0][2] * fZ);
		result.SetY(_mat.m_af[1][0] * fX + _mat.m_af[1][1] * fY + _mat.m_af[1][2] * fZ);
		result.SetZ(_mat.m_af[2][0] * fX + _mat.m_af[2][1] * fY + _mat.m_af[2][2] * fZ);

		return result;
	}

	Matrix33 DadEngine::operator* (float _f, const Matrix33 &_mat)
	{
		Matrix33 result;

		// Row 0
		result.m_af[0][0] = _mat.m_af[0][0] * _f;
		result.m_af[0][1] = _mat.m_af[0][1] * _f;
		result.m_af[0][2] = _mat.m_af[0][2] * _f;

		// Row 1
		result.m_af[1][0] = _mat.m_af[1][0] * _f;
		result.m_af[1][1] = _mat.m_af[1][1] * _f;
		result.m_af[1][2] = _mat.m_af[1][2] * _f;

		// Row 2
		result.m_af[2][0] = _mat.m_af[2][0] * _f;
		result.m_af[2][1] = _mat.m_af[2][1] * _f;
		result.m_af[2][2] = _mat.m_af[2][2] * _f;

		return result;
	}


	// debug function
	ostream &operator<< (ostream& _out, const Matrix33 &_v)
	{
		// Row 0
		_out << "La valeur du composant 11 de la matrice est " << _v.m_af[0][0] << endl << endl;
		_out << "La valeur du composant 12 de la matrice est " << _v.m_af[0][1] << endl << endl;
		_out << "La valeur du composant 13 de la matrice est " << _v.m_af[0][2] << endl << endl;

		// Row 1
		_out << "La valeur du composant 21 de la matrice est " << _v.m_af[1][0] << endl << endl;
		_out << "La valeur du composant 22 de la matrice est " << _v.m_af[1][1] << endl << endl;
		_out << "La valeur du composant 23 de la matrice est " << _v.m_af[1][2] << endl << endl;

		// Row 2
		_out << "La valeur du composant 31 de la matrice est " << _v.m_af[2][0] << endl << endl;
		_out << "La valeur du composant 32 de la matrice est " << _v.m_af[2][1] << endl << endl;
		_out << "La valeur du composant 33 de la matrice est " << _v.m_af[2][2] << endl << endl;

		return _out;
	}

	istream &operator>> (istream& _in, Matrix33 &_v)
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

		return _in;
	}

	void Matrix33::Display() const
	{
		cout << "Ligne 1 :" << endl;
		cout << m_af[0][0] << "\t" << m_af[0][1] << "\t" << m_af[0][2] << endl << endl;

		cout << "Ligne 2 :" << endl;
		cout << m_af[1][0] << "\t" << m_af[1][1] << "\t" << m_af[0][2] << endl << endl;

		cout << "Ligne 3 :" << endl;
		cout << m_af[2][0] << "\t" << m_af[2][1] << "\t" << m_af[2][2] << endl << endl;
	}
}