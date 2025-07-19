#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>

typedef struct PeoInf {
	char name[20];
	char gender[6];
	int age;
	char phone[11];
	char address[50];
} PeoInf;

typedef struct Contact {
	PeoInf data[1000];
	int size;
}Contact;

void InitContact(Contact* con);

void AddContact(Contact* con);

void ShowContact(const Contact* con);//显示联系人

void DelContact(Contact* con);//删除联系人

void SearchContact(const Contact* con);//查找联系人

void ModifyContact(Contact* con);//修改联系人

void SortContact(Contact* con);//排序联系人

void ClearContact(Contact* con);//清空联系人