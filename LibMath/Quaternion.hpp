/*Documentation										*/
/*@author	:	Quentin Ladevie						*/
/*@file		:	Quaternion.hpp						*/
/*@date		:	07/01/2016							*/
/*@brief	:	Fichier d'en-tête des quaternions	*/
#ifndef __QUATERNION_H_
#define __QUATERNION_H_

#include "ExportMath.hpp"
#include "Vector3.hpp"


namespace DadEngine
{
	class DADENGINE_MATHAPI Quaternion
	{

	public:

		Quaternion();

		~Quaternion();


	private:

		// Member datas
		float m_fScalarPart;
		Vector3 m_vImaginaryPart;
	};
}

#endif // __QUATERNION_H_