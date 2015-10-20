#include <iostream>
#include "Application.h"
#include "btBulletDynamicsCommon.h"

#if defined(DEBUG) || defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

int main()
{
	// Test
	btBoxShape* box = new btBoxShape(btVector3(1, 1, 1));

	// Memory leak detection
	#if defined(DEBUG) | defined(_DEBUG)
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
		//_CrtSetBreakAlloc(777);
	#endif

	Application game;
	game.Run();

	return 0;
}
