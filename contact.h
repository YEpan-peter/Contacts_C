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

void ShowContact(const Contact* con);//��ʾ��ϵ��

void DelContact(Contact* con);//ɾ����ϵ��

void SearchContact(const Contact* con);//������ϵ��

void ModifyContact(Contact* con);//�޸���ϵ��

void SortContact(Contact* con);//������ϵ��

void ClearContact(Contact* con);//�����ϵ��