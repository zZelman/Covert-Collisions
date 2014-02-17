/*
 * CPhysicsEngine.cpp
 *
 *  Created on: Dec 14, 2013
 *      Author: zZelman
 */

#include "../Headers/CPhysicsEngine.h"

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

			if (player_tile(pPlayer, pTile) == false)
			{
				canStepNormally = false;
				break;
			}
		}

		if (canStepNormally == true)
		{
			normals.push_front(pPlayer);
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
		int newY = tileRect.top - futureRect.height;
		pPlayer->setPosition(futureRect.left, newY);

		pPlayer->m_sPhysics.gravityTimer.restart();

		pPlayer->m_sPhysics.isFalling = false;

		return false;
	}

	return true;
}

void CPhysicsEngine::applyPhysics(DPhysics* pObject)
{
	sf::Time timer = pObject->m_sPhysics.gravityTimer.getElapsedTime();
	int elapsed = timer.asMilliseconds();
	pObject->m_sPhysics.velosity_y = (0.01) * (elapsed);
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
