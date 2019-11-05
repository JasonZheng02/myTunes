#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main(void) {
  printf("LINKED LIST TESTS\n========================================\n");

  printf("\nTesting print_list:\n");
  struct song_node *songList = NULL;
  songList = insert_alpha(songList,"Hey","Bob");
  songList = insert_alpha(songList,"Ah","Bob");
  songList = insert_alpha(songList,"ASDF","Jack");
  songList = insert_alpha(songList,"CDAS", "Jack");
  songList = insert_alpha(songList,"Yo", "Fred");
  songList = insert_alpha(songList,"Hello", "Fred");
  print_list(songList);
  
  printf("\n\nTesting print_node:\n");
  print_node(songList);
  printf("\n========================================\n");
  
  printf("\nTesting find_node:\nlooking for Jack: ASDF\n");
  print_node(find_node(songList,"ASDF", "Jack"));
  
  printf("\n\nTesting find_artist:\n");
  print_node(find_artist(songList, "Fred"));
  
  printf("\n\nTesting random:\n");
  print_node(random_node(songList));
  printf("\n");
  print_node(random_node(songList));
  printf("\n");
  print_node(random_node(songList));
  
  printf("\n\nTesting remove:\n");
  printf("Removing Fred: Yo|\n");
  print_list(remove_node(songList,"Yo","Fred"));
  
  printf("\n\nTesting free_list:\n");
  print_list(free_list(songList));
  printf("After printing the empty list\n");
  
  printf("========================================\n");
  printf("\nMUSIC LIBRARY TESTS\n");
  printf("\n========================================\n");
}
