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
     * Array of pointers to dictionary entries
     */
    struct DictionaryEntry ** words;
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
 * with empty word and definition
 * @param wordSize - word length
 * @param definitionSize - definition length
 * @return pointer to dictionary entry
 */
struct DictionaryEntry * create_empty_dictionary_entry(int wordSize, int definitionSize);

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
struct Dictionary * create_dictionary(long size);

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
 * Frees the memory allocated for word and definition
 * @param entry - pointer to dictionary entry
 */
void deallocate_dictionary_entry(struct DictionaryEntry * entry);

#endif
