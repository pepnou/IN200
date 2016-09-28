#include "graphics.h"
#include <time.h>

int main()
{
init_graphics(900,600);

// Debut du code

POINT p1;
p1.x=0;p1.y=0;
POINT p2;
p2.x=5000;p2.y=5000;

COULEUR c;

int r=0;
int g=0;
int b=0;



draw_fill_rectangle(p1,p2,c);










// Fin du code

wait_escape();
exit(0);
}
