
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

