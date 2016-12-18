#include <stddef.h>
#include "m_hashtree.h"

int mods[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void ht_init(hashtree* ht)
{
	ht->count = 0;
	ht->root = (ht_node*)malloc(sizeof(ht_node));
	htnd_init(ht->root, 0);
}

void htnd_init(ht_node* node, int n)
{
	node->occupied = 0;
	node->nodes = (ht_node*)malloc(sizeof(ht_node) * mods[n]);
	memset(node->nodes, 0, sizeof(ht_node) * mods[n]);
}

int ht_insert(hashtree* ht, int key, void* data)
{
	ht_node* node = ht->root;
	int c = 0;
	while(c < 10)
	{
		int m = mods[c] % key;
		ht_node* target;
		if(node->nodes[m] == 0)
		{
			htnd_init(node->nodes+m, c + 1);
			target = &node->nodes[m];
		}else
			target = &node.nodes[m];

		if(target->occupied)
		{
			if(target->key == key)
			{
				target-> data = data;
				return 0 ;
			}
			node = target;
			c++;
			continue;
		}

		target->key = key;
		target->data = data;
		target->occupied = 1;
	}
	return 1;
}
void ht_delete(hashtree* ht, int key)
{
	ht_node* node = ht->root;
	int c = 0;
	while(c < 10)
	{
		int m = mods[c] % key;
		ht_node* target;
		if(node->nodes[m] == NULL)
			return;
		else
			target = &node->nodes[m];

		if(target->occupied && target->key == key)
		{
			free(target->data);
			target->key = 0;
			target->occuied = 0;
			return;
		}
		node = target;
		c++;
		continue;
	}
}
void* ht_find(hashtree *ht, int key)
{
	ht_node* node = ht->root;
	int c = 0;
	while(c < 10)
	{
		int m = mods[c] % key;
		ht_node* target;
		if(node->nodes[m] == NULL)
			return NULL;
		else
			target = &node->nodes[m];

		if(target->occupied && target->key == key)
			return target->data;

		node = target;
		c++;
		continue;
	}
}