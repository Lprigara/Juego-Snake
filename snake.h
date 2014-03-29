#include<allegro.h>
#include<stdlib.h>
#include<time.h>


using namespace std;

//Pantalla inicio
BITMAP *buffer2;
BITMAP *fondo1;
BITMAP *fondo2;
BITMAP *fondo3;
BITMAP *cursor;

//juego
BITMAP *buffer;
BITMAP *roca;
BITMAP *pacbmp;
BITMAP *snake;
BITMAP *comida;


//pantalla gameover
BITMAP *perder;
BITMAP *buffer3;



struct coord{  //tanto para la serpiente como para la comida
       int x;
       int y;
}coordenadas;

class serpiente{
      private:
            coord cuerpo[100];
            int tam;
            int puntos;
            bool salir;
            int dir;

      public:
            serpiente();
           // ~serpiente();

            void mover_personaje();
            void dibujar_personaje();
            bool game_over();

            ////GET
            int getcuerpox(int i){return cuerpo[i].x;}
            int getcuerpoy(int i){return cuerpo[i].y;}
            int gettam(){return tam;};
            int getpuntos(){return puntos;};

            ////SET
            void settam(int i){tam+=i;};
            void setpuntos(int i){puntos+=i;};
            void setdir(int i){dir=i;};

};
