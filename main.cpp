#include "snake.cpp"

int main(){
    //funciones allegro
    allegro_init();
    install_mouse();
    install_keyboard();

    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 500, 400, 0, 0);

    srand(time(NULL)); //semilla para el random

    //cargar imagenes iniciales
    buffer2 = create_bitmap(500,400);
    fondo1 = load_bitmap("blanco.bmp",NULL);
    fondo2 = load_bitmap("empezar.bmp",NULL);
    fondo3 = load_bitmap("sdj.bmp",NULL);
    cursor = load_bitmap("cursor.bmp",NULL);

    bool salida = false;
    coord food;

    while(!salida && !key[KEY_ESC]){ //hazlo mientras no choque o no se pulse la tecla ESC

        if(mouse_x > 141 && mouse_x < 318 && mouse_y > 255 && mouse_y < 293){ //si está dentro de las coordenadas
            blit(fondo2, buffer2,0,0,0,0,500,400);
            if(mouse_b & 1){ //si se clickea "EMPEZAR", carga las imagenes y empieza el juego

                buffer = create_bitmap(880, 660);
                roca = load_bitmap("roca.bmp", NULL);
                pacbmp = load_bitmap("snake.bmp",NULL);
                snake = create_bitmap(33,33);
                comida = load_bitmap("Comida.bmp",NULL);

                set_gfx_mode(GFX_AUTODETECT_WINDOWED, 880, 660, 0, 0);

                serpiente s;

                food.y=(1+rand()%(MAXFILES-2)); //poner comida aleatoriamente dentro de los limites de la pantalla
                food.x=(1+rand()%(MAXCOLS-2));

                while(!key[KEY_ESC] &&  !s.game_over()  ){

                        draw_sprite(buffer,comida,food.x*30,food.y*30);//manda a dibujar comida

                        //establecer direcciones
                        if(key[KEY_RIGHT]) s.setdir(1);
                        else if(key[KEY_LEFT]) s.setdir(0);
                        else if(key[KEY_UP]) s.setdir(2);
                        else if(key[KEY_DOWN]) s.setdir(3);

                        s.mover_personaje();

                        //si come, que ponga otra comida, aumente puntos y tamano
                        if(s.getcuerpox(0)/30 == food.x && s.getcuerpoy(0)/30==food.y){

                                food.y=(1+rand()%(MAXFILES-2));
                                food.x=(1+rand()%(MAXCOLS-2));
                                s.settam(1);
                                s.setpuntos(10);
                        }

                        dibujar_mapa();
                        s.dibujar_personaje();

                        //funciones allegro que muestra por pantalla, en este caso, puntos y tamano
                        char c1[10];
                        textout_ex(buffer,font,"Tamano:",50,630,0xfff000,-1);
                        textout_ex(buffer, font, itoa(s.gettam(),c1,10), 110, 630,  0xfff000, -1);
                        textout_ex(buffer,font,"Puntos:",50,640,0xfff000,-1);
                        textout_ex(buffer, font, itoa(s.getpuntos(),c1,10), 110, 640,  0xfff000, -1);

                        pantalla();
                        rest(150);


                        //limpia los buffer
                        clear(buffer);
                        clear(snake);
                        //////////////////////////////////////////////////////////////////////game over

                        if(s.game_over()){
                            set_color_depth(32);
                            set_gfx_mode(GFX_AUTODETECT_WINDOWED, 500, 400, 0, 0);

                            for(int i=0; i<10; ){
                                buffer3 = create_bitmap(500,400);
                                perder = load_bitmap("perder.bmp",NULL);
                                blit(perder, screen, 0,0,0,0,880,660);
                                rest(150);
                                i++;
                            }//end for

                        }//end if

                        salida=true; //sal, es decir, termina el while
                }//end while

          }//end if mouse

                destroy_bitmap(buffer);
    }//if salida



    //si se pulsa el ratón dentro de estas coordenadas (en la imagen referencia a la opción SALIR), pon salida a true
    else if(mouse_x > 103 && mouse_x < 394 && mouse_y > 302 && mouse_y < 341){
        blit(fondo3,buffer2,0,0,0,0,500,400);
        if(mouse_b & 1){
            salida=true;
        }
    }//end elseif

    else blit(fondo1,buffer2,0,0,0,0,500,400);

    //coge coordenadas del cursor y lo muestra
    masked_blit(cursor,buffer2,0,0,mouse_x,mouse_y,13,22);
    blit(buffer2,screen,0,0,0,0,500,400);
    }//while salida


}//end main

END_OF_MAIN();
