#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

void print_list(struct node * node) {
  while(node != NULL){
    print_node(node);
    printf(" | ");
    node = node -> next;
  }
}

void print_node(struct node * node){
  printf(" %s: %s ", node -> artist, node -> name);
}

struct node * insert_front(struct node * node, char * songName, char * artistName) {
  struct node * newHead = malloc(sizeof(struct node));
  strcpy(newHead -> name,songName);
  strcpy(newHead -> artist,artistName);
  newHead -> next = node;
  return newHead;
}

struct node * free_list(struct node * node) {
  while (node != NULL){
    struct node *freeNode = node;
    free(freeNode);
    freeNode = NULL;
    node = node -> next;
  }
  return node;
}

struct node * remove_node(struct node * node, char * songName, char * artistName) {
  struct node * newNode = node;
  struct node * next = node -> next;
  if(strcmp(newNode -> name, songName) == 0 && strcmp(newNode -> artist, artistName) == 0){
    free(newNode);
    return next;
  }
  while (next != NULL){
    if (strcmp(next -> name, songName) == 0 && strcmp(next -> artist, artistName) == 0) {
      newNode -> next = next -> next;
      free(next);
      return node;
    }
    newNode = next;
    next = next -> next;
  }
  printf("%s - %s not found\n", songName, artistName);
  return node;
}

struct node * insert_alpha(struct node * node, char * songName, char * artistName) {
  struct node * newNode = malloc(sizeof(struct node));
  strcpy(newNode -> name, songName);
  strcpy(newNode -> artist, artistName);
  struct node * newList = node;
  struct node * prev = NULL;
  if(newList == NULL) {
    newNode -> next = NULL;
    return newNode;
  }
  while(newList != NULL) {
    if(songcmp(newNode,newList) <= 0) {
      if(prev == NULL) {
        newNode -> next = newList;
        return newNode;
      }
      prev -> next = newNode;
      newNode -> next = newList;
      return node;
      }
      else {
        if(newList -> next == NULL) {
          newList -> next = newNode;
          newNode -> next = NULL;
          return node;
        }
        prev = newList;
        newList = newList -> next;
      }
    }
  return node;
}

struct node * random_node(struct node * node) {
  int len = 0;
  struct node * newNode = node;
  while (newNode != NULL){
    len++;
    newNode = newNode -> next;
  }
  int random = rand() % len;
  newNode = node;
  while (random > 0){
    newNode = newNode -> next;
    random--;
  }
  return newNode;
}

int songcmp(struct node * node1, struct node * node2) {
  if(strcmp(node1 -> artist,node2 -> artist) == 0) {
    return strcmp(node1 -> name, node2 -> name);
  }
  return strcmp(node1 -> artist,node2 -> artist);
}

struct node * find_node(struct node * list, char * name, char * artist) {
  struct node *newList = list;
  while(newList != NULL) {
    if((strcmp(newList -> artist,artist) == 0) && (strcmp(newList -> name,name) == 0)) {
      return newList;
    }
    newList = newList -> next;
  }
  return NULL;
}

struct node * find_artist(struct node * list, char * artist) {
  struct node * newList = list;
  while(newList != NULL) {
    if((strcmp(newList -> artist,artist) == 0)) {
      return newList;
    }
    newList = newList -> next;
  }
  return NULL;
}