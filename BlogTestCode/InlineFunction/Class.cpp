class MyClass
{
public:
	int getNum() const { return num; }

private:
	int num;
};

int main()
{
	MyClass myClass;
	myClass.getNum();
}