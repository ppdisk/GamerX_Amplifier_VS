/*
 * Menu.cpp
 *
 *  Created on: Sep 30, 2020
 *      Author: macukov-ma
 */

#include "Menu.h"

Menu::Menu()
{
	this->CurrentItem = 0;
	MenuItems[0] = "Chanel1";
	MenuItems[1] = "Chanel2";
	MenuItems[2] = "Chanel3";
	MenuItems[3] = "Chanel4";
	MenuItems[4] = "Chanel5";
	MenuItems[5] = "Chanel6";
	MenuItems[6] = "Reset settings";


}

void Menu::NextItem(void)
{
	CurrentItem++;
	if(CurrentItem==sizeof(MenuItems))
		CurrentItem = 0;


}

std::string Menu::CurrentMenutext(void)
{
	return MenuItems[CurrentItem];
}
