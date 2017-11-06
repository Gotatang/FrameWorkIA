/*Documentation																		*/
/*@author	:	Quentin Ladevie														*/
/*@file		:	GameManager.hpp														*/
/*@date		:	21/12/2015															*/
/*@brief	:	Fichier d'en-tête du gestionnaire de jeu (facade de la surcouche)	*/
#ifndef __GAMEMANAGER_H_
#define __GAMEMANAGER_H_

#include "ExportSFML.hpp"
#include "Singleton.hpp"
#include "SFML\Graphics.hpp"


namespace DadEngine
{
	class Scene;

	class DADENGINE_SFMLAPI GameManager : public Singleton<GameManager>
	{

		DADENGINE_SFMLAPI friend class Singleton<GameManager>;


	public:

		// Game functions
		void Init(Scene* _ptrsStartScene, unsigned int _uiWidth = 800, unsigned int _uiHeight = 600, std::string _sWndName = "Window");
		void GameLoop();
		void Deinit();

		// Handling functions
		void Time();
		void Input();
		void Update();
		void Draw();

		// Get
		sf::RenderWindow* GetWnd() const;
		sf::Event& GetEventHandler() const;
		float GetDeltaTime() const;			// Seconds


	protected:

		GameManager();

		virtual ~GameManager();


	private:

		GameManager(const GameManager& _copy);

		// Member datas
		sf::RenderWindow* m_ptrWnd;
		sf::Event* m_ptrEventHandler;
		sf::Clock* m_ptrcDeltaTimeClock;
		sf::Time* m_ptrtDeltaTime;
	};
}

#endif // __GAMEMANAGER_H_