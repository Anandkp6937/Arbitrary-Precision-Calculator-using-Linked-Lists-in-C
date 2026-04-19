#ifndef MAIN_H
#define MAIN_H
#define NOT_VALID 0
#define SUCCESS 1
#define FAILURE -1
#include <stdio.h>
#include <string.h>
typedef struct DlinkedList{
     int data;
     struct DlinkedList*prev;
     struct DlinkedList*next;
}Dlist;

// Function prototype
void print_list(Dlist *head);

int checkNumber(char*argv);

int build_Ll(Dlist**,Dlist**,int);

int createTheFullList(Dlist**,Dlist**,char*argv);

int addLinkedList(Dlist**,Dlist**,Dlist**,Dlist**,Dlist**,Dlist**);

int subLinkedL(Dlist**,Dlist**,Dlist**,Dlist**,Dlist**,Dlist**);

void copy_List(Dlist *src_head, Dlist *src_tail, Dlist **dest_head, Dlist **dest_tail);

int mulLinkedL(Dlist**,Dlist**,Dlist**,Dlist**,Dlist**,Dlist**);

int divLinkedL(Dlist**,Dlist**,Dlist**,Dlist**,Dlist**,Dlist**);

int reverse_Result_Dll(Dlist**,Dlist**);

int compareLinkedList(Dlist *head1, Dlist *head2);

void free_Dlist(Dlist*head);
#endif // MAIN_H