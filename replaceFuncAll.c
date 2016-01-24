#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define SIZE 1000

void replaceFuncAll(char* str,regex_t reg,char* (*func)(char*),int cap){

  int match_elems = 100;
  regmatch_t match[100];

  
  int i,j,k,l;
  
  char* buff;
  int buffsize = 0;
  
  char* middle;
    
  char* p = str;
  
  buff = (char *)malloc(sizeof(char) * SIZE);
  if(buff == NULL) exit(1);
  
  while(regexec(&reg, p, match_elems, match, 0) != REG_NOMATCH){
    
    middle = (char *)malloc(sizeof(char) * SIZE);
    if(middle == NULL) exit(1);
    
     for(i = 0;match[cap].rm_so + i < match[cap].rm_eo;i++){
        if(i != 0 && (i%1000 == 0)) middle = (char *)realloc(middle,sizeof(char) * (i + SIZE));
	middle[i] = p[match[cap].rm_so + i];
      }
      if(i != 0 && (i%1000 == 0)) middle = (char *)realloc(middle,sizeof(char) * (i + SIZE));
      middle[i] = '\0';
      middle = func(middle);

    
    
    //left copy
    for(i = 0;i < match[0].rm_so;i++){
      if(buffsize != 0 && (buffsize%1000 == 0)) buff = (char *)realloc(buff,sizeof(char) * (buffsize + SIZE));
      buff[buffsize] = *(p + i);
      buffsize++;
    }

    //middle copy
    for(i = 0;middle[i] != '\0';i++){
      if(buffsize != 0 && (buffsize%1000 == 0)) buff = (char *)realloc(buff,sizeof(char) * (buffsize + SIZE));
      buff[buffsize] = middle[i];
      buffsize++;
    }    
    p += match[0].rm_eo;
    free(middle);
  }

  //right copy
  for(;*p != '\0';p++){
    if(buffsize != 0 && (buffsize%1000 == 0)) buff = (char *)realloc(buff,sizeof(char) * (buffsize + SIZE));
    buff[buffsize] = *p;
    buffsize++;
  }
  if(buffsize != 0 && (buffsize%1000 == 0)) buff = (char *)realloc(buff,sizeof(char) * (buffsize + 1));
  buff[buffsize] = '\0';
  
  if(strlen(str) < buffsize) str = (char *)realloc(str,sizeof(char) * (buffsize + 1));
  strcpy(str,buff);

  free(buff);
}