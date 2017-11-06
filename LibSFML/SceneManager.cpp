/*Documentation												*/
/*@author	:	Quentin Ladevie								*/
/*@file		:	SceneManager.cpp							*/
/*@date		:	21/12/2015									*/
/*@brief	:	Fichier source du gestionnaire de scenes	*/
#include "stdafx.h"
#include "SceneManager.hpp"


namespace DadEngine
{
	SceneManager::SceneManager()
	{}


	SceneManager::~SceneManager()
	{}


	// Scene functions
	bool SceneManager::Input()
	{
		if (m_ptrsCurrentScene)
		{
			m_ptrsCurrentScene->Input();

			return true;
		}

		return false;
	}

	bool SceneManager::Update()
	{
		if (m_ptrsCurrentScene)
		{
			m_ptrsCurrentScene->Update();

			return true;
		}

		return false;
	}

	bool SceneManager::Draw()
	{
		if (m_ptrsCurrentScene)
		{
			m_ptrsCurrentScene->Draw();

			return true;
		}

		return false;
	}


	// Set used scene
	Scene* SceneManager::GetScene()
	{
		return m_ptrsCurrentScene;
	}

	void SceneManager::SetScene(Scene* _ptrsNewScene)
	{
		if (m_ptrsCurrentScene)
		{
			m_ptrsCurrentScene->Deinit();

			delete m_ptrsCurrentScene;
		}

		m_ptrsCurrentScene = _ptrsNewScene;

		{
		if (m_ptrsCurrentScene)
			m_ptrsCurrentScene->Init();
		}
	}
}