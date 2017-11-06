/*Documentation													*/
/*@author	:	Quentin Ladevie									*/
/*@file		:	Polygon3.cpp									*/
/*@date		:	10/12/2015										*/
/*@brief	:	Fichier source des polygones en 3 dimensions	*/
#include "stdafx.h"
#include "Polygon3.hpp"


namespace DadEngine
{
	Polygon3::Polygon3(int _iPointCount) : Shape3D(), m_iPointCount(_iPointCount)
	{
		if (m_iPointCount)
		{
			m_ptrpPoints = new Point3[m_iPointCount];
		}
	}

	Polygon3::Polygon3(const Point3& _pOrigin, Point3& _pPosition, const Matrix33& _mDirection, int _iCountPoint) : Shape3D(_pOrigin, _pPosition, _mDirection), m_iPointCount(_iCountPoint)
	{
		if (m_iPointCount)
		{
			m_ptrpPoints = new Point3[m_iPointCount];
		}
	}

	Polygon3::Polygon3(const Polygon3& _p)
	{
		m_iPointCount = _p.m_iPointCount;

		m_ptrpPoints = new Point3[m_iPointCount];

		for (int i = 0; i < m_iPointCount; ++i)
		{
			m_ptrpPoints[i] = _p.m_ptrpPoints[i];
		}
	}


	Polygon3::~Polygon3()
	{
		if (m_ptrpPoints)
		{
			delete[] m_ptrpPoints;
			m_ptrpPoints = NULL;
		}
	}


	// Get/Set
	Point3 Polygon3::GetPoint(int _iIndex) const
	{
		if (_iIndex < m_iPointCount)
		{
			return m_ptrpPoints[_iIndex];
		}

		return Point3();
	}

	void Polygon3::SetPoint(const Point3& _pNewPoint, int _iIndex)
	{
		if (_iIndex < m_iPointCount)
		{
			m_ptrpPoints[_iIndex] = _pNewPoint;
		}
	}


	int Polygon3::GetPointCount()
	{
		return m_iPointCount;
	}

	void Polygon3::SetPointCount(int _iNewSize)
	{
		// Init new points
		Point3* ptrpTempPoints = NULL;

		m_iPointCount = _iNewSize;

		ptrpTempPoints = new Point3[_iNewSize];

		for (int i = 0; i < m_iPointCount; ++i)
		{
			ptrpTempPoints[i] = m_ptrpPoints[i];
		}

		delete m_ptrpPoints;
		m_ptrpPoints = ptrpTempPoints;
	}


	// Operators
	Polygon3& Polygon3::operator = (const Polygon3& _p)
	{
		m_iPointCount = _p.m_iPointCount;

		m_ptrpPoints = new Point3[m_iPointCount];

		for (int i = 0; i < m_iPointCount; ++i)
		{
			m_ptrpPoints[i] = _p.m_ptrpPoints[i];
		}

		return *this;
	}


	// Display
	void Polygon3::Draw(sf::RenderWindow* _wnd)
	{

	}


	// Debug
	void Polygon3::Display() const
	{
		cout << *this;
	}

	ostream& operator<< (ostream& _out, const Polygon3& _p)
	{
		Shape3D* s = (Shape3D*)&_p;

		_out << "Membres Shape3D : " << *s << endl;

		return _out;
	}
}