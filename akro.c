#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "header.h"
int inmod=0,words=0;
int main(void){
	wordList *tmp,*tmp1;
	char str[800];
	char *str4=NULL;
	char *str2;
	char str1[]=" ";
	char *str3;
	int i,j,a=0,z,len,w,k=0,flagcr=0,l=0;
	char *ch;
	head=NULL;
	last=NULL;
	for(i=0;i<26;i++)
	{
		alphabet[i]=('A'+i);
	}
	srand(time(NULL));
	menu();
	while(getchar()!='\n');
	while(1)
	{
		gets(str);
		for(i=0;str[i]!='\0';i++) //kefalaia ola ta grammata tou str 
		{
			str[i]=toupper(str[i]);
		}
		if(!strncmp(str,"INSERT: ",8)) //insert
		{
				inmod=1; //tropos eisagwghs
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
			printf("prostethikan sthn lista %d lexeis\n",words);
			words=0;
			
		}
		else if(!strncmp(str,"DELETE: ",8)) //delete
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
				
		}
		else if(!strncmp(str,"SHOWFWD: ",9)) //emfanisi tis listas apo brosta gia ta prwta w stoixeia
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
		else if(!strncmp(str,"SHOWREV: ",9)) //emfanisi tis listas apo pisw gia ta prwrta w sroixeia apo to telos
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
		else if(!strncmp(str,"FIND: ",6)) // anazhthsh twnw stoixeiwn pou xekinaei apo ena sygkekreimenh lexi
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
		else if(!strncmp(str,"CREATE: ",8)) //dhmiourgei thn akrostoixida 
		{
			if(flagcr==0)
			{
				flagcr=1;
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
							flagcr=0;
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
					len_arr=strlen(str4);
					if(str4!=NULL && k>0)
					{
						arr=(char**)malloc(len_arr*sizeof(char*));
						arr2=(char**)malloc(len_arr*sizeof(char*));
						for(i=0;i<len_arr;i++)
						{
							ch=&str4[i];
							create(ch,i,k);
						}
						print_akrostoixida(len_arr);
					}
				}
			}
			else
			{
				printf("exeis hdh akrostoixida\n");
			}
		}
		else if(!strncmp(str,"LOAD: ",6)) //eisagei tis lexeis apo kapoio arxeio typou .txt
		{
			inmod=0;
			str2= strtok(str,str1);
			if(str2!=NULL)
			{	
				str2=strtok(NULL,str1);
				if(str2==NULL)
			 	{			
					printf("den yparxei allh lexi\n");
					break;
		
				}
				str3=(char*)malloc((strlen(str2)+5)*sizeof(char));
				if(str3==NULL)
				{
					printf("no space\n");
					exit(0);
				}
				str3=strcat(str2,".txt");
				
				
			}
			build_list(str3);
			printf("prostethikan sthn lista %d lexeis\n",words);
			words=0;
			
		}
		else if(!strncmp(str,"SAVE: ",6)) // apothikevei thn akrostoixida se ena arxeio typou .txt
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
				str3=(char*)malloc((strlen(str2)+5)*sizeof(char));
				if(str3==NULL)
				{
					printf("no space\n");
					exit(0);
				}
				str3=strcat(str2,".txt");
				save_acrostic(str3);
				free_acrostic();
			}
		}
			
		else if(!strncmp(str,"EXIT",4))	// termatizei to programma
		{
			printf(" THE END \n");
			exit(0);
		}
		else if(!strncmp(str,"CHECK",5)) // epiprostheth epilogh pou mas dinei stoixeia gia tis lexeis pou eisagontai sti lista
		{
			if(!isempty())
			{
				check();
			}
			else
			{
				printf("no list\n");
			}
			
		}
		else
		{
			printf("WRONG COMMAND\n");
		}
	}
			
	
	return 0;
}

