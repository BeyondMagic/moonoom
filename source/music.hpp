#pragma once

#include <mpv/client.h>
#include <iostream>

class Music {

  private:

    mpv_handle *ctx;
  
    static inline auto check(int status) -> void
    {
        if (status < 0)
          error(mpv_error_string(status));
    }

    static inline auto error (std::string a) -> void
    {

      std::cout << "Music.hpp: " << a << "\n";
      exit(1);

    }

  public:

    auto option( std::string , std::string ) -> void;
    auto option( std::string , mpv_format, int ) -> void;
    auto play(std::string song) -> void;
    auto initialise(void) -> void;

    Music();

    ~Music();

};

auto Music::option( std::string option, std::string value ) -> void
{

  check(mpv_set_option_string(ctx, option.c_str(), value.c_str()));

}

auto Music::option( std::string option, mpv_format flag, int value) -> void
{

  check(mpv_set_option(ctx, option.c_str(), flag, &value));

}

auto Music::initialise(void) -> void
{

  check(mpv_initialize(ctx));

}

auto Music::play(std::string song) -> void
{

  const char *cmd[] = { "loadfile", song.c_str(), NULL };

  check(mpv_command(ctx, cmd));

  while (true)
  {
    
    mpv_event *event = mpv_wait_event(ctx, 10000);

    std::cout << "event: " << mpv_event_name(event->event_id) << "\n";

    if (event->event_id == MPV_EVENT_SHUTDOWN)
      break;

  }

}

Music::Music()
{

  ctx = mpv_create();

  if (!ctx)
    error("Could not create the context.");

}

Music::~Music()
{

  mpv_terminate_destroy(ctx);

}
