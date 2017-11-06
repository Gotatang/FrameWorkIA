/*Documentation														*/
/*@author	:	Quentin Ladevie										*/
/*@file		:	Point2.hpp											*/
/*@date		:	19/11/2015											*/
/*@brief	:	Fichier d'en-tête des points à 2 Dimensions			*/
#ifndef __POINT2_H_
#define __POINT2_H_

#include <ostream>
#include <istream>
#include "ExportMath.hpp"

using std::ostream;
using std::istream;


namespace DadEngine
{
	class DADENGINE_MATHAPI Point2
	{

	public:

		Point2();
		Point2(const Point2& _copy);
		Point2(float _fX, float _fY);

		~Point2();


		// Set/Get functions
		void SetX(float _fX);
		void SetY(float _fY);

		float GetX() const;
		float GetY() const;


		// Handling functions
		Point2 Lerp(const Point2 _to, float _step) const;
		void Translate(float _fX, float _fY);
		void Display() const;


		// Assignement operators
		Point2& operator+= (const Point2& _p);
		Point2& operator-= (const Point2& _p);
		Point2& operator*= (float _f);
		Point2& operator/= (float _f);


		// Unary operators
		Point2 operator+ () const;
		Point2 operator- () const;


		// Binary operators
		Point2 operator+ (const Point2& _p) const;
		Point2 operator- (const Point2& _p) const;
		Point2 operator* (float _f) const;
		Point2 operator/ (float _f) const;


		bool operator== (const Point2& _p) const;
		bool operator!= (const Point2& _p) const;


		// DADENGINE_MATHAPI friends operators
		DADENGINE_MATHAPI friend Point2 operator* (float _f, const Point2& _p);
		DADENGINE_MATHAPI friend ostream& operator <<(ostream& _o, const Point2& _p);
		DADENGINE_MATHAPI friend istream& operator >>(istream& _i, Point2& _p);


	private:

		float m_fX;
		float m_fY;
	};



	// Get/Set funtions
	inline void Point2::SetX(float _x)
	{
		m_fX = _x;
	}

	inline void Point2::SetY(float _y)
	{
		m_fY = _y;
	}


	inline float Point2::GetX() const
	{
		return m_fX;
	}

	inline float Point2::GetY() const
	{
		return m_fY;
	}


	const Point2 POINT2ORIGIN(0.f, 0.f);

}

#endif // __POINT2_H_