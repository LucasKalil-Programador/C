#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "methods.h"

// configura o method_runner
struct Settings
{
  double A;
  double B;
  double N;
  double (*f)(double);
};

// execulta o methodo escolhido
double method_runner(double (*method)(double, double, double, double (*)(double)), char *method_name, struct Settings sets)
{
  time_t start = time(NULL);

  double result = method(sets.A, sets.B, sets.N, sets.f);

  int elapsed_time = (int)(time(NULL) - start);
  printf("\r\n%s = Resultado: %.16f | Demorou: %d seconds", method_name, result, elapsed_time);
  return result;
}

int main()
{
  double f(double x) { return pow(x, 2); };

  struct Settings sets = {2, 3, pow(10, 9), f};

  method_runner(method1, "M1", sets);
  method_runner(method2, "M2", sets);
  method_runner(method3, "M3", sets);
  method_runner(method4, "M4", sets);
  method_runner(method5, "M5", sets);
  return 0;
}