struct data{
	mutable int i;
	short s;
};

const struct data a = {
	.i = 1,
	.s = 1,
};

int main()
{
	a.i = 10;//ok,����a��ֻ�����󣬵���i��mutable��Ա��,�ܱ��޸�
	a.s = 10;//error��a��ֻ�����󣬹ʴ�s��Ա���ܱ��޸�	
}


