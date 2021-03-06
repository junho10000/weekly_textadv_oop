#include <stdio.h>
#include <string.h>

#include "sString.h"

void sString::Init(const char* text, eStringType type)
{
	_type = type;
	strcpy_s(_text, text);
}

void sString::Init(const char* text, eStringType type, int selectY, int selectN)
{
	Init(text, type);
	_selectY = selectY;
	_selectN = selectN;
}

void sString::Print()
{
	printf(_text);
	printf("\n");
}
