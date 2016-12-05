#ifndef KEYHANDLER_H
#define KEYHANDLER_H

#include "SDL.h"

#ifndef EVENT_POLL_SIZE
  #define EVENT_POLL_SIZE 4
#endif

SDL_KeyboardEvent *currentKeys();


#endif
