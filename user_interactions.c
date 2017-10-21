#include <stdio.h>
#include <string.h>
#include "dictionary.h"
#include "user_interactions.h"

extern unsigned int MAX_WORD_SIZE;
extern unsigned int MAX_DEFINITION_SIZE;

void new_word(struct Dictionary * dictionary) {
    system("clear");
    printf("%s","Enter the word and press the Enter key\n");
    char * wordBuffer = malloc(MAX_WORD_SIZE);
    scanf("%128[^\n]", wordBuffer);
    flush_istream();

    printf("%s","Enter the word definition\n");
    char * definitionBuffer = malloc(MAX_DEFINITION_SIZE);
    scanf("%1000[^\n]", definitionBuffer);
    flush_istream();

    struct DictionaryEntry * newEntry = create_dictionary_entry(wordBuffer,definitionBuffer);
    add_entry_to_dictionary(dictionary, newEntry);

    system("clear");
}

void show_dictionary(struct Dictionary * dictionary) {
    system("clear");
    print_dictionary(dictionary);

    printf("%s","Press Enter to continue\n");
    getchar();
    system("clear");
}

int * get_occurence_indices(struct Dictionary * dictionary, char * prefix) {
    int * indicesArray = malloc(dictionary->dictionary_size + 1);
    int * indicesArrayIterator = indicesArray;

    for (int i; i < dictionary->dictionary_size; i++) {
        if (strstr(dictionary->words[i]->word, prefix) != NULL) {
            *indicesArrayIterator = i;
            indicesArrayIterator++;
        }
    }

    *indicesArrayIterator = -1;

    if (indicesArrayIterator == indicesArray) {
        // iterator didn't move, no occurences found
        free(indicesArray);
        return NULL;
    } else {
        return indicesArray;
    }
}

void find_word(struct Dictionary * dictionary) {
    system("clear");
    printf("%s","Enter the word and press the Enter key\n");
    char * prefixBuffer = malloc(MAX_WORD_SIZE);
    scanf("%128[^\n]", prefixBuffer);
    flush_istream();

    int * indices = get_occurence_indices(dictionary, prefixBuffer);
    system("clear");

    if (indices == NULL) {
        printf("%s","Couldn't find your word\n");
    } else {
        int * index = indices;
        while(*index != -1) {
            print_dictionary_entry(dictionary->words[*index]);
            index++;
        }
    }

    printf("%s","Press Enter to continue\n");
    getchar();
    system("clear");
}

void save_and_exit() {
    exit(0);
}

void flush_istream() {
    int c;
    while((c= getchar()) != '\n' && c != EOF)
        /* discard */ ;
}
