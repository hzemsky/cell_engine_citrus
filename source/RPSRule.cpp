/*
Copywrite 2022 Holden Haruki Zemsky

This file is part of cell engine citrus.
Cell engine citrus is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Cell engine citrus is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY or even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with cell engine citrus. If not, see <https://www.gnu.org/licenses/>.
*/

#include "Constants.h"
#include "RPSRule.h"
#include "Engine.h"


inline int rps(int* cells, int i)
{
    int threat = cells[i] + 1;
    if (threat > 2) threat = 0;
    
    int* coord = new int[2];
    Engine::indexToCoord(i, coord);

    int minX, maxX, minY, maxY;
    minX = maxX = coord[0];
    minY = maxY = coord[1];

    if (coord[0] > 0) minX--;
    if (coord[0] < GRID_WIDTH - 1) maxX++;
    if (coord[1] > 0) minY--;
    if (coord[1] < GRID_HEIGHT - 1) maxY++;

    delete[] coord;

    int threatLevel = 0;
    for (int x = minX; x <= maxX; x++) {
        for (int y = minY; y <= maxY; y++) {
            if ( cells[ y * GRID_WIDTH + x ] == threat)
                threatLevel++;
        }
    }
    
    int threshold = 2;

    if (threatLevel > threshold) return threat;
    else return cells[i];
}

void RPSRule::Update(int* cells)
{
    int tmp[CELL_COUNT];

    
    for (int i = 0; i < CELL_COUNT; i++) tmp[i] = rps(cells, i);
    for (int i = 0; i < CELL_COUNT; i++) cells[i] = tmp[i];
}

