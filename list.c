#include <stdlib.h>
#include "list.h"

Status add_to_end( List_ptr list, int value) {
  int count = list->count;
  insertValue(list, value);
  if( count + 1 == list->count) return Success;
  return Failure;
}

Node_ptr create_node( int value){
  Node_ptr new_node = malloc(sizeof(Node));
  new_node->next = NULL;
  new_node->value = value;
  return new_node;
}

void insertValue(List_ptr list, int value){
  Node_ptr new_node = create_node(value);
  if( list->head == NULL){
    list->head = new_node;
  } else {
    list->last->next = new_node;
  }
  list->count++;
  list->last = new_node;
}

List_ptr create_list(){
  List_ptr list = malloc(sizeof(List));
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return list;
}