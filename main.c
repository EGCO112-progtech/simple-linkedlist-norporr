//
//  main.c
//  simple linkedlist
//
//  Created by Mingmanas Sivaraksa on 4/2/2566 BE.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(int argc, const char * argv[]) {
    int c=5;
    struct node a,b,x,y,*head ;
    a.value = c;
    a.next=&b;
    head=&a;
    b.value=head->value+3;

    //ex1
    b.next=&x; 
    /*x.value=11;
    a.next->next->value = 11;
    head->next->next->value =11;
    */
    b.next->value=11;
    x.next=NULL; //important

    //ex2
    y.next=&a; // pai add at the begining(a is the first variable)
    head=&y;
    head->value=2;


    printf("%d\n", (*head).value ); //what value for 2
    printf("%d\n", head ->next->value ); //what value for 5 or ((*(*head).next).value)
    printf("%d\n", head ->next ->next ->value ); //8
    printf("%d\n", head ->next ->next ->next ->value ); //11
/*  Exercise I
    1. Add 1 more than at the end
    2. Add value(11)
    3. Make next become NULL
 */
    
/*  Exercise II
        1. Add 1 more than at the begining!!!!
        2. Add value (2)
        
*/
    typedef struct node* NodePtr;
    NodePtr tmp=head; //add temp value to faciliate
        
    //  Exercise III Use loop to print everything
        printf("\n\n");
        int i,n=4;
        for(i=0;i<n;i++){ // this type of for loop we need to know exactly how many the number are 
            printf("%4d", tmp->value);
            tmp = tmp->next;
          // What is missing???

        }
    
    
   // Exercise IV change to while loop!! (you can use NULL to help)
        tmp=head;
        printf("\n\n");
         while(tmp!=NULL){ //if tmp->next!=NULL, next is a null pointer and its already null so last one (11) will not print out
            printf("%4d", tmp->value);
            tmp = tmp->next;
           
           // What is missing???
        }
    
    
 //  Exercise V Use malloc to create all nodes, instead of create a struct!!

        typedef struct node* nodeptr;
        nodeptr temp;
        head = (nodeptr)malloc(sizeof(struct node));
        temp = head;
        //int i;
        //temp->next = (nodeptr)malloc(sizeof(struct node)); //or we can use head->next
        for (i=0;i<3;i++)
        {
            temp->value=i+3;
            temp->next=(nodeptr)malloc(sizeof(struct node));
            temp = temp->next;
        }
          //use a loop to help
         temp->value=i+3;
         temp->next=NULL;
     
     printf("\n\n");
         for (temp=head;temp!=NULL;temp=temp->next)
         {
            printf("%4d", temp->value);
         }

    //  Exercise VI Free all node !!
         //use a loop to help
         printf("\n\n");
         for (temp=head;temp!=NULL;temp=head)
         {
            head=head->next;
            printf("Freeing %d\n", temp->value);
            free(temp);
         }
          
     
    
    return 0;
}
