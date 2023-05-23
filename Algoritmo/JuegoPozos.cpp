#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int tablero[9][9], i=0, j=0, t=0, casilla1[2], casilla2[2], perdio=0, gano=0, mov_ar=1, mov_der=1, mov_izq=1, mov_ab=1, movimiento[2], respuesta;
char piso[]="X", pozo[]="O", pj[]="R", input[1], izquierda[]="a", derecha[]="d", abajo[]="s", arriba[]="w", pregunta[2], resp[]="si";
main()
{
	srand(time(NULL));
	printf("\n");
	printf("En este juego usted debe llegar a la posicion 9:9 mediante el movimiento de casillas de a una por vez.\n");
	printf("\n");
	printf("Para eso, seleccione la direccion en la que le gustaria moverse usando wasd.\n");
	printf("\n");
	printf("Si cae en uno de los pozos generados aleatoriamente pierde.\n");
	printf("\n");
do
{	
	movimiento[1] = 0;
	movimiento[0] = 0;
	perdio = 0;
	gano = 0;
	for(t=0;t<3;t++)
	{
	casilla1[t] = 1+rand()%(9-1);
	casilla2[t] = 1+rand()%(9-1);		
	}
	for(t=0;t<3;t++)
	{
		if(casilla1[t] == 0 && casilla2[t] == 0)
		{
			casilla1[t] = 1+rand()%(9-1);
			casilla2[t] = 1+rand()%(9-1);
		}
	}
		for(t=0;t<3;t++)
	{
		if(casilla1[t] == 9 && casilla2[t] == 9)
		{
			casilla1[t] = 1+rand()%(9-1);
			casilla2[t] = 1+rand()%(9-1);
		}
	}
	do
	{
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			
			if(i== movimiento[1] && j==movimiento[0])
			{
			printf("%s ", pj);			
			}
			else
			{
			tablero[i][j] = tablero[i][j] + 1;
			printf("%s ", piso);				
			}
			for(t=0;t<3;t++)
			{
			if(movimiento[1] == casilla1[t]-1 && movimiento[0] == casilla2[t]-1)
			{
				perdio = 1;
			}			
			if(movimiento[1] == 8 && movimiento[0] == 8)
			{
				gano = 1;
			}					
			}		
		}
		printf("\n");
	}
	
	if(gano==1)
	{
		printf("Usted gano!");
	}
	else if(perdio==1)
	{
	printf("Usted cayo en un pozo y perdio.");		
	}
	else
	{
		
	printf("Ingrese la direccion en la que le gustaria moverse: ");
	scanf("%s", &input);
	
	mov_ar = strcmp(input,arriba);
	if(mov_ar == 0)
	{
		movimiento[1] = movimiento[1] - 1;
	}
	
	mov_ab = strcmp(input,abajo);
	if(mov_ab == 0)
	{
		movimiento[1] = movimiento[1] + 1;
	}
		
	mov_der = strcmp(input,derecha);
	if(mov_der == 0)
	{
		movimiento[0] = movimiento[0]+1;
	}
	
	mov_izq = strcmp(input,izquierda);
	if(mov_izq == 0)
	{
		movimiento[0] = movimiento[0]-1;
	}
	}
		
	}while(perdio != 1 && gano != 1);
	
	printf("Le gustaria volver a jugar?: ");
	scanf("%s", &pregunta);
	respuesta= strcmp(resp,pregunta);
}while(respuesta == 0);
}
