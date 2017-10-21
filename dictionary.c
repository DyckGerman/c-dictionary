#include <stdio.h>
#include "dictionary.h"

void add_entry_to_dictionary(struct Dictionary * dict, struct DictionaryEntry * entry) {
    // assign new entry pointer to last element of dictionary entry pointers array
    dict->words[dict->dictionary_size] = entry;

    // update dictionary size
    dict->dictionary_size++;
}

void delete_entry_from_dictionary(struct Dictionary * dictionary, long index) {
    // as we store the words as a linear array
    // we are going to delete the word by placing the last one onto the
    // position of the word that should be deleted

    struct DictionaryEntry * wordToDelete = dictionary->words[index];
    struct DictionaryEntry * lastWord = dictionary->words[dictionary->dictionary_size - 1];

    free(wordToDelete->word);
    free(wordToDelete->definition);

    if (index != dictionary->dictionary_size - 1) {
        wordToDelete->word = lastWord->word;
        wordToDelete->definition = lastWord->definition;
    }

    lastWord->word = lastWord->definition = NULL;

    dictionary->dictionary_size--;
}

struct Dictionary * create_dictionary(long size) {
    struct Dictionary * dictionary = malloc(sizeof(struct Dictionary));
    dictionary->dictionary_size = 0;
    dictionary->words = malloc(size * sizeof(struct DictionaryEntry));
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
        print_dictionary_entry(dictionary->words[i], i);
        i++;
    }
}

void print_dictionary_entry(struct DictionaryEntry * entry, int index) {
    printf("%d. %s\n\t%s\n\n", index + 1, entry->word, entry->definition);
}
