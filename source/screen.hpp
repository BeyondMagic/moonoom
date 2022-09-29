#pragma once

#include <iostream>

// UI library.
#include "ftxui/dom/elements.hpp"
#include "ftxui/screen/screen.hpp"
#include "ftxui/screen/string.hpp"

#include "config.hpp"

namespace Screen {

  void setup () {

    // For the whole screen.
    auto screen = ftxui::Screen::Create(
      ftxui::Dimension::Full(),
      ftxui::Dimension::Full()
    );

    // Define the document.
    ftxui::Element document = ftxui::hbox({
        
        ftxui::text("left") | ftxui::bgcolor(ftxui::Color::Red1)  | ftxui::border,

        // Space for lanes.
        ftxui::vbox({
          ftxui::text("volcano") | ftxui::border | ftxui::flex,

          // Lanes.
          ftxui::hbox({

              // A.
              ftxui::text("        ") | ftxui::bgcolor(Config::Lanes::a.second),

              // A.
              ftxui::text("        ") | ftxui::bgcolor(Config::Lanes::b.second),

              // A.
              ftxui::text("        ") | ftxui::bgcolor(Config::Lanes::c.second),

              // A.
              ftxui::text("        ") | ftxui::bgcolor(Config::Lanes::d.second),

          }) | ftxui::border

        }) | ftxui::flex_grow,

        ftxui::text("right")  | ftxui::border,

    });


    Render(screen, document);
    screen.Print();

  }

}
