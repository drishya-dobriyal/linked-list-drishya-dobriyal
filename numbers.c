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

void print_status(int value){
  if( value == 1) printf("SuccessFully done\n");
  else printf("Failed\n");
}

int main(void) {
  char ch;
  int value, position;
  List_ptr list = create_list();
  display_menu();
  ch = getchar();

  while( ch != 'm'){
    switch (ch)
    {
    case 'a':
      printf("Enter number:\n");
      scanf("%d", &value);
      print_status(add_to_end(list, value));
      display_menu();
      break;
    
    case 'b' : 
      printf("Enter number:\n");
      scanf("%d", &value);
      print_status(add_to_start(list, value));
      display_menu();
      break;

    case 'c' : 
      printf("Enter number and position:\n");
      scanf("%d %d", &value, &position);
      print_status(insert_at(list, value, position - 1));
      display_menu();
      break;

    case 'd' :
      printf("Enter number:\n");
      scanf("%d", &value);
      print_status(add_unique(list, value));
      display_menu();
      break;
    
    case 'e' :
      print_status(remove_from_start(list));
      display_menu();
      break;
    
    case 'f' :
      print_status(remove_from_end(list));
      display_menu();
      break;

    case 'g' :
      printf("Enter position:\n");
      scanf("%d",&position);
      print_status(remove_at(list, position));
      display_menu();
      break;

    case 'h' :
      printf("Enter number:\n");
      scanf("%d", &value);
      print_status(remove_first_occurrence(list, value));
      display_menu();
      break;

    case 'i' :
      printf("Enter number:\n");
      scanf("%d", &value);
      print_status(remove_all_occurrences(list, value));
      display_menu();
      break;

    case 'j' :
      print_status(clear_list(list));
      display_menu();
      break;

    case 'k' :
      printf("Enter number:\n");
      scanf("%d", &value);
      printf("%s\n",is_value_present(list, value) == Success ? "Present" : "Not Present");
      display_menu();
      break;

    case 'l' : 
      display(list);
      // display_menu();
      break;
    }  

    while(getchar() != '\n');
    ch = getchar();
  }
  destroy_list(list);
  return 0;
}