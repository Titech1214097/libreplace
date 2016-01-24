#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include <libreplace.h>

int main(void){
  
  char *str;
  char *regex = "stock\\s*tips?";
  char *replacement = "[\\0]";
  regex_t reg;
  str = (char *)malloc(sizeof(char)*55);
  strcpy(str,"I have two stock tips");

  regcomp(&reg,regex,REG_EXTENDED);
  replaceAll(str,reg,replacement);


  printf("%s\n",str);

  free(str);
  regfree(&reg);
  return 0;
}
