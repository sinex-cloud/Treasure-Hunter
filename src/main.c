#include <SDL.h>
#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL_mixer.h>
#include <stdbool.h>
// Define screen dimensions

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 512
#define FONT_PATH   "assets/pacifico/Pacifico.ttf"
#define WAVES_SOUND "assets/level1.wav"
bool check_collision(SDL_Rect player, SDL_Rect tile) {
    return SDL_HasIntersection(&player, &tile);
}
bool collides(SDL_Rect rect1, SDL_Rect rect2) {
    if (rect1.x < rect2.x + rect2.w &&
        rect1.x + rect1.w > rect2.x &&
        rect1.y < rect2.y + rect2.h &&
        rect1.h + rect1.y > rect2.y) {
            return true;
    }
    return false;

}
bool collides1(SDL_Rect rect1, SDL_Rect rect2) {

        int right1 = rect1.x + rect1.w;
        int left2 = rect2.x;

        if (right1 >= left2) {
            return true; // Rectangles collide
        } else {
            return false; // Rectangles don't collide
        }

}
bool isBottomTouchingTop(SDL_Rect rect1, SDL_Rect rect2) {
    int bottom1 = (rect1.y + rect1.h)*32;
    int top2 = rect2.y;

    return (bottom1 <= top2);

}
bool checkCollisionR(SDL_Rect rect1, SDL_Rect rect2) {

    // Check if the right edge of rect1 collides with the left edge of rect2
    if (rect1.x + rect1.w >= rect2.x*32 && rect1.x + rect1.w <= (rect2.x + rect2.w)*32) {
        return true;
    }
    return false;
}
bool checkCollisionl(SDL_Rect rect1, SDL_Rect rect2){
    // Check if the right edge of rect2 collides with the left edge of rect1
    if ((rect2.x + rect2.w)*32 >= rect1.x && (rect2.x + rect2.w )*32<= rect1.x + rect1.w) {
        return true;
    }
    // No collision detected
    return false;
}

Mix_Chunk* load_wav_file(const char* file_path)
{
    Mix_Chunk* audio_chunk = Mix_LoadWAV(file_path);
    if (audio_chunk == NULL) {
        printf("Error loading audio file: %s\n", SDL_GetError());
    }
    return audio_chunk;
}



int main(int argc, char* args[])
{






    SDL_Init(SDL_INIT_AUDIO);
    Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    // Load WAV audio file
    Mix_Chunk* audio_chunk = load_wav_file("assets/level1.wav");
    if (audio_chunk == NULL) {
        printf("Error loading audio file!\n");
        return 1;
    }

    // Play audio file

    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    // Create window
    SDL_Window* window = SDL_CreateWindow("tresure_hunter",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SCREEN_WIDTH,
                                          SCREEN_HEIGHT,
                                          SDL_WINDOW_SHOWN);


    // Create renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);


    // Load sprite sheet
    SDL_Surface* spriteSheet = IMG_Load("assets/player_sprites1.png");


    // Create sprite sheet texture
    SDL_Texture* spriteTexture = SDL_CreateTextureFromSurface(renderer, spriteSheet);

    SDL_Surface* enemy = IMG_Load("assets/craby1.png");

    SDL_Texture* enemeyTexture = SDL_CreateTextureFromSurface(renderer, enemy);

    SDL_Surface* shark = IMG_Load("assets/shark.png");

    SDL_Texture* sharkTexture = SDL_CreateTextureFromSurface(renderer, shark);
    SDL_Surface* bgSurface = IMG_Load("assets/playing_bg_img.png");

    // Create background texture
    SDL_Texture* bgTexture = SDL_CreateTextureFromSurface(renderer, bgSurface);

    SDL_Surface* bgSurface1 = IMG_Load("assets/big_clouds.png");

    // Create background texture

    SDL_Surface* bgSurface2 = IMG_Load("assets/small_clouds.png");




    // Free surface
    SDL_FreeSurface(bgSurface);

    SDL_Surface* bgstart = IMG_Load("assets/press space to start.png");

    SDL_Texture* bgstartTexture = SDL_CreateTextureFromSurface(renderer, bgstart);



    // Free surface
    SDL_FreeSurface(bgstart );



    SDL_Surface* LOSE = IMG_Load("assets/DIEAD.png");

    SDL_Texture*LOSETexture = SDL_CreateTextureFromSurface(renderer,LOSE);



    // Free surface
    SDL_FreeSurface(LOSE);






    SDL_Surface* tree = IMG_Load("assets/tree_one_atlas.png");

    SDL_Texture* treeTexture = SDL_CreateTextureFromSurface(renderer, tree);



    // Free surface
    SDL_FreeSurface(tree );



    SDL_Surface* flag = IMG_Load("assets/flag.png");

    SDL_Texture* flagTexture = SDL_CreateTextureFromSurface(renderer, flag);



    // Free surface
    SDL_FreeSurface(flag );


    SDL_Surface* chest = IMG_Load("assets/chest.png");

    SDL_Texture* chestTexture = SDL_CreateTextureFromSurface(renderer,chest);



    // Free surface
    SDL_FreeSurface(chest );


    SDL_Surface* wheel = IMG_Load("assets/wheel.png");

    SDL_Texture* wheelTexture = SDL_CreateTextureFromSurface(renderer, wheel);



    // Free surface
    SDL_FreeSurface(wheel );


    SDL_Surface* grass = IMG_Load("assets/grass_atlas.png");

    SDL_Texture* grassTexture = SDL_CreateTextureFromSurface(renderer, grass);

    SDL_FreeSurface(grass );










   SDL_Surface* spikes = IMG_Load("assets/trap_atlas.png");

    // Create background texture
    SDL_Texture* skipetexture = SDL_CreateTextureFromSurface(renderer,spikes);

    // Free surface
    SDL_FreeSurface(spikes);
    SDL_Surface* mapoutlast = IMG_Load("assets/outside_sprites.png");

    // Create background texture
    SDL_Texture* mapoutlasttexture = SDL_CreateTextureFromSurface(renderer, mapoutlast );

  SDL_FreeSurface(bgSurface);
    TTF_Font *font = TTF_OpenFont(FONT_PATH, 50);


    SDL_Color textColor           = { 0x00, 0x00, 0x00, 0xFF };
    SDL_Color textBackgroundColor = { 0xFF, 0xFF, 0xFF, 0x0F};
   SDL_Texture *text = NULL;
   SDL_Texture *text1 = NULL;

   SDL_Texture *text2 = NULL;

   SDL_Texture *text3 = NULL;

    SDL_Rect textRect;


    SDL_Surface *textSurface = TTF_RenderText_Shaded(font, " - The First Level - ", textColor, textBackgroundColor);
    SDL_Surface *textSurface1 = TTF_RenderText_Shaded(font, " - The Second Level - ", textColor, textBackgroundColor);
    SDL_Surface *textSurface2 = TTF_RenderText_Shaded(font, " - The Third Level - ", textColor, textBackgroundColor);
    SDL_Surface *textSurface3 = TTF_RenderText_Shaded(font, " - The final Level - ", textColor, textBackgroundColor);



        text = SDL_CreateTextureFromSurface(renderer, textSurface);
        text1 = SDL_CreateTextureFromSurface(renderer, textSurface1);
         text2 = SDL_CreateTextureFromSurface(renderer, textSurface2);
          text3 = SDL_CreateTextureFromSurface(renderer, textSurface3);

        textRect.w = textSurface->w;
        textRect.h = textSurface->h;


        SDL_FreeSurface(textSurface);

    textRect.x = (SCREEN_WIDTH - textRect.w) / 2;
    textRect.y = 5;

SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
label1:
SDL_Init( SDL_INIT_AUDIO) ;

if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
{
    printf("SDL2_mixer could not be initialized!\n"
           "SDL_Error: %s\n", SDL_GetError());
}

Mix_PlayChannel(-1, audio_chunk, -1);
int level1[16][32]={
    {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
    {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
    {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
    {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
    {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
    {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
    {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
    {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
    {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
    {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
    {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
    {9,9,9,9,9,7,9,9,9,7,9,9,9,9,9,7,9,9,9,9,9,9,9,9,9,9,7,9,9,9,9,9},
    {9,9,9,9,9,9,9,11,9,9,9,9,3,9,9,5,9,9,9,9,11,9,90,9,9,9,9,4,9,9,10,9},
    {9,9,7,9,9,0,0,0,0,0,9,9,9,9,9,0,0,0,0,0,0,0,0,0,0,0,0,9,9,9,9,9},
    {9,9,9,9,9,6,6,6,6,6,2,2,2,2,2,6,6,6,6,6,6,6,6,6,6,6,6,2,9,9,9,9},
    {0,0,0,0,0,6,6,6,6,6,17,17,17,17,17,6,6,6,6,6,6,6,6,6,6,6,6,17,0,0,0,0}
};

 int level2[16][32]={

             {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
             {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
             {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
             {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,10},
             {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,7,9,9,9,9,9},
             {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,5,9,90,11,9,4},
             {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,0,0,0,0,0,0},
             {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,6,6,6,6,6,6},
             {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,3,9,9,6,6,6,6,6,6},
             {9,9,9,9,9,9,9,9,9,9,9,0,9,9,3,9,9,3,9,9,3,9,9,9,9,9,6,6,6,6,6,6},
             {9,9,9,9,9,9,9,9,9,9,0,6,9,9,9,9,9,9,9,9,9,9,9,9,9,9,6,6,6,6,6,6},
             {9,9,9,9,9,9,9,9,9,0,6,6,9,9,9,9,9,9,9,9,9,9,9,9,9,9,6,6,6,6,6,6},
             {7,9,9,9,9,9,7,9,0,6,6,6,9,9,9,9,9,9,9,9,9,9,9,9,9,9,6,6,6,6,6,6},
             {9,9,9,11,9,9,9,0,6,6,6,6,9,9,9,9,9,9,9,9,9,9,9,9,9,9,6,6,6,6,6,6},
             {0,0,0,0,0,0,0,6,6,6,6,6,9,9,9,9,9,9,9,9,9,9,9,9,9,9,6,6,6,6,6,6},
             {6,6,6,6,6,6,6,6,6,6,6,6,2,2,2,2,2,2,2,2,2,2,2,2,2,2,6,6,6,6,6,6}




 };
      int level3[16][32]={
          {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
          {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
          {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
          {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,10},
          {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
          {7,9,9,7,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
          {9,9,11,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,3,9,0},
          {0,0,0,0,9,9,0,9,9,0,9,9,0,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,6},
          {6,6,6,6,9,9,6,9,9,6,9,9,6,9,9,9,9,9,9,9,9,9,9,9,9,9,3,9,9,9,9,6},
          {6,6,6,6,9,9,6,9,9,6,9,9,6,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,6},
          {6,6,6,6,9,9,6,9,9,6,9,9,6,9,9,9,9,7,9,9,7,9,9,3,9,9,9,9,9,9,9,6},
          {6,6,6,6,9,9,6,9,9,6,9,9,6,9,9,9,9,5,11,90,9,4,9,9 ,9,9,9,9,9,9,9,6},
          {6,6,6,6,9,9,6,9,9,6,9,9,6,9,9,9,9,0,0,0,0,9,9,9,9,9,9,9,9,9,9,6},
          {6,6,6,6,9,9,6,9,9,6,9,9,6,9,9,3,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,6},
          {6,6,6,6,9,9,6,9,9,6,9,9,6,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,6},
          {6,6,6,6,2,2,6,2,2,6,2,2,6,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,6}

            };


      int level4[16][32]={
              {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
              {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
              {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
              {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
              {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
              {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
              {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
              {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
              {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
              {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
              {9,9,9,9,7,9,9,9,7,9,9,9,9,7,9,9,9,7,9,9,9,9,9,7,9,9,9,7,9,9,9,9},
              {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
              {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
              {6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6},
              {6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6},
              {6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6}



      };

      int nexttimeattack=500;
      int delay=0;
      int aftercrabbyhit=0;
      int afterplayerhit=0;
      int afterhitdelay1=0;
        int lower = 1, upper = 3;
      int random=0;
      int nextattack=0;
      bool endattack=true;
      int boss_direction=-1;
      int afterhitdelay=0;
      int max_health_boss = 100;
      int current_health_boss = 100;
      int bar_width_boss= 200;
      int bar_height_boss = 20;
      int bar_x_boss = 820;
      int bar_y_boss = 5;
      int boss_x=950;
      int boss_y=312;
      int max_health = 100;
      int current_health = 100;
      int bar_width = 200;
      int bar_height = 20;
      int bar_x = 5;
      int bar_y = 5;
     int moveSpeed = 1;
 bool moveLeft = false;
   bool attacking = false;
   bool moveRight = false;
int direction=-1;
int level=0;
bool issolide=false;
 int enemeyaction=1;
 int enemy1action=1;
int SPRITE_WIDTH= 64;
int SPRITE_HEIGHT=40;
int SPRITE_ROWS= 9;
int SPRITE_COLS= 9;
int enemyX = 800;
float enemyY =0;
int enemyWidth = 72;
int enemyHeight =32;
int inair=0;
const float GRAVITY =0.1;
const float JUMP_FORCE = -4.5;
 float y=0;
   //float y1=0;
 int enemyrow =5;
 int enemycol =9;
int playeraction=0;
(void)argc;
(void)args;
int red=0;
int jumpinsg=0;

    SDL_Rect spriteRects[SPRITE_COLS ][SPRITE_ROWS];
    SDL_Rect enemyRects[  enemycol ][ enemyrow ];
    SDL_Rect maprects[ 12 ][19 ];
    SDL_Rect enemyRects1[8][5];
    SDL_Rect grassRects1[1][3];

    SDL_Rect flagRects[1][9];
   SDL_Rect chestRects1[1][5];
    SDL_Rect wheelRects1[1][10];

for (int j=0;j<5;j++){
    chestRects1[0][j].x = j * 64;
    chestRects1[0][j].y = 0;
    chestRects1[0][j].w = 64;
    chestRects1[0][j].h= 35;

}

for (int j=0;j<8;j++){
    flagRects[0][j].x = j * 34;
    flagRects[0][j].y = 0;
    flagRects[0][j].w = 34;
    flagRects[0][j].h= 93;

}

for (int j=0;j<10;j++){
    wheelRects1[0][j].x = j * 31;
  wheelRects1[0][j].y = 0;
   wheelRects1[0][j].w = 31;
   wheelRects1[0][j].h= 32;

}

for (int j=0;j<3;j++){
   grassRects1[0][j].x = j * 23;
 grassRects1[0][j].y = 0;
   grassRects1[0][j].w = 23;
   grassRects1[0][j].h= 32;

}





    //SDL_Rect plyer_hitbox;
    SDL_Rect player_hitbox;
      SDL_Rect enemy_hitbox;
    int index_Current = 6;
    int index_Idle = 4;
    int index_Running = 5;
    int index_Jumping = 2;
      int index_falling = 1;

    int  j;
    for (int i = 0 ; i < SPRITE_ROWS; i++)
    {
        for (j = 0; j < SPRITE_COLS; j++)
        {
            spriteRects[i][j].x = j * SPRITE_WIDTH;
            spriteRects[i][j].y = i * SPRITE_HEIGHT;
            spriteRects[i][j].w = SPRITE_WIDTH;
            spriteRects[i][j].h= SPRITE_HEIGHT;
        }
    }
    for (int k = 0 ; k < 4; k++)
    {
        for (int h = 0; h <  12; h++)
        {
         maprects[k][h].x = h *  32;
          maprects[k][h].y = k *  32;
          maprects[k][h].w =  32;
          maprects[k][h].h=  32;
        }
    }
    for (int k = 0 ; k <  enemyrow; k++)
    {
        for (int h = 0; h <  enemycol; h++)
        {
          enemyRects[k][h].x = h *  enemyWidth;
          enemyRects[k][h].y = k *  enemyHeight;
          enemyRects[k][h].w =  enemyWidth;
          enemyRects[k][h].h=  enemyHeight;
        }
    }


    for (int j = 0 ; j <  5; j++)
    {
        for (int g = 0; g< 8; g++)
        {
          enemyRects1[j][g].x = g *  34;
          enemyRects1[j][g].y = j * 30;
          enemyRects1[j][g].w = 34;
          enemyRects1[j][g].h= 30;
        }
    }


    int currentFrame = 0;
    int frameDelay =10;
    int frameCounter = 0;
    int currentFrame1 = 0;
    int frameDelay1 =10; // Adjust this value to change animation speed
    int frameCounter1 = 0;
     int index_Current1 = 6;
     int currentFrame2 = 0;
     int frameDelay2 =10; // Adjust this value to change animation speed
     int frameCounter2 = 0;
      int index_Current2 = 8;
      int currentFrame3 = 0;
      int frameDelay3 =10; // Adjust this value to change animation speed
      int frameCounter3 = 0;
      int currentFrame4 = 0;
      int frameDelay4 =10; // Adjust this value to change animation speed
      int frameCounter4 = 0;
      int currentFrame5 = 0;
      int frameDelay5 =10; // Adjust this value to change animation speed
      int frameCounter5 = 0;
      int currentFrame6 = 0;
      int frameDelay6 =20; // Adjust this value to change animation speed
      int frameCounter6 = 0;

    int quit =0;
    int x=0;
    SDL_RendererFlip isFlip = SDL_FLIP_NONE;
    SDL_RendererFlip isFlip1 = SDL_FLIP_NONE;
    SDL_RendererFlip isFlip3 = SDL_FLIP_NONE;

    //SDL_RendererFlip isFlip2 = SDL_FLIP_NONE;
    int xPos = 0;
    double yPos =360;
    int spacePressed = 0;
    SDL_Rect bgclouds={0,1,448,101};
    SDL_Rect bgclouds1={300,1,448,101};
    SDL_Rect bgclouds2={600,1,448,101};
    SDL_Rect cloudRects[6];
    cloudRects[0] =(SDL_Rect) {0, 10, 150, 50};
cloudRects[1] = (SDL_Rect){600, 0, 150, 50};
cloudRects[2] = (SDL_Rect){400,80, 150, 50};
cloudRects[3] =(SDL_Rect) {0, 70, 150, 50};
cloudRects[4] = (SDL_Rect){300, 20, 150, 50};
cloudRects[5] = (SDL_Rect){500, 0, 150, 50};

    SDL_Texture* bgTexture1 = SDL_CreateTextureFromSurface(renderer, bgSurface1);
    SDL_Texture* bgTextures = SDL_CreateTextureFromSurface(renderer, bgSurface2);
    index_Current2=4;
    enemy1action=0;
    while (!quit)
    {
          if(level==0){
            frameDelay=400;
            frameCounter++;
           index_Current= index_Idle;
            if (frameCounter >= frameDelay)
            {
                currentFrame++;
                if (currentFrame >= index_Current )
                {
                    currentFrame = 0;
                }
                frameCounter = 0;
            }

            SDL_Rect spriteRect = { 400,245, 192, 120 };
            playeraction=0;
            SDL_RenderCopy(renderer, bgstartTexture , NULL, NULL);

            SDL_RenderCopy(renderer, spriteTexture, &spriteRects[playeraction][currentFrame], &spriteRect);

            SDL_RenderPresent(renderer);


            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
                switch (event.type)
                {
                case SDL_QUIT:
                    quit = 1;
                    break;
                default:
                    break;
                case SDL_KEYDOWN:
                            if (event.key.keysym.sym == SDLK_SPACE  ) {

                                level=1;
                                frameDelay=10;
                            }


        }

}
        }

if(current_health<=0 && current_health !=-1){

    direction=0;
    boss_direction=0;
    playeraction=6;
    SDL_Rect spriteRect = { 420,90, 192, 120 };

    SDL_Rect loseRect = { 380,50, 300,400  };

    SDL_RenderCopy(renderer, LOSETexture ,NULL , &loseRect);
   SDL_RenderCopy(renderer, spriteTexture, &spriteRects[playeraction][6], &spriteRect);

    SDL_RenderPresent(renderer);

Mix_HaltChannel(0);

    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            quit = 1;
            break;
        default:
            break;
        case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_r  ) {

                        goto label1;
                    }else if(event.key.keysym.sym == SDLK_q ){

                          quit = 1;
                    }


}

}




}



if(level !=0  ){

if(current_health>0 ){

        SDL_RenderCopy(renderer, bgTexture, NULL, NULL);

        SDL_RenderCopy(renderer,  bgTexture1, NULL,  &bgclouds);
        SDL_RenderCopy(renderer,  bgTexture1, NULL,  &bgclouds1);
        SDL_RenderCopy(renderer,  bgTexture1, NULL,  &bgclouds2);



        for (int i = 0; i < 6; i++) {
             cloudRects[i].x += i/5+ 1;
             if (cloudRects[i].x >1030) {
                 cloudRects[i].x = 0;
             }
         }
        for (int i = 0; i < 6; i++) {
                SDL_RenderCopy(renderer,  bgTextures , NULL, &cloudRects[i]);
            }






if(level==1){
 SDL_RenderCopy(renderer, text, NULL, &textRect);
}
if(level==2){
 SDL_RenderCopy(renderer, text1, NULL, &textRect);
}
if(level==3){
 SDL_RenderCopy(renderer, text2, NULL, &textRect);
}
if(level==4){
 SDL_RenderCopy(renderer, text3, NULL, &textRect);
}

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                quit = 1;
                break;

            case SDL_KEYDOWN:

                        if (event.key.keysym.sym == SDLK_LEFT) {
                            if (inair == 0) {
                                index_Current = index_Running;
                                playeraction = 1;
                            }
                            isFlip = SDL_FLIP_HORIZONTAL;
                            moveLeft = true;

                        } else if (event.key.keysym.sym == SDLK_RIGHT) {
                            if (inair == 0) {
                                index_Current = index_Running;
                                playeraction = 1;
                            }
                            isFlip = SDL_FLIP_NONE;
                            moveRight = true;

                        } else if (event.key.keysym.sym == SDLK_UP) {
                            attacking = true;

                        }
                       else if (event.key.keysym.sym == SDLK_SPACE && !jumpinsg   ) {
                            jumpinsg = 1;
                            y =JUMP_FORCE;

                            spacePressed = 1;
                            if( spacePressed==1){
                            index_Current =index_Jumping ;
                            playeraction=2;
                            }

                            inair=1;

                        }
                        break;

                    case SDL_KEYUP:
                        if (event.key.keysym.sym == SDLK_SPACE) {
                            spacePressed = 0;
            }  else if (event.type == SDL_KEYUP) {

                if (event.key.keysym.sym == SDLK_LEFT) {
                    moveLeft = false;

                } else if (event.key.keysym.sym == SDLK_RIGHT) {
                    moveRight = false;

                } else if (event.key.keysym.sym == SDLK_UP) {
                    attacking = false;

                }
            default:
                       break;
            }
}

}
        if(inair==0){

            jumpinsg=0;
        }




        frameCounter3++;
        if (frameCounter3 >= frameDelay3)
        {
            currentFrame3++;
            if (currentFrame3 >= 8 )
            {
                currentFrame3 = 0;
            }
            frameCounter3 = 0;
        }

        frameCounter4++;
        if (frameCounter4 >= frameDelay4)
        {
            currentFrame4++;
            if (currentFrame4 >= 10 )
            {
                currentFrame4 = 0;
            }
            frameCounter4 = 0;
        }


        frameCounter5++;
        if (frameCounter5 >= frameDelay5)
        {
            currentFrame5++;
            if (currentFrame5 >= 3 )
            {
                currentFrame5 = 0;
            }
            frameCounter5 = 0;
        }


        frameCounter6++;
        if (frameCounter6 >= frameDelay6)
        {
            currentFrame6++;
            if (currentFrame6 >= 5 )
            {
                currentFrame6 = 0;
            }
            frameCounter6 = 0;
        }
        frameCounter++;
        if (frameCounter >= frameDelay)
        {
            currentFrame++;
            if (currentFrame >= index_Current )
            {
                currentFrame = 0;
            }
            frameCounter = 0;
        }


        frameCounter1++;

        if (frameCounter1 >= frameDelay1)
        {

            currentFrame1++;
            if (currentFrame1 >= index_Current1 )
            {

                currentFrame1 = 0;
            }

            frameCounter1 = 0;

        }
        frameCounter2++;

        if (frameCounter2 >= frameDelay2)
        {

            currentFrame2++;
            if (currentFrame2 >= index_Current2 )
            {

                currentFrame2 = 0;
            }

            frameCounter2 = 0;

        }
    enemy_hitbox.x= enemyX+25;
    enemy_hitbox.y= enemyY+10;
     enemy_hitbox.w= 22;
      enemy_hitbox.h= 25;





        if (moveLeft && !attacking  )
        {
         x-= moveSpeed ;
        }

        if (moveRight && !attacking  )
        {
           x+= moveSpeed ;
        }




if( event.type == SDL_KEYUP){
    moveLeft=false;
    moveRight=false;
    attacking=false;
}

        if (attacking && !moveRight && ! moveLeft) {
            SDL_Rect sword_hitbox;
            if (isFlip == SDL_FLIP_NONE){

             sword_hitbox.x=xPos+45;
              sword_hitbox.y=yPos+9;
               sword_hitbox.w=10;
                sword_hitbox.h=5;
            }

            if(isFlip == SDL_FLIP_HORIZONTAL){

                sword_hitbox.x=xPos+10;
                 sword_hitbox.y=yPos+9;
                  sword_hitbox.w=10;
                   sword_hitbox.h=5;
               }
            index_Current =index_Jumping ;
            playeraction=4;
             if (collides(sword_hitbox, enemy_hitbox)==true && enemeyaction !=4 ){
                 if(current_health<100){
                 current_health+=20;

}
enemeyaction=3;
enemeyaction=4;
direction=0;
            }

        }
        if (moveRight && attacking)
        {
            SDL_Rect sword_hitbox;

             sword_hitbox.x=xPos+45;
              sword_hitbox.y=yPos+9;
               sword_hitbox.w=10;
                sword_hitbox.h=5;

           x+= moveSpeed ;
           index_Current =index_Jumping ;
           playeraction=4;
           if (collides(sword_hitbox, enemy_hitbox)==true && enemeyaction !=4 ){
               if(current_health<100){
               current_health+=20;
            delay=0;
}
enemeyaction=3;

enemeyaction=4;
direction=0;

           }
        }
        if (moveLeft && attacking)
        {
            SDL_Rect sword_hitbox;

             sword_hitbox.x=xPos+10;
              sword_hitbox.y=yPos+9;
               sword_hitbox.w=10;
                sword_hitbox.h=5;
         x-= moveSpeed ;
         index_Current =index_Jumping ;
         playeraction=4;
            if (collides(sword_hitbox, enemy_hitbox)==true && enemeyaction !=4 ){
                if(current_health<100){
                current_health+=20;

}
enemeyaction=3;
enemeyaction=4;
direction=0;


         }
        }
if(enemeyaction==4 && currentFrame1 !=6 ){
  currentFrame1=4;


}

xPos=x;

if (enemeyaction==4 && red ==1 ){
red=0;
}



if(inair==1 &&issolide==false ){
        yPos += y;
         y+= GRAVITY;

}

        if( event.type == SDL_KEYUP && inair==1 ){

             playeraction = 3;
             index_Current = index_falling;
jumpinsg=1;

        }
        if(event.type == SDL_KEYUP && inair==0){

            playeraction = 0;
            index_Current = index_Idle;
            jumpinsg=0;
        }



if(issolide==false){
  inair=1;


}
if (!spacePressed && jumpinsg==0 && yPos == 465 && event.type == SDL_KEYUP && inair==0) {
            playeraction = 0;
            index_Current = index_Idle;

            jumpinsg = 0;
        }


  if(event.type == SDL_KEYUP && inair==0


                 ){
                 playeraction = 0;
                 index_Current = index_Idle;

                 }


 SDL_Rect spriteRect = { xPos, player_hitbox.y-12, SPRITE_WIDTH, SPRITE_HEIGHT };
player_hitbox.x= xPos+24;
 player_hitbox.y= yPos;
  player_hitbox.w= 14;
   player_hitbox.h= 20;
   enemy_hitbox.x= enemyX+25;
   enemy_hitbox.y= enemyY+10;
    enemy_hitbox.w= 22;
     enemy_hitbox.h= 25;
  int tileID=0;


     for (int i = 0; i < 16; i++) {
         for (int j = 0; j < 32; j++) {
             if(level==1){

            tileID =level1[i][j];
}
             if(level==2 && level !=1){
            tileID =level2[i][j];
}
             if(level==3){
            tileID =level3[i][j];
}
             if(level==4){
            tileID =level4[i][j];
}



             if (tileID == 10  ) {
                 SDL_Rect   treepos= {j*32,i*32, 40,100};

                     SDL_RenderCopy(renderer, flagTexture,&flagRects[0][currentFrame3] , &treepos);
             }

             if (tileID == 11  ) {
                 SDL_Rect   treepos= {j*32,i*32, 31,32};

                     SDL_RenderCopy(renderer, wheelTexture, &wheelRects1[0][currentFrame4], &treepos);
             }




             if (tileID == 7  ) {
                 SDL_Rect   treepos= {j*32,i*32-70, 40,150};

                     SDL_RenderCopy(renderer, treeTexture, NULL, &treepos);
             }


                 if (tileID == 2  ) {
                     SDL_Rect spikepos= {j*32,i*32, 32, 32 };

                         SDL_RenderCopy(renderer, skipetexture, NULL, &spikepos);

                     SDL_Rect tileRect1 = {j * 32, i * 32+12, 32, 20};

if (collides(player_hitbox, tileRect1)==true ){
    x=0;
    current_health-=20;
    yPos=50;

}
                 }


                 if (tileID == 17 ) {
                         SDL_Rect tileRect = {j * 32, i * 32, 32, 32};
                       SDL_RenderCopy(renderer, mapoutlasttexture, & maprects[0][1], &tileRect);

                 }

             if (tileID == 0 ) {
                     SDL_Rect tileRect = {j * 32, i * 32, 32, 32};
                   SDL_RenderCopy(renderer, mapoutlasttexture, & maprects[0][1], &tileRect);


for (int h=0;h<16;h+=5){
                   SDL_Rect grassRect = {j * 32+h, i * 32-40, 20, 40};

                 SDL_RenderCopy(renderer, grassTexture, &   grassRects1[0][1], &grassRect);

}


if (SDL_HasIntersection(&player_hitbox, &tileRect)){
    if (player_hitbox.x < tileRect.x  && player_hitbox.y+player_hitbox.h > tileRect.y-tileRect.h && tileRect.y+tileRect.h != player_hitbox.y+player_hitbox.h && player_hitbox.y >tileRect.y) {
        // player collided with left side of tile
          x+=-1;

    }
    else if (player_hitbox.x > tileRect.x && player_hitbox.y+player_hitbox.h > tileRect.y-tileRect.h && tileRect.y+tileRect.h != player_hitbox.y+player_hitbox.h && player_hitbox.y> tileRect.y) {
        x+=1;
    }
    if (player_hitbox.y < tileRect.y && player_hitbox.y+player_hitbox.h > tileRect.y-tileRect.h) {
player_hitbox.y=tileRect.y-18;
        inair=0;
    }else if (player_hitbox.y>tileRect.y ) {
        // player collided with bottom of tile
      inair=1;
    }




}

}
             if(tileID==6){
                 SDL_Rect tileRect = {j * 32, i * 32, 32, 32};

               SDL_RenderCopy(renderer, mapoutlasttexture, & maprects[1][1], &tileRect);

                 if (SDL_HasIntersection(&player_hitbox, &tileRect)){

                                      if (player_hitbox.x < tileRect.x) {
                                          // player collided with left side of tile
                                            x+=-1;
                                      }
                                      else if (player_hitbox.x > tileRect.x) {
                                          x+=1;
                                      }
                                  }
                                  }
             if( tileID == 3){

                 SDL_Rect tileRect = {j * 32, i * 32, 32, 32};

               SDL_RenderCopy(renderer, mapoutlasttexture, & maprects[3][3], & tileRect);
                 if (SDL_HasIntersection(&player_hitbox, &tileRect)){
                     if (player_hitbox.x < tileRect.x  && player_hitbox.y+player_hitbox.h > tileRect.y-tileRect.h && tileRect.y+tileRect.h != player_hitbox.y+player_hitbox.h && player_hitbox.y >tileRect.y) {
                         // player collided with left side of tile
                           x+=-1;

                     }
                     else if (player_hitbox.x > tileRect.x && player_hitbox.y+player_hitbox.h > tileRect.y-tileRect.h && tileRect.y+tileRect.h != player_hitbox.y+player_hitbox.h && player_hitbox.y> tileRect.y) {
                         x+=1;
                     }
                     if (player_hitbox.y < tileRect.y && player_hitbox.y+player_hitbox.h > tileRect.y-tileRect.h) {
player_hitbox.y=tileRect.y-20;
                         inair=0;
                     }else if (player_hitbox.y>tileRect.y ) {
                         // player collided with bottom of tile
                       inair=1;
                     }


                 }
                 }
             if((tileID==90 || tileID==91)&& red==3  ){
                 enemyX=j*32;
                 enemyY=i*32+3;
             }
             if( tileID == 5){

                 SDL_Rect tileRect = {j * 32, i * 32,1, 32};

                    if (SDL_HasIntersection(&enemy_hitbox, &tileRect)){
                        direction*=-1;

                                 isFlip1 = SDL_FLIP_HORIZONTAL;

                    }
             }

             if( tileID == 4){

                 SDL_Rect tileRect = {j * 32, i * 32,1, 32};

                    if (SDL_HasIntersection(&enemy_hitbox, &tileRect)){
                        direction*=-1;


                                    isFlip1 =SDL_FLIP_NONE;

                            }
                    }

             if(tileID==9){
                 SDL_Rect tileRect = {j * 32, i * 32, 32, 32};
               SDL_RenderCopy(renderer, mapoutlasttexture, & maprects[4][19], &tileRect);
             }
         }
     }
        enemyX+=direction;
aftercrabbyhit++;
     if (check_collision(enemy_hitbox,player_hitbox)==true && enemeyaction !=4 && aftercrabbyhit>100 ) {
current_health-=20;
        aftercrabbyhit=0;
     }
     SDL_Rect dest = { enemyX, enemyY, enemyWidth, enemyHeight };

SDL_Point pos1 = {dest.x, dest.y};

if (x==1030 && level ==1  ){
    yPos=50;

        x=0;
         level=2;
        red=1;
    }
if ( level==2 && enemeyaction==4 && red==1){

enemeyaction=1;
direction=-1;


    yPos=50;
red=0;
}
if (x==1030 && level ==2 ){
    yPos=50;
      x=0;
          level=3;
        red=1;
    }
if ( level==3 && red==1 && enemeyaction==4 ){

    enemeyaction=1;
    direction=-1;
red=0;
    yPos=50;
}
if (x==1030 && level ==3 ){
    enemyX=-50;

    yPos=50;
      x=10;
          level=4;
        red=1;
    }

if(level==4 && enemy1action !=4 ){

isFlip1=SDL_FLIP_NONE;
    SDL_Rect dest1 = { boss_x, boss_y, 68, 80};
    SDL_RenderCopyEx(renderer, sharkTexture , &enemyRects1[enemy1action][currentFrame2], &dest1 , 0, 0, isFlip3);


SDL_Rect boss_hitbox;
  boss_hitbox.x= boss_x+20;
   boss_hitbox.y= boss_y+20;
    boss_hitbox.w=30;
     boss_hitbox.h=50;
     afterhitdelay++;
     afterhitdelay1++;
      afterplayerhit++;
      if (attacking && !moveRight && ! moveLeft) {

          SDL_Rect sword_hitbox;

          if (isFlip == SDL_FLIP_NONE){

           sword_hitbox.x=xPos+45;
            sword_hitbox.y=yPos+9;
             sword_hitbox.w=15;
              sword_hitbox.h=5;
          }

          if(isFlip == SDL_FLIP_HORIZONTAL){

              sword_hitbox.x=xPos+10;
               sword_hitbox.y=yPos+9;
                sword_hitbox.w=10;
                 sword_hitbox.h=5;
             }
          index_Current =index_Jumping ;
          playeraction=4;
           if (collides(sword_hitbox, boss_hitbox)==true && afterplayerhit>150 && enemy1action !=4  ){
current_health_boss-=10;
afterplayerhit=0;
          }

      }
      if (moveRight && attacking)
      {
          SDL_Rect sword_hitbox;

           sword_hitbox.x=xPos+45;
            sword_hitbox.y=yPos+9;
             sword_hitbox.w=10;
              sword_hitbox.h=5;

         index_Current =index_Jumping ;
         playeraction=4;
         if (collides(sword_hitbox, boss_hitbox)==true && afterplayerhit>150 && enemy1action !=4  ){


current_health_boss-=10;
afterplayerhit=0;
        }
      }
      if (moveLeft && attacking)
      {
          SDL_Rect sword_hitbox;

           sword_hitbox.x=xPos+10;
            sword_hitbox.y=yPos+9;
             sword_hitbox.w=10;
              sword_hitbox.h=5;
       index_Current =index_Jumping ;
       playeraction=4;
       if (collides(sword_hitbox, boss_hitbox)==true && afterplayerhit>150 && enemy1action !=4 ){

current_health_boss-=10;
afterplayerhit=0;
      }
      }
      if( afterplayerhit==0){
          enemy1action=3;

      }if (afterplayerhit>50 && enemy1action !=2 ) {
          enemy1action=0;


      }
      SDL_Rect outline_rect1 = { bar_x_boss,bar_y_boss, bar_width_boss, bar_height_boss };
      SDL_Rect fill_rect1 = { bar_x_boss + 1, bar_y_boss + 1, (bar_width_boss - 2) * current_health_boss / max_health_boss,  bar_height_boss - 2 };
      SDL_SetRenderDrawColor(renderer, 0,0, 0, 255);
      SDL_RenderDrawRect(renderer, &outline_rect1);
      SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
      SDL_RenderFillRect(renderer, &fill_rect1);
     if(collides(player_hitbox,boss_hitbox) &&afterhitdelay>500 && random==1 ){
         current_health-=30;
         afterhitdelay=0;

}

if((random==1 || random==2 || random==3) && nextattack==0){
    enemy1action=0;



}

if (random == 1 && endattack) {
    boss_direction = -1;
}
     if(random==1 &&  !endattack  ){
         enemy1action=1;

     boss_x += boss_direction;
     boss_x += boss_direction;

     boss_x += boss_direction;


          if ( boss_x ==900) {
              // If the enemy reaches the end of the screen, stop it
               boss_x  =900;
               index_Current2=4;
               enemy1action=0;
              boss_direction = 0;
              enemy1action=0;
             isFlip3 =SDL_FLIP_NONE;
                 endattack = true;
                 enemy1action=0;
nextattack=0;

          } else if ( boss_x < 0) {
              // If the enemy reaches the left side of the screen, reverse its direction
             boss_x = 0;
                           isFlip3 =SDL_FLIP_HORIZONTAL;
             index_Current2=4;
             enemy1action=1;
             boss_direction= 1;
             enemy1action=1;

          }
}

if (random==2 && ! endattack){

    enemyX=boss_x+10;
    enemyY=boss_y+43;
    endattack=true;
    nextattack=0;




}

if (random==2 &&  nextattack ==0 && enemeyaction==4){
    direction=-1;
enemeyaction=1;
}
if(random==3 && !endattack){
    endattack=true;
    nextattack=200;

}


if (boss_hitbox.x-player_hitbox.x<35  && afterhitdelay1>100 && endattack && random !=3 &&  enemy1action !=3  && enemy1action !=4){

  enemy1action=2;
  current_health-=10;
 afterhitdelay1=0;

}
if (boss_hitbox.x-player_hitbox.x>35  && endattack ){

    enemy1action=0;
}
if (current_health_boss==0   ){
    enemy1action=4;
boss_direction=0;

}
if( enemy1action==4 && frameCounter2 !=8 ){
    currentFrame2=4;
    frameCounter2=0;
}




}

if (endattack && nextattack==nexttimeattack  && current_health_boss !=0){
    random=(rand() % (upper - lower + 1)) + lower;

    endattack=false;




}

nextattack++;
if(enemeyaction==4){

delay++;
}
if( enemy1action==4 &&  level==4 ){
    currentFrame2=4;
    SDL_Rect dest1 = { boss_x, boss_y, 68, 80};

    SDL_Rect des2 = { 515, boss_y+20, 128, 60};

    SDL_RenderCopyEx(renderer, sharkTexture , &enemyRects1[enemy1action][currentFrame2], &dest1 , 0, 0, isFlip3);
currentFrame2=0;
    SDL_RenderCopy(renderer, chestTexture , & chestRects1[0][currentFrame6], &des2 );



    frameCounter2=0;
}

SDL_Rect outline_rect = { bar_x, bar_y, bar_width, bar_height };
SDL_Rect fill_rect = { bar_x + 1, bar_y + 1, (bar_width - 2) * current_health / max_health, bar_height - 2 };
SDL_SetRenderDrawColor(renderer, 0,0, 0, 255);
SDL_RenderDrawRect(renderer, &outline_rect);
SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
SDL_RenderFillRect(renderer, &fill_rect);

SDL_RenderCopyEx(renderer, enemeyTexture, &enemyRects[enemeyaction][currentFrame1], &dest, 0, &pos1,isFlip1);

SDL_Point pos3 = { player_hitbox.x,  player_hitbox.y};
SDL_RenderCopyEx(renderer, spriteTexture, &spriteRects[playeraction][currentFrame], &spriteRect, 0, & pos3, isFlip);

SDL_RenderPresent(renderer);
SDL_Delay(10);
if(red==1){
SDL_RenderClear(renderer);
}
red++;
}


}





    }
    Mix_FreeChunk(audio_chunk);
    Mix_CloseAudio();
    Mix_Quit();
    SDL_Quit();
SDL_DestroyRenderer(renderer);
SDL_DestroyTexture(spriteTexture);
SDL_FreeSurface(spriteSheet);
SDL_DestroyTexture(enemeyTexture);

SDL_DestroyTexture(sharkTexture);
SDL_DestroyTexture(text);
SDL_DestroyTexture(text1);
SDL_DestroyTexture(text2);
SDL_DestroyTexture(text3);
SDL_DestroyTexture(skipetexture);
SDL_DestroyTexture(bgTexture);
SDL_DestroyTexture(bgTexture1);

SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
 Mix_CloseAudio();
SDL_Quit();
 SDL_DestroyTexture(mapoutlasttexture);
return 0;
}
