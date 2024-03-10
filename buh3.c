#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1

char **memo;

long long int CalcularTamanioIZQ(long long int n)
{
     if (n == 0)
          return 0;
     else
          return (1LL << (n + 1)) - n - 3;
}

long long int Tiny(long long int T, long long int n)
{
     return (T - 1 - n) / 2;
}

char CalcularCentroHelper(long long int n, long long int pos, long long int Tamanioizq)
{
     long long int TamanioTinyIzq = Tiny(Tamanioizq, n);

     if (n <= 1)
     {
          if (pos == Tamanioizq + 1)
               return 'B';
          else if (pos == Tamanioizq + 2 + n)
               return 'H';
          else
               return 'U';
     }

     if (memo[n][pos] != 0)
     {
          return memo[n][pos];
     }

     char result;
     if (pos <= Tamanioizq)
     {
          result = CalcularCentroHelper(n - 1, pos, TamanioTinyIzq);
     }
     else if (pos > Tamanioizq + 2 + n)
     {
          result = CalcularCentroHelper(n - 1, pos - Tamanioizq - 2 - n, TamanioTinyIzq);
     }

     if (pos == Tamanioizq + 1)
          result = 'B';
     else if (pos == Tamanioizq + 2 + n)
          result = 'H';
     else
          result = 'U';
     memo[n][pos] = result;
     return result;
}

char CalcularCentro(long long int n, long long int pos)
{
     long long int Tamanioizq = CalcularTamanioIZQ(n);
     return CalcularCentroHelper(n, pos, Tamanioizq);
}

int casoDePrueba()
{
     long long int n, pos;
     if (scanf("%lld %lld", &n, &pos) == EOF) // Read the start of the test case
          return 0;                           // false
     else
     {
          printf("%c\n", CalcularCentro(n, pos));
          return 1; // true
     }
}

int main()
{
     int i, j;
     memo = (char **)malloc(MAX_N * sizeof(char *));
     for (i = 0; i < MAX_N; i++)
     {
          memo[i] = (char *)calloc(MAX_N, sizeof(char));
     }

     while (casoDePrueba())
          ;

     for (i = 0; i < MAX_N; i++)
     {
          free(memo[i]);
     }
     free(memo);

     return 0;
}
