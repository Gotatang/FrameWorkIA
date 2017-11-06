/*Documentation										*/
/*@author	:	Quentin Ladevie						*/
/*@file		:	SFTexture.cpp						*/
/*@date		:	22/12/2015							*/
/*@brief	:	Fichier source des textures SFML	*/
#include "stdafx.h"
#include "SFTexture.hpp"


namespace DadEngine
{
	SFTexture::SFTexture(string _sName)
	{
		if (!m_texture.loadFromFile(TEXTURES_PATH + _sName))
		{
#ifdef		_DEBUG
			cout << "Texture " << _sName << " can't be load" << endl;
#endif	
		}

		m_vSize = Vector2((float) m_texture.getSize().x, (float)m_texture.getSize().y);
	}


	SFTexture::~SFTexture()
	{
	}


	// Get/Set
	sf::Texture& SFTexture::GetTexture()
	{
		return m_texture;
	}

	Vector2 SFTexture::GetSize()
	{
		return m_vSize;
	}


	void SFTexture::SetTexture(const sf::Texture& _newTexture)
	{
		m_texture = _newTexture;
	}


	// Get a copy
	Texture* SFTexture::GetClone()
	{
		return new SFTexture (*this);
	}
}