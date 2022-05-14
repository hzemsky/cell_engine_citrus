/*
Copywrite 2022 Holden Haruki Zemsky

This file is part of cell engine citrus.
Cell engine citrus is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Cell engine citrus is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY or even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with cell engine citrus. If not, see <https://www.gnu.org/licenses/>.
*/

#include <citro2d.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "Constants.h"
#include "Engine.h"
#include "Graphics.h"




int main(int argc, char* argv[])
{
	// Init Engine
	Engine* engine = new Engine();

	// Init Graphics
	C3D_RenderTarget* target = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
	Graphics* graphics = new Graphics(target);
	if (!graphics->init()) return -1;
	// store reference to cells in graphics
	graphics->setCells( engine->getCells() );

	// Main Loop
	while (aptMainLoop())
	{
		hidScanInput();

		// temp quitout
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START) break;
		
		if (kDown & KEY_A) engine->randomizeCells();
		else engine->update();
		graphics->render();
	}

	// Clean Up
	graphics->release();
	delete graphics;
	delete engine;
	return 0;
}
