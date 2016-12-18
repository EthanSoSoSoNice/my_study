#include <stdio.h>
#include <stdlib.h>
#include "m_hash.h"

int main()
{
	m_hash* hash = (m_hash*)malloc(sizeof(m_hash));
	hash_init(hash, 20);
	char* name = "wangweining";
	hash_int(hash, 20, name);
	printf("name:%s\n", hash_look(hash, 20));
	return 1;
}
