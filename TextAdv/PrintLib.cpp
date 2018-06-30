#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "PrintLib.h"

void sString::InitString(sString* string, const char* text, eStringType type)
{
	string->_type = type;
	strcpy_s(string->_text, text);
}
void sString::InitString(sString* string, const char* text, eStringType type, int selectY, int selectN)
{
	InitString(string, text, type);
	string->_selectY = selectY;
	string->_selectN = selectN;
}

void AddStringToParagraph(sParagraph* paragraph, sString* string)
{
	// ù ������ ��, ù ������ �ƴ� �� ������ �ٸ���.
	if (NULL == paragraph->current)
	{
		// ù ���� (paragraph->current : ù ����)
		paragraph->current = string;	// ���� ���� ����
		string->_prev = NULL;
		string->_next = NULL;
		paragraph->start = string;
	}
	else
	{
		// ù ���� �ƴ�
		paragraph->current->_next = string;
		string->_prev = paragraph->current;
		string->_next = NULL;
		paragraph->current = string;
	}
}

int PrintParagraph(sParagraph* paragraph)
{
	// ���� ����� ������ ù �������� ����
	// (ù ���� ���� ���)
	paragraph->current = paragraph->start;
	// ���� ������ �����ϴ� �� �ݺ� (NULL �̸� ����)
	// != : �ƴϸ�
	// ������ ������ �𸣴� ���¿��� �ݺ��� �����Ѵ�.
	while(NULL != paragraph->current)
	{
		// stringList[i] : i ��° �ִ� ����
		// current : ���� ����
		// stringList[i].  ==>  current->
		switch (paragraph->current->_type)
		{
		case TEXT:
			PrintText(paragraph->current->_text);
			break;
		case BRANCH:
			PrintText(paragraph->current->_text);
			while (true)
			{
				char ch = _getche();
				if ('y' == ch || 'Y' == ch)
				{
					return paragraph->current->_selectY;
				}
				else if ('n' == ch || 'N' == ch)
				{
					return paragraph->current->_selectN;
				}
				else if ('q' == ch || 'Q' == ch || 27 == ch)	// 27 : ESC
				{
					return -1;	// ����
				}
			}
			break;
		case QUIT:
			PrintText(paragraph->current->_text);
			return -1;	// ����
		}

		paragraph->current = paragraph->current->_next;
	}

	return 0;
}

void AddParagraphToList(sParagraphList* paragraphList, sParagraph* paragraph)
{
	paragraphList->list[paragraphList->count] = *paragraph;
	paragraphList->count++;
}

void PrintText(const char* text)
{
	printf(text);
	printf("\n");
}
