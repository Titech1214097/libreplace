#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>


#include <time.h>

int main(void){
  
  char *str;
  char *regex = "_([^_]+)_";
  regmatch_t match[10];
  regex_t reg;
  clock_t c1,c2;
  int i = 0;

  str = (char *)malloc(50);
  strcpy(str,"_Ruby_ is _cool_");
  
  c1 = clock();
  regcomp(&reg,regex,REG_EXTENDED);
  while( i < 1000000){
	regexec(&reg,str,10,match,0);
        i++; 
  }
  c2 = clock();
  printf("%d %d %d\n",c1,c2,CLOCKS_PER_SEC);

  free(str);
  regfree(&reg);
  return 0;
}
