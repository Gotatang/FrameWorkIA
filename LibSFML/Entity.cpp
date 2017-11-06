/*Documentation										*/
/*@author	:	Quentin Ladevie						*/
/*@file		:	Entity.cpp							*/
/*@date		:	22/12/2015							*/
/*@brief	:	Fichier source de la classe entitée	*/
#include "stdafx.h"
#include "Entity.hpp"


namespace DadEngine
{
	Entity::Entity(std::string& _sName, Entity* _ptrParent) : m_sName(_sName), m_ptrParent(_ptrParent)
	{}


	Entity::~Entity()
	{
		size_t componentCount = m_vComponent.size();

		for (size_t i = 0; i < componentCount; ++i)
		{
			delete m_vComponent[i];
		}

		m_vComponent.clear();


		size_t childrenCount = m_vChildren.size();

		for (size_t i = 0; i < childrenCount; ++i)
		{
			delete m_vChildren[i];
		}

		m_vChildren.clear();
	}


	// Entity handling functions
	bool Entity::Update()
	{
		size_t componentCount = m_vComponent.size();

		for (size_t i = 0; i < componentCount; ++i)
		{
			m_vComponent[i]->Update();
		}


		size_t childrenCount = m_vChildren.size();

		for (size_t i = 0; i < childrenCount; ++i)
		{
			m_vChildren[i]->Update();
		}

		return true;
	}

	bool Entity::Draw()
	{
		size_t componentCount = m_vComponent.size();

		for (size_t i = 0; i < componentCount; ++i)
		{
			m_vComponent[i]->Draw();
		}


		size_t childrenCount = m_vChildren.size();

		for (size_t i = 0; i < childrenCount; ++i)
		{
			m_vChildren[i]->Draw();
		}

		return true;
	}


	// Tree handling
	void Entity::AddChild(Entity* _ptrNewEntity)
	{
		m_vChildren.push_back(_ptrNewEntity);
		_ptrNewEntity->SetParent(this);
	}

	void Entity::AddComponent(Component* _ptrNewComponent)
	{
		m_vComponent.push_back(_ptrNewComponent);
	}
}