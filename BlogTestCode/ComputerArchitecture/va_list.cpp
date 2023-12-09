#include <iostream>
#include <cstdarg>

// std arg�� ����� �������� C ��Ÿ���� ���� �Ķ���� �Լ�
inline int __cdecl MyPrintf(const char* format, ...)
{
	va_list arg; // ���� ���� ����� ���� ����

	va_start(arg, format); // ���� ���� ��� �ʱ�ȭ

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'd':
				{
					int i = va_arg(arg, int); // ���� ���� ��Ͽ��� ���� ���ڸ� int�� �����ɴϴ�.
					std::cout << i;
				}
				break;
			case 'c':
				{
					char c = va_arg(arg, char);
					std::cout << c;
				}
				break;
			}
		}
		else
		{
			std::cout << *format;
		}
		format++;
	}

	va_end(arg); // ���� ���� ����� ����� �Ŀ��� va_end�� ȣ���� ���ڸ� ���� �մϴ�.

	return 0;
}

// �������� ���Ḧ ���� �Լ�
int _cdecl MyTPrintf(const char* format)
{
	std::cout << format << std::endl;
	return 0;
}

// C++11�� ���ø� ���� �Ķ���� (Variadic Templates) �Լ�
template<typename T, typename... Args>
int _cdecl MyTPrintf(const char* format, T value, Args... args)
{
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'd':
				std::cout << (int)value;
				break;
			case 'c':
				std::cout << (char)value;
				break;
			}
			
			return MyTPrintf(++format, args...);
		}
		else
		{
			std::cout << *format;
		}

		format++;
	}

	return 0;
}

int main()
{
	//MyPrintf("Hello! %c is %d in ASCII code.", 'A', 'A');

	//std::cout << std::endl;

	MyTPrintf("Hello! %c is %d in ASCII code.", 'A', 'A');
}