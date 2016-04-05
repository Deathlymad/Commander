#include "core/oxygine.h"
#include "Stage.h"
#include "DebugActor.h"

#include "CommanderGame.h"

using namespace oxygine;

int main(int argc, char* argv[])
{
	ObjectBase::__startTracingLeaks();

	// Initialize Oxygine's internal stuff
	core::init_desc desc;
	desc.title = "Commander Game";

	desc.w = 960;
	desc.h = 640;

	CommanderGame instance;

	instance.preInit();
	core::init(&desc);


	// Create the stage. Stage is a root node for all updateable and drawable objects
	Stage::instance = new Stage(true);
	Point size = core::getDisplaySize();
	getStage()->setSize(size);

	// DebugActor is a helper actor node. It shows FPS, memory usage and other useful stuff
	DebugActor::show();

	// Initializes our example game. See example.cpp
	instance.init();

	// This is the main game loop.
	while (1)
	{
		int done = instance.update();
		if (done)
			break;
	}

	ObjectBase::dumpCreatedObjects(); //checking for leaks

	instance.destroy();

	core::release();

	ObjectBase::dumpCreatedObjects(); //Memory Leak Check #2
	ObjectBase::__stopTracingLeaks();
}