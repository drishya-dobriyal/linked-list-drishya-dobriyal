#include <stdlib.h>
#include "list.h"

Status add_to_end( List_ptr list, int value) {
  int count = list->count;
  insert_at(list, value, count);
  if( count + 1 == list->count) return Success;
  return Failure;
}

Status add_to_start( List_ptr list, int value) {
  int count = list->count;
  insert_at(list, value, 0);
  if( count + 1 == list->count) return Success;
  return Failure;
}

Node_ptr create_node( int value){
  Node_ptr new_node = malloc(sizeof(Node));
  new_node->next = NULL;
  new_node->value = value;
  return new_node;
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

Status insert_at(List_ptr list, int value, int position){
  Node_ptr new_node = create_node(value);
  
  if(list->head == NULL ) return insert_initital_node(list,new_node);
  if( position == 0 ) return insert_at_start( list, new_node);

  Node_ptr p_walk = list->head;
  int currPosition = 1;
  while ( currPosition != position)
  {
    p_walk = p_walk->next;
    currPosition++;
  }
  
  p_walk->next =  new_node;
  if( position == list->count) list->last = new_node;
  else
  {
    Node_ptr pre_pos = p_walk->next;
    new_node->next = pre_pos;  
  }
  list->count++;
  return Success;
}

List_ptr create_list(){
  List_ptr list = malloc(sizeof(List));
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return list;
}