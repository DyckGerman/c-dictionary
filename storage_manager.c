#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dictionary.h"

#include "storage_manager.h"

extern const char storagePath[];

const long wordBufferSize = 128;
const long definitionBufferSize = 1000;

struct Dictionary * load_dictionary_from_disk() {
    FILE *fp;
    fp = fopen(storagePath, "r");

    if (fp == NULL) {
        printf("Failed to load dictionary file. Exit");
        exit(1);
    }

    struct Dictionary * dictionary = create_dictionary(10);




    int readSuccess = 1;
    while(readSuccess != EOF) {
        char * wordBuffer = malloc(wordBufferSize);
        char * definitionBuffer = malloc(definitionBufferSize);

        readSuccess = fscanf(fp, "%[^§]§%10000[^\n]\n", wordBuffer, definitionBuffer);
        if (readSuccess != EOF) {
            struct DictionaryEntry * entry = create_dictionary_entry(wordBuffer, definitionBuffer);
            definitionBuffer = wordBuffer = NULL;
            add_entry_to_dictionary(dictionary, entry);

        } else {
            free(wordBuffer);
            free(definitionBuffer);
        }
    }




    return dictionary;
}
