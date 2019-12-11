#ifndef parser_h
#define parser_h

#include"scanner.h"

typedef class retorno
{
	public:
	int tipo=0;
	int n=0;
	token A=_error;
};


bool parser();
bool slr1();
retorno T(int,token);
int R(int,token);
void init();
void initControlador();
void initTransicion();

#endif
