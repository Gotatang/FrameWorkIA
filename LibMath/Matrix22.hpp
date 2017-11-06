/*Documentation															*/
/*@author	:	Quentin Ladevie											*/
/*@file		:	Matrix22.hpp											*/
/*@date		:	03/12/2015												*/
/*@brief	:	Fichier d'en-tête des matrices carré de dimension 2		*/
#ifndef __MATRIX22_H_
#define __MATRIX22_H_

#define MATRIX22_COMPENENTCOUNT 4

#include <iostream>
#include "ExportMath.hpp"

using std::istream;
using std::ostream;


namespace DadEngine
{
	class Vector2;

	class DADENGINE_MATHAPI Matrix22
	{
		float m_af[2][2];

	public:

		// Constructor and destructor
		Matrix22();
		Matrix22(float _faM[4]);
		Matrix22(float _fM11, float _fM12,
			float _fM21, float _fM22);


		// Set/get
		void SetRotation(float _fAngle);									// in radians
		void SetScale(float _fX, float _fY);
		void SetIdentity();
		void SetZero();


		// assignment operators
		Matrix22& operator*= (const Matrix22 &_mat);
		Matrix22& operator+= (const Matrix22 &_mat);
		Matrix22& operator-= (const Matrix22 &_mat);
		Matrix22& operator*= (float _f);
		Matrix22& operator/= (float _f);


		// unary operators
		Matrix22 operator+ () const;
		Matrix22 operator- () const;


		// binary operators
		Matrix22 operator* (const Matrix22 &_mat) const;
		Matrix22 operator+ (const Matrix22 &_mat) const;
		Matrix22 operator- (const Matrix22 &_mat) const;
		Matrix22 operator* (float _f) const;
		Matrix22 operator/ (float _f) const;

		bool operator== (const Matrix22 &_mat) const;
		bool operator!= (const Matrix22 &_mat) const;

		Vector2 operator* (const Vector2& _v);


		// accessor
		float& operator () (int _iRow, int _iCol);
		float operator () (int _iRow, int _iCol) const;


		// matrix operation
		void Transpose();
		bool Inverse();


		// DADENGINE_MATHAPI friend function
		DADENGINE_MATHAPI friend Vector2  operator* (const Vector2& _v, const Matrix22 &_mat);
		DADENGINE_MATHAPI friend Matrix22 operator* (float _f, const Matrix22 &_mat);


		// debug function
		DADENGINE_MATHAPI friend ostream &operator<< (ostream& _out, const Matrix22 &_v);
		DADENGINE_MATHAPI friend istream &operator>> (istream& _in, Matrix22 &_v);
		void Display() const;
	};

	const Matrix22 MATRIX22ZERO(0.0f, 0.0f,
								0.0f, 0.0f);

	const Matrix22 MATRIX22IDENTITY(1.0f, 0.0f,
									0.0f, 1.0f);

}

#endif // __MATRIX22_H_