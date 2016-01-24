#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libreplace.h>

#include <regex.h>


int main(void){
  
  char *str;
  char *regex = "true|false";
  char *replacement = "bool";
  regex_t reg;
  str = (char *)malloc(sizeof(char)*55);
  strcpy(str,"i = false; j = true;");

  regcomp(&reg,regex,REG_EXTENDED);
  replaceAll(str,reg,replacement);


  printf("%s\n",str);

  free(str);
  regfree(&reg);
  return 0;
}
