#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include <libreplace.h>

#include <time.h>

int main(void){
  
  char *str;
  char *regex = "([[:digit:]]{1,4})[/-]([[:digit:]]{1,2})[/-]([[:digit:]]{1,2})";
  char *replacement = "\\1”N\\2ŒŽ\\3“ú";
  regex_t reg;
  clock_t c1,c2;
  int i = 0;

  c1 = clock();
  regcomp(&reg,regex,REG_EXTENDED);
  while(i < 1000000){
    str = (char *)malloc(sizeof(char)*55);
    strcpy(str,"Ž„‚Í2015-11-10‚É‹A‘î");
    replaceAll(str,reg,replacement);
    i++;
  }
  c2 = clock();

  printf("%d %d %d\n",c1,c2,CLOCKS_PER_SEC);

  free(str);
  regfree(&reg);
  return 0;
}
