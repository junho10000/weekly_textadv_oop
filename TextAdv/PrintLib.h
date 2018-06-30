#pragma once

enum eStringType
{
	TEXT,		// 0
	BRANCH,		// 1
	QUIT,		// 2
};

struct sString
{
	eStringType _type;
	char _text[256];
	int _selectY;
	int _selectN;

	sString* _prev;	// ���� ����
	sString* _next;	// ���� ����
};

struct sParagraph
{
	sString* start;		// ���� ����
	sString* current;	// ���� ����ؾ� �� ����
};

struct sParagraphList
{
	int count;
	//struct sParagraph list[256];
	struct sParagraph* list;
};

void InitString(sString* string, const char* text, eStringType type);
void InitString(sString* string, const char* text, eStringType type, int selectY, int selectN);

void AddStringToParagraph(sParagraph* paragraph, sString* text);

void AddParagraphToList(sParagraphList* paragraphList, sParagraph* paragraph);

void PrintText(const char* text);
int PrintParagraph(sParagraph* paragraph);