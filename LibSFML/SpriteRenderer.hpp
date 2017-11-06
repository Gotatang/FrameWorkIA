/*Documentation										*/
/*@author	:	Quentin Ladevie						*/
/*@file		:	SpriteRenderer.hpp					*/
/*@date		:	06/01/2016							*/
/*@brief	:	Fichier d'en-tête du sprite renderer*/
#ifndef __SPRITERENDERER_H_
#define __SPRITERENDERER_H_

#include "ExportSFML.hpp"
#include "Component.hpp"


namespace DadEngine
{
	class Rectangle;

	class DADENGINE_SFMLAPI SpriteRenderer : public Component
	{

	public:

		SpriteRenderer();
		SpriteRenderer(SFTexture* _spriteTexture);
		SpriteRenderer(const SpriteRenderer& _copy);

		~SpriteRenderer();

		// Handling functions
		bool Update();
		bool Draw();

		// Set
		void SetTexture(SFTexture* _newTexture);


		// Operators
		SpriteRenderer& operator=(const SpriteRenderer& _rightObject);


	private:

		// Member datas
		Rectangle* m_spriteRectangle;
		SFTexture* m_spriteTexture;
	};
}

#endif // __SPRITERENDERER_H_