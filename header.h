typedef struct wList
{
	char *word;
	int wordlength;
	int uniqletters;
	int numoftimes;
	int insertionmode;
	int use;
	int flag;
	struct wList *next;
	struct wList *previous;
}wordList;
wordList *head;
wordList *last;
char **arr,**arr2;
int len_arr;
char alphabet[26];
void insert_empty( char *str2,int len);
void insert(char *str2,int len);
void check (void);
int isempty(void);
void insert_akri1(char *str2,int len);
void insert_akri2(char *str2,int len);
void showfwd(int ep);
void showrev(int ep);
void find(int num ,char *str);
void delete(char *str2);
void elements(wordList *new,int len);
void level(wordList *tmp,int len,int uniq,int num);
void create(char *ch,int i,int k);
void print_akrostoixida(int len);
void build_list(char *fileName);
void save_acrostic(char *str3);
void free_acrostic(void);
void menu(void);
