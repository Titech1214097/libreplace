#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define SIZE 1000

void replaceFunc(char* str,regex_t reg,char* (*func)(char*),int cap){

    int match_elems = 100;
    regmatch_t match[100];
    
    char* right;
    int rightsize;
    
    char* middle;
    
    int i,j,k,l;
  
    
    if(regexec(&reg, str, match_elems, match, 0) != REG_NOMATCH){
      
      middle = (char *)malloc(sizeof(char)*SIZE);
      if(middle == NULL) exit(1);
      
      for(i = 0;match[cap].rm_so + i < match[cap].rm_eo;i++){
        if(i != 0 && (i%1000 == 0)) middle = (char *)realloc(middle,sizeof(char) * (i + SIZE));
	middle[i] = str[match[cap].rm_so + i];
      }
      if(i != 0 && (i%1000 == 0)) middle = (char *)realloc(middle,sizeof(char) * (i + SIZE));
      middle[i] = '\0';
      middle = func(middle);


      //right buffer
      for(i =0; str[i + match[cap].rm_eo] != '\0';i++);
      rightsize = i + 1;
      right = (char *)malloc( sizeof(char) * rightsize);
      if(right == NULL) exit(1);
      for(i = 0,j = match[cap].rm_eo;str[j] != '\0';i++ ,j++) right[i] = str[j];
      right[i] = '\0';

      if(strlen(str) < match[cap].rm_so + strlen(middle) + rightsize)
      str = (char *)realloc(str, sizeof(char)*(match[cap].rm_so + strlen(middle) + rightsize));


      for(i = match[cap].rm_so,j = 0;middle[j] != '\0';i++, j++) str[i] = middle[j];
      for(j = 0;right[j] != '\0'; i++,j++) str[i] = right[j];
      str[i] = '\0';

      free(right);
      free(middle);

    }
}