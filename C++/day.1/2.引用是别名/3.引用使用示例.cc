#include <stdio.h>

void xchang(int *px, int *py)
{
	printf("%s: x = %d, y = %d\n", __func__, *px, *py);
	int tmp = *px;
	*px = *py;
	*py = tmp;
	printf("%s: x = %d, y = %d\n", __func__, *px, *py);
}

void newxchang(int &a, int &b)
{
	printf("%s: x = %d, y = %d\n", __func__, a, b);
	int tmp = a;
	a = b;
	b = tmp;
	printf("%s: x = %d, y = %d\n", __func__, a, b);
}

int main(int argv, char *argc[])
{
	int x = 1, y = 2;

	xchang(&x, &y);

	newxchang(x, y);

	return 0;
}

