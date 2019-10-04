#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "ArrayEmployees.h"
#include "utn_.h"

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param limite int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(eEmployee* list, int limite)// INICIALIZAR EMPLEADOS
{
    int retorno= -1;
    int i;
    if(list!= NULL &&limite>0)// VALIDAR QUE NO SEA NULO Y QUE SEA MAYOR A CERO EL TAMAÑO DEL ARRAY
    {
        for(i=0;i<limite;i++)
        {
            list[i].isEmpty= 1;// SI ENTRA, CARGO EL ARRAY CON 1 Y RETORNO CERO
        }
        retorno=0;
    }
    return retorno;
}
//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param limite int
* \param contadorID int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*
*/

int addEmployee(eEmployee* list, int limite, int* contadorID)// CARGAR DATOS DE LOS EMPLEADOS
{
    int retorno= -1;
    int posicion;


    if(list!=NULL && limite>0 && contadorID!=NULL)
    {
        if(findEmptyEmployee(list,limite,&posicion)==-1)//PRIMERO BUSCAR QUE ESTE VACIO EL LUGAR PARA CARGAR LOS DATOS
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {

            (*contadorID)++;
            list[posicion].id=*contadorID;
            list[posicion].isEmpty = 0;
            utn_getName("\nIngrese nombre de empleado: ","\nError",1,20,3,list[posicion].name);
            utn_getName("\nIngrese apellido de empleado: ","\nError",1,20,3,list[posicion].lastName);
            utn_getFloat("\nIngrese sueldo del empleado: ","\nError",1,10,1,10,3,&list[posicion].salary);
            utn_getUnsignedInt("\nIngrese sector del empleado: \n1)RRHH\n2)contabilidad\n3)Administracion\n ","\Error opcion invalida",1,sizeof(int),1,3,2,&list[posicion].sector);


            system("cls");
            printf("\n ID: %d\n Nombre: %s\n Apellido: %s\n Sueldo: %.2f\n Sector: %d",list[posicion].id,list[posicion].name,list[posicion].lastName,list[posicion].salary,list[posicion].sector);


            retorno= 0;
        }
    }

    return retorno;
}
//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

/** \brief Finds first empty index in array
* \param list employee*
* \param int limite
* \param position int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*
*/
int findEmptyEmployee(eEmployee* list, int limite, int *position)// BUSCA EL LUGAR VACIO
{
    int retorno=-1;
    int i;
    if(list!= NULL && limite>=0 && position!=NULL)// CONDICION PARA QUE EL ARRAY SEA VALIDO
    {
        for(i=0;i<limite;i++)
        {
            if(list[i].isEmpty==1)
            {
                retorno = 0;
                *position = i;// ME DEVUELVE LA POSICION CON EL PUNTERO
                break;
            }
        }
    }
    return retorno;
}
//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
int employe_modificar(eEmployee array[], int limite)                                //cambiar array
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && limite>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,limite,1,&id);         //cambiar si no se busca por ID
        if(findEmployeeById(array,limite,id,&posicion)==-1)// SI EL RETORNO ES -1 NO EXISTE       //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                //printf("\n Posicion: %d\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s",
                //       posicion, array[posicion].idEstudiante,array[posicion].varInt,array[posicion].varFloat,array[posicion].varString,array[posicion].varLongString);

                utn_getChar("\nModificar: \nA-Nombre \nB-Apellido \nS(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getName("\nIngrese el nuevo nombre: ","\nError",1,TEXT_SIZE,1,array[posicion].name);
                        break;
                   case 'B':
                        utn_getLastName("\nIngrese apellido: ","\nError, ingrese nuevamente",1,TEXT_SIZE,2,array[posicion].lastName);           //mensaje + cambiar campo varInt

                    case 'S':
                         system("cls");
                        system("pause");
                        break;
                    default:
                        printf("\nOpcion no valida\n");

                }


            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}
//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param limite int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(eEmployee* list, int limite,int id, int *position)
{
    int retorno=-1;
    int i;
    if(list!= NULL && limite>=0)
    {
        for(i=0;i<limite;i++)
        {
            if(list[i].isEmpty==1)
                continue;
            else if(list[i].id==id) //SI EL ID QUE BUSCO ES IGUAL RETORNO CERO Y DEVUELVO LA POSICION           //cambiar campo ID
            {
                retorno=0;
                *position = i;
                break;
            }
        }
    }
    return retorno;
}
//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param limite int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(eEmployee* list, int limite)
{
    int retorno= -1;
    int posicion;
    int id;
    if(list!=NULL && limite>0)
    {
        printEmployees(list, limite);//MUESTRO LA LISTA PARA VER CUAL ELEGIR
        utn_getUnsignedInt("\nID del empleado que se quiere dar de baja : ","\nError",1,sizeof(int),1,limite,1,&id);          //cambiar si no se busca por ID
        if(findEmployeeById(list,limite,id,&posicion)== -1)//BUSCO EL ID                             //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            list[posicion].isEmpty=1;
            list[posicion].id=0;                                                                   //cambiar campo id
            strcpy(list[posicion].name,"");                                                   //cambiar campo varString
            strcpy(list[posicion].lastName,"");                                               //cambiar campo varLongString
            list[posicion].sector=0;                                                               //cambiar campo varInt
            list[posicion].salary=0;                                                             //cambiar campo varFloat
            retorno=0;

            printf("Empleado eliminado exitosamente.\n");
        }
    }
    system("cls");
    system("pause");
    return retorno;
}
//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

/** \brief Sort the elements in the array of employees
*
* \param list Employee*
* \param limite int
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(eEmployee* list, int limite)
{
    int retorno= -1;
    int i;
    int j;
    int elegir;
    eEmployee auxList;
    eEmployee auxSector;


 do{    //MUESTRO OPCIONES
        utn_getUnsignedInt("\n\n SELECCIONE OPCION A REALIZAR: \n\n1) Ordenar empleados de la A a la Z y sector de menor a mayor \n2)Ordenar empleados de la A a la Z y sector de menor a mayor \n3)Salir ","Error, opcion invalida",1,sizeof(int),1,3,2,&elegir);


        switch(elegir)
        {
            case 1: //ORDENADO DE LA A - Z Y DE SECTOR 1 - 3

                for(i=0; i < limite - 1; i++)
             {
                    if(list[i].isEmpty == -1)
                    {
                        continue;
                    }
                for(j=i+1; j < limite; j++)
                {
                    if(list[j].isEmpty == -1)
                    {
                            continue;
                    }
                    if(strcmp(list[i].lastName,list[j].lastName) >0)// DE MENOR a MAYOR, CAMBIAR SIGNO PARA FORMA DESCENDENTE
                    {
                        auxList= list[j];
                        list[j] = list[i];
                        list[i] = auxList;
                    }
                 printf("\n Ordenados por apellido de la A a Z");
                 printEmployees(list,limite);
                }

                   for(j=i+1; j < limite; j++)
                {
                    if(list[j].isEmpty == -1)
                    {
                            continue;
                    }
                    if(list[i].sector>list[j].sector)// DE MENOR a MAYOR, (ES AL REVEZ QUE CON LOS NOMBRES)
                    {
                        auxSector= list[j];
                        list[j] = list[i];
                        list[i] = auxSector;
                    }
                 printf("\n Ordenados por sector de menor a mayor");
                 printEmployees(list,limite);
                }
            }
            break;

            case 2:    //ORDENADO DE LA Z - A Y DE SECTOR 3 - 1


                for(i=0; i < limite - 1; i++)
             {
                    if(list[i].isEmpty == -1)
                    {
                        continue;
                    }
                for(j=i+1; j < limite; j++)
                {
                    if(list[j].isEmpty == -1)
                    {
                            continue;
                    }
                    if(strcmp(list[i].lastName,list[j].lastName) <0)// DE MAYOR A MENOR, CAMBIAR SIGNO PARA FORMA DESCENDENTE
                    {
                        auxList= list[j];
                        list[j] = list[i];
                        list[i] = auxList;
                    }
                 printf("\n Ordenados por apellido de la Z a A");
                 printEmployees(list,limite);
                }

                   for(j=i+1; j < limite; j++)
                {
                    if(list[j].isEmpty == -1)
                    {
                            continue;
                    }
                    if(list[i].sector<list[j].sector)// DE  MAYOR A MENOR, (ES AL REVEZ QUE CON LOS NOMBRES)
                    {
                        auxSector= list[j];
                        list[j] = list[i];
                        list[i] = auxSector;
                    }
                 printf("\n Ordenados por sector de mayor a menor");
                 printEmployees(list,limite);
                }
            }
            break;

            default:
                    printf("\nHa salido del ordenamiento\n");

       }
   }while(elegir!=3);
    return retorno;
}

/** \brief print the content of employees array
*
* \param list Employee*
* \param limite int
* \return int
*
*/
int printEmployees(eEmployee* list, int limite)
{
    int retorno=-1;
    int i;
    if(list!=NULL && limite>=0)
    {
        for(i=0;i<limite;i++)
        {
            if(list[i].isEmpty == 1)// SI SE ENCUENTRA VACIO..
                continue;
            else if(list[i].isEmpty == 0)
            {
                printf("\n ID: %d\n Nombre: %s\n Apellido: %s\n Sueldo: %.2f\n Sector: %d\n",
                   list[i].id,list[i].name,list[i].lastName,list[i].salary, list[i].sector);
            }
        }
        retorno=0;
    }
    return retorno;
}

/** \brief print the total and average salary of employees
*
* \param list Employee*
* \param  limite int
* \return int
*
*/

int promediosEmployees(eEmployee* list, int limite)
{
    float promedioSalario;//EL RESULTADO
    float salarioTotal = 0;// PARA SUMAR TODOS LOS SALARIOS
    int contador = 0;// PARA PODER HACER LA DIVISION
    int superoElPromedio = 0;//
    int i;
    int retorno = -1;

    if(list != NULL && limite >= 0)
    {
        for(i = 0; i < limite; i++)
        {
            if(list[i].isEmpty == 0)
            {
                contador++;
                salarioTotal = salarioTotal + list[i].salary;
            }

        }

        promedioSalario = salarioTotal / (float)contador;
        for(i = 0; i < limite; i++)
        {
            if(list[i].isEmpty == 0 && list[i].salary > promedioSalario)//SI ALGUN SALARIO ES MAYOR AL PROMEDIO, ENTONCES LO SUPERO
            {
                superoElPromedio++;
            }
        }
        printf("\nTotal de salarios : %.2f\nPromedio de salarios : %.2f\n", salarioTotal, promedioSalario);
        printf("\nCantidad de empleados que superan el salario promedio : %d ", superoElPromedio);
        retorno = 0;
    }

    return retorno;
}

/** \brief allows you to choose which report you want to see
*
* \param list eEmployee*
* \param limite int
* \return int
*
*/

int informarEmploye(eEmployee list[], int limite)
{
    int opcion;
    int retorno = -1;
    if(list!=NULL && limite>=0)
    {

      do{

            utn_getUnsignedInt("Seleccione opcion: \n1 - Listar empleados \n2 - Promedios salarios \n3 -Salir  \n","\nError", 1, sizeof(int), 1, 3, 3, &opcion);


        switch(opcion)
        {
            case 1:
                if(sortEmployees(list, limite)==0)
                {
                    retorno= 0;
                }

                break;
            case 2:
                if(promediosEmployees(list, limite)==0)
                {
                    retorno = 0;
                }

                break;
            case 3:
                printf("\nHa salido de Informar\n");
                break;
            default:
                printf("\nOpcion no valida");
        }
      }while(opcion!=3);
    }
    return retorno;
}

