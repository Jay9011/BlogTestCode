typedef struct MyStruct
{
	int a;
} MS;

int main()
{
	// typedef를 사용하지 않은 경우 struct 키워드를 사용해야 한다.
	struct MyStruct myStruct;
	myStruct.a = 10;

	// typedef를 사용한 경우 struct 키워드를 사용하지 않아도 된다.
	MS myStruct2;
	myStruct2.a = 10;
}