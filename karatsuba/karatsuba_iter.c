#include <stdio.h>
#include <math.h>

long long karatsuba_iterative(long long x, long long y) {
    if (x < 10 || y < 10) {
        return x * y;
    }

    int n = fmax(log10(x) + 1, log10(y) + 1);
    int m = n / 2;

    long long pow10m = pow(10, m);
    long long x1 = x / pow10m;
    long long x0 = x % pow10m;
    long long y1 = y / pow10m;
    long long y0 = y % pow10m;

    long long z0 = x0 * y0; // z0
    long long z1 = x1 * y1; // z1
    long long z2 = (x1 + x0) * (y1 + y0) - z1 - z0; // z2

    return z1 * pow(10, 2 * m) + z2 * pow10m + z0;
}

int main() {
    long long x, y;
    printf("Введите два числа для умножения: ");
    scanf("%lld %lld", &x, &y);

    long long result = karatsuba_iterative(x, y);
    printf("Результат умножения: %lld\n", result);

    return 0;
}
