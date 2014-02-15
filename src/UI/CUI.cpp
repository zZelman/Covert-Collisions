/*
 * CUI.cpp
 *
 *  Created on: Jan 2, 2014
 *      Author: zZelman
 */

#include "../Headers/CUI.h"

#include <iostream>

CUI::CUI(CPlayer* pPlayer)
{
	m_sKeys.nullStates();
	setRoomKeybinds();

	m_pPlayer = pPlayer;
}


CUI::~CUI()
{
}


void CUI::update()
{
}


bool CUI::userInput_keyPress(sf::Event* pEvent)
{
	// up
	if ((pEvent->key.code == m_sKeys.up) &&
	        (!m_sKeys.isUp))
	{
		m_sKeys.isUp = true;
		m_pPlayer->move_up();

		return true;
	}

	// down
	if ((pEvent->key.code == m_sKeys.down) &&
	        (!m_sKeys.isDown))
	{
		m_sKeys.isDown = true;
		m_pPlayer->move_down();

		return true;
	}

	// left
	if ((pEvent->key.code == m_sKeys.left) &&
	        (!m_sKeys.isLeft))
	{
		m_sKeys.isLeft = true;
		m_pPlayer->move_left();

		return true;
	}

	// right
	if ((pEvent->key.code == m_sKeys.right) &&
	        (!m_sKeys.isRight))
	{
		m_sKeys.isRight = true;
		m_pPlayer->move_right();

		return true;
	}


	return false;
}


bool CUI::userInput_keyRelease(sf::Event* pEvent)
{
	// up
	if ((pEvent->key.code == m_sKeys.up) &&
	        (m_sKeys.isUp))
	{
		m_sKeys.isUp = false;

		return true;
	}

	// down
	if ((pEvent->key.code == m_sKeys.down) &&
	        (m_sKeys.isDown))
	{
		m_sKeys.isDown = false;

		return true;
	}

	// left
	if ((pEvent->key.code == m_sKeys.left) &&
	        (m_sKeys.isLeft))
	{
		m_sKeys.isLeft = false;

		return true;
	}

	// right
	if ((pEvent->key.code == m_sKeys.right) &&
	        (m_sKeys.isRight))
	{
		m_sKeys.isRight = false;

		return true;
	}


	return false;
}


bool CUI::userInput_mousePress(sf::Event* pEvent)
{
	if (pEvent->mouseButton.button == sf::Mouse::Left)
	{
	}
	else if (pEvent->mouseButton.button == sf::Mouse::Right)
	{
	}

	return false;
}


bool CUI::userInput_mouseRelease(sf::Event* pEvent)
{
	if (pEvent->mouseButton.button == sf::Mouse::Left)
	{
	}
	else if (pEvent->mouseButton.button == sf::Mouse::Right)
	{
	}

	return false;
}

void CUI::setRoomKeybinds()
{
	m_sKeys.up 		= sf::Keyboard::W;
	m_sKeys.down 	= sf::Keyboard::S;
	m_sKeys.left 	= sf::Keyboard::A;
	m_sKeys.right 	= sf::Keyboard::D;
}
