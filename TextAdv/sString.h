#pragma once


enum eStringType
{
	TEXT,		// 0
	BRANCH,		// 1
	QUIT,		// 2
};

class sString
{
public:
	eStringType _type;
	char _text[256];
	int _selectY;
	int _selectN;

	sString* _prev;	// ���� ����
	sString* _next;	// ���� ����

	void Init(const char* text, eStringType type);
	void Init(const char* text, eStringType type, int selectY, int selectN);
	void Print();
};