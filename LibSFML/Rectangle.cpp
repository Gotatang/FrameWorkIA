/*Documentation									*/
/*@author	:	Quentin Ladevie					*/
/*@file		:	Rectangle.cpp					*/
/*@date		:	08/12/2015						*/
/*@brief	:	Fichier sources des rectangles	*/
#include "stdafx.h"
#include "Rectangle.hpp"


namespace DadEngine
{
	Rectangle::Rectangle(float _fWidth, float _fHeight) : Shape2D(POINT2ORIGIN, Point2(-_fWidth / 2.f, -_fHeight / 2.f), MATRIX22IDENTITY), m_fWidth(_fWidth), m_fHeight(_fHeight)
	{}

	Rectangle::Rectangle(const Point2& _pPosition, float _fWidth, float _fHeight) : Shape2D(Point2(_pPosition.GetX() + _fWidth / 2.f, _pPosition.GetY() + _fHeight / 2.f), _pPosition, MATRIX22IDENTITY), m_fWidth(_fWidth), m_fHeight(_fHeight)
	{}

	Rectangle::Rectangle(const Point2& _pOrigin, const Point2& _pPosition, const Matrix22& _mDirection, float _fWidth, float _fHeight) : Shape2D(_pOrigin, _pPosition, _mDirection), m_fWidth(_fWidth), m_fHeight(_fHeight)
	{}


	Rectangle::~Rectangle()
	{}


	// Get/Set
	Point2 Rectangle::GetPoint(int _iIndex) const
	{
		_iIndex %= RECTANGLE_POINT_COUNT;

		if (_iIndex < RECTANGLE_POINT_COUNT)
		{
			Point2 pSeekedPoint;

			pSeekedPoint.SetX(m_pPosition.GetX() + ((_iIndex & 1) * m_fWidth));
			pSeekedPoint.SetY(m_pPosition.GetY() + ((_iIndex >> 1) * m_fHeight));

			return pSeekedPoint;
		}

		return Point2();
	}

	int Rectangle::GetPointCount()
	{
		return RECTANGLE_POINT_COUNT;
	}


	float Rectangle::GetWidth() const
	{
		return m_fWidth;
	}

	float Rectangle::GetHeight() const
	{
		return m_fHeight;
	}

	void Rectangle::SetWidth(float _fWidth)
	{
		m_fWidth = _fWidth;
	}

	void Rectangle::SetHeight(float _fHeight)
	{
		m_fHeight = _fHeight;
	}


	// Display
	void Rectangle::Draw(SFTexture* _applyedTexture)
	{
		if (_applyedTexture)
		{
			sf::VertexArray rectangle(sf::PrimitiveType::Quads, GetPointCount());


			rectangle[0].position.x = GetPoint(0).GetX();
			rectangle[0].position.y = GetPoint(0).GetY();
			rectangle[1].position.x = GetPoint(1).GetX();
			rectangle[1].position.y = GetPoint(1).GetY();
			rectangle[2].position.x = GetPoint(3).GetX();
			rectangle[2].position.y = GetPoint(3).GetY();
			rectangle[3].position.x = GetPoint(2).GetX();
			rectangle[3].position.y = GetPoint(2).GetY();

			rectangle[0].texCoords.x = 0.f;
			rectangle[0].texCoords.y = 0.f;
			rectangle[1].texCoords.x = _applyedTexture->GetSize().GetX();
			rectangle[1].texCoords.y = 0.f;
			rectangle[2].texCoords.x = _applyedTexture->GetSize().GetX();
			rectangle[2].texCoords.y = _applyedTexture->GetSize().GetY();
			rectangle[3].texCoords.x = 0.f;
			rectangle[3].texCoords.y = _applyedTexture->GetSize().GetY();

			GameManager::GetInstance()->GetWnd()->draw(rectangle, &_applyedTexture->GetTexture());

#ifdef		_DEBUG

			sf::VertexArray rectangleDebug(sf::PrimitiveType::LinesStrip, GetPointCount() + 1);

			rectangleDebug[0].position.x = GetPoint(0).GetX();
			rectangleDebug[0].position.y = GetPoint(0).GetY();
			rectangleDebug[1].position.x = GetPoint(1).GetX();
			rectangleDebug[1].position.y = GetPoint(1).GetY();
			rectangleDebug[2].position.x = GetPoint(3).GetX();
			rectangleDebug[2].position.y = GetPoint(3).GetY();
			rectangleDebug[3].position.x = GetPoint(2).GetX();
			rectangleDebug[3].position.y = GetPoint(2).GetY();
			rectangleDebug[4].position.x = GetPoint(4).GetX();
			rectangleDebug[4].position.y = GetPoint(4).GetY();

			GameManager::GetInstance()->GetWnd()->draw(rectangleDebug);
#endif

			return;
		}

		// When there is no texture
		sf::VertexArray rectangle(sf::PrimitiveType::LinesStrip, GetPointCount() + 1);

		rectangle[0].position.x = GetPoint(0).GetX();
		rectangle[0].position.y = GetPoint(0).GetY();
		rectangle[1].position.x = GetPoint(1).GetX();
		rectangle[1].position.y = GetPoint(1).GetY();
		rectangle[2].position.x = GetPoint(3).GetX();
		rectangle[2].position.y = GetPoint(3).GetY();
		rectangle[3].position.x = GetPoint(2).GetX();
		rectangle[3].position.y = GetPoint(2).GetY();
		rectangle[4].position.x = GetPoint(4).GetX();
		rectangle[4].position.y = GetPoint(4).GetY();

		GameManager::GetInstance()->GetWnd()->draw(rectangle);
	}

	void Rectangle::Draw(sf::Color _applyedColor)
	{
		sf::VertexArray rectangle(sf::PrimitiveType::Quads, GetPointCount());

		rectangle[0].position.x = GetPoint(0).GetX();
		rectangle[0].position.y = GetPoint(0).GetY();
		rectangle[1].position.x = GetPoint(1).GetX();
		rectangle[1].position.y = GetPoint(1).GetY();
		rectangle[2].position.x = GetPoint(3).GetX();
		rectangle[2].position.y = GetPoint(3).GetY();
		rectangle[3].position.x = GetPoint(2).GetX();
		rectangle[3].position.y = GetPoint(2).GetY();

		
		rectangle[0].color = _applyedColor;
		rectangle[1].color = _applyedColor;
		rectangle[2].color = _applyedColor;
		rectangle[3].color = _applyedColor;

		GameManager::GetInstance()->GetWnd()->draw(rectangle);
	}


	// Debug
	void Rectangle::Display() const
	{
		cout << *this;
	}

	ostream& operator<< (ostream& _out, const Rectangle& _r)
	{
		Shape2D* s = (Shape2D*)&_r;

		cout << "Membres Shape 2D : " << *s << endl;
		cout << "Largeur : " << _r.m_fWidth << endl;
		cout << "Hauteur : " << _r.m_fHeight << endl;

		return _out;
	}
}