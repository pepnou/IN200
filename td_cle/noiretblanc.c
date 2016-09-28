#include "graphics.h"

int plat[10][10];
int somme_case;

void affiche_plateau(){
	
	fill_screen(couleur_RGB(0,170,0));
	
	POINT p1;POINT p2;POINT p3;POINT p4;
	p1.x=0;p1.y=0;
	p2.x=500;p2.y=0;
	p3.x=0;p3.y=0;
	p4.x=0;p4.y=500;
	int i;
	for(i=0;i<10;i++){
		draw_line(p1,p2,noir);
		p1.y=p2.y=p2.y+50;
		draw_line(p3,p4,noir);
		p3.x=p4.x=p4.x+50;
	}
	
}
void initialise_plateau(){
	int i,j;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			plat[i][j]=alea_int(2);
		}
	}
}
void dessine_pion(){
	POINT p;
	int i,j;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			p.x=25+i*50;p.y=25+j*50;
			if(plat[i][j]==0){
				draw_fill_circle(p,25,blanc);
			}
			else{
				draw_fill_circle(p,25,noir);
			}
		}
	}
}
void modifie_plateau(POINT p){
	p.x=p.x/50;
	p.x=p.x*50;
	p.y=p.y/50;
	p.y=p.y*50;
}
int somme(){
	int i,j;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			somme_case=somme_case + plat[i][j];
		}
	}
	return somme_case;
}
int encore(){
	if (somme_case==0 || somme_case==100){
		return 0;
	}
	else{
		return 1;
	}
}
	
int main(){

init_graphics(500,500);

POINT p;
p=wait_clic();

affiche_plateau();
initialise_plateau();
dessine_pion();


wait_escape();
exit(0);
}
