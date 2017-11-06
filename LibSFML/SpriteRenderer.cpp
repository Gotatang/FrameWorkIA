/*Documentation										*/
/*@author	:	Quentin Ladevie						*/
/*@file		:	SpriteRenderer.cpp					*/
/*@date		:	06/01/2016							*/
/*@brief	:	Fichier source du sprite renderer	*/
#include "stdafx.h"
#include "SpriteRenderer.hpp"


namespace DadEngine
{
	SpriteRenderer::SpriteRenderer() : m_spriteTexture(NULL), m_spriteRectangle(NULL)
	{
	}

	SpriteRenderer::SpriteRenderer(SFTexture* _spriteTexture) : m_spriteTexture(_spriteTexture)
	{
		m_spriteRectangle = new Rectangle((float)m_spriteTexture->GetSize().GetX(), (float)m_spriteTexture->GetSize().GetY());
	}

	SpriteRenderer::SpriteRenderer(const SpriteRenderer& _copy)
	{
		m_spriteTexture = _copy.m_spriteTexture;
		m_spriteRectangle = _copy.m_spriteRectangle;
	}


	SpriteRenderer::~SpriteRenderer()
	{
		if (m_spriteTexture)
			delete m_spriteTexture;

		if (m_spriteRectangle)
			delete m_spriteRectangle;
	}


	// Handling functions
	bool SpriteRenderer::Update()
	{
		return true;
	}

	bool SpriteRenderer::Draw()
	{
		if (m_spriteTexture)
			m_spriteRectangle->Draw(m_spriteTexture);

		return true;
	}


	// Set
	void SpriteRenderer::SetTexture(SFTexture* _newTexture)
	{
		delete m_spriteTexture;
		m_spriteTexture = NULL;


		delete m_spriteRectangle;
		m_spriteRectangle = NULL;


		if (_newTexture)
		{
			m_spriteTexture = _newTexture;

			m_spriteRectangle = new Rectangle((float)m_spriteTexture->GetSize().GetX(), (float)m_spriteTexture->GetSize().GetY());
		}
	}


	// Operators
	SpriteRenderer& SpriteRenderer::operator=(const SpriteRenderer& _rightObject)
	{
		m_spriteTexture = _rightObject.m_spriteTexture;
		m_spriteRectangle = _rightObject.m_spriteRectangle;

		return *this;
	}
}