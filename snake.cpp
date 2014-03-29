#include "snake.h"

#define MAXFILES 20 //PARA EL EJE Y
#define MAXCOLS 31  // PARA EL EJE X

char mapa[MAXFILES][MAXCOLS] = {
      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
      "X                           X",
      "X                           X",
      "X                           X",
      "X                           X",
      "X                           X",
      "X                           X",
      "X                           X",
      "X                           X",
      "X                           X",
      "X                           X",
      "X                           X",
      "X                           X",
      "X                           X",
      "X                           X",
      "X                           X",
      "X                           X",
      "X                           X",
      "X                           X",
      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
};


void dibujar_mapa(){
    int row, col;

    for(row = 0; row< MAXFILES; row++){
        for(col=0; col<MAXCOLS; col++)
          if(mapa[row][col]=='X') //cada vez que encuentre una X. dibuja una roca
            draw_sprite(buffer, roca, col*30,row*30);
    }
}

void pantalla(){
    blit(buffer, screen, 0,0,0,0,880,660);
}

//constructor
serpiente::serpiente(){
    tam=3;
    dir=1;
    salir=false;
    puntos=0;
    int x = 12*30; //pos inicial
    int y = 12*30;
    for(int c = 0; c<tam; c++){ //asigna al vector de coordenadas cuerpo para luego poder dibujarlos
        cuerpo[c].x=x;
        cuerpo[c].y=y+c;
    }
}


void serpiente::dibujar_personaje(){ //recorre el vector y asigna un bitmap a cada pos
    int x,y;
    for ( int c = tam-1; c >= 0; c--){
       x =  cuerpo[c].x;
       y =  cuerpo[c].y;

       if(c==0){
            blit(pacbmp, snake, dir*33,0,0,0,33,33);
            draw_sprite(buffer, snake, cuerpo[0].x,cuerpo[0].y);
       }
       else{
            blit(pacbmp, snake, 4*33,0,0,0,33,33);
            draw_sprite(buffer, snake, cuerpo[c].x,cuerpo[c].y);
       }
    }
}

void serpiente::mover_personaje(){
    for(int c= tam-1; c>0; c--){
        cuerpo[c].x = cuerpo[c-1].x;
        cuerpo[c].y = cuerpo[c-1].y;
    }

    if(dir == 0){
        if(mapa[cuerpo[0].y/30][(cuerpo[0].x-30)/30] != 'X')
           cuerpo[0].x -= 30;
        else salir=true;
    }
    if(dir == 1){
        if(mapa[cuerpo[0].y/30][(cuerpo[0].x+30)/30] != 'X')
           cuerpo[0].x += 30;
        else salir=true;
    }
    if(dir == 2){
        if(mapa[(cuerpo[0].y-30)/30][cuerpo[0].x/30] != 'X')
           cuerpo[0].y -= 30;
           else salir=true;
    }
    if(dir == 3){
        if(mapa[(cuerpo[0].y+30)/30][cuerpo[0].x/30] != 'X')
           cuerpo[0].y += 30;
           else salir=true;
    }
}

bool serpiente::game_over(){
    if(salir==true)
        return true;

    else return false;
}

