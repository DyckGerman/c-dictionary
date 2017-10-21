#ifndef USER_INTERACTIONS_H
#define USER_INTERACTIONS_H

#include "dictionary.h"

void new_word(struct Dictionary * dictionary);
void show_dictionary(struct Dictionary * dictionary);
void find_word(struct Dictionary * dictionary);
void save_and_exit();

void flush_istream();

#endif