/*Documentation										*/
/*@author	:	Quentin Ladevie						*/
/*@file		:	Transform2.hpp						*/
/*@date		:	07/01/2016							*/
/*@brief	:	Fichier d'en-tête des transforms 2D	*/
#ifndef __TRANSFORM2_H_
#define __TRANSFORM2_H_

#include "ExportMath.hpp"


namespace DadEngine
{
	class Vector2;
	class Matrix22;
	class Matrix33;

	class DADENGINE_MATHAPI Transform2
	{

	public:

		Transform2(float _fM[9]);
		Transform2( float _fM11, float _fM12, float _fM13,
					float _fM21, float _fM22, float _fM23,
					float _fM31, float _fM32, float _fM33);
		Transform2(const Matrix33& _m);
		Transform2(Matrix22* _ptrmRotation = NULL, Vector2* _ptrvTranslation = NULL, Vector2* _ptrvScale = NULL);
		Transform2(const Transform2& _copy);

		~Transform2();

		// Set/Get functions
		void SetTranslation(Vector2* _ptrV);
		void SetRotation(Matrix22* _ptrM);
		void SetScale(Vector2* _ptrV);
		void SetMatrix(Matrix33& _m);
		inline Vector2* GetTranslation() const;
		inline Matrix22* GetRotation() const;
		inline Vector2* GetScale() const;
		Matrix33 GetMatrix() const;

		// Operators
		Transform2& operator*= (const Transform2 &_mat);
		Transform2 operator* (const Transform2 &_mat) const;
		Transform2& operator= (const Transform2 &_mat);
		bool operator== (const Transform2 &_mat) const;
		bool operator!= (const Transform2 &_mat) const;

		Vector3 operator* (const Vector3& _v);

		// Debug function
		DADENGINE_MATHAPI friend ostream &operator<< (ostream& _out, const Transform2 &_v);
		DADENGINE_MATHAPI friend istream &operator>> (istream& _in, Transform2 &_v);

		void Display() const;


	protected:

		// Member datas
		Matrix22*		m_ptrRotation;
		Vector2*		m_ptrTranslation;
		Vector2*		m_ptrScale;
	};


	inline Vector2* Transform2::GetTranslation() const
	{
		if (m_ptrTranslation)
		{
			return m_ptrTranslation;
		}

		return NULL;
	}

	inline Matrix22* Transform2::GetRotation() const
	{
		if (m_ptrRotation)
		{
			return m_ptrRotation;
		}

		return NULL;
	}

	inline Vector2* Transform2::GetScale() const
	{
		if (m_ptrScale)
		{
			return m_ptrScale;
		}
		
		return m_ptrScale;
	}
}

#endif // __TRANSFORM2_H_