/*Documentation															*/
/*@author	:	Quentin Ladevie											*/
/*@file		:	Vector2.hpp												*/
/*@date		:	19/11/2015												*/
/*@brief	:	Fichier d'en-tête des vecteurs à 2 Dimensions			*/
#ifndef __VECTOR2_H_
#define __VECTOR2_H_

#include "ExportMath.hpp"
#include <iostream>
#include "Matrix22.hpp"


using std::ostream;
using std::istream;

namespace DadEngine
{
	class DADENGINE_MATHAPI Vector2
	{

	public:

		Vector2();
		Vector2(const Vector2& _copy);
		Vector2(float _fX, float _fY);

		~Vector2();


		// Set/Get functions
		void SetX(float _fX);
		void SetY(float _fY);

		float GetX() const;
		float GetY() const;


		// Handling functions
		static Vector2 Lerp(const Vector2 _from, const Vector2 _to, float _step);
		void Scale(float _fScaleFactor);
		void Translate(float _fX, float _fY);
		void Display() const;
		float Length() const;
		bool IsNullByEpsilon() const;
		bool IsUnitByEpsilon() const;
		bool Normalize();
		float Dot(const Vector2 &_vector1) const;
		float Angle(const Vector2 &_vector1) const;


		// Assignement operators
		Vector2& operator+= (const Vector2& _v);
		Vector2& operator-= (const Vector2& _v);
		Vector2& operator*= (float _f);
		Vector2& operator/= (float _f);


		// Unary operators
		Vector2 operator+ () const;
		Vector2 operator- () const;


		// Binary operators
		Vector2 operator+ (const Vector2& _v) const;
		Vector2 operator- (const Vector2& _v) const;
		Vector2 operator* (float _f) const;
		Vector2 operator/ (float _f) const;


		bool operator== (const Vector2& _v) const;
		bool operator!= (const Vector2& _v) const;


		// DADENGINE_MATHAPI friends operators
		DADENGINE_MATHAPI friend Vector2 operator* (float _f, const Vector2& _v);
		DADENGINE_MATHAPI friend ostream& operator <<(ostream& _o, const Vector2& _v);
		DADENGINE_MATHAPI friend istream& operator >>(istream& _i, Vector2& _v);

		// Freinds with other class
		DADENGINE_MATHAPI friend Vector2 operator* (const Vector2& _v, const Matrix22&_mat);


	private:

		float m_fX;
		float m_fY;
	};


	const Vector2 VECTOR2ZERO(0.f, 0.f);
	const Vector2 VECTOR2ONE(1.f, 1.f);

}

#endif // __VECTOR2_H_
