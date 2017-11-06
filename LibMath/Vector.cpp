/*Documentation													*/
/*@author	:	Quentin Ladevie									*/
/*@file		:	Vector.cpp										*/
/*@date		:	19/11/2015										*/
/*@brief	:	Fichier source des vecteurs à n Dimensions		*/
#include "stdafx.h"
#include "Vector.hpp"


namespace DadEngine
{
	Vector::Vector()
	{
		m_uiSize = 0;
		m_ptrfV = NULL;
	}

	Vector::Vector(const Vector& _copy)
	{
		m_uiSize = _copy.m_uiSize;

		m_ptrfV = new float[m_uiSize];

		for (unsigned int i = 0; i < m_uiSize; ++i)
		{
			m_ptrfV[i] = _copy.m_ptrfV[i];
		}
	}

	Vector::Vector(unsigned int _uiSize) : m_uiSize(_uiSize)
	{
		m_ptrfV = new float[m_uiSize];

		for (unsigned int i = 0; i < m_uiSize; ++i)
		{
			m_ptrfV[i] = 0.f;
		}
	}

	Vector::Vector(unsigned int _uiSize, float* _ptrfVector) : m_uiSize(_uiSize), m_ptrfV(_ptrfVector)
	{}


	Vector::~Vector()
	{
		delete[] m_ptrfV;
	}


	// Get/Set
	bool Vector::Set(unsigned int _iIndex, float _fNewValue)
	{
		if (_iIndex < m_uiSize && _iIndex >= 0)
		{
			m_ptrfV[_iIndex] = _fNewValue;

			return EXIT_SUCCESS;
		}

		return EXIT_FAILURE;
	}

	bool Vector::Get(unsigned int _iIndex, float& _fValue) const
	{
		if (_iIndex < m_uiSize && _iIndex >= 0)
		{
			_fValue = m_ptrfV[_iIndex];

			return EXIT_SUCCESS;
		}

		return EXIT_FAILURE;
	}


	// Handling
	void Vector::Scale(float _fSize)
	{
		for (unsigned int i = 0; i < m_uiSize; ++i)
		{
			m_ptrfV[i] *= _fSize;
		}
	}

	void Vector::Translate(float* _ptrfTranslationVector)
	{
		for (unsigned int i = 0; i < m_uiSize; ++i)
		{
			m_ptrfV[i] += _ptrfTranslationVector[i];
		}
	}

	float Vector::Dot(Vector& _vector) const
	{
		float fResult = 0.f;

		if (_vector.m_uiSize != m_uiSize)
		{
			cout << "Impossible d'effectuer l'opération suivante sur des vecteurs de tailles différente." << endl << endl;

			return fResult;
		}

		for (unsigned int i = 0; i < m_uiSize; ++i)
		{
			fResult += m_ptrfV[i] * _vector.m_ptrfV[i];
		}

		return fResult;
	}

	Vector Vector::Add(Vector& _vector) const
	{
		Vector result;

		if (_vector.m_uiSize != m_uiSize)
		{
			cout << "Impossible d'effectuer l'opération suivante sur des vecteurs de tailles différente." << endl << endl;

			return EXIT_FAILURE;
		}

		result.m_uiSize = m_uiSize;

		for (unsigned int i = 0; i < m_uiSize; ++i)
		{
			result.m_ptrfV[i] = m_ptrfV[i] + _vector.m_ptrfV[i];
		}

		return result;
	}


	void Vector::Display() const
	{
		cout << "Le vecteur est le suivant : " << endl;

		for (unsigned int i = 0; i < m_uiSize; ++i)
		{
			cout << "\t" << m_ptrfV[i] << endl;
		}
	}


	// Assignement operators
	Vector& Vector::operator+= (const Vector& _v)
	{
		unsigned int uiMaxValue = m_uiSize;

		if (uiMaxValue > _v.m_uiSize)
		{
			uiMaxValue = _v.m_uiSize;
		}

		for (unsigned int i = 0; i < uiMaxValue; ++i)
		{
			m_ptrfV[i] += _v.m_ptrfV[i];
		}

		return *this;
	}

	Vector& Vector::operator-= (const Vector& _v)
	{
		unsigned int uiMaxValue = m_uiSize;

		if (uiMaxValue > _v.m_uiSize)
		{
			uiMaxValue = _v.m_uiSize;
		}

		for (unsigned int i = 0; i < uiMaxValue; ++i)
		{
			m_ptrfV[i] -= _v.m_ptrfV[i];
		}

		return *this;
	}

	Vector& Vector::operator*= (float _f)
	{
		unsigned int uiMaxValue = m_uiSize;

		for (unsigned int i = 0; i < uiMaxValue; ++i)
		{
			m_ptrfV[i] *= _f;
		}

		return *this;
	}

	Vector& Vector::operator/= (float _f)
	{
		unsigned int uiMaxValue = m_uiSize;

		for (unsigned int i = 0; i < uiMaxValue; ++i)
		{
			m_ptrfV[i] /= _f;
		}

		return *this;
	}

	Vector& Vector::operator = (const Vector& _v)
	{
		delete[] m_ptrfV;

		m_uiSize = _v.m_uiSize;

		m_ptrfV = new float[m_uiSize];

		for (unsigned int i = 0; i < m_uiSize; ++i)
		{
			m_ptrfV[i] = _v.m_ptrfV[i];
		}

		return *this;
	}


	// Unary operators
	Vector Vector::operator+ () const
	{
		Vector result(m_uiSize);
		unsigned int uiMaxValue = m_uiSize;

		for (unsigned int i = 0; i < uiMaxValue; ++i)
		{
			result.m_ptrfV[i] = abs(m_ptrfV[i]);
		}

		return result;
	}

	Vector Vector::operator- () const
	{
		Vector result(m_uiSize);
		unsigned int uiMaxValue = m_uiSize;

		for (unsigned int i = 0; i < uiMaxValue; ++i)
		{
			result.m_ptrfV[i] = -m_ptrfV[i];
		}

		return result;
	}


	// Binary operators
	Vector Vector::operator+ (const Vector& _v) const
	{
		// Take the smaller value
		unsigned int uiMaxValue = (m_uiSize < _v.m_uiSize) ? (m_uiSize) : (_v.m_uiSize);

		Vector result(uiMaxValue);

		for (unsigned int i = 0; i < uiMaxValue; ++i)
		{
			result.m_ptrfV[i] = m_ptrfV[i] + _v.m_ptrfV[i];
		}

		return result;
	}

	Vector Vector::operator- (const Vector& _v) const
	{
		// Take the smaller value
		unsigned int uiMaxValue = (m_uiSize < _v.m_uiSize) ? (m_uiSize) : (_v.m_uiSize);

		Vector result(uiMaxValue);

		for (unsigned int i = 0; i < uiMaxValue; ++i)
		{
			result.m_ptrfV[i] = m_ptrfV[i] - _v.m_ptrfV[i];
		}

		return result;
	}

	Vector Vector::operator* (float _f) const
	{
		unsigned int uiMaxValue = m_uiSize;

		Vector result(uiMaxValue);

		for (unsigned int i = 0; i < uiMaxValue; ++i)
		{
			result.m_ptrfV[i] = m_ptrfV[i] * _f;
		}

		return result;
	}

	Vector Vector::operator/ (float _f) const
	{
		unsigned int uiMaxValue = m_uiSize;

		Vector result(uiMaxValue);

		for (unsigned int i = 0; i < uiMaxValue; ++i)
		{
			result.m_ptrfV[i] = m_ptrfV[i] / _f;
		}

		return result;
	}


	bool Vector::operator== (const Vector& _v) const
	{
		unsigned int uiMaxValue = m_uiSize;

		for (unsigned int i = 0; i < uiMaxValue; ++i)
		{
			if (m_ptrfV[i] != _v.m_ptrfV[i])
			{
				return false;
			}
		}

		return true;
	}

	bool Vector::operator!= (const Vector& _v) const
	{
		unsigned int uiMaxValue = m_uiSize;

		for (unsigned int i = 0; i < uiMaxValue; ++i)
		{
			if (m_ptrfV[i] == _v.m_ptrfV[i])
			{
				return false;
			}
		}

		return true;
	}


	// DADENGINE_MATHAPI friends operators
	Vector operator* (float _f, const Vector& _v)
	{
		unsigned int uiMaxValue = _v.m_uiSize;

		Vector result(uiMaxValue);

		for (unsigned int i = 0; i < uiMaxValue; ++i)
		{
			result.m_ptrfV[i] = _v.m_ptrfV[i] * _f;
		}

		return result;
	}

	ostream& operator <<(ostream& _o, const Vector& _v)
	{
		unsigned int uiMaxValue = _v.m_uiSize;

		for (unsigned int i = 0; i < uiMaxValue; ++i)
		{
			_o << "Composante " << i + 1 << " du vecteur : " << _v.m_ptrfV[i] << endl;
		}

		return _o;
	}

	istream& operator >>(istream& _i, Vector& _v)
	{
		unsigned int uiMaxValue = 0;

		if (_v.m_uiSize == 0)
		{
			cout << "Entrez un nombre de composantes arbitraire pour le veteur :" << endl << endl;

			_i >> uiMaxValue;
			_v.m_uiSize = uiMaxValue;

			_v.m_ptrfV = new float[uiMaxValue];
		}

		for (unsigned int i = 0; i < uiMaxValue; ++i)
		{
			cout << "Entrez la composante " << i + 1 << " du vecteur : " << endl << endl;

			_i.clear();
			_i.sync();
			_i >> _v.m_ptrfV[i];

			cout << endl << endl;
		}

		return _i;
	}
}