#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include <libreplace.h>

int main(void){
  
  char *str;
  char *regex = ".*\n";
  char *replacement = ">\\0";
  regex_t reg;
  str = (char *)malloc(sizeof(char)*55);
  strcpy(str,"abc\ndef\nghijk\nlmn\n");

  regcomp(&reg,regex,REG_EXTENDED|REG_NEWLINE);
  replaceAll(str,reg,replacement);


  printf("%s\n",str);

  free(str);
  regfree(&reg);
  return 0;
}
