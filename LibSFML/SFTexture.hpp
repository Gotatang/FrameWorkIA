/*Documentation										*/
/*@author	:	Quentin Ladevie						*/
/*@file		:	SFTexture.hpp						*/
/*@date		:	22/12/2015							*/
/*@brief	:	Fichier d'en-tête des textures SFML	*/
#ifndef __SFTEXTURE_H_
#define __SFTEXTURE_H_

#include "ExportSFML.hpp"
#include "Vector2.hpp"
#include "Texture.hpp"
#include "SFML\Graphics.hpp"


namespace DadEngine
{
	class DADENGINE_SFMLAPI SFTexture : public Texture
	{

	public:

		SFTexture( std::string _sName );

		virtual ~SFTexture();


		// Get/Set
		sf::Texture& GetTexture();
		Vector2 GetSize();

		void SetTexture(const sf::Texture& _newTexture);


		// Get a copy
		virtual Texture* GetClone();


	private:

		// Member datas
		sf::Texture m_texture;

		Vector2 m_vSize;
	};
}

#endif // __SFTEXTURE_H_