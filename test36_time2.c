#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include <libreplace.h>

#include <time.h>

int main(void){
  
  regmatch_t match[10];
  char *str;
  char *regex = "(http://)([^/]*)/(.*)";
  char *replacement = "[\\0]";
  regex_t reg;
  clock_t c1,c2;
  int i = 0;
  FILE *fp;
  char com[2000];


  str = (char *)malloc(2000);
  fp = fopen("str.txt","r");
  if(fp == NULL){
    printf("FILE READ ERROR");
    return -1;
  }

  fgets(com,1025,fp);
  com[1024] = '\0';
  strcpy(str,com);

  c1 = clock();
  regcomp(&reg,regex,REG_EXTENDED);
  while(i < 1000000){
    regexec(&reg,str,10,match,0);
    i++;
  }
  c2 = clock();

  printf("%d %d %d\n",c1,c2,CLOCKS_PER_SEC);

  free(str);
  fclose(fp);
  regfree(&reg);
  return 0;
}
