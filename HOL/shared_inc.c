#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL/lib/x86/SDL2.lib" )
#pragma comment( lib, "SDL/lib/x86/SDL2main.lib" )
#include <stdio.h>

#define NUMTH 8

int var = 0;

int Compute(void* data)
{
	SDL_mutex* mutex = SDL_CreateMutex();
	SDL_LockMutex(mutex);
	for (int i = 0; i < 1000000; i++)
	{
		var++;
	}
	SDL_UnlockMutex(mutex);
	SDL_DestroyMutex(mutex);
}

int main(int argc, char* argv[])
{
	unsigned int beginTime = 0, endTime;
	int threadReturn;
	beginTime = SDL_GetTicks();

	printf("Start time: %d\n", beginTime);


	SDL_Thread* thread[NUMTH];

	for (int i = 0; i < NUMTH; i++) {
	
		thread[i] = SDL_CreateThread(Compute, "ComputeThread", (void*)& i);

		printf("Thread number %i \n", i);
		if (thread[i] == NULL) {
			printf("SDL_CreateThread failed: %s\n", SDL_GetError());
		}
		else
		{
			SDL_WaitThread(thread[i], &threadReturn);
			
			printf("Thread return value %d\n", threadReturn);
		}
	}
	endTime = SDL_GetTicks() - beginTime;

	printf("End time: %d\n", endTime);
	printf("Value at %d thread(s): %d\n", NUMTH, var);

	
	// Wait for all the threads
	// Print something to validate the result

	return 0;
}