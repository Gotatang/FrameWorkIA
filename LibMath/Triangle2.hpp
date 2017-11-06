/*Documentation															*/
/*@author	:	Quentin Ladevie											*/
/*@file		:	Triangle2.hpp											*/
/*@date		:	19/11/2015												*/
/*@brief	:	Fichier d'en-tête des triangles en 2 Dimensions			*/
#ifndef __TRIANGLE2_H_
#define __TRIANGLE2_H_

#include "ExportMath.hpp"


namespace DadEngine
{
	class DADENGINE_MATHAPI Triangle2
	{

	public:

		Triangle2();
		Triangle2(Point2 _p1, Point2 _p2, Point2 _p3);
		~Triangle2();

		// Set/Get
		inline void SetPoint(unsigned int _iIndex, const Point2& _newPoint);
		inline Point2 GetPoint(unsigned int _uiIndex) const;


		Triangle2 Display() const;


		// Unary operators
		Triangle2 operator+ () const;
		Triangle2 operator- () const;


		// Binary operators
		bool operator== (const Triangle2& _t) const;
		bool operator!= (const Triangle2& _t) const;


		// DADENGINE_MATHAPI friends operators
		DADENGINE_MATHAPI friend ostream& operator <<(ostream& _o, const Triangle2& _t);
		DADENGINE_MATHAPI friend istream& operator >>(istream& _i, Triangle2& _t);


	private:

		Point2 m_aPoints[3];
	};
}

#endif // __TRIANGLE2_H_