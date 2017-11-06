/*Documentation										*/
/*@author	:	Quentin Ladevie						*/
/*@file		:	SFText.hpp							*/
/*@date		:	29/12/2015							*/
/*@brief	:	Fichier d'en-tête des textes SFML	*/
#ifndef __SFTEXT_H_
#define __SFTEXT_H_

#include "ExportSFML.hpp"
#include "Text.hpp"
#include "SFML\Graphics.hpp"


namespace DadEngine
{
	class SFFont;

	class DADENGINE_SFMLAPI SFText : public Text
	{

	public:

		SFText();

		virtual ~SFText();


		// Get/Set
		sf::Text& GetText();

		void SetText(const sf::Text& _newText);


		// Get a copy
		virtual Text* GetClone();


	private:

		// Member datas
		sf::Text m_text;
	};
}

#endif // __SFTEXT_H_