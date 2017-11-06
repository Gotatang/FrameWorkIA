/*Documentation											*/
/*@author	:	Quentin Ladevie							*/
/*@file		:	Transform3.hpp							*/
/*@date		:	03/12/2015								*/
/*@brief	:	Fichier source des matrices Transform3s	*/
#include "stdafx.h"
#include "Transform3.hpp"


namespace DadEngine
{
	// constructor and destructor
	Transform3::Transform3(float _fM[16])
	{
		m_ptrRotation = new Matrix33(_fM[0], _fM[1], _fM[2],
									 _fM[4], _fM[5], _fM[6],
									 _fM[8], _fM[9], _fM[10]);

		m_ptrTranslation = new Vector3(_fM[3], _fM[7], _fM[11]);

		m_ptrScale = NULL;
	}

#	pragma warning( disable : 4100 )
	Transform3::Transform3(	float _fM11, float _fM12, float _fM13, float _fM14,
							float _fM21, float _fM22, float _fM23, float _fM24,
							float _fM31, float _fM32, float _fM33, float _fM34,
							float _fM41, float _fM42, float _fM43, float _fM44)
	{
		m_ptrRotation = new Matrix33(_fM11, _fM12, _fM13,
									 _fM21, _fM22, _fM23,
									 _fM31, _fM32, _fM33);

		m_ptrTranslation = new Vector3(_fM14, _fM24, _fM34);

		m_ptrScale = NULL;
	}
#	pragma warning( default : 4100 )

	Transform3::Transform3(const Matrix44& _m)
	{
		m_ptrRotation = new Matrix33(_m(0, 0), _m(0, 1), _m(0, 2),
									 _m(1, 0), _m(1, 1), _m(1, 2),
									 _m(2, 0), _m(2, 1), _m(2, 2));

		m_ptrTranslation = new Vector3(_m(0, 3), _m(1, 3), _m(2, 3));

		m_ptrScale = NULL;
	}

	Transform3::Transform3(Matrix33* _ptrRotation, Vector3* _ptrTranslation, Vector3* _ptrScale) : m_ptrRotation(_ptrRotation), m_ptrTranslation(_ptrTranslation), m_ptrScale(_ptrScale)
	{}

	Transform3::Transform3(const Transform3& _m)
	{
		Matrix33* tempRotation = NULL;
		Vector3* tempTranslation = NULL;
		Vector3* tempScale = NULL;

		if (_m.m_ptrTranslation)
		{
			tempTranslation = new Vector3;

			tempTranslation->SetX(_m.m_ptrTranslation->GetX());
			tempTranslation->SetY(_m.m_ptrTranslation->GetY());
			tempTranslation->SetZ(_m.m_ptrTranslation->GetZ());
		}

		if (_m.m_ptrScale)
		{
			tempScale = new Vector3;

			tempScale->SetX(_m.m_ptrScale->GetX());
			tempScale->SetY(_m.m_ptrScale->GetY());
			tempScale->SetZ(_m.m_ptrScale->GetZ());
		}

		if (_m.m_ptrRotation)
		{
			tempRotation = new Matrix33(*_m.m_ptrRotation);
		}

		m_ptrRotation = tempRotation;
		m_ptrTranslation = tempTranslation;
		m_ptrScale = tempScale;
	}


	Transform3::~Transform3()
	{
		if (m_ptrTranslation)
		{
			delete m_ptrTranslation;
			m_ptrTranslation = NULL;
		}

		if (m_ptrScale)
		{
			delete m_ptrScale;
			m_ptrScale = NULL;
		}

		if (m_ptrRotation)
		{
			delete m_ptrRotation;
			m_ptrRotation = NULL;
		}
	}


	// set/get functions
	void Transform3::SetTranslation(Vector3* _ptrV)
	{
		if (m_ptrTranslation)
		{
			*m_ptrTranslation = *_ptrV;

			return;
		}

		m_ptrTranslation = new Vector3(*_ptrV);
	}

	void Transform3::SetRotation(Matrix33* _ptrM)
	{
		if (m_ptrRotation)
		{
			*m_ptrRotation = *_ptrM;

			return;
		}

		m_ptrRotation = new Matrix33(*_ptrM);
	}

	void Transform3::SetScale(Vector3* _ptrV)
	{
		if (m_ptrScale)
		{
			*m_ptrScale = *_ptrV;

			return;
		}

		m_ptrScale = new Vector3(*_ptrV);
	}

	void Transform3::SetMatrix(Matrix44& _m)
	{
		m_ptrRotation = new Matrix33(_m(0, 0), _m(0, 1), _m(0, 2),
									 _m(1, 0), _m(1, 1), _m(1, 2),
									 _m(2, 0), _m(2, 1), _m(2, 2));

		m_ptrTranslation = new Vector3(_m(0, 3), _m(1, 3), _m(2, 3));

		m_ptrScale = NULL;
	}

	Matrix44 Transform3::GetMatrix() const
	{
		Matrix44 RTS, R, T, S;

		if (m_ptrRotation)
		{
			R.SetRotation(*m_ptrRotation);
			RTS *= R;
		}

		if (m_ptrTranslation)
		{
			T.SetTranslation(*m_ptrTranslation);
			RTS *= T;
		}

		if (m_ptrScale)
		{
			S.SetScale(*m_ptrScale);
			RTS *= S;
		}

		return RTS;
	}


	// operators
	Transform3& Transform3::operator*= (const Transform3 &_mat)
	{
		*this = Transform3(*this * _mat);

		return *this;
	}

	Transform3 Transform3::operator* (const Transform3 &_mat) const
	{
		Transform3 result(GetMatrix() * _mat.GetMatrix());

		return result;
	}

	Transform3& Transform3::operator = (const Transform3 &_mat)
	{
		Matrix33* tempRotation = NULL;
		Vector3* tempTranslation = NULL;
		Vector3* tempScale = NULL;

		if (_mat.m_ptrTranslation)
		{
			if (m_ptrTranslation)
			{
				delete m_ptrTranslation;
			}

			tempTranslation = new Vector3;

			tempTranslation->SetX(_mat.m_ptrTranslation->GetX());
			tempTranslation->SetY(_mat.m_ptrTranslation->GetY());
			tempTranslation->SetZ(_mat.m_ptrTranslation->GetZ());
		}

		if (_mat.m_ptrScale)
		{
			if (m_ptrScale)
			{
				delete m_ptrScale;
			}

			tempScale = new Vector3;

			tempScale->SetX(_mat.m_ptrScale->GetX());
			tempScale->SetY(_mat.m_ptrScale->GetY());
			tempScale->SetZ(_mat.m_ptrScale->GetZ());
		}

		if (_mat.m_ptrRotation)
		{
			if (m_ptrRotation)
			{
				delete m_ptrRotation;
			}

			tempRotation = new Matrix33(*_mat.m_ptrRotation);
		}

		m_ptrRotation = tempRotation;
		m_ptrTranslation = tempTranslation;
		m_ptrScale = tempScale;

		return *this;
	}

	bool Transform3::operator== (const Transform3 &_mat) const
	{
		return ((m_ptrRotation == NULL || *m_ptrRotation == *_mat.m_ptrRotation) && (m_ptrTranslation == NULL || *m_ptrTranslation == *_mat.m_ptrTranslation) && (m_ptrScale == NULL || *m_ptrScale == *_mat.m_ptrScale));
	}

	bool Transform3::operator!= (const Transform3 &_mat) const
	{
		return !((m_ptrRotation == NULL || *m_ptrRotation == *_mat.m_ptrRotation) && (m_ptrTranslation == NULL || *m_ptrTranslation == *_mat.m_ptrTranslation) && (m_ptrScale == NULL || *m_ptrScale == *_mat.m_ptrScale));
	}

	Vector4 Transform3::operator* (const Vector4& _v)
	{
		Matrix44 tempRTS = GetMatrix();

		if (_v.GetW() != 0.f)
		{
			return Vector4(tempRTS * _v);
		}

		if (tempRTS.Inverse())
		{
			tempRTS.Transpose();

			return Vector4(GetMatrix() * _v);
		}

		return VECTOR4ZERO;
	}


	// debug function
	ostream &operator<< (ostream& _out, const Transform3 &_v)
	{
		_out << "Transform3 : " << endl << endl;

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

	istream &operator>> (istream& _in, Transform3 &_v)
	{
		cout << "Matrice Transform3 :" << endl << endl;
		cout << "1) Rotation : " << endl;

		if (!_v.m_ptrRotation)
		{
			_v.m_ptrRotation = new Matrix33;
		}

		_in >> *_v.m_ptrRotation;


		cout << "2) Translation : " << endl;

		if (!_v.m_ptrTranslation)
		{
			_v.m_ptrTranslation = new Vector3;
		}

		_in >> *_v.m_ptrTranslation;


		cout << "3) Scale : " << endl;

		if (!_v.m_ptrScale)
		{
			_v.m_ptrScale = new Vector3;
		}

		_in >> *_v.m_ptrScale;


		return _in;
	}


	void Transform3::Display() const
	{
		cout << *this;
	}
}