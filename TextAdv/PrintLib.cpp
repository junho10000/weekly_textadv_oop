#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "PrintLib.h"

void InitString(sString* string, const char* text, eStringType type)
{
	string->type = type;
	strcpy_s(string->text, text);
}
void InitString(sString* string, const char* text, eStringType type, int selectY, int selectN)
{
	InitString(string, text, type);
	string->selectY = selectY;
	string->selectN = selectN;
}

void AddStringToParagraph(sParagraph* paragraph, sString* string)
{
	/*
	paragraph->stringList[paragraph->count] = *text;
	paragraph->count++;	// 1�� ����
	*/
	// ù ������ ��, ù ������ �ƴ� �� ������ �ٸ���.
	if (NULL == paragraph->current)
	{
		// ù ���� (paragraph->current : ù ����)
		paragraph->current = string;	// ���� ���� ����
		string->prev = NULL;
		string->next = NULL;
		paragraph->start = string;
	}
	else
	{
		// ù ���� �ƴ�
		// current ���� "ù ����" �̶�� ���� ����
		// string ���� "�ι� ° ����" �̶�� ���� ����
		paragraph->current->next = string;
		string->prev = paragraph->current;
		string->next = NULL;
		paragraph->current = string;
	}
}

int PrintParagraph(sParagraph* paragraph)
{
	/*
	for (int i = 0; i < paragraph->count; i++)
	{
		switch (paragraph->stringList[i].type)
		{
		case TEXT:	// case 0:
			PrintText(paragraph->stringList[i].text);
			break;
		case BRANCH:	// case 1:
			PrintText(paragraph->stringList[i].text);
			// �䱸����
			// ������ �����ϱ� �������� �ӹ��� ���̾� �Ѵ�.
			// ������ y or n �� �����ϸ� ����.
			// ������ ���ÿ� ���� ���� ������ ������ �ε����� ����
			while (true)
			{
				// || : or, �Ǵ�
				// && : and, �׸���
				// == : equal, ������
				char ch = _getche();
				if ('y' == ch || 'Y' == ch)
				{
					return paragraph->stringList[i].selectY;
				}
				else if ('n' == ch || 'N' == ch)
				{
					return paragraph->stringList[i].selectN;
				}
				else if ('q' ==ch || 'Q' == ch || 27 == ch)	// 27 : ESC
				{
					return -1;	// ����
				}
			}
			break;
		case QUIT:	// case 2:
			PrintText(paragraph->stringList[i].text);
			return -1;	// ����
		}
	}
	*/

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
		switch (paragraph->current->type)
		{
		case TEXT:
			PrintText(paragraph->current->text);
			break;
		case BRANCH:
			PrintText(paragraph->current->text);
			while (true)
			{
				char ch = _getche();
				if ('y' == ch || 'Y' == ch)
				{
					return paragraph->current->selectY;
				}
				else if ('n' == ch || 'N' == ch)
				{
					return paragraph->current->selectN;
				}
				else if ('q' == ch || 'Q' == ch || 27 == ch)	// 27 : ESC
				{
					return -1;	// ����
				}
			}
			break;
		case QUIT:
			PrintText(paragraph->current->text);
			return -1;	// ����
		}

		paragraph->current = paragraph->current->next;
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
