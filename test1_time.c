#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include <libreplace.h>

#include <time.h>

int main(void){
  
  char *str;
  char *regex = "(\r\n|\r|\n)";
  char *replacement = "<br />";
  regex_t reg;
  clock_t c1,c2;
  int i = 0;
  
  c1 = clock();
  regcomp(&reg,regex,REG_EXTENDED);
  while( i < 1000000){
	str = (char *)malloc(sizeof(char)*55);
  	strcpy(str,"hello,\nworld\r\n");
  	replaceAll(str,reg,replacement);
        i++; 
  }
  c2 = clock();
  printf("%d %d %d\n",c1,c2,CLOCKS_PER_SEC);

  free(str);
  regfree(&reg);
  return 0;
}
