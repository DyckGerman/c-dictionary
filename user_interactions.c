#include <stdio.h>
#include "dictionary.h"
#include "user_interactions.h"

extern int MAX_WORD_SIZE;
extern int MAX_DEFINITION_SIZE;

void new_word(struct Dictionary * dictionary) {
    printf("%s","Enter the word and press the Enter key");
    char * wordBuffer = malloc(MAX_WORD_SIZE);
    scanf("%128[^\n]", wordBuffer);
    flush_istream();

    printf("%s","Enter the word definition");
    char * definitionBuffer = malloc(MAX_DEFINITION_SIZE);
    scanf("%1000[^\n]", definitionBuffer);
    flush_istream();

    struct DictionaryEntry * newEntry = create_dictionary_entry(wordBuffer,definitionBuffer);
    add_entry_to_dictionary(dictionary, newEntry);
}

void print_dictionary(struct Dictionary * dictionary) {
    int i = 0;
    while (i < dictionary->dictionary_size) {
        printf("%s\n\t%s\n\n", dictionary->words[i]->word, dictionary->words[i]->definition);
        i++;
    }
}

void flush_istream() {
    int c;
    while((c= getchar()) != '\n' && c != EOF)
        /* discard */ ;
}
