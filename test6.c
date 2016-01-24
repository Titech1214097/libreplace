#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <libreplace.h>
#include <regex.h>



int main(void){
  
  char *str;
  char *regex = "abc";
  char *replacement = "[\\0]";
  regex_t reg;
  str = (char *)malloc(sizeof(char)*55);
  strcpy(str,"Abc-ABC-AbC-abc");


  regcomp(&reg,regex,REG_EXTENDED|REG_ICASE);
  replaceAll(str,reg,replacement);


  printf("%s\n",str);

  free(str);
  regfree(&reg);
  return 0;
}
