int * lettercount(ssize_t read, size_t len, FILE * inputstream, char *line, int *letterz);
void wordcount(ssize_t read, size_t len, FILE * inputstream, char *line, int *letterz);
int checknum();
//int hash(char *word);
//void insert(char *word);
//void display();

struct node * createNode(char *name);
void insertToHash(char *name);
//void deleteFromHash(int key);
void searchInHash(char *name);
void display();
int hashnum(char *name);
struct node {
    char name[100];
    struct node *next;
    int count;
};

struct hash {
    struct node *head;
    int count;
};
