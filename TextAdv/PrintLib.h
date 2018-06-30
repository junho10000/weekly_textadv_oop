#pragma once

enum eStringType
{
	TEXT,		// 0
	BRANCH,		// 1
	QUIT,		// 2
};

struct sString
{
	eStringType type;
	char text[256];
	int selectY;
	int selectN;

	sString* prev;	// 이전 문장
	sString* next;	// 다음 문장
};

struct sParagraph
{
	/*
	sString* stringList;
	int count;
	*/
	sString* start;		// 시작 문장
	sString* current;	// 현재 출력해야 할 문장
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