#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
void mysh_parse_command(const char* command,int *argc, char*** argv)
{
  // TODO: Fill this!
 int count=0;
 int escape=1; 
 char temp[8096];
 char* token;
 *argv=(char**)malloc(sizeof(char*)*8096);
 strcpy(temp,command);
 token=strtok(temp," \n\t"); 
 (*argv)[count]=(char*)malloc(sizeof(char)*8096);
 if(token==NULL){
 escape=0;
 strcpy((*argv)[0],"");
 count=1;}
 else{
 strcpy((*argv)[count],token);}
 while(escape){
  	count++;
 	token=strtok(NULL," \n\t");	
   		if( token == NULL){
		escape=0;}
		else{
	        (*argv)[count]=(char*)malloc(sizeof(char)*8096);
		 strcpy((*argv)[count],token);}
					     	   	
		}
	*argc=count;
 }
