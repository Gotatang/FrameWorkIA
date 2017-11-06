/*Documentation									*/
/*@author	:	Quentin Ladevie					*/
/*@file		:	SFFont.cpp						*/
/*@date		:	30/12/2015						*/
/*@brief	:	Fichier source des polices SFML	*/
#include "stdafx.h"
#include "SFFont.hpp"


namespace DadEngine
{
	SFFont::SFFont(string _sName)
	{
		if (!m_font.loadFromFile(FONTS_PATH + _sName + ".ttf"))
		{
#ifdef		_DEBUG
			cout << "Font " << _sName << " can't be load"<< endl;
#endif
		}
	}


	SFFont::~SFFont()
	{
	}


	// Get/Set
	sf::Font& SFFont::GetFont()
	{
		return m_font;
	}

	void SFFont::SetFont(const sf::Font& _newFont)
	{
		m_font = _newFont;
	}


	// Get a copy
	Font* SFFont::GetClone()
	{
		return new SFFont(*this);
	}
}