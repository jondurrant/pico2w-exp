/*
 * BlinkWAgent.cpp
 *
 *  Created on: 27 Nov 2024
 *      Author: jondurrant
 */

#include "BlinkWAgent.h"
#include "stdio.h"
#include "pico/cyw43_arch.h"


//Blink Delay
#define DELAY			500

/***
 * Constructor

 */
BlinkWAgent::BlinkWAgent() {
}

/***
 * Destructor
 */
BlinkWAgent::~BlinkWAgent() {
	stop();
}


 /***
  * Main Run Task for agent
  */
 void BlinkWAgent::run(){

	printf("Blink Started\n");

	cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN,  false);

	while (true) { // Loop forever
		cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN,  true);
		vTaskDelay(DELAY);
		cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN,  false);
		vTaskDelay(DELAY);
	}

 }

/***
 * Get the static depth required in words
 * @return - words
 */
configSTACK_DEPTH_TYPE BlinkWAgent::getMaxStackSize(){
	return 150;
}
