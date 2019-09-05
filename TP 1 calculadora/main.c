#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "Tomar-Mostrar.h"



int main()
{
    int valorA;  int valorB;  int opciones=0;
    char seguir; int flagOp1=0; int flagOp2=0;  int flagOpcion3=0;


    do
    {

        mostrarMenu();
        scanf("%d",&opciones);

        switch(opciones)
        {

            case 1:

                flagOp1=1;
                valorA=pedirNumeroUno();
                mostrarNumero1(valorA);
                break;

            case 2:

                flagOp2=1;
                valorB=pedirNumeroDos();
                mostrarNumero2(valorB);
                break;

            case 3:
                if(flagOp1==1 && flagOp2==1)
                {
                    sumar(valorA,valorB);
                    restar(valorA,valorB);
                    multiplicar(valorA,valorB);
                    Dividir(valorA,valorB);
                    factorial(valorA);
                    factorial(valorB);
                }
                else
                {
                    printf("Error, Ingrese los numeros antes de hacer los calculos \n");

                }
            printf("Calculos realizados..\n");
            flagOpcion3=1;
            break;

            case 4:

                if (flagOpcion3==1)
                    {
                        mostrarNumero1(valorA);
                        mostrarNumero2(valorB);
                        mostrarResultadoSuma(sumar(valorA,valorB));
                        mostrarResultadoResta(restar(valorA,valorB));
                        mostrarResultadoMul(multiplicar(valorA,valorB));

                        if(valorB==0)
                            {
                                mostrarDivnosepuede();
                            }
                            else
                                {
                                    mostrarResultadoDiv(Dividir(valorA,valorB));
                                }


                        if (valorA>0)
                            {
                                mostrarResFac1(factorial(valorA));
                            }
                        else
                            {
                                mostrarFAcnosepuede();
                            }


                        if (valorB>0)
                            {
                                mostrarResFac2(factorial(valorB));
                            }
                        else
                            {
                                mostrarFAcnosepuede();
                            }
                    }
            break;


            case 5:

                seguir='5';
                printf("El programa termino, hasta la proxima!!\n");
                break;

            default:
                printf("No ha elegido una opcion valida");
                break;

            }
        system("pause");//El programa va esperar a que el usuario presione una tecla para continuar
        system("cls");//Limpia la pantalla al elegir opciones y que no sue vaya acumulando todo el texto mientras se va ejecutando el programa


    }while(seguir!='5');


    return 0;
}



