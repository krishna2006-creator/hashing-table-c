#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef char* string;
char *getstring(){
int capacity=8;
int length=0;
char *buffer=malloc(8);
if(buffer==NULL){
	return NULL;
}
int c;
while((c=getchar())!='\n'){
	if(length+1>=capacity){
		capacity*=2;
		char *temp=realloc(buffer,capacity);
		if(temp==NULL){
		return NULL;
		}
		buffer=temp;
		temp=NULL;
	}
buffer[length]=c;
length++;
buffer[length]='\0';
}
return buffer;
}
typedef struct node{
	int id;
	string name;
	string number;
	string email;
     struct node *next;
}node;
node *table[25];
node *add(int id,string name,string number,string email);
void insert();
void display();
void display(){
	for(int i=0;i<26;i++){
		node *newnode=NULL;
		newnode=table[i];
		int j=1;
		if(table[i]!=NULL){
		printf("Alphabet order for %c\n",newnode->name[0]);
		while(newnode!=NULL){
		 
			printf("%d:%d\n",j,newnode->id);
			printf("%s\n",newnode->name);
			newnode=newnode->next;
			j++;
		}
		}
	}
}
int value(string name);
void hashtable(node *new,string name);
int main()
{
	for(int i=0;i<26;i++){
		table[i]=NULL;
	}
	int choice=0;
printf("************************************\n");
printf("students records using hashing table\n");
printf("************************************\n");
do{
	printf("1.insert data to database\n");
	printf("2.display\n");
	printf("3.exit\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			insert();
			break;
		case 2:
			display();
			break;
		case 3:
			printf("quit\n");
			break;
		default:
			printf("invalid number try again !\n");
	}
}while(choice!=3);

    return 0;
}
/*void stcpy(string source,string des){
	int i=0;
	while(source[i]!='\0'){
		des[i]=source[i];
		i++;
	}
}*/
node *add(int id,string name,string number,string email){
	node *newnode=malloc(sizeof(node));
	newnode->id=id;
	newnode->name=name;
	newnode->number=number;
	newnode->email=email;
	newnode->next=NULL;
/*
	stcpy(newnode->number,number);
	stcpy(newnode->email,email);
	newnode->next=NULL;*/
	return newnode;
}
int value(string name){
	return toupper(name[0])-'A';
}
void hashtable(node *new,string name){
	int index=0;
	index=value(name);
	if(table[index]==NULL){
		table[index]=new;
	}
	else{
	node *temp=NULL;
	temp=table[index];
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=new;
	new->next=NULL;
	}
}
void insert(){
	int id;
	string name;
	string number;
	string email;
	int no=0;
	printf("enter the numbers of students\n");
        scanf("%d",&no);
	for(int i=1;i<=no;i++){
	printf("enter the students data\n");
	printf("enter student id\n");
	scanf("%d",&id);
	getchar();
	printf("enter the sudent name\n");
	name=getstring();
	printf("enter the student number\n");
	number=getstring();
	printf("enter the student email\n");
	email=getstring();
	node *new=add(id,name,number,email);
           hashtable(new,name);
}
}
