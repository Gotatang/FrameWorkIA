/*Documentation														*/
/*@author	:	Quentin Ladevie										*/
/*@file		:	Point3.hpp											*/
/*@date		:	19/11/2015											*/
/*@brief	:	Fichier d'en-tête des points à 3 Dimensions			*/
#ifndef __POINT3_H_
#define __POINT3_H_

#include "ExportMath.hpp"

namespace DadEngine
{
	class DADENGINE_MATHAPI Point3
	{

	public:

		Point3();
		Point3(const Point3& _copy);
		Point3(float _fX, float _fY, float _fZ);

		~Point3();


		// Set/Get functions
		void SetX(float _fX);
		void SetY(float _fY);
		void SetZ(float _fZ);

		float GetX() const;
		float GetY() const;
		float GetZ() const;


		// Handling functions
		Point3 Lerp(const Point3 _to, float _step) const;
		void Translate(float _fX, float _fY, float _fZ);
		void Display() const;


		// Assignement operators
		Point3& operator+= (const Point3& _p);
		Point3& operator-= (const Point3& _p);
		Point3& operator*= (float _f);
		Point3& operator/= (float _f);


		// Unary operators
		Point3 operator+ () const;
		Point3 operator- () const;


		// Binary operators
		Point3 operator+ (const Point3& _p) const;
		Point3 operator- (const Point3& _p) const;
		Point3 operator* (float _f) const;
		Point3 operator/ (float _f) const;


		bool operator== (const Point3& _p) const;
		bool operator!= (const Point3& _p) const;


		// friends operators
		DADENGINE_MATHAPI friend Point3 operator* (float _f, const Point3& _p);
		DADENGINE_MATHAPI friend ostream& operator <<(ostream& _o, const Point3& _p);
		DADENGINE_MATHAPI friend istream& operator >>(istream& _i, Point3& _p);


	private:

		float m_fX;
		float m_fY;
		float m_fZ;
	};

	const Point3 POINT3ORIGIN(0.f, 0.f, 0.f);

}

#endif // __POINT2_H_