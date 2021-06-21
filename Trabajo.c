#include <stdio.h>
#include <stdlib.h>
#include <math.h>
char  Calculos[100];
int opcion, posicion, cuenta;
float numero1,numero2, calculo , Resultados[100];

float Suma(float a, float b)
{
	calculo=a+b;
	return calculo;
}

float Resta(float a, float b)
{
	calculo=a-b;
	return calculo;
	
}
float multiplicacion(float a, float b)
{
	calculo=a*b;
	return calculo;
}


float Division(float a,float b)
{
	calculo=a/b;
	return calculo;	
}

float potencia(float a, float b)
{
	calculo=pow(a,b);
	return calculo;
}

float Raiz(float a)
{
	calculo= sqrt(a);
	return calculo;
}



void ImprimirResultados()
{
	printf("\n Resultado: %.1f \n",calculo);
}

void GuardarDatos(float resul, int posicion, int opercion)
{
	Resultados[posicion]=resul;	
	Calculos[posicion]=opercion;	
	
}


void ImprimirCalculosHistoricos(int posiciones)
{
	int i;

	for (i; i<posiciones; i++)
	{
		switch(Calculos[i])
		{
			case 1:
				printf("Los resultados Historicos son: %.1f Suma\n",Resultados[i]);
			break;
			
			case 2:
				printf("Los resultados Historicos son: %.1f Resta \n",Resultados[i]);
			break;
			case 3:
				printf("Los resultados Historicos son: %.1f multiplicacion \n",Resultados[i]);
			break;
			case 4: 
				printf("Los resultados Historicos son: %.1f Division \n",Resultados[i]);
			break;
			
			case 5:
				printf("Los resultados Historicos son: %.1f potencia \n",Resultados[i]);
				break;
			case 6:
				printf("Los resultados Historicos son: %.1f Raiz \n",Resultados[i]);
			break;
					
    		
				
		}
		
	}
}


void IngresoDatos(int opc,int posicion, int cuenta)
{
	int i, aprobado, resp;
	float Anterior;
	
	for(i=0; i<posicion; i++)
	{
		Anterior=Resultados[i];		
	}
	if(cuenta>0)
	{
		printf("Tiene un valor guardado para reusar, desea usarlo? \n 1.Si 2.No \n");
		scanf("%d", &resp);
		if(resp==1)
		{
			numero1=Anterior;
			aprobado=aprobado+1;
		}
		else
		{
			if(resp==2)
			{
				printf("Continuamos.. \n");
			}else
			{
				
				printf("Ingresaste incorrecto, continuamos.. \n");
			}
		}
				
	}
	if(aprobado>0)
	{		
		if(opc==4)
		{			
			printf("Ingresar numero 2 \n");
			scanf("%f", &numero2);
			while(numero2==0)
			{
				printf("No se puede dividir por 0 vuelva a intentarlo \n");
				scanf("%f", &numero2);
			}
		}
		else
		{
			if(opc!=6)
			{				
				printf("Ingresar numero 2 \n");
				scanf("%f", &numero2);
			}
		
			
		}
	} 
	else
	{	
		if (opc==4)
		{
			printf("Ingresar numero 1 \n");
			scanf("%f", &numero1);
			printf("Ingresar numero 2 \n");
			scanf("%f", &numero2);
			while(numero2==0)
			{	
				printf("No se puede dividir por 0 vuelva a intentarlo \n");
				scanf("%f", &numero2);				
			}
		}
		else
		{
			
			printf("Ingresar numero 1 \n");
			scanf("%f", &numero1);
			if (opc!=6)
			{
				printf("Ingresar numero 2 \n");
				scanf("%f", &numero2);				
			}
		}
	}
}


void bienvenido()
{
	    printf("\n   MENU CALCULADORA" );
        printf("\n   1. Sumar dos numeros." );
        printf("\n   2. Restar dos numeros." );
        printf("\n   3. Multiplicar dos numeros." );
        printf("\n   4. Dividir dos numeros." );
        printf("\n   5. Potencia");
        printf("\n   6. Raiz de un numero." );
        printf("\n   7. Salir.\n" );      			
}



int main() {
   do{
   	
    bienvenido(); 
	scanf("%d",&opcion);
    
   	
	switch(opcion)
    {
    	case 1:
    		
    		IngresoDatos(opcion,posicion, cuenta);
    		cuenta=cuenta+1;
    		GuardarDatos(Suma(numero1,numero2), posicion, opcion);
    		
    		ImprimirResultados();
    		posicion=posicion+1;
    	break;
    	case 2:
    		IngresoDatos(opcion,posicion, cuenta);
    		cuenta=cuenta+1;
    		
    		GuardarDatos(Resta(numero1,numero2),posicion, opcion);
    		ImprimirResultados();
    		posicion=posicion+1;
    	break;
    	case 3:
    		IngresoDatos(opcion,posicion, cuenta);
    		cuenta=cuenta+1;
    		
    		GuardarDatos(multiplicacion(numero1,numero2),posicion, opcion);
    		ImprimirResultados();
    		posicion=posicion+1;
    		break;
    	case 4:
    		IngresoDatos(opcion,posicion, cuenta);
    		cuenta=cuenta+1;    		
    		GuardarDatos(Division(numero1,numero2),posicion, opcion);
    		ImprimirResultados();
    		posicion=posicion+1;
    		break;
    		
    	case 5:
    			IngresoDatos(opcion,posicion, cuenta);
    		    cuenta=cuenta+1;
    		
    		    GuardarDatos(potencia(numero1,numero2),posicion, opcion);
    		    ImprimirResultados();
    		    posicion=posicion+1;
    		    break;
    	case 6:
    			IngresoDatos(opcion,posicion, cuenta);
    		    cuenta=cuenta+1;
    		
    		    GuardarDatos(Raiz(numero1),posicion, opcion);
    		    ImprimirResultados();
    		    posicion=posicion+1;
    		    break;  	
    	
    	case 7:
    		ImprimirCalculosHistoricos(posicion);
    	break;    	
    		
    	
    	default:
    		printf("Ingreso numero incorrecto vuelva a intentar");
    		break;
		    		
	}
   }
   while(opcion!=7);
    
    
	
	    
	return 0;
}

