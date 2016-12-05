#ifndef RENDERER_H
#define RENDERER_H

#include "SDL.h"

#ifndef EVENT_POLL_SIZE
  #define EVENT_POLL_SIZE 4
#endif

void setupScreen();
void cleanup();

#endif
