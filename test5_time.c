#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include <libreplace.h>

#include <time.h>


char* upcase(char* str){
  int i;
  for(i = 0; str[i] != '\0';i++){
     if(str[i] >= 'a' && str[i] <= 'z') str[i] = str[i] -('a' - 'A');
  }
  return str;
}

int main(void){
  
  char *str;
  char *regex = "\\w+";
  regex_t reg;
  clock_t c1,c2;
  int i = 0;

  c1 = clock();
  regcomp(&reg,regex,REG_EXTENDED);
  while(i < 1000000){
    str = (char *)malloc(sizeof(char)*55);
    strcpy(str,"hello, world");
    replaceFunc(str,reg,upcase,0);
    i++;
  }
  c2 = clock();
  printf("%d %d %d\n",c1,c2,CLOCKS_PER_SEC);

  free(str);
  regfree(&reg);
  return 0;
}
