#pragma once

#include <array>

// UI library.
#include "ftxui/dom/elements.hpp"
#include "ftxui/screen/screen.hpp"
#include "ftxui/screen/string.hpp"

#define LANE const static std::pair<const char, const ftxui::Color>

namespace Config {

  //char * exit 'ESC';
  //char restart 'R';

  static constexpr char quit {'Q'};

  namespace Lanes {

    LANE inactive = { ' ', ftxui::Color::RGB(111, 111, 111)};

    LANE a = { 'D', ftxui::Color::RGB(25, 69, 85)};
    LANE b = { 'F', ftxui::Color::RGB(75, 36, 10)};
    LANE c = { 'J', ftxui::Color::RGB(0, 0, 0)};
    LANE d = { 'K', ftxui::Color::RGB(255, 255, 255)};

  };

};
