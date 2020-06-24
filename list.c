#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "header.h"
extern int inmod;
extern int words;
//  synarthseis pou sxetizontai me thn lista
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
	words++;
	printf("sth lista bhke:");
	puts(new->word);
	elements(new,len);
	new->next=NULL;
	new->previous=NULL;
	head=new;
	last=new;
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
	words++;
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
	words++;
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
	words++;
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
	while (tmp!=NULL)
	{
		puts(tmp->word);
		printf("%d %d %d %d\n",tmp->wordlength,tmp->uniqletters,tmp->insertionmode,tmp->numoftimes);
		tmp=tmp->next;
		
	}

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
