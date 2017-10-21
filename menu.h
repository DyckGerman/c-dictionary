#ifndef MENU_H
#define MENU_H

#include <stdlib.h>

#include "dictionary.h"

typedef void (*ActionPointer)(struct Dictionary*);

struct MenuPage {
    int actionsCount;
    char * displayString;
    ActionPointer * actionsArray;
    int * exitFlag;
};

struct MenuPage * create_main_menu(int * exitFlag);

int show_menu_page(struct MenuPage * menuPage, struct Dictionary * dictionary);

#endif
