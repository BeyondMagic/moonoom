#pragma once

#include <mpv/client.h>
#include <iostream>

#define loop while (true)

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

    auto option( std::string option, std::string value ) -> void
    {

      check(mpv_set_option_string(ctx, option.c_str(), value.c_str()));

    }

    auto option( std::string option, mpv_format flag, int value) -> void
    {

      check(mpv_set_option(ctx, option.c_str(), flag, &value));

    }

    auto initialise(void) -> void
    {

      check(mpv_initialize(ctx));

    }

    auto play(std::string song) -> void
    {

      const char *cmd[] = { "loadfile", song.c_str(), NULL };

      check(mpv_command(ctx, cmd));

      loop {
        
        mpv_event *event = mpv_wait_event(ctx, 10000);

        std::cout << "event: " << mpv_event_name(event->event_id) << "\n";

        if (event->event_id == MPV_EVENT_SHUTDOWN)
          break;

      }

    }

    Music()
    {

      ctx = mpv_create();

      if (!ctx)
        error("Could not create the context.");

    }

    ~Music()
    {

      mpv_terminate_destroy(ctx);

    }


};
