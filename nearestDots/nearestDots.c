
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

double euclidean_distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int compare_x(const void* a, const void* b) {
    Point* p1 = (Point*)a;
    Point* p2 = (Point*)b;
    return (p1->x > p2->x) - (p1->x < p2->x);
}

int compare_y(const void* a, const void* b) {
    Point* p1 = (Point*)a;
    Point* p2 = (Point*)b;
    return (p1->y > p2->y) - (p1->y < p2->y);
}

double closest_pair(Point points[], int left, int right) {
    if (right - left <= 3) {
        double min_dist = __DBL_MAX__;
        for (int i = left; i < right; i++) {
            for (int j = i + 1; j < right; j++) {
                double dist = euclidean_distance(points[i], points[j]);
                if (dist < min_dist) {
                    min_dist = dist;
                }
            }
        }
        return min_dist;
    }

    int mid = (left + right) / 2;
    double mid_x = points[mid].x;

    double d1 = closest_pair(points, left, mid);
    double d2 = closest_pair(points, mid, right);
    double d = fmin(d1, d2);

    Point* strip = (Point*)malloc((right - left) * sizeof(Point));
    int j = 0;
    for (int i = left; i < right; i++) {
        if (fabs(points[i].x - mid_x) < d) {
            strip[j++] = points[i];
        }
    }

    qsort(strip, j, sizeof(Point), compare_y);

    for (int i = 0; i < j; i++) {
        for (int k = i + 1; k < j && (strip[k].y - strip[i].y) < d; k++) {
            double dist = euclidean_distance(strip[i], strip[k]);
            if (dist < d) {
                d = dist;
            }
        }
    }

    free(strip);
    return d;
}

int main() {
    int n;
    printf("Введите количество точек: ");
    scanf("%d", &n);

    Point* points = (Point*)malloc(n * sizeof(Point));
    printf("Введите координаты точек (x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    qsort(points, n, sizeof(Point), compare_x);

    double min_distance = closest_pair(points, 0, n);
    printf("Минимальное расстояние между ближайшими парами точек: %lf\n", min_distance);

    free(points);
    return 0;
}
