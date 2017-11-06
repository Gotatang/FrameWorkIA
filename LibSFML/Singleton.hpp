/*Documentation													*/
/*@author	:	Quentin Ladevie									*/
/*@file		:	Singleton<T>.hpp								*/
/*@date		:	17/12/2015										*/
/*@brief	:	Fichier d'en-tête du design pattern singleton	*/
#ifndef __SINGLETON_H_
#define __SINGLETON_H_

#include "ExportSFML.hpp"


namespace DadEngine
{
	template <typename T> class Singleton
	{

	public:

		// Handling
		static T* GetInstance()
		{
			if (s_tInstance)
				return s_tInstance;

			s_tInstance = new T;

			return s_tInstance;
		};
		

	protected:

		Singleton() {};

		virtual ~Singleton() {};


	private:

		// Disable copying
		Singleton(const Singleton<T>& _copy) {};

		Singleton<T>& operator = (const Singleton<T>& _t1) { return *this; };


		// Member data
		static T* s_tInstance;

	};

	template <typename T> T *Singleton<T>::s_tInstance = NULL;

}

#endif // __SINGLETON_H_