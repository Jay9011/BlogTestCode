typedef struct MyStruct
{
	int a;
} MS;

int main()
{
	// typedef�� ������� ���� ��� struct Ű���带 ����ؾ� �Ѵ�.
	struct MyStruct myStruct;
	myStruct.a = 10;

	// typedef�� ����� ��� struct Ű���带 ������� �ʾƵ� �ȴ�.
	MS myStruct2;
	myStruct2.a = 10;
}