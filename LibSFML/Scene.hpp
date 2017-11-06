/*Documentation																	*/
/*@author	:	Quentin Ladevie													*/
/*@file		:	Scene.hpp														*/
/*@date		:	22/12/2015														*/
/*@brief	:	Fichier d'en-tête de la class abstraite "Scene" mère des scenes	*/
#ifndef __SCENE_H_
#define __SCENE_H_

#include "ExportSFML.hpp"
#include "SceneManager.hpp"


namespace DadEngine
{
	class DADENGINE_SFMLAPI Scene
	{

	public:

		Scene() { /*DadEngine::SceneManager::GetInstance()->SetScene(this);*/ };
		virtual ~Scene() {};

		virtual bool Init() = 0;
		virtual bool Input() = 0;
		virtual bool Update() = 0;
		virtual bool Draw() = 0;
		virtual bool Deinit() = 0;

	};
}

#endif // __SCENE_H_