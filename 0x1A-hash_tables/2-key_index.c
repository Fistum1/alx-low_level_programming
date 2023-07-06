#include "hash_tables.h"

/**
 * key_index - Which gets the index at where a key/value pair will.
 *
 * @key: Key to get the index of.
 * @size: Size of the array of the hash table.
 *
 * Return: Index key.
 * Description: Uses the djb2 algorithm.
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
