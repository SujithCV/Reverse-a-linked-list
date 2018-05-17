#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
struct node {
   int data;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;
void printList() {
   struct node *ptr = head;
   while(ptr != NULL) {
      printf("%d ",ptr->data);
      ptr = ptr->next;
   }

   printf(" ");
}
void insert(int data) {

   struct node *link = (struct node*) malloc(sizeof(struct node));

   link->data = data;
   link->next = head;
   head = link;
}
void reverseUtil(struct node *curr,struct node *prev,struct node **head);

void reverse(struct node **head)
{
    if (!head)
        return;
    reverseUtil(*head, NULL, head);
}

void reverseUtil(struct node *curr,struct node *prev, struct node **head)
{
    // If last node mark it head
    if (!curr->next)
    {
        *head = curr;

        //Update next to prev node */
        curr->next = prev;
        return;
    }

    // Save curr->next node for recursive call
    struct node *next = curr->next;

    //update next
    curr->next = prev;

    reverseUtil(next, curr, head);
}
int main()
{
insert(20);
insert(30);
insert(40);
insert(50);
printList();
printf("\n");   
reverse(&head);
printList();


}
