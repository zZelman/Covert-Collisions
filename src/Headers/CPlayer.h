/*
 * CPlayer.h
 *
 *  Created on: Feb 14, 2014
 *      Author: zZelman
 */

#ifndef CPLAYER_H_
#define CPLAYER_H_

#include "include_sfml.h"
#include "ARenderable.h"
#include "CTexture.h"

class CPlayer: public ARenderable
{
public:
	CPlayer(CTexture* pTexture,
	        const sf::Vector2<int>& currSub);
	~CPlayer();

	void move_up();
	void move_down();
	void move_left();
	void move_right();

private:
	/**
	 * linear movement step while a move key is down.
	 */
	int moveStep;

	/**
	 * Current bounds of the sprite.
	 *
	 * Allocated here to increase efficacy
	 */
	sf::FloatRect currentBounds;
};

#endif /* CPLAYER_H_ */
