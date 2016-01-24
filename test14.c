#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include <libreplace.h>

int main(void){
  
  char *str;
  char *regex = "[[:digit:]]{2,5}-[[:digit:]]{1,4}-[[:digit:]]{4}";
  char *replacement = "TEL";
  regex_t reg;
  str = (char *)malloc(sizeof(char)*55);
  strcpy(str,"My number is 0120-345-6789 !");

  regcomp(&reg,regex,REG_EXTENDED);
  replaceAll(str,reg,replacement);


  printf("%s\n",str);

  free(str);
  regfree(&reg);
  return 0;
}
