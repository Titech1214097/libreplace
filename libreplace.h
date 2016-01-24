#include <regex.h>
void replace(char* str,regex_t reg,char* replacement);

void replaceAll(char* str,regex_t reg,char*replacement);

void replaceFunc(char* str,regex_t reg,char* (*func)(char*),int cap);

void replaceFuncAll(char* str,regex_t reg,char* (*func)(char*),int cap);