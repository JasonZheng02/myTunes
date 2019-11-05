#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "linkedList.h"
#include "musicLibrary.h"

void clear_library() {
  int i;
  for(i = 0; i < sizeof(table)/sizeof(table[0]);i++) {
    table[i] =  NULL;
  }
}

void add_song(char * name, char * artist) {
  int i = artist[0] - 'a';
  if(i < 0) {
    i = 26;
  }
  table[i] = insert_alpha(table[i], name, artist);
}

void print_library() {
  int i;
  for(i = 0; i < sizeof(table)/sizeof(table[0]) - 1;i++) {
    print_list(table[i]);
  }
}

void print_letter(char * artist) {
  int i = artist[0] - 'a';
  //If the first letter of the index starts with a number:
  if(i < 0) {
    i = 26;
  }
  printf("%c list\n", artist[0]);
  print_list(table[i]);
}

struct node * find(char * name, char * artist) {
  int i = artist[0] - 'a';
  if(i < 0) {
    i = 26;
  }
  printf("looking for [%s: %s]:\n", name, artist);
  if(find_node(table[i], name, artist) != NULL) {
    printf("song found! %s: %s", name, artist);
  }
  else {
    printf("song not found\n");
  }
  return find_node(table[i], name, artist);
}

struct node * find_by_artist(char * artist) {
  int i = artist[0] - 'a';
  if(i < 0) {
    i = 26;
  }
  if(find_artist(table[i], artist) != NULL) {
    struct node * temp = find_artist(table[i], artist);
    struct node * newList = temp;
    while(newList != NULL) {
      if(strcmp(temp -> artist,newList -> artist) != 0) {
        temp = remove_node(temp, newList -> name, newList -> artist);
      }
      newList = newList -> next;
    }
    printf("\tartist found!");
    print_list(temp);
  }
  else {
    printf("artist not found");
  }
  return find_artist(table[i], artist);
}

void print_artist(char * artist) {
  int i = artist[0] - 'a';
  if(i < 0) {
    i = 26;
  }
  struct node * temp = find_artist(table[i], artist);
  struct node * newList = temp;
  while(newList != NULL) {
    if(strcmp(temp -> artist,newList -> artist) != 0) {
      temp = remove_node(temp, newList -> name, newList -> artist);
    }
    newList = newList -> next;
  }
  struct node * newNode = temp;
  while (newNode != NULL){
    printf("[%s: %s]\n", newNode -> artist, newNode -> name);
    newNode = newNode -> next;
  }
}

void remove_song(char * name, char * artist){
  int i = artist[0] - 'a';
  if(i < 0) {
    i = 26;
  }
  struct node * removeNode = table[i];
  table[i] = remove_node(removeNode,name,artist);
}

void shuffle(){
  int random = rand() % 30;
  int i = 3;
  while (i > 0){
    if (table[random] != NULL){
      print_node(random_node(table[random]));
      i--;
    }
    random = rand() % 30;
  }
}