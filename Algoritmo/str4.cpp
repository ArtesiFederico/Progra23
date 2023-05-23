#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int i, j, tablero, turno=1, tesoro[2], movimientos, gano=0, perdio=0, mov_ar=1, mov_der=1, mov_izq=1, mov_ab=1, movimiento[3], start[2], repe=0, respuesta;
char input[1], izquierda[]="a", derecha[]="d", abajo[]="s", arriba[]="w", resp[]="si", pregunta[2];
main()
{	
	srand(time(NULL));
do{
	turno =0;
	system("CLS"); 
	do
	{
	printf("Ingrese un numero mayor a 4 y menor a 20 para determinar los espacios del tablero: ");
	scanf("%d", &tablero);		
	}while(tablero<5||tablero>20);

	
	printf("Ingrese la cantidad de movimientos que dessea tener para encontrar el tesoro: ");
	scanf("%d", &movimientos);
	

	
	do
	{
	tesoro[1] =2+rand()%(tablero-2);
	tesoro[2] =2+rand()%(tablero-2);
	}while(tesoro[1] == 2 && tesoro[2] == 2);
	do
	{
	start[1] =2+rand()%(tablero-2);
	start[2] =2+rand()%(tablero-2);		
	}while(start[1] == tablero - 1 && start[2] == 2 || start[1] == 2 && start[2] == tablero - 1 || start[1] == tesoro[1] && start[2] == tesoro[2]);

	movimiento[1] = start[1];
	movimiento[2] = start[2];	
	do
	{
	
	for(i=1;i<=tablero;i++)
	{
		for(j=1;j<=tablero;j++)
		{
			if(movimiento[2] == j && movimiento[1] == i)
			{
				printf("%c ", 254);
			}
			else if(i == tablero - 1 && j == 2 || i == 2 && j == tablero - 1)
			{
				printf("%c ", 005);
			}
			else if(i==1 || i == tablero || j == 1 || j == tablero)
			{
				printf("A ");
			}
			else
			{
			printf("%c ", 250);			
			}
		}
		printf("\n");
	}
	
	printf("%d", tesoro[1]);
	printf("%d\n", tesoro[2]);
	
	if(movimiento[2] == 1 || movimiento[2] == tablero || movimiento[1] == 1 || movimiento[1] == tablero)
	{
		perdio = 1;
	}
	else if(tesoro[1] == movimiento[1] && tesoro[2] == movimiento[2])
	{
		gano = 1;
	}
	else
	{	
		turno = turno + 1;
		if(movimiento[2] == 2 && movimiento[1] == tablero - 1 && repe!=1)
		{
			movimiento[2] = tablero - 1;
			movimiento[1] = 2;
			repe = 1;
		}
		else if(movimiento[1] == 2 && movimiento[2] == tablero - 1 && repe!=1)
		{
			movimiento[1] = tablero - 1;
			movimiento[2] = 2;
			repe = 1;	
		}
	
		printf("Ingrese la direccion en la que le gustaria moverse: ");
		scanf("%s", input);
		
		mov_ar = strcmp(input,arriba);
		if(mov_ar == 0)
		{
			movimiento[1] = movimiento[1] - 1;
		}
		
		mov_ab = strcmp(input,abajo);
		if(mov_ab==0)
		{
			movimiento[1] = movimiento[1] + 1;
		}
		
		mov_izq = strcmp(input,izquierda);
		if(mov_izq==0)
		{
			movimiento[2] = movimiento[2] - 1;		
		}
		
		mov_der = strcmp(input,derecha);
		if(mov_der==0)
		{
			movimiento[2] = movimiento[2] + 1;
		}		
		repe=0;
		

						
	}

	}while(movimientos != turno && gano != 1 && perdio!= 1);
	if(turno == movimientos)
	{
		printf("-\n-\n-\n-\n-\n-\n-\n-\n");
		printf("Se ha quedado sin movimientos :(\n");
		printf("Le gustaria jugar de vuelta?: ");
		scanf("%s", &pregunta);
		respuesta= strcmp(resp,pregunta);		
	}
	if(perdio == 1)
	{
		printf("-\n-\n-\n-\n-\n-\n-\n-\n");
		printf("Usted cayo en el agua y se ahogo.\n");
		printf("Le gustaria jugar de vuelta?: ");
		scanf("%s", &pregunta);
		respuesta= strcmp(resp,pregunta);
	}
	if(gano == 1)
	{
		printf("-\n-\n-\n-\n-\n-\n-\n-\n");
		printf("Usted encontro el tesoro y gano!!!.\n");
		printf("Le gustaria jugar de vuelta?: ");
		scanf("%s", &pregunta);
		respuesta= strcmp(resp,pregunta);
	}
}while(respuesta == 0);
}




