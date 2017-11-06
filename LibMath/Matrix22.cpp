/*Documentation															*/
/*@author	:	Quentin Ladevie											*/
/*@file		:	Matrix22.hpp											*/
/*@date		:	03/12/2015												*/
/*@brief	:	Fichier source des matrices carré de dimension 2		*/
#include "stdafx.h"
#include "Matrix22.hpp"


namespace DadEngine
{
	// constructor and destructor
	Matrix22::Matrix22()
	{
		*this = MATRIX22ZERO;
	}

	Matrix22::Matrix22(float _afM[4])
	{
		m_af[0][0] = _afM[0];
		m_af[0][1] = _afM[1];
		m_af[1][0] = _afM[2];
		m_af[1][1] = _afM[3];
	}

	Matrix22::Matrix22(float _fM11, float _fM12,
		float _fM21, float _fM22)
	{
		m_af[0][0] = _fM11;
		m_af[0][1] = _fM12;
		m_af[1][0] = _fM21;
		m_af[1][1] = _fM22;
	}


	// set/get
	void Matrix22::SetRotation(float _fAngle)									// in radians
	{
		float fCos = cos(_fAngle);
		float fSin = sin(_fAngle);

		*this = Matrix22(fCos, fSin,
			-fSin, fCos);
	}

	void Matrix22::SetScale(float _fX, float _fY)
	{
		*this = Matrix22(_fX, 0.f,
			0., _fY);
	}

	void Matrix22::SetIdentity()
	{
		*this = MATRIX22IDENTITY;
	}

	void Matrix22::SetZero()
	{
		*this = MATRIX22ZERO;
	}


	// assignment operators
	Matrix22& Matrix22::operator*= (const Matrix22 &_mat)
	{
		// Row 0
		m_af[0][0] = m_af[0][0] * _mat.m_af[0][0] + m_af[0][1] * _mat.m_af[1][0];
		m_af[0][1] = m_af[0][0] * _mat.m_af[0][1] + m_af[0][1] * _mat.m_af[1][1];

		// Row 1
		m_af[1][0] = m_af[1][0] * _mat.m_af[0][0] + m_af[1][1] * _mat.m_af[1][0];
		m_af[1][1] = m_af[1][0] * _mat.m_af[0][1] + m_af[1][1] * _mat.m_af[1][1];

		return *this;
	}

	Matrix22& Matrix22::operator+= (const Matrix22 &_mat)
	{
		m_af[0][0] += _mat.m_af[0][0];
		m_af[0][1] += _mat.m_af[0][1];
		m_af[1][0] += _mat.m_af[1][0];
		m_af[1][1] += _mat.m_af[1][1];

		return *this;
	}

	Matrix22& Matrix22::operator-= (const Matrix22 &_mat)
	{
		m_af[0][0] -= _mat.m_af[0][0];
		m_af[0][1] -= _mat.m_af[0][1];
		m_af[1][0] -= _mat.m_af[1][0];
		m_af[1][1] -= _mat.m_af[1][1];

		return *this;
	}

	Matrix22& Matrix22::operator*= (float _f)
	{
		m_af[0][0] *= _f;
		m_af[0][1] *= _f;
		m_af[1][0] *= _f;
		m_af[1][1] *= _f;

		return *this;
	}

	Matrix22& Matrix22::operator/= (float _f)
	{
		m_af[0][0] /= _f;
		m_af[0][1] /= _f;
		m_af[1][0] /= _f;
		m_af[1][1] /= _f;

		return *this;
	}


	// unary operators
	Matrix22 Matrix22::operator+ () const
	{
		Matrix22 result;

		result.m_af[0][0] = abs(m_af[0][0]);
		result.m_af[0][1] = abs(m_af[0][1]);
		result.m_af[1][0] = abs(m_af[1][0]);
		result.m_af[1][1] = abs(m_af[1][1]);

		return result;
	}

	Matrix22 Matrix22::operator- () const
	{
		Matrix22 result;

		result.m_af[0][0] = -m_af[0][0];
		result.m_af[0][1] = -m_af[0][1];
		result.m_af[1][0] = -m_af[1][0];
		result.m_af[1][1] = -m_af[1][1];

		return result;
	}


	// binary operators
	Matrix22 Matrix22::operator* (const Matrix22 &_mat) const
	{
		Matrix22 result;

		result.m_af[0][0] = m_af[0][0] * _mat.m_af[0][0] + m_af[0][1] * _mat.m_af[1][0];
		result.m_af[0][1] = m_af[0][0] * _mat.m_af[0][1] + m_af[0][1] * _mat.m_af[1][1];
		result.m_af[1][0] = m_af[1][0] * _mat.m_af[0][0] + m_af[1][1] * _mat.m_af[0][1];
		result.m_af[1][1] = m_af[1][0] * _mat.m_af[0][1] + m_af[1][1] * _mat.m_af[1][1];

		return result;
	}

	Matrix22 Matrix22::operator+ (const Matrix22 &_mat) const
	{
		Matrix22 result;

		result.m_af[0][0] = m_af[0][0] + _mat.m_af[0][0];
		result.m_af[0][1] = m_af[0][1] + _mat.m_af[0][1];
		result.m_af[1][0] = m_af[1][0] + _mat.m_af[1][0];
		result.m_af[1][1] = m_af[1][1] + _mat.m_af[1][1];

		return result;
	}

	Matrix22 Matrix22::operator- (const Matrix22 &_mat) const
	{
		Matrix22 result;

		result.m_af[0][0] = m_af[0][0] - _mat.m_af[0][0];
		result.m_af[0][1] = m_af[0][1] - _mat.m_af[0][1];
		result.m_af[1][0] = m_af[1][0] - _mat.m_af[1][0];
		result.m_af[1][1] = m_af[1][1] - _mat.m_af[1][1];

		return result;
	}

	Matrix22 Matrix22::operator* (float _f) const
	{
		Matrix22 result;

		result.m_af[0][0] = m_af[0][0] * _f;
		result.m_af[0][1] = m_af[0][1] * _f;
		result.m_af[1][0] = m_af[1][0] * _f;
		result.m_af[1][1] = m_af[1][1] * _f;

		return result;
	}

	Matrix22 Matrix22::operator/ (float _f) const
	{
		Matrix22 result;

		result.m_af[0][0] = m_af[0][0] / _f;
		result.m_af[0][1] = m_af[0][1] / _f;
		result.m_af[1][0] = m_af[1][0] / _f;
		result.m_af[1][1] = m_af[1][1] / _f;

		return result;
	}


	bool Matrix22::operator== (const Matrix22 &_mat) const
	{
		return (m_af[0][0] == _mat.m_af[0][0] && m_af[0][1] == _mat.m_af[0][1]		// Row 0
			&& m_af[1][0] == _mat.m_af[1][0] && m_af[1][1] == _mat.m_af[1][1]); // Row 1
	}

	bool Matrix22::operator!= (const Matrix22 &_mat) const
	{
		return !(m_af[0][0] == _mat.m_af[0][0] && m_af[0][1] == _mat.m_af[0][1] && m_af[1][0] == _mat.m_af[1][0] && m_af[1][1] == _mat.m_af[1][1]);
	}


	Vector2 Matrix22::operator* (const Vector2& _v)
	{
		Vector2 result;

		float fX = _v.GetX();
		float fY = _v.GetY();

		result.SetX(m_af[0][0] * fX + m_af[1][0] * fY);
		result.SetY(m_af[0][1] * fX + m_af[1][1] * fY);

		return result;
	}


	// accessor
	float& Matrix22::operator () (int _iRow, int _iCol)
	{
		return m_af[_iRow][_iCol];
	}

	float  Matrix22::operator () (int _iRow, int _iCol) const
	{
		return m_af[_iRow][_iCol];
	}


	// matrix operation
	void Matrix22::Transpose()
	{
		Matrix22 tempMat22 = *this;

		// Swap Row 0 & Column 0
		m_af[0][1] = tempMat22.m_af[1][0];

		// Swap Row 1 & Column 1
		m_af[1][0] = tempMat22.m_af[0][1];
	}

	bool Matrix22::Inverse()
	{
		float fDeterminant = m_af[0][0] * m_af[1][1] - m_af[1][0] * m_af[0][1];

		if (fDeterminant != 0.f)
		{
			Matrix22 cofactorMatrix = Matrix22(m_af[1][1], -m_af[0][1],
				-m_af[1][0], m_af[0][0]);

			*this = (1.f / fDeterminant) * cofactorMatrix;

			return EXIT_SUCCESS;
		}

		return EXIT_FAILURE;
	}


	// DADENGINE_MATHAPI friend function
	Vector2 operator* (const Vector2& _v, const Matrix22 &_mat)
	{
		Vector2 result;
		float fX = _v.GetX();
		float fY = _v.GetY();

		result.SetX( _mat.m_af[0][0] * fX + _mat.m_af[0][1] * fY);
		result.SetY( _mat.m_af[1][0] * fX + _mat.m_af[1][1] * fY);

		return result;
	}

	Matrix22 operator* (float _f, const Matrix22 &_mat)
	{
		Matrix22 result;

		result.m_af[0][0] = _mat.m_af[0][0] * _f;
		result.m_af[0][1] = _mat.m_af[0][1] * _f;
		result.m_af[1][0] = _mat.m_af[1][0] * _f;
		result.m_af[1][1] = _mat.m_af[1][1] * _f;

		return result;
	}


	// debug function
	ostream &operator<< (ostream& _out, const Matrix22 &_v)
	{
		_out << "La valeur du composant 11 de la matrice est " << _v.m_af[0][0] << endl << endl;
		_out << "La valeur du composant 12 de la matrice est " << _v.m_af[0][1] << endl << endl;
		_out << "La valeur du composant 21 de la matrice est " << _v.m_af[1][0] << endl << endl;
		_out << "La valeur du composant 22 de la matrice est " << _v.m_af[1][1] << endl << endl;

		return _out;
	}

	istream &operator>> (istream& _in, Matrix22 &_v)
	{
		cout << "Entrez une valeur pour le composant 11 de la matrice :" << endl << endl;
		_in.clear();
		_in.sync();
		_in >> _v.m_af[0][0];

		cout << "Entrez une valeur pour le composant 12 de la matrice :" << endl << endl;
		_in.clear();
		_in.sync();
		_in >> _v.m_af[0][1];

		cout << "Entrez une valeur pour le composant 21 de la matrice :" << endl << endl;
		_in.clear();
		_in.sync();
		_in >> _v.m_af[1][0];

		cout << "Entrez une valeur pour le composant 22 de la matrice :" << endl << endl;
		_in.clear();
		_in.sync();
		_in >> _v.m_af[1][1];

		return _in;
	}


	void Matrix22::Display() const
	{
		cout << "Ligne 1 :" << endl;
		cout << m_af[0][0] << "\t" << m_af[0][1] << endl << endl;

		cout << "Ligne 2 :" << endl;
		cout << m_af[1][0] << "\t" << m_af[1][1] << endl << endl;
	}
}