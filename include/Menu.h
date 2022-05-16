/*
Copywrite 2022 Holden Haruki Zemsky

This file is part of cell engine citrus.
Cell engine citrus is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Cell engine citrus is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY or even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with cell engine citrus. If not, see <https://www.gnu.org/licenses/>.
*/

#include <3ds.h>
#include <string>

enum Setting { Rule = 0, Color, Quit };

enum Rule { RPS = 0 };

enum ColorScheme { BW = 0, RGB, Purples };

class Menu {
public:
    Menu();
    Menu(const Menu&) = delete;
    Menu& operator= (const Menu&) = delete;
    ~Menu();

    void scrollUp();
    void scrollDown();
    void plus();
    void minus();
    void select();

    void updateStrings();
    void print();

    // Menu updates public bools, and Main() does these based on whether they're set
    bool quitApp;
    bool running;
    bool colorUpdateNeeded;

    // settings. strings are for printing to console
    int selectedSetting;
    int rule;
    std::string rule_s;
    int color;
    std::string color_s;
    std::string color_preview_s;

private:
    bool needsUpdate; // only update console when it changes
};