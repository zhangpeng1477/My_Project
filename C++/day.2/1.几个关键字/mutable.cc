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
	a.i = 10;//ok,尽管a是只读对象，但是i是mutable成员域,能被修改
	a.s = 10;//error：a是只读对象，故此s成员域不能被修改	
}


