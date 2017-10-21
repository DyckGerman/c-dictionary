#include <stdio.h>
#include "dictionary.h"

void add_entry_to_dictionary(struct Dictionary * dict, struct DictionaryEntry * entry) {
    // assign new entry pointer to last element of dictionary entry pointers array
    dict->words[dict->dictionary_size] = entry;

    // update dictionary size
    dict->dictionary_size++;
}

struct Dictionary * create_dictionary(long size) {
    struct Dictionary * dictionary = malloc(sizeof(struct Dictionary));
    dictionary->dictionary_size = 0;
    dictionary->words = malloc(size * sizeof(struct DictionaryEntry));
    return dictionary;
}

struct DictionaryEntry * create_empty_dictionary_entry(int wordSize, int definitionSize) {
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
    for (int wordNumber = 0; wordNumber < dict->dictionary_size; wordNumber++) {
        deallocate_dictionary_entry(dict->words[wordNumber]);
    }
    free(dict);
}

void deallocate_dictionary_entry(struct DictionaryEntry * entry) {
    free(entry->definition);
    free(entry->word);
    free(entry);
}

void print_dictionary(struct Dictionary * dictionary) {
    int i = 0;
    while (i < dictionary->dictionary_size) {
        print_dictionary_entry(dictionary->words[i]);
        i++;
    }
}

void print_dictionary_entry(struct DictionaryEntry * entry) {
    printf("%s\n\t%s\n\n", entry->word, entry->definition);
}
