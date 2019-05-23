/**
    algoritmo:
    Defimos o tamanho da tela   (constantes: 640x480)
    Declaramos uma janela e superficie
    verificamos se o video esta ok se nao, mostra erro
            criamos  o a janela com titulo e posisaos e tamanho e se visivel(eu acho)
            verifica se foi criando a janela se nao, mostra erro
            pegamos a superficie e colocamos na janela
            desenhos um retagulo com a cor vermelho
            esperamos 2 segundo e destruimos a jenala e saimos do programa !
**/


#include <cstdio>
#include <SDL.h>
//#include <exception>
//#include <string>
//#include <iostream>
//#include <cstdlib>
//#define

/// Defimos o tamanho da tela;
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


using namespace std;
int main( int argc, char * args[] )
{
    ///declaramos uma janela
    SDL_Window* janela  = NULL;

    ///desclaramos uma superficie
    SDL_Surface* superficie = NULL;


    /// verifica se  o video ta ok para inicialiaza a janela
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("erro ao inicia o video %s\n",SDL_GetError());
    }else{
        /// cria janela como seu atributos
        janela = SDL_CreateWindow("Hello World ",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
        if(janela == NULL){
            printf("erro ao criar janela SDL_ERROR: %s\n",SDL_GetError());
        }else{

            /// pega superficie da janela
            superficie = SDL_GetWindowSurface(janela);

            /// desenha um retagulo na superficie
            SDL_FillRect(superficie,NULL,SDL_MapRGB(superficie->format,255,0,0));


            ///atualizar o superficie da janela
            SDL_UpdateWindowSurface(janela);

            ///atraso na janela

            SDL_Delay(2000);

        }
    }



    /// destruir janela
    SDL_DestroyWindow(janela);

    /// sair da programa!
    SDL_Quit();

    return 1;
}

/*palavra


*/



