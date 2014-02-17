/*
 * CPlayer.cpp
 *
 *  Created on: Feb 14, 2014
 *      Author: zZelman
 */

#include "../Headers/CPlayer.h"
#include <iostream>

CPlayer::CPlayer(CTexture* pTexture, const sf::Vector2<int>& currSub)
	: ARenderable(pTexture, currSub), AUpdate()
{
	moveStep = 3;

	setKeybinds();

}


CPlayer::~CPlayer()
{
}


void CPlayer::setKeybinds()
{
	m_sKeys.nullStates();

	m_sKeys.up 		= sf::Keyboard::W;
	m_sKeys.down 	= sf::Keyboard::S;
	m_sKeys.left 	= sf::Keyboard::A;
	m_sKeys.right 	= sf::Keyboard::D;
}


void CPlayer::update()
{
	if (m_isFirstUpdate)
	{
//		m_sPhysics.nullAll();
		m_isFirstUpdate = false;
		return;
	}

	if (m_sKeys.isUp && !m_sKeys.isDown)
	{
		move_up();
	}

	if (m_sKeys.isDown && !m_sKeys.isUp)
	{
		move_down();
	}

	if (m_sKeys.isLeft && !m_sKeys.isRight)
	{
		move_left();
	}

	if (m_sKeys.isRight && !m_sKeys.isLeft)
	{
		move_right();
	}
}


bool CPlayer::userInput_keyPress(sf::Event* pEvent)
{
	// up
	if (pEvent->key.code == m_sKeys.up)
	{
		m_sKeys.isUp = true;

		return true;
	}

	// down
	if (pEvent->key.code == m_sKeys.down)
	{
		m_sKeys.isDown = true;

		return true;
	}

	// left
	if (pEvent->key.code == m_sKeys.left)
	{
		m_sKeys.isLeft = true;

		return true;
	}

	// right
	if (pEvent->key.code == m_sKeys.right)
	{
		m_sKeys.isRight = true;

		return true;
	}


	// UI not consumed
	return false;
}


bool CPlayer::userInput_keyRelease(sf::Event* pEvent)
{
	// up
	if (pEvent->key.code == m_sKeys.up)
	{
		m_sKeys.isUp = false;

		return true;
	}

	// down
	if (pEvent->key.code == m_sKeys.down)
	{
		m_sKeys.isDown = false;

		return true;
	}

	// left
	if (pEvent->key.code == m_sKeys.left)
	{
		m_sKeys.isLeft = false;

		return true;
	}

	// right
	if (pEvent->key.code == m_sKeys.right)
	{
		m_sKeys.isRight = false;

		return true;
	}


	// UI not consumed
	return false;
}


bool CPlayer::userInput_mousePress(sf::Event* pEvent)
{
	return false;
}


bool CPlayer::userInput_mouseRelease(sf::Event* pEvent)
{
	return false;
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
