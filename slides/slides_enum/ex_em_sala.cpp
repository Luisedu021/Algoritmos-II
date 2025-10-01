#include <stdio.h>
#include <math.h>

struct ponto2d{
    int x,y;
};

double dist_euclidiana(struct ponto2d p1,struct ponto2d p2) {
    double diff_x = p2.x - p1.x;
    double diff_y = p2.y - p1.y;

    return sqrt((diff_x)*(diff_x) + (diff_y) * (diff_y));
};

int main() {
    struct ponto2d a{2,5};
    struct ponto2d b{4,6};
    printf("%lf",dist_euclidiana(a,b));
    return 0;
}