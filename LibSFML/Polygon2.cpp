/*Documentation													*/
/*@author	:	Quentin Ladevie									*/
/*@file		:	Polygon2.cpp									*/
/*@date		:	08/12/2015										*/
/*@brief	:	Fichier source des polygones en 2 dimensions	*/
#include "stdafx.h"
#include "Polygon2.hpp"


namespace DadEngine
{
	Polygon2::Polygon2(int _iPointCount) : Shape2D(), m_iPointCount(_iPointCount), m_ptrpPoints(NULL)
	{
		if (m_iPointCount)
		{
			m_ptrpPoints = new Point2[m_iPointCount];
		}
	}

	Polygon2::Polygon2(Point2& _pOrigin, Point2& _pPosition, Matrix22& _mDirection, int _iPointCount) : Shape2D(_pOrigin, _pPosition, _mDirection), m_iPointCount(_iPointCount), m_ptrpPoints(NULL)
	{
		if (m_iPointCount)
		{
			m_ptrpPoints = new Point2[m_iPointCount];
		}
	}

	Polygon2::Polygon2(const Polygon2& _p)
	{
		m_iPointCount = _p.m_iPointCount;

		m_ptrpPoints = new Point2[m_iPointCount];

		for (int i = 0; i < m_iPointCount; ++i)
		{
			m_ptrpPoints[i] = _p.m_ptrpPoints[i];
		}
	}


	Polygon2::~Polygon2()
	{
		if (m_ptrpPoints)
		{
			delete[] m_ptrpPoints;
			m_ptrpPoints = NULL;
		}
	}


	// Get/Set
	Point2 Polygon2::GetPoint(int _iIndex) const
	{
		if (_iIndex < m_iPointCount)
		{
			return m_ptrpPoints[_iIndex];
		}

		return Point2();
	}

	void Polygon2::SetPoint(const Point2& _pNewPoint, int _iIndex)
	{
		if (_iIndex < m_iPointCount)
		{
			m_ptrpPoints[_iIndex] = _pNewPoint;
		}
	}


	int Polygon2::GetPointCount()
	{
		return m_iPointCount;
	}

	void Polygon2::SetPointCount(int _iNewSize)
	{
		// Init new points
		Point2* ptrpTempPoints = NULL;

		m_iPointCount = _iNewSize;

		ptrpTempPoints = new Point2[_iNewSize];

		for (int i = 0; i < m_iPointCount; ++i)
		{
			ptrpTempPoints[i] = m_ptrpPoints[i];
		}

		delete m_ptrpPoints;
		m_ptrpPoints = ptrpTempPoints;
	}


	// Operators
	Polygon2& Polygon2::operator= (const Polygon2& _p)
	{
		m_iPointCount = _p.m_iPointCount;

		m_ptrpPoints = new Point2[m_iPointCount];

		for (int i = 0; i < m_iPointCount; ++i)
		{
			m_ptrpPoints[i] = _p.m_ptrpPoints[i];
		}

		return *this;
	}


	// Display
	void Polygon2::Draw(SFTexture* _applyedTexture)
	{

	}


	// Debug
	void Polygon2::Display() const
	{
		cout << *this;
	}

	ostream& operator<< (ostream& _out, const Polygon2& _p)
	{
		Shape2D* s = (Shape2D*)&_p;

		_out << "Membres Shape 2D : " << *s << endl;

		return _out;
	}
}