#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include <libreplace.h>

int main(void){
  
  char *str;
  char *regex = "([[:digit:]]{1,4})[/-]([[:digit:]]{1,2})[/-]([[:digit:]]{1,2})";
  char *replacement = "\\1�N\\2��\\3��";
  regex_t reg;
  str = (char *)malloc(sizeof(char)*55);
  strcpy(str,"����2015-11-10�ɋA��");

  regcomp(&reg,regex,REG_EXTENDED);
  replaceAll(str,reg,replacement);

  printf("%s\n",str);

  free(str);
  regfree(&reg);
  return 0;
}
