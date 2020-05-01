#include <stdio.h>
#include "list.h"

void display_menu() {
  printf("Main Menu\n");
  printf("(a) add a number to the end of the list\n");
  printf("(b) add a number to the start of the list\n");
  printf("(c) insert a number at a given position in the list\n");
  printf("(d) add a unique item on the list at the end(if it already exists, do not insert)\n");
  printf("(e) remove a number from the beginning of the list\n");
  printf("(f) remove a number from the end of the list\n");  
  printf("(g) remove a number from a given position in the list\n"); 
  printf("(h) remove first occurrence of a number\n"); 
  printf("(i) remove all occurrences of a number\n"); 
  printf("(j) clear the whole list\n"); 
  printf("(k) check if a number exists in the list\n"); 
  printf("(l) display the list of numbers\n"); 
  printf("(m) exit\n\n"); 
  printf("Please enter the alphabet of the operation you would like to perform\n"); 
}

int main(void) {
  char ch;
  int value;
  List_ptr list = create_list();
  display_menu();
  ch = getchar();

  while( ch != 'm'){
    if( ch == 'a' ) {
      printf("Enter number:\n");
      scanf("%d", &value);
      printf("%d\n",add_to_end(list, value));
    }
    if( ch == 'b' ) {
      printf("Enter number:\n");
      scanf("%d", &value);
      printf("%d\n",add_to_start(list, value));
    }
    while(getchar() != '\n');
    ch = getchar();
  }
  return 0;
}