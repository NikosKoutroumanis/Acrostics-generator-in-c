#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
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
int inmod=0;
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
void build_list(char* fileName);
void save_acrostic(char *str3);
int main(void){
	wordList *tmp,*tmp1;
	char str[100];
	char *str4=NULL;
	char *str2;
	char str1[]=" ";
	char *str3;
	int i,j,a=0,z,len,w,k=0;
	char *ch;
	head=NULL;
	last=NULL;
	for(i=0;i<26;i++)
	{
		alphabet[i]=('A'+i);
	}
	srand(time(NULL));
	while(1)
	{
		gets(str);
		for(i=0;str[i]!='\0';i++)
		{
			str[i]=toupper(str[i]);
		}
		if(!strncmp(str,"INSERT: ",8))
		{
				inmod=1;
				for(i=0;str[i]!='\0';i++)
				{
					if(isdigit(str[i]))
					{
						if(isspace(str[i-1]) && isspace(str[i+1]))
						{
							str[i]=' ';
						}
					}
					if(ispunct(str[i]))
					{
						if(isspace(str[i-1]) || isspace(str[i+1]))
						{
							str[i]=' ';
						}
					}
					if(isalpha(str[i]))
					{
						if(isspace(str[i-1]) && isspace(str[i+1]))
						{
							str[i]=' ';
						}
					}
				}		
				str2= strtok(str,str1);
				while(str2!=NULL)
				{
					a=0;
					tmp1=head;
					tmp=head;
					str2=strtok(NULL,str1);
					if(str2==NULL)
				 	{
					
						printf("den yparxei allh lexi\n");
						break;
		
					}
					len=strlen(str2);
					for(i=0;i<len;i++)
					{
						if(isalpha(str2[i]))
						{
							a++;
						}
					}
					if(a==len)
					{
						printf("bhke h lexi:");					
						if(isempty())
						{
	
							insert_empty(str2,len+1);
							
						}
						else
						{
							if(strcmp(head->word,str2)>0)
							{
								insert_akri1(str2,len+1);
							}
							else if(strcmp(last->word,str2)<0)
							{
								insert_akri2(str2,len+1);
							}
							else
							{
								insert(str2,len+1);
							}
							
						}
						printf("\n");
					}
					else
					{
						printf("h lexi den prostethike ");
						puts(str2);
						printf("\n");
					}
				}
			
		}
		else if(!strncmp(str,"DELETE: ",8))
		{
			for(i=0;str[i]!='\0';i++)
			{
				if(isdigit(str[i]))
				{
					if(isspace(str[i-1]) && isspace(str[i+1]))
					{
						str[i]=' ';
					}
				}
				if(ispunct(str[i]))
				{
					if(isspace(str[i-1]) || isspace(str[i+1]))
					{
						str[i]=' ';
					}
				}
				if(isalpha(str[i]))
				{
					if(isspace(str[i-1]) && isspace(str[i+1]))
					{
						str[i]=' ';
					}
				}
			}		
			str2= strtok(str,str1);
			while(str2!=NULL)
			{
				str2=strtok(NULL,str1);
				if(str2==NULL)
			 	{
				
					printf("den yparxei allh lexi\n");
					break;
	
				}
				delete(str2);
			}
			check();
				
		}
		else if(!strncmp(str,"SHOWFWD: ",9))
		{
			str2= strtok(str,str1);
			for(i=0;str[i]!='\0';i++)
			{
				if(ispunct(str[i]))
				{
					str[i]=' ';
				}
				if(isalpha(str[i]))
				{
					str[i]=' ';
				}
			}
			
			while(str2!=NULL)
			{
				str2=strtok(NULL,str1);
				
				if(str2==NULL)
				{	
					printf("den yparxei arithmos\n");
					break;
				}
				w=atoi(str2);
				showfwd(w);
				w=0;
			}
		}
		else if(!strncmp(str,"SHOWREV: ",9))
		{
			str2= strtok(str,str1);
			for(i=0;str[i]!='\0';i++)
			{
				if(ispunct(str[i]))
				{
					str[i]=' ';
				}
				if(isalpha(str[i]))
				{
					str[i]=' ';
				}
			}
			
			while(str2!=NULL)
			{
				str2=strtok(NULL,str1);
				
				if(str2==NULL)
				{	
					printf("den yparxei arithmos\n");
					break;
				}
				w=atoi(str2);
				showrev(w);
				w=0;
			}
		}
		else if(!strncmp(str,"FIND: ",6))
		{
			str2= strtok(str,str1);
			for(i=0;str[i]!='\0';i++)
			{
				if(ispunct(str[i]))
				{
					str[i]=' ';
				}
			}
			str2=strtok(NULL,str1);
			while(str2!=NULL)
			{
				str4=strtok(NULL,str1);
				w=atoi(str4);
				find(w,str2);
				w=0;
				break;
			}
			printf("The first %s words starting with <%s> have been found and printed\n",str4,str2);
		}
		else if(!strncmp(str,"CREATE: ",8))
		{
			for(i=0;str[i]!='\0';i++)
			{
				if(isdigit(str[i]))
				{
					if(isspace(str[i-1]) && isspace(str[i+1]))
					{
						str[i]=' ';
					}
				}
				if(ispunct(str[i]))
				{
					if(isspace(str[i-1]) || isspace(str[i+1]))
					{
						str[i]=' ';
					}
				}
				if(isalpha(str[i]))
				{
					if(isspace(str[i-1]) && isspace(str[i+1]))
					{
						str[i]=' ';
					}
				}
			}		
			str2= strtok(str,str1);
			while(str2!=NULL)
			{
				str2=strtok(NULL,str1);
				if(str2==NULL)
			 	{
					if(k==0)
					{
						printf("no level\n");
					}
					else
					{
						printf("den yparxei allh lexi\n");
					}
					break;

				}

				if(!strcmp(str2,"EASY"))
				{
					k=1;
				}
				else if(!strcmp(str2,"HARD"))
				{
					k=2;
				}
				else
				{
					str4=str2;
				}
				len=strlen(str4);
				len_arr=len;
				if(str4!=NULL && k>0)
				{
					arr=(char**)malloc(len*sizeof(char*));
					arr2=(char**)malloc(len*sizeof(char*));
					for(i=0;str4[i]!='\0';i++)
					{
						ch=&str4[i];
						create(ch,i,k);
					}
					print_akrostoixida(len);
				}
			}
		}
		else if(!strncmp(str,"LOAD: ",6))
		{
			inmod=0;
			str2= strtok(str,str1);
			while(str2!=NULL)
			{	
				str2=strtok(NULL,str1);
				if(str2==NULL)
			 	{			
					printf("den yparxei allh lexi\n");
					break;
		
				}
				str3=strcat(str2,".txt");
				build_list(str3);
			}
		}
		else if(!strncmp(str,"SAVE: ",6))
		{
			str2= strtok(str,str1);
			while(str2!=NULL)
			{	
				str2=strtok(NULL,str1);
				if(str2==NULL)
			 	{			
					printf("den yparxei allh lexi\n");
					break;
		
				}
				str3=strcat(str2,".txt");
				save_acrostic(str3);
			}
		}	
	}
			
	
	return 0;
}
void insert_empty( char *str2,int len)
{
	wordList *new;
	new=(wordList*)malloc(sizeof(wordList));
	if(new==NULL)
	{
		printf("no space \n");
		exit(0);
	}
	new->word=(char*)malloc(len*sizeof(char));
	if(new->word==NULL)
	{
		printf("no space \n");
		exit(0);
	}
	strcpy(new->word,str2);
	printf("sth lista bhke:");
	puts(new->word);
	elements(new,len);
	new->next=NULL;
	new->previous=NULL;
	head=new;
	last=new;
	printf("%d %d %d %d\n",new->wordlength,new->uniqletters,new->insertionmode,new->numoftimes);
}
void insert(char *str2,int len)
{
	wordList *new,*tmp1,*tmp2;
	tmp1=tmp2=head;
	while(tmp1!=NULL)
	{
		if(strcmp(tmp1->word,str2)>0)
		{
			break;
		}
		else if(strcmp(tmp1->word,str2)==0)
		{
			tmp1->numoftimes++;
			return;
		}
		tmp1=tmp1->next;
		
	}
	new=(wordList*)malloc(sizeof(wordList));
	if(new==NULL)
	{
		printf("no space \n");
		exit(0);
	}
	new->word=(char*)malloc(len*sizeof(char));
	if(new->word==NULL)
	{
		printf("no space \n");
		exit(0);
	}
	strcpy(new->word,str2);
	printf("sth lista bhke:");
	puts(new->word);
	elements(new,len);
	tmp2=tmp1->previous;
	tmp1->previous=new;
	new->previous=tmp2;
	tmp2->next=new;
	new->next=tmp1;
}
void insert_akri1(char *str2,int len)
{
	wordList *new;
	new=(wordList*)malloc(sizeof(wordList));
	if(new==NULL)
	{
		printf("no space \n");
		exit(0);
	}
	new->word=(char*)malloc(len*sizeof(char));
	if(new->word==NULL)
	{
		printf("no space \n");
		exit(0);
	}
	strcpy(new->word,str2);
	printf("sth lista bhke:");
	puts(new->word);
	elements(new,len);
	new->next=head;
	new->previous=NULL;
	head->previous=new;
	head=new;
}
void insert_akri2(char *str2,int len)
{
	wordList *new;
	new=(wordList*)malloc(sizeof(wordList));
	if(new==NULL)
	{
		printf("no space \n");
		exit(0);
	}
	new->word=(char*)malloc(len*sizeof(char));
	if(new->word==NULL)
	{
		printf("no space \n");
		exit(0);
	}
	strcpy(new->word,str2);
	printf("sth lista bhke:");
	puts(new->word);
	elements(new,len);
	last->next=new;
	new->previous=last;
	new->next=NULL;
	last=new;
}
int isempty(void)
{
	if(head==NULL && last==NULL)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}
void check (void)
{
	wordList *tmp=head;
	while (tmp!=last)
	{
		puts(tmp->word);
		printf("%d %d %d %d\n",tmp->wordlength,tmp->uniqletters,tmp->insertionmode,tmp->numoftimes);
		tmp=tmp->next;
		
	}
	puts(tmp->word);

}
void showfwd(int ep)
{
	wordList *tmp;
	tmp=head;
	while(tmp!=NULL && ep>0 )
	{
		puts(tmp->word);
		tmp=tmp->next;
		ep=ep-1;
	}
}
void showrev(int ep)
{
	wordList *tmp;
	tmp=last;
	while(tmp!=NULL && ep>0)
	{
		puts(tmp->word);
		tmp=tmp->previous;
		ep=ep-1;
	}
}
void find(int num ,char *str)
{
	wordList *tmp;
	char k;
	tmp=head;
	k=strlen(str);
	while(num>0 && tmp!=NULL)
	{
		if(!strncmp(tmp->word,str,k))
		{
			puts(tmp->word);
			num=num-1;
		}
		tmp=tmp->next;
	}
}
void delete(char *str2)
{
	wordList *tmp=head, *tmp2=head,*tmp3=head;
	int count=0;
	while(tmp!=NULL)
	{
		if(!strcmp(tmp->word,str2))
		{
			count++;
			if(tmp==head)
			{
				head=tmp->next;
				head->previous=NULL;
			}
			else if(tmp==last)
			{
				last=tmp->previous;
				last->next=NULL;
			}
			else
			{
				tmp2=tmp->previous;	
				tmp3=tmp->next;
				tmp2->next=tmp3;
				tmp3->previous=tmp2;
			}
			free(tmp->word);
			free(tmp);
			break;
		}
		else
		{
			tmp=tmp->next;
		}
	}
	if(count!=0)
	{
		printf(" diagrafike h lexi <%s> \n",str2);
	}
	else 
	{
		printf("h lexi <%s> den vrethike\n",str2);
	}
}
void elements(wordList *new,int len)
{
	int i,j,l=0;
	new->wordlength=len-1;
	new->uniqletters=len-1;
	for(i=0;i<26;i++)
	{
		for(j=0;j<len-1;j++)
		{
			if(new->word[j]==alphabet[i])
			{
				l++;
			}
		}
		if(l>1)
		{
			new->uniqletters=new->uniqletters-l+1;
		}
		l=0;
	}
	new->insertionmode=inmod;
	new->numoftimes=1;
	level(new,len-1,new->uniqletters,new->numoftimes);
	new->flag=0;
}
void create(char *ch,int i,int k)
{
	srand(time(NULL));
	int lev=0,n,l;
	wordList *tmp=head;
	while(tmp!=NULL)
	{
		if(!strncmp(tmp->word,ch,1))
		{
			if(tmp->use==k && tmp->flag==0)
			{
				arr[i]=(char*)malloc((tmp->wordlength+1)*sizeof(char));
				arr2[i]=(char*)malloc((tmp->wordlength+1)*sizeof(char));
				strcpy(arr[i],tmp->word);
				strcpy(arr2[i],tmp->word);
				tmp->flag=1;
				if(k==1)
				{
					lev=35*tmp->wordlength/100;
				}
				else if(k==2)
				{
					lev=70*tmp->wordlength/100;
				}
				if(tmp->wordlength<=3)
				{
					lev=1;
				}
				while(lev>0)
				{
					n=1+rand()%(tmp->wordlength-1);
					arr2[i][n]='_';
					lev--;
				}
				for(l=0;l<tmp->wordlength;l++)
				{

					if(arr2[i][l]==arr2[i][n] && arr2[i][l]!='_')

					{

						arr2[i][l]='_';

					}

				}
				break;
			}
		}
		tmp=tmp->next;
	}
		if(tmp==NULL)
		{
			printf("den yparxoun arketes lexeis\n");
		}		
}

void print_akrostoixida(int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		printf("%s                       | %s\n",arr[i],arr2[i]);
	}
}
void level(wordList *tmp,int len,int uniq,int num)
{
	int i=0;
	i=(len*2)-(uniq/num);
	if(i<len)
	{
		tmp->use=2;
	}
	else
	{
		tmp->use=1;
	}
}
void build_list(char* fileName)
{
	FILE* file = fopen(fileName, "r");
	char c;
	int word_size = 1,i,a=0,len;
	char *word1;
	int word_count = 0;
	word1=(char*)malloc(word_size*sizeof(char));
	while ((c = fgetc(file)) != EOF)
	{
		a=0;

		while (c != ' ' && c != EOF)
		{
			if (word_count == word_size)
			{
				word_size += 1;
				word1 = realloc(word1, word_size);

			}

			word1[word_count++] = c;

			c = fgetc(file);

		}
		if (c == EOF)
		{
			break;
		}
		word1 = realloc(word1, word_size + 1);
		word1[word_size] = '\0';
		for(i=0;word1[i]!='\0';i++)
		{
			word1[i]=toupper(word1[i]);
		}
		len=strlen(word1);
		if(len<2)
		{
			word_count = 0;
			word_size = 1;
			word1 = (char*)malloc(word_size*sizeof(char));
			continue;
		}

		for(i=0;i<len;i++)
		{
			if(isalpha(word1[i]))
			{
				a++;
			}
		}
		if(a==len)
		{
			printf("bhke h lexi:");					
			if(isempty())
			{

				insert_empty(word1,len+1);
			}
			else
			{
				if(strcmp(head->word,word1)>0)
				{
					insert_akri1(word1,len+1);
				}
				else if(strcmp(last->word,word1)<0)
				{
					insert_akri2(word1,len+1);
				}
				else
				{
					insert(word1,len+1);
				}
			}
			printf("\n");
			check();
		}
		else
		{
			printf("h lexi den prostethike ");
			puts(word1);
			printf("\n");
		}
		word_count = 0;
		word_size = 1;
		word1 = malloc(word_size);

	}
	free(word1);
	fclose(file);
}
void save_acrostic(char *str3)
{
	int i;
	FILE *fileptr;
	fileptr=fopen(str3,"a+");
while(!feof(fileptr))
{
	for(i=0;i<len_arr;i++)
	{
		fputs (arr[i],fileptr);
		fputs ("\n",fileptr);
		
	}
	fputs ("\n",fileptr);
	for(i=0;i<len_arr;i++)
	{
		fputs (arr2[i],fileptr);
		fputs ("\n",fileptr);
	}
}
	fclose(fileptr);
}
