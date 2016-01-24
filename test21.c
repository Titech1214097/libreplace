#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include <libreplace.h>

int main(void){
  
  char *str;
  char *regex = "v[i!1][a@]gr[a@]";
  char *replacement = "viagra";
  regex_t reg;
  str = (char *)malloc(sizeof(char)*55);
  strcpy(str,"vi@gra v1agra v1@gra v!@gra");

  regcomp(&reg,regex,REG_EXTENDED);
  replaceAll(str,reg,replacement);


  printf("%s\n",str);

  free(str);
  regfree(&reg);
  return 0;
}
