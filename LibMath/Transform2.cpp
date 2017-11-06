/*Documentation										*/
/*@author	:	Quentin Ladevie						*/
/*@file		:	Transform2.cpp						*/
/*@date		:	07/01/16							*/
/*@brief	:	Fichier source des transforms 2D	*/

#include "stdafx.h"
#include "Transform2.hpp"


namespace DadEngine
{
	Transform2::Transform2(float _fM[9])
	{
		m_ptrRotation = new Matrix22(_fM[0], _fM[1],
									 _fM[3], _fM[4]);

		m_ptrTranslation = new Vector2(_fM[2], _fM[5]);

		m_ptrScale = NULL;
	}

#	pragma warning( disable : 4100 )
	Transform2::Transform2(	float _fM11, float _fM12, float _fM13,
							float _fM21, float _fM22, float _fM23,
							float _fM31, float _fM32, float _fM33)
	{
		m_ptrRotation = new Matrix22(_fM11, _fM12,
									 _fM21, _fM22);

		m_ptrTranslation = new Vector2(_fM13, _fM23);

		m_ptrScale = NULL;
	}
#	pragma warning( default : 4100 )

	Transform2::Transform2(const Matrix33& _m)
	{
		m_ptrRotation = new Matrix22(_m(0, 0), _m(0, 1),
									 _m(1, 0), _m(1, 1));

		m_ptrTranslation = new Vector2(_m(0, 2), _m(1, 2));

		m_ptrScale = NULL;
	}

	Transform2::Transform2(Matrix22* _ptrmRotation, Vector2* _ptrvTranslation, Vector2* _ptrvScale) : m_ptrRotation(_ptrmRotation), m_ptrTranslation(_ptrvTranslation), m_ptrScale(_ptrvScale)
	{}

	Transform2::Transform2(const Transform2& _copy)
	{
		m_ptrRotation = NULL;
		m_ptrScale = NULL;
		m_ptrTranslation = NULL;


		if (_copy.m_ptrRotation)
		{
			m_ptrRotation = new Matrix22(*_copy.m_ptrRotation);
		}

		if (m_ptrScale)
		{
			m_ptrScale = new Vector2(*_copy.m_ptrScale);
		}

		if (m_ptrTranslation)
		{
			m_ptrTranslation = new Vector2(*_copy.m_ptrTranslation);
		}
	}


	Transform2::~Transform2()
	{
		if (m_ptrRotation)
		{
			delete m_ptrRotation;
		}

		m_ptrRotation = NULL;


		if (m_ptrScale)
		{
			delete m_ptrScale;
		}

		m_ptrScale = NULL;


		if (m_ptrTranslation)
		{
			delete m_ptrTranslation;
		}

		m_ptrTranslation = NULL;
	}


	// Set/Get functions
	void Transform2::SetTranslation(Vector2* _ptrV)
	{
		m_ptrTranslation = _ptrV;
	}

	void Transform2::SetRotation(Matrix22* _ptrM)
	{
		m_ptrRotation = _ptrM;
	}

	void Transform2::SetScale(Vector2* _ptrV)
	{
		m_ptrScale = _ptrV;
	}

	void Transform2::SetMatrix(Matrix33& _m)
	{
		m_ptrRotation = new Matrix22(_m(0, 0), _m(0, 1),
									 _m(1, 0), _m(1, 1));

		m_ptrTranslation = new Vector2(_m(0, 2), _m(1, 2));

		m_ptrScale = NULL;
	}

	Matrix33 Transform2::GetMatrix() const
	{
		Matrix33 RTS, R, T, S;

		if (m_ptrRotation)
		{
			RTS *= Matrix33((*m_ptrRotation)(0, 0), (*m_ptrRotation)(0, 1), 0.f,
							(*m_ptrRotation)(1, 0), (*m_ptrRotation)(1, 1), 0.f,
							0.f					  , 0.f					  , 1.f);
		}

		if (m_ptrScale)
		{
			S.SetScale(m_ptrScale->GetX(), m_ptrScale->GetY(), 1.f);
			RTS *= S;
		}

		if (m_ptrTranslation)
		{
			T.SetTranslation(m_ptrTranslation->GetX(), m_ptrTranslation->GetY());
			RTS *= T;
		}


		return RTS;
	}


	// Operators
	Transform2& Transform2::operator*= (const Transform2 &_mat)
	{
		return Transform2();
	}

	Transform2 Transform2::operator* (const Transform2 &_mat) const
	{
		return Transform2();
	}

	Transform2& Transform2::operator= (const Transform2 &_mat)
	{
		return Transform2();
	}

	bool Transform2::operator== (const Transform2 &_mat) const
	{
		return true;
	}

	bool Transform2::operator!= (const Transform2 &_mat) const
	{
		return true;
	}

	Vector3 Transform2::operator* (const Vector3& _v)
	{
		return Vector3();
	}


	// Debug function
	ostream &operator<< (ostream& _out, const Transform2 &_v)
	{
		_out << "Transform2 : " << endl << endl;

		if (_v.m_ptrRotation)
		{
			_out << "Rotation : " << endl << *_v.m_ptrRotation << endl;
		}

		if (_v.m_ptrTranslation)
		{
			_out << "Translation : " << endl << *_v.m_ptrTranslation << endl;
		}

		if (_v.m_ptrScale)
		{
			_out << "Scale : " << endl << *_v.m_ptrScale << endl;
		}

		return _out;
	}

	istream &operator>> (istream& _in, Transform2 &_v)
	{
		cout << "Matrice Transform2 :" << endl << endl;
		cout << "1) Rotation : " << endl;

		if (!_v.m_ptrRotation)
		{
			_v.m_ptrRotation = new Matrix22;
		}

		_in >> *_v.m_ptrRotation;


		cout << "2) Translation : " << endl;

		if (!_v.m_ptrTranslation)
		{
			_v.m_ptrTranslation = new Vector2;
		}

		_in >> *_v.m_ptrTranslation;


		cout << "3) Scale : " << endl;

		if (!_v.m_ptrScale)
		{
			_v.m_ptrScale = new Vector2;
		}

		_in >> *_v.m_ptrScale;


		return _in;
	}


	void Transform2::Display() const
	{
		cout << *this<< endl;
	}
}