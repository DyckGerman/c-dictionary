#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "dictionary.h"
#include "storage_manager.h"

const char storagePath[]  = "../test.txt";

int main() {
    struct Dictionary * dict = load_dictionary_from_disk();

    deallocate_dictionary(dict);

    return 0;
}


