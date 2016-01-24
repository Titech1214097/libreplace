#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define SIZE 1000


void replaceAll(char* str,regex_t reg,char*replacement){
  int match_elems = 100;
  regmatch_t match[100];
  int GroupToCap[11];
  
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
    
    //Check meta word in replacement
    for(i = 0,j = 0;replacement[i] != '\0';i++){
      if(replacement[i] == '\\'){
	if('0' <= replacement[i + 1] && replacement[i + 1] <= '9'){
	  k = (int)replacement[i + 1] - (int)'0';
	  for(l = match[k].rm_so; l < match[k].rm_eo;j++,l++){
	    if(j!=0 && (j%1000 == 0)) middle = (char *)realloc(middle,sizeof(char) * (j + SIZE));
	    middle[j] = p[l];
	  }
	  i++;
	}else if(replacement[i + 1] == '+'){
	  for(k = 0;(match[k].rm_so != -1) && (k <= 10);k++);
	  for(l = match[k-1].rm_so; l < match[k-1].rm_eo;j++,l++){
	    if(j!=0 && (j%1000 == 0)) middle = (char *)realloc(middle,sizeof(char) * (j + SIZE));
	    middle[j] = p[l];
	  }
	  i++;
	} else if(replacement[i + 1] == '`'){
	  for(l = 0; l < match[0].rm_so;j++,l++){
	    if(j!=0 && (j%1000 == 0)) middle = (char *)realloc(middle,sizeof(char) * (j + SIZE));
	    middle[j] = p[l];
	  }
	  i++;
	}else if(replacement[i + 1] == '\''){
	  for(l = match[0].rm_eo; p[l] != '\0';j++,l++){
	    if(j!=0 && (j%1000 == 0)) middle = (char *)realloc(middle,sizeof(char) * (j + SIZE));
	    middle[j] = p[l];
	  }
	  i++;
	}
      }else{
	middle[j] = replacement[i];
	j++;
	if(j!=0 && (j%1000 == 0)) middle = (char *)realloc(middle,sizeof(char) * (j + SIZE));
      }
    }
    middle[j] = '\0';
    
    
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
  for(i = 0;*(p + i) != '\0';i++){
    if(buffsize != 0 && (buffsize%1000 == 0)) buff = (char *)realloc(buff,sizeof(char) * (buffsize + SIZE));
    buff[buffsize] = *(p + i);
    buffsize++;
  }
  if(buffsize != 0 && (buffsize%1000 == 0)) buff = (char *)realloc(buff,sizeof(char) * (buffsize + 1));
  buff[buffsize] = '\0';
  
  if(strlen(str) < buffsize) str = (char *)realloc(str,sizeof(char) * (buffsize + 1));
  strcpy(str,buff);

  free(buff);
}