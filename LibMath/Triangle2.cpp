/*Documentation													*/
/*@author	:	Quentin Ladevie									*/
/*@file		:	Triangle2.cpp									*/
/*@date		:	19/11/2015										*/
/*@brief	:	Fichier source des triangles en 2 Dimensions	*/
#include "stdafx.h"
#include "Triangle2.hpp"


namespace DadEngine
{
	Triangle2::Triangle2()
	{}

	Triangle2::Triangle2(Point2 _p1, Point2 _p2, Point2 _p3)
	{
		m_aPoints[0] = _p1;
		m_aPoints[1] = _p2;
		m_aPoints[2] = _p3;
	}


	Triangle2::~Triangle2()
	{}


	// Set/Get
	inline void Triangle2::SetPoint(unsigned int _uiIndex, const Point2& _newPoint)
	{
		m_aPoints[_uiIndex] = _newPoint;
	}

	inline Point2 Triangle2::GetPoint(unsigned int _uiIndex) const
	{
		return m_aPoints[_uiIndex];
	}


	Triangle2 Triangle2::Display() const
	{
		cout << " Point 1 " << endl << endl;;
		m_aPoints[0].Display();
		cout << endl;

		cout << " Point 2 " << endl << endl;
		m_aPoints[1].Display();
		cout << endl;

		cout << " Point 3 " << endl << endl;
		m_aPoints[2].Display();
		cout << endl;

		return *this;
	}


	// Unary operators
	Triangle2 Triangle2::operator+ () const
	{
		Triangle2 result(+m_aPoints[0], +m_aPoints[1], +m_aPoints[2]);

		return result;
	}

	Triangle2 Triangle2::operator- () const
	{
		Triangle2 result(-m_aPoints[0], -m_aPoints[1], -m_aPoints[2]);

		return result;
	}


	// Binary operators
	bool Triangle2::operator== (const Triangle2& _t) const
	{
		return (m_aPoints[0] == _t.m_aPoints[0] && m_aPoints[1] == _t.m_aPoints[1] && m_aPoints[2] == _t.m_aPoints[2]);
	}

	bool Triangle2::operator!= (const Triangle2& _t) const
	{
		return (m_aPoints[0] != _t.m_aPoints[0] || m_aPoints[1] != _t.m_aPoints[1] || m_aPoints[2] != _t.m_aPoints[2]);
	}


	// DADENGINE_MATHAPI friends operators
	ostream& operator <<(ostream& _o, const Triangle2& _t)
	{
		_o << "Point1 : " << _t.m_aPoints[0] << endl << "Point2 : " << _t.m_aPoints[1] << "Point3 : " << _t.m_aPoints[2] << endl << endl;

		return _o;
	}

	istream& operator >>(istream& _i, Triangle2& _t)
	{
		cout << "Point1 : ";
		_i.clear();
		_i.sync();
		_i >> _t.m_aPoints[0];
		cout << endl;

		cout << "Point2 : ";
		_i.clear();
		_i.sync();
		_i >> _t.m_aPoints[1];
		cout << endl;

		cout << "Point3 : ";
		_i.clear();
		_i.sync();
		_i >> _t.m_aPoints[2];
		cout << endl;

		return _i;
	}
}