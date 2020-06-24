#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "header.h"
// synarthseis pou sxetizontai me thn apothikefsi kai fortosi arxeiwn
void create(char *ch,int i,int k)
{
	srand(time(NULL));
	int lev=0,n,l;
	wordList *tmp=head;
	while(tmp!=NULL)
	{
		if(!strncmp(tmp->word,ch,1))
		{
			if(tmp->use==k && tmp->flag==0 && tmp->wordlength>2)
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
				if(tmp->wordlength==3)
				{
					lev=1;
				}
				while(lev>0 && tmp->wordlength>2)
				{
					n=1+rand()%(tmp->wordlength-2);
					if(arr2[i][n]=='_')
					{
						continue;
					}
					for(l=0;l<tmp->wordlength;l++)
					{
						if(arr[i][l]==arr[i][n])
						{
							arr2[i][l]='_';
						}	
					}
					arr2[i][n]='_';
					lev--;
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
		printf("%20s|%s\n",arr[i],arr2[i]);
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
void build_list(char *fileName)
{
	char c;
	int word_size = 1,i,a=0,len;
	char *word1;
	int word_count = 0;
	FILE *file=fopen(fileName,"r");
	if(file==NULL)
	{
		
		printf(" to arxeio den anoikse\n");
		exit(0);
	}
	word1=(char*)malloc(word_size*sizeof(char));
	if(word1==NULL)
	{
		printf("no space\n");
		exit(0);
	}
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
		if (c==EOF)
		{
			free(word1);
			fclose(file);
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
			free(word1);
			word1 = (char*)malloc(word_size*sizeof(char));
			if(word1==NULL)
			{
				printf("no space\n");
				exit(0);
			}
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
		}
		else
		{
			printf("h lexi den prostethike ");
			puts(word1);
			printf("\n");
		}
		word_count = 0;
		word_size = 1;
		free(word1);
		word1 = (char*)malloc(word_size*sizeof(char));
		if(word1==NULL)
		{
			printf("no space\n");
			exit(0);
		}

	}
		
}	
void save_acrostic(char *str3)
{
	int i=0;
	FILE *fileptr;
	fileptr=fopen(str3,"a");
	if(fileptr==NULL)
	{
		printf("to arxeio den anoikse\n");
		exit(0);
	}
	for(i=0;i<len_arr;i++)
	{
		fprintf(fileptr,"%s",arr[i]);
		fprintf(fileptr,"\n");
	}
	for(i=0;i<len_arr;i++)
	{
		fprintf(fileptr,"%s",arr2[i]);
		if(i==len_arr-1)
		{
			return;
		}
		fprintf(fileptr,"%s",arr2[i]);
		fprintf(fileptr,"\n");
		
	}
	fclose(fileptr);
}
void free_acrostic(void)
{
	int i;
	for(i=0;i<len_arr;i++)
	{
		free(arr[i]);
		free(arr2[i]);
	}
	free(arr);
	free(arr2);
}

