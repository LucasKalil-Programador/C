#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double f(double x)
{
  return pow(x, 2);
}

// metodo dos retangulos
double method1(double A, double B, double N)
{
  double result, delta_x = (B - A) / N;

  for (int i = 1; i <= N; i++)
  {
    double A_rectangle = delta_x * f(A + delta_x * (i - 1));
    result += A_rectangle;
  }
  return result;
}

// metodo dos triangulos
double method2(double A, double B, double N)
{
  double result, delta_x = (B - A) / N;

  for (int i = 1; i <= N; i++)
  {
    double A_rectangle = delta_x * f(A + delta_x * (i - 1));
    double A_triangle = (delta_x * (delta_x * i - delta_x * (i - 1))) / 2;
    result += A_rectangle + A_triangle;
  }
  return result;
}

// metodo dos semicirculos
double method3(double A, double B, double N)
{
  double result, delta_x = (B - A) / N;

  for (int i = 1; i <= N; i++)
  {
    double A_rectangle = delta_x * f(A + delta_x * (i - 1));
    double A_circle = (M_PI * pow(delta_x, 2)) / 2;
    result += A_rectangle + A_circle;
  }
  return result;
}

// metodo dos trapezios
double method4(double A, double B, double N)
{
  double result, delta_x = (B - A) / N;

  for (int i = 1; i <= N; i++)
  {
    double A_rectangle = delta_x * f(A + delta_x * (i - 1));
    double A_trapeze = ((delta_x + delta_x / 2) * (f(A + delta_x * i) - f(A + delta_x * (i - 1)))) / 2;
    result += A_rectangle + A_trapeze;
  }
  return result;
}

// metodo das elipses
double method5(double A, double B, double N)
{
  double result, delta_x = (B - A) / N;

  for (int i = 1; i <= N; i++)
  {
    double A_rectangle = delta_x * f(A + delta_x * (i - 1));
    double A_ellipse = M_PI * (delta_x / 2) * (f(A + delta_x * (i - 1) + (delta_x / 2)) - f(A + delta_x * (i - 1)));
    result += A_rectangle + A_ellipse;
  }
  return result;
}

int main()
{
  double A = 2, B = 3, N = 1000000000, result = 0;

  time_t start = time(NULL);

  result = method5(A, B, N);

  int elapsed_time = (int)(time(NULL) - start);
  printf("\r\nResultado: %.16f | Demorou: %d seconds", result, elapsed_time);
  return 0;
}

// testes A = 2, B = 3, N = 5
// Valor correto   6.3333333333333333...3
// M1 = Resultado: 5.8399999999999999 | Demorou: 0 seconds Valor mais longe
// M2 = Resultado: 5.9400000000000004 | Demorou: 0 seconds
// M3 = Resultado: 6.1541592653589801 | Demorou: 0 seconds Valor mais proximo
// M4 = Resultado: 6.5899999999999999 | Demorou: 0 seconds
// M5 = Resultado: 6.6096902001294993 | Demorou: 0 seconds

// testes A = 2, B = 3, N = 1_000_000_000
// Valor correto   6.3333333333333333...3
// M1 = Resultado: 6.3333333308305493 | Demorou: 70 seconds  
// M2 = Resultado: 6.3333333313307039 | Demorou: 72 seconds
// M3 = Resultado: 6.3333333324024572 | Demorou: 112 seconds Valor mais proximo
// M4 = Resultado: 6.3333333345807503 | Demorou: 211 seconds Mais demorado 
// M5 = Resultado: 6.3333333347580094 | Demorou: 205 seconds Valor mais longe

// Conclusão 
// todos os métodos convergiram para o mesmo resultado provando que a implementação de todos esta correta
// o método que se mostrou mais eficiente foi o dos semicírculos para esse caso