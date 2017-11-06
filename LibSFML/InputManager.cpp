/*Documentation															*/
/*@author	:	Quentin Ladevie											*/
/*@file		:	InputManager.cpp										*/
/*@date		:	21/12/2015												*/
/*@brief	:	Fichier source du gestionnaire des entrées périphériques*/
#include "stdafx.h"
#include "InputManager.hpp"


namespace DadEngine
{
	InputManager::InputManager() : m_event(GameManager::GetInstance()->GetEventHandler())
	{
	}


	InputManager::~InputManager()
	{
	}


	// Keyboard inputs handling
	bool InputManager::IsKeyPressed(sf::Keyboard::Key _eCurrentKeyCode)
	{
		if (m_event.type == sf::Event::KeyPressed)
		{
			return (m_event.key.code == _eCurrentKeyCode);
		}

		return false;
	}

	bool InputManager::IsKeyDown(sf::Keyboard::Key _eCurrentKeyCode)
	{
		return true;
	}

	bool InputManager::IsKeyReleased(sf::Keyboard::Key _eCurrentKeyCode)
	{
		if (m_event.type == sf::Event::KeyReleased)
		{
			return (m_event.key.code == _eCurrentKeyCode);
		}

		return false;
	}

	bool InputManager::IsKeyUp(sf::Keyboard::Key _eCurrentKeyCode)
	{
		return true;
	}


	// Mouse inputs handling
	bool InputManager::IsButtonPressed(sf::Mouse::Button _eCurrentButtonCode)
	{
		if (m_event.type == sf::Event::MouseButtonPressed)
		{
			return (m_event.key.code == _eCurrentButtonCode);
		}

		return false;
	}

	bool InputManager::IsButtonReleased(sf::Mouse::Button _eCurrentButtonCode)
	{
		if (m_event.type == sf::Event::MouseButtonReleased)
		{
			return (m_event.key.code == _eCurrentButtonCode);
		}

		return false;
	}


	Point2 InputManager::GetMousePositionInWindow()
	{
		return Point2(sf::Mouse::getPosition(*GameManager::GetInstance()->GetWnd()).x, sf::Mouse::getPosition(*GameManager::GetInstance()->GetWnd()).y);
	}

	Point2 InputManager::GetMousePositionInScreen()
	{
		return Point2(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
	}
}