#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linkedList.h"
#include "musicLibrary.h"

int main(void) {
	srand(time(NULL));
	printf("LINKED LIST TESTS\n========================================\n");
	
	printf("\nTesting print_list:\n");
	struct node *songList = NULL;
	songList = insert_alpha(songList,"hey","bob");
	songList = insert_alpha(songList,"ah","bob");
	songList = insert_alpha(songList,"asdf","jack");
	songList = insert_alpha(songList,"cdas", "jack");
	songList = insert_alpha(songList,"yo", "fred");
	songList = insert_alpha(songList,"hello", "fred");
	print_list(songList);
	
	printf("\n\nTesting print_node:\n");
	print_node(songList);
	printf("\n========================================\n");
	
	printf("\nTesting find_node:\nlooking for jack: asdf\n");
	print_node(find_node(songList,"asdf", "jack"));
	
	printf("\n\nTesting find_artist:\n");
	print_node(find_artist(songList, "fred"));
	
	printf("\n\nTesting random:\n");
	print_node(random_node(songList));
	printf("\n");
	print_node(random_node(songList));
	printf("\n");
	print_node(random_node(songList));
	
	printf("\n\nTesting remove:\n");
	printf("Removing fred: yo|\n");
	print_list(remove_node(songList,"yo","fred"));
	
	printf("\n\nTesting free_list:\n");
	print_list(free_list(songList));
	printf("After printing the empty list\n");
	
	
	printf("========================================\n");
	printf("\nMUSIC LIBRARY TESTS\n");
	printf("\n========================================\n");
	
	
	add_song("hey","bob");
	add_song("ah","bob");
	add_song("asdf","jack");
	add_song("cdas", "jack");
	add_song("yo", "fred");
	add_song("hello", "fred");
	
	printf("\nTesting print_library:\n");
	print_library();
	printf("\n========================================\n");
	
	printf("\nTesting print_letter:\n");
	print_letter("f");
	printf("\n========================================\n");
	
	printf("\nTesting find:");
	printf("\nLooking for bob: hey\n");
	find("hey","bob");
	printf("\n========================================\n");
	
	printf("\nTesting find artist:");
	printf("\nLooking for bob\n");
	find_by_artist("bob");
	printf("\n========================================\n");
	
	printf("\nTesting remove song:");
	printf("\nRemoving jack: asdf\n");
	remove_song("asdf","jack");
	print_library();
	printf("\n========================================\n");
	
	printf("\nTesting print_artist:");
	printf("\nPrinting fred\n");
	print_artist("fred");
	printf("========================================\n");
	
	printf("\nTesting shuffle:");
	shuffle();
	printf("\n========================================\n");
	
	printf("\nTesting clear library:");
	clear_library();
	printf("\nEmpty Library after clear\n");
	print_library();
	printf("========================================\n");
}
