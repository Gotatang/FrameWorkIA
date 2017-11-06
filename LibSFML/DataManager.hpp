/*Documentation																		*/
/*@author	:	Quentin Ladevie														*/
/*@file		:	DataManager.hpp														*/
/*@date		:	17/12/2015															*/
/*@brief	:	Fichier d'en-tête du gestionnaire de données (texture, modèles, ...)*/
#ifndef __DATAMANAGER_H_
#define __DATAMANAGER_H_

#include "Singleton.hpp"

#include <map>


namespace DadEngine
{
	class Texture;
	class Text;
	class Font;

	class DADENGINE_SFMLAPI DataManager : public Singleton<DataManager>
	{

		DADENGINE_SFMLAPI friend Singleton<DataManager>;


	public:

		enum ASSETTYPE : int
		{
			SFTEXTURE,
			SFTEXT,
			SFFONT,
			SHAPE,
		};


		void* CreateAsset(int _iAssetType, std::string _sAssetName);


		// Get asset
		void* GetAsset(int _iAssetType, std::string _sAssetName);


		// Get memory info
		int GetAllocatedMemory(int _iMemoryType);

		void DisplayAllocatedMemory(int _iMemoryType);


		// Free memory
		void ClearDataManager();


	protected:

		DataManager();

		virtual ~DataManager();


	private:

		DataManager(const DataManager& _copy);


		// Member datas
		std::map <std::string, Texture*> m_mInstanciedTextures;
		std::map <std::string, Text*> m_mInstanciedTexts;
		std::map <std::string, Font*> m_mInstanciedFonts;
	};
}

#endif // __DATAMANAGER_H_