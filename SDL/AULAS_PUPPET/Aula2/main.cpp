#include <iostream>
#include <cstdlib>
#include <SDL.h>
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

///
bool init();
bool loadMedia();
void close();

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gBackground;



using namespace std;
int main(int argc,char* argv[]){
    if(!init()){
        cout << "erro na inicializao" << endl;
    }else{
        if(!loadMedia()){
            cout << "erro na imagem " << endl;
        }else{
            SDL_BlitSurface(gBackground,NULL,gScreenSurface,NULL);
            SDL_UpdateWindowSurface(gWindow);
            SDL_Delay(3000);
        }
    }

    close();
    return 0;
}





bool init(){
    bool success = true;

    if( SDL_Init( SDL_INIT_VIDEO ) <  0 ){
        cout << "SDL nao inicializou SDL_Error: " << SDL_GetError() << endl;
    }else{
        gWindow = SDL_CreateWindow("SDL aula2 ", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
        if(gWindow == NULL){
            cout << "window nao foi creato SDL_Error: " << SDL_GetError() << endl;
            success = false;
        }else{
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }
    return success;
}

bool loadMedia(){
    bool success = true;

    gBackground = SDL_LoadBMP("background.bmp");
    if(gBackground == NULL){
        cout << "erro ao carrega a imagem SDL_Error: " << SDL_GetError() << endl;
    }
    return success;

}

void close(){
    SDL_FreeSurface(gBackground);
    gBackground == NULL;

    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    SDL_Quit();
}



