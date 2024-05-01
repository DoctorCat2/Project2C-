#include <iostream>
#include <Windows.h>
#include <cmath>
using namespace std;
double F1(double x) {
    return  pow(sin(x), 2) +2;
}
double F2(double x) {
    return exp(x * x);
}
double Integral(double(*f)(double), double a, double b, double e) {
    double s = (f(a) + f(b)) / 2.0;
    double k = a;
    int n = (int)((b - a) / e);
    for (int i = 0; i < n; i++) {
        k += e;
        s += f(k);
    }
    return s*e;
}
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double EPS1 = 0.0001;
    cout << "Введите погрешность e(1>e>0): ";
    cin >> EPS1;
    if (EPS1 >= 1 || EPS1 <= 0)
    {
        cout << "Погрешность введена неверно!" << endl;
        system("pause");
        return 0;
    }
    cout << endl;
    double xn = -2;
    double xk = 2;
    
    double x = xn;
    double x1 = 0;
    double x2 = 0;
    double dx = EPS1 / 10;
    double k = 0;
    while (x <= xk + dx)
    {
        if (abs(F1(x) - F2(x)) < EPS1 && k == 0)
        {
            k = 1;
            x1 = x;
        }
        else
            if (abs(F1(x) - F2(x)) < EPS1 && k == 1)
            {
                x2 = x;
            }
    x+= dx;
    }
    double p1 = Integral(F1, x1, x2, EPS1);
    double p2 = Integral(F2, x1, x2, EPS1);
    double p = abs(p1 - p2);
    cout << "Точки пресечения кривых:" << endl;
    cout <<"x1= "<<x1<<"    y1= "<< F1(x1) << endl;
    cout << "x2= " << x2 << "    y2= " << F1(x2) << endl;
    cout << "Площадь замкнутой области= "<< p<< endl;
    cout << "Точность= " << abs(F1(x1) - F2(x2)) << endl;
    system("pause");
    return 0;
}