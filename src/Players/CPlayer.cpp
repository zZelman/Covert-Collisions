/*
 * CPlayer.cpp
 *
 *  Created on: Feb 14, 2014
 *      Author: zZelman
 */

#include "../Headers/CPlayer.h"

CPlayer::CPlayer(CTexture* pTexture, const sf::Vector2<int>& currSub)
	: ARenderable(pTexture, currSub)
{
	moveStep = 3;
}

CPlayer::~CPlayer()
{
}


void CPlayer::move_up()
{
	currentBounds = getGlobalBounds();

	int topX = currentBounds.left;
	int topY = currentBounds.top;

	m_pSprite->setPosition(topX, topY - moveStep);

	m_pSprite->setSubImage(1, 1);
}


void CPlayer::move_down()
{
	currentBounds = getGlobalBounds();

	int topX = currentBounds.left;
	int topY = currentBounds.top;

	m_pSprite->setPosition(topX, topY + moveStep);

	m_pSprite->setSubImage(2, 1);
}


void CPlayer::move_left()
{
	currentBounds = getGlobalBounds();

	int topX = currentBounds.left;
	int topY = currentBounds.top;

	m_pSprite->setPosition(topX - moveStep, topY);

	m_pSprite->setSubImage(1, 2);
}


void CPlayer::move_right()
{
	currentBounds = getGlobalBounds();

	int topX = currentBounds.left;
	int topY = currentBounds.top;

	m_pSprite->setPosition(topX + moveStep, topY);

	m_pSprite->setSubImage(2, 2);
}
