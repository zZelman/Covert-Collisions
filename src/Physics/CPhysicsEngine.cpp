/*
 * CPhysicsEngine.cpp
 *
 *  Created on: Dec 14, 2013
 *      Author: zZelman
 */

#include "../Headers/CPhysicsEngine.h"
#include <iostream>

CPhysicsEngine::CPhysicsEngine(CPlayer* pPlayer,
                               CTile_Container* pTile_Container)
{
	m_pTile_Container = pTile_Container;

	m_pPlayer = pPlayer;

}


CPhysicsEngine::~CPhysicsEngine()
{
}


void CPhysicsEngine::update()
{
	n2_collision();
}


void CPhysicsEngine::n2_collision()
{
	std::cout << "fall: " << m_pPlayer->m_sPhysics.isFalling << std::endl
	          << "jump: " << m_pPlayer->m_sPhysics.isJumping << std::endl << std::endl;

	std::list<ARenderable*> tiles;
	m_pTile_Container->getCollisiondata(&tiles);

	std::list<ARenderable*> players;
	players.push_back(m_pPlayer);

	CTile* pTile = NULL;
	CPlayer* pPlayer = NULL;
	bool canStepNormally = true;
	std::list<DPhysics*> normals; // objects that can step normally


	for (std::list<ARenderable*>::iterator itr_players = players.begin();
	        itr_players != players.end();
	        ++itr_players)
	{
		canStepNormally = true;

		pPlayer = dynamic_cast<CPlayer*>(*itr_players);
		applyPhysics(pPlayer);

		for (std::list<ARenderable*>::iterator itr_tiles = tiles.begin();
		        itr_tiles != tiles.end();
		        ++itr_tiles)
		{
			pTile = dynamic_cast<CTile*>(*itr_tiles);

			if (player_tile(pPlayer, pTile) == true)
			{
				canStepNormally = false;
				break;
			}
		}

		if (canStepNormally == true)
		{
			normals.push_front(pPlayer);

			if (pPlayer->m_sPhysics.isJumping == false)
			{
				pPlayer->m_sPhysics.isFalling = true;
			}
		}

	}

	applyStepNormally(&normals);
}


bool CPhysicsEngine::player_tile(CPlayer* pPlayer, CTile* pTile)
{
	// pull required data from pRoom
	sf::FloatRect futureRect = pPlayer->getGlobalBounds();

	// test the future
	futureRect.top += pPlayer->m_sPhysics.velosity_y;

	sf::FloatRect tileRect = pTile->getGlobalBounds();

	if (futureRect.intersects(tileRect))
	{
		if (pPlayer->m_sPhysics.velosity_y > 0) // moving down
		{
			int newY = tileRect.top - futureRect.height;
			pPlayer->setPosition(futureRect.left, newY);
		}
		else if (pPlayer->m_sPhysics.velosity_y < 0) // moving up
		{
			int newY = tileRect.top + tileRect.height;
			pPlayer->setPosition(futureRect.left, newY);
		}
		else
		{
#ifdef DEBUG
			// I have no idea when this case would be called, but i want
			//		to know when it does
			bool isNoVelosity = false;
			assert("Collision with no velocity [CPhysicsEngine::applyPhysics()] " && isNoVelosity);
#endif
		}

		// common to all collisions
		pPlayer->m_sPhysics.gravityTimer.restart();
		pPlayer->m_sPhysics.isFalling = false;
		pPlayer->m_sPhysics.isJumping = false;

		return true;
	}

	return false;
}

void CPhysicsEngine::applyPhysics(DPhysics* pObject)
{
	sf::Time timer = pObject->m_sPhysics.gravityTimer.getElapsedTime();

	double elapsed = timer.asMilliseconds();

	// make game look nice
	// remember 'elapsed' is in MS, this reduces that massive x var
	double reductionFactor = 0.005;

	bool isJumping = pObject->m_sPhysics.isJumping;
	bool isFalling = pObject->m_sPhysics.isFalling;

	if (isJumping)
	{
		pObject->m_sPhysics.velosity_y = 2 * (reductionFactor * elapsed) - 10;
	}

	if (isFalling)
	{
		pObject->m_sPhysics.velosity_y = 2 * (reductionFactor * elapsed);
	}
}


void CPhysicsEngine::applyStepNormally(std::list<DPhysics*>* pList)
{
	for (std::list<DPhysics*>::iterator itr = pList->begin();
	        itr != pList->end();
	        ++itr)
	{
		(*itr)->stepNormally();
	}
}
