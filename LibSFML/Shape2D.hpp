/*Documentation													*/
/*@author	:	Quentin Ladevie									*/
/*@file		:	Shape2D.hpp										*/
/*@date		:	08/12/2015										*/
/*@brief	:	Fichier d'en-tête des shapes en 2 dimensions	*/
#ifndef __SHAPE2D_H_
#define __SHAPE2D_H_

#include "ExportSFML.hpp"
#include "Shape.hpp"
#include "Point2.hpp"
#include "Matrix22.hpp"
#include <iostream>

using std::ostream;


namespace DadEngine
{
	class SFTexture;

	class DADENGINE_SFMLAPI Shape2D : public Shape
	{

	public:

		Shape2D();
		Shape2D(const Point2& _pOrigin, const Point2& _pPosition, const Matrix22& _mDirection);

		virtual ~Shape2D();


		// Get/Set
		virtual Point2 GetPoint(int _iIndex) const = 0;
		virtual int GetPointCount() = 0;

		Point2 GetOrigin() const;
		Point2 GetPosition() const;
		Matrix22 GetDirection() const;

		void SetOrigin(Point2& _pNewOrigin);
		void SetPosition(Point2& _pNewPosition);
		void SetDirection(Matrix22& _mNewDirection);


		// Display
		virtual void Draw(SFTexture* _applyedTexture = NULL) = 0;


		// Debug
		virtual void Display() const = 0;

		DADENGINE_SFMLAPI friend ostream& operator<< (ostream& _out, const Shape2D& _s);


	protected:

		Point2 m_pOrigin;
		Point2 m_pPosition;
		Matrix22 m_mDirection;
	};
}

#endif // __SHAPE2D_H_