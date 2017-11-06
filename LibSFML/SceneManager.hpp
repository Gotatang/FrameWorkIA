/*Documentation												*/
/*@author	:	Quentin Ladevie								*/
/*@file		:	SceneManager.hpp							*/
/*@date		:	21/12/2015									*/
/*@brief	:	Fichier d'en-tête du gestionnaire de scenes	*/
#ifndef __SCENEMANAGER_H_
#define __SCENEMANAGER_H_

#include "ExportSFML.hpp"
#include "Singleton.hpp"


namespace DadEngine
{
	class Scene;

	class DADENGINE_SFMLAPI SceneManager : public Singleton<SceneManager>
	{

		DADENGINE_SFMLAPI friend Singleton<SceneManager>;


	public:

		// Scene functions
		bool Input();
		bool Update();
		bool Draw();


		// Get/Set current scene
		Scene* GetScene();

		void SetScene(Scene* _ptrNewScene);


	protected:

		SceneManager();

		virtual ~SceneManager();


	private:

		SceneManager(const SceneManager& _copy);
		
		// Member datas
		Scene* m_ptrsCurrentScene;
	};
}

#endif // __SCENEMANAGER_H_