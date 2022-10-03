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
    auto document = ftxui::Container::Horizontal({
        
        ftxui::text("left") | ftxui::flex | ftxui::border,

        ftxui::text("right") | ftxui::flex | ftxui::border,

    });


    //Render(screen, document);
    screen.Loop(document);



  }

}
