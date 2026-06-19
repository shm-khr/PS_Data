#include<cstdio>
#include<cmath>
struct Point {double x, y;};

double inner(double x1, double y1, double x2, double y2){
    return x1*x2 + y1*y2;
}

double cross(double x1, double y1, double x2, double y2){
    return x1*y2 - y1*x2;
}

double abs(Point x){
    return sqrt(x.x*x.x + x.y*x.y);
}

int main(int argc, char const *argv[])
{
    Point p0, p1, p2;
    Point a, b, x;
    
    int q;
    scanf("%lf %lf %lf %lf", &p1.x, &p1.y, &p2.x, &p2.y);
    a.x = p2.x - p1.x;
    a.y = p2.y - p1.y;

    scanf("%d", &q);
    for(int i=0; i<q; i++){
        scanf("%lf %lf", &p0.x, &p0.y);
        b.x = p0.x - p1.x;
        b.y = p0.y - p1.y;

        double sine = cross(a.x, a.y, b.x, b.y)/(abs(a)*abs(b));
        double cosine = inner(a.x, a.y, b.x, b.y)/(abs(a)*abs(b)); 

        x.x = (2*cosine*cosine-1)*b.x + (2*cosine*sine)*b.y;
        x.y = -(2*cosine*sine)*b.x + (2*cosine*cosine-1)*b.y;
        
        printf("%.10lf %.10lf\n", x.x+p1.x, x.y+p1.y);
    }
    return 0;
}

