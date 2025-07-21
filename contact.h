//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include<assert.h>
//
//typedef struct PeoInf {
//	char name[20];
//	char gender[7];
//	int age;
//	char phone[12];
//	char address[50];
//} PeoInf;
//
//typedef struct Contact {
//	PeoInf data[1000];
//	int size;
//}Contact;
//
//void InitContact(Contact* con);
//
//void AddContact(Contact* con);
//
//void ShowContact(const Contact* con);
//
//void DelContact(Contact* con);
//
//void SearchContact(const Contact* con);
//
//void ModifyContact(Contact* con);
//
//void SortContact(Contact* con);
//
//void ClearContact(Contact* con);
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define INIT_CAPACITY 10
#define GROWTH_FACTOR 2

typedef struct PeoInf {
    char name[20];
    char gender[7];
    int age;
    char phone[12];
    char address[50];
} PeoInf;

typedef struct Contact {
    PeoInf* data;
    int size;
    int capacity;
} Contact;

void InitContact(Contact* con);
void SaveToFile(const Contact* con, const char* filename);
void LoadFromFile(Contact* con, const char* filename);

void AddContact(Contact* con);
void ShowContact(const Contact* con);
void DelContact(Contact* con);
void SearchContact(const Contact* con);
void ModifyContact(Contact* con);
void SortContact(Contact* con);
void ClearContact(Contact* con);
void FreeContact(Contact* con);