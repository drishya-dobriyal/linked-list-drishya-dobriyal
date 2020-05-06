#include <stdio.h>
#include <stdlib.h>
#include "list.h"


Node_ptr create_node( int value){
  Node_ptr new_node = malloc(sizeof(Node));
  new_node->next = NULL;
  new_node->value = value;
  return new_node;
}

List_ptr create_list(){
  List_ptr list = malloc(sizeof(List));
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return list;
}

Status is_value_present(List_ptr list,int value) {
  Node_ptr p_walk = list->head;
  while (p_walk != NULL)
  {
    if(p_walk->value == value) return Success;
    p_walk = p_walk->next;
  }
  return Failure;
}

void display(List_ptr list){
  printf("The list is \n");
  Node *p_walk = list->head;
  int count = 0;
  while (p_walk != NULL)
  {
    printf("%d\n",p_walk->value);
    p_walk = p_walk->next;
  }
}

Status clear_list(List_ptr list) {
  Node_ptr p_walk = list->head;
  Node_ptr eliminate_ptr = NULL;
  while (p_walk != NULL)
  {
    eliminate_ptr = p_walk;
    p_walk = p_walk->next;
    free(eliminate_ptr);
  }
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return Success;
}

void destroy_list(List_ptr list){
  Node_ptr p_walk = list->head;
  Node_ptr eliminate_ptr = NULL;
  while (p_walk != NULL)
  {
    eliminate_ptr = p_walk;
    p_walk = p_walk->next;
    free(eliminate_ptr);
  }
  free(list);
}

Status add_to_end( List_ptr list, int value) {
  int count = list->count;
  return insert_at(list, value, count);
}

Status add_to_start( List_ptr list, int value) {
  return insert_at(list, value, 0);
}

Status add_unique(List_ptr list, int value){
  if(is_value_present(list, value)) return Failure;
  return insert_at(list,value,list->count);
}

Status insert_at_start(List_ptr list,Node_ptr new_node){
  Node_ptr pre_pos = list->head;
  list->head = new_node;
  new_node->next = pre_pos;
  list->count++;
  return Success;
}

Status insert_initital_node(List_ptr list,Node_ptr new_node){
  list->head = new_node;
  list->last = new_node;
  list->count++;
  return Success;
}

Node_ptr get_node( List_ptr list, int position){
  Node_ptr p_walk = list->head;
  int currPosition = 1;
  while ( currPosition != position)
  {
    p_walk = p_walk->next;
    currPosition++;
  }
  return p_walk;
}

Status insert_at(List_ptr list, int value, int position){
  if( position > list->count || position < 0) return Failure;
  
  Node_ptr new_node = create_node(value);
  if(list->head == NULL ) return insert_initital_node(list,new_node);
  if( position == 0) return insert_at_start( list, new_node);
  
  Node_ptr p_walk = get_node(list, position);
  Node_ptr pre_pos = p_walk->next;
  p_walk->next =  new_node;
  if( position == list->count) list->last = new_node;
  else new_node->next = pre_pos;   
  list->count++;
  return Success;
}

Status remove_from_start(List_ptr list) {
  if(list->head == NULL) return Failure;
  Node_ptr new_head = list->head->next;
  free(list->head);
  list->head = new_head;
  list->count--;
  return Success;
}

Status remove_from_end(List_ptr list){
  return remove_at(list, list->count - 1);
};
 
Status remove_at(List_ptr list, int position){
  if(list->head == NULL|| position > list->count || position < 0 ) return Failure;
  if( position == 0) return remove_from_start( list );
   
  Node_ptr pre_node = get_node(list, position);
  Node_ptr elimate_node = pre_node->next;
  if( position == list->count - 1) {
    list->last = pre_node;
    list->last->next = NULL;
  }
  else {
    pre_node->next = elimate_node->next;
  };   
  list->count--;
  free(elimate_node);
  return Success;
}

Status remove_first_occurrence(List_ptr list, int value){
  Node_ptr p_walk = list->head;
  int pos = 0;
  while (p_walk != NULL)
  {
    if(p_walk->value == value) return remove_at(list, pos);
    p_walk = p_walk->next;
    pos++;
  }
  return Failure;
}

Status remove_all_occurrences(List_ptr list, int value){
  Status status = is_value_present( list ,value);
  if( ! status ) return Failure;
  while( status ) {
    status = remove_first_occurrence(list, value);
  }
  return Success;
}