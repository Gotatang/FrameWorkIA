/*Documentation																	*/
/*@author	:	Quentin Ladevie													*/
/*@file		:	GameManager.cpp													*/
/*@date		:	21/12/2015														*/
/*@brief	:	Fichier source du gestionnaire de jeu (facade de la surcouche)	*/
#include "stdafx.h"
#include "GameManager.hpp"


namespace DadEngine
{
	GameManager::GameManager() : m_ptrWnd(NULL)
	{}


	GameManager::~GameManager()
	{}


	// Game functions
	void GameManager::Init(Scene* _ptrsStartScene, unsigned int _uiWidth, unsigned int _uiHeight, std::string _sWndName)
	{
		m_ptrWnd = NULL;
		m_ptrWnd = new sf::RenderWindow(sf::VideoMode(_uiWidth, _uiHeight), _sWndName);

		if (!m_ptrWnd)
		{
#			ifdef _DEBUG
			cout << "Window can't be allocated" << endl;
#			endif
		}

		m_ptrEventHandler = NULL;
		m_ptrEventHandler = new sf::Event;

		if (!m_ptrEventHandler)
		{
#			ifdef _DEBUG
			cout << "Event handler can't be allocated" << endl;
#			endif
		}


		if (_ptrsStartScene)
		{
			SceneManager::GetInstance()->SetScene(_ptrsStartScene);
		}

		m_ptrcDeltaTimeClock = NULL;
		m_ptrcDeltaTimeClock = new sf::Clock;

		if (!m_ptrcDeltaTimeClock)
		{
#			ifdef _DEBUG
			cout << "Delta time clock can't be allocated" << endl;
#			endif
		}


		m_ptrtDeltaTime = NULL;
		m_ptrtDeltaTime = new sf::Time;

		if (!m_ptrtDeltaTime)
		{
#			ifdef _DEBUG
			cout << "Delta time can't be allocated" << endl;
#			endif
		}
	}

	void GameManager::GameLoop()
	{
		while (m_ptrWnd->isOpen())
		{
			Time();

			Input();
			Update();
			Draw();
		}
	}

	void GameManager::Deinit()
	{
		if (m_ptrWnd)
			delete m_ptrWnd;

		m_ptrWnd = NULL;


		if (m_ptrEventHandler)
			delete m_ptrEventHandler;

		m_ptrEventHandler = NULL;


		if (m_ptrcDeltaTimeClock)
			delete m_ptrcDeltaTimeClock;

		m_ptrcDeltaTimeClock = NULL;


		if (m_ptrtDeltaTime)
			delete m_ptrtDeltaTime;

		m_ptrtDeltaTime = NULL;

		DataManager::GetInstance()->ClearDataManager();
	}


	// Handling functions
	void GameManager::Time()
	{
		*m_ptrtDeltaTime = m_ptrcDeltaTimeClock->restart();
	}

	void GameManager::Input()
	{
		while (m_ptrWnd->pollEvent(*m_ptrEventHandler))
		{
			if (m_ptrEventHandler->type == m_ptrEventHandler->Closed)
			{
				m_ptrWnd->close();
			}

			SceneManager::GetInstance()->Input();
		}
	}

	void GameManager::Update()
	{
		SceneManager::GetInstance()->Update();
		EntityManager::GetInstance()->Update();
	}

	void GameManager::Draw()
	{
		m_ptrWnd->clear();

		SceneManager::GetInstance()->Draw();
		EntityManager::GetInstance()->Draw();

		m_ptrWnd->display();
	}


	// Get
	sf::RenderWindow* GameManager::GetWnd() const
	{
		return m_ptrWnd;
	}

	sf::Event& GameManager::GetEventHandler() const
	{
		return *m_ptrEventHandler;
	}

	float GameManager::GetDeltaTime() const
	{
		return m_ptrtDeltaTime->asSeconds();
	}
}