#ifndef HASHTREE
#define HASHTREE

typedef struct ht_node_
{
	struct ht_node_* nodes;
	int key;
	void* data;
	int occupied;
}ht_node;

typedef struct hashtree_
{
	struct ht_node* root;
	int count;
}hashtree;

void ht_init(hashtree* ht);
int ht_insert(hashtree* ht, int key, void* data);
void* ht_find(hashtree* ht, int key);
void ht_delete(hashtree* ht, int key);



#endif