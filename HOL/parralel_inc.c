//#include "SDL/include/SDL.h"
//#pragma comment( lib, "SDL/lib/x86/SDL2.lib" )
//#pragma comment( lib, "SDL/lib/x86/SDL2main.lib" )
//#include <stdio.h>
//#define M 1000
//#define N 2000
//#define NUMTH 8
//
//int mat[M][N] = { 0 };
//
//
//
//int Compute(void* data)
//{
//	int thrid = (int)data;
//	int i = 0;
//	for (i = thrid*(M/2); i < thrid*(M/2) + (M/2); i++)
//	//for(i = 0; i <M; i++)
//	{
//		for (int j = 0; j < N; j++)
//			mat[i][j]++;
//	}
//	return thrid;
//}
//
//int main(int argc, char* argv[])
//{
//	unsigned int beginTime = 0, endTime;
//	int threadReturn;
//	beginTime = SDL_GetTicks();
//
//	printf("Start time: %d\n", beginTime);
//
//
//	SDL_Thread* thread[NUMTH];
//
//	for (int i = 0; i < NUMTH; i++) {
//		thread[i] = SDL_CreateThread(Compute, "ComputeThread", (void*)& i);
//		printf("Thread number %i \n", i);
//		if (thread[i] == NULL) {
//			printf("SDL_CreateThread failed: %s\n", SDL_GetError());
//		}
//		else
//		{
//			SDL_WaitThread(thread[i], &threadReturn);
//			printf("Thread return value %d\n", threadReturn);
//		}
//	}
//	endTime = SDL_GetTicks() - beginTime;
//	  
//	printf("End time: %d\n", endTime);
//	// Wait for all the threads
//	// Print something to validate the result
//
//	return 0;
//}