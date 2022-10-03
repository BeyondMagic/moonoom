#include "main.hpp"
//#include <future>

//int main(int argc, const char* argv[]) {
//  auto screen = ftxui::ScreenInteractive::TerminalOutput();
//  int value = 50;
//  auto slider = ftxui::Slider("Value:", &value, 0, 100, 1);
//  screen.Loop(slider);
//}

auto main (const int argc, const char ** argv) -> int
{

  if (Options::Parse(argc, argv))
    return EXIT_FAILURE;

  Music music;

  music.option("input-default-bindings", "yes");
  music.option("input-vo-keyboard", "yes");
  music.option("osc", MPV_FORMAT_FLAG, 1);
  music.initialise();

  //Screen::setup();
  music.play(Options::song);

}
