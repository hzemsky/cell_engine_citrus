/*
Copywrite 2022 Holden Haruki Zemsky

This file is part of cell engine citrus.
Cell engine citrus is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Cell engine citrus is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY or even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with cell engine citrus. If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

class UpdateRule {
public:
    UpdateRule() = default;
    UpdateRule(const UpdateRule&) = default;
    virtual UpdateRule& operator= (const UpdateRule&) = default;
    virtual ~UpdateRule() = default;

    virtual void Update(int* cells) = 0;
};