#include <string.h>
#include <stdio.h>
#include "m_string.h"

/*
	Brute Force算法
	普通的字符串匹配算法
	复杂度为O(N * M)
*/
int m_brute_force(char* ori, char* patter)
{
	if(!ori || !patter)
		return -1;

	char* o = ori;
	char* p = patter;
	char* c = o;
	int i = 1;
	while(*c)
	{
		if(*c == *p)
		{
			c++;
			p++;
			if(!*p)
				return (o - ori);
		}else
		{
			p = patter;
			c = ++o;
		}
		printf("i %d\n", i++);
	}

	return -1;
}

// int main()
// {
// 	printf("test %d\n", m_brute_force("cccccc", "ccg")); // 最坏情况: 设ori的长度为N， patter的长度为N那么执行次数应该是(N * M) - (N - 1)^2
// 	return 0;
// }