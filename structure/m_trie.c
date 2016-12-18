#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "m_trie.h"

void destroy(void* data);
trie_node* create_trienode();
trie_node* search_node(m_list* list, char c);

void trie_init(trie* trie)
{
	trie->root = create_trienode();
}

trie_node* create_trienode()
{
	trie_node* node = (trie_node*)malloc(sizeof(trie_node));
	node->nodes = (m_list*)malloc(sizeof(m_list));
	list_init(node->nodes, &destroy);
	return node;
}

trie_node* search_node(m_list* list, char c)
{
	lnode* ln;
	if(!(ln = LHEAD(list)))
		return NULL;
	do
	{
		trie_node* node = (trie_node*)ln->data;
		if(*node->key == c)
			return node;
	}while((ln = ln->next));

	return NULL;
}



void trie_insert(trie* trie, char* c)
{
	trie_node* node = trie->root;
	do
	{
		trie_node* branch;
		if(!(branch = search_node(node->nodes, *c)))
		{
			branch = create_trienode();
			branch->key = c;
			if(!(*(c+1)))
				branch->is_end = 1;
			else
				branch->is_end = 0;
			list_int_t(node->nodes, branch);
		}
		node = branch;
	}while(*(++c));
}

int trie_find(trie *trie, char* c)
{
	trie_node* node = trie->root;
	do
	{
		if(!(node = search_node(node->nodes, *c)))
			break;
	}while(*(++c));
	return node->is_end;
}

void destroy(void* data)
{
	free(data);
}