#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include <libreplace.h>

int main(void){
  
  char *str;
  char *regex = "_([^_]+)_";
  char *replacement = "<em>\\1</em>";
  regex_t reg;
  str = (char *)malloc(sizeof(char)*55);
  strcpy(str,"_Ruby_ is _cool_.");

  regcomp(&reg,regex,REG_EXTENDED);
  replaceAll(str,reg,replacement);


  printf("%s\n",str);

  free(str);
  regfree(&reg);
  return 0;
}
