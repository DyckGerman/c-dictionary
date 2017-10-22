#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdlib.h>

/**
 * Structure that represents dictionary
 */
struct Dictionary {
    /**
     * Dictionary Words count
     */
    long dictionary_size;

    /**
     * First element of pointers array to dictionary entries
     */
    struct LinkedListNode * firstWord;

    /**
     * Last element of pointers array to dictionary entries
     */
    struct LinkedListNode * lastWord;
};

/**
 * Structure that wraps DictionaryEntry for insertion
 * into bidirectional linked list
 */
struct LinkedListNode {
    struct LinkedListNode * nextNode;
    struct LinkedListNode * previousNode;

    struct DictionaryEntry * dictionaryEntry;
};

/**
 * Main dictionary unit
 */
struct DictionaryEntry {
    /**
     * Word
     */
    char* word;

    /**
     * Words definition
     */
    char* definition;
};

/**
 * Creates new dictionary entry and initialises it
 * with word and definition passed as a function parameters
 * @param wordBuffer
 * @param definitionBuffer
 * @return
 */
struct DictionaryEntry * create_dictionary_entry(char * wordBuffer, char * definitionBuffer);

/**
 * Initialises new dictionary
 * @param size - words count in dictionary
 * @return pointer to dictionary
 */
struct Dictionary * create_dictionary();

/**
 * Frees the memory allocated for dictionary
 * @param dict
 */
void deallocate_dictionary(struct Dictionary * dict);

/**
 * Adds new dictionary entry to the end of the dictionary
 * @param dictionary - dictionary to put new entry
 * @param entry - new entry to put into the dictionary
 */
void add_entry_to_dictionary(struct Dictionary * dictionary, struct DictionaryEntry * entry);

/**
 * Deleted entry from the dictionary
 * @param dictionary - pointer to dictionary
 * @param index - index to delete
 */
void delete_entry_from_dictionary(struct Dictionary * dictionary, long index);

/**
 * Frees the memory allocated for word and definition
 * @param entry - pointer to dictionary entry
 */
void deallocate_dictionary_entry(struct DictionaryEntry * entry);

/**
 * Prints all the words and definitions
 * @param dictionary - pointer to dictionary
 */
void print_dictionary(struct Dictionary * dictionary);

/**
 * Prints word and definition
 * @param entry - pointer to dictionary entry
 * @param index - index of the word
 */
void print_dictionary_entry(struct DictionaryEntry * entry, int index);

#endif
