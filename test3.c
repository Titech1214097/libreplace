#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include <libreplace.h>

char* capitalize(char* str){
  if(str[0] >= 'a' && str[0] <= 'z') str[0] = str[0] - ('a' - 'A');
  return str;
}
  

int main(void){


  char *str;
  char *regex = "\\w+";
  regex_t reg;
  str = (char *)malloc(sizeof(char)*55);
  strcpy(str,"hello, world");

  regcomp(&reg,regex,REG_EXTENDED);
  replaceFuncAll(str,reg,capitalize,0);


  printf("%s\n",str);

  free(str);
  regfree(&reg);
  return 0;
}

/*
s = "hello, world"
puts s.gsub(/\w+/) {|word| word.capitalize }
*/