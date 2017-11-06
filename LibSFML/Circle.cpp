/*Documentation								*/
/*@author	:	Quentin Ladevie				*/
/*@file		:	Circle.cpp					*/
/*@date		:	08/12/2015					*/
/*@brief	:	Fichier source des cercles	*/
#include "stdafx.h"
#include "Circle.hpp"


namespace DadEngine
{
	Circle::Circle(float _fRadius, int _iCountPoint) : Shape2D(), m_fRadius(_fRadius), m_iPointCount(_iCountPoint)
	{}

	Circle::Circle(const Point2& _pPosition, float _fRadius, int _iCountPoint) : Shape2D(_pPosition, _pPosition, MATRIX22IDENTITY), m_fRadius(_fRadius), m_iPointCount(_iCountPoint)
	{}

	Circle::Circle(const Point2& _pOrigin, const Point2& _pPosition, const Matrix22& _mDirection, float _fRadius, int _iCountPoint) : Shape2D(_pOrigin, _pPosition, _mDirection), m_fRadius(_fRadius), m_iPointCount(_iCountPoint)
	{}


	// Get/Set
	Point2 Circle::GetPoint(int _iIndex) const
	{
		_iIndex %= m_iPointCount;

		if (_iIndex < m_iPointCount)
		{
			float fAngle = LERP(-C_PI, C_PI, (1.f / m_iPointCount) * _iIndex) - (30.f /180.f) * C_PI;	// Add 30° to get a straight shape in case of low point count

			Point2 position(m_pOrigin.GetX() + (cos(fAngle) * m_fRadius), m_pOrigin.GetY() + (sin(fAngle) * m_fRadius));

			return position;
		}

		return Point2();
	}

	int Circle::GetPointCount()
	{
		return m_iPointCount;
	}


	float Circle::GetRadius() const
	{
		return m_fRadius;
	}


	void Circle::SetRadius(float _fRadius)
	{
		m_fRadius = _fRadius;
	}


	// Display
	void Circle::Draw(SFTexture* _applyedTexture)
	{
		sf::VertexArray circle(sf::PrimitiveType::LinesStrip, m_iPointCount + 1);

		for (size_t i = 0; i < (size_t) m_iPointCount + 1; ++i)
		{
			circle[i].position.x = GetPoint(i).GetX();
			circle[i].position.y = GetPoint(i).GetY();
		}

		GameManager::GetInstance()->GetWnd()->draw(circle);
	}


	// Debug
	void Circle::Display() const
	{
		cout << *this;
	}

	ostream& operator<< (ostream& _out, const Circle& _c)
	{
		Shape2D* s = (Shape2D*)&_c;

		_out << "Membres Shape 2D : " << *s << endl;
		_out << "Radius : " << _c.m_fRadius << endl;

		return _out;
	}
}