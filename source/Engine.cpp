/*
Copywrite 2022 Holden Haruki Zemsky

This file is part of cell engine citrus.
Cell engine citrus is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Cell engine citrus is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY or even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with cell engine citrus. If not, see <https://www.gnu.org/licenses/>.
*/

#include <3ds.h>

#include <stdio.h>
#include <time.h>
#include <math.h>

#include "Engine.h"

Engine::Engine()
    : cells(new int[GRID_HEIGHT * GRID_WIDTH]), currentRule(nullptr), rps(nullptr)
{
    rps = new RPSRule();
    currentRule = rps;
    randomizeCells();
}

Engine::~Engine()
{
    delete rps;
}

int* Engine::getCells()
{
    return cells;
}

void Engine::randomizeCells()
{
    srand(time(NULL));
    for (int i = 0; i < GRID_HEIGHT * GRID_WIDTH; i++) {
        cells[i] = rand() % 3;
    }
}

void Engine::update()
{
    currentRule->Update(cells);
}

void Engine::indexToCoord(int i, int* coord) {
    coord[0] = i % GRID_WIDTH;
    coord[1] = i / GRID_WIDTH;
};



