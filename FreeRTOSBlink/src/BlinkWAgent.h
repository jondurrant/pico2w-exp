/*
 * BlinkWAgent.h
 *
 * Active agent to run as task and blink and Pico 2 W onboard LED
 *
 *  Created on: 27 Nov 2024
 *      Author: jondurrant
 */

#ifndef BLINKAGENT_H_
#define BLINKAGENT_H_

#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"

#include "Agent.h"


class BlinkWAgent: public Agent {
public:
	/***
	 * Constructor
	 *
	 */
	BlinkWAgent();

	/***
	 * Destructor
	 */
	virtual ~BlinkWAgent();


protected:

	/***
	 * Run loop for the agent.
	 */
	virtual void run();


	/***
	 * Get the static depth required in words
	 * @return - words
	 */
	virtual configSTACK_DEPTH_TYPE getMaxStackSize();

};


#endif /* BLINKAGENT_H_ */
