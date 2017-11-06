/*Documentation															*/
/*@author	:	Quentin Ladevie											*/
/*@file		:	Vector.hpp												*/
/*@date		:	19/11/2015												*/
/*@brief	:	Fichier d'en-tête des vecteurs à n Dimensions			*/
#ifndef __VECTOR_H_
#define __VECTOR_H_

#include "ExportMath.hpp"


namespace DadEngine
{
	class DADENGINE_MATHAPI Vector
	{

	public:

		Vector();
		Vector(const Vector& _copy);
		Vector(unsigned int _iSize);
		Vector(unsigned int _iSize, float* _ptrfVector);

		~Vector();


		// Set/Get functions
		bool Set(unsigned int _iIndex, float _fNewValue);
		bool Get(unsigned int _iIndex, float& _fValue) const;


		void Scale(float _fSize);
		void Translate(float* _ptrfTranslationVector);
		float Dot(Vector& _v1) const;
		Vector Add(Vector& _v1) const;

		void Display() const;


		// Assignement operators
		Vector& operator+= (const Vector& _v);
		Vector& operator-= (const Vector& _v);
		Vector& operator*= (float _f);
		Vector& operator/= (float _f);
		Vector& operator = (const Vector& _v);


		// Unary operators
		Vector operator+ () const;
		Vector operator- () const;


		// Binary operators
		Vector operator+ (const Vector& _v) const;
		Vector operator- (const Vector& _v) const;
		Vector operator* (float _f) const;
		Vector operator/ (float _f) const;


		bool operator== (const Vector& _v) const;
		bool operator!= (const Vector& _v) const;


		// DADENGINE_MATHAPI friends operators
		DADENGINE_MATHAPI friend Vector operator* (float _f, const Vector& _v);
		DADENGINE_MATHAPI friend ostream& operator <<(ostream& _o, const Vector& _v);
		DADENGINE_MATHAPI friend istream& operator >>(istream& _i, Vector& _v);


	private:

		unsigned int m_uiSize;
		float* m_ptrfV;
	};
}

#endif // __VECTOR_H_