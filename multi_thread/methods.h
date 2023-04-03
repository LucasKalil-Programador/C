// metodo dos triangulos
double method2(double A, double delta_x, double i, double (*f)(double))
{
  double A_rectangle = delta_x * f(A + delta_x * (i - 1));
  double A_triangle = (delta_x * (delta_x * i - delta_x * (i - 1))) / 2;
  return A_rectangle + A_triangle;
}