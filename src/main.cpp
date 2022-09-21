#include "jazzlights/config.h"

#ifdef JAZZLIGHTS_PLATFORMIO

#include <Arduino.h>

#include "jazzlights/vest.h"

void setup() { jazzlights::vestSetup(); }

void loop() { jazzlights::vestLoop(); }

#endif  // JAZZLIGHTS_PLATFORMIO
