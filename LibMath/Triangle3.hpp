/*Documentation															*/
/*@author	:	Quentin Ladevie											*/
/*@file		:	Triangle3.hpp											*/
/*@date		:	19/11/2015												*/
/*@brief	:	Fichier d'en-tête des triangles en 3 Dimensions			*/
#ifndef __TRIANGLE3_H_
#define __TRIANGLE3_H_

#include "ExportMath.hpp"


namespace DadEngine
{
	class Point3;

	class DADENGINE_MATHAPI Triangle3
	{

	public:

		Triangle3();
		Triangle3(const Triangle3& _copy);
		Triangle3(Point3 _p1, Point3 _p2, Point3 _p3);

		~Triangle3();

		// Get/Set
		inline void SetPoint(unsigned int _uiIndex, const Point3& _newPoint);
		inline Point3 GetPoint(unsigned int _uiIndex) const;

		// Static
		static unsigned int GetTriangles3Count();

		Triangle3 Display() const;


		// Unary operators
		Triangle3 operator+ () const;
		Triangle3 operator- () const;


		// Binary operators
		bool operator== (const Triangle3& _t) const;
		bool operator!= (const Triangle3& _t) const;


		// DADENGINE_MATHAPI friends operators
		DADENGINE_MATHAPI friend Triangle3 operator* (float _f, const Triangle3& _t);
		DADENGINE_MATHAPI friend ostream& operator <<(ostream& _o, const Triangle3& _t);
		DADENGINE_MATHAPI friend istream& operator >>(istream& _i, Triangle3& _t);


	private:

		static unsigned int s_uiEntityCount;
		Point3 m_aPoints[3];
	};
}

#endif // __TRIANGLE3_H_