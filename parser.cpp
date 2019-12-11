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

Controlador transicion;

void initControlador()
{
	//controlador[vertice][token]=accion; //1=shift 2=reduce 3=accept 0==error
	controlador[0][_resta]=1;
	controlador[0][_not]=1;
	controlador[0][_parIzq]=1;
	controlador[0][_num]=1;
	controlador[0][_id]=1;
	controlador[0][_false]=1;
	controlador[0][_true]=1;
	
	controlador[1][_eof]=3;
	
	controlador[2][_interrogacion]=1;
	controlador[2][_dosPuntos]=2;
	controlador[2][_or]=1;
	controlador[2][_parDer]=2;
	controlador[2][_eof]=2;
	
	controlador[3][_interrogacion]=2;
	controlador[3][_dosPuntos]=2;
	controlador[3][_or]=2;
	controlador[3][_and]=1;
	controlador[3][_parDer]=2;
	controlador[3][_eof]=2;
	
	controlador[4][_interrogacion]=2;
	controlador[4][_dosPuntos]=2;
	controlador[4][_or]=2;
	controlador[4][_and]=2;
	controlador[4][_parDer]=2;
	controlador[4][_eof]=2;
	
	controlador[5][_interrogacion]=2;
	controlador[5][_dosPuntos]=2;
	controlador[5][_or]=2;
	controlador[5][_and]=2;
	controlador[5][_parDer]=2;
	controlador[5][_eof]=2;
	controlador[5][_igual]=1;
	controlador[5][_diferente]=1;
	controlador[5][_menor]=1;
	controlador[5][_mayor]=1;
	controlador[5][_menorIgual]=1;
	controlador[5][_mayorIgual]=1;
	controlador[5][_suma]=1;
	controlador[5][_resta]=1;
	
	controlador[6][_interrogacion]=2;
	controlador[6][_dosPuntos]=2;
	controlador[6][_or]=2;
	controlador[6][_and]=2;
	controlador[6][_igual]=2;
	controlador[6][_diferente]=2;
	controlador[6][_menor]=2;
	controlador[6][_mayor]=2;
	controlador[6][_menorIgual]=2;
	controlador[6][_mayorIgual]=2;
	controlador[6][_suma]=2;
	controlador[6][_resta]=2;
	controlador[6][_multi]=1;
	controlador[6][_divi]=1;
	controlador[6][_parDer]=2;
	controlador[6][_eof]=2;
	
	controlador[7][_interrogacion]=2;
	controlador[7][_dosPuntos]=2;
	controlador[7][_or]=2;
	controlador[7][_and]=2;
	controlador[7][_igual]=2;
	controlador[7][_diferente]=2;
	controlador[7][_menor]=2;
	controlador[7][_mayor]=2;
	controlador[7][_menorIgual]=2;
	controlador[7][_mayorIgual]=2;
	controlador[7][_suma]=2;
	controlador[7][_resta]=2;
	controlador[7][_multi]=2;
	controlador[7][_divi]=2;
	controlador[7][_parDer]=2;
	controlador[7][_eof]=2;

	controlador[8][_resta]=1;
	controlador[8][_not]=1;
	controlador[8][_parIzq]=1;
	controlador[8][_num]=1;
	controlador[8][_id]=1;
	controlador[8][_false]=1;
	controlador[8][_true]=1;
	
	controlador[9][_resta]=1;
	controlador[9][_not]=1;
	controlador[9][_parIzq]=1;
	controlador[9][_num]=1;
	controlador[9][_id]=1;
	controlador[9][_false]=1;
	controlador[9][_true]=1;
	
	controlador[10][_resta]=1;
	controlador[10][_not]=1;
	controlador[10][_parIzq]=1;
	controlador[10][_num]=1;
	controlador[10][_id]=1;
	controlador[10][_false]=1;
	controlador[10][_true]=1;
	
	controlador[11][_interrogacion]=2;
	controlador[11][_dosPuntos]=2;
	controlador[11][_or]=2;
	controlador[11][_and]=2;
	controlador[11][_igual]=2;
	controlador[11][_diferente]=2;
	controlador[11][_menor]=2;
	controlador[11][_mayor]=2;
	controlador[11][_menorIgual]=2;
	controlador[11][_mayorIgual]=2;
	controlador[11][_suma]=2;
	controlador[11][_resta]=2;
	controlador[11][_multi]=2;
	controlador[11][_divi]=2;
	controlador[11][_parDer]=2;
	controlador[11][_eof]=2;
	
	controlador[12][_interrogacion]=2;
	controlador[12][_dosPuntos]=2;
	controlador[12][_or]=2;
	controlador[12][_and]=2;
	controlador[12][_igual]=2;
	controlador[12][_diferente]=2;
	controlador[12][_menor]=2;
	controlador[12][_mayor]=2;
	controlador[12][_menorIgual]=2;
	controlador[12][_mayorIgual]=2;
	controlador[12][_suma]=2;
	controlador[12][_resta]=2;
	controlador[12][_multi]=2;
	controlador[12][_divi]=2;
	controlador[12][_parDer]=2;
	controlador[12][_eof]=2;
	
	controlador[13][_interrogacion]=2;
	controlador[13][_dosPuntos]=2;
	controlador[13][_or]=2;
	controlador[13][_and]=2;
	controlador[13][_igual]=2;
	controlador[13][_diferente]=2;
	controlador[13][_menor]=2;
	controlador[13][_mayor]=2;
	controlador[13][_menorIgual]=2;
	controlador[13][_mayorIgual]=2;
	controlador[13][_suma]=2;
	controlador[13][_resta]=2;
	controlador[13][_multi]=2;
	controlador[13][_divi]=2;
	controlador[13][_parDer]=2;
	controlador[13][_eof]=2;

	controlador[14][_interrogacion]=2;
	controlador[14][_dosPuntos]=2;
	controlador[14][_or]=2;
	controlador[14][_and]=2;
	controlador[14][_igual]=2;
	controlador[14][_diferente]=2;
	controlador[14][_menor]=2;
	controlador[14][_mayor]=2;
	controlador[14][_menorIgual]=2;
	controlador[14][_mayorIgual]=2;
	controlador[14][_suma]=2;
	controlador[14][_resta]=2;
	controlador[14][_multi]=2;
	controlador[14][_divi]=2;
	controlador[14][_parDer]=2;
	controlador[14][_eof]=2;
	
	controlador[15][_resta]=1;
	controlador[15][_not]=1;
	controlador[15][_parIzq]=1;
	controlador[15][_num]=1;
	controlador[15][_id]=1;
	controlador[15][_false]=1;
	controlador[15][_true]=1;
	
	controlador[16][_resta]=1;
	controlador[16][_not]=1;
	controlador[16][_parIzq]=1;
	controlador[16][_num]=1;
	controlador[16][_id]=1;
	controlador[16][_false]=1;
	controlador[16][_true]=1;

	controlador[17][_resta]=1;
	controlador[17][_not]=1;
	controlador[17][_parIzq]=1;
	controlador[17][_num]=1;
	controlador[17][_id]=1;
	controlador[17][_false]=1;
	controlador[17][_true]=1;

	controlador[18][_resta]=1;
	controlador[18][_not]=1;
	controlador[18][_parIzq]=1;
	controlador[18][_num]=1;
	controlador[18][_id]=1;
	controlador[18][_false]=1;
	controlador[18][_true]=1;

	controlador[19][_resta]=1;
	controlador[19][_not]=1;
	controlador[19][_parIzq]=1;
	controlador[19][_num]=1;
	controlador[19][_id]=1;
	controlador[19][_false]=1;
	controlador[19][_true]=1;
	
	controlador[20][_resta]=1;
	controlador[20][_not]=1;
	controlador[20][_parIzq]=1;
	controlador[20][_num]=1;
	controlador[20][_id]=1;
	controlador[20][_false]=1;
	controlador[20][_true]=1;
	
	controlador[21][_resta]=1;
	controlador[21][_not]=1;
	controlador[21][_parIzq]=1;
	controlador[21][_num]=1;
	controlador[21][_id]=1;
	controlador[21][_false]=1;
	controlador[21][_true]=1;
	
	controlador[22][_resta]=1;
	controlador[22][_not]=1;
	controlador[22][_parIzq]=1;
	controlador[22][_num]=1;
	controlador[22][_id]=1;
	controlador[22][_false]=1;
	controlador[22][_true]=1;
	
	controlador[23][_resta]=1;
	controlador[23][_not]=1;
	controlador[23][_parIzq]=1;
	controlador[23][_num]=1;
	controlador[23][_id]=1;
	controlador[23][_false]=1;
	controlador[23][_true]=1;

	controlador[24][_resta]=1;
	controlador[24][_not]=1;
	controlador[24][_parIzq]=1;
	controlador[24][_num]=1;
	controlador[24][_id]=1;
	controlador[24][_false]=1;
	controlador[24][_true]=1;

	controlador[25][_resta]=1;
	controlador[25][_not]=1;
	controlador[25][_parIzq]=1;
	controlador[25][_num]=1;
	controlador[25][_id]=1;
	controlador[25][_false]=1;
	controlador[25][_true]=1;
	
	controlador[26][_resta]=1;
	controlador[26][_not]=1;
	controlador[26][_parIzq]=1;
	controlador[26][_num]=1;
	controlador[26][_id]=1;
	controlador[26][_false]=1;
	controlador[26][_true]=1;
	
	controlador[27][_resta]=1;
	controlador[27][_not]=1;
	controlador[27][_parIzq]=1;
	controlador[27][_num]=1;
	controlador[27][_id]=1;
	controlador[27][_false]=1;
	controlador[27][_true]=1;
	
	controlador[28][_interrogacion]=2;
	controlador[28][_dosPuntos]=2;
	controlador[28][_or]=2;
	controlador[28][_and]=2;
	controlador[28][_igual]=2;
	controlador[28][_diferente]=2;
	controlador[28][_menor]=2;
	controlador[28][_mayor]=2;
	controlador[28][_menorIgual]=2;
	controlador[28][_mayorIgual]=2;
	controlador[28][_suma]=2;
	controlador[28][_resta]=2;
	controlador[28][_multi]=2;
	controlador[28][_divi]=2;
	controlador[28][_parDer]=2;
	controlador[28][_eof]=2;
	
	controlador[29][_interrogacion]=2;
	controlador[29][_dosPuntos]=2;
	controlador[29][_or]=2;
	controlador[29][_and]=2;
	controlador[29][_igual]=2;
	controlador[29][_diferente]=2;
	controlador[29][_menor]=2;
	controlador[29][_mayor]=2;
	controlador[29][_menorIgual]=2;
	controlador[29][_mayorIgual]=2;
	controlador[29][_suma]=2;
	controlador[29][_resta]=2;
	controlador[29][_multi]=2;
	controlador[29][_divi]=2;
	controlador[29][_parDer]=2;
	controlador[29][_eof]=2;
	
	controlador[30][_parDer]=1;
	
	controlador[31][_dosPuntos]=1;
	
	controlador[32][_interrogacion]=2;
	controlador[32][_dosPuntos]=2;
	controlador[32][_or]=2;
	controlador[32][_and]=1;
	controlador[32][_parDer]=2;
	controlador[32][_eof]=2;
	
	controlador[33][_interrogacion]=2;
	controlador[33][_dosPuntos]=2;
	controlador[33][_or]=2;
	controlador[33][_and]=2;
	controlador[33][_parDer]=2;
	controlador[33][_eof]=2;
	
	controlador[34][_interrogacion]=2;
	controlador[34][_dosPuntos]=2;
	controlador[34][_or]=2;
	controlador[34][_and]=2;
	controlador[34][_suma]=1;
	controlador[34][_resta]=1;
	controlador[34][_parDer]=2;
	controlador[34][_eof]=2;
	
	controlador[35][_interrogacion]=2;
	controlador[35][_dosPuntos]=2;
	controlador[35][_or]=2;
	controlador[35][_and]=2;
	controlador[35][_suma]=1;
	controlador[35][_resta]=1;
	controlador[35][_parDer]=2;
	controlador[35][_eof]=2;
	
	controlador[36][_interrogacion]=2;
	controlador[36][_dosPuntos]=2;
	controlador[36][_or]=2;
	controlador[36][_and]=2;
	controlador[36][_suma]=1;
	controlador[36][_resta]=1;
	controlador[36][_parDer]=2;
	controlador[36][_eof]=2;
	
	controlador[37][_interrogacion]=2;
	controlador[37][_dosPuntos]=2;
	controlador[37][_or]=2;
	controlador[37][_and]=2;
	controlador[37][_suma]=1;
	controlador[37][_resta]=1;
	controlador[37][_parDer]=2;
	controlador[37][_eof]=2;
	
	controlador[38][_interrogacion]=2;
	controlador[38][_dosPuntos]=2;
	controlador[38][_or]=2;
	controlador[38][_and]=2;
	controlador[38][_suma]=1;
	controlador[38][_resta]=1;
	controlador[38][_parDer]=2;
	controlador[38][_eof]=2;
	
	controlador[39][_interrogacion]=2;
	controlador[39][_dosPuntos]=2;
	controlador[39][_or]=2;
	controlador[39][_and]=2;
	controlador[39][_suma]=1;
	controlador[39][_resta]=1;
	controlador[39][_parDer]=2;
	controlador[39][_eof]=2;
	
	controlador[40][_interrogacion]=2;
	controlador[40][_dosPuntos]=2;
	controlador[40][_or]=2;
	controlador[40][_and]=2;
	controlador[40][_igual]=2;
	controlador[40][_diferente]=2;
	controlador[40][_menor]=2;
	controlador[40][_mayor]=2;
	controlador[40][_menorIgual]=2;
	controlador[40][_mayorIgual]=2;
	controlador[40][_suma]=2;
	controlador[40][_resta]=2;
	controlador[40][_multi]=1;
	controlador[40][_divi]=1;
	controlador[40][_parDer]=2;
	controlador[40][_eof]=2;
	
	controlador[41][_interrogacion]=2;
	controlador[41][_dosPuntos]=2;
	controlador[41][_or]=2;
	controlador[41][_and]=2;
	controlador[41][_igual]=2;
	controlador[41][_diferente]=2;
	controlador[41][_menor]=2;
	controlador[41][_mayor]=2;
	controlador[41][_menorIgual]=2;
	controlador[41][_mayorIgual]=2;
	controlador[41][_suma]=2;
	controlador[41][_resta]=2;
	controlador[41][_multi]=1;
	controlador[41][_divi]=1;
	controlador[41][_parDer]=2;
	controlador[41][_eof]=2;
	
	controlador[42][_interrogacion]=2;
	controlador[42][_dosPuntos]=2;
	controlador[42][_or]=2;
	controlador[42][_and]=2;
	controlador[42][_igual]=2;
	controlador[42][_diferente]=2;
	controlador[42][_menor]=2;
	controlador[42][_mayor]=2;
	controlador[42][_menorIgual]=2;
	controlador[42][_mayorIgual]=2;
	controlador[42][_suma]=2;
	controlador[42][_resta]=2;
	controlador[42][_multi]=2;
	controlador[42][_divi]=2;
	controlador[42][_parDer]=2;
	controlador[42][_eof]=2;
	
	controlador[43][_interrogacion]=2;
	controlador[43][_dosPuntos]=2;
	controlador[43][_or]=2;
	controlador[43][_and]=2;
	controlador[43][_igual]=2;
	controlador[43][_diferente]=2;
	controlador[43][_menor]=2;
	controlador[43][_mayor]=2;
	controlador[43][_menorIgual]=2;
	controlador[43][_mayorIgual]=2;
	controlador[43][_suma]=2;
	controlador[43][_resta]=2;
	controlador[43][_multi]=2;
	controlador[43][_divi]=2;
	controlador[43][_parDer]=2;
	controlador[43][_eof]=2;

	controlador[44][_interrogacion]=2;
	controlador[44][_dosPuntos]=2;
	controlador[44][_or]=2;
	controlador[44][_and]=2;
	controlador[44][_igual]=2;
	controlador[44][_diferente]=2;
	controlador[44][_menor]=2;
	controlador[44][_mayor]=2;
	controlador[44][_menorIgual]=2;
	controlador[44][_mayorIgual]=2;
	controlador[44][_suma]=2;
	controlador[44][_resta]=2;
	controlador[44][_multi]=2;
	controlador[44][_divi]=2;
	controlador[44][_parDer]=2;
	controlador[44][_eof]=2;

	controlador[45][_resta]=1;
	controlador[45][_not]=1;
	controlador[45][_parIzq]=1;
	controlador[45][_num]=1;
	controlador[45][_id]=1;
	controlador[45][_false]=1;
	controlador[45][_true]=1;
	
	controlador[46][_dosPuntos]=2;
	controlador[46][_parDer]=2;
	controlador[46][_eof]=2;
}

void initTransicion()
{
	///////////////////////////////////////////////////////////////////////////////////////
	transicion[0][_QUEST]=1;
	transicion[0][_PROP]=2;
	transicion[0][_CLAUSE]=3;
	transicion[0][_REL]=4;
	transicion[0][_EXP]=5;
	transicion[0][_TERM]=6;
	transicion[0][_FACT]=7;
	transicion[0][_resta]=8;
	transicion[0][_not]=9;
	transicion[0][_parIzq]=10;
	transicion[0][_num]=11;
	transicion[0][_id]=12;
	transicion[0][_false]=13;
	transicion[0][_true]=14;
	
	transicion[2][_interrogacion]=15;
	transicion[2][_or]=16;
	
	transicion[3][_and]=17;
	
	transicion[5][_igual]=18;
	transicion[5][_diferente]=19;
	transicion[5][_menor]=20;
	transicion[5][_mayor]=21;
	transicion[5][_menorIgual]=22;
	transicion[5][_mayorIgual]=23;
	transicion[5][_suma]=24;
	transicion[5][_resta]=25;
	
	transicion[6][_multi]=26;
	transicion[6][_divi]=27;
	
	transicion[8][_FACT]=28;
	transicion[8][_resta]=8;
	transicion[8][_not]=9;
	transicion[8][_parIzq]=10;
	transicion[8][_num]=11;
	transicion[8][_id]=12;
	transicion[8][_false]=13;
	transicion[8][_true]=14;
	
	transicion[9][_FACT]=29;
	transicion[9][_resta]=8;
	transicion[9][_not]=9;
	transicion[9][_parIzq]=10;
	transicion[9][_num]=11;
	transicion[9][_id]=12;
	transicion[9][_false]=13;
	transicion[9][_true]=14;
	
	transicion[10][_QUEST]=30;
	transicion[10][_PROP]=2;
	transicion[10][_CLAUSE]=3;
	transicion[10][_REL]=4;
	transicion[10][_EXP]=5;
	transicion[10][_TERM]=6;
	transicion[10][_FACT]=7;
	transicion[10][_resta]=8;
	transicion[10][_not]=9;
	transicion[10][_parIzq]=10;
	transicion[10][_num]=11;
	transicion[10][_id]=12;
	transicion[10][_false]=13;
	transicion[10][_true]=14;
	
	transicion[15][_QUEST]=31;
	transicion[15][_PROP]=2;
	transicion[15][_CLAUSE]=3;
	transicion[15][_REL]=4;
	transicion[15][_EXP]=5;
	transicion[15][_TERM]=6;
	transicion[15][_FACT]=7;
	transicion[15][_resta]=8;
	transicion[15][_not]=9;
	transicion[15][_parIzq]=10;
	transicion[15][_num]=11;
	transicion[15][_id]=12;
	transicion[15][_false]=13;
	transicion[15][_true]=14;
	
	transicion[16][_CLAUSE]=32;
	transicion[16][_REL]=4;
	transicion[16][_EXP]=5;
	transicion[16][_TERM]=6;
	transicion[16][_FACT]=7;
	transicion[16][_resta]=8;
	transicion[16][_not]=9;
	transicion[16][_parIzq]=10;
	transicion[16][_num]=11;
	transicion[16][_id]=12;
	transicion[16][_false]=13;
	transicion[16][_true]=14;

	transicion[17][_REL]=33;
	transicion[17][_EXP]=5;
	transicion[17][_TERM]=6;
	transicion[17][_FACT]=7;
	transicion[17][_resta]=8;
	transicion[17][_not]=9;
	transicion[17][_parIzq]=10;
	transicion[17][_num]=11;
	transicion[17][_id]=12;
	transicion[17][_false]=13;
	transicion[17][_true]=14;

	transicion[18][_EXP]=34;
	transicion[18][_TERM]=6;
	transicion[18][_FACT]=7;
	transicion[18][_resta]=8;
	transicion[18][_not]=9;
	transicion[18][_parIzq]=10;
	transicion[18][_num]=11;
	transicion[18][_id]=12;
	transicion[18][_false]=13;
	transicion[18][_true]=14;

	transicion[19][_EXP]=35;
	transicion[19][_TERM]=6;
	transicion[19][_FACT]=7;
	transicion[19][_resta]=8;
	transicion[19][_not]=9;
	transicion[19][_parIzq]=10;
	transicion[19][_num]=11;
	transicion[19][_id]=12;
	transicion[19][_false]=13;
	transicion[19][_true]=14;
	
	transicion[20][_EXP]=36;
	transicion[20][_TERM]=6;
	transicion[20][_FACT]=7;
	transicion[20][_resta]=8;
	transicion[20][_not]=9;
	transicion[20][_parIzq]=10;
	transicion[20][_num]=11;
	transicion[20][_id]=12;
	transicion[20][_false]=13;
	transicion[20][_true]=14;
	
	transicion[21][_EXP]=37;
	transicion[21][_TERM]=6;
	transicion[21][_FACT]=7;
	transicion[21][_resta]=8;
	transicion[21][_not]=9;
	transicion[21][_parIzq]=10;
	transicion[21][_num]=11;
	transicion[21][_id]=12;
	transicion[21][_false]=13;
	transicion[21][_true]=14;
	
	transicion[22][_EXP]=38;
	transicion[22][_TERM]=6;
	transicion[22][_FACT]=7;
	transicion[22][_resta]=8;
	transicion[22][_not]=9;
	transicion[22][_parIzq]=10;
	transicion[22][_num]=11;
	transicion[22][_id]=12;
	transicion[22][_false]=13;
	transicion[22][_true]=14;
	
	transicion[23][_EXP]=39;
	transicion[23][_TERM]=6;
	transicion[23][_FACT]=7;
	transicion[23][_resta]=8;
	transicion[23][_not]=9;
	transicion[23][_parIzq]=10;
	transicion[23][_num]=11;
	transicion[23][_id]=12;
	transicion[23][_false]=13;
	transicion[23][_true]=14;

	transicion[24][_TERM]=40;
	transicion[24][_FACT]=7;
	transicion[24][_resta]=8;
	transicion[24][_not]=9;
	transicion[24][_parIzq]=10;
	transicion[24][_num]=11;
	transicion[24][_id]=12;
	transicion[24][_false]=13;
	transicion[24][_true]=14;

	transicion[25][_TERM]=41;
	transicion[25][_FACT]=7;
	transicion[25][_resta]=8;
	transicion[25][_not]=9;
	transicion[25][_parIzq]=10;
	transicion[25][_num]=11;
	transicion[25][_id]=12;
	transicion[25][_false]=13;
	transicion[25][_true]=14;
	
	transicion[26][_FACT]=42;
	transicion[26][_resta]=8;
	transicion[26][_not]=9;
	transicion[26][_parIzq]=10;
	transicion[26][_num]=11;
	transicion[26][_id]=12;
	transicion[26][_false]=13;
	transicion[26][_true]=14;
	
	transicion[27][_FACT]=43;
	transicion[27][_resta]=8;
	transicion[27][_not]=9;
	transicion[27][_parIzq]=10;
	transicion[27][_num]=11;
	transicion[27][_id]=12;
	transicion[27][_false]=13;
	transicion[27][_true]=14;

	transicion[30][_parDer]=44;

	transicion[31][_dosPuntos]=45;
	
	transicion[32][_and]=17;
	
	transicion[34][_suma]=24;
	transicion[34][_resta]=25;
	
	transicion[35][_suma]=24;
	transicion[35][_resta]=25;
	
	transicion[36][_suma]=24;
	transicion[36][_resta]=25;
	
	transicion[37][_suma]=24;
	transicion[37][_resta]=25;
	
	transicion[38][_suma]=24;
	transicion[38][_resta]=25;
	
	transicion[39][_suma]=24;
	transicion[39][_resta]=25;
	
	transicion[40][_multi]=26;
	transicion[40][_divi]=27;
	
	transicion[41][_multi]=26;
	transicion[41][_divi]=27;

	transicion[45][_QUEST]=46;
	transicion[45][_PROP]=2;
	transicion[45][_CLAUSE]=3;
	transicion[45][_REL]=4;
	transicion[45][_EXP]=5;
	transicion[45][_TERM]=6;
	transicion[45][_FACT]=7;
	transicion[45][_resta]=8;
	transicion[45][_not]=9;
	transicion[45][_parIzq]=10;
	transicion[45][_num]=11;
	transicion[45][_id]=12;
	transicion[45][_false]=13;
	transicion[45][_true]=14;
}

void init()
{
	initControlador();
	initTransicion();
	
}

bool parser() 
{
 	init();		
 	
	/*token p=next();
	int i=1;
	while(p!=_eof && p!=_error)
	{
		p=next();
	}*/
	
	return slr1();
}

retorno T(int v,token f)
{
	retorno r;
	
	if(controlador[v][f]==1)
	{
		r.tipo=1;
		
		return r;
	}
	else if(controlador[v][f]==2)
	{
		r.tipo=2;
		
		if(v==2){r.n=1; r.A=_QUEST;}
		else if(v==3){r.n=1; r.A=_PROP;}
		else if(v==4){r.n=1; r.A=_CLAUSE;}
		else if(v==5){r.n=1; r.A=_REL;}
		else if(v==6){r.n=1; r.A=_EXP;}
		else if(v==7){r.n=1; r.A=_TERM;}
		else if(v==11){r.n=1; r.A=_FACT;}
		else if(v==12){r.n=1; r.A=_FACT;}
		else if(v==13){r.n=1; r.A=_FACT;}
		else if(v==14){r.n=1; r.A=_FACT;}
		else if(v==28){r.n=2; r.A=_FACT;}
		else if(v==29){r.n=2; r.A=_FACT;}
		else if(v==32){r.n=3; r.A=_PROP;}
		else if(v==33){r.n=3; r.A=_CLAUSE;}
		else if(v==34){r.n=3; r.A=_REL;}
		else if(v==35){r.n=3; r.A=_REL;}
		else if(v==36){r.n=3; r.A=_REL;}
		else if(v==37){r.n=3; r.A=_REL;}
		else if(v==38){r.n=3; r.A=_REL;}
		else if(v==39){r.n=3; r.A=_REL;}
		else if(v==40){r.n=3; r.A=_EXP;}
		else if(v==41){r.n=3; r.A=_EXP;}
		else if(v==42){r.n=3; r.A=_TERM;}
		else if(v==43){r.n=3; r.A=_TERM;}
		else if(v==44){r.n=3; r.A=_FACT;}
		else if(v==46){r.n=5; r.A=_QUEST;}
	}
	else if(controlador[v][f]==3)
	{
		r.tipo=3;
		return r;
	}
	
	//return controlador[v][f];
	return r;
}

int R(int v,token A)
{
	int r=transicion[v][A];
	if(r==0)return -1; 
	return r;
}

bool slr1()
{
	init();
	stack<int> pila;
	int v;
	token A;
	int n;
	int op;
	
	pila.push(0);
	t=next();
	
	retorno r;
	
	do
	{
		v=pila.top();
		//printf(" v:%i ",v);
		r=T(v,t);
		op=r.tipo;
		
		switch(op)
		{
			case 1: //shift
				//if(R(v,t)==0) return false;
				//printf(" S,%i ",R(v,t));
				pila.push(R(v,t));
				t=next();
				break;
			case 2: //reduce
				n=r.n;
				for(int i=0;i<n;i++)
				{
					pila.pop();
				}
				A=r.A;
				//if(R(pila.top(),A)==0) return false;
				//printf(" (R,%i)",n);
				//printf(",%i,%i ",pila.top(),R(pila.top(),A));
				pila.push(R(pila.top(),A));
				break;
			case 0: //error
				//printf(" -error- ");
				return false;
				break;
			case 3: //accept
				//printf(" -accept- ");
				while(!pila.empty()) pila.pop();
				//return true;
				break;
		}
		//system("pause");
	}while(!pila.empty());
	
	return true;
}
