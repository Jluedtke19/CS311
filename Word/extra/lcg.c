
#include <stdio.h>
#include <stdlib.h>

int previousValue = 300;
int multiplier = 742;
int increment = 106;
int modulus = 2047;

typedef struct point Point2D, *Point2DPointer;
typedef struct collection Collection, *CollectionPointer;

struct point {
  double x;
  double y;
};

struct collection {
  int size;
  Point2DPointer points;
};

int linearCongruentialGenerator() {
  previousValue = (multiplier * previousValue + increment) % modulus;
  return previousValue;
} // linearCongruentialGenerator()

double getCoordinate() {
  return 2 * (((double) linearCongruentialGenerator())/modulus) - 1;
} // getCoordinate()

Point2D getPoint2D() {
    Point2DPointer pp = (Point2DPointer) malloc( sizeof(Point2D) );
    pp->x = getCoordinate();
    pp->y = getCoordinate();
    return *pp;
} // getPoint2D()

void printPoint2D( Point2D p ) {
    printf( "(%8.4f, %8.4f)\n", p.x, p.y );
} // printPoint2D( Point2D )

Collection makeCollection( int numberOfPoints ) {
    CollectionPointer cp = (CollectionPointer) malloc( sizeof(Collection) );
    cp->size = numberOfPoints * sizeof(Point2D);
    cp->points = (Point2DPointer) malloc( sizeof(Point2D) );

    for( int i = 0; i < cp->size; i++ ) {
        cp->points[i] = getPoint2D();
    } // for

    return *cp;
} // makeCollection( int )

int main( int argc, char** argv ) {

    int length = 128;
    int sample;

    Collection data = makeCollection( length );
    
    for( int i = 0; i < data.size; i++ ) {
        printPoint2D( data.points[i] );
    } // for

} // main( int, char** )

