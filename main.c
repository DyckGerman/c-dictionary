#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "dictionary.h"
#include "menu.h"
#include "storage_manager.h"
#include "user_interactions.h"

const char storagePath[]  = "../test.txt";
const int MAX_WORD_SIZE = 128;
const int MAX_DEFINITION_SIZE = 1000;


int main() {
    // Initialize dictionary
    struct Dictionary * dict = load_dictionary_from_disk();

    int exitFlag = 0;
    struct MenuPage * mainMenu = create_main_menu(&exitFlag);

    while(!exitFlag) {
        show_menu_page(mainMenu, dict);
    }

    deallocate_dictionary(dict);

    return 0;
}
