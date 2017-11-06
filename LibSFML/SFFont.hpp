/*Documentation										*/
/*@author	:	Quentin Ladevie						*/
/*@file		:	SFFont.hpp							*/
/*@date		:	30/12/2015							*/
/*@brief	:	Fichier d'en-tête des polices SFML	*/
#ifndef __SFFONT_H_
#define __SFFONT_H_

#include "ExportSFML.hpp"
#include "Font.hpp"
#include "SFML\Graphics.hpp"


namespace DadEngine
{
	class DADENGINE_SFMLAPI SFFont : public Font
	{

	public:

		SFFont(std::string _sName);

		virtual ~SFFont();


		// Get/Set
		sf::Font& GetFont();
		void SetFont(const sf::Font& _newFont);

		// Get a copy
		virtual Font* GetClone();


	private:

		// Member datas
		sf::Font m_font;
	};
}

#endif // __SFFONT_H_