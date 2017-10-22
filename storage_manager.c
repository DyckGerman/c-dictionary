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

    struct Dictionary * dictionary = create_dictionary(1000);

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

    fclose(fp);
    return dictionary;
}

void save_dictionary_to_disk(struct Dictionary * dictionary) {
    FILE *fp;
    fp = fopen(storagePath, "w");

    if (fp == NULL) {
        printf("Failed to save dictionary to file");
        exit(1);
    }

    struct LinkedListNode * listNode = dictionary->firstWord;

    while (listNode != NULL) {
        fprintf(fp, "%s§%s\n", listNode->dictionaryEntry->word, listNode->dictionaryEntry->definition);
        listNode = listNode->nextNode;
    }

    fclose(fp);
}
