#include <fstream>
#include <sstream>

namespace LaneLine {

  // Note: The following values are valid.
  //       064, // 1st lane.
  //       192, // 2nd lane.
  //       320, // 3rd lane.
  //       448, // 4th lane.
  int lane;

}

class Osu {
  
  private:

  public:

    auto read ( std::ifstream & ) -> void;



};

auto Osu::read (std::ifstream & file) -> void
{

  std::string line;
  bool calculate {false};

  while (std::getline(file, line))
  {

    // Only start calculating past "[HitObjects]" line.
    if (line == "[HitObjects]")
      calculate = true;

    else if (calculate)
    {

      std::stringstream ss(line);

      ss >> LaneLine::lane;

      ss >> 

    }



  }

}
