/*Documentation													*/
/*@author	:	Quentin Ladevie									*/
/*@file		:	Triangle3.cpp									*/
/*@date		:	19/11/2015										*/
/*@brief	:	Fichier source des triangles en 3 Dimensions	*/
#include "stdafx.h"
#include "Triangle3.hpp"


namespace DadEngine
{
	unsigned int Triangle3::s_uiEntityCount = 0;

	Triangle3::Triangle3()
	{
		++s_uiEntityCount;

		cout << "Nombre de triangles alloués : " << s_uiEntityCount << endl << endl;
	}

	Triangle3::Triangle3(const Triangle3& _copy)
	{
		*this = _copy;

		++s_uiEntityCount;

		cout << "Nombre de triangles alloués : " << s_uiEntityCount << endl << endl;
	}

	Triangle3::Triangle3(Point3 _p1, Point3 _p2, Point3 _p3)
	{
		m_aPoints[0] = _p1;
		m_aPoints[1] = _p2;
		m_aPoints[2] = _p3;

		++s_uiEntityCount;

		cout << "Nombre de triangles alloués : " << s_uiEntityCount << endl << endl;
	}


	Triangle3::~Triangle3()
	{
		--s_uiEntityCount;

		cout << "Nombre de triangles alloués : " << s_uiEntityCount << endl << endl;
	}


	// Get/Set
	inline void Triangle3::SetPoint(unsigned int _uiIndex, const Point3& _newPoint)
	{
		m_aPoints[_uiIndex] = _newPoint;
	}

	inline Point3 Triangle3::GetPoint(unsigned int _uiIndex) const
	{
		return m_aPoints[_uiIndex];
	}


	unsigned int Triangle3::GetTriangles3Count()
	{
		return s_uiEntityCount;
	}



	Triangle3 Triangle3::Display() const
	{
		cout << " Point 1 " << endl << endl;
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
	Triangle3 Triangle3::operator+ () const
	{
		Triangle3 result(+m_aPoints[0], +m_aPoints[1], +m_aPoints[2]);

		return result;
	}

	Triangle3 Triangle3::operator- () const
	{
		Triangle3 result(m_aPoints[0], -m_aPoints[1], -m_aPoints[2]);

		return result;
	}


	// Binary operators
	bool Triangle3::operator== (const Triangle3& _t) const
	{
		return (m_aPoints[0] == _t.m_aPoints[0] && m_aPoints[1] == _t.m_aPoints[1] && m_aPoints[2] == _t.m_aPoints[2]);
	}

	bool Triangle3::operator!= (const Triangle3& _t) const
	{
		return (m_aPoints[0] != _t.m_aPoints[0] || m_aPoints[1] != _t.m_aPoints[1] || m_aPoints[2] != _t.m_aPoints[2]);
	}


	// DADENGINE_MATHAPI friends operators
	ostream& operator <<(ostream& _o, const Triangle3& _t)
	{
		_o << "Point1 : " << _t.m_aPoints[0] << endl << "Point2 : " << _t.m_aPoints[1] << "Point3 : " << _t.m_aPoints[2] << endl << endl;

		return _o;
	}

	istream& operator >>(istream& _i, Triangle3& _t)
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