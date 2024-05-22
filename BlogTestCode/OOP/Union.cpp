#include <cstdio>
#include <Windows.h>

struct MyStruct
{
	int int1;
	short short1;
	char char1;
};

union MyUnion
{
	int int1;
	short short1;
	char char1;
};

typedef struct _D3DMATRIX {
    union {
        struct {
            float        _11, _12, _13, _14;
            float        _21, _22, _23, _24;
            float        _31, _32, _33, _34;
            float        _41, _42, _43, _44;
        };
		float m[4][4] = { 0, };
    };
} D3DMATRIX;

int main()
{
	printf("Size of MyStruct: %d\n", sizeof(MyStruct));
	printf("Size of MyUnion: %d\n", sizeof(MyUnion));

	_D3DMATRIX mat;
	mat._11 = 1.0f;
	mat._22 = 2.0f;
	mat.m[2][2] = 3.0f;

	for (int i = 0; i < 4; i++)
	{
		printf("%.0f %.0f %.0f %.0f\n", mat.m[i][0], mat.m[i][1], mat.m[i][2], mat.m[i][3]);
	}

	LARGE_INTEGER li;
}