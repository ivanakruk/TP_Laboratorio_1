/** \brief Con los valores de A y B realiza las operaciones y devuelve un resultado
 ** \param x+y; x-y; x*y; x/y; *
 * \return Devuelve el resultado de la operacion
 *
 */

int sumar(int x, int y)
{
    int total;
    total=x+y;
    return total;
}
int restar(int x, int y)
{
    int total;
    total=x-y;
    return total;
}
int multiplicar(int x, int y)
{
    int total;
    total=x*y;
    return total;
}
float Dividir (int x, int y)
{
    float total;
    total=(float)x/y;
    return total;
}

/** \brief Factorial toma un valor de A o B y retorna el resultado despues de haber realizado la recursividad
 *
 * \param Si el numero es menor a cero no se realiza la operacion
 * \return Devuelve el resultado
 *
 */

int factorial (int z)
{
    int resultado;

    if(z<0)
    {
        resultado=0;
    }
    else{

        if(z==0)
          {
            resultado = 1;
          }
         else
          {
            resultado=z*(factorial(z-1));
          }

        }
       return resultado;



}

