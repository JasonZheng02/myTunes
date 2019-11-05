struct node * table[30];

void clear_library();
void add_song(char * name, char * artist);
void print_library();
void print_letter(char *a);
struct node * find(char * name, char * artist);
struct node * find_by_artist(char * artist);
void print_artist(char * artist);
void remove_song(char * name, char * artist);
void shuffle();