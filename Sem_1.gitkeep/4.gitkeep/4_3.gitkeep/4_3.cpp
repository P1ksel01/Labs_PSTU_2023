#include <iostream>
#include <cmath>
/*
    f'(x) = 1-cos(1/x)/x^2
    -1/r < λ < 0, если f'(x) > 0
    r= (0,46;0,78)= 0,78
    -1,28 < l < 0
    l = -1
 */
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    float x, xPrev;
    double lambda = -1;
    x = 2;
    xPrev = 0;
    double eps = 0.000001;

    while (abs(x - xPrev) > eps){
        xPrev = x;
        x = lambda * (xPrev - 2 + sin(1 / xPrev)) + xPrev;
    }
    cout << "Корень по методу итераций: " << x << endl;
    return 0;
}