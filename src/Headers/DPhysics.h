/*
 * DPhysics.h
 *
 *  Created on: Dec 13, 2013
 *      Author: zZelman
 */

#ifndef DPHYSICS_H_
#define DPHYSICS_H_

#include "include_sfml.h"

class DPhysics
{
public:
	DPhysics();
	virtual ~DPhysics();

	/**
	 * Physics Data
	 */
	struct SPhysics
	{
		sf::Clock gravityTimer; // used in parabolic curve modeling
		int velosity_x;
		int velosity_y;

		bool isFalling;

		void nullAll();
	} m_sPhysics;

	/**
	 * A normal step in 1 update call
	 *
	 * When this method is called, it is assumed that there will NOT
	 * be a collision within the next step based on the velocities
	 */
	virtual void stepNormally() = 0;
};

#endif /* DPHYSICS_H_ */
