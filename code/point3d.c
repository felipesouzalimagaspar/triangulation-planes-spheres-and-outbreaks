#include "point3d.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
//Cálculo da distância euclidiana
//d² = (x2-x1)² + (y2-y1)² + (z2-z1)²
float euclidean_distance(Point3D p1, Point3D p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
}
//Cálculo baseado na Fórmula de Heron
//Primeiro é feito o cálculo das distâncias euclidianas
//Após é definido o semi-perimetro como a metade do perimetro
//Por fim utiliza-se a fórumula de Heron
// area = sqrt(s * (s - a) * (s - b) * (s - c))
float area_triangle(Point3D p1, Point3D p2, Point3D p3) {
    float a = euclidean_distance(p1,p2);
    float b = euclidean_distance(p2,p3);
    float c = euclidean_distance(p1,p3);
    float s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
//Os pontos são colineares quando a área do triângulo formado por estes é igual a 0
bool is_collinear(Point3D p1, Point3D p2, Point3D p3) {
    float area = area_triangle(p1, p2, p3);
    return area == 0;
}
// A definição dem um plano com base em 3 pontos segue a fórmula
// ax + by + cz + d = 0
// Uma premissa para este cálculo é que os 3 pontos não sejam colineares
// Primeiramente é necessário calcular o vetor normal (perpendicular) ao plano
// Para isso calcula-se o produto vetorial de dois vetores quaisquer que pertençam ao plano e passem pelos 3 pontos
// É feito um processo de normalização para garantir que o vetor normal tenha comprimento = 1
// Nesse processo é calculado a norma do vetor, elevando ao quadrado cada componente e cálculando a raiz quadrada da soma dos quadrados dos componentes
// Após, dividimos o vetor pela sua norma 
// Por fim, utiliza-se um dos pontos para encontrar a constante de deslocamento d e são definidas as constantes a,b,c e d para o plano p1,p2,p3
void plane_equation(Point3D p1, Point3D p2, Point3D p3, float* a, float* b, float* c, float* d) {
    if (is_collinear(p1, p2, p3)) {
        printf("Os pontos fornecidos sao colineares e nao formam um plano.\n");
        return;
    }
    float v1[3] = { p2.x - p1.x, p2.y - p1.y, p2.z - p1.z };
    float v2[3] = { p3.x - p1.x, p3.y - p1.y, p3.z - p1.z };
    
    float n[3] = {
        v1[1] * v2[2] - v1[2] * v2[1],
        v1[2] * v2[0] - v1[0] * v2[2],
        v1[0] * v2[1] - v1[1] * v2[0]
    };
    
    float n_len = sqrt(n[0] * n[0] + n[1] * n[1] + n[2] * n[2]);
    n[0] /= n_len;
    n[1] /= n_len;
    n[2] /= n_len;
    
    *d = -(n[0] * p1.x + n[1] * p1.y + n[2] * p1.z);
    
    *a = n[0];
    *b = n[1];
    *c = n[2];
}
//Para determinar se P4 está no plano, basta substituir os coeficientes e as coordenadas de P4 na equação do plnao
bool is_point_in_plane(float a, float b, float c, float d, Point3D p4){
    return a * p4.x + b * p4.y + c * p4.z + d == 0;
}