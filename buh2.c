#include <stdio.h>
long long int CalcularTamanioIZQ(long long int n)
{
     if (n == 0)
          return 0;
     else
     return (1LL << (n + 1)) - n - 3;
}
long long int Tiny(long long int T, long long int n){
     return (T-1-n)/2;
}
char CalcularCentroHelper(long long int n, long long int pos, long long int Tamanioizq)
{
     long long int TamanioTinyIzq = Tiny(Tamanioizq,n);
     if (n > 1)
     {
          if (pos <= Tamanioizq){
               return CalcularCentroHelper(n - 1, pos, TamanioTinyIzq );
          }

          else if (pos > Tamanioizq + 2 + n)
               return CalcularCentroHelper(n - 1, pos - Tamanioizq - 2 - n,TamanioTinyIzq);
     }
     if (pos == Tamanioizq + 1)
          return 'B';
     else if (pos == Tamanioizq + 2 + n)
          return 'H';
     else
     return 'U';
}

char CalcularCentro(long long int n, long long int pos)
{
     long long int Tamanioizq = CalcularTamanioIZQ(n);
     return CalcularCentroHelper(n, pos, Tamanioizq);
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