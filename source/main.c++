#include "main.hpp"
#include <future>

//int main(int argc, const char* argv[]) {
//  auto screen = ftxui::ScreenInteractive::TerminalOutput();
//  int value = 50;
//  auto slider = ftxui::Slider("Value:", &value, 0, 100, 1);
//  screen.Loop(slider);
//}

auto main (const int argc, const char ** argv) -> int
{

  // 1.
  if (Options::Parse(argc, argv))
    return EXIT_FAILURE;

  // 2.
  Music music;

  music.option("input-default-bindings", "yes");
  music.option("input-vo-keyboard", "yes");
  music.option("osc", MPV_FORMAT_FLAG, 1);
  music.initialise();

  // 3.
  auto playing = std::async(&Music::play, music, Options::song);

  //Screen::setup();

  playing.get();

}
