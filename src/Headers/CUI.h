/*
 * CUI.h
 *
 *  Created on: Jan 2, 2014
 *      Author: zZelman
 */

#ifndef CUI_H_
#define CUI_H_

#include "include_sfml.h"
#include "CPlayer.h"
#include "IUpdateable.h"
#include "AUserInput.h"

/**
 * 'Parses' user events, as well as keeps
 * Bookkeeping information on several user states.
 *
 * Keeps bookkeeping information for the states
 * of keys that are bound to spawn Rooms/Units
 *
 * Tells the 'Spawner' module to spawn specific
 * objects based on current values of the key states
 *
 * Uses a finite state machine to determine how
 * user events are interpreted (menu vs. game-play)
 */
class CUI: public AUserInput, public IUpdateable
{
public:
	CUI(CPlayer* pPlayer);
	~CUI();

	void update();

	bool userInput_keyPress(sf::Event* pEvent);
	bool userInput_keyRelease(sf::Event* pEvent);

	bool userInput_mousePress(sf::Event* pEvent);
	bool userInput_mouseRelease(sf::Event* pEvent);


private:
	/**
	 * TEMPORARY.
	 *
	 * This will only exist as long as the simple example does
	 */
	CPlayer* m_pPlayer;

	/**
	 * Utility function only used by the constructor to set what key
	 * presses are acceptable to spawn a room.
	 */
	void setRoomKeybinds();
};

#endif /* CUI_H_ */
