#include <stdio.h>
#include <string.h>
#include "dictionary.h"

void add_entry_to_dictionary(struct Dictionary * dict, struct DictionaryEntry * entry) {
    struct LinkedListNode * newNode = malloc(sizeof(struct LinkedListNode));
    newNode->dictionaryEntry = entry;

    if (dict->firstWord == NULL) {
        // create first node if dictionary is empty
        dict->firstWord = newNode;
        newNode->previousNode = NULL;
    } else {
        // add new node to list end and update references
        dict->lastWord->nextNode = newNode;
        newNode->previousNode = dict->lastWord;
    }

    dict->lastWord = newNode;
    newNode->nextNode = NULL;

    // update dictionary size
    dict->dictionary_size++;
}

void delete_entry_from_dictionary(struct Dictionary * dictionary, long index) {
    struct LinkedListNode * listNode = dictionary->firstWord;
    int counter = 0;

    // iterate over nodes list to find node with specified index
    while (counter < index) {
        listNode = listNode->nextNode;
        counter++;
    }

    // create pointers to previous and next nodes
    struct LinkedListNode * previousNode = listNode->previousNode;
    struct LinkedListNode * nextNode = listNode->nextNode;

    // deallocate underlying dictionary entry
    deallocate_dictionary_entry(listNode->dictionaryEntry);

    if (previousNode == NULL) {
        // if node is the first
        dictionary->firstWord = nextNode;
        if (nextNode != NULL) {
            nextNode->previousNode = NULL;
        }
    } else {
        previousNode->nextNode = nextNode;
    }

    if (nextNode == NULL) {
        // if node is last
        dictionary->lastWord = previousNode;
        if (previousNode != NULL) {
            previousNode->nextNode = NULL;
        }
    } else {
        nextNode->previousNode = previousNode;
    }

    free(listNode);

    // update dictionary size
    dictionary->dictionary_size--;
}

struct Dictionary * create_dictionary() {
    struct Dictionary * dictionary = malloc(sizeof(struct Dictionary));
    dictionary->dictionary_size = 0;
    dictionary->firstWord = NULL;
    dictionary->lastWord = NULL;

    return dictionary;
}

struct DictionaryEntry * create_dictionary_entry(char * wordBuffer, char * definitionBuffer) {
    struct DictionaryEntry * result = malloc(sizeof(struct DictionaryEntry));

    result->word = malloc(strlen(wordBuffer) + 1);
    strcpy(result->word, wordBuffer);

    result->definition = malloc(strlen(definitionBuffer) + 1);
    strcpy(result->definition, definitionBuffer);
    
    return result;
}

void deallocate_dictionary(struct Dictionary * dict) {
    struct LinkedListNode * listNode = dict->firstWord;

    while (listNode != NULL) {
        deallocate_dictionary_entry(listNode->dictionaryEntry);
        struct LinkedListNode * nodeToDeallocate = listNode;
        listNode = listNode->nextNode;
        free(nodeToDeallocate);
    }

    free(dict);
}

void deallocate_dictionary_entry(struct DictionaryEntry * entry) {
    free(entry->definition);
    free(entry->word);
    free(entry);
}

void print_dictionary(struct Dictionary * dictionary) {
    struct LinkedListNode * listNode = dictionary->firstWord;
    int i = 0;

    while (listNode != NULL) {
        print_dictionary_entry(listNode->dictionaryEntry,i);
        i++;
        listNode = listNode->nextNode;
    }
}

void print_dictionary_entry(struct DictionaryEntry * entry, int index) {
    printf("%d. %s\n\t%s\n\n", index + 1, entry->word, entry->definition);
}
