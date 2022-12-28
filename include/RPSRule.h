/*
Copywrite 2022 Holden Haruki Zemsky

This file is part of cell engine citrus.
Cell engine citrus is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Cell engine citrus is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY or even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with cell engine citrus. If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once
#include "UpdateRule.h"

class RPSRule : public UpdateRule {
public:
    RPSRule() = default;
    RPSRule(const RPSRule&) = default;
    RPSRule& operator= (const RPSRule&) = default;
    ~RPSRule() = default;

    void Update(int* cells);
};