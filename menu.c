#include <stdio.h>
#include "menu.h"
#include "user_interactions.h"

ActionPointer * actions;

char * mainMenuDisplayString = "1. Print the dictionary\n2. Add word\n3. Find definition\n4. Delete word\n0. Exit\n\n";

int get_choice(const char * displayString) {
    printf("%s", displayString);
    int choice = 0;
    int success = scanf("%d", &choice);
    return choice;
}



struct MenuPage * create_main_menu() {
    struct MenuPage *mainMenu = malloc(sizeof(struct MenuPage));
    mainMenu->actionsCount = 5;
    mainMenu->displayString = mainMenuDisplayString;
    mainMenu->actionsArray = malloc(sizeof(ActionPointer) * 5);
    mainMenu->actionsArray[2] = &new_word;
    mainMenu->actionsArray[1] = &print_dictionary;


    return mainMenu;
}

int show_menu_page(struct MenuPage * menuPage, struct Dictionary * dictionary) {
    printf("%s",menuPage->displayString);
    int choice = 0;
    int success = scanf("%d", &choice) > 0 ;
    flush_istream();
    if (success && choice < menuPage->actionsCount) {
        (*(menuPage->actionsArray + choice)) (dictionary);
    } else {
        return 1;
    }

    return 0;
}


