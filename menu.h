#ifndef MENU_H
#define MENU_H

#include <stdlib.h>

#include "dictionary.h"

/**
 * Pointer to ahe ActionFunction where
 * ActionFunction is the function that accepts
 * pointer to the dictionary as a parameter
 */
typedef void (*ActionPointer)(struct Dictionary*);

/**
 * Abstract structure for menu page that stores
 * things to display and matching actions
 */
struct MenuPage {
    int actionsCount;
    char * displayString;
    ActionPointer * actionsArray;
    int * exitFlag;
};

/**
 * Creates MenuPage instance for main menu
 * @param exitFlag - the flag reference that will be
 * set to 1 if menu can be closed
 * @return - pointer to main menu page
 */
struct MenuPage * create_main_menu(int * exitFlag);

/**
 * Shows abstract menu page
 * @param menuPage - pointer to menu page to show
 * @param dictionary - dictionary reference to pass to the action functions
 * @return
 */
int show_menu_page(struct MenuPage * menuPage, struct Dictionary * dictionary);

#endif
