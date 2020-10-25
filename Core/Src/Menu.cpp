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
	MenuItems[0] = "Main";
	MenuItems[1] = "Chanel1";
	MenuItems[2] = "Chanel2";
	MenuItems[3] = "Chanel3";
	MenuItems[4] = "Chanel4";
	MenuItems[5] = "Chanel5";
	MenuItems[6] = "Chanel6";
	MenuItems[7] = "Reset settings";


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
