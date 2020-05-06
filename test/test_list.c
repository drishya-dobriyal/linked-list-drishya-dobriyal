#include <assert.h>
#include <stdio.h>
#include "../list.h"

void test_add_to_end( void ){
  printf("Testing add_to_end \n");
  List_ptr list = create_list();
  printf("Should add number to end when list is empty\n");
  assert(add_to_end(list , 1));
  assert(list->count == 1);
  assert(list->head->value == 1);
  assert(list->last->value == 1);

  printf("Should add the number when list is not empty\n");
  add_to_end(list, 2);
  add_to_end(list, 3);
  assert(add_to_end(list, 4));
  assert(list->count == 4);
  assert(list->last->value == 4);

  printf("Test for add_to_end completed\n\n");
}

void test_add_to_start( void ){
  printf("Testing add_to_start \n");
  List_ptr list = create_list();
  
  printf("Should add number to start when list is empty\n");
  assert(add_to_start(list , 1));
  assert(list->count == 1);
  assert(list->head->value == 1);
  assert(list->last->value == 1);

  printf("Should add the number when list is not empty\n");
  add_to_start(list, 2);
  add_to_start(list, 3);
  assert(add_to_start(list, 4));
  assert(list->head->value == 4);
  assert(list->count == 4);

  printf("Test for add_to_end completed\n\n");
}

void test_insert_at( void ){
  printf("Testing insert_at \n");
  List_ptr list = create_list();
  
  printf("Should insert at zero position of list when list  is empty\n");
  assert(insert_at(list, 1 , 0));
  assert(list->count == 1);
  assert(list->head->value == 1);
  assert(list->last->value == 1);

  printf("Should insert at middle of the list \n");
  add_to_end(list, 2);
  add_to_end(list, 3);
  assert(insert_at(list, 4, 1)); 
  assert(list->count == 4);
  assert(list->head->next->value == 4);

  printf("Should insert at last of the list \n");
  assert(insert_at(list, 5 , 4));
  assert(list->count == 5);
  assert(list->last->value == 5);
   
  printf("Should not insert at invalid position\n");
  assert(!insert_at(list, 5 , 10));
  assert(list->count == 5);

  printf("Test for insert_at completed\n\n");
}

void test_add_unique( void ){
  printf("Testing add_unique \n");
  List_ptr list = create_list();
  add_unique(list, 1);
  add_unique(list, 2);
  add_unique(list, 3);

  printf("Should add num at last if num is not present\n");
  assert(add_unique(list, 4));
  assert(list->count == 4);
  assert(list->last->value == 4);

  printf("Should not add num at last if num is not present\n");
  assert(!add_unique(list, 1));
  assert(list->count == 4);
  assert(list->last->value == 4);
  printf("Test for add_unique completed\n\n");
}

void test_is_value_present( void ){
  printf("Testing is_value_present \n");
  List_ptr list = create_list();
  add_unique(list, 1);
  add_unique(list, 2);
  add_unique(list, 3);

  printf("Should give true if value is present\n");
  assert(is_value_present( list ,1));

  printf("Should give false if value is not present\n");
  assert(!is_value_present(list, 5 ));

  printf("Test for is_value_present completed\n\n");
}

void test_remove_at(void) {
  printf("Testing remove_at\n");
  List_ptr list = create_list();
  printf("should fail if the list is empty\n");
  assert(!remove_at(list,1));
  assert(list->head == NULL);
  assert(list->last == NULL);
  assert(list->count == 0);

  printf("should remove the num in middle of list\n");
  add_to_end(list,1);
  add_to_end(list,2);
  add_to_end(list,3);
  add_to_end(list,4);
  add_to_end(list,5);
  assert(remove_at(list,1));
  assert(list->count == 4);
  assert(list->head->next->value == 3);

  printf("should remove the num in starting of list of list\n");
  assert(remove_at(list,0));
  assert(list->count == 3);
  assert(list->head->value == 3);
 
  printf("should remove the num at last of list of list\n");
  assert(remove_at(list,2));
  assert(list->count == 2);
  assert(list->last->value == 4);
 
  printf("should fail if invalid position is given\n");
  assert(!remove_at(list,5));
  assert(list->count == 2);

  printf("Test for remove_at completed\n\n");
};

void test_remove_from_end(void) {
  printf("Testing remove_from_end\n");
  List_ptr list = create_list();

  printf("should fail if the list is empty\n");
  assert(!remove_from_end(list));
  assert(list->count == 0);

  printf("should remove num from last in the list\n");
  add_to_end(list,1);
  add_to_end(list,2);
  assert(remove_from_end(list));
  assert(list->count == 1);
  assert(list->head->value == 1);
  assert(list->last->value == 1);

  printf("Test for remove_from_end completed\n\n");
};

void assert_remove_from_start(void) {
  printf("Testing remove_from_start\n");
  List_ptr list = create_list();
  
  printf("should fail if the list is empty\n");
  assert(!remove_from_start(list));
  assert(list->count == 0);

  printf("should remove first num from the list\n");
  add_to_end(list,5);
  assert(remove_from_start(list));
  assert(list->count == 0);
  assert(list->head == NULL);

  printf("should remove first num from the list when more than one is present\n");
  add_to_end(list,1);
  add_to_end(list,2);
  assert(remove_from_start(list));
  assert(list->count == 1);
  assert(list->last->value == 2);
  assert(list->head->value == 2);

  printf("Test for remove_from_start completed\n\n");
};

void test_remove_all_occurrence(void){
  printf("Testing remove_all_occurrence\n");
  List_ptr list = create_list();
 
  printf("should fail if the list is empty\n");
  assert(!remove_all_occurrences(list,2));
  assert(list->head == NULL);

  printf("should fail if num is not present in the list\n");
  add_to_end(list,1);
  add_to_end(list,2);
  assert(!remove_all_occurrences(list,4));
  assert(list->count == 2);

  printf("should remove all occurrences of a num from the list\n");
  add_to_end(list,1);
  assert(remove_all_occurrences(list,1));
  assert(list->count == 1);
  assert(list->head->value == 2);
  assert(list->last->value == 2);
  printf("Test for remove_all_occurrences completed\n\n");
}

void test_remove_first_occurrence(void) {
  printf("Testing remove_first_occurrence\n");
  List_ptr list = create_list();

  printf("should fail if the list is empty\n");
  assert(!remove_first_occurrence(list,1));
  assert(list->count == 0);

  printf("should fail if num is not present in the list\n");
  add_to_end(list,1);
  add_to_end(list,2);
  assert(!remove_first_occurrence(list,3));
  assert(list->count == 2);

  printf("should remove the first occurrence of the num from the list\n");
  assert(remove_first_occurrence(list,2));
  assert(list->count == 1);
  assert(list->head->value == 1);
  assert(list->last->value == 1);
  printf("Test for remove_first_occurrences completed\n\n");
};

int main(void){
  test_add_to_end();
  test_add_to_start();
  test_insert_at();
  test_add_unique();
  test_is_value_present();
  test_remove_at();
  assert_remove_from_start();
  test_remove_from_end();
  test_remove_first_occurrence();
  test_remove_all_occurrence();
  return  0;
}