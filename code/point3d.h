#include <stdbool.h>
#ifndef POINT3D_H
#define POINT3D_H

typedef struct {
    float x;
    float y;
    float z;
} Point3D;

float euclidean_distance(Point3D p1, Point3D p2);
float area_triangle(Point3D p1, Point3D p2, Point3D p3);
bool is_collinear(Point3D p1, Point3D p2, Point3D p3);
void plane_equation(Point3D p1, Point3D p2, Point3D p3, float* a, float* b, float* c, float* d);
bool is_point_in_plane(float a, float b, float c, float d, Point3D p4);

#endif
