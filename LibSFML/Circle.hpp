/*Documentation									*/
/*@author	:	Quentin Ladevie					*/
/*@file		:	Circle.hpp						*/
/*@date		:	08/12/2015						*/
/*@brief	:	Fichier d'en-tête des cercles	*/
#ifndef __CIRCLE_H_
#define __CIRCLE_H_

#include "ExportSFML.hpp"
#include "Shape2D.hpp"


namespace DadEngine
{
	class DADENGINE_SFMLAPI Circle : public Shape2D
	{

	public:

		Circle(float _fRadius = 1.f, int _iCountPoint = 10);
		Circle(const Point2& _pPosition, float _fRadius = 1.f, int _iCountPoint = 10);
		Circle(const Point2& _pOrigin, const Point2& _pPosition, const Matrix22& _mDirection, float _fRadius = 1.f, int _iCountPoint = 10);


		// Get/Set
		virtual Point2 GetPoint(int _iIndex) const override;
		virtual int GetPointCount() override;

		float GetRadius() const;

		void SetRadius(float _fradius);


		// Display
		virtual void Draw(SFTexture* _applyedTexture = NULL);

		// Debug
		virtual void Display() const;

		DADENGINE_SFMLAPI friend ostream& operator<< (ostream& _out, const Circle& _c);


	private:

		float m_fRadius;
		int m_iPointCount;
	};
}

#endif // __CIRCLE_H_