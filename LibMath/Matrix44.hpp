/*Documentation															*/
/*@author	:	Quentin Ladevie											*/
/*@file		:	Matrix44.hpp											*/
/*@date		:	03/12/2015												*/
/*@brief	:	Fichier d'en-tête des matrices carré de dimension 4		*/
#ifndef __MATRIX44_H_
#define __MATRIX44_H_

#include <iostream>
#include "ExportMath.hpp"

using std::istream;
using std::ostream;


namespace DadEngine
{
	class Vector3;
	class Vector4;
	class Matrix33;

	class DADENGINE_MATHAPI Matrix44
	{
	protected:
		float m_af[4][4];

	public:

		// constructor and destructor
		Matrix44();
		Matrix44(float _afM[16]);
		Matrix44(float _fM11, float _fM12, float _fM13, float _fM14,
			float _fM21, float _fM22, float _fM23, float _fM24,
			float _fM31, float _fM32, float _fM33, float _fM34,
			float _fM41, float _fM42, float _fM43, float _fM44);
		Matrix44(const Matrix33 &_mat, const Vector3& _v);


		// set/get
		void SetTranslation(Vector3& _v);
		void SetRotation(Matrix33& _m);
		void SetScale(Vector3& _v);
		void SetIdentity();
		void SetZero();


		// assignment operators
		Matrix44& operator*= (const Matrix44 &_mat);
		Matrix44& operator+= (const Matrix44 &_mat);
		Matrix44& operator-= (const Matrix44 &_mat);
		Matrix44& operator*= (float _f);
		Matrix44& operator/= (float _f);


		// unary operators
		Matrix44 operator+ () const;
		Matrix44 operator- () const;


		// binary operators
		Matrix44 operator* (const Matrix44 &_mat) const;
		Matrix44 operator+ (const Matrix44 &_mat) const;
		Matrix44 operator- (const Matrix44 &_mat) const;
		Matrix44 operator* (float _f) const;
		Matrix44 operator/ (float _f) const;


		// Comparison operators
		bool operator== (const Matrix44 &_mat) const;
		bool operator!= (const Matrix44 &_mat) const;

		Vector4 operator* (const Vector4& _v);


		// accessor
		float& operator () (int _iRow, int _iCol);
		float operator () (int _iRow, int _iCol) const;


		// matrix operation
		void Transpose();
		bool Inverse();


		// DADENGINE_MATHAPI friend function
		DADENGINE_MATHAPI friend Vector4 operator* (const Vector4& _v, const Matrix44 &_mat);
		DADENGINE_MATHAPI friend Matrix44 operator* (float _f, const Matrix44 &_mat);


		// debug function
		DADENGINE_MATHAPI friend ostream &operator<< (ostream& _out, const Matrix44 &_v);
		DADENGINE_MATHAPI friend istream &operator>> (istream& _in, Matrix44 &_v);
		void Display() const;
	};

	const Matrix44 MATRIX44ZERO(0.0f, 0.0f, 0.0f, 0.0f,
								0.0f, 0.0f, 0.0f, 0.0f,
								0.0f, 0.0f, 0.0f, 0.0f,
								0.0f, 0.0f, 0.0f, 0.0f);

	const Matrix44 MATRIX44IDENTITY(1.0f, 0.0f, 0.0f, 0.0f,
									0.0f, 1.0f, 0.0f, 0.0f,
									0.0f, 0.0f, 1.0f, 0.0f,
									0.0f, 0.0f, 0.0f, 1.0f);

}

#endif // __MATRIX44_H_