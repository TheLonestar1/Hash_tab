#include"hashtab.h"
#define HASH_SIZE 2000000
int main()
{
	char **words = malloc(sizeof(**words) * HASH_SIZE);
	for(int i; i < HASH_SIZE; i++){
		char word[4];
		for(int j = 0; j < 4; j ++)
			word[j] = (char)rand() % 100;
		words[i] = word;	
	}
	struct listnode *node, **hashtab;
	hashtab = malloc(sizeof(*hashtab) * HASH_SIZE);
	hashtab_init(hashtab);
	for(int i = 0; i < HASH_SIZE; i++)
		hashtab_add(hashtab, words[i], rand() % 1000);
	node = hashtab_lookup(hashtab, "A");	
	if (node != NULL)
		printf("Node: %s, %d\n", node->key, node->value);
	return 0;
}
