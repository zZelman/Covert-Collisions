/*
 * IRenderable.h
 *
 *  Created on: Oct 10, 2013
 *      Author: zZelman
 */

#ifndef ARENDER_H_
#define ARENDER_H_

#include "include_sfml.h"
#include "CTexture.h"
#include "CSprite.h"

class ARenderable
{
public:
	ARenderable(CTexture* pTexture,
	            const sf::Vector2<int>& currSub);

	/**
	 * if this constructor is used, note that this object then takes responsibility
	 * for the CSprite*
	 */
	ARenderable(CSprite* pSprite);
	virtual ~ARenderable();

	CSprite* const getSprite();

	/**
	 * Returns the API version of this sprite
	 */
	sf::Sprite* const getSprite_API();
	sf::FloatRect getGlobalBounds();

	void setPosition(float x, float y);

protected:
	CSprite* m_pSprite;
};


#endif /* IRENDERABLE_H_ */
