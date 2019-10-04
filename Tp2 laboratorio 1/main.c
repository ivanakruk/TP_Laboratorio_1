#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "ArrayEmployees.h"
#include "utn_.h"



int main()
{
    int opcion;
    int contadorIDemployee=0;
    int flag= -1;
    eEmployee  arrayEmployee[arrayTam];


    //INICIALIZAR EMPLEADOS
    initEmployees(arrayEmployee,arrayTam);

    do{

        //MUESTRO OPCIONES
        utn_getUnsignedInt("\n\n SELECCIONE OPCION A REALIZAR: \n\n1) Alta \n2) Modificar \n3) Baja \n4) Informar \n5) Salir\n","Error, primero cargue datos",1,sizeof(int),1,4,2,&opcion);

        switch(opcion)
        {
            //ALTA
            case 1:
                if(!addEmployee(arrayEmployee,arrayTam,&contadorIDemployee))// SI HAY ESPACIO ENTRA EN LA CONDICION
                    {
                        printf("\n Datos del empleado ingresados\n");
                        flag=0;
                        system("\npause");
                        system("cls");
                    }
                break;
            //MODIFICAR EMPLEADO NOMBRE O APELLIDO
            case 2:
                if(flag==0)
                {
                    employe_modificar(arrayEmployee,arrayTam);
                }
                else
                {
                    printf("\nNo se ha ingresado algun empleado");
                }
            break;
            //DAR DE BAJA UN EMPLEADO
            case 3:
                if(flag==0)
                {
                    removeEmployee(arrayEmployee,arrayTam);
                }
                 else
                {
                    printf("\nNo se ha ingresado algun empleado");
                }
            case 4:
                if(flag==0)
                {
                   informarEmploye(arrayEmployee,arrayTam);
                }
                else
                {
                    printf("\nNo se ha ingresado algun empleado");
                }

            break;
            case 5:
                printf("\nHa salido del programa..");
            break;

             default:
                printf("\nNo ingreso una opcion correcta");

        }
    }while(opcion!=5);
    return 0;
}
