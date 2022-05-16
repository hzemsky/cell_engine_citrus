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
	// init engine, graphics, menu
	C3D_RenderTarget* target = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
	
	Engine* engine = new Engine();
	Menu* menu = new Menu();
	Graphics* graphics = new Graphics(target);
	
	if (!graphics->init()) return -1;
	graphics->setCells( engine->getCells() );
	graphics->setMenu( menu );

	// main loop
	while (aptMainLoop())
	{
		hidScanInput();

		if (menu->quitApp) break; // quit to hbmenu

		// menu controls
		uint32_t kDown = hidKeysDown();
		if (kDown & KEY_UP) menu->scrollUp();
		if (kDown & KEY_DOWN) menu->scrollDown();
		if (kDown & KEY_A) menu->select();
		if (kDown & KEY_RIGHT) menu->plus();
		if (kDown & KEY_LEFT) menu->minus();
		
		// guess what they do
		if (menu->running) engine->update();
		if (menu->colorUpdateNeeded) graphics->updateColors();
		graphics->render();
	}

	// Clean Up
	graphics->release();
	delete menu;
	delete graphics;
	delete engine;
	return 0;
}
