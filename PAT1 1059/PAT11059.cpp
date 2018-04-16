// PAT11059.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct student {
	int name;
	int reward;
}C;

int cmp(const void *p1, const void *p2) {
	C *p = (struct student *)p1;
	C *q = (struct student *)p2;
	return p->name - q->name;
}

//判断整形数i是否为正整数，若返回1（true），否返回0（false）
bool isZHISHU(int i) {
	int n;
	for (n = 2; n <= sqrt(i); n++)
	{
		if (i%n == 0)
		{
			return 0;
		}
	}
	return 1;
}

/*在得奖名单rewardlist中用二分查找名字为search的元素，返回特征值
-2：未找到；
3：找到0；
4：找到1；
5：找到2；
*/
int giftis(C *rewardlist,int search, int left, int right) {
	int x = (left + right) / 2;
	if (search == rewardlist[x].name)
	{
		rewardlist[x].reward += 3;
		return rewardlist[x].reward;
	}
	else if (left == right)
	{
		return -2;
	}
	else
	{
		if (search > rewardlist[x].name)
		{
			return giftis(rewardlist, search, x + 1, right);
		}
		else
		{
			return giftis(rewardlist, search, left, x - 1);
		}
	}
}

int main()
{
	int count, i;
	static C rewardlist[10001];
	scanf_s("%d", &count);
	int t;
	scanf_s("%d", &rewardlist[0].name);
	rewardlist[0].reward = 0;
	for (i = 1; i < count; i++)
	{
		scanf_s("%d", &rewardlist[i].name);
		if (isZHISHU(i + 1) == 1)
		{
			rewardlist[i].reward = 1;
		}
		else
		{
			rewardlist[i].reward = 2;
		}
	}
	qsort(rewardlist, count, sizeof(rewardlist[0]), cmp);
	int count2;
	scanf_s("%d", &count2);
	for (i = 0; i < count2; i++)
	{
		scanf_s("%d", &t);
		printf("%04d: ", t);
		switch (giftis(rewardlist, t, 0, count - 1))
		{
		case -2:
			printf("Are you kidding?\n");
			break;
		case 3:
			printf("Mystery Award\n");
			break;
		case 4:
			printf("Minion\n");
			break;
		case 5:
			printf("Chocolate\n");
			break;
		default:
			printf("Checked\n");
			break;
		}
	}
    return 0;
}

