#include "dictionary.h"

/**
 * Reads dictionary from file
 * @return loaded dictionary
 */
struct Dictionary * load_dictionary_from_disk();

/**
 * Saves file to disk
 * @param dictionary - pointer to the dictionary to save
 */
void save_dictionary_to_disk(struct Dictionary * dictionary);
