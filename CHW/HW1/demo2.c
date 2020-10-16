#include <stdio.h>
#include <math.h>
    float max3(float, float, float);
    float max2(float, float);
    float min3(float, float, float);
    float min2(float, float);
int main()
{
    float a[4][2], m, n, s;
    printf("Input vertex 1: ");
    scanf("%f %f", &a[0][0], &a[0][1]);
    fflush(stdin);
    printf("Input vertex 2: ");
    scanf("%f %f", &a[1][0], &a[1][1]);
    fflush(stdin);
    printf("Input vertex 3: ");
    scanf("%f %f", &a[2][0], &a[2][1]);
    fflush(stdin);
    a[3][0] = (a[0][0] + a[1][0] + a[2][0]) / 3;
    a[3][1] = (a[0][1] + a[1][1] + a[2][1]) / 3;
    m = sqrt(pow(a[0][0] - a[3][0], 2) + pow(a[0][1] - a[3][1], 2));
    n = sqrt(pow(a[1][0] - a[3][0], 2) + pow(a[1][1] - a[3][1], 2));
    s = sqrt(pow(a[2][0] - a[3][0], 2) + pow(a[2][1] - a[3][1], 2));
    printf("The center of the triangle is: %.1f %.1f\n", a[3][0], a[3][1]);
    printf("The maximum distance between center and vertices: %.2f\n", max3(m, n, s));
    printf("The minimum distance between center and vertices: %.2f\n", min3(m, n, s));
    getchar();
    getchar();
    return 0;
}
float max3(float p, float q, float r)
{
    return max2(max2(p, q), max2(q, r));
}
float max2(float h, float k)
{
    return h > k ? h : k;
}
float min3(float p, float q, float r)
{
    return min2(min2(p, q), min2(q, r));
}
float min2(float h, float k)
{
    return h < k ? h : k;
}