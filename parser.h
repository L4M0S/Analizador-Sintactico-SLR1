#ifndef parser_h
#define parser_h

#include"scanner.h"


bool parser();
bool match(token);
bool slr1();
int T(int,token);
int R(int,int);
void init();

#endif
