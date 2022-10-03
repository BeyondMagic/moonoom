#include <args.hxx>
#include <fstream>
#include <sstream>
#include <filesystem>

#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/table.hpp>
#include <ftxui/screen/screen.hpp>

namespace Options {

  namespace Print {

    namespace Error {

      inline auto file ( std::string message ) -> bool {

        std::cerr << "Failed file parsing: " << message << "\n";

        return true;

      }

      inline auto song ( std::string message ) -> bool {

        std::cerr << "Failed song's file parsing: " << message << "\n";

        return true;

      }

      inline auto parsing (const char * what ) -> bool {

        std::cerr << "Invalid arguments.\n" << what << "\n";

        return true;

      }

    }

    inline auto version ( void ) -> bool {

      std::cout << "2022-10-02 0.0.1\n";

      return true;

    }

    inline auto help ( args::ArgumentParser & args ) -> bool {

      std::cout << args;

      return true;

    }

    inline auto keybinding ( void ) -> bool {

      auto table = ftxui::Table(std::vector<std::vector<std::string>>{
          {"keys", "action"},
          //
          {"Navigate", "← ↑ ↓ →"},
          {"", "h j k l "},
          {"", "Mouse::WheelUp"},
          {"", "Mouse::WheelDown"},
          //
          {"Toggle", "enter"},
          {"", "Mouse::Left"},
          //
          {"Exit", "Escape"},
          {"", "q"},
          //
          {"Navigate", ""},
          {" - first", "page-up"},
          {" - last", "page-down"},
          {" - top", "gg"},
          {" - bottom", "G"},
          //
      });

      table.SelectRows(0, 0).DecorateCells(color(ftxui::Color::Cyan));
      table.SelectRows(1, 4).Border(ftxui::LIGHT);
      table.SelectRows(5, 6).Border(ftxui::LIGHT);
      table.SelectRows(7, 8).Border(ftxui::LIGHT);
      table.SelectRows(9, 13).Border(ftxui::LIGHT);
      table.SelectAll().SeparatorVertical(ftxui::LIGHT);
      table.SelectAll().Border(ftxui::LIGHT);

      auto document = table.Render();
      auto screen = ftxui::Screen::Create(ftxui::Dimension::Fit(document));

      Render(screen, document);

      screen.Print();

      std::cout << "\n";

      return true;

    }

  }

  static std::string song;
  static std::string map;

  // -- Definitions.
  auto Parse ( const int count, const char ** arguments) -> bool
  {

    args::ArgumentParser args("");

    args.Prog("TTYist");

    args.Description("A 4K osu terminal player.");

    args.Epilog(
        "Two files are passed, one for the song, and another for the map.\n"
        "\n"
        "Please report bugs to: "
        "https://github.com/BeyondMagic/TTYist");

    args::ValueFlag<std::string> file(args, "file", "A .osu file.", {'m', "map"});
    args::ValueFlag<std::string> music(args, "song", "A file supported by MPV.", {'s', "song"});

    args::Flag help       (args, "help",       "Display this help menu.", {'h', "help"});
    args::Flag version    (args, "version",    "Print version.",          {'v', "version"});
    args::Flag keybinding (args, "keybinding", "Display key binding.",    {'k', "key", "keybinding"});

    try {
      args.ParseCLI(count, arguments);
    }
    catch (args::Help const &) {
      return Print::help(args);
    }

    catch (args::ParseError const &e) {
      return Print::Error::parsing(e.what());
    }

    catch (args::ValidationError const &e) {
      return Print::Error::parsing(e.what());
    }

    if (version)
      return Print::version();

    if (keybinding)
      return Print::keybinding();

    if (help)
      return Print::help(args);

    if (!file)
      return Print::Error::file("No file was provided for the map.");

    else {

      map = args::get(file);

      auto file_stream = std::ifstream(map);

      if (!file_stream)
        return Print::Error::file("Could not read the file '" + map + "'.");

      std::stringstream string_stream;

      string_stream << file_stream.rdbuf();

      map = string_stream.str();

    }

    if (!music)
      return Print::Error::song("No file was provided for the song.");

    else {

      song = args::get(music);

      std::filesystem::path song_path{song};
    
      if (!std::filesystem::exists(song_path))
        return Print::Error::song("Could not read the file '" + song + "'.");

    }



    return false;

  }

}
