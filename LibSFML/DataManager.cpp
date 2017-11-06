/*Documentation																	*/
/*@author	:	Quentin Ladevie													*/
/*@file		:	DataManager.cpp													*/
/*@date		:	17/12/2015														*/
/*@brief	:	Fichier source du gestionnaire de données (texture, modèles, ...)*/
#include "stdafx.h"
#include "DataManager.hpp"


namespace DadEngine
{
	DataManager::DataManager()
	{}


	DataManager::~DataManager()
	{
		ClearDataManager();
	}


	void* DataManager::CreateAsset(int _iAssetType, std::string _sAssetName)
	{
		switch (_iAssetType)
		{
			case SFTEXTURE:
			{
				SFTexture* ptrTexture = new SFTexture(_sAssetName);

				m_mInstanciedTextures.insert(std::pair<string, Texture*>(_sAssetName, ptrTexture));

				return ptrTexture;

				break;
			}

			case SFTEXT:
			{
				SFText* ptrText = new SFText;

				m_mInstanciedTexts.insert(std::pair<string, Text*>(_sAssetName, ptrText));

				return ptrText;

				break;
			}

			case SFFONT:
			{
				SFFont* ptrFont = new SFFont(_sAssetName);

				m_mInstanciedFonts.insert(std::pair<string, Font*>(_sAssetName, ptrFont));

				return ptrFont;

				break;
			}


			default:
			{
				cout << "Unknow asset type !" << endl << endl;

				return NULL;
			}
		}
	}


	// Get asset
	void* DataManager::GetAsset(int _iAssetType, std::string _sAssetName)
	{
		switch (_iAssetType)
		{
			case SFTEXTURE:
			{
				map<string, Texture*>::iterator it = m_mInstanciedTextures.find(_sAssetName);

				if (it == m_mInstanciedTextures.end())
				{
					cout << "This asset doesn't exist !" << endl << endl;

					return NULL;
				}

				return it->second;

				break;
			}

			case SFTEXT:
			{
				map<string, Text*>::iterator it = m_mInstanciedTexts.find(_sAssetName);

				if (it == m_mInstanciedTexts.end())
				{
					cout << "This asset doesn't exist !" << endl << endl;

					return NULL;
				}

				return it->second;

				break;
			}

			case SFFONT:
			{
				map<string, Font*>::iterator it = m_mInstanciedFonts.find(_sAssetName);

				if (it == m_mInstanciedFonts.end())
				{
					cout << "This asset doesn't exist !" << endl << endl;

					return NULL;
				}

				return it->second;

				break;
			}

		
			default:
			{
				cout << "Unknow asset type !" << endl << endl;

				return NULL;
			}
		}
	}


	// Get memory info
	int DataManager::GetAllocatedMemory(int _iMemoryType)
	{
		switch (_iMemoryType)
		{
			case SFTEXTURE:
			{
				return m_mInstanciedTextures.size ();
			}

			case SFTEXT:
			{
				return  m_mInstanciedTexts.size();
			}

			case SFFONT:
			{
				return m_mInstanciedFonts.size();
			}

			case SHAPE:
			{
				return ShapeList::GetInstance()->GetList().size();
			}


			default:
			{
				cout << "Unknow asset type !" << endl << endl;

				return m_mInstanciedTextures.size() + m_mInstanciedTexts.size() + m_mInstanciedFonts.size() + ShapeList::GetInstance()->GetList().size();
			}
		}

		return 0;
	}

	void DataManager::DisplayAllocatedMemory(int _iMemoryType)
	{
		switch (_iMemoryType)
		{
			case SFTEXTURE:
			{
				cout << m_mInstanciedTextures.size() << " textures allocated." << endl;
				break;
			}

			case SFTEXT:
			{
				cout << m_mInstanciedTexts.size() << " texts allocated." << endl;
				break;
			}

			case SFFONT:
			{
				cout << m_mInstanciedFonts.size() << " fonts allocated." << endl;
				break;
			}

			case SHAPE:
			{
				cout << ShapeList::GetInstance()->GetList().size() << " shapes allocated." << endl;
				break;
			}


			default:
			{
				cout << "Unknow asset type !" << endl << endl;
			
				cout << m_mInstanciedTextures.size() << " textures allocated." << endl;
				cout << m_mInstanciedTexts.size() << " texts allocated." << endl;
				cout << m_mInstanciedFonts.size() << " fonts allocated." << endl;
				cout << ShapeList::GetInstance()->GetList().size() << " shapes allocated." << endl;

				break;
			}
		}
	}


	// Free memory
	void DataManager::ClearDataManager()
	{
		map<string, Texture*>::iterator itTextures = m_mInstanciedTextures.begin();
		map<string, Text*>::iterator itTexts = m_mInstanciedTexts.begin();
		map<string, Font*>::iterator itFonts = m_mInstanciedFonts.begin();

		while (m_mInstanciedTextures.size ())
		{
			delete itTextures->second;
			itTextures = m_mInstanciedTextures.erase(itTextures);
		}

		m_mInstanciedTextures.clear();


		while (m_mInstanciedTexts.size())
		{
			delete itTexts->second;
			itTexts = m_mInstanciedTexts.erase(itTexts);
		}

		m_mInstanciedTexts.clear();


		while (m_mInstanciedFonts.size())
		{
			delete itFonts->second;
			itFonts = m_mInstanciedFonts.erase(itFonts);
		}

		m_mInstanciedFonts.clear();
	}
}