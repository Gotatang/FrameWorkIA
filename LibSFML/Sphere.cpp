/*Documentation								*/
/*@author	:	Quentin Ladevie				*/
/*@file		:	Sphere.cpp					*/
/*@date		:	10/12/2015					*/
/*@brief	:	Fichier source des spheres	*/
#include "stdafx.h"
#include "Sphere.hpp"


namespace DadEngine
{
	Sphere::Sphere(float _fRadius, int _iCountTriangle) : m_fRadius(_fRadius), m_iCountTriangle(_iCountTriangle)
	{}

	Sphere::Sphere(const Point3& _pOrigin, const Point3& _pPosition, const Matrix33& _mDirection, float _fRadius, int _iCountTriangle) : Shape3D(_pOrigin, _pPosition, _mDirection), m_fRadius(_fRadius), m_iCountTriangle(_iCountTriangle)
	{}


	Sphere::~Sphere()
	{}


	// Get/Set
	Point3 Sphere::GetPoint(int _iIndex) const
	{
		if (_iIndex < (m_iCountTriangle - 1))
		{
			Point3 pSeekedPoint;
			int iX = _iIndex % m_iCountTriangle;
			int iY = _iIndex / m_iCountTriangle;
			float fTheta = 0.f;
			float fPhi = 0.f;
			float fCosTheta = 0.f;
			float fSinTheta = 0.f;
			float fCosPhi = 0.f;
			float fSinPhi = 0.f;

			fTheta = ((1 - ((float)iX / (m_iCountTriangle - 1))) * -C_PI) + (((float)iX / (m_iCountTriangle - 1)) * C_PI);
			fPhi = ((1 - ((float)iY / (m_iCountTriangle - 1))) * -C_PI2) + (((float)iY / (m_iCountTriangle - 1)) * C_PI2);

			fCosTheta = cos(fTheta);
			fSinTheta = sin(fTheta);
			fCosPhi = cos(fPhi);
			fSinPhi = sin(fPhi);

			pSeekedPoint.SetX(m_fRadius * fCosTheta + fCosPhi);
			pSeekedPoint.SetY(m_fRadius * fCosTheta + fSinPhi);
			pSeekedPoint.SetZ(m_fRadius * fSinTheta);
		}

		cout << "Seeking a point out a sphere !" << endl << endl;

		return Point3();
	}

	int Sphere::GetPointCount()
	{
		return m_iCountTriangle;
	}


	float Sphere::GetRadius() const
	{
		return m_fRadius;
	}

	void Sphere::SetRadius(float _fNewRadius)
	{
		m_fRadius = _fNewRadius;
	}


	// Display
	void Sphere::Draw(sf::RenderWindow* _wnd)
	{

	}


	// Debug
	void Sphere::Display() const
	{
		cout << *this;
	}

	ostream& operator<< (ostream& _out, const Sphere& _s)
	{
		Shape3D* s = (Shape3D*)&_s;

		_out << "Membres Shape3D : " << *s << endl;
		_out << "Rayon : " << _s.m_fRadius << endl;

		return _out;
	}
}