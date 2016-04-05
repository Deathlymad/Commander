#include "CommanderGame.h"

#include "core/oxygine.h"
#include "Stage.h"

using namespace oxygine;

CommanderGame::CommanderGame()
{

}

void CommanderGame::preInit()
{

}
void CommanderGame::init()
{

}
int CommanderGame::update()
{
	// Update our stage
    // Update all actors. Actor::update will also be called for all its children
    getStage()->update();

	if (core::beginRendering())
	{
		Color clearColor(32, 32, 32, 255);
		Rect viewport(Point(0, 0), core::getDisplaySize());
		// Render all actors inside the stage. Actor::render will also be called for all its children
		getStage()->render(clearColor, viewport);

		core::swapDisplayBuffers();
	}

	// Update engine-internal components
	// If input events are available, they are passed to Stage::instance.handleEvent
	// If the function returns true, it means that the user requested the application to terminate
	return core::update();
}

void CommanderGame::destroy()
{

}