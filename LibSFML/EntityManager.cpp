/*Documentation											*/
/*@author	:	Quentin Ladevie							*/
/*@file		:	EntityManager.cpp						*/
/*@date		:	17/12/2015								*/
/*@brief	:	Fichier source du gestionnaire d'entité	*/
#include "stdafx.h"
#include "EntityManager.hpp"


namespace DadEngine
{
	EntityManager::EntityManager()
	{
	}


	EntityManager::~EntityManager()
	{
		Clear();
	}


	// Entity handling
	void EntityManager::Update()
	{
		if (m_ptrRoot)
		{
			m_ptrRoot->Update();
		}
	}

	void EntityManager::Draw()
	{
		if (m_ptrRoot)
		{
			m_ptrRoot->Draw();
		}
	}


	void EntityManager::Clear()
	{
		delete m_ptrRoot;

		m_ptrRoot = NULL;
	}
}