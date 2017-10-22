#include <stdio.h>
#include <string.h>
#include "dictionary.h"
#include "storage_manager.h"
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
    printf("%s","The word added. Press Enter to continue\n");
    getchar();

    system("clear");
}

void show_dictionary(struct Dictionary * dictionary) {
    system("clear");
    print_dictionary(dictionary);

    printf("%s","Press Enter to continue\n");
    getchar();
    system("clear");
}

struct LinkedListNode * get_occurence_indices(struct Dictionary * dictionary, char * prefix) {
    struct LinkedListNode * listNode = dictionary->firstWord;
    struct LinkedListNode * matchedNode = NULL;
    struct LinkedListNode * lastMatchedNode = NULL;

    while (listNode != NULL) {
        if (strstr(listNode->dictionaryEntry->word, prefix) != NULL) {
            if (matchedNode == NULL) {
                matchedNode = lastMatchedNode = malloc(sizeof(struct LinkedListNode));
            }

            lastMatchedNode->nextNode = malloc(sizeof(struct LinkedListNode));
            lastMatchedNode->nextNode = lastMatchedNode;

            lastMatchedNode->dictionaryEntry = listNode->dictionaryEntry;
            lastMatchedNode->nextNode = NULL;
        }

        listNode = listNode->nextNode;
    }

    return matchedNode;
}

void find_word(struct Dictionary * dictionary) {
    system("clear");
    printf("%s","Enter the word and press the Enter key\n");
    char * prefixBuffer = malloc(MAX_WORD_SIZE);
    scanf("%128[^\n]", prefixBuffer);
    flush_istream();

    system("clear");

    struct LinkedListNode * indices = get_occurence_indices(dictionary, prefixBuffer);

    if (indices == NULL) {
        printf("%s","Couldn't find your word\n");
    } else {
        struct LinkedListNode * iterator = indices;

        int index = 1;
        while(iterator != NULL) {
            print_dictionary_entry(iterator->dictionaryEntry, index);
            iterator = iterator->nextNode;
        }
    }

    printf("%s","Press Enter to continue\n");
    getchar();
    system("clear");
}

void delete_word(struct Dictionary * dictionary) {
    system("clear");
    printf("%s","Enter the word number and press the Enter key\n");
    int wordNumberBuffer;
    scanf("%d", &wordNumberBuffer);
    flush_istream();

    if (dictionary->firstWord == NULL) {
        printf("%s","There are no words in the dictionary. Press Enter to continue\n");
        getchar();
    }

    if (dictionary->firstWord == NULL) {
        printf("%s","There are no words in the dictionary. Press Enter to continue\n");
        getchar();
    }

    if (wordNumberBuffer > dictionary->dictionary_size) {
        printf("%s","The word number exceeds the dictionary size. Press Enter to continue\n");
        getchar();
        system("clear");
        return;
    }

    delete_entry_from_dictionary(dictionary, wordNumberBuffer - 1);

    printf("%s","The word has been deleted. Press Enter to continue\n");
    getchar();

    system("clear");
}

void save_dictionary(struct Dictionary * dictionary) {
    save_dictionary_to_disk(dictionary);
}

void flush_istream() {
    int c;
    while((c= getchar()) != '\n' && c != EOF)
        /* discard */ ;
}
