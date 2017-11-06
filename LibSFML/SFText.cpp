/*Documentation									*/
/*@author	:	Quentin Ladevie					*/
/*@file		:	SFText.cpp						*/
/*@date		:	29/12/2015						*/
/*@brief	:	Fichier source des textes SFML	*/
#include "stdafx.h"
#include "SFText.hpp"


namespace DadEngine
{
	SFText::SFText()
	{
	}


	SFText::~SFText()
	{
	}


	// Get/Set
	sf::Text& SFText::GetText()
	{
		return m_text;
	}


	void SFText::SetText(const sf::Text& _newText)
	{
		m_text = _newText;
	}


	// Get a copy
	Text* SFText::GetClone()
	{
		return new SFText (*this);
	}
}