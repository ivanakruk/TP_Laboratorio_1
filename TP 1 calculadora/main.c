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

        mostrarMenu();//mostramos el menu de opciones para ver que elegir para realizar las operaciones
        scanf("%d",&opciones);

        switch(opciones)//usamos un switch para que cada caso sea un boton de las opciones del menu, en el cual adentro se desarrollaran sus funciones
        {

            case 1:// pedimos el num y lo guardamos con un scanf

                flagOp1=1;
                valorA=pedirNumeroUno();
                fflush(stdin);
                mostrarNumero1(valorA);
                break;

            case 2://pedimos el segundo num y lo guardamos

                flagOp2=1;
                valorB=pedirNumeroDos();
                fflush(stdin);
                mostrarNumero2(valorB);
                break;

            case 3://si se ingresaron las dos numero se a poder proceder a realizar los calculos, por eso caso1 y 2 tienen una bandera c/u
                if(flagOp1==1 && flagOp2==1)
                {
                    sumar(valorA,valorB);
                    restar(valorA,valorB);
                    multiplicar(valorA,valorB);
                    Dividir(valorA,valorB);
                    factorial(valorA);
                    factorial(valorB);

                }
                else//si no se ingresaron los dos operandos no se puede realizar el calculo
                {
                    ErroringreseNum();
                }
            CalculosREalizados();
            flagOpcion3=1;//Si se realizaron los calculos el flag op3 se pone en 1
            break;

            case 4:

                if (flagOpcion3==1)//si el flag de las op3 esta en uno se van a mostrar los resultados
                {
                        mostrarNumero1(valorA);//todos los datos se van a mostrar llamando a las funciones con su resultado
                        mostrarNumero2(valorB);
                        mostrarResultadoSuma(sumar(valorA,valorB));
                        mostrarResultadoResta(restar(valorA,valorB));
                        mostrarResultadoMul(multiplicar(valorA,valorB));


                        if(valorB==0)//si el el segundo n° es cero no se va a poder hacer la division
                            {
                                mostrarDivnosepuede();
                            }
                            else
                                {
                                    mostrarResultadoDiv(Dividir(valorA,valorB));//Si no es cero se hace la division
                                }


                        if (valorA>0)//si el valor a o el valor b son menores a cero no se va a poder factorizar
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

                }else
                {
                    realiceCalculos();//Cuando no se puedan hacer los calculos me va avisar que no se puede mostrar los resultados
                }
                fflush(stdin);
            break;


            case 5:// El 5 nos va a sacar del programa, en el cual esta en la condicion del while al final, que mientras no presione el 5 no va a salir

                seguir='5';
                FinPrograma();

                break;

            default:
                opcionNovalida();
                break;

            }
        system("pause");//El programa va esperar a que el usuario presione una tecla para continuar
        system("cls");//Limpia la pantalla al elegir opciones y que no sue vaya acumulando todo el texto mientras se va ejecutando el programa


    }while(seguir!='5');


    return 0;
}

