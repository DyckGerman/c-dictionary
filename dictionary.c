#include <stdio.h>
#include "dictionary.h"

void add_entry_to_dictionary(struct Dictionary * dict, struct DictionaryEntry * entry) {
    struct LinkedListNode * newNode = malloc(sizeof(struct LinkedListNode));
    newNode->dictionaryEntry = entry;

    if (dict->firstWord == NULL) {
        // create first node
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

    while (counter < index) {
        listNode = listNode->nextNode;
        counter++;
    }

    struct LinkedListNode * previousNode = listNode->previousNode;
    struct LinkedListNode * nextNode = listNode->nextNode;

    deallocate_dictionary_entry(listNode->dictionaryEntry);

    if (previousNode == NULL) {
        dictionary->firstWord = nextNode;
        if (nextNode != NULL) {
            nextNode->previousNode = NULL;
        }
    } else {
        previousNode->nextNode = nextNode;
    }

    if (nextNode == NULL) {
        dictionary->lastWord = previousNode;
        if (previousNode != NULL) {
            previousNode->nextNode = NULL;
        }
    } else {
        nextNode->previousNode = previousNode;
    }

    free(listNode);

    dictionary->dictionary_size--;
}

struct Dictionary * create_dictionary(long size) {
    struct Dictionary * dictionary = malloc(sizeof(struct Dictionary));
    dictionary->dictionary_size = 0;
    dictionary->firstWord = NULL;
    dictionary->lastWord = NULL;

    return dictionary;
}

struct DictionaryEntry * create_empty_dictionary_entry(size_t wordSize, size_t definitionSize) {
    struct DictionaryEntry * result = malloc(sizeof(struct DictionaryEntry));
    result->word = malloc(wordSize);
    result->definition = malloc(definitionSize);
    result->word[0] = '\0';
    result->definition[0] = '\0';

    return result;
}

struct DictionaryEntry * create_dictionary_entry(char * wordBuffer, char * definitionBuffer) {
    struct DictionaryEntry * result = malloc(sizeof(struct DictionaryEntry));
    result->definition = definitionBuffer;
    result->word = wordBuffer;

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
