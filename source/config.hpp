#pragma once

#include <array>

// UI library.
#include "ftxui/dom/elements.hpp"
#include "ftxui/screen/screen.hpp"
#include "ftxui/screen/string.hpp"

//#define CONFIG_PATH "config.json"

namespace Config {

  //char * exit 'ESC';
  //char restart 'R';

  static constexpr char quit {'Q'};

  namespace Lanes {

    const static std::pair<const char, const ftxui::Color> a = {'D', ftxui::Color(25, 69, 85)};
    const static std::pair<const char, const ftxui::Color> b = {'F', ftxui::Color(75, 36, 10)};
    const static std::pair<const char, const ftxui::Color> c = {'J', ftxui::Color(0, 0, 0)};
    const static std::pair<const char, const ftxui::Color> d = {'K', ftxui::Color(100, 100, 100)};

  };

};
