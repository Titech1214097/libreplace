#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define SIZE 1000

void replace(char* str, regex_t reg,char* replacement){

    int match_elems = 100;
    regmatch_t match[100];

    char* right;
    int rightsize;

    char* middle;

    int i,j,k,l;

    if(regexec(&reg, str, match_elems, match, 0) != REG_NOMATCH){ 

      middle = (char *)malloc(sizeof(char) * SIZE);
      if(middle == NULL) exit(1);
      
      
     //Check meta word in replacement
      for(i = 0,j = 0;replacement[i] != '\0';i++){
	if(replacement[i] == '\\'){
	  if('0' <= replacement[i + 1] && replacement[i + 1] <= '9'){
	    k = (int)replacement[i + 1] - (int)'0';
	    for(l = match[k].rm_so; l < match[k].rm_eo;j++,l++){
              if(j!=0 && (j%1000 == 0)) middle = (char *)realloc(middle,sizeof(char) * (j + SIZE));
              middle[j] = str[l];
	    }
	    i++;
	  }else if(replacement[i + 1] == '+'){
	    for(k = 0;(match[k].rm_so != -1) && (k <= 10);k++);
	    for(l = match[k-1].rm_so; l < match[k-1].rm_eo;j++,l++){
              if(j!=0 && (j%1000 == 0)) middle = (char *)realloc(middle,sizeof(char) * (j + SIZE));
              middle[j] = str[l];
            }
	    i++;
	  } else if(replacement[i + 1] == '`'){
	    for(l = 0; l < match[0].rm_so;j++,l++){
              if(j!=0 && (j%1000 == 0)) middle = (char *)realloc(middle,sizeof(char) * (j + SIZE));
              middle[j] = str[l];
            }
	    i++;
	  }else if(replacement[i + 1] == '\''){
	    for(l = match[0].rm_eo; str[l] != '\0';j++,l++){
              if(j!=0 && (j%1000 == 0)) middle = (char *)realloc(middle,sizeof(char) * (j + SIZE));
              middle[j] = str[l];
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


      //right buffer
      for(i =0; str[i + match[0].rm_eo] != '\0';i++);
      rightsize = i + 1;
      right = (char *)malloc( sizeof(char) * rightsize);
      if(right == NULL) exit(1);
      for(i = 0,j = match[0].rm_eo;str[j] != '\0';i++ ,j++) right[i] = str[j];
      right[i] = '\0';

      
      if(strlen(str) < match[0].rm_so + strlen(middle) + rightsize)
      str = (char *)realloc(str,sizeof(char)* (match[0].rm_so + strlen(middle) + rightsize));

      for(i = match[0].rm_so,j = 0;middle[j] != '\0';i++, j++) str[i] = middle[j];
      for(j = 0;right[j] != '\0'; i++,j++) str[i] = right[j];
      str[i] = '\0';

      free(right);
      free(middle);

    }
}
