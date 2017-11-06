/*Documentation													*/
/*@author	:	Quentin Ladevie									*/
/*@file		:	Shape3D.hpp										*/
/*@date		:	08/12/2015										*/
/*@brief	:	Fichier d'en-tête des shapes en 3 dimensions	*/
#ifndef __SHAPE3D_H_
#define __SHAPE3D_H_

#include "ExportSFML.hpp"
#include "Shape.hpp"


namespace DadEngine
{
	class DADENGINE_SFMLAPI Shape3D : public Shape
	{

	public:

		Shape3D();
		Shape3D(Point3 _pOrigin, Point3 _pPosition, Matrix33 _mDirection);

		virtual ~Shape3D();


		// Get/Set
		virtual Point3 GetPoint(int _iIndex) const = 0;
		virtual int GetPointCount() = 0;


		Point3 GetOrigin() const;
		Point3 GetPosition() const;
		Matrix33 GetDirection() const;

		void SetOrigin(Point3& _pNewOrigin);
		void SetPosition(Point3& _pNewPosition);
		void SetDirection(Matrix33& _mNewDirection);


		// Display
		virtual void Draw(sf::RenderWindow* _wnd) = 0;


		// Debug
		virtual void Display() const = 0;

		DADENGINE_SFMLAPI friend ostream& operator<< (ostream& _out, const Shape3D& _s);


	protected:

		Point3 m_pOrigin;
		Point3 m_pPosition;
		Matrix33 m_mDirection;
	};
}

#endif // __SHAPE3D_H_