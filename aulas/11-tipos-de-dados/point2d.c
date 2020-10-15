#include "point2d.h"
#include <stdlib.h>

struct _p {
    double x, y;
};

typedef struct _p Point2D;


Point2D *point2D_new(double x, double y) {
    Point2D *ponto = malloc(sizeof(Point2D));
    ponto->x = x;
    ponto->y = y;
    return ponto;
}


void point2D_destroy(Point2D *p) {
    free(p);
}

double point2D_get_x(Point2D *p) {
    return p->x; // (*p).x == p->x
}

double point2D_get_y(Point2D *p) {
    return p->y;
}
/*
    double xn = point2D_get_x(p1)+point2D_get_x(p2);
    double yn = point2D_get_y(p1)+point2D_get_y(p2);
    Point2D *p3 = point2D_new(xn,yn);
    return p3;
*/
Point2D *point2D_add(Point2D *p1, Point2D *p2) {
    Point2D *p3 = point2D_new( p1->x+p2->x , p1->y+p2->y );
    return p3;
}

/*
    double adjacente = point2D_get_x(p2) - point2D_get_x(p1);
    double oposto = point2D_get_y(p2) - point2D_get_y(p1);
    return oposto/adjacente;
*/

double point2D_theta(Point2D *p1, Point2D *p2) {
    double theta = (p2->y-p1->y)/(p2->x-p1->x);
    return theta;
}

Point2D *point2D_scale(Point2D *p, double s) {
    Point2D *ponto = point2D_new(point2D_get_x(p)*s,point2D_get_y(p)*s);
    return ponto;
}

