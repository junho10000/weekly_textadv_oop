#pragma once

class sString;

struct sParagraph
{
	sString* start;		// ���� ����
	sString* current;	// ���� ����ؾ� �� ����
};

struct sParagraphList
{
	int count;
	struct sParagraph* list;
};

void AddStringToParagraph(sParagraph* paragraph, sString* text);

void AddParagraphToList(sParagraphList* paragraphList, sParagraph* paragraph);

int PrintParagraph(sParagraph* paragraph);