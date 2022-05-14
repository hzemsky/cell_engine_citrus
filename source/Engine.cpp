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
    : cells(new int[GRID_HEIGHT * GRID_WIDTH])
{
    randomizeCells();
}

Engine::~Engine()
{

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
    int tmp[CELL_COUNT];

    for (int i = 0; i < CELL_COUNT; i++) tmp[i] = rps(i);
    for (int i = 0; i < CELL_COUNT; i++) cells[i] = tmp[i];
}

inline void indexToCoord(int i, int* coord) {
    coord[0] = i % GRID_WIDTH;
    coord[1] = i / GRID_WIDTH;
};

int Engine::rps(int i)
{
    int threat = cells[i] + 1;
    if (threat > 2) threat = 0;
    
    int* coord = new int[2];
    indexToCoord(i, coord);
    int minX = (coord[0] > 0)              ? (coord[0] - 1) : (coord[0]),
        maxX = (coord[0] < GRID_WIDTH-1)   ? (coord[0] + 1) : (coord[0]),
        minY = (coord[1] > 0)              ? (coord[1] - 1) : (coord[1]),
        maxY = (coord[1] < GRID_HEIGHT-1)   ? (coord[1] + 1) : (coord[1]);
    delete[] coord;

    int threatLevel = 0;
    for (int x = minX; x <= maxX; x++) {
        for (int y = minY; y <= maxY; y++) {
            if ( cells[ y * GRID_WIDTH + x ] == threat) 
                threatLevel++;
        }
    }
    
    int threshold = 4;

    if (threatLevel > threshold) return threat;
    else return cells[i];
}

