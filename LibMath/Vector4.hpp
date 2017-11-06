/*Documentation															*/
/*@author	:	Quentin Ladevie											*/
/*@file		:	Vector4.hpp												*/
/*@date		:	19/11/2015												*/
/*@brief	:	Fichier d'en-tête des vecteurs à 4 Dimensions			*/
#ifndef __VECTOR4_H_
#define __VECTOR4_H_

#include "ExportMath.hpp"


namespace DadEngine
{
	class Matrix44;

	class DADENGINE_MATHAPI Vector4
	{

	public:

		Vector4();
		Vector4(const Vector4& _copy);
		Vector4(float _fX, float _fY, float _fZ, float _fW);

		~Vector4();


		// Get/Set
		void SetX(float _fX);
		void SetY(float _fY);
		void SetZ(float _fZ);
		void SetW(float _fW);

		float GetX() const;
		float GetY() const;
		float GetZ() const;
		float GetW() const;


		// Handling functions
		static Vector4 Lerp(const Vector4 _from, const Vector4 _to, float _step);
		void Scale(float _fScaleFactor);
		void Translate(float _fX, float _fY, float _fZ, float _fW);
		void Display() const;
		float Length() const;
		bool IsNullByEpsilon() const;
		bool IsUnitByEpsilon() const;
		bool Normalize();
		float Dot(const Vector4 &_vector1) const;
		float Angle(const Vector4 &_vector1) const;
		Vector4 Cross(const Vector4 &_vector1) const;

		// DADENGINE_MATHAPI friend
		DADENGINE_MATHAPI friend ostream& operator <<(ostream& _o, const Vector4& _v);
		DADENGINE_MATHAPI friend istream& operator >>(istream& _i, Vector4& _v);

		// DADENGINE_MATHAPI friends with other class
		DADENGINE_MATHAPI friend Vector4 operator* (const Vector4& _v, const Matrix44 &_mat);


	private:

		float m_fX;
		float m_fY;
		float m_fZ;
		float m_fW;
	};

	//----------------------------
	// Inline functions
	//----------------------------

	// Get/Set
	inline void Vector4::SetX(float _fX)
	{
		m_fX = _fX;
	}

	inline void Vector4::SetY(float _fY)
	{
		m_fY = _fY;
	}

	inline void Vector4::SetZ(float _fZ)
	{
		m_fZ = _fZ;
	}

	inline void Vector4::SetW(float _fW)
	{
		m_fW = _fW;
	}


	inline float Vector4::GetX() const
	{
		return m_fX;
	}

	inline float Vector4::GetY() const
	{
		return m_fY;
	}

	inline float Vector4::GetZ() const
	{
		return m_fZ;
	}

	inline float Vector4::GetW() const
	{
		return m_fW;
	}


	const Vector4 VECTOR4ZERO(0.f, 0.f, 0.f, 0.f);
	const Vector4 VECTOR4ONE(1.f, 1.f, 1.f, 1.f);

}

#endif // __VECTOR4_H_