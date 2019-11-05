struct node {
  char name[100];
  char artist[100];
  struct node * next;
};

void print_node(struct node * node);
void print_list(struct node * node);
struct node * insert_front(struct node * node, char * newName, char * newArtist);
struct node * free_list(struct node * head);
struct node * remove_node(struct node * front, char * newName, char * newArtist);
struct node * insert_alpha(struct node * node, char * newName, char * newArtist);
int songcmp(struct node * node1, struct node * node2);
struct node * random_node(struct node * list);
struct node * find_node(struct node * list, char * name, char * artist);
struct node * find_artist(struct node * list, char * artist);