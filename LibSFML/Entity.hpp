/*Documentation											*/
/*@author	:	Quentin Ladevie							*/
/*@file		:	Entity.hpp								*/
/*@date		:	22/12/2015								*/
/*@brief	:	Fichier d'en-tête de la classe entitée	*/
#ifndef __ENTITY_H_
#define __ENTITY_H_

#include "ExportSFML.hpp"


namespace DadEngine
{
	class Component;

	class DADENGINE_SFMLAPI Entity
	{

	public:

		Entity(std::string& _sName, Entity* _ptrParent);

		virtual ~Entity();


		// Entity handling functions
		virtual bool Update();
		virtual bool Draw();


		// Tree handling
		virtual void AddChild(Entity* _ptrNewEntity);
		virtual void AddComponent(Component* _ptrNewComponent);


		// Set
		inline void SetParent(Entity* _ptrNewParent) { m_ptrParent = _ptrNewParent; }


	private:

		// Member datas
		string						m_sName;			// Current entity name

		Entity*						m_ptrParent;		// Current entity parent
		std::vector<Entity*>		m_vChildren;		// Other entities
		std::vector<Component*>		m_vComponent;		// Current entity component
	};
}

#endif // __ENTITY_H_