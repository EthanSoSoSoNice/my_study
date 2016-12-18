#ifndef M_TRIE
#define M_TRIE
#include "m_list.h"

typedef struct trie_node_
{
	m_list* nodes;
	char* key;
	int is_end;
}trie_node;

typedef struct trie_
{
	trie_node* root;
}trie;

void trie_init(trie* trie);
void trie_insert(trie* trie, char* c);
int trie_find(trie* trie, char* c);
#endif