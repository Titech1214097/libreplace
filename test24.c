#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include <libreplace.h>

int main(void){
  
  char *str;
  char *regex = "([[:digit:]]{1,4})[/-]([[:digit:]]{1,2})[/-]([[:digit:]]{1,2})";
  char *replacement = "\\1年\\2月\\3日";
  regex_t reg;
  str = (char *)malloc(sizeof(char)*55);
  strcpy(str,"私は2015-11-10に帰宅");

  regcomp(&reg,regex,REG_EXTENDED);
  replaceAll(str,reg,replacement);

  printf("%s\n",str);

  free(str);
  regfree(&reg);
  return 0;
}
