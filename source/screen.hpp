#pragma once

#include <iostream>

// UI library.
#include "ftxui/dom/elements.hpp"
#include "ftxui/screen/screen.hpp"
#include "ftxui/screen/string.hpp"
#include "ftxui/component/captured_mouse.hpp"      // for ftxui
#include "ftxui/component/component.hpp"           // for Slider
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive

#include "config.hpp"

namespace Screen
{

  auto setup () -> void
  {

    // For the whole screen.
    auto screen = ftxui::ScreenInteractive::Fullscreen();

    // Define the document.
    auto document = ftxui::Container::Vertical({
        
        ftxui::text("left") | ftxui::flex | ftxui::border,

        // Space for lanes.
        ftxui::hbox({

            // A.
            ftxui::vbox({ 
              ftxui::text("        ") | ftxui::flex_grow,
              ftxui::text("        ") | ftxui::bgcolor(Config::Lanes::inactive.second),
              ftxui::text("        ") | ftxui::bgcolor(Config::Lanes::inactive.second)
            }) | ftxui::flex_grow,

            ftxui::separatorCharacter(" "),

            // B.
            ftxui::vbox({
              ftxui::text("        ") | ftxui::flex_grow,
              ftxui::text("        ") | ftxui::bgcolor(Config::Lanes::inactive.second),
              ftxui::text("        ") | ftxui::bgcolor(Config::Lanes::inactive.second)
            }) | ftxui::flex_grow,

            ftxui::separatorCharacter(" "),
            
            // C.
            ftxui::vbox({
              ftxui::text("        ") | ftxui::flex_grow,
              ftxui::text("        ") | ftxui::bgcolor(Config::Lanes::inactive.second),
              ftxui::text("        ") | ftxui::bgcolor(Config::Lanes::inactive.second)
            }) | ftxui::flex_grow,

            ftxui::separatorCharacter(" "),

            // D.
            ftxui::vbox({
              ftxui::text("        ") | ftxui::flex_grow,
              ftxui::text("        ") | ftxui::bgcolor(Config::Lanes::inactive.second),
              ftxui::text("        ") | ftxui::bgcolor(Config::Lanes::inactive.second)
            }) | ftxui::flex_grow,

        }) | ftxui::border,

        ftxui::text("right") | ftxui::flex | ftxui::border,

    });


    //Render(screen, document);
    screen.Loop(document);

  }

}
