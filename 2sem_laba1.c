#include <stdio.h>
#include <math.h>

void nomerone(int year){
    int a, b, c, d, e, f;
    a = year % 19;
    b = year % 4;
    c = year % 7;
    d = (19 * a + 15) % 30;
    e = (2 * b + 4 * c + 6 * d + 6) % 7;
    f = d + e;
    
    if (f <= 26) {
        printf("Дата Пасхи в %d году: %d апреля\n", year, 4 + f);
    } else {
        printf("Дата Пасхи в %d году: %d мая\n", year, f - 26);
    }
}

float nomertwo(float x, int n){
    float y = 1.0;

    if (n >= 0) {
        for (int i = 0; i < n; i++) {
            y *= x;
        }
    } else {
        for (int i = 0; i > n; i--) {
            y /= x;
        }
    }

    return y;
}

double nomerthree(double zxc) {
    double result = 1.0;
    double term = 1.0;
    int n = 1;
    double eps = 0.0001;

    while (fabs(term) > eps) {
        term *= -zxc * zxc / (2 * n * (2 * n - 1));
        result += term;
        n++;
    }

    return result;
}


int main() {
    int year;
    printf("Введите год: ");
    scanf("%d", &year);

    nomerone(year);

    float x;
    int n;

    printf("Введите вещественное число x: ");
    scanf("%f", &x);

    printf("Введите целую степень n: ");
    scanf("%d", &n);

    float y = nomertwo(x, n);

    printf("%lf в степени %d равно %lf\n", x, n, y);

    double zxc;
    printf("Введите угол в радианах: ");
    scanf("%lf", &zxc);

    double mcos = nomerthree(zxc);
    double standcos = cos(zxc);

    printf("Значение myCos(%lf): %lf\n", zxc, mcos);
    printf("Значение cos(%lf): %lf\n", zxc, standcos);

    
    double epsilon = 0.000001; // Задал погрешность

    double difference = fabs(mcos - standcos);

    printf("Разница между значениями: %lf\n", difference);


    return 0;
}
