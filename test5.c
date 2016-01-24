#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include <libreplace.h>


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
  str = (char *)malloc(sizeof(char)*55);
  strcpy(str,"hello, world");

  regcomp(&reg,regex,REG_EXTENDED);
  replaceFunc(str,reg,upcase,0);

  printf("%s\n",str);

  free(str);
  regfree(&reg);
  return 0;
}
