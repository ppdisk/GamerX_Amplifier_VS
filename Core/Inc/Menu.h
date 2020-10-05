/*
 * Menu.h
 *
 *  Created on: Sep 30, 2020
 *      Author: macukov-ma
 */

#include "stm32f1xx_hal.h"
#include <string>

#ifndef MENU_H_
#define MENU_H_

class Menu {
public:
	Menu();
	void NextItem(void);
	std::string CurrentMenutext(void);
private:
	uint8_t CurrentItem;
	std::string MenuItems[6];
};

#endif /* MENU_H_ */
