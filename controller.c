#include "main.h"
#include<stdlib.h>

//print linked list
void print_list(Dlist *head)
{
	
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	    printf("👉 Head -> ");
	    while (head)		
	    {
		   
		    printf("%d <-", head -> data);

		   
		    head = head -> next;
		    if (head)
		        printf("> ");
	    }
    	printf(" Tail\n");
    }
}



//build the linked list
int build_Ll(Dlist**head,Dlist**tail,int data){
Dlist*new=(Dlist*)malloc(sizeof(Dlist));
Dlist*ptr=*head;

new->data=data;
new->prev=NULL;
new->next=NULL;
//check if it is a first node to create
if(*head==NULL){
*head=new;
*tail=new;
return SUCCESS;
}

else{
while(ptr->next!=NULL){
     ptr=ptr->next;
}
ptr->next=new;
new->prev=ptr;
*tail=new;
return SUCCESS;
}
return FAILURE;
}

int createTheFullList(Dlist**head,Dlist**tail,char*argv){
     for(int i=0;i<strlen(argv);i++){
          int data=argv[i]-'0';
          if(build_Ll(head,tail,data)==FAILURE){
            return FAILURE;
          }
     }
     return SUCCESS;          
}

int checkNumber(char*argv){
for(int i=0;i<strlen(argv);i++){
     if(!(argv[i]>=48 && argv[i]<=57)){
     return FAILURE;
     }
}
return SUCCESS;
}

//Reverse result Dll
int reverse_Result_Dll(Dlist**head,Dlist**tail){
Dlist*temp=*head;
Dlist*copy=NULL;

while(temp!=NULL){
if(temp->prev==NULL){
		*tail=temp;
}

copy=temp->prev;
temp->prev=temp->next;
temp->next=copy;
*head=temp;
temp=(temp->prev);
}

return SUCCESS;
}

//add linked list
int addLinkedList(Dlist**head1,Dlist**head2,Dlist**tail1,Dlist**tail2,Dlist**r_head,Dlist**r_tail){
	int carry=0;

	while(*tail1!=NULL && *tail2!=NULL){
	int temp=((*tail1)->data)+((*tail2)->data);
	if(carry>0){
		temp=temp+carry;
	}
	if(temp>9){
	build_Ll(r_head,r_tail,(temp%10));
	carry=temp/10;
}

else{
	build_Ll(r_head,r_tail,temp);
}

*tail1=(*tail1)->prev;
*tail2=(*tail2)->prev;

}

while(*tail1!=NULL){
	int temp = (*tail1)->data + carry;
	build_Ll(r_head,r_tail,(*tail1)->data);
	*tail1=(*tail1)->prev;
}

while(*tail2!=NULL){
	int temp =(*tail2)->data + carry;
	build_Ll(r_head,r_tail,(*tail2)->data);
	*tail2=(*tail2)->prev;
}

if (carry > 0)

	build_Ll(r_head, r_tail, carry);
	reverse_Result_Dll(r_head,r_tail);
	
	return SUCCESS;

}

//substract linked list
int subLinkedL(Dlist**head1, Dlist**head2, Dlist**tail1, Dlist**tail2, Dlist**r_head, Dlist**r_tail) {
    int carry = 0, f1 = 0, f2 = 0, flag = 0;
    
   
    Dlist* current_tail1 = *tail1;
    Dlist* current_tail2 = *tail2;
    
  
    Dlist* temp_count1 = *tail1;
    Dlist* temp_count2 = *tail2;
    while(temp_count1 != NULL) { f1++; temp_count1 = temp_count1->prev; }
    while(temp_count2 != NULL) { f2++; temp_count2 = temp_count2->prev; }
    
   
    if (f2 > f1 || (f1 == f2 && (*head2)->data > (*head1)->data)) {
        Dlist* tempo = *head1;
        Dlist* tempt = *tail1;
        *head1 = *head2;
        *head2 = tempo;
        *tail1 = *tail2;
        *tail2 = tempt;
        flag = 1;
        
      
        current_tail2 = *tail2;
    }

  
    while (current_tail1 != NULL && current_tail2 != NULL) {
        int d1 = current_tail1->data;
        int d2 = current_tail2->data;

        if (carry) {
            d1 -= carry;
            carry = 0;
        }

        int temp = d1 - d2;
     
        if (temp < 0) {
            temp += 10;
            carry = 1;
        }

        build_Ll(r_head, r_tail, temp);

       
        current_tail1 = current_tail1->prev;
        current_tail2 = current_tail2->prev;
    }

    
    while (current_tail1 != NULL) {
        int d1 = current_tail1->data;
        if (carry) {
            d1 -= carry;
            carry = 0;
            if (d1 < 0) {
                d1 += 10;
                carry = 1; 
            }
        }
        build_Ll(r_head, r_tail, d1);
        current_tail1 = current_tail1->prev;
    }

   

    reverse_Result_Dll(r_head, r_tail);

    if (flag) {
        printf("Answer is - (Negative)\n");
    }

    return SUCCESS;
}

void free_Dlist(Dlist*head){
	while(head!=NULL){
		Dlist*temp=head;
		head=head->next;
		free(temp);
	}
}

void copy_List(Dlist *src_head, Dlist *src_tail, Dlist **dest_head, Dlist **dest_tail) {
    *dest_head = NULL;
    *dest_tail = NULL;

    Dlist *temp = src_head;
    while (temp != NULL) {
        build_Ll(dest_head, dest_tail, temp->data);
        temp = temp->next;
    }
}



//multiplication linked list
int mulLinkedL(Dlist **head1, Dlist **head2, Dlist **tail1, Dlist **tail2,
               Dlist **r_head, Dlist **r_tail)
{
    int carry = 0;
    int i = 0; // For shifting zeros (place values)
    Dlist *ctail2 = *tail2;

    // Outer loop: for each digit in second number
    while (ctail2 != NULL) {
        Dlist *a_head = NULL;
        Dlist *a_tail = NULL;
        Dlist *ctail1 = *tail1;
        carry = 0;

        
        for (int k = 0; k < i; k++)
            build_Ll(&a_head, &a_tail, 0);

        
        while (ctail1 != NULL) {
            int temp = (ctail1->data * ctail2->data) + carry;
            carry = temp / 10;
            temp = temp % 10;
            build_Ll(&a_head, &a_tail, temp);
            ctail1 = ctail1->prev;
        }

        // Add leftover carry if any
        if (carry > 0)
            build_Ll(&a_head, &a_tail, carry);

        // Reverse partial result (since we built from LSD)
        reverse_Result_Dll(&a_head, &a_tail);

        // Add partial result to final result
        if (*r_head == NULL)
            copy_List(a_head, a_tail, r_head, r_tail); // first partial product
        else {
            Dlist *sum_head = NULL, *sum_tail = NULL;

           
            addLinkedList(r_head, &a_head, r_tail, &a_tail, &sum_head, &sum_tail);
			free_Dlist(*r_head);
            // Update result list to new sum
            *r_head = sum_head;
            *r_tail = sum_tail;
        }

        // Move to next digit of num2
        ctail2 = ctail2->prev;
        i++;
    }

//     reverse_Result_Dll(r_head, r_tail);
    return SUCCESS;
}

int compareLinkedList(Dlist *head1, Dlist *head2) {
    if (head1 == NULL || head2 == NULL)
        return FAILURE; 

   
    Dlist *h1 = head1;
    Dlist *h2 = head2;
    
   
    while (h1 && h1->data == 0 && h1->next) {
        h1 = h1->next;
    }
   
    while (h2 && h2->data == 0 && h2->next) {
        h2 = h2->next;
    }
    
 
    int len1 = 0, len2 = 0;
    Dlist *temp1 = h1, *temp2 = h2; 

    while (temp1) {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2) {
        len2++;
        temp2 = temp2->next;
    }

    
    if (len1 > len2)
        return SUCCESS;
    else if (len1 < len2)
        return FAILURE;

   
    while (h1 && h2) {
        if (h1->data > h2->data)
            return SUCCESS;
        else if (h1->data < h2->data)
            return FAILURE;

        h1 = h1->next;
        h2 = h2->next;
    }

   
    return 0;
}
int divLinkedL(Dlist **head1, Dlist **head2,
               Dlist **tail1, Dlist **tail2,
               Dlist **r_head, Dlist **r_tail) {
    int counter = 0;


    if (*head2 == NULL) {
        printf("ERROR: Division by zero!\n");
        return FAILURE;
    }


   while (compareLinkedList(*head1, *head2) == SUCCESS ||
       compareLinkedList(*head1, *head2) == 0) {

      
        subLinkedL(head1, head2, tail1, tail2, r_head, r_tail);

       
        free_Dlist(*head1);

    
        *head1 = *r_head;
        *tail1 = *r_tail;

       
        *r_head = NULL;
        *r_tail = NULL;

        counter++;
    }
    

    printf("Quotient: %d\n", counter);

    return SUCCESS;
}
