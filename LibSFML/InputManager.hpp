/*Documentation																*/
/*@author	:	Quentin Ladevie												*/
/*@file		:	InputManager.hpp											*/
/*@date		:	21/12/2015													*/
/*@brief	:	Fichier d'en-tête du gestionnaire des entrées prériphériques*/
#ifndef __INPUTMANAGER_H_
#define __INPUTMANAGER_H_

#include "Singleton.hpp"
#include "Point2.hpp"
#include "SFML\Graphics.hpp"


namespace DadEngine
{
	class DADENGINE_SFMLAPI InputManager : public Singleton<InputManager>
	{

		DADENGINE_SFMLAPI friend Singleton<InputManager>;


	public:
		
		// Get
		sf::Event* GetEventHandler();

		// Keyboard inputs handling
		bool IsKeyPressed(sf::Keyboard::Key _eCurrentKeyCode);
		bool IsKeyDown(sf::Keyboard::Key _eCurrentKeyCode);

		bool IsKeyReleased(sf::Keyboard::Key _eCurrentKeyCode);
		bool IsKeyUp(sf::Keyboard::Key _eCurrentKeyCode);


		// Mouse inputs handling
		bool IsButtonPressed(sf::Mouse::Button _eCurrentButtonCode);
		bool IsButtonReleased(sf::Mouse::Button _eCurrentButtonCode);

		Point2 GetMousePositionInWindow();
		Point2 GetMousePositionInScreen();


	protected:

		InputManager();
		~InputManager();


	private:

		InputManager(const InputManager& _copy);


		// Member datas
		const sf::Event& m_event;
	};
}

#endif // __INPUTMANAGER_H_