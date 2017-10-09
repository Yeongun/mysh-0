#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "commands.h"

int do_cd(int argc, char** argv) {
  if (!validate_cd_argv(argc, argv))
    return -1;
  if(strcmp(argv[1],"..")==0){
	chdir('../');
   }else{
	chdir(argv[1]);	}
  return 0;
}

int do_pwd(int argc, char** argv) {
  if (!validate_pwd_argv(argc, argv))
    return -1;
 char dirname[200];
 getcwd(dirname,200);
 printf("%s\n",dirname);
 

  return 0;
}

int validate_cd_argv(int argc, char** argv) {
  if(argc==2){
	if(chdir(argv[1])==-1 || argv[1]==".")
	return 0;
	return 1;}
  else{
 	return 0;}
    
  
 
  
}

int validate_pwd_argv(int argc, char** argv) {
 if(argc==1&&strcmp(argv[0],"pwd")==0){
  return 1;}
 else{
	return 0;
	}
}
