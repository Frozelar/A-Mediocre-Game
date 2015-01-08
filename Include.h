// Include all the external libraries and whatnot that we'll be needing
#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <random>
#include <time.h>
#include <string>
#include <random>
#include <time.h>

const int levelW(){ std::ifstream levelMap("resources/level.map"); int unitType = -1; levelMap >> unitType; return unitType; }
const int levelH(){ std::ifstream levelMap("resources/level.map"); int unitType = -1; levelMap >> unitType; levelMap >> unitType; return unitType; }

// window width (in pixels)
const int WINDOW_W = 800;

// window height (in pixels)
const int WINDOW_H = 600;

// default unit width (in pixels)
const int DEFAULT_W = 16;

// default unit height (in pixels)
const int DEFAULT_H = 16;

// maximum level size
const int LEVEL_MAX = 4096;

// default units in the level
const int DEFAULT_LEVEL_UNITS = levelW() * levelH();

// default width of the level (in units)
const int DEFAULT_LEVEL_W = sqrt(DEFAULT_LEVEL_UNITS);

// default height of the level (in units)
const int DEFAULT_LEVEL_H = sqrt(DEFAULT_LEVEL_UNITS);

// default level width in pixels
const int DEFAULT_LEVEL_W_PIXELS = DEFAULT_LEVEL_W * DEFAULT_W;

// default level height in pixels
const int DEFAULT_LEVEL_H_PIXELS = DEFAULT_LEVEL_H * DEFAULT_H;

// default pixels in the level
const int DEFAULT_LEVEL_PIXELS = DEFAULT_LEVEL_UNITS * DEFAULT_W;

// default player width (gfx)
const int DEFAULT_PLAYER_W = 32;

// default player height (gfx)
const int DEFAULT_PLAYER_H = 48;

// player hitbox width
const int PLAYER_HITBOX_W = 12;

// player hitbox height
const int PLAYER_HITBOX_H = 28;

// default width for a bullet
const int DEFAULT_BULLET_W = 4;

// default height for a bullet
const int DEFAULT_BULLET_H = 2;

// default melee weapon width
const int DEFAULT_WEAPON_W = 16;

// default melee weapon height
const int DEFAULT_WEAPON_H = 16;

// default particle width
const int DEFAULT_PARTICLE_W = 3;

// default particle height
const int DEFAULT_PARTICLE_H = 3;

// types of blocks
const int TOTAL_BLOCK_TYPES = 2;

// types of enemies
const int TOTAL_ENEMY_TYPES = 3;

// types of collectibles
const int TOTAL_COLLECTIBLE_TYPES = 1;

// number of player powerups (for use with graphics handling)
const int TOTAL_POWERUPS = 1;

// total possible number of signs in level
const int TOTAL_SIGNS = 16;

// total number of messages
const int TOTAL_MESSAGES = 16;

// total number of options on the entire menu
const int TOTAL_MENU_OPTIONS = 11;

// largest possible amount of bullets
const int MAX_BULLETS = 64;

// largest possible number of things attacking at once
const int MAX_MELEE = 64;

// largest possible number of particles at once
const int MAX_PARTICLES = 256;

// default units for gravity
const int DEFAULT_GRAVITY_UNITS = 16;

// default speed at which the player falls
int defaultGravity[DEFAULT_GRAVITY_UNITS] = { 2, 4, 4, 4, 4, 6, 6, 6, 6, 6, 6, 6, 8, 8, 8, 8 };

// initializes some stuff
bool initOne(void);

// initializes other stuff
bool initTwo(void);

// lays down the level
bool generateLevel(void);

// have we initialized?
bool initialized = initOne();

SDL_Window* gWindow = SDL_CreateWindow("Hey There Guy", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_W, WINDOW_H, SDL_WINDOW_SHOWN);
SDL_Renderer* gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

// the default jump height
const int JUMP_ARRAY_UNITS = 16;
int jumpArray[JUMP_ARRAY_UNITS] = { 16, 12, 12, 8, 8, 8, 8, 8, 8, 6, 6, 4, 4, 4, 4, 2 };

// default jump height for enemies
const int ENEMY_JUMP_ARRAY_UNITS = 8;
int enemyJumpArray[ENEMY_JUMP_ARRAY_UNITS] = { 16, 12, 8, 8, 6, 4, 4, 2 };

// how things, like collectibles, will float in the air
const int FLOATING_ARRAY_UNITS = 20;
int floatingArray[FLOATING_ARRAY_UNITS] = { 1, 1, 2, 1, 1, 0, 0, 0, 0, 0, 1, 1, 2, 1, 1, 0, 0, 0, 0, 0 };

// how enemies will fly
const int FLY_ARRAY_UNITS = 44;
int flyArray[FLY_ARRAY_UNITS] = { 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 4, 4, 4, 4, 4, 4,
	4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1 };

enum MoveType
{
	NO_MOVEMENT, MOVE_RIGHT, MOVE_LEFT, JUMP
};

enum ThingType
{
	NOTHING, PLAYER, SIGN, BULLET, MELEE,
	DEFAULT_BLOCK = 10, BASIC_BLOCK,
	DEFAULT_ENEMY = 40, BASIC_ENEMY, FLY,
	DEFAULT_COLLECTIBLE = 80,
	THINGTYPE_MAX = 99,
	NO_BG = 100, DEFAULT_BG,
	NO_MUSIC = 150, DEFAULT_MUSIC,
	TOTAL_MAX = 200
};

enum FrameType
{
	NO_GFX = -1, IDLE_1, IDLE_2, IDLE_3, IDLE_4,
	WALK_LEFT_1, WALK_LEFT_2, WALK_LEFT_3, WALK_LEFT_4, WALK_LEFT_5, WALK_LEFT_6, WALK_LEFT_7, WALK_LEFT_8,
	WALK_RIGHT_1, WALK_RIGHT_2, WALK_RIGHT_3, WALK_RIGHT_4, WALK_RIGHT_5, WALK_RIGHT_6, WALK_RIGHT_7, WALK_RIGHT_8,
	FALLING_1, FALLING_2,
	JUMPING_1, JUMPING_2,
	SHOOT_LEFT_1, SHOOT_LEFT_2,
	SHOOT_RIGHT_1, SHOOT_RIGHT_2,
	SHOOT_UP_1, SHOOT_UP_2,
	SHOOT_DOWN_1, SHOOT_DOWN_2,
	MELEE_LEFT_1,
	MELEE_RIGHT_1,
	MELEE_UP_1,
	MELEE_DOWN_1,
	TOTAL_FRAMES
};

enum ParticleType
{
	RED_PARTICLE, GREY_PARTICLE, BLUE_PARTICLE, TOTAL_PARTICLE_TYPES
};

enum ParticleFrameType
{
	FLASH_1, FLASH_2, TOTAL_PARTICLE_FRAMES
};

enum Direction
{
	NO_DIRECTION, UP, DOWN, LEFT, RIGHT
};

enum MenuOption
{
	NO_OPTION, RESUME, CONFIG, HELP, EXIT, PSEUDO_TOTAL_OPTIONS
};
const int MENU_TOTAL = PSEUDO_TOTAL_OPTIONS - 1;

enum ConfigMenuOption
{
	NO_CONFIG_OPTION = MENU_TOTAL, CONFIGURE_SOMETHING, CONFIGURE_SOMETHING_ELSE, CONFIG_RETURN, PSEUDO_CONFIG_TOTAL_OPTIONS
};
const int CONFIG_MENU_TOTAL = PSEUDO_CONFIG_TOTAL_OPTIONS - 1;

enum HelpMenuOption
{
	NO_HELP_OPTION = CONFIG_MENU_TOTAL, HELP_WITH_THIS_THING, HELP_WITH_THIS_OTHER_THING, HELP_RETURN, PSEUDO_HELP_TOTAL_OPTIONS
};
const int HELP_MENU_TOTAL = PSEUDO_HELP_TOTAL_OPTIONS - 1;

bool quit = false;
SDL_Event e;
SDL_Event prev_e;
bool inSign = false;
bool keyIsDown = false;
bool levelIsScrollingHorizontal = false;
bool levelIsScrollingVertical = false;
Uint8 oneMoreMove = 0;
int playerCenterDifferenceX = 0;
int playerCenterDifferenceY = 0;
bool collisionMatters = true;
// bool isColliding = false;
bool framesCycled = false;
int bulletShootWaitCounter = 0;
bool initializedFrame = false;
Direction directionKey = NO_DIRECTION;
bool shiftDown = false;
bool canShoot = true;
int canMelee = -1;
bool inMenu = false;
int inSubMenu = NO_OPTION;
bool frameSwitched = false;
int levelMovementsX = 0;
int levelMovementsY = 0;

/*
class Level
{
public:
	int levelW;
	int levelH;
	int levelUnits;
	int levelPixels;
	int levelW_pixels;
	int levelH_pixels;
};
*/

class Texture
{
public:

	// constructor to initialize properties
	Texture(int = 2, int = 2, int = DEFAULT_W, int = DEFAULT_H);

	// deconstructor to destroy everything
	~Texture();

	// render the texture to the screen
	void txRender(SDL_Rect *clip = NULL, SDL_Point *center = NULL,
		double rotation = 0.0, SDL_RendererFlip flip = SDL_FLIP_NONE);

	// load up a texture from a file
	bool txLoadF(std::string);

#ifdef _SDL_TTF_H
	//Creates image from font string
	bool loadT(std::string textureText, SDL_Color textColor);
#endif

	// free everything
	void txFree(void);

	// set color using red, green, blue
	void txColor(Uint8 r, Uint8 g, Uint8 b);

	// set transparency (aka alpha)
	void txAlpha(Uint8 a);

	// set blend mode
	void txBlend(SDL_BlendMode b);

	SDL_Texture* txTexture;
	SDL_Rect txRect;
};

class Player
{
public:
	// set properties
	Player(int = WINDOW_W/2, int = WINDOW_H/2, int = DEFAULT_PLAYER_W, int = DEFAULT_PLAYER_H);

	// destroy texture
	~Player();

	// makes the player jump
	void plJump(void);

	// syncronize the texture to where the actual player is
	void plSyncTexture(void);

	// check to see if the input has to do with the player (returns whether it did or not)
	bool plHandleEvent(SDL_Event*);

	// moves the player and checks collision (takes a moveType, or NULL if the direction is build in to the speed)
	void plMove(int);

	// makes the player shoot a bullet
	void plShoot(Direction);

	// makes the player do a MELEE ATTAACK
	void plMelee(Direction);

	// renders the desired player frame to the screen
	void plRender();

	// void plUpdate();

	SDL_Rect plGFXrect;
	SDL_Rect plHitboxRect;
	int plSpeed = 0;
	int plIsJumping = -1;
	int plIsFalling = 0;
	int plIsShooting = 0;
	int plIsMelee = -1;
	int plParticleCounter = 0;
	bool plTestFalling = false;
	FrameType plCurrentFrame = NO_GFX;
	int plFrameWaitCounter = 0;
	int plHealth = 100;
};

class Enemy
{
public:
	// initialize everything
	Enemy(int = 2, int = 2, int = DEFAULT_W, int = DEFAULT_H, int = DEFAULT_ENEMY);

	// destroy texture
	~Enemy();

	// syncronize the position of the enemy's rect to its actual position
	void enSyncTexture(void);

	void enRender(void);

	void enJump(int);

	void enDie(int, bool);

	void enUpdate(void);

	SDL_Rect enHitboxRect;
	SDL_Rect enGFXrect;
	int enIsJumping = -1;
	int enIsFalling = 0;
	int enIsShooting = -1;
	int enIsMelee = -1;
	bool enTestFalling = false;
	int enSpeed = 2;
	FrameType enCurrentFrame = NO_GFX;
	int enFrameWaitCounter = 0;
	int enType = DEFAULT_ENEMY;
};

class Collectible
{
public:
	Collectible(int = 2, int = 2, int = DEFAULT_W, int = DEFAULT_H, int = DEFAULT_COLLECTIBLE);

	void clRender(void);

	void clCollect(int = NULL);

	void clUpdate(void);

	SDL_Rect clRect;
	int clType = DEFAULT_COLLECTIBLE;
	int clIsFalling = 0;
	int clMovements = 0;
	int clParticleCounter = 0;
	bool clTestFalling = false;
};

class Camera
{
public:
	Camera(int, int, int, int);

	void cmCenterCamera(void);

	SDL_Rect cmRect;
};

class Block
{
public:
	// initialize everything
	Block(int = 2, int = 2, int = DEFAULT_W, int = DEFAULT_H, int = DEFAULT_BLOCK);

	// destroy texture
	~Block();

	void blRender(void);

	void blUpdate(void);

	SDL_Rect blRect;
	int blType = DEFAULT_BLOCK;
	bool blIsSolid = true;
};

class Bullet
{
public:

	// initialize stuff
	Bullet(int = NULL, int = NULL, int = NULL, int = NULL, Direction = NO_DIRECTION, int = -1);

	// clear up everything
	~Bullet();

	void btRender(void);

	void btShoot(void);

	void btMove(int = -1);

	void btDestroy(int = -1);

	SDL_Rect btRect;
	Direction btDirection;
	// ThingType btWhatShotIt;
	int btEnemyNum = -1;
	bool btShouldMove = false;
};

class Melee
{
public:

	Melee(int = NULL, int = NULL, int = NULL, int = NULL, Direction = NO_DIRECTION, int = -1);

	~Melee();

	void meRender(void);

	void meSwing(void);

	void meMove(int = -1);
	
	void meStop(int = -1);

	SDL_Rect meRect;
	Direction meDirection;
	// ThingType meWhatSwungIt;
	int meEnemyNum = -1;
	bool meShouldSwing = false;
};

class Background
{
public:
	Background(int = 0, int = 0, int = WINDOW_W, int = WINDOW_H);

	void bgRender(void);

	void bgUpdate(void);
	
	SDL_Rect bgRect;
	int bgType = DEFAULT_BG;
};

class Particle
{
public:
	Particle(int = NULL, int = NULL, int = DEFAULT_PARTICLE_W, int = DEFAULT_PARTICLE_H, int = RED_PARTICLE);

	void ptMove(int = -1);

	void ptRender(void);

	void ptDie(int = -1);

	SDL_Rect ptRect;
	SDL_Point ptOriginalLocation;
	SDL_Point ptDirectionPoint;
	int ptType;
	int ptLifespan;
	int ptAlpha = 255;
	int ptCounter = 0;
	int ptSlope = 0;
	ParticleFrameType ptFrame;
};

class Music
{
public:
	Music(char* = NULL, int = DEFAULT_MUSIC);

	~Music();

	void msLoad(char* = NULL);

	void msPlay();

	int msType = DEFAULT_MUSIC;
};

class SFX
{
public:
};

class Sign
{
public:
	Sign(int = 0, int = 0, int = DEFAULT_W, int = DEFAULT_H, int = NULL);

	void snLoadMessage();

	void snShowMessage(void);

	void snRender(void);

	SDL_Rect snRect;
	std::string snMessage;
	int snNumber = 0;
};

Player gPlayer;
//Enemy* enemies[DEFAULT_LEVEL_UNITS];
Enemy* enemies[LEVEL_MAX];
Texture collectibleTexture;
//Collectible* collectibles[DEFAULT_LEVEL_UNITS];
Collectible* collectibles[LEVEL_MAX];
//Block* blocks[DEFAULT_LEVEL_UNITS];
Block* blocks[LEVEL_MAX];
Bullet* bullets[MAX_BULLETS];
Melee* weapons[MAX_MELEE];
Particle* particles[MAX_PARTICLES];
Texture playerTextures[TOTAL_FRAMES+1];
Texture defaultEnemyTextures[TOTAL_FRAMES+1][TOTAL_ENEMY_TYPES];
// uh UHHH
Texture* blockTextures[TOTAL_BLOCK_TYPES];
Texture* particleTextures[TOTAL_PARTICLE_FRAMES][TOTAL_PARTICLE_TYPES];
Texture bgTexture;
Texture healthTexture;
Texture bulletTextureH;
Texture bulletTextureV;
Texture playerMeleeTextureH;
Texture playerMeleeTextureV;
Texture enemyMeleeTextureH;
Texture enemyMeleeTextureV;
Background gBackground;
Camera gCamera(NULL, NULL, NULL, NULL);
Mix_Music* gTrack = NULL;
Music gMusic;
//Uint8 gColliding[DEFAULT_LEVEL_UNITS];
Uint8 gCollidingPlayer[LEVEL_MAX];
Uint8 gCollidingEnemy[LEVEL_MAX];
Uint8 gCollidingBullet[LEVEL_MAX];
Uint8 gCollidingSign[TOTAL_SIGNS];
Uint8 gCollidingMelee[LEVEL_MAX];
TTF_Font* gFont = NULL;
Texture* textTextures[TOTAL_MESSAGES];
Texture signTexture;
Texture messageTexture;
Sign* signs[TOTAL_SIGNS];
char* messages[TOTAL_MESSAGES][TOTAL_MESSAGES] = { { "come on and slam and welcome to the jam",
	"come on and slam uh you wanna jam", NULL, NULL },
	{ "it's time for a slamjam",
	"SPACE KABOOOOOOM", NULL, NULL } };
// int messageW[TOTAL_MESSAGES][TOTAL_MESSAGES] = { { 39 * 12, 33 * 12 }, { 23 * 12, 43 * 12 } };
// int messageGroups[16] = { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };
int whichSign = NULL;
Texture menuTexture;
SDL_Rect menuRects[TOTAL_MENU_OPTIONS];
char* menuMessages[TOTAL_MENU_OPTIONS] = { "aaa", "Resume", "Configurations", "Help & Other Options", "Exit Level",
										  "Config 1", "Config 2", "Return", 
										  "Help 1", "Help 2", "Return"};

bool initOne(void)
{
	// initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < NULL)
	{
		std::cout << "SDL error:" << std::endl;
		std::cout << SDL_GetError() << std::endl;
		return false;
	}

	// initialize SDL_image to load png images
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		std::cout << "SDL_Image error:" << std::endl;
		std::cout << IMG_GetError() << std::endl;
		return false;
	}

	// initialize SDL_Mixer for music
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < NULL)
	{
		std::cout << "SDL_Mixer error:" << std::endl;
		std::cout << Mix_GetError() << std::endl;
		return false;
	}

	// initialize SDL_TTF for text
	if (TTF_Init() == -1)
	{
		std::cout << "SDL_TTF error:" << std::endl;
		std::cout << TTF_GetError() << std::endl;
		return false;
	}

	return true;
}

bool initTwo(void)
{
	for (int i = 0; i < LEVEL_MAX; i++)
	{
		enemies[i] = NULL;
		blocks[i] = NULL;
		collectibles[i] = NULL;
	}
	for (int i = 0; i < TOTAL_SIGNS; i++)
	{
		signs[i] = NULL;
		gCollidingSign[i] = NULL;
	}

	for (int i = 0; i < MAX_BULLETS; i++)
	{
		bullets[i] = NULL;
	}

	for (int i = 0; i < MAX_MELEE; i++)
	{
		weapons[i] = NULL;
	}

	for (int i = 0; i < MAX_PARTICLES; i++)
	{
		particles[i] = NULL;
	}

	for (int i = 0, x = 0, y = 0; i < TOTAL_FRAMES+1; i++)
	{
		playerTextures[i].txRect.w = DEFAULT_PLAYER_W;
		playerTextures[i].txRect.h = DEFAULT_PLAYER_H;

		switch (i)
		{
		case NO_GFX: break;
		case IDLE_1: playerTextures[i].txLoadF("resources/plIdle1.png"); 
			defaultEnemyTextures[y][x].txLoadF("resources/enWalkLeft1.png");
			defaultEnemyTextures[y][x + 1].txLoadF("resources/basicEnWalkLeft1.png"); break;
		case IDLE_2: playerTextures[i].txLoadF("resources/plIdle1.png"); 
			defaultEnemyTextures[y][x].txLoadF("resources/enWalkLeft2.png");
			defaultEnemyTextures[y][x + 1].txLoadF("resources/basicEnWalkLeft2.png"); break;
		case WALK_LEFT_1: playerTextures[i].txLoadF("resources/plWalkLeft1.png"); 
			defaultEnemyTextures[y][x].txLoadF("resources/enWalkLeft1.png");
			defaultEnemyTextures[y][x + 1].txLoadF("resources/basicEnWalkLeft1.png"); break;
		case WALK_LEFT_2: playerTextures[i].txLoadF("resources/plWalkLeft2.png");
			defaultEnemyTextures[y][x].txLoadF("resources/enWalkLeft2.png");
			defaultEnemyTextures[y][x + 1].txLoadF("resources/basicEnWalkLeft2.png"); break;
		case WALK_LEFT_3: playerTextures[i].txLoadF("resources/plWalkLeft3.png");
			defaultEnemyTextures[y][x].txLoadF("resources/enemy.png");
			defaultEnemyTextures[y][x + 1].txLoadF("resources/basic_enemy.png"); break;
		case WALK_LEFT_4: playerTextures[i].txLoadF("resources/plWalkLeft4.png");
			defaultEnemyTextures[y][x].txLoadF("resources/enemy.png");
			defaultEnemyTextures[y][x + 1].txLoadF("resources/basic_enemy.png"); break;
		case WALK_LEFT_5: playerTextures[i].txLoadF("resources/plWalkLeft5.png"); break;
		case WALK_LEFT_6: playerTextures[i].txLoadF("resources/plWalkLeft6.png"); break;
		case WALK_LEFT_7: playerTextures[i].txLoadF("resources/plWalkLeft7.png"); break;
		case WALK_LEFT_8: playerTextures[i].txLoadF("resources/plWalkLeft8.png"); break;
		case WALK_RIGHT_1: playerTextures[i].txLoadF("resources/plWalkRight1.png"); 
			defaultEnemyTextures[y][x].txLoadF("resources/enWalkRight1.png");
			defaultEnemyTextures[y][x + 1].txLoadF("resources/basicEnWalkRight1.png"); break;
		case WALK_RIGHT_2: playerTextures[i].txLoadF("resources/plWalkRight2.png"); 
			defaultEnemyTextures[y][x].txLoadF("resources/enWalkRight2.png");
			defaultEnemyTextures[y][x + 1].txLoadF("resources/basicEnWalkRight2.png"); break;
		case WALK_RIGHT_3: playerTextures[i].txLoadF("resources/plWalkRight3.png");
			defaultEnemyTextures[y][x].txLoadF("resources/enemy.png");
			defaultEnemyTextures[y][x + 1].txLoadF("resources/basic_enemy.png"); break;
		case WALK_RIGHT_4: playerTextures[i].txLoadF("resources/plWalkRight4.png");
			defaultEnemyTextures[y][x].txLoadF("resources/enemy.png");
			defaultEnemyTextures[y][x + 1].txLoadF("resources/basic_enemy.png"); break;
		case WALK_RIGHT_5: playerTextures[i].txLoadF("resources/plWalkRight5.png"); break;
		case WALK_RIGHT_6: playerTextures[i].txLoadF("resources/plWalkRight6.png"); break;
		case WALK_RIGHT_7: playerTextures[i].txLoadF("resources/plWalkRight7.png"); break;
		case WALK_RIGHT_8: playerTextures[i].txLoadF("resources/plWalkRight8.png"); break;
		case FALLING_1: playerTextures[i].txLoadF("resources/plFall1.png"); 
			defaultEnemyTextures[y][x].txLoadF("resources/enFall.png");
			defaultEnemyTextures[y][x + 1].txLoadF("resources/basicEnFall.png");
			defaultEnemyTextures[y][x + 2].txLoadF("resources/flyDescend1.png"); break;
		case FALLING_2: playerTextures[i].txLoadF("resources/plFall2.png");
			defaultEnemyTextures[y][x].txLoadF("resources/enFall.png");
			defaultEnemyTextures[y][x + 1].txLoadF("resources/basicEnFall.png");
			defaultEnemyTextures[y][x + 2].txLoadF("resources/flyDescend2.png"); break;
		case JUMPING_1: playerTextures[i].txLoadF("resources/plJump1.png"); 
			defaultEnemyTextures[y][x].txLoadF("resources/enJump.png");
			defaultEnemyTextures[y][x + 1].txLoadF("resources/basicEnJump.png");
			defaultEnemyTextures[y][x + 2].txLoadF("resources/flyAscend1.png"); break;
		case JUMPING_2: playerTextures[i].txLoadF("resources/plJump2.png");
			defaultEnemyTextures[y][x].txLoadF("resources/enJump.png");
			defaultEnemyTextures[y][x + 1].txLoadF("resources/basicEnJump.png");
			defaultEnemyTextures[y][x + 2].txLoadF("resources/flyAscend2.png"); break;
		case TOTAL_FRAMES: break;
		}

		if (i != NO_GFX && i != TOTAL_FRAMES)
		{
			y++;
		}
	}

	for (int i = 0; i < TOTAL_BLOCK_TYPES; i++)
	{
		switch (i)
		{
		case 0:
			blockTextures[i] = new Texture();
			blockTextures[i]->txLoadF("resources/block.png");
			break;
		case 1:
			blockTextures[i] = new Texture();
			blockTextures[i]->txLoadF("resources/basic_block.png");
			break;
		}
	}

	for (int x = 0, y = 0, i = 0; i < TOTAL_PARTICLE_TYPES; i++)
	{
		// use RED or GREY instead of x or x + 1 ?????
		switch (i)
		{
		case FLASH_1:
			particleTextures[y][x] = new Texture();
			particleTextures[y][x]->txLoadF("resources/redParticle1.png");

			particleTextures[y][x + 1] = new Texture();
			particleTextures[y][x + 1]->txLoadF("resources/greyParticle1.png");
			break;
		case FLASH_2:
			particleTextures[y][x] = new Texture();
			particleTextures[y][x]->txLoadF("resources/redParticle2.png");

			particleTextures[y][x + 1] = new Texture();
			particleTextures[y][x + 1]->txLoadF("resources/greyParticle2.png");
			break;
		}

		if (i != TOTAL_PARTICLE_FRAMES)
		{
			y++;
		}
	}

	healthTexture.txRect.x = 2;
	healthTexture.txRect.y = 2;
	healthTexture.txRect.w = 2;
	healthTexture.txRect.h = 2;
	healthTexture.txLoadF("resources/health.png");

	messageTexture.txRect.x = 50;
	messageTexture.txRect.y = 50;
	messageTexture.txRect.w = WINDOW_W - 100;
	messageTexture.txRect.h = WINDOW_H / 4;
	messageTexture.txLoadF("resources/message.png");

	signTexture.txRect.x = 0;
	signTexture.txRect.y = 0;
	signTexture.txRect.w = DEFAULT_W;
	signTexture.txRect.h = DEFAULT_H;
	signTexture.txLoadF("resources/sign.png");

	bulletTextureH.txRect.x = 0;
	bulletTextureH.txRect.y = 0;
	bulletTextureH.txRect.w = DEFAULT_BULLET_W;
	bulletTextureH.txRect.h = DEFAULT_BULLET_H;
	bulletTextureH.txLoadF("resources/bulletHoriz.png");

	bulletTextureV.txRect.x = 0;
	bulletTextureV.txRect.y = 0;
	bulletTextureV.txRect.w = DEFAULT_BULLET_H;
	bulletTextureV.txRect.h = DEFAULT_BULLET_W;
	bulletTextureV.txLoadF("resources/bulletVert.png");

	playerMeleeTextureH.txRect.x = 0;
	playerMeleeTextureH.txRect.y = 0;
	playerMeleeTextureH.txRect.w = DEFAULT_WEAPON_W;
	playerMeleeTextureH.txRect.h = DEFAULT_WEAPON_H;
	playerMeleeTextureH.txLoadF("resources/plMeleeHoriz.png");

	playerMeleeTextureV.txRect.x = 0;
	playerMeleeTextureV.txRect.y = 0;
	playerMeleeTextureV.txRect.w = DEFAULT_WEAPON_H;
	playerMeleeTextureV.txRect.h = DEFAULT_WEAPON_W;
	playerMeleeTextureV.txLoadF("resources/plMeleeVert.png");

	enemyMeleeTextureH.txRect.x = 0;
	enemyMeleeTextureH.txRect.y = 0;
	enemyMeleeTextureH.txRect.w = DEFAULT_WEAPON_W;
	enemyMeleeTextureH.txRect.h = DEFAULT_WEAPON_H;
	enemyMeleeTextureH.txLoadF("resources/enMeleeHoriz");

	enemyMeleeTextureV.txRect.x = 0;
	enemyMeleeTextureV.txRect.y = 0;
	enemyMeleeTextureV.txRect.w = DEFAULT_WEAPON_W;
	enemyMeleeTextureV.txRect.h = DEFAULT_WEAPON_H;
	enemyMeleeTextureV.txLoadF("resources/enMeleeVert");
	
	for (int i = 0; i < TOTAL_MESSAGES; i++)
	{
		if (textTextures[i] != NULL)
		{
			textTextures[i] = NULL;
		}
	}

	// let's get ourselves a font
	gFont = TTF_OpenFont("resources/AveriaSans-Regular.ttf", 18);
	if (gFont == NULL)
	{
		std::cout << "Error opening the font:" << std::endl;
		std::cout << TTF_GetError() << std::endl;
		return false;
	}
	else
	{
		/*
		//Render text
		SDL_Color textColor = { 0, 0, 0 };
		if (!textTexture.loadT("The quick brown fox jumps over the lazy dog", textColor))
		{
			printf("Failed to render text texture!\n");
			return false;
		}
		*/
	}

	for (int i = 1; i < TOTAL_MENU_OPTIONS; i++)
	{
		menuRects[i].w = 0;
		menuRects[i].h = 0;
		menuRects[i].x = (WINDOW_W / 4) + ((DEFAULT_W*i <= 0 ? 1 : 16*i));
		menuRects[i].y = (WINDOW_H / 4) + ((DEFAULT_H*i <= 0 ? 1 : 32*i));
	}

	menuTexture.txRect.x = WINDOW_W / 8;
	menuTexture.txRect.y = WINDOW_H / 8;
	menuTexture.txRect.w = WINDOW_W - (WINDOW_W / 4);
	menuTexture.txRect.h = WINDOW_H - (WINDOW_H / 4);
	menuTexture.txLoadF("resources/menu.png");

	return true;
}

void close(void)
{
	for (int i = 0; i < DEFAULT_LEVEL_UNITS; i++)
	{
		if (blocks[i] != NULL)
		{
			delete blocks[i];
			blocks[i] = NULL;
		}
		if (enemies[i] != NULL)
		{
			delete enemies[i];
			enemies[i] = NULL;
		}
		if (collectibles[i] != NULL)
		{
			delete collectibles[i];
			collectibles[i] = NULL;
		}
	}
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		if (bullets[i] != NULL)
		{
			delete bullets[i];
			bullets[i] = NULL;
		}
	}
	for (int i = 0; i < MAX_MELEE; i++)
	{
		if (weapons[i] != NULL)
		{
			delete weapons[i];
			weapons[i] = NULL;
		}
	}
	for (int i = 0; i < MAX_PARTICLES; i++)
	{
		if (particles[i] != NULL)
		{
			delete particles[i];
			particles[i] = NULL;
		}
	}
	for (int i = 0; i < TOTAL_SIGNS; i++)
	{
		if (signs[i] != NULL)
		{
			delete signs[i];
			signs[i] = NULL;
		}
	}

	Mix_CloseAudio();
	Mix_Quit();
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();

	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;
}

bool generateLevel(void)
{
	int x, y;
	x = 0, y = 0;
	int unitType = -1;
	int signNum = 0;

	std::ifstream levelMap("resources/level.map");
	levelMap >> unitType;
	levelMap >> unitType;

	for (int i = 0, j = 0; i < DEFAULT_LEVEL_PIXELS;)
	{
		unitType = -1;

		levelMap >> unitType;

		if (levelMap.fail())
		{
			std::cout << "Failed to load level.map!  Darn." << std::endl;
			return false;
		}

		if (unitType != NOTHING)
		{
			if (unitType >= DEFAULT_BLOCK && unitType < DEFAULT_ENEMY)
			{
				blocks[j] = new Block(x, y, DEFAULT_W, DEFAULT_H, unitType);
				blocks[j]->blUpdate();
			}
			else if (unitType >= DEFAULT_ENEMY && unitType < DEFAULT_COLLECTIBLE)
			{
				enemies[j] = new Enemy(x, y, DEFAULT_W, DEFAULT_H, unitType);
				enemies[j]->enUpdate();
			}
			else if (unitType == PLAYER)
			{
				gPlayer.plHitboxRect.x = WINDOW_W / 2;
				gPlayer.plHitboxRect.y = WINDOW_H / 2;
				playerCenterDifferenceX = gPlayer.plHitboxRect.x - x;
				playerCenterDifferenceY = gPlayer.plHitboxRect.y - y;
				//gPlayer.plRect.x = x;
				//gPlayer.plRect.y = y;
			}
			else if (unitType >= DEFAULT_COLLECTIBLE && unitType < THINGTYPE_MAX)
			{
				collectibles[j] = new Collectible(x, y, DEFAULT_W, DEFAULT_H, unitType);
				collectibles[j]->clUpdate();
			}
			else if (unitType == SIGN)
			{
				signs[signNum] = new Sign(x, y, DEFAULT_W, DEFAULT_H, signNum);
				signNum++;
			}
			else if (unitType >= NO_BG && unitType < NO_MUSIC)
			{
				gBackground.bgRect.x = 0;
				gBackground.bgRect.y = 0;
				gBackground.bgRect.w = WINDOW_W;
				gBackground.bgRect.h = WINDOW_H;
				gBackground.bgType = unitType;
				gBackground.bgUpdate();
			}
			else if (unitType >= DEFAULT_MUSIC && unitType < TOTAL_MAX)
			{
				gMusic.msLoad("resources/beret2.ogg");
				gMusic.msPlay();
			}
			else
			{
				std::cout << "Unknown unit type during level generation!  :(" << std::endl;
				return false;
			}
		}

		if (x + DEFAULT_W >= DEFAULT_LEVEL_W * DEFAULT_W && unitType < THINGTYPE_MAX)
		{
			x = 0;
			y += DEFAULT_H;
		}
		else if (unitType < THINGTYPE_MAX)
		{
			x += DEFAULT_W;
		}

		if (unitType < THINGTYPE_MAX)
		{
			i += DEFAULT_W;
			j++;
		}
	}

	levelMap.close();

	return true;
}

bool checkCollision(SDL_Rect* thing1, SDL_Rect* thingTwo, bool outputCollision = true, int thingtype = NOTHING, int enemyNum = -1)
{
	// check collision between the first and second things
	// (checks collision with everything in the level if blockTwo and enemyTwo is NULL)

	bool isColliding = false;
	bool needToCheck = true;
	SDL_Rect* thingOne = new SDL_Rect;

	if (thingtype != BULLET)
	{
		thingOne->x = thing1->x + 1;
		thingOne->y = thing1->y + 1;
		thingOne->w = thing1->w - 2;
		thingOne->h = thing1->h - 2;
	}
	else
	{
		thingOne = thing1;
	}

	// clear out gColliding so that results are not reused
	if (outputCollision)
	{
		for (int i = 0; i < DEFAULT_LEVEL_UNITS; i++)
		{
			if (thingtype == PLAYER)
			{
				if (gCollidingPlayer[i] != NULL)
				{
					gCollidingPlayer[i] = NULL;
				}
			}
			else if (thingtype >= DEFAULT_ENEMY && thingtype < DEFAULT_COLLECTIBLE)
			{
				if (gCollidingEnemy[i] != NULL)
				{
					gCollidingEnemy[i] = NULL;
				}
			}
			else if (thingtype == MELEE)
			{
				if (gCollidingMelee[i] != NULL)
				{
					gCollidingMelee[i] = NULL;
				}
			}
			else if (thingtype == BULLET)
			{
				if (gCollidingBullet[i] != NULL)
				{
					gCollidingBullet[i] = NULL;
				}
			}
		}

		if (thingtype == MELEE)
		{
			for (int i = 0; i < MAX_MELEE; i++)
			{
				if (gCollidingMelee[i] != NULL)
				{
					gCollidingMelee[i] = NULL;
				}
			}
		}
	}

	// if we need to check for collision with everything in the level
	if (thingTwo == NULL)
	{
		for (int i = 0; i < DEFAULT_LEVEL_UNITS; i++)
		{
			if (blocks[i] != NULL)
			{
				if ((thingOne->x + thingOne->w > blocks[i]->blRect.x &&
					thingOne->x < blocks[i]->blRect.x + blocks[i]->blRect.w) &&
					(thingOne->y + thingOne->h > blocks[i]->blRect.y &&
					thingOne->y < blocks[i]->blRect.y + blocks[i]->blRect.h))
				{
					if (outputCollision)
					{
						if (thingtype == PLAYER)
						{
							gCollidingPlayer[i] = blocks[i]->blType;
						}
						else if (thingtype >= DEFAULT_ENEMY && thingtype < DEFAULT_COLLECTIBLE)
						{
							gCollidingEnemy[i] = blocks[i]->blType;
						}
						else if (thingtype == BULLET)
						{
							gCollidingBullet[i] = blocks[i]->blType;
						}
						else if (thingtype == MELEE)
						{
							gCollidingMelee[i] = blocks[i]->blType;
						}
					}
					if (!isColliding)
						isColliding = true;
				}
			}

			if (enemies[i] != NULL && i != enemyNum)
			{
				if ((thingOne->x + thingOne->w > enemies[i]->enHitboxRect.x &&
					thingOne->x < enemies[i]->enHitboxRect.x + enemies[i]->enHitboxRect.w) &&
					(thingOne->y + thingOne->h > enemies[i]->enHitboxRect.y &&
					thingOne->y < enemies[i]->enHitboxRect.y + enemies[i]->enHitboxRect.h))
				{
					if (outputCollision)
					{
						if (thingtype == PLAYER)
						{
							gCollidingPlayer[i] = enemies[i]->enType;
						}
						else if (thingtype >= DEFAULT_ENEMY && thingtype < DEFAULT_COLLECTIBLE)
						{
							gCollidingEnemy[i] = enemies[i]->enType;
						}
						else if (thingtype == BULLET)
						{
							gCollidingBullet[i] = enemies[i]->enType;
						}
						else if (thingtype == MELEE)
						{
							gCollidingMelee[i] = enemies[i]->enType;
						}
					}
					if (!isColliding)
						isColliding = true;
				}
			}

			if (collectibles[i] != NULL)
			{
				if ((thingOne->x + thingOne->w > collectibles[i]->clRect.x &&
					thingOne->x < collectibles[i]->clRect.x + collectibles[i]->clRect.w) &&
					(thingOne->y + thingOne->h > collectibles[i]->clRect.y &&
					thingOne->y < collectibles[i]->clRect.y + collectibles[i]->clRect.h))
				{
					if (outputCollision)
					{
						if (thingtype == PLAYER)
						{
							gCollidingPlayer[i] = collectibles[i]->clType;
						}
						// for now enemies can't interact with collectibles but maybe change that in the future??
						else if (thingtype >= DEFAULT_ENEMY && thingtype < DEFAULT_COLLECTIBLE)
						{
							gCollidingEnemy[i] = collectibles[i]->clType;
						}
					}
					if (!isColliding)
						isColliding = true;
				}
			}

			if (thingtype == BULLET || thingtype == MELEE)
			{
				if ((thingOne->x + thingOne->w > gPlayer.plHitboxRect.x &&
					thingOne->x < gPlayer.plHitboxRect.x + gPlayer.plHitboxRect.w) &&
					(thingOne->y + thingOne->h > gPlayer.plHitboxRect.y &&
					thingOne->y < gPlayer.plHitboxRect.y + gPlayer.plHitboxRect.h))
				{
					if (thingtype == BULLET)
						gCollidingBullet[i] = PLAYER;
					else if (thingtype == MELEE)
						gCollidingMelee[i] = PLAYER;

					if (!isColliding)
						isColliding = true;
				}
			}
		}
	}
	else
	{
		if (thingOne != NULL && thingTwo != NULL)
		{
			if ((thingOne->x + thingOne->w > thingTwo->x &&
				thingOne->x < thingTwo->x + thingTwo->w) &&
				(thingOne->y + thingOne->h > thingTwo->y &&
				thingOne->y < thingTwo->y + thingTwo->h))
			{
				isColliding = true;
			}
		}
	}

	return isColliding;
}

bool checkForSign(SDL_Rect* thing)
{
	bool isColliding = false;

	for (int i = 0; i < TOTAL_SIGNS; i++)
	{
		if (gCollidingSign[i] != -1)
		{
			gCollidingSign[i] = -1;
		}
	}

	for (int i = 0; i < TOTAL_SIGNS; i++)
	{
		if (signs[i] != NULL)
		{
			if ((thing->x + thing->w > signs[i]->snRect.x &&
				thing->x < signs[i]->snRect.x + signs[i]->snRect.w) &&
				(thing->y + thing->h > signs[i]->snRect.y &&
				thing->y < signs[i]->snRect.y + signs[i]->snRect.h))
			{
				gCollidingSign[i] = signs[i]->snNumber;
				whichSign = i;

				if (!isColliding)
					isColliding = true;
			}
		}
	}

	return isColliding;
}

void handleSign(void)
{
	bool signSet = false;

	while (inSign)
	{
		for (int i = 0; i < DEFAULT_LEVEL_UNITS; i++)
		{
			if (gCollidingSign[i] != -1)
			{
				for (int j = 0; j < TOTAL_SIGNS; j++)
				{
					if (signs[j] != NULL)
					{
						if (!signSet)
						{
							signs[i]->snLoadMessage();
							signSet = true;
						}

						signs[j]->snShowMessage();
						break;
					}
				}
			}
		}
		SDL_RenderPresent(gRenderer);

		SDL_PollEvent(&e);
		gPlayer.plHandleEvent(&e);
	}

	signSet = false;
}

/*
bool checkCollisionWithGround(SDL_Rect* thingy, int thingtype, int enemyNum = NULL)
{
	if (thingy != NULL)
	{
		SDL_Rect nextPos;
		nextPos.w = thingy->w;
		nextPos.h = thingy->h;
		nextPos.x = thingy->x;
		nextPos.y = thingy->y + 1;

		if (checkCollision(&nextPos, NULL, true, thingtype, enemyNum))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	return false;
}

bool checkCollisionWithCeiling(SDL_Rect* thingy, int thingtype, int enemyNum = NULL)
{
	if (thingy != NULL)
	{
		SDL_Rect nextPos;
		nextPos.w = thingy->w;
		nextPos.h = thingy->h;
		nextPos.x = thingy->x;
		nextPos.y = thingy->y - 1;

		if (checkCollision(&nextPos, NULL, true, thingtype, enemyNum))
		{
			return true;
		}

		return false;
	}

	return false;
}
*/

/*
bool checkCollisionWithWall(SDL_Rect* thingy)
{
	bool isColliding = false;
	thingy->x++;
	for (int i = 0; i < DEFAULT_LEVEL_UNITS; i++)
	{
		if (blocks[i] != NULL)
		{
			if ((thingy->x + thingy->w == blocks[i]->blRect.x &&
				thingy->y > blocks[i]->blRect.y && thingy->y + thingy->h < blocks[i]->blRect.y + blocks[i]->blRect.h) ||
				(thingy->x == blocks[i]->blRect.x + blocks[i]->blRect.w &&
				thingy->y > blocks[i]->blRect.y && thingy->y + thingy->h < blocks[i]->blRect.y + blocks[i]->blRect.h))
			{
				isColliding = true;
			}
		}

		if (enemies[i] != NULL)
		{
			if ((thingy->x + thingy->w == enemies[i]->enRect.x &&
				thingy->y > enemies[i]->enRect.y && thingy->y + thingy->h < enemies[i]->enRect.y + enemies[i]->enRect.h) ||
				(thingy->x == enemies[i]->enRect.x + enemies[i]->enRect.w &&
				thingy->y > enemies[i]->enRect.y && thingy->y + thingy->h < enemies[i]->enRect.y + enemies[i]->enRect.h))
			{
				isColliding = true;
			}
		}

		if (collectibles[i] != NULL)
		{
			if ((thingy->x + thingy->w == collectibles[i]->clRect.x &&
				thingy->y > collectibles[i]->clRect.y && thingy->y + thingy->h < collectibles[i]->clRect.y + collectibles[i]->clRect.h) ||
				(thingy->x == collectibles[i]->clRect.x + collectibles[i]->clRect.w &&
				thingy->y > collectibles[i]->clRect.y && thingy->y + thingy->h < collectibles[i]->clRect.y + collectibles[i]->clRect.h))
			{
				isColliding = true;
			}
		}
	}
	thingy->x--;
	for (int i = 0; i < DEFAULT_LEVEL_UNITS; i++)
	{
		if (blocks[i] != NULL)
		{
			if ((thingy->x + thingy->w == blocks[i]->blRect.x &&
				thingy->y > blocks[i]->blRect.y && thingy->y + thingy->h < blocks[i]->blRect.y + blocks[i]->blRect.h) ||
				(thingy->x == blocks[i]->blRect.x + blocks[i]->blRect.w &&
				thingy->y > blocks[i]->blRect.y && thingy->y + thingy->h < blocks[i]->blRect.y + blocks[i]->blRect.h))
			{
				isColliding = true;
			}
		}

		if (enemies[i] != NULL)
		{
			if ((thingy->x + thingy->w == enemies[i]->enRect.x &&
				thingy->y > enemies[i]->enRect.y && thingy->y + thingy->h < enemies[i]->enRect.y + enemies[i]->enRect.h) ||
				(thingy->x == enemies[i]->enRect.x + enemies[i]->enRect.w &&
				thingy->y > enemies[i]->enRect.y && thingy->y + thingy->h < enemies[i]->enRect.y + enemies[i]->enRect.h))
			{
				isColliding = true;
			}
		}

		if (collectibles[i] != NULL)
		{
			if ((thingy->x + thingy->w == collectibles[i]->clRect.x &&
				thingy->y > collectibles[i]->clRect.y && thingy->y + thingy->h < collectibles[i]->clRect.y + collectibles[i]->clRect.h) ||
				(thingy->x == collectibles[i]->clRect.x + collectibles[i]->clRect.w &&
				thingy->y > collectibles[i]->clRect.y && thingy->y + thingy->h < collectibles[i]->clRect.y + collectibles[i]->clRect.h))
			{
				isColliding = true;
			}
		}
	}

	return isColliding;
}
*/

void applyGravity(Player* player, Enemy* enemy)
{
	SDL_Rect enemyCheckForGround;
	SDL_Rect playerCheckForGround = gPlayer.plHitboxRect;
	SDL_Rect nextPos;
	bool collision = false;
	bool positionedCorrectly = true;
	bool collidedBefore = false;
	bool isColliding = false;
	bool collidedWithEnemy = false;
	static bool wasFalling = false;

	playerCheckForGround.y++;
	isColliding = checkCollision(&playerCheckForGround, NULL, true, PLAYER);
	/*for (int i = 0; i < DEFAULT_LEVEL_UNITS; i++)
	{
		if (gCollidingPlayer[i] != NULL && gCollidingPlayer[i] >= DEFAULT_ENEMY && gCollidingPlayer[i] < DEFAULT_COLLECTIBLE)
		{
			gPlayer.plTestFalling = true;
			break;
		}
	}*/
	if (!isColliding && gPlayer.plIsJumping < 0)
	{
		gPlayer.plTestFalling = true;
	}
	else
	{
		gPlayer.plTestFalling = false;

		if (gPlayer.plSpeed != 0 && gPlayer.plParticleCounter++ >= 4)
		{
			gPlayer.plParticleCounter = 0;
			for (int i = 0; i < MAX_PARTICLES; i++)
			{
				if (particles[i] == NULL)
				{
					particles[i] = new Particle(gPlayer.plGFXrect.x + (gPlayer.plGFXrect.w / 2), gPlayer.plGFXrect.y + gPlayer.plGFXrect.h - 8,
						DEFAULT_PARTICLE_W, DEFAULT_PARTICLE_H, GREY_PARTICLE);
					break;
				}
			}
		}
	}

	if (gPlayer.plIsJumping == 1)
	{
		for (int i = 0, j = 0; i < MAX_PARTICLES && j < 8; i++)
		{
			if (particles[i] == NULL)
			{
				particles[i] = new Particle(gPlayer.plGFXrect.x + (gPlayer.plGFXrect.w / 2), gPlayer.plGFXrect.y + gPlayer.plGFXrect.h - 8,
					DEFAULT_PARTICLE_W, DEFAULT_PARTICLE_H, GREY_PARTICLE);
				j++;
			}
		}
	}

	if (gPlayer.plTestFalling)
	{
		gPlayer.plIsFalling++;
		wasFalling = true;
	}
	else
	{
		if (wasFalling)
		{
			wasFalling = false;
			for (int i = 0, j = 0; i < MAX_PARTICLES && j < 16; i++)
			{
				if (particles[i] == NULL)
				{
					particles[i] = new Particle(gPlayer.plGFXrect.x + (gPlayer.plGFXrect.w / 2), gPlayer.plGFXrect.y + gPlayer.plGFXrect.h - 8,
						DEFAULT_PARTICLE_W, DEFAULT_PARTICLE_H, GREY_PARTICLE);
					j++;
				}
			}
		}
		gPlayer.plIsFalling = 0;
	}

	if (gPlayer.plIsFalling > DEFAULT_GRAVITY_UNITS - 1)
	{
		gPlayer.plIsFalling = DEFAULT_GRAVITY_UNITS - 1;
	}

	// if everything is null, apply gravity to everything in the level
	if (player == NULL && enemy == NULL)
	{
		for (int i = 0; i < DEFAULT_LEVEL_UNITS; i++)
		{
			if (enemies[i] != NULL && enemies[i]->enType != FLY)
			{
				enemyCheckForGround.y = enemies[i]->enHitboxRect.y + defaultGravity[enemies[i]->enIsFalling];
				enemyCheckForGround.x = enemies[i]->enHitboxRect.x;
				enemyCheckForGround.w = enemies[i]->enHitboxRect.w;
				enemyCheckForGround.h = enemies[i]->enHitboxRect.h;
				if (!checkCollision(&enemyCheckForGround, NULL, true, enemies[i]->enType, i) && enemies[i]->enIsJumping < 0)
				{
					enemies[i]->enHitboxRect.y += defaultGravity[enemies[i]->enIsFalling];
				}
				else
				{
					enemyCheckForGround.y = enemies[i]->enHitboxRect.y + 1;
					while (!checkCollision(&enemyCheckForGround, NULL, true, enemies[i]->enType, i) && enemies[i]->enIsJumping < 0)
					{
						enemies[i]->enHitboxRect.y++;
						enemyCheckForGround.y = enemies[i]->enHitboxRect.y + 1;
					}
				}
			}
		}

		/*
		for (int i = 0; i < DEFAULT_LEVEL_UNITS; i++)
		{
			if (collectibles[i] != NULL)
			{
				collectibleCheckForGround.y = collectibles[i]->clRect.y + defaultGravity[collectibles[i]->clIsFalling];
				collectibleCheckForGround.x = collectibles[i]->clRect.x;
				collectibleCheckForGround.w = collectibles[i]->clRect.w;
				collectibleCheckForGround.h = collectibles[i]->clRect.h;
				if (!checkCollision(&collectibleCheckForGround, NULL, true, i))
				{
					collectibles[i]->clRect.y += defaultGravity[collectibles[i]->clIsFalling];
				}
				else
				{
					collectibleCheckForGround.y = collectibles[i]->clRect.y + 1;
					while (!checkCollision(&collectibleCheckForGround, NULL, true, i))
					{
						collectibles[i]->clRect.y++;
						collectibleCheckForGround.y = collectibles[i]->clRect.y + 1;
					}
				}
			}
		}
		*/

		playerCheckForGround.y = gPlayer.plHitboxRect.y + defaultGravity[gPlayer.plIsFalling];
		playerCheckForGround.x = gPlayer.plHitboxRect.x;
		playerCheckForGround.w = gPlayer.plHitboxRect.w;
		playerCheckForGround.h = gPlayer.plHitboxRect.h;
		if (!checkCollision(&playerCheckForGround, NULL, true, PLAYER) && gPlayer.plIsJumping < 0)
		{
			levelMovementsY -= defaultGravity[gPlayer.plIsFalling];
		}
		else
		{
			int a = 0;
			playerCheckForGround.y = gPlayer.plHitboxRect.y;
			while (!checkCollision(&playerCheckForGround, NULL, true, PLAYER) && gPlayer.plIsJumping < 0)
			{
				playerCheckForGround.y++;
				a++;
			}

			// FIX THIS?
			for (int i = 0; i < DEFAULT_LEVEL_UNITS; i++)
			{
				if ((gCollidingPlayer[i] >= DEFAULT_ENEMY && gCollidingPlayer[i] < DEFAULT_COLLECTIBLE))
				{
					nextPos = gPlayer.plHitboxRect;
					nextPos.y -= 4;
					
					if (!checkCollision(&nextPos, &enemies[i]->enHitboxRect))
					{
						enemies[i]->enDie(i, true);
					}

				}
				else if (gCollidingPlayer[i] >= DEFAULT_COLLECTIBLE && gCollidingPlayer[i] < THINGTYPE_MAX)
				{
					collectibles[i]->clCollect(i);
				}
			}

			if (a != 0)
			{
				levelMovementsY -= a - 1;
			}
		}
	}
	// if something isn't null, then apply gravity to only that thing
	else
	{
		if (player != NULL)
		{
			playerCheckForGround.y = player->plHitboxRect.y + defaultGravity[player->plIsFalling];
			if (!checkCollision(&playerCheckForGround, NULL, true, PLAYER))
			{
				player->plHitboxRect.y += defaultGravity[player->plIsFalling];
			}
		}
		else if (enemy != NULL)
		{
			enemyCheckForGround.y = enemy->enHitboxRect.y + defaultGravity[enemy->enIsFalling];
			if (!checkCollision(&enemyCheckForGround, NULL, true, enemy->enType))
			{
				enemy->enHitboxRect.y += defaultGravity[enemy->enIsFalling];
			}
		}
	}
}

void handleMenu(void)
{
	static bool menuSet = false;
	static int whichMenuSet = -1;
	static SDL_Rect mouseRect{ 0, 0, 2, 2 };
	static int whichOption = -1;
	static bool isColliding = false;
	// bool enlargeSet = false;
	// bool reduceSet = false;
	static Uint8 enlargedOrReduced[TOTAL_MENU_OPTIONS];

	for (int i = 1; i < TOTAL_MENU_OPTIONS; i++)
	{
		enlargedOrReduced[i] = 0;
	}

	while (inMenu)
	{
		if (inSubMenu != whichMenuSet)
		{
			for (int i = 0; i < TOTAL_MESSAGES; i++)
			{
				if (textTextures[i] != NULL)
				{
					delete textTextures[i];
					textTextures[i] = NULL;
				}
			}
		}

		for (int i = 1; i < TOTAL_MENU_OPTIONS; i++)
		{
			if (inSubMenu == NO_OPTION && whichMenuSet != NO_OPTION)
			{
				for (int i = NO_OPTION + 1; i <= MENU_TOTAL; i++)
				{
					if (textTextures[i] == NULL)
					{
						textTextures[i] = new Texture();
						textTextures[i]->txRect = menuRects[i];

						SDL_Color textColor = { 200, 200, 200 };
						if (!textTextures[i]->loadT(menuMessages[i], textColor))
						{
							printf("Failed to render text texture!\n");
						}
					}
				}

				whichMenuSet = NO_OPTION;
			}
			else if (inSubMenu == CONFIG && whichMenuSet != CONFIG)
			{
				for (int i = NO_CONFIG_OPTION + 1; i <= CONFIG_MENU_TOTAL; i++)
				{
					if (textTextures[i] == NULL)
					{
						textTextures[i] = new Texture();
						textTextures[i]->txRect = menuRects[i];

						SDL_Color textColor = { 200, 200, 200 };
						if (!textTextures[i]->loadT(menuMessages[i], textColor))
						{
							printf("Failed to render text texture!\n");
						}
					}
				}

				whichMenuSet = CONFIG;
			}
			else if (inSubMenu == HELP && whichMenuSet != HELP)
			{
				for (int i = NO_HELP_OPTION + 1; i <= HELP_MENU_TOTAL; i++)
				{
					if (textTextures[i] == NULL)
					{
						textTextures[i] = new Texture();
						textTextures[i]->txRect = menuRects[i];

						SDL_Color textColor = { 200, 200, 200 };
						if (!textTextures[i]->loadT(menuMessages[i], textColor))
						{
							printf("Failed to render text texture!\n");
						}
					}
				}

				whichMenuSet = HELP;
			}
		}

		if (SDL_PollEvent(&e) != NULL)
		{
			if (e.type == SDL_MOUSEBUTTONUP)
			{
				SDL_GetMouseState(&mouseRect.x, &mouseRect.y);

				for (int i = 1; i < TOTAL_MENU_OPTIONS; i++)
				{
					if (textTextures[i] != NULL)
					{
						if (checkCollision(&mouseRect, &textTextures[i]->txRect))
						{
							if (inSubMenu == NO_OPTION && whichMenuSet == NO_OPTION)
							{
								switch (i)
								{
								case RESUME:
									// resume
									inMenu = false;
									break;
								case CONFIG:
									// config
									inSubMenu = CONFIG;
									enlargedOrReduced[i] = 0;
									break;
								case HELP:
									// help
									inSubMenu = HELP;
									enlargedOrReduced[i] = 0;
									break;
								case EXIT:
									// exit
									inMenu = false;
									quit = true;
									break;
								}
							}
							else if (inSubMenu == CONFIG && whichMenuSet == CONFIG)
							{
								switch (i)
								{
								case CONFIGURE_SOMETHING:
									std::cout << "well ok one" << std::endl;
									break;
								case CONFIGURE_SOMETHING_ELSE:
									std::cout << "well ok two" << std::endl;
									break;
								case CONFIG_RETURN:
									inSubMenu = NO_OPTION;
									enlargedOrReduced[i] = 0;
									break;
								}
							}
							else if (inSubMenu == HELP && whichMenuSet == HELP)
							{
								switch (i)
								{
								case HELP_WITH_THIS_THING:
									std::cout << "I don't wanna help" << std::endl;
									break;
								case HELP_WITH_THIS_OTHER_THING:
									std::cout << "I don't wanna help with this either" << std::endl;
									break;
								case HELP_RETURN:
									inSubMenu = NO_OPTION;
									enlargedOrReduced[i] = 0;
									break;
								}
							}
						}
					}
				}
			}
			else if (e.type == SDL_MOUSEMOTION)
			{
				SDL_GetMouseState(&mouseRect.x, &mouseRect.y);

				for (int i = 0; i < TOTAL_MENU_OPTIONS; i++)
				{
					if (textTextures[i] != NULL)
					{
						isColliding = checkCollision(&mouseRect, &textTextures[i]->txRect);

						if (isColliding && enlargedOrReduced[i] != 1)
						{
							textTextures[i]->txRect.w *= 1.5;
							textTextures[i]->txRect.h *= 1.2;
							enlargedOrReduced[i] = 1;
						}
						else if (!isColliding && enlargedOrReduced[i] == 1)
						{
							textTextures[i]->txRect.w /= 1.5;
							textTextures[i]->txRect.h /= 1.2;
							enlargedOrReduced[i] = 0;
						}
					}
				}
			}
			else
			{
				gPlayer.plHandleEvent(&e);
			}
		}

		menuTexture.txRender();

		for (int i = 0; i < TOTAL_MENU_OPTIONS; i++)
		{
			if (textTextures[i] != NULL)
			{
				textTextures[i]->txRender();
			}
		}

		SDL_RenderPresent(gRenderer);
	}
}

///

Texture::Texture(int passedX, int passedY, int passedW, int passedH)
{
	// set properties
	txRect.x = passedX;
	txRect.y = passedY;
	txRect.w = passedW;
	txRect.h = passedH;
}

Texture::~Texture()
{
	// free everything
	txFree();
}

void Texture::txColor(Uint8 r, Uint8 g, Uint8 b)
{
	// set colors to the texture
	SDL_SetTextureColorMod(txTexture, r, g, b);
}

void Texture::txBlend(SDL_BlendMode b)
{
	// set the blend mode
	SDL_SetTextureBlendMode(txTexture, b);
}

void Texture::txAlpha(Uint8 a)
{
	// set alpha to the texture
	SDL_SetTextureAlphaMod(txTexture, a);
}

bool Texture::txLoadF(std::string path)
{
	// keeps track of whether a failure occurred
	bool success = true;

	// free the current texture (if it exists)
	txFree();

	// the texture that we will (hopefully) end up with
	SDL_Texture* createdTexture = NULL;

	// the surface that the texture's image will be loaded onto
	SDL_Surface* imageSurface = IMG_Load(path.c_str());

	if (imageSurface == NULL)
	{
		// output a message if the surface failed to load
		printf("Error loading image at the specified path: %s\n", path);
		printf("IMG_GetError: %s\n", IMG_GetError());
		success = false;
	}
	else
	{
		// set the color key
		SDL_SetColorKey(imageSurface, SDL_TRUE, SDL_MapRGB(imageSurface->format, 0, 255, 255));

		// create the texture itself from the surface
		createdTexture = SDL_CreateTextureFromSurface(gRenderer, imageSurface);

		if (createdTexture == NULL)
		{
			// output an error
			printf("Error creating texture from surface.  SDL_GetError: %s\n", SDL_GetError());
		}
		else
		{
			if (txRect.w == NULL || txRect.h == NULL)
			{
				txRect.w = imageSurface->w;
				txRect.h = imageSurface->h;
			}
		}
	}

	// the surface isn't needed anymore
	SDL_FreeSurface(imageSurface);

	// make the texture member point to the newly created texture
	txTexture = createdTexture;

	// return whether everything ran successfully or not
	return success;
}

// uh UHHH
#ifdef _SDL_TTF_H
bool Texture::loadT(std::string text, SDL_Color color)
{
	//Get rid of preexisting texture
	txFree();

	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, text.c_str(), color);
	if (textSurface != NULL)
	{
		//Create texture from surface pixels
		txTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
		if (txTexture == NULL)
		{
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			if (txRect.w == NULL || txRect.h == NULL)
			{
				txRect.w = textSurface->w;
				txRect.h = textSurface->h;
			}
		}

		//Get rid of old surface
		SDL_FreeSurface(textSurface);
	}
	else
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}

	//Return success
	return txTexture != NULL;
}
#endif

void Texture::txRender(SDL_Rect *clip, SDL_Point *center,
	double rotation, SDL_RendererFlip flip)
{
	// rect to render to
	SDL_Rect renderRect{ txRect.x, txRect.y, txRect.w, txRect.h };

	// if clip is given, set properties
	if (clip != NULL)
	{
		renderRect.w = clip->w;
		renderRect.h = clip->h;
	}

	// render to the screen
	SDL_RenderCopyEx(gRenderer, txTexture, clip, &renderRect, rotation, center, flip);
}

void Texture::txFree()
{
	// destroy the texture
	if (txTexture != NULL)
	{
		SDL_DestroyTexture(txTexture);
	}
}

Player::Player(int passedX, int passedY, int passedW, int passedH)
{
	// set properties
	plGFXrect.x = passedX;
	plGFXrect.y = passedY;
	plGFXrect.w = passedW;
	plGFXrect.h = passedH;

	plHitboxRect.x = passedX + 10;
	plHitboxRect.y = passedY + 12;
	plHitboxRect.w = passedW - 20;
	plHitboxRect.h = passedH - 20;

	/* plTexture->txTexture = playerTexture.txTexture;

	// sync the texture properties
	plTexture->txRect.w = passedW;
	plTexture->txRect.h = passedH;
	plSyncTexture();

	plTexture->txRender(); */
}

Player::~Player()
{
	/*// destroy texture
	plTexture->txFree();*/
}

void Player::plSyncTexture(void)
{
	plGFXrect.x = plHitboxRect.x - 10;
	plGFXrect.y = plHitboxRect.y - 12;
	plGFXrect.w = plHitboxRect.w + 20;
	plGFXrect.h = plHitboxRect.h + 20;
}

void Player::plJump(void)
{
	SDL_Rect nextPos{ plHitboxRect.x, plHitboxRect.y, plHitboxRect.w, plHitboxRect.h };
	nextPos.y -= jumpArray[plIsJumping];
	int oldPlIsJumping = plIsJumping;
	bool collected = false;
	if (!checkCollision(&nextPos, NULL, true, PLAYER))
	{
		if (plIsJumping >= 0)
		{
			levelMovementsY += jumpArray[plIsJumping];
		}
		else
		{
			nextPos = plHitboxRect;
			nextPos.y++;
			if (checkCollision(&nextPos, NULL, true, PLAYER))
			{
				plIsJumping++;
				plHitboxRect.y -= jumpArray[plIsJumping];
			}
		}
	}
	else
	{
		for (int i = 0; i < DEFAULT_LEVEL_UNITS; i++)
		{
			if (gCollidingPlayer[i] >= DEFAULT_ENEMY && gCollidingPlayer[i] < DEFAULT_COLLECTIBLE)
			{
				gPlayer.plHealth -= 2;
				gPlayer.plIsJumping = oldPlIsJumping;
			}
			else if (gCollidingPlayer[i] >= DEFAULT_COLLECTIBLE && gCollidingPlayer[i] < THINGTYPE_MAX)
			{
				collectibles[i]->clCollect(i);
				collected = true;
			}
		}

		if (!collected)
		{
			nextPos.y += jumpArray[plIsJumping];
			nextPos.y--;
			int a = 1;
			while (!checkCollision(&nextPos, NULL, true, PLAYER))
			{
				nextPos.y--;
				a++;
			}
			levelMovementsY += a + 1;

			plIsJumping = -1;
		}

		return;
	}
}

/*
void Player::plJump(void)
{
	if (!checkCollisionWithCeiling(&plRect))
	{
		if (plIsJumping >= 0)
		{
			SDL_Rect nextPos{ plRect.x, plRect.y, plRect.w, plRect.h };
			nextPos.y -= jumpArray[plIsJumping];

			if (checkCollision(&nextPos, NULL))
			{
				nextPos.y += jumpArray[plIsJumping];
				nextPos.y--;
				while (!checkCollision(&nextPos, NULL))
				{
					nextPos.y--;
				}
				plRect.y = nextPos.y - 4;
				plIsJumping = -1;
				return;
			}
			else
			{
				plRect.y -= jumpArray[plIsJumping];
			}
		}
		else
		{
			if (checkCollisionWithGround(&plRect))
			{
				plIsJumping++;
				plRect.y -= jumpArray[plIsJumping];
			}
		}
	}
	else
	{
		plIsJumping = -1;
	}
}
*/

bool Player::plHandleEvent(SDL_Event* e)
{
	if (e->type == SDL_KEYDOWN && e->key.repeat == NULL)
	{
		keyIsDown = true;
	}
	if (e->type == SDL_KEYUP && e->key.repeat == NULL)
	{
		keyIsDown = false;
		initializedFrame = false;
		framesCycled = false;

		switch (e->key.keysym.sym)
		{
		case SDLK_d: 
			plSpeed = 0; 
			levelIsScrollingHorizontal = false; 
			break;
		case SDLK_a: 
			plSpeed = 0; 
			levelIsScrollingHorizontal = false; 
			break;
		case SDLK_s: inSign = false; 
			break;
		case SDLK_w:
			if (plIsJumping <= JUMP_ARRAY_UNITS - 4 && plIsJumping > 0)
			{
				plIsJumping = JUMP_ARRAY_UNITS - 4;
			}
			break;
		case SDLK_LEFT:
			directionKey = NO_DIRECTION;
			break;
		case SDLK_RIGHT:
			directionKey = NO_DIRECTION;
			break;
		case SDLK_UP:
			directionKey = NO_DIRECTION;
			break;
		case SDLK_DOWN:
			directionKey = NO_DIRECTION;
			break;
		case SDLK_LSHIFT:
			shiftDown = false;
			break;
		}
	}

	if (keyIsDown && e->key.repeat == NULL)
	{
		SDL_Rect prevPos{ plHitboxRect.x - plSpeed, plHitboxRect.y, plHitboxRect.w, plHitboxRect.h };
		switch (e->key.keysym.sym)
		{
		case SDLK_d:
			// if (!checkCollision(&gPlayer.plHitboxRect, NULL, true, PLAYER))
			// {
				plSpeed = 4;
				levelIsScrollingHorizontal = true;
			// }
			break;
		case SDLK_a:
			// if (!checkCollision(&gPlayer.plHitboxRect, NULL, true, PLAYER))
			// {
				plSpeed = -4;
				levelIsScrollingHorizontal = true;
			// }
			break;
			/*
			case SDLK_d:
			isColliding = checkCollision(&gPlayer.plHitboxRect, NULL, true, PLAYER);

			if (isColliding)
			{
			for (int i = 0; i < DEFAULT_LEVEL_UNITS; i++)
			{
			if (gCollidingPlayer[i] != NULL && gCollidingPlayer[i] >= DEFAULT_BLOCK && gCollidingPlayer[i] < DEFAULT_ENEMY)
			{
			isCollidingWithBlock = true;
			break;
			}
			}
			}

			if (!isCollidingWithBlock)
			{
			plSpeed = 4;
			levelIsScrollingHorizontal = true;
			}
			break;
			case SDLK_a:
			isColliding = checkCollision(&gPlayer.plHitboxRect, NULL, true, PLAYER);

			if (isColliding)
			{
			for (int i = 0; i < DEFAULT_LEVEL_UNITS; i++)
			{
			if (gCollidingPlayer[i] != NULL && gCollidingPlayer[i] >= DEFAULT_BLOCK && gCollidingPlayer[i] < DEFAULT_ENEMY)
			{
			isCollidingWithBlock = true;
			break;
			}
			}
			}

			if (!isCollidingWithBlock)
			{
			plSpeed = -4;
			levelIsScrollingHorizontal = true;
			}
			break;
			*/
		case SDLK_s:
			if (checkForSign(&gPlayer.plHitboxRect))
			{
				inSign = true;
			}
			break;
		case SDLK_w:
			prevPos.y++;
			if (checkCollision(&prevPos, NULL, true, PLAYER))
			{
				plIsJumping = 0;
			}
			break;
		case SDLK_LEFT:
			directionKey = LEFT;
			break;
		case SDLK_RIGHT:
			directionKey = RIGHT;
			break;
		case SDLK_UP:
			directionKey = UP;
			break;
		case SDLK_DOWN:
			directionKey = DOWN;
			break;
		case SDLK_LSHIFT:
			shiftDown = true;
			break;
		case SDLK_p:
			if (!inMenu)
			{
				inMenu = true;
			}
			else
			{
				inMenu = false;
			}
			break;
		}
	}
	else
	{
		directionKey = NO_DIRECTION;
	}

	/*
	if (gPlayer.plRect.x >= DEFAULT_LEVEL_W - gPlayer.plRect.w || gPlayer.plRect.x <= 0 ||
		gPlayer.plRect.y >= DEFAULT_LEVEL_H - gPlayer.plRect.h || gPlayer.plRect.y <= 0)
	{
		gPlayer.plSpeed = 0;
	}
	*/

	if (shiftDown && directionKey != NO_DIRECTION && (bulletShootWaitCounter % 256 == 1 || canShoot))
	{
		canShoot = false;
		plShoot(directionKey);
	}
	else if (!shiftDown || !directionKey)
	{
		canShoot = true;
	}

	if (bulletShootWaitCounter % 256 == 1)
	{
		bulletShootWaitCounter = 0;
	}
	else
	{
		bulletShootWaitCounter++;
	}

	if (!shiftDown && directionKey != NO_DIRECTION)
	{
		plMelee(directionKey);
		canMelee++;
	}
	else if (canMelee >= 0 && canMelee <= 4)
	{
		canMelee++;
	}
	else
	{
		canMelee = -1;
	}

	return true;
}

// moves the player and checks collision (takes a moveType, or NULL if the direction is built in to the speed)
void Player::plMove(int movement)
{
	int nextMove = plSpeed;
	bool collected = false;
	bool isColliding = false;
	bool collidedWithEnemy = false;
	bool collidedWithBlock = false;
	bool shouldScroll = false;
	SDL_Rect nextPos{ plHitboxRect.x, plHitboxRect.y, plHitboxRect.w, plHitboxRect.h };
	bool increaseFrameCounter = true;

	switch (movement)
	{

		/*
	case RIGHT: 
		
		if (!levelIsScrollingHorizontal)
		{
			nextPos.x += plSpeed;
		}

		if (plCurrentFrame == WALK_RIGHT_1)
			plCurrentFrame = WALK_RIGHT_2;
		else if (plCurrentFrame == WALK_RIGHT_2)
			plCurrentFrame = WALK_RIGHT_1;
		else
			plCurrentFrame = WALK_RIGHT_1;
		break;

	case LEFT: 
		
		if (!levelIsScrollingHorizontal)
		{
			nextPos.x -= plSpeed;
		}

		if (plCurrentFrame == WALK_LEFT_1)
			plCurrentFrame = WALK_LEFT_2;
		else if (plCurrentFrame == WALK_LEFT_2)
			plCurrentFrame = WALK_LEFT_1;
		else
			plCurrentFrame = WALK_LEFT_1;
		break;
		*/

	case NULL: 

			nextPos.x += plSpeed;
			isColliding = checkCollision(&nextPos, NULL, true, PLAYER);

			for (int i = 0; i < DEFAULT_LEVEL_UNITS; i++)
			{
				if (gCollidingPlayer[i] >= DEFAULT_BLOCK && gCollidingPlayer[i] < DEFAULT_ENEMY)
				{
					collidedWithBlock = true;
				}
				if (gCollidingPlayer[i] >= DEFAULT_ENEMY && gCollidingPlayer[i] < DEFAULT_COLLECTIBLE)
				{
					gPlayer.plHealth -= 2;
					gPlayer.plSpeed = 0;
					collidedWithEnemy = true;
				}
				else if (gCollidingPlayer[i] >= DEFAULT_COLLECTIBLE && gCollidingPlayer[i] < THINGTYPE_MAX)
				{
					collectibles[i]->clCollect(i);
					collected = true;
				}
			}

			/*
			for (int i = 0; i < DEFAULT_LEVEL_UNITS; i++)
			{
				if (gCollidingPlayer[i] >= DEFAULT_ENEMY && gCollidingPlayer[i] < DEFAULT_COLLECTIBLE)
				{
					// uh
				}
			}
			*/

			if (isColliding && !collidedWithEnemy)
			{
				nextPos.x -= plSpeed;

				while (!checkCollision(&nextPos, NULL, true, PLAYER))
				{
					nextPos.x += (plSpeed > 0 ? 1 : -1);
					nextMove--;
				}
				nextPos.x += nextMove;

				nextPos.x += plSpeed;
			}
			else if (isColliding && (collidedWithEnemy && !collidedWithBlock))
			{
				shouldScroll = true;
			}
			else
			{
				nextPos.x -= plSpeed;
			}


		/*
		if (plSpeed < 0)
		{
			nextPos.x -= 4;
			isColliding = checkCollision(&nextPos, NULL, true, PLAYER);

			for (int i = 0; i < DEFAULT_LEVEL_UNITS; i++)
			{
				if (gCollidingPlayer[i] >= DEFAULT_ENEMY && gCollidingPlayer[i] < DEFAULT_COLLECTIBLE)
				{
					gPlayer.plHealth -= 2;
					collidedWithEnemy = true;
				}
				else if (gCollidingPlayer[i] >= DEFAULT_COLLECTIBLE && gCollidingPlayer[i] < THINGTYPE_MAX)
				{
					collectibles[i]->clCollect(i);
					collected = true;
				}
			}

			/*
			for (int i = 0; i < DEFAULT_LEVEL_UNITS; i++)
			{
				if (gCollidingPlayer[i] >= DEFAULT_ENEMY && gCollidingPlayer[i] < DEFAULT_COLLECTIBLE)
				{
					// uh
				}
			}
			

			if (isColliding && !collidedWithEnemy)
			{
				nextPos.x += 4;

				while (!checkCollision(&nextPos, NULL, true, PLAYER))
				{
					nextPos.x--;
					nextMove++;
				}
				nextPos.x -= nextMove;

				nextPos.x += 4;
			}
			else if (isColliding && collidedWithEnemy)
			{
				shouldScroll = true;
			}
			else
			{
				nextPos.x += 4;
			}
		}
		*/

		if (plSpeed == 0 && plIsJumping < 0 && plIsFalling <= 0)
		{
			plFrameWaitCounter = 0;
		}

		if ((levelIsScrollingHorizontal && !isColliding) || shouldScroll)
		{
			levelMovementsX -= nextMove;
		}

		/*
		if (!collected)
		{
			nextPos.x = plHitboxRect.x - 2;
			nextPos.y = plHitboxRect.y - 2;
			nextPos.w = plHitboxRect.w + 4;
			nextPos.h = plHitboxRect.h + 4;
			if (checkCollision(&nextPos, NULL, true, PLAYER))
			{
				for (int i = 0; i < DEFAULT_LEVEL_UNITS; i++)
				{
					if (gCollidingPlayer[i] >= DEFAULT_COLLECTIBLE && gCollidingPlayer[i] < THINGTYPE_MAX)
					{
						collectibles[i]->clCollect(i);
					}
				}
			}

			/*
			for (int i = 0; i < DEFAULT_LEVEL_UNITS; i++)
			{
				if (collectibles[i] != NULL)
				{
					nextPos.x = plHitboxRect.x - 2;
					nextPos.y = plHitboxRect.y - 2;
					nextPos.w = plHitboxRect.w;
					nextPos.h = plHitboxRect.h;

					if (checkCollision(&nextPos, &collectibles[i]->clRect))
					{
						collectibles[i]->clCollect(i);
					}
					else
					{
						nextPos.x = plHitboxRect.x + 2;
						if (checkCollision(&nextPos, &collectibles[i]->clRect))
						{
							collectibles[i]->clCollect(i);
						}
						
					}
				}
			}
			

		}
		*/
	}

	/*
	checkCollision(&plRect, NULL);
	for (int i = 0; i < DEFAULT_LEVEL_UNITS; i++)
	{
		if (gColliding[i] == ENEMY)
		{
			std::cout << "eee" << std::endl;
			plRect.y += 2; plRect.x += 2; plRect.w -= 2;
			if (checkCollision(&plRect, NULL, false) && gColliding[i] == ENEMY)
			{
				plRect.y -= 2; plRect.x -= 2; plRect.w += 2;
				delete enemies[i];
				enemies[i] = NULL;
				gPlayer.plIsJumping = 0;
				std::cout << "enemy die" << std::endl;
				break;
			}
			else
			{
				plRect.y -= 2; plRect.x -= 2; plRect.w += 2;
				std::cout << "uh" << std::endl;
				break;
			}
		}
	}
	*/
}

/*
void Player::plMove(int movement)
{
	SDL_Rect previousPos{ plRect.x, plRect.y, DEFAULT_PLAYER_W, DEFAULT_PLAYER_H };
	SDL_Rect nextPos{ plRect.x, plRect.y, DEFAULT_PLAYER_W, DEFAULT_PLAYER_H };

	switch (movement)
	{
	case RIGHT: 
		
		if (!levelIsScrollingHorizontal)
		{
			nextPos.x += plSpeed;
		}

		if (plCurrentFrame == WALK_RIGHT_1)
			plCurrentFrame = WALK_RIGHT_2;
		else if (plCurrentFrame == WALK_RIGHT_2)
			plCurrentFrame = WALK_RIGHT_1;
		else
			plCurrentFrame = WALK_RIGHT_1;
		break;

	case LEFT: 
		
		if (!levelIsScrollingHorizontal)
		{
			nextPos.x -= plSpeed;
		}

		if (plCurrentFrame == WALK_LEFT_1)
			plCurrentFrame = WALK_LEFT_2;
		else if (plCurrentFrame == WALK_LEFT_2)
			plCurrentFrame = WALK_LEFT_1;
		else
			plCurrentFrame = WALK_LEFT_1;
		break;

	case NULL: 
		
		if (!levelIsScrollingHorizontal)
		{
			nextPos.x += plSpeed;
		}

		if (plSpeed < 0)
		{
			if (plCurrentFrame == WALK_LEFT_1)
				plCurrentFrame = WALK_LEFT_2;
			else if (plCurrentFrame == WALK_LEFT_2)
				plCurrentFrame = WALK_LEFT_1;
			else
				plCurrentFrame = WALK_LEFT_1;
		} 
		else if (plSpeed > 0)
		{
			if (plCurrentFrame == WALK_RIGHT_1)
				plCurrentFrame = WALK_RIGHT_2;
			else if (plCurrentFrame == WALK_RIGHT_2)
				plCurrentFrame = WALK_RIGHT_1;
			else
				plCurrentFrame = WALK_RIGHT_1;
		}
		else 
		{
			plCurrentFrame = IDLE_1;
		} break;
	}

	if (checkCollision(&nextPos, NULL))
	{
		if (plSpeed < 0)
		{
			nextPos.x = gPlayer.plRect.x - 1;
			while (!checkCollision(&nextPos, NULL))
			{
				plRect.x = nextPos.x;
				nextPos.x--;
			}
		}
		else if (plSpeed > 0)
		{
			nextPos.x = gPlayer.plRect.x + 1;
			while (!checkCollision(&nextPos, NULL))
			{
				plRect.x = nextPos.x;
				nextPos.x++;
			}
		}
		else
		{
			plCurrentFrame = IDLE_1;
		}

		for (int i = 0; i < DEFAULT_LEVEL_UNITS; i++)
		{
			if (gColliding[i] == BLOCK)
			{
				// uh
			}
			else if (gColliding[i] == ENEMY)
			{
				plRect.x = 2;
				plRect.y = 2;
			}
			else
			{
				// uh
			}
		}
	}
	else
	{
		plRect.x = nextPos.x;
	}
}
*/

void Player::plShoot(Direction dir)
{
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		if (bullets[i] == NULL)
		{
			bullets[i] = new Bullet(NULL, NULL, NULL, NULL, dir, -1);
			break;
		}
	}
}

void Player::plMelee(Direction dir)
{
	for (int i = 0; i < MAX_MELEE; i++)
	{
		if (weapons[i] == NULL)
		{
			weapons[i] = new Melee(NULL, NULL, NULL, NULL, dir, -1);
			break;
		}
	}
}

Block::Block(int passedX, int passedY, int passedW, int passedH, int type)
{
	blRect.x = passedX;
	blRect.y = passedY;
	blRect.w = passedW;
	blRect.h = passedH;
	blType = type;

	/*blTexture->txTexture = blockTexture.txTexture;

	blTexture->txRect.w = passedW;
	blTexture->txRect.h = passedH;
	blTexture->txRect.x = passedX;
	blTexture->txRect.y = passedY;

	blTexture->txRender();*/
}

void Block::blUpdate(void)
{
	/* uh
	blockTexture.txRect.x = blRect.x;
	blockTexture.txRect.y = blRect.y;
	blockTexture.txRect.w = blRect.w;
	blockTexture.txRect.h = blRect.h;
	*/
}

void Block::blRender(void)
{
	int type = blType - 10;
	blockTextures[type]->txRect = blRect;

	blockTextures[type]->txRender();
}

void Sign::snRender(void)
{
	signTexture.txRect = snRect;

	signTexture.txRender();
}

Block::~Block()
{
	// destroy the texture
	/*blTexture->txFree();*/
}

Background::Background(int passedX, int passedY, int passedW, int passedH)
{
	bgRect.x = passedX;
	bgRect.y = passedY;
	bgRect.w = passedW;
	bgRect.h = passedH;
}

void Background::bgRender(void)
{
	bgTexture.txRect.x = bgRect.x;
	bgTexture.txRect.y = bgRect.y;
	bgTexture.txRect.w = bgRect.w + DEFAULT_W*2;
	bgTexture.txRect.h = bgRect.h + DEFAULT_H*2;

	bgTexture.txRender();
}

void Background::bgUpdate(void)
{
	bgTexture.txRect.x = bgRect.x;
	bgTexture.txRect.y = bgRect.y;
	bgTexture.txRect.w = bgRect.w + DEFAULT_W*2;
	bgTexture.txRect.h = bgRect.h + DEFAULT_H*2;

	switch (bgType)
	{
	case DEFAULT_BG:
		bgTexture.txLoadF("resources/bg.png");
		break;
	}
}

Enemy::Enemy(int passedX, int passedY, int passedW, int passedH, int type)
{
	if (type == DEFAULT_ENEMY || type == FLY || type == BASIC_ENEMY)
	{
		enGFXrect.x = passedX - 4;
		enGFXrect.y = passedY - 4;
		enGFXrect.w = passedW + 8;
		enGFXrect.h = passedH + 8;
	}

	enHitboxRect.x = passedX + 2;
	enHitboxRect.y = passedY + 2;
	enHitboxRect.w = passedW - 4;
	enHitboxRect.h = passedH - 2;

	enType = type;

	/*enTexture->txTexture = enemyTexture.txTexture;

	enTexture->txRect.w = passedW;
	enTexture->txRect.h = passedH;

	enSyncTexture();
	enTexture->txRender();*/
}

Enemy::~Enemy()
{
	// destroy texture
	/*enTexture->txFree();*/
}

void Enemy::enUpdate(void)
{
	/*
	switch (enType)
	{
	case DEFAULT_ENEMY:
		for (int i = 0; i < TOTAL_FRAMES; i++)
		{
			defaultEnemyTextures[i].txRect.w = DEFAULT_W;
			defaultEnemyTextures[i].txRect.h = DEFAULT_H;

			switch (i)
			{
			case NO_GFX: break;
			case IDLE_1: playerTextures[i].txLoadF("resources/plIdle1.png");
				defaultEnemyTextures[i].txLoadF("resources/enemy.png"); break;
			case IDLE_2: playerTextures[i].txLoadF("resources/plIdle1.png");
				defaultEnemyTextures[i].txLoadF("resources/enemy.png"); break;
			case WALK_LEFT_1: playerTextures[i].txLoadF("resources/plWalkLeft1.png");
				defaultEnemyTextures[i].txLoadF("resources/enemy.png"); break;
			case WALK_LEFT_2: playerTextures[i].txLoadF("resources/plWalkLeft2.png");
				defaultEnemyTextures[i].txLoadF("resources/enemy.png"); break;
			case WALK_RIGHT_1: playerTextures[i].txLoadF("resources/plWalkRight1.png");
				defaultEnemyTextures[i].txLoadF("resources/enemy.png"); break;
			case WALK_RIGHT_2: playerTextures[i].txLoadF("resources/plWalkRight2.png");
				defaultEnemyTextures[i].txLoadF("resources/enemy.png"); break;
			case FALLING: playerTextures[i].txLoadF("resources/plIdle1.png");
				defaultEnemyTextures[i].txLoadF("resources/enemy.png"); break;
			case JUMPING: playerTextures[i].txLoadF("resources/plIdle1.png");
				defaultEnemyTextures[i].txLoadF("resources/enemy.png"); break;
			case TOTAL_FRAMES: break;
			}
		}
		break;
	case BASIC_ENEMY:
		for (int i = 0; i < TOTAL_FRAMES; i++)
		{
			playerTextures[i].txRect.w = DEFAULT_PLAYER_W;
			playerTextures[i].txRect.h = DEFAULT_PLAYER_H;
			defaultEnemyTextures[i].txRect.w = DEFAULT_W;
			defaultEnemyTextures[i].txRect.h = DEFAULT_H;

			switch (i)
			{
			case NO_GFX: break;
			case IDLE_1: playerTextures[i].txLoadF("resources/plIdle1.png");
				defaultEnemyTextures[i].txLoadF("resources/basic_enemy.png"); break;
			case IDLE_2: playerTextures[i].txLoadF("resources/plIdle1.png");
				defaultEnemyTextures[i].txLoadF("resources/basic_enemy.png"); break;
			case WALK_LEFT_1: playerTextures[i].txLoadF("resources/plWalkLeft1.png");
				defaultEnemyTextures[i].txLoadF("resources/basic_enemy.png"); break;
			case WALK_LEFT_2: playerTextures[i].txLoadF("resources/plWalkLeft2.png");
				defaultEnemyTextures[i].txLoadF("resources/basic_enemy.png"); break;
			case WALK_RIGHT_1: playerTextures[i].txLoadF("resources/plWalkRight1.png");
				defaultEnemyTextures[i].txLoadF("resources/basic_enemy.png"); break;
			case WALK_RIGHT_2: playerTextures[i].txLoadF("resources/plWalkRight2.png");
				defaultEnemyTextures[i].txLoadF("resources/basic_enemy.png"); break;
			case FALLING: playerTextures[i].txLoadF("resources/plIdle1.png");
				defaultEnemyTextures[i].txLoadF("resources/basic_enemy.png"); break;
			case JUMPING: playerTextures[i].txLoadF("resources/plIdle1.png");
				defaultEnemyTextures[i].txLoadF("resources/basic_enemy.png"); break;
			case TOTAL_FRAMES: break;
			}
		}
		break;
	}
	*/
}

void Enemy::enDie(int enemyNum, bool needToJump)
{
	delete enemies[enemyNum];
	enemies[enemyNum] = NULL;

	if (needToJump)
	{
		gPlayer.plIsJumping = 0;
	}
}

void Enemy::enSyncTexture(void)
{
	if (enType == DEFAULT_ENEMY || enType == FLY || enType == BASIC_ENEMY)
	{
		enGFXrect.x = enHitboxRect.x - 6;
		enGFXrect.y = enHitboxRect.y - 6;
		enGFXrect.w = enHitboxRect.w + 12;
		enGFXrect.h = enHitboxRect.h + 10;
	}
	else
	{
		enGFXrect.x = enHitboxRect.x - 2;
		enGFXrect.y = enHitboxRect.y - 2;
		enGFXrect.w = enHitboxRect.w + 4;
		enGFXrect.h = enHitboxRect.h + 2;
	}
}

void Enemy::enRender(void)
{
	if (enType == FLY && enSpeed < 0)
	{
		if (enFrameWaitCounter >= 0 && enFrameWaitCounter < 4)
			enCurrentFrame = JUMPING_1;
		else if (enFrameWaitCounter >= 4)
			enCurrentFrame = JUMPING_2;
	}
	else if (enType == FLY && enSpeed > 0)
	{
		if (enFrameWaitCounter >= 0 && enFrameWaitCounter < 4)
			enCurrentFrame = FALLING_1;
		else if (enFrameWaitCounter >= 4)
			enCurrentFrame = FALLING_2;
	}
	else if (enSpeed < 0 && enIsJumping < 0 && enIsFalling <= 0 && enType != FLY)
	{
		if (enFrameWaitCounter >= 0 && enFrameWaitCounter < 4)
			enCurrentFrame = WALK_LEFT_2;
		else if (enFrameWaitCounter >= 4)
			enCurrentFrame = WALK_LEFT_1;
	}
	else if (enSpeed > 0 && enIsJumping < 0 && enIsFalling <= 0 && enType != FLY)
	{
		if (enFrameWaitCounter >= 0 && enFrameWaitCounter < 4)
			enCurrentFrame = WALK_RIGHT_2;
		else if (enFrameWaitCounter >= 4)
			enCurrentFrame = WALK_RIGHT_1;
	}
	else if (enIsFalling > 0 && enType != FLY)
	{
		enCurrentFrame = FALLING_1;
	}
	else if (enIsJumping >= 0 && enType != FLY)
	{
		enCurrentFrame = JUMPING_1;
	}
	else
	{
		enCurrentFrame = IDLE_1;
	}

	int type = enType - 40;

	defaultEnemyTextures[enCurrentFrame][type].txRect = enGFXrect;

	defaultEnemyTextures[enCurrentFrame][type].txRender();

	if (enFrameWaitCounter != 8)
	{
		enFrameWaitCounter++;
	}
	else if (enFrameWaitCounter == 8)
	{
		enFrameWaitCounter = 0;
	}
}

void Enemy::enJump(int enemyNum = NULL)
{
	SDL_Rect nextPos{ enHitboxRect.x, enHitboxRect.y, enHitboxRect.w, enHitboxRect.h };
	nextPos.y -= enemyJumpArray[enIsJumping];
	SDL_Rect ceilingGroundCheck{ enHitboxRect.x, enHitboxRect.y, enHitboxRect.w, enHitboxRect.h };
	ceilingGroundCheck.y--;
	if (!checkCollision(&ceilingGroundCheck, NULL, true, enType, enemyNum))
	{
		if (enIsJumping >= 0)
		{
			if (checkCollision(&nextPos, NULL, true, enType, enemyNum))
			{
				nextPos.y += enemyJumpArray[enIsJumping];
				nextPos.y--;
				int a = 1;
				while (!checkCollision(&nextPos, NULL, true, enType, enemyNum))
				{
					nextPos.y--;
					a++;
				}
				enHitboxRect.y -= a + 4;
				enIsJumping = -1;
				return;
			}
			else
			{
				enHitboxRect.y -= enemyJumpArray[enIsJumping];
				enIsJumping++;
			}
		}
		else
		{
			ceilingGroundCheck.y = enHitboxRect.y + 1;
			if (checkCollision(&ceilingGroundCheck, NULL, true, enType, enemyNum))
			{
				enIsJumping++;
				enHitboxRect.y -= enemyJumpArray[enIsJumping];
			}
		}
	}
	else
	{
		enIsJumping = -1;
	}

	/*
	if (checkCollision(&nextPos, &gPlayer.plHitboxRect, false, NULL))
	{
		enDie(enemyNum);
	}
	*/
}

void applyEnemyAI(void)
{
	SDL_Rect nextPos;
	SDL_Rect groundCheck;
	int enIsFlying = NULL;
	bool collided = false;
	bool assigned = false;

	for (int i = 0; i < DEFAULT_LEVEL_UNITS; i++)
	{
		if (enemies[i] != NULL)
		{
			switch (enemies[i]->enType)
			{
			case DEFAULT_ENEMY:
				nextPos = enemies[i]->enHitboxRect;
				if (enemies[i]->enSpeed > 0)
				{
					nextPos.x = enemies[i]->enHitboxRect.x + enemies[i]->enHitboxRect.w + DEFAULT_W;
				}
				else if (enemies[i]->enSpeed < 0)
				{
					nextPos.x = enemies[i]->enHitboxRect.x - DEFAULT_W;
				}

				groundCheck = enemies[i]->enHitboxRect;
				groundCheck.y++;

				if (checkCollision(&nextPos, NULL, true, enemies[i]->enType, i) &&  
					checkCollision(&groundCheck, NULL, true, enemies[i]->enType, i))
				{
					nextPos.y -= DEFAULT_H * 3;
					if (!checkCollision(&nextPos, NULL, true, enemies[i]->enType, i))
					{
						if (enemies[i]->enIsJumping < 0)
						{
							enemies[i]->enIsJumping++;
						}
					}
				}

				nextPos.x = enemies[i]->enHitboxRect.x + enemies[i]->enSpeed;
				nextPos.y = enemies[i]->enHitboxRect.y;
				if (checkCollision(&nextPos, NULL, true, enemies[i]->enType, i))
				{
					enemies[i]->enSpeed = -(enemies[i]->enSpeed);
				}

				/*
				if (!checkCollision(&enemies[i]->enRect, NULL, true, enemies[i]->enType, i))
				{
					nextPos.x = enemies[i]->enRect.x + enemies[i]->enSpeed;
					nextPos.y = enemies[i]->enRect.y;
				}

				if (checkCollision(&nextPos, NULL, true, enemies[i]->enType, i))
				{
					enemies[i]->enSpeed = -(enemies[i]->enSpeed);
				}
				*/

				enemies[i]->enHitboxRect.x += enemies[i]->enSpeed;
				break;

			case BASIC_ENEMY:
				nextPos.x = enemies[i]->enHitboxRect.x + enemies[i]->enSpeed;
				nextPos.y = enemies[i]->enHitboxRect.y;
				nextPos.w = enemies[i]->enHitboxRect.w;
				nextPos.h = enemies[i]->enHitboxRect.h;

				if (!checkCollision(&nextPos, NULL, true, enemies[i]->enType, i))
				{
					enemies[i]->enHitboxRect.x += enemies[i]->enSpeed;
				}
				else
				{
					enemies[i]->enSpeed = -(enemies[i]->enSpeed);
				}
				break;

			case FLY:
				if (enemies[i]->enIsJumping <= 0)
				{
					enemies[i]->enIsJumping = 0;
				}
				else if (enemies[i]->enIsJumping >= FLY_ARRAY_UNITS)
				{
					enemies[i]->enIsJumping = FLY_ARRAY_UNITS - 1;
				}

				enIsFlying = enemies[i]->enIsJumping;

				// if the dude is descending
				if (enemies[i]->enSpeed > 0)
				{
					nextPos.x = enemies[i]->enHitboxRect.x;
					nextPos.y = enemies[i]->enHitboxRect.y + flyArray[enIsFlying];
					nextPos.w = enemies[i]->enHitboxRect.w;
					nextPos.h = enemies[i]->enHitboxRect.h;

					if (checkCollision(&nextPos, NULL, true, enemies[i]->enType, i))
					{
						if (!assigned)
						{
							enemies[i]->enSpeed = -(enemies[i]->enSpeed);
							enIsFlying = FLY_ARRAY_UNITS - 2;
							collided = true;
							assigned = true;
						}
						nextPos.y = enemies[i]->enHitboxRect.y;

						while (checkCollision(&nextPos, NULL, true, enemies[i]->enType, i))
						{
							nextPos.y++;
						}

						enemies[i]->enHitboxRect.y = nextPos.y;
					}

					if (++enIsFlying >= FLY_ARRAY_UNITS - 1 && !collided)
					{
						enIsFlying = FLY_ARRAY_UNITS - 1;
						enemies[i]->enSpeed = -(enemies[i]->enSpeed);
					}

					if (!collided)
					{
						enemies[i]->enHitboxRect.y += flyArray[enIsFlying];
					}
				}
				// if the dude is ascending
				else if (enemies[i]->enSpeed < 0)
				{
					nextPos.x = enemies[i]->enHitboxRect.x;
					nextPos.y = enemies[i]->enHitboxRect.y - flyArray[enIsFlying];
					nextPos.w = enemies[i]->enHitboxRect.w;
					nextPos.h = enemies[i]->enHitboxRect.h;

					if (checkCollision(&nextPos, NULL, true, enemies[i]->enType, i))
					{
						if (!assigned)
						{
							enemies[i]->enSpeed = -(enemies[i]->enSpeed);
							enIsFlying = 1;
							collided = true;
							assigned = true;
						}

						nextPos.y = enemies[i]->enHitboxRect.y;

						while (checkCollision(&nextPos, NULL, true, enemies[i]->enType, i))
						{
							nextPos.y--;
						}

						enemies[i]->enHitboxRect.y = nextPos.y;
					}

					if (--enIsFlying <= 0 && !collided)
					{
						enIsFlying = 0;
						enemies[i]->enSpeed = -(enemies[i]->enSpeed);
					}

					if (!collided)
					{
						enemies[i]->enHitboxRect.y -= flyArray[enIsFlying];
					}
				}

				enemies[i]->enIsJumping = enIsFlying;
				break;

			default:
				std::cout << "boop" << std::endl;
				break;
			}
		}
	}
}

void applyMiscAI(void)
{
	for (int i = 0; i < DEFAULT_LEVEL_UNITS; i++)
	{
		if (collectibles[i] != NULL)
		{
			int move = 0;
			switch (collectibles[i]->clType)
			{
			case DEFAULT_COLLECTIBLE:
				if (collectibles[i]->clMovements < (FLOATING_ARRAY_UNITS/2) && collectibles[i]->clMovements >= 0)
				{
					move = floatingArray[collectibles[i]->clMovements];
					collectibles[i]->clMovements++;
					collectibles[i]->clRect.y += move;
				}
				else if (collectibles[i]->clMovements >= (FLOATING_ARRAY_UNITS/2) && collectibles[i]->clMovements < (FLOATING_ARRAY_UNITS))
				{
					move = floatingArray[collectibles[i]->clMovements];
					collectibles[i]->clMovements++;
					collectibles[i]->clRect.y -= move;
				}
				else
				{
					collectibles[i]->clMovements = 0;
				}
			}
		}
	}
}

Collectible::Collectible(int passedX, int passedY, int passedW, int passedH, int type)
{
	clRect.x = passedX;
	clRect.y = passedY;
	clRect.w = passedW;
	clRect.h = passedH;

	clType = type;
}

void Collectible::clRender(void)
{
	collectibleTexture.txRect = clRect;

	collectibleTexture.txRender();
}

void Collectible::clUpdate(void)
{
	collectibleTexture.txRect = clRect;

	switch (clType)
	{
	case DEFAULT_COLLECTIBLE:
		collectibleTexture.txLoadF("resources/heart.png");
		break;
	}
}

void Collectible::clCollect(int position)
{
	switch (clType)
	{
	case DEFAULT_COLLECTIBLE:
		gPlayer.plHealth += 50;
		break;
	}

	delete collectibles[position];
	collectibles[position] = NULL;
}

void Player::plRender(void)
{
	if (plSpeed < 0 && plIsJumping < 0 && plIsFalling <= 0)
	{
		if (plFrameWaitCounter >= 36)
		{
			plFrameWaitCounter = 0;
		}

		if (plFrameWaitCounter == 0)
		{
			plCurrentFrame = WALK_LEFT_1;
		}
		else if (plFrameWaitCounter == 4 && plCurrentFrame == WALK_LEFT_1)
		{
			plCurrentFrame = WALK_LEFT_2;
		}
		else if (plFrameWaitCounter == 8 && plCurrentFrame == WALK_LEFT_2)
		{
			plCurrentFrame = WALK_LEFT_3;
		}
		else if (plFrameWaitCounter == 12 && plCurrentFrame == WALK_LEFT_3)
		{
			plCurrentFrame = WALK_LEFT_4;
		}
		else if (plFrameWaitCounter == 16 && plCurrentFrame == WALK_LEFT_4)
		{
			plCurrentFrame = WALK_LEFT_5;
		}
		else if (plFrameWaitCounter == 20 && plCurrentFrame == WALK_LEFT_5)
		{
			plCurrentFrame = WALK_LEFT_6;
		}
		else if (plFrameWaitCounter == 24 && plCurrentFrame == WALK_LEFT_6)
		{
			plCurrentFrame = WALK_LEFT_7;
		}
		else if (plFrameWaitCounter == 28 && plCurrentFrame == WALK_LEFT_7)
		{
			plCurrentFrame = WALK_LEFT_8;
		}
		else if (plFrameWaitCounter == 32 && plCurrentFrame == WALK_LEFT_8)
		{
			plCurrentFrame = WALK_LEFT_1;
			plFrameWaitCounter = -1;
		}
	}
	else if (plSpeed > 0 && plIsJumping < 0 && plIsFalling <= 0)
	{
		if (plFrameWaitCounter >= 36)
		{
			plFrameWaitCounter = 0;
		}

		if (plFrameWaitCounter == 0)
		{
			plCurrentFrame = WALK_RIGHT_1;
		}
		else if (plFrameWaitCounter == 4 && plCurrentFrame == WALK_RIGHT_1)
		{
			plCurrentFrame = WALK_RIGHT_2;
		}
		else if (plFrameWaitCounter == 8 && plCurrentFrame == WALK_RIGHT_2)
		{
			plCurrentFrame = WALK_RIGHT_3;
		}
		else if (plFrameWaitCounter == 12 && plCurrentFrame == WALK_RIGHT_3)
		{
			plCurrentFrame = WALK_RIGHT_4;
		}
		else if (plFrameWaitCounter == 16 && plCurrentFrame == WALK_RIGHT_4)
		{
			plCurrentFrame = WALK_RIGHT_5;
		}
		else if (plFrameWaitCounter == 20 && plCurrentFrame == WALK_RIGHT_5)
		{
			plCurrentFrame = WALK_RIGHT_6;
		}
		else if (plFrameWaitCounter == 24 && plCurrentFrame == WALK_RIGHT_6)
		{
			plCurrentFrame = WALK_RIGHT_7;
		}
		else if (plFrameWaitCounter == 28 && plCurrentFrame == WALK_RIGHT_7)
		{
			plCurrentFrame = WALK_RIGHT_8;
		}
		else if (plFrameWaitCounter == 32 && plCurrentFrame == WALK_RIGHT_8)
		{
			plCurrentFrame = WALK_RIGHT_1;
			plFrameWaitCounter = -1;
		}
	}
	else if (plIsFalling > 0 && plIsJumping < 0)
	{
		if (plFrameWaitCounter < 40)
		{
			plFrameWaitCounter = 40;
		}
		else if (plFrameWaitCounter >= 48)
		{
			plFrameWaitCounter = 40;
		}

		if (plFrameWaitCounter >= 40 && plFrameWaitCounter < 44)
		{
			plCurrentFrame = FALLING_2;
		}
		else if (plFrameWaitCounter >= 44)
		{
			plCurrentFrame = FALLING_1;
		}
		else
		{
			plCurrentFrame = FALLING_1;
		}
	}
	else if (plIsJumping >= 0)
	{
		if (plFrameWaitCounter >= 8)
		{
			plFrameWaitCounter = 0;
		}

		if (plFrameWaitCounter >= 0 && plFrameWaitCounter < 4)
		{
			plCurrentFrame = JUMPING_2;
		}
		else if (plFrameWaitCounter >= 4)
		{
			plCurrentFrame = JUMPING_1;
		}
		else
		{
			plCurrentFrame = JUMPING_1;
		}
	}
	else
	{
		plCurrentFrame = IDLE_1;
	}

	if (plSpeed != 0 || plIsJumping >= 0 || plIsFalling > 0)
	{
		plFrameWaitCounter++;
	}

	playerTextures[plCurrentFrame].txRect = plGFXrect;

	if (plIsMelee >= 0)
	{
		playerTextures[plCurrentFrame].txRect.y += 24;
		
		SDL_Rect clipRect{ 0, 24, plGFXrect.w, plGFXrect.h - 24 };

		playerTextures[plCurrentFrame].txRender(&clipRect, NULL, NULL, SDL_FLIP_NONE);
		playerTextures[plCurrentFrame].txRect = plGFXrect;
	}
	else
	{
		playerTextures[plCurrentFrame].txRender();
	}
}

Particle::Particle(int passedX, int passedY, int passedW, int passedH, int type)
{
	ptRect.x = passedX;
	ptRect.y = passedY;
	ptRect.w = passedW;
	ptRect.h = passedH;

	ptOriginalLocation.x = passedX;
	ptOriginalLocation.y = passedY;

	ptType = type;

	ptLifespan = (8 + rand() % 16);

	ptDirectionPoint.x = (rand() % WINDOW_W);
	ptDirectionPoint.y = (rand() % WINDOW_H);

	int s1 = (ptDirectionPoint.y - ptRect.y);
	int s2 = (ptDirectionPoint.x - ptRect.x);

	ptSlope = (s2 != 0 ? s1 / s2 : s1 / 1);
}

void Particle::ptMove(int particleNumber)
{
	(ptDirectionPoint.x >= ptRect.x ? ptRect.x++ : ptRect.x--);
	ptRect.y += ptSlope;

	if (abs(ptRect.x - ptOriginalLocation.x) >= 32 || abs(ptRect.y - ptOriginalLocation.y) >= 32)
	{
		ptLifespan = -1;
	}

	if (ptLifespan-- <= 0)
	{
		ptLifespan = -1;

		// if ((ptAlpha -= 51) <= 0)
		// {
			ptDie(particleNumber);
		// }
	}
}

void Particle::ptRender(void)
{
	if (ptCounter++ >= 8)
	{
		ptCounter = 0;
	}

	if (ptCounter >= 0 && ptCounter < 4)
	{
		ptFrame = FLASH_2;
	}
	else if (ptCounter >= 4)
	{
		ptFrame = FLASH_1;
	}
	else
	{
		ptFrame = FLASH_1;
	}

	particleTextures[ptFrame][ptType]->txRect = ptRect;

	particleTextures[ptFrame][ptType]->txRender();
}

void Particle::ptDie(int particleNumber)
{
	delete particles[particleNumber];
	particles[particleNumber] = NULL;
}

// pass in NULL for everything if you just want the camera to act in its default way
Camera::Camera(int passedX, int passedY, int passedW, int passedH)
{
	if (passedX == NULL && passedY == NULL && passedW == NULL && passedH == NULL)
	{
		cmRect.x = (gPlayer.plGFXrect.x + gPlayer.plGFXrect.w / 2) - (WINDOW_W / 2);
		cmRect.y = (gPlayer.plGFXrect.y + gPlayer.plGFXrect.h / 2) - (WINDOW_H / 2);
		cmRect.w = WINDOW_W;
		cmRect.h = WINDOW_H;
	}
	else
	{
		cmRect.x = passedX;
		cmRect.y = passedY;
		cmRect.w = passedW;
		cmRect.h = passedH;
	}
}

void Camera::cmCenterCamera(void)
{
	cmRect.x = (gPlayer.plGFXrect.x + gPlayer.plGFXrect.w / 2) - (WINDOW_W / 2);
	cmRect.y = (gPlayer.plGFXrect.y + gPlayer.plGFXrect.h / 2) - (WINDOW_H / 2);
	static bool set1 = false;
	static bool set2 = false;
	if (playerCenterDifferenceX != NULL && !set1)
	{
		levelMovementsX += playerCenterDifferenceX;
		set1 = true;
	}

	if (playerCenterDifferenceY != NULL && !set2)
	{
		levelMovementsY += playerCenterDifferenceY;
		set2 = true;
	}
}

/*
void Camera::cmCenterCamera(void)
{
	cmRect.x = (gPlayer.plRect.x + gPlayer.plRect.w / 2) - (WINDOW_W / 2);
	cmRect.y = (gPlayer.plRect.y + gPlayer.plRect.h / 2) - (WINDOW_H / 2);
	static int difference;
	if (difference == NULL)
	{
		difference = (gPlayer.plRect.y + gPlayer.plRect.h / 2) - (WINDOW_H / 2);
	}

	if (cmRect.x > 0 && cmRect.x < DEFAULT_LEVEL_W_PIXELS)
	{
		difference = (gPlayer.plRect.x + gPlayer.plRect.w / 2) - (WINDOW_W / 2);
		for (int i = 0; i < DEFAULT_LEVEL_UNITS; i++)
		{
			if (blocks[i] != NULL)
			{
				blocks[i]->blRect.x -= difference;
			}
			if (enemies[i] != NULL)
			{
				enemies[i]->enRect.x -= difference;
			}
		}
	}
	else
	{
		cmRect.x = 0;
		// uh
	}


	if (cmRect.y > 0 && cmRect.y < DEFAULT_LEVEL_H_PIXELS)
	{
		std::cout << difference << std::endl;
		SDL_Rect nextPos{ gPlayer.plRect.x, gPlayer.plRect.y + difference, gPlayer.plRect.w, gPlayer.plRect.h };
		if (!checkCollisionWithGround(&nextPos))
		{
			for (int i = 0; i < DEFAULT_LEVEL_UNITS; i++)
			{
				if (difference != 0)
				{
					if (blocks[i] != NULL)
					{
						blocks[i]->blRect.y -= 4;
					}
					if (enemies[i] != NULL)
					{
						enemies[i]->enRect.y -= 4;
					}

					if (difference - 3 != 0 && difference - 2 != 0 && difference - 1 != 0)
					{
						difference -= 4;
					}
					else
					{
						difference = 0;
					}
				}
			}
			levelIsScrollingVertical = true;
		}

	}
	else
	{
		levelIsScrollingVertical = false;
		cmRect.y = 0;
		// uh
	}

}
*/

/*
void Camera::cmCenterCamera(void)
{
	SDL_Rect nextPos;
	nextPos.x = (gPlayer.plRect.x + gPlayer.plRect.w / 2) - (WINDOW_W / 2);
	nextPos.y = (gPlayer.plRect.y + gPlayer.plRect.h / 2) - (WINDOW_H / 2);
	nextPos.w = cmRect.w;
	nextPos.h = cmRect.h;

	if (nextPos.x < 0)
	{
		nextPos.x = 0;
		cmRect.x = nextPos.x;
	}
	if (nextPos.y < 0)
	{
		nextPos.y = 0;
		cmRect.y = nextPos.y;
	}
	if (nextPos.x > DEFAULT_LEVEL_W_PIXELS - nextPos.w)
	{
		nextPos.x = DEFAULT_LEVEL_W_PIXELS - nextPos.w;
		cmRect.x = nextPos.x;
	}
	if (nextPos.y > DEFAULT_LEVEL_H_PIXELS - nextPos.h)
	{
		nextPos.y = DEFAULT_LEVEL_H_PIXELS - nextPos.h;
		cmRect.y = nextPos.y;
	}

	if (nextPos.x != cmRect.x && !checkCollisionWithWall(&gPlayer.plRect))
	{
		for (int i = 0; i < DEFAULT_LEVEL_UNITS; i++)
		{
			if (blocks[i] != NULL)
			{
				blocks[i]->blRect.x -= gPlayer.plSpeed;
			}

			if (enemies[i] != NULL)
			{
				enemies[i]->enRect.x -= gPlayer.plSpeed;
			}
		}
		levelIsScrollingHorizontal = true;
	}
	else
	{
		levelIsScrollingHorizontal = false;
	}
	
	if (nextPos.y != cmRect.y && !checkCollisionWithGround(&gPlayer.plRect) && gPlayer.plIsJumping < 0 &&
		cmRect.y < DEFAULT_LEVEL_H_PIXELS - cmRect.h && nextPos.y < DEFAULT_LEVEL_H_PIXELS - nextPos.h)
	{
		for (int i = 0; i < DEFAULT_LEVEL_UNITS; i++)
		{
			if (blocks[i] != NULL)
			{
				blocks[i]->blRect.y -= (nextPos.y - cmRect.y);
			}

			if (enemies[i] != NULL)
			{
				enemies[i]->enRect.y -= (nextPos.y - cmRect.y);
			}
		}
		levelIsScrollingVertical = true;
	}
	else
	{
		levelIsScrollingVertical = false;
	}

	if (cmRect.x != nextPos.x)
	{
		cmRect.x = nextPos.x;
	}
	if (cmRect.y != nextPos.y)
	{
		cmRect.y = nextPos.y;
	}

	for (int xCoord = 0, yCoord = 0; cmRect.x > 0 && cmRect.y > 0 &&
		cmRect.x < DEFAULT_LEVEL_W_PIXELS - cmRect.w && cmRect.y < DEFAULT_LEVEL_H_PIXELS - cmRect.h &&
		cmRect.x != (gPlayer.plRect.x + gPlayer.plRect.w / 2) - (WINDOW_W / 2) &&
		cmRect.y != (gPlayer.plRect.y + gPlayer.plRect.h / 2) - (WINDOW_H / 2);)
	{
		if (cmRect.x - ((gPlayer.plRect.x + gPlayer.plRect.w / 2) - (WINDOW_W / 2)) != 0)
		{
			xCoord = cmRect.x - ((gPlayer.plRect.x + gPlayer.plRect.w / 2) - (WINDOW_W / 2));
			for (int i = 0; i < DEFAULT_LEVEL_UNITS; i++)
			{
				if (blocks[i] != NULL)
				{
					blocks[i]->blRect.x += xCoord;
				}
				if (enemies[i] != NULL)
				{
					enemies[i]->enRect.x += xCoord;
				}
			}
		}
		if (cmRect.y - ((gPlayer.plRect.y + gPlayer.plRect.h / 2) - (WINDOW_W / 2)) != 0)
		{
			yCoord = cmRect.y - ((gPlayer.plRect.y + gPlayer.plRect.h / 2) - (WINDOW_W / 2));
			for (int i = 0; i < DEFAULT_LEVEL_UNITS; i++)
			{
				if (blocks[i] != NULL)
				{
					blocks[i]->blRect.y += yCoord;
				}
				if (enemies[i] != NULL)
				{
					enemies[i]->enRect.y += yCoord;
				}
			}
		}
	}
	std::cout << "x " << (gPlayer.plRect.x + gPlayer.plRect.w / 2) - (WINDOW_W / 2) << std::endl;
	std::cout << "y " << (gPlayer.plRect.y + gPlayer.plRect.h / 2) - (WINDOW_H / 2) << std::endl;
}
*/

Sign::Sign(int passedX, int passedY, int passedW, int passedH, int num)
{
	snRect.x = passedX;
	snRect.y = passedY;
	snRect.w = passedW;
	snRect.h = passedH;
	snNumber = num;
}

void Sign::snLoadMessage(void)
{
	for (int i = 0; i < TOTAL_MESSAGES; i++)
	{
		if (textTextures[i] != NULL)
		{
			delete textTextures[i];
			textTextures[i] = NULL;
		}
	}

	for (int i = 0; i < TOTAL_MESSAGES; i++)
	{
		if (signs[i] != NULL)
		{
			for (int x = 0, y = 0, z = 0; messages[(y = gCollidingSign[whichSign])][x] != NULL; z++)
			{
				textTextures[z] = new Texture();
				textTextures[z]->txRect.x = 54;
				textTextures[z]->txRect.y = 54 + (24 * z);
				// textTextures[z]->txRect.w = messageW[y][x];
				// textTextures[z]->txRect.h = 16;
				textTextures[z]->txRect.w = 0;
				textTextures[z]->txRect.h = 0;

				// render the text to the screen
				SDL_Color textColor = { 200, 200, 200 };
				if (!textTextures[z]->loadT(messages[y][x], textColor))
				{
					std::cout << "Error while creating text texture!" << std::endl;
				}

				if (messages[y][++x] == NULL)
				{
					return;
				}
			}
		}
	}
}

void Sign::snShowMessage(void)
{
	messageTexture.txRender();

	for (int i = 0; i < TOTAL_MESSAGES; i++)
	{
		if (textTextures[i] != NULL)
		{
			textTextures[i]->txRender();
		}
	}
}

Bullet::Bullet(int passedX, int passedY, int passedW, int passedH, Direction dir, int passedEnemyNum)
{
	if (passedX == NULL && passedY == NULL && passedW == NULL && passedH == NULL)
	{
		if (passedEnemyNum == -1)
		{
			if (dir == RIGHT)
			{
				btRect.y = gPlayer.plGFXrect.y + (gPlayer.plGFXrect.h * 0.6);
				btRect.w = DEFAULT_BULLET_W;
				btRect.h = DEFAULT_BULLET_H;
				btRect.x = gPlayer.plGFXrect.x + gPlayer.plGFXrect.w;
			}
			else if (dir == LEFT)
			{
				btRect.y = gPlayer.plGFXrect.y + (gPlayer.plGFXrect.h * 0.6);
				btRect.w = DEFAULT_BULLET_W;
				btRect.h = DEFAULT_BULLET_H;
				btRect.x = gPlayer.plGFXrect.x - btRect.w;
			}
			else if (dir == UP)
			{
				// we gotta make some changes since it's vertical
				btRect.x = gPlayer.plGFXrect.x + (gPlayer.plGFXrect.w / 2);
				btRect.w = DEFAULT_BULLET_H;
				btRect.h = DEFAULT_BULLET_W;
				btRect.y = gPlayer.plGFXrect.y - btRect.h;
			}
			else if (dir == DOWN)
			{
				btRect.x = gPlayer.plGFXrect.x + (gPlayer.plGFXrect.w / 2);
				btRect.w = DEFAULT_BULLET_H;
				btRect.h = DEFAULT_BULLET_W;
				btRect.y = gPlayer.plGFXrect.y + gPlayer.plGFXrect.h;
			}
			else
			{
				std::cout << "somethin aint right yo" << std::endl;
			}
		}
		else if (passedEnemyNum >= 0)
		{
			if (dir == RIGHT)
			{
				btRect.y = enemies[passedEnemyNum]->enGFXrect.y + (enemies[passedEnemyNum]->enGFXrect.h * 0.75);
				btRect.w = DEFAULT_BULLET_W;
				btRect.h = DEFAULT_BULLET_H;
				btRect.x = enemies[passedEnemyNum]->enGFXrect.x + enemies[passedEnemyNum]->enGFXrect.w;
			}
			else if (dir == LEFT)
			{
				btRect.y = enemies[passedEnemyNum]->enGFXrect.y + (enemies[passedEnemyNum]->enGFXrect.h * 0.75);
				btRect.w = DEFAULT_BULLET_W;
				btRect.h = DEFAULT_BULLET_H;
				btRect.x = enemies[passedEnemyNum]->enGFXrect.x - btRect.w;
			}
			else if (dir == UP)
			{
				// we gotta make some changes since it's vertical
				btRect.x = enemies[passedEnemyNum]->enGFXrect.x + (enemies[passedEnemyNum]->enGFXrect.w / 2);
				btRect.w = DEFAULT_BULLET_H;
				btRect.h = DEFAULT_BULLET_W;
				btRect.y = enemies[passedEnemyNum]->enGFXrect.y - btRect.h;
			}
			else if (dir == DOWN)
			{
				btRect.x = enemies[passedEnemyNum]->enGFXrect.x + (enemies[passedEnemyNum]->enGFXrect.w / 2);
				btRect.w = DEFAULT_BULLET_H;
				btRect.h = DEFAULT_BULLET_W;
				btRect.y = enemies[passedEnemyNum]->enGFXrect.y + enemies[passedEnemyNum]->enGFXrect.h;
			}
			else
			{
				std::cout << "somethin aint right yo" << std::endl;
			}
		}
	}
	
	// btWhatShotIt = what;

	btDirection = dir;
	btEnemyNum = passedEnemyNum;
}

Bullet::~Bullet()
{

}

void Bullet::btRender(void)
{
	if (btDirection == LEFT)
	{
		bulletTextureH.txRect = btRect;
		bulletTextureH.txRender(NULL, NULL, NULL, SDL_FLIP_HORIZONTAL);
	}
	else if (btDirection == RIGHT)
	{
		bulletTextureH.txRect = btRect;
		bulletTextureH.txRender();
	}
	else if (btDirection == UP)
	{
		bulletTextureV.txRect = btRect;
		bulletTextureV.txRender();
	}
	else if (btDirection == DOWN)
	{
		bulletTextureV.txRect = btRect;
		bulletTextureV.txRender(NULL, NULL, NULL, SDL_FLIP_VERTICAL);
	}
	else
	{
		std::cout << "uh what" << std::endl;
	}
}

void Bullet::btShoot(void)
{

}

void Bullet::btMove(int bulletNum)
{
	bool destroyed = false;
	if (!checkCollision(&btRect, NULL, true, BULLET) || btShouldMove)
	{
		Uint8 howMuchToMove = 1;
		if (btShouldMove)
		{
			// we need to move the bullet by twice as much since it already missed a movement cycle
			btShouldMove = false;
			howMuchToMove = 2;
		}

		if (btDirection == LEFT)
		{
			btRect.x -= 8 * howMuchToMove;
		}
		else if (btDirection == RIGHT)
		{
			btRect.x += 8 * howMuchToMove;
		}
		else if (btDirection == UP)
		{
			btRect.y -= 8 * howMuchToMove;
		}
		else if (btDirection == DOWN)
		{
			btRect.y += 8 * howMuchToMove;
		}
	}
	else
	{
		for (int i = 0; i < DEFAULT_LEVEL_UNITS; i++)
		{
			if (gCollidingBullet[i] == PLAYER)
			{
				if (btEnemyNum >= 0)
				{
					destroyed = true;
					btDestroy(bulletNum);
					quit = true;
					break;
				}
				else
				{
					btShouldMove = true;
				}
			}
			else if (gCollidingBullet[i] >= DEFAULT_BLOCK && gCollidingBullet[i] < DEFAULT_ENEMY)
			{
				destroyed = true;
				btDestroy(bulletNum);
				break;
			}
			else if (gCollidingBullet[i] >= DEFAULT_ENEMY && gCollidingBullet[i] < DEFAULT_COLLECTIBLE)
			{
				if (btEnemyNum == -1)
				{
					destroyed = true;
					enemies[i]->enDie(i, false);
					btDestroy(bulletNum);
					break;
				}
				else
				{
					btShouldMove = true;
				}
			}
		}
	}

	if (btEnemyNum == -1 && !destroyed)
	{
		if (gPlayer.plIsShooting++ >= 256)
		{
			btDestroy(bulletNum);
			gPlayer.plIsShooting = -1;
		}
	}
	else if (!destroyed)
	{
		if (enemies[btEnemyNum]->enIsShooting++ >= 256)
		{
			btDestroy(bulletNum);
			// gPlayer.plIsShooting = -1;
		}
	}
}

void Bullet::btDestroy(int bulletNum)
{
	delete bullets[bulletNum];
	bullets[bulletNum] = NULL;
}

Melee::Melee(int passedX, int passedY, int passedW, int passedH, Direction dir, int passedEnemyNum)
{
	if (passedX == NULL && passedY == NULL && passedW == NULL && passedH == NULL)
	{
		meRect.w = DEFAULT_WEAPON_H;
		meRect.h = DEFAULT_WEAPON_W;
		if (passedEnemyNum == -1)
		{
			if (dir == LEFT)
			{
				meRect.x = gPlayer.plGFXrect.x;
				meRect.y = gPlayer.plGFXrect.y + (meRect.h * 0.75);
			}
			else if (dir == RIGHT)
			{
				meRect.x = gPlayer.plGFXrect.x + gPlayer.plGFXrect.w - meRect.w;
				meRect.y = gPlayer.plGFXrect.y + (meRect.h * 0.75);
			}
			else if (dir == UP)
			{
				meRect.x = gPlayer.plGFXrect.x + 8;
				meRect.y = gPlayer.plGFXrect.y;
			}
			else if (dir == DOWN)
			{
				meRect.x = gPlayer.plGFXrect.x + 8;
				meRect.y = gPlayer.plGFXrect.y + (gPlayer.plGFXrect.h * 0.75);
			}
		}
		else if (passedEnemyNum >= 0)
		{
			if (dir == LEFT)
			{
				meRect.x = enemies[passedEnemyNum]->enGFXrect.x + 8;
				meRect.y = enemies[passedEnemyNum]->enGFXrect.y + (meRect.h * 0.5);
			}
			else if (dir == RIGHT)
			{
				meRect.x = enemies[passedEnemyNum]->enGFXrect.x + enemies[passedEnemyNum]->enGFXrect.w - 8;
				meRect.y = enemies[passedEnemyNum]->enGFXrect.y + (meRect.h * 0.5);
			}
			else if (dir == UP)
			{
				meRect.x = enemies[passedEnemyNum]->enGFXrect.x + 8;
				meRect.y = enemies[passedEnemyNum]->enGFXrect.y;
			}
			else if (dir == DOWN)
			{
				meRect.x = enemies[passedEnemyNum]->enGFXrect.x + 8;
				meRect.y = enemies[passedEnemyNum]->enGFXrect.y + enemies[passedEnemyNum]->enGFXrect.h;
			}
		}
	}

	// meWhatSwungIt = what;

	meDirection = dir;
	meEnemyNum = passedEnemyNum;
}

Melee::~Melee()
{
	// uh
}

void Melee::meMove(int weaponNum)
{
	bool isColliding = false;

	if (meEnemyNum == -1)
	{
			gPlayer.plIsMelee++;
			if (gPlayer.plIsMelee < 4 && gPlayer.plIsMelee >= 0)
			{
				(meDirection == RIGHT || meDirection == LEFT ? meRect.x : meRect.y) += (meDirection == RIGHT || meDirection == DOWN ? 4 : -4);
				isColliding = checkCollision(&meRect, NULL, true, MELEE);
			}
			else if (gPlayer.plIsMelee >= 4 && gPlayer.plIsMelee < 8)
			{
				(meDirection == RIGHT || meDirection == LEFT ? meRect.x : meRect.y) += (meDirection == RIGHT || meDirection == DOWN ? -4 : 4);
				isColliding = checkCollision(&meRect, NULL, true, MELEE);
			}
			else
			{
				gPlayer.plIsMelee = -1;
				meStop(weaponNum);
			}
	}
	else if (meEnemyNum >= 0)
	{
		enemies[meEnemyNum]->enIsMelee++;
		if (enemies[meEnemyNum]->enIsMelee < 4 && enemies[meEnemyNum]->enIsMelee >= 0)
		{
			meRect.x += 4;
			isColliding = checkCollision(&meRect, NULL, true, MELEE);
		}
		else if (enemies[meEnemyNum]->enIsMelee >= 4 && enemies[meEnemyNum]->enIsMelee < 8)
		{
			meRect.x -= 4;
			isColliding = checkCollision(&meRect, NULL, true, MELEE);
		}
		else
		{
			enemies[meEnemyNum]->enIsMelee = -1;
			meStop(weaponNum);
		}
	}

	if (isColliding)
	{
		for (int i = 0; i < DEFAULT_LEVEL_UNITS; i++)
		{
			if (gCollidingMelee[i] != NULL)
			{
				if (gCollidingMelee[i] == PLAYER && meEnemyNum >= 0)
				{
					quit = true;
				}
				else if ((gCollidingMelee[i] >= DEFAULT_ENEMY && gCollidingMelee[i] < DEFAULT_COLLECTIBLE) && meEnemyNum == -1)
				{
					enemies[i]->enDie(i, false);
				}
			}
		}
	}
}

void Melee::meSwing(void)
{

}

void Melee::meRender(void)
{
	if (meEnemyNum == -1)
	{
		if (meDirection == LEFT)
		{
			playerMeleeTextureH.txRect = meRect;
			playerMeleeTextureH.txRender(NULL, NULL, NULL, SDL_FLIP_HORIZONTAL);
		}
		else if (meDirection == RIGHT)
		{
			playerMeleeTextureH.txRect = meRect;
			playerMeleeTextureH.txRender();
		}
		else if (meDirection == UP)
		{
			playerMeleeTextureV.txRect = meRect;
			playerMeleeTextureV.txRender();
		}
		else if (meDirection == DOWN)
		{
			playerMeleeTextureV.txRect = meRect;
			playerMeleeTextureV.txRender(NULL, NULL, NULL, SDL_FLIP_VERTICAL);
		}
		else
		{
			std::cout << "uh what" << std::endl;
		}
	}
	else
	{
		if (meDirection == LEFT)
		{
			enemyMeleeTextureH.txRect = meRect;
			enemyMeleeTextureH.txRender(NULL, NULL, NULL, SDL_FLIP_HORIZONTAL);
		}
		else if (meDirection == RIGHT)
		{
			enemyMeleeTextureH.txRect = meRect;
			enemyMeleeTextureH.txRender();
		}
		else if (meDirection == UP)
		{
			enemyMeleeTextureV.txRect = meRect;
			enemyMeleeTextureV.txRender();
		}
		else if (meDirection == DOWN)
		{
			enemyMeleeTextureV.txRect = meRect;
			enemyMeleeTextureV.txRender(NULL, NULL, NULL, SDL_FLIP_VERTICAL);
		}
		else
		{
			std::cout << "uh what" << std::endl;
		}
	}
}

void Melee::meStop(int weaponNum)
{
	delete weapons[weaponNum];
	weapons[weaponNum] = NULL;
}

Music::Music(char* path, int type)
{
	if (path != NULL)
	{
		gTrack = Mix_LoadMUS(path);
	}

	if (gTrack == NULL && path != NULL)
	{
		std::cout << "The stupid music track didn't load!!" << std::endl;
	}

	msType = type;
}

Music::~Music()
{
	gTrack = NULL;
}

void Music::msLoad(char* path)
{
	if (path != NULL)
	{
		gTrack = Mix_LoadMUS(path);
	}
}

void Music::msPlay(void)
{
	if (gTrack != NULL)
	{
		Mix_PlayMusic(gTrack, -1);
	}
}