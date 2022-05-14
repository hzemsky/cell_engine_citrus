/*
Copywrite 2022 Holden Haruki Zemsky

This file is part of cell engine citrus.
Cell engine citrus is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Cell engine citrus is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY or even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with cell engine citrus. If not, see <https://www.gnu.org/licenses/>.
*/

#include "Constants.h"
#include "Graphics.h"

Graphics::Graphics(C3D_RenderTarget* target)
    : top(target), cells(nullptr),
    clrClear( C2D_Color32(0x00, 0x00, 0xFF, 0xFF) ),
    clrRed( C2D_Color32(0xFF, 0x00, 0x00, 0xFF) ),
    clrGreen( C2D_Color32(0x00, 0xFF, 0x00, 0xFF) ),
    clrBlue( C2D_Color32(0x00, 0x00, 0xFF, 0xFF) )
{
}

Graphics::~Graphics()
{
}

bool Graphics::init()
{
    if (!top) return false; 

    // Init libraries
	gfxInitDefault();
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();
	consoleInit(GFX_BOTTOM, NULL);

    return true;
}

bool Graphics::release()
{
    // Release Libraries
	C2D_Fini();
	C3D_Fini();
	gfxExit();

    return true;
}

void Graphics::setCells(int* c)
{
    cells = c;
}

void Graphics::render()
{
    // Render the scene
	C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
	C2D_TargetClear(top, clrClear);
	C2D_SceneBegin(top);

    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            switch (cells[ y * GRID_WIDTH + x]) {
            case 0:
                C2D_DrawRectangle(x * CELL_SIZE, y * CELL_SIZE, 0, CELL_SIZE, CELL_SIZE, clrRed, clrRed, clrRed, clrRed);
                break;
            case 1:
                C2D_DrawRectangle(x * CELL_SIZE, y * CELL_SIZE, 0, CELL_SIZE, CELL_SIZE, clrGreen, clrGreen, clrGreen, clrGreen);
                break;
            case 2:
                C2D_DrawRectangle(x * CELL_SIZE, y * CELL_SIZE, 0, CELL_SIZE, CELL_SIZE, clrBlue, clrBlue, clrBlue, clrBlue);
                break;
            }
        }
    }




	// lower screen options
	printf("\x1b[1;1H z3msky cell engine 3d v0");
	printf("\x1b[2;1H    rule:   < %s >", "placeholder");
	printf("\x1b[3;1H    colors: < %s >", "placeholder");
	printf("\x1b[4;1H  > exit");
	C3D_FrameEnd(0);
}