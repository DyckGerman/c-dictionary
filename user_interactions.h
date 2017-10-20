#ifndef USER_INTERACTIONS_H
#define USER_INTERACTIONS_H

#include "dictionary.h"

void new_word(struct Dictionary * dictionary);
void print_dictionary(struct Dictionary * dictionary);

void flush_istream();

#endif