#include <stdio.h>
#include "code/point3d.h"

void main(void)
{
    Point3D p1 = {0,0,0};
    Point3D p2 = {80,0,0};
    Point3D p3 = {40,220,0};
    Point3D p4 = {40,0,0};
    Point3D p5;
    float a,b,c,d;

    float D1 = 40;
    float D2 = 40;
    float D3 = 220;

    plane_equation(p1,p2,p3,&a,&b,&c,&d);
    printf("Equação do plano: %fx + %fy + %fz + %f = 0\n", a, b, c, d);

    trilateration(p1,D1,p2,D2,p3,D3,&p5);
    printf("%f %f %f", p5.x,p5.y,p5.z);

    //if(is_point_in_plane(a,b,c,d,p4)){
    //    printf("O ponto P4 está no mesmo plano\n");
    //}else{
    //    printf("O ponto P4 não está no mesmo plano\n");
    //}
}
