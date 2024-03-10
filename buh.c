#include <stdio.h>
#include <math.h>
long long int CalcularTamanioIZQ(long long int n)
{
     if (n == 0)
          return 0;

     return (1LL << (n + 2)) - n - 4;
}
char CalcularCentro(long long int n, long long int pos)
{
     long long int Tamanioizq = CalcularTamanioIZQ(n - 1);
     if (pos <= Tamanioizq)
          return CalcularCentro(n - 1, pos);

     if (pos > Tamanioizq + 2 + n)
          return CalcularCentro(n - 1, pos - Tamanioizq - 2 - n);

     if (pos == Tamanioizq + 1)
          return 'B';
     else if (pos == Tamanioizq + 2 + n)
          return 'H';
     return 'U';
}
int casoDePrueba()
{
     long long int n, pos;
     if (scanf("%lld %lld", &n, &pos) == EOF) // Leer el inicio del caso de prueba
          return 0;                           // false
     else
     {
          printf("%c\n", CalcularCentro(n, pos));

          return 1; // true
     }

} // casoDePrueba

int main()
{

     while (casoDePrueba())
          ;

     return 0;

} // main
