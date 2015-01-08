// Include the header file that has everything that will be needed
#include "Include.h"

//  make camera work, make gravity affect enemies,

int main(int argc, char** argv)
{
	srand(time(NULL));

	if (!initialized || !initTwo())
	{
		std::cout << "Failed to initialize!  isn't it exciting" << std::endl;
		return -1;
	}

	if (!generateLevel())
	{
		std::cout << "Couldn't generate the level!  Sorry!" << std::endl;
		return -1;
	}

	SDL_Rect debugRect{gPlayer.plHitboxRect.x, gPlayer.plHitboxRect.y, gPlayer.plHitboxRect.w, gPlayer.plHitboxRect.h};
	bool menuSet = false;
	SDL_Rect menuRect{ 0, 0, 0, 0 };
	SDL_Rect enemyGroundCheck;
	int timing = 0;
	bool timingSet = false;
	int ticks = 0;

	while (!quit)
	{
		prev_e = e;

		levelMovementsX = 0;
		levelMovementsY = 0;

		while (SDL_PollEvent(&e) != NULL)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			else
			{
				if (gPlayer.plHandleEvent(&e) == false)
				{
				}
				else
				{
				}
			}
		}

		if (gPlayer.plSpeed == 0 && gPlayer.plIsFalling <= 0 && gPlayer.plIsJumping < 0 && gPlayer.plCurrentFrame != IDLE_2)
		{
			gPlayer.plCurrentFrame = IDLE_1;
		}

		if (gPlayer.plIsJumping > -1)
		{
			if (gPlayer.plIsJumping >= JUMP_ARRAY_UNITS-1)
			{
				gPlayer.plIsJumping = -1;
			}
			else
			{
				gPlayer.plIsJumping++;
				gPlayer.plJump();
			}
		}

		gPlayer.plMove(NULL);
		gCamera.cmCenterCamera();
		applyGravity(NULL, NULL);

		applyEnemyAI();
		applyMiscAI();
		gPlayer.plSyncTexture();

		for (int i = 0; i < DEFAULT_LEVEL_UNITS; i++)
		{
			if (enemies[i] != NULL)
			{
				if (enemies[i]->enIsJumping > -1)
				{
					if (enemies[i]->enIsJumping > ENEMY_JUMP_ARRAY_UNITS && enemies[i]->enType != FLY)
					{
						enemies[i]->enIsJumping = -1;
					}
					else if (enemies[i]->enType != FLY)
					{
						enemies[i]->enJump(i);
					}
				}

				if (enemies[i] != NULL)
				{
					enemyGroundCheck = enemies[i]->enHitboxRect;
					enemyGroundCheck.y++;
					if (!checkCollision(&enemyGroundCheck, NULL, true, enemies[i]->enType, i) && enemies[i]->enIsJumping < 0)
					{
						enemies[i]->enTestFalling = true;
					}
					else
					{
						enemies[i]->enTestFalling = false;
					}

					if (enemies[i]->enTestFalling)
					{
						enemies[i]->enIsFalling++;
					}
					else
					{
						enemies[i]->enIsFalling = 0;
					}

					if (enemies[i]->enIsFalling > DEFAULT_GRAVITY_UNITS-1)
					{
						enemies[i]->enIsFalling = DEFAULT_GRAVITY_UNITS-1;
					}
				}

				/*
				if (collectibles[i] != NULL)
				{
					if (!checkCollisionWithGround(&collectibles[i]->clRect, i))
					{
						collectibles[i]->clTestFalling = true;
					}
					else
					{
						collectibles[i]->clTestFalling = false;
					}

					if (collectibles[i]->clTestFalling)
					{
						collectibles[i]->clIsFalling++;
					}
					else
					{
						collectibles[i]->clIsFalling = 0;
					}

					if (collectibles[i]->clIsFalling > 7)
					{
						collectibles[i]->clIsFalling = 7;
					}
				}
				*/
			}

			/*
			if (collectibles[i] != NULL)
			{
				if (checkCollision(&gPlayer.plHitboxRect, &collectibles[i]->clRect, true))
				{
					collectibles[i]->clCollect();
				}
			}
			*/
		}
		
		/*  uh
		debugRect.x = gPlayer.plRect.x;
		debugRect.y = gPlayer.plRect.y - 1;
		while (checkCollisionWithGround(&gPlayer.plRect) && checkCollisionWithGround(&debugRect))
		{
			gPlayer.plRect.y--;
			debugRect.y--;
		}
		*/

		for (int i = 0; i < DEFAULT_LEVEL_UNITS; i++)
		{
			if (blocks[i] != NULL)
			{
				blocks[i]->blRect.y += levelMovementsY;
				blocks[i]->blRect.x += levelMovementsX;
			}

			if (enemies[i] != NULL)
			{
				enemies[i]->enHitboxRect.y += levelMovementsY;
				enemies[i]->enHitboxRect.x += levelMovementsX;
			}

			if (collectibles[i] != NULL)
			{
				collectibles[i]->clRect.y += levelMovementsY;
				collectibles[i]->clRect.x += levelMovementsX;
			}
		}
		for (int i = 0; i < TOTAL_SIGNS; i++)
		{
			if (signs[i] != NULL)
			{
				signs[i]->snRect.y += levelMovementsY;
				signs[i]->snRect.x += levelMovementsX;
			}
		}
		for (int i = 0; i < MAX_BULLETS; i++)
		{
			if (bullets[i] != NULL)
			{
				bullets[i]->btRect.y += levelMovementsY;
				bullets[i]->btRect.x += levelMovementsX;
			}
		}
		for (int i = 0; i < MAX_MELEE; i++)
		{
			if (weapons[i] != NULL)
			{
				weapons[i]->meRect.y += levelMovementsY;
				weapons[i]->meRect.x += levelMovementsX;
			}
		}
		for (int i = 0; i < MAX_PARTICLES; i++)
		{
			if (particles[i] != NULL)
			{
				particles[i]->ptRect.y += levelMovementsY;
				particles[i]->ptRect.x += levelMovementsX;
			}
		}

		SDL_SetRenderDrawColor(gRenderer, 115, 105, 245, 255);
		SDL_RenderClear(gRenderer);

		gBackground.bgRender();

		for (int i = 0; i < TOTAL_SIGNS; i++)
		{
			if (signs[i] != NULL)
			{
				signs[i]->snRender();
			}
		}

		gPlayer.plRender();
		for (int i = 0; i < DEFAULT_LEVEL_UNITS; i++)
		{
			// uh
			SDL_Rect collisionCheck{ gCamera.cmRect.x - (WINDOW_W / 2), gCamera.cmRect.y - (WINDOW_H / 2),
				gCamera.cmRect.w + WINDOW_W, gCamera.cmRect.h + WINDOW_H };
			if (enemies[i] != NULL)
			{
				if (checkCollision(&enemies[i]->enHitboxRect, &collisionCheck))
				{
					enemies[i]->enSyncTexture();
					enemies[i]->enRender();
				}
			}
			else if (blocks[i] != NULL)
			{
				if (checkCollision(&blocks[i]->blRect, &collisionCheck))
				{
					blocks[i]->blRender();
				}
			}
			else if (collectibles[i] != NULL)
			{
				if (collectibles[i]->clType == DEFAULT_COLLECTIBLE)
				{
					if (collectibles[i]->clParticleCounter++ >= 4)
					{
						collectibles[i]->clParticleCounter = 0;
						for (int j = 0; j < MAX_PARTICLES; j++)
						{
							if (particles[j] == NULL)
							{
								particles[j] = new Particle(
									(collectibles[i]->clRect.x + collectibles[i]->clRect.w / 2),
									(collectibles[i]->clRect.y + collectibles[i]->clRect.h / 2),
									DEFAULT_PARTICLE_W, DEFAULT_PARTICLE_H, RED_PARTICLE);
								break;
							}
						}
					}
				}

				if (checkCollision(&collectibles[i]->clRect, &collisionCheck))
				{
					collectibles[i]->clRender();
				}
			}
		}

		for (int j = 0; j < MAX_PARTICLES; j++)
		{
			if (particles[j] != NULL)
			{
				particles[j]->ptRender();
				particles[j]->ptMove(j);
			}
		}

		for (int i = 0; i < MAX_BULLETS; i++)
		{
			if (bullets[i] != NULL)
			{
				bullets[i]->btRender();
				bullets[i]->btMove(i);
			}
		}

		for (int i = 0; i < MAX_MELEE; i++)
		{
			if (weapons[i] != NULL)
			{
				weapons[i]->meRender();
				weapons[i]->meMove(i);
			}
		}

		if (gPlayer.plHealth > 0)
		{
			for (int i = 0, x = 2; i <= gPlayer.plHealth; i += 2, x += 2)
			{
				healthTexture.txRect.x = x;
				healthTexture.txRender();
			}
		}
		else
		{
			quit = true;
		}

		if (inMenu)
		{
			handleMenu();
		}
		else if (inSign)
		{
			handleSign();
		}
		else
		{
			SDL_RenderPresent(gRenderer);
		}

		timing++;

		/*
		if (timing == 30)
		{
			timing = 0;
			if (!timingSet && (ticks = SDL_GetTicks()) < timing)
			{
				SDL_Delay(timing - ticks);
				timingSet = true;
			}
			else
			{
				SDL_Delay(timing - ticks);
			}
		}
		*/

	}

	close();
	return 0;
}