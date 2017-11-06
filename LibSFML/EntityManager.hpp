/*Documentation												*/
/*@author	:	Quentin Ladevie								*/
/*@file		:	EntityManager.hpp							*/
/*@date		:	17/12/2015									*/
/*@brief	:	Fichier d'en-tête du gestionnaire d'entité	*/
#ifndef __ENTITYMANAGER_H_
#define __ENTITYMANAGER_H_

#include "ExportSFML.hpp"
#include "Singleton.hpp"


namespace DadEngine
{
	class Entity;

	class DADENGINE_SFMLAPI EntityManager : public Singleton<EntityManager>
	{

		DADENGINE_SFMLAPI friend Singleton<EntityManager>;


	public:

		// Entity handling
		void Update();
		void Draw();

		void Clear();


	protected:

		EntityManager();

		virtual ~EntityManager();
		

	private:

		EntityManager(const EntityManager& _copy);


		// Member datas
		Entity* m_ptrRoot;			// Root entity
	};
}

#endif // __ENTITYMANAGER_H_