#include "linked_list.h"

void main() {
   insert_data(1,10);
   insert_data(2,20);
   insert_data(23,232);

   printf("Original List: ");

   //print list
   print_list();

   while(!is_empty()) {
      struct node *temp = delete_data();
      printf("\nDeleted value:");
      printf("(%d,%d) ",temp->key,temp->data);
      printf("\nCurrent list: ");
      print_list();
   }

   printf("\nList after deleting all items: ");
   print_list();

   insert_data(1,10);
   insert_data(2,20);
   insert_data(3,30);
   insert_data(4,1);
   insert_data(5,40);
   insert_data(6,56);

   printf("\nRestored List: ");
   print_list();
   printf("\n");
   printf("The length of the list is: %d\n",length());

   struct node *foundLink = find(4);

   if(foundLink != NULL) {
      printf("Element found: ");
      printf("(%d,%d) ",foundLink->key,foundLink->data);
      printf("\n");
   } else {
      printf("Element not found.");
   }

   delete(4);
   printf("List after deleting an item: ");
   print_list();
   printf("\n");
   foundLink = find(4);

   if(foundLink != NULL) {
      printf("Element found: ");
      printf("(%d,%d) ",foundLink->key,foundLink->data);
      printf("\n");
   } else {
      printf("Element not found.");
   }

   printf("\n");
   sort();

   printf("List after sorting the data: ");
   print_list();

   reverse(&head);
   printf("\nList after reversing the data: ");
   print_list();
}
