/*Documentation															*/
/*@author	:	Quentin Ladevie											*/
/*@file		:	Matrix33.hpp											*/
/*@date		:	03/12/2015												*/
/*@brief	:	Fichier d'en-tête des matrices carré de dimension 3		*/
#ifndef __MATRIX33_H_
#define __MATRIX33_H_

#include <iostream>
#include "ExportMath.hpp"

using std::ostream;
using std::istream;


namespace DadEngine
{
	class Vector3;
	class Matrix22;

	class DADENGINE_MATHAPI Matrix33
	{
		float m_af[3][3];

	public:

		// constructor and destructor
		Matrix33();
		Matrix33(float _afM[9]);
		Matrix33(float _fM11, float _fM12, float _fM13,
				 float _fM21, float _fM22, float _fM23,
				 float _fM31, float _fM32, float _fM33);
		Matrix33(const Vector3& _v1, const Vector3& _v2, const Vector3& _v3);


		// set/get
		void SetTranslation(float _fX, float _fY);
		void SetRotation(float _fAngle, Vector3& _axe);
		void SetRotationX(float _fAngle);									// in radians
		void SetRotationY(float _fAngle);									// in radians
		void SetRotationZ(float _fAngle);									// in radians
		void SetScale(float _fX, float _fY, float _fZ);
		void SetIdentity();
		void SetZero();


		// assignment operators
		Matrix33& operator*= (const Matrix33 &_mat);
		Matrix33& operator+= (const Matrix33 &_mat);
		Matrix33& operator-= (const Matrix33 &_mat);
		Matrix33& operator*= (float _f);
		Matrix33& operator/= (float _f);


		// unary operators
		Matrix33 operator+ () const;
		Matrix33 operator- () const;


		// binary operators
		Matrix33 operator* (const Matrix33 &_mat) const;
		Matrix33 operator+ (const Matrix33 &_mat) const;
		Matrix33 operator- (const Matrix33 &_mat) const;
		Matrix33 operator* (float _f) const;
		Matrix33 operator/ (float _f) const;

		bool operator== (const Matrix33 &_mat) const;
		bool operator!= (const Matrix33 &_mat) const;

		Vector3 operator* (const Vector3& _v);


		// accessor
		float& operator () (int _iRow, int _iCol);
		float operator () (int _iRow, int _iCol) const;


		// matrix operation
		void Transpose();
		bool Inverse();


		// DADENGINE_MATHAPI friend function
		DADENGINE_MATHAPI friend Vector3  operator* (const Vector3& _v, const Matrix33 &_mat);
		DADENGINE_MATHAPI friend Matrix33 operator* (float _f, const Matrix33 &_mat);


		// debug function
		DADENGINE_MATHAPI friend ostream &operator<< (ostream& _out, const Matrix33 &_v);
		DADENGINE_MATHAPI friend istream &operator>> (istream& _in, Matrix33 &_v);
		void Display() const;
	};

	const Matrix33 MATRIX33ZERO(0.0f, 0.0f, 0.0f,
								0.0f, 0.0f, 0.0f,
								0.0f, 0.0f, 0.0f);

	const Matrix33 MATRIX33IDENTITY(1.0f, 0.0f, 0.0f,
									0.0f, 1.0f, 0.0f,
									0.0f, 0.0f, 1.0f);

}

#endif // __MATRIX33_H_