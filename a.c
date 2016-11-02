#include "SDL.h"
#include "SDL/SDL_ttf.h"

int main(int argc, char *argv[]) {
    SDL_Window *win = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *bitmapTex = NULL;
    SDL_Surface *bitmapSurface = NULL;
    int posX = 100, posY = 100, width = 320, height = 240;

    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
        if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	}
	else{
	SDL_Surface *screenSurface = SDL_CreateRGBSurfaceFrom(NULL,
                                   SCREEN_WIDTH, SCREEN_HEIGHT,
                                   32, 4,
                                   0x00FF0000,
                                   0x0000FF00,
                                   0x000000FF,
                                   0xFF000000);
	
	SDL_PixelFormat *format = SDL_AllocFormat(SDL_PIXELFORMAT_ARGB8888);
	assert(format);
        win = SDL_CreateWindow("Hello World", posX, posY, width, height, 0);
        assert(win);
    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	assert(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	bitmapTex = SDL_CreateTextureFromSurface(renderer, screenSurface);
	SDL_Texture *screen = SDL_CreateTexture(renderer,
						SDL_PIXELFORMAT_ARGB8888,
						SDL_TEXTUREACCESS_STREAMING,
						SCREEN_WIDTH,
						SCREEN_HEIGHT);
	assert(screen);
   // bitmapSurface = SDL_LoadBMP("road2.bmp.bmp");
    bitmapTex = SDL_CreateTextureFromSurface(renderer, bitmapSurface);
    SDL_FreeSurface(bitmapSurface);

   			SDL_Event event;
       
       				 switch(code){
					case SDL_START:
						start();
						break;
					case SDL_ADDREC:
					        addrec(j);
						break;
					case SDL_SEARCHREC:
					        searchrec(j);
						break;
					case SDL_MODREC:
						modrec(j); 
						break;
					case SDL_FEE:
						fee(j);
						break;
					case SDL_CHKDAT:
						chkdat(mm,dd);
						break;
				  	case SDL_CLSCANF:
				                clscanf();
						break;
						
					
					default:
						{
						SDL_invalid:
						}
						break;
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, bitmapTex, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(bitmapTex);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);

    SDL_Quit();
    TTF_Quit();

    return 0;
}

