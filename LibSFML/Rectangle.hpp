/*Documentation										*/
/*@author	:	Quentin Ladevie						*/
/*@file		:	Rectangle.hpp						*/
/*@date		:	08/12/2015							*/
/*@brief	:	Fichier d'en-tête des rectangles	*/
#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_

#include "ExportSFML.hpp"
#include "Shape2D.hpp"
#include "SFML\Graphics.hpp"

#define RECTANGLE_POINT_COUNT 4


namespace DadEngine
{
	class DADENGINE_SFMLAPI Rectangle : public Shape2D
	{

	public:

		Rectangle(float _fWidth = 1.f, float _fHeight = 1.f);
		Rectangle(const Point2& _pPosition, float _fWidth = 1.f, float _fHeight = 1.f);
		Rectangle(const Point2& _pOrigin, const Point2& _pPosition, const Matrix22& _mDirection, float _fWidth = 1.f, float _fHeight = 1.f);

		virtual ~Rectangle();


		// Get/Set
		virtual Point2 GetPoint(int _iIndex) const override;
		virtual int GetPointCount() override;


		float GetWidth() const;
		float GetHeight() const;

		void SetWidth(float _fWidth);
		void SetHeight(float _fHeight);


		// Display
		virtual void Draw(SFTexture* _applyedTexture = NULL);
		virtual void Draw(sf::Color _applyedColor);


		// Debug
		virtual void Display() const;

		DADENGINE_SFMLAPI friend ostream& operator<< (ostream& _out, const Rectangle& _r);


	private:

		float m_fWidth, m_fHeight;

	};
}

#endif // __RECTANGLE_H_