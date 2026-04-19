#include<stdio.h>
#include<string.h>
#include "main.h"
int main(int argc,char*argv[]){
     Dlist*head1=NULL;
     Dlist*head2=NULL;
     Dlist*tail1=NULL;
     Dlist*tail2=NULL;
     Dlist*r_head=NULL;
     Dlist*r_tail=NULL;
     Dlist *q_head=NULL;
      Dlist *q_tail=NULL;
     int sign=0;
//check arguments numbers
if(argc!=4){
    printf("ERR: 👀 ARGUMENT ERROR \n");
    printf("` Example Usage : ./a.out 123 + 1 `\n");
     return FAILURE;
}
//check the number is perfect without any other character 
if(!(checkNumber(argv[1])==SUCCESS && checkNumber(argv[3])==SUCCESS)){
          fprintf(stderr,"ERR: 👀 NOT A NUMBER  \n");
               return FAILURE;
     }
//operator validation
     char*op;
       if(strcmp(argv[2],"+")==0 ||strcmp(argv[2],"-")==0 || strcmp(argv[2],"*")==0 || strcmp(argv[2],"/")==0){
       op=argv[2];
       printf("INFO: SUCESSFULLY VERIFIED OPERATOR: %s\n",op);
     }
       else{
               printf("ERR:INVALID  OPERATOR  \n");

          return NOT_VALID;
       }





//creating Dlinkedl for operand1
if(createTheFullList(&head1,&tail1,argv[1])==SUCCESS){
     printf("INFO: SUCESSFULLY CREATED OPERAND 1 DLL \n");
     print_list(head1);
}
else{
     printf("👀:ERROR CREATING DLL OF FIRST OPERAND \n");
     return FAILURE;
}
//creating dll for operand 2

if(createTheFullList(&head2,&tail2,argv[3])==SUCCESS){
      printf("INFO: SUCESSFULLY CREATED OPERAND 2 DLL \n");
     print_list(head2);
}
else{
     return FAILURE;
}
int res;


switch(op[0]){
     case'+' :
     if(addLinkedList(&head1,&head2,&tail1,&tail2,&r_head,&r_tail)==SUCCESS){
          printf("INFO:SUCESSFULLY DONE ADDITION \n");
          print_list(r_head);
     }
     else{
          printf("INFO:ERROR OCCURED IN SUMMING \n");
     }
     break;

           case'-' :
     if(subLinkedL(&head1,&head2,&tail1,&tail2,&r_head,&r_tail)==SUCCESS){
          printf("INFO:SUCESSFULLY DONE SUBSTRACTION \n");

          print_list(r_head);
     }
     else{
          printf("INFO:ERROR OCCURED IN SUBSTRACTION \n");
     }
     break;

         case'*' :
     if(mulLinkedL(&head1,&head2,&tail1,&tail2,&r_head,&r_tail)==SUCCESS){
          printf("INFO:SUCESSFULLY DONE MULTIPLICATION \n");
          print_list(r_head);
     }
     else{
          printf("INFO:ERROR OCCURED IN MULTIPLICATION  \n");
     }
     break;

      case '/' :
     if(divLinkedL(&head1,&head2,&tail1,&tail2,&r_head,&r_tail)==SUCCESS){
          printf("INFO:SUCESSFULLY DONE DIVISION \n");
     }
     else{
          printf("INFO:ERROR OCCURED IN DIVISION  \n");
     }
     break;

     default:
     printf("errr \n");

}

     return 0;
}