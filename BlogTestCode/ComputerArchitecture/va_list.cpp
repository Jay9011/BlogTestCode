#include <iostream>
#include <cstdarg>

// std arg를 사용한 전통적인 C 스타일의 가변 파라미터 함수
inline int __cdecl MyPrintf(const char* format, ...)
{
	va_list arg; // 가변 인자 목록을 위한 변수

	va_start(arg, format); // 가변 인자 목록 초기화

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'd':
				{
					int i = va_arg(arg, int); // 가변 인자 목록에서 다음 인자를 int로 가져옵니다.
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

	va_end(arg); // 가변 인자 목록을 사용한 후에는 va_end를 호출해 인자를 정리 합니다.

	return 0;
}

// 가변인자 종료를 위한 함수
int _cdecl MyTPrintf(const char* format)
{
	std::cout << format << std::endl;
	return 0;
}

// C++11의 템플릿 가변 파라미터 (Variadic Templates) 함수
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