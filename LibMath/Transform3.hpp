/*Documentation										*/
/*@author	:	Quentin Ladevie						*/
/*@file		:	Transform.hpp						*/
/*@date		:	03/12/2015							*/
/*@brief	:	Fichier d'en-tête des transforms 3D	*/
#ifndef __TRANSFORM3_H_
#define __TRANSFORM3_H_

#include "ExportMath.hpp"
#include <iostream>

using std::istream;
using std::ostream;

namespace DadEngine
{
	class Vector3;
	class Vector4;
	class Matrix33;
	class Matrix44;

	class DADENGINE_MATHAPI Transform3
	{

	public:

		// constructor and destructor
		Transform3(float _fM[16]);
		Transform3( float _fM11, float _fM12, float _fM13, float _fM14,
					float _fM21, float _fM22, float _fM23, float _fM24,
					float _fM31, float _fM32, float _fM33, float _fM34,
					float _fM41, float _fM42, float _fM43, float _fM44);
		Transform3(const Matrix44& _m);
		Transform3(Matrix33* _ptrRotation = NULL, Vector3* _ptrTranslation = NULL, Vector3* _ptrScale = NULL);
		Transform3(const Transform3& _m);

		~Transform3();

		// set/get functions
		void SetTranslation(Vector3* _ptrV);
		void SetRotation(Matrix33* _ptrM);
		void SetScale(Vector3* _ptrV);
		void SetMatrix(Matrix44& _m);
		inline Vector3* GetTranslation() const;
		inline Matrix33* GetRotation() const;
		inline Vector3* GetScale() const;
		Matrix44 GetMatrix() const;

		// operators
		Transform3& operator*= (const Transform3 &_mat);
		Transform3 operator* (const Transform3 &_mat) const;
		Transform3& operator= (const Transform3 &_mat);
		bool operator== (const Transform3 &_mat) const;
		bool operator!= (const Transform3 &_mat) const;

		Vector4 operator* (const Vector4& _v);

		// debug function
		DADENGINE_MATHAPI friend ostream &operator<< (ostream& _out, const Transform3 &_v);
		DADENGINE_MATHAPI friend istream &operator>> (istream& _in, Transform3 &_v);

		void Display() const;


	protected:

		// Member datas
		Matrix33*		m_ptrRotation;
		Vector3*		m_ptrTranslation;
		Vector3*		m_ptrScale;

	};


	// Get inline
	inline Vector3* Transform3::GetTranslation() const
	{
		return m_ptrTranslation;
	}

	inline Matrix33* Transform3::GetRotation() const
	{
		return m_ptrRotation;
	}

	inline Vector3* Transform3::GetScale() const
	{
		return m_ptrScale;
	}
}

#endif // __TRANSFORM_H_