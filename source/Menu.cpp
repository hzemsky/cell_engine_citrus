/*
Copywrite 2022 Holden Haruki Zemsky

This file is part of cell engine citrus.
Cell engine citrus is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Cell engine citrus is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY or even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with cell engine citrus. If not, see <https://www.gnu.org/licenses/>.
*/

#include "Menu.h"

#define RUN             "Run simulation"
#define RULE_RPS        " Rock Paper Scissors "
#define COLOR_RGB       " Red Green Blue      "
#define COLOR_PURPLES   " Purples             "
#define COLOR_PREVIEW_RGB "\x1b[31;41mR\x1b[0m\x1b[32;42mG\x1b[0m\x1b[34;44mB\x1b[0m"
#define COLOR_PREVIEW_PURPLES "\x1b[34;44mR\x1b[0m\x1b[34;44mG\x1b[0m\x1b[34;44mB\x1b[0m"

Menu::Menu()
    : quitApp(false), running(true), colorUpdateNeeded(false),
    selectedSetting(Setting::Rule),
    rule(Rule::RPS), rule_s(RULE_RPS),
    color(ColorScheme::RGB), color_s(COLOR_RGB), color_preview_s(COLOR_PREVIEW_RGB),
    needsUpdate(true)
{

}

Menu::~Menu()
{

}

void Menu::updateStrings() {
    switch (color) {
    case ColorScheme::RGB:
        color_s = COLOR_RGB;
        color_preview_s = COLOR_PREVIEW_RGB;
        break;
    case ColorScheme::Purples:
        color_s = COLOR_PURPLES;
        color_preview_s = COLOR_PREVIEW_PURPLES;
    }
    needsUpdate = true;
}

void Menu::print()
{
    if (needsUpdate) {
        needsUpdate = false;
        updateStrings();
        consoleClear();
        switch (selectedSetting) {
        case Setting::Rule:
            printf("\x1b[2;1H Welcome to cell engine citrus v0");
            printf("\x1b[4;1H Rule:   \x1b[47;30m <%s> \x1b[0m", rule_s.c_str());
            printf("\x1b[5;1H Colors:   %s   %s", color_s.c_str(), color_preview_s.c_str());
            printf("\x1b[6;1H Quit");
            break;
        case Setting::Color:
            printf("\x1b[2;1H Welcome to cell engine citrus v0");
            printf("\x1b[4;1H Rule:     %s", rule_s.c_str());
            printf("\x1b[5;1H Colors: \x1b[47;30m <%s> \x1b[0m %s", color_s.c_str(), color_preview_s.c_str());
            printf("\x1b[6;1H Quit");
            break;
        case Setting::Quit:
            printf("\x1b[2;1H Welcome to cell engine citrus v0");
            printf("\x1b[4;1H Rule:     %s", rule_s.c_str());
            printf("\x1b[5;1H Colors:   %s   %s", color_s.c_str(), color_preview_s.c_str());
            printf("\x1b[6;1H Quit    \x1b[47;30m   press A to quit      \x1b[0m");
            break;
        }
    }
}

void Menu::select()
{
    needsUpdate = true;
    switch(selectedSetting) {
    case Setting::Quit:
        quitApp = true;
        break;
    }
}

void Menu::scrollUp()
{
    selectedSetting--;
    if (selectedSetting < 0) selectedSetting = Setting::Quit;
    needsUpdate = true;
}

void Menu::scrollDown()
{
    selectedSetting++;
    if (selectedSetting > Setting::Quit) selectedSetting = Setting::Rule;
    needsUpdate = true;
}

void Menu::plus()
{
    switch(selectedSetting) {
    case Setting::Rule:
        break;
    case Setting::Color:
        color++;
        if (rule == Rule::RPS && color > ColorScheme::Purples) color = ColorScheme::RGB;
        colorUpdateNeeded = true;
        updateStrings();
        break;
    }
}

void Menu::minus()
{
    switch(selectedSetting) {
    case Setting::Rule:
        break;
    case Setting::Color:
        color--;
        if (rule == Rule::RPS && color < ColorScheme::RGB) color = ColorScheme::Purples;
        colorUpdateNeeded = true;
        updateStrings();
        break;
    }
}