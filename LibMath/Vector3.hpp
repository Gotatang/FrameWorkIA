/*Documentation															*/
/*@author	:	Quentin Ladevie											*/
/*@file		:	Vector3.hpp												*/
/*@date		:	19/11/2015												*/
/*@brief	:	Fichier d'en-tête des vecteurs à 3 Dimensions			*/
#ifndef __VECTOR3_H_
#define __VECTOR3_H_

#include "ExportMath.hpp"


namespace DadEngine
{
	class Matrix33;

	class DADENGINE_MATHAPI Vector3
	{

	public:

		Vector3();
		Vector3(const Vector3& _copy);
		Vector3(float _fX, float _fY, float _fZ);
		Vector3(Vector2& _v);

		~Vector3();


		// Set/Get functions
		void SetX(float _fX);
		void SetY(float _fY);
		void SetZ(float _fZ);

		float GetX() const;
		float GetY() const;
		float GetZ() const;


		// Handling functions
		static Vector3 Lerp(const Vector3 _from, const Vector3 _to, float _step);
		void Scale(float _fScaleFactor);
		void Translate(float _fX, float _fY, float _fZ);
		void Display() const;
		float Length() const;
		bool IsNullByEpsilon() const;
		bool IsUnitByEpsilon() const;
		bool Normalize();
		float Dot(const Vector3 &_vector1) const;
		float Angle(const Vector3 &_vector1) const;
		Vector3 Cross(const Vector3 &_vector1) const;


		// Assignement operators
		Vector3& operator+= (const Vector3& _v);
		Vector3& operator-= (const Vector3& _v);
		Vector3& operator*= (float _f);
		Vector3& operator/= (float _f);


		// Unary operators
		Vector3 operator+ () const;
		Vector3 operator- () const;


		// Binary operators
		Vector3 operator+ (const Vector3& _v) const;
		Vector3 operator- (const Vector3& _v) const;
		Vector3 operator* (float _f) const;
		Vector3 operator/ (float _f) const;


		bool operator== (const Vector3& _v) const;
		bool operator!= (const Vector3& _v) const;


		// DADENGINE_MATHAPI friends operators
		DADENGINE_MATHAPI friend Vector3 operator* (float _f, const Vector3& _v);
		DADENGINE_MATHAPI friend ostream& operator <<(ostream& _o, const Vector3& _v);
		DADENGINE_MATHAPI friend istream& operator >>(istream& _i, Vector3& _v);

		// DADENGINE_MATHAPI friend with other class
		DADENGINE_MATHAPI friend Vector3 operator* (const Vector3& _v, const Matrix33 &_mat);


	private:

		float m_fX;
		float m_fY;
		float m_fZ;
	};

	const Vector3 VECTOR3ZERO(0.f, 0.f, 0.f);
	const Vector3 VECTOR3ONE(1.f, 1.f, 1.f);

}

#endif // __VECTOR3_H_m