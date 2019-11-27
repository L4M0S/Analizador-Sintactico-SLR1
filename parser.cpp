#include"parser.h"

#include"scanner.h"

#include<cstdio>
#include<stack>
#include<map>
#include<set>
#include<vector>

token t;

typedef map<token,int> Par;
typedef map<int,Par> Controlador;
Controlador controlador;

void init()
{
	//controlador[vertice][token]=accion;
}

bool parser() 
{		
	return slr1();
}

int T(int v,token f) //controlador
{
	return 3;
}

int R(int A,int n)
{
	return 0;
}

bool match(token k)
{
	if(k==t)
	{
		t=next();
		return true;
	}
	return false;
}

bool slr1()
{
	init();
	stack<int> pila;
	int v;
	int A;
	int op;
	
	pila.push(0);
	t=next();
	
	do
	{
		v=pila.top();
		op=T(v,t);
		
		switch(op)
		{
			case 1: //shift
				pila.push(R(v,t));
				t=next();
				break;
			case 2: //reduce
				pila.pop();
				pila.push(R(pila.top(),A));
				break;
			case 0: //error
				return false;
				break;
			case 3: //accept
				pila.empty();
				break;
		}
		
	}while(!pila.empty());
	
	return true;
}

