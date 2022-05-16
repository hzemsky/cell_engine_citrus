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
    clrA(0),
    clrB(0),
    clrC(0)
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
	//C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Init(CELL_COUNT);
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

void Graphics::setMenu(Menu* m)
{
    menu = m;
    updateColors();
}

void Graphics::updateColors()
{
    switch (menu->color) {
        case ColorScheme::RGB:
            clrA = C2D_Color32(255, 0, 0, 255);
            clrB = C2D_Color32(0, 255, 0, 255);
            clrC = C2D_Color32(0, 0, 255, 255);
            break;
        case ColorScheme::Purples:
            clrA = C2D_Color32(81, 45, 158, 255);
            clrB = C2D_Color32(115, 45, 217, 255);
            clrC = C2D_Color32(149, 117, 205, 255);
            break;
        default: 
            break; // updates color per draw
    }
    menu->colorUpdateNeeded = false;
}

void Graphics::render()
{
    // Render the scene
	C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
	C2D_TargetClear(top, clrA);
	C2D_SceneBegin(top);

    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            switch (cells[ y * GRID_WIDTH + x]) {
            case 0:
                C2D_DrawRectangle(x * CELL_SIZE, y * CELL_SIZE, 0, CELL_SIZE, CELL_SIZE, clrA, clrA, clrA, clrA);
                break;
            case 1:
                C2D_DrawRectangle(x * CELL_SIZE, y * CELL_SIZE, 0, CELL_SIZE, CELL_SIZE, clrB, clrB, clrB, clrB);
                break;
            case 2:
                C2D_DrawRectangle(x * CELL_SIZE, y * CELL_SIZE, 0, CELL_SIZE, CELL_SIZE, clrC, clrC, clrC, clrC);
                break;
            }
        }
    }

    menu->print();

	C3D_FrameEnd(0);
}