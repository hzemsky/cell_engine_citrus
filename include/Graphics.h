/*
Copywrite 2022 Holden Haruki Zemsky

This file is part of cell engine citrus.
Cell engine citrus is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Cell engine citrus is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY or even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with cell engine citrus. If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <citro2d.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "Menu.h"

class Graphics {
public:
    Graphics() = delete;
    Graphics(C3D_RenderTarget* target);
    Graphics(const Graphics&) = delete;
    Graphics& operator= (const Graphics&) = delete;
    ~Graphics();

    bool init();
    void setCells(int*);
    void setMenu(Menu*);
    bool release();

    void updateColors();
    void render();

private:
    C3D_RenderTarget* top;
    Menu* menu;
    int* cells;

    uint32_t clrA; // A is used when theres more than 3 colors
    uint32_t clrB;
    uint32_t clrC;
};