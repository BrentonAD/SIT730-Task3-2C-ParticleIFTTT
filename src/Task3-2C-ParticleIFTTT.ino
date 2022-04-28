/*
 * Project Task3-2C-ParticleIFTTT
 * Description: System to read light level from BH1750 sensor and notify when below a threshold
 * Author: Brenton Adey @BrentonAD
 * Date: 2022-04-28
 */

SerialLogHandler logHandler;

#include "../lib/BH1750Lib/src/BH1750Lib.h"

//initialize device
BH1750Lib bh1750;

int lightLevel;
bool sunUp = TRUE;

void setup() {
  bh1750.begin(BH1750LIB_MODE_CONTINUOUSHIGHRES);

  // Set-up Particle Variable
  Particle.variable("lightLevel", lightLevel);
}

void loop() {
  lightLevel = bh1750.lightLevel();

  Log.info("lightLevel=%d", lightLevel);

  if (lightLevel > 10) {
    if (!sunUp) {
      sunUp = TRUE;
      Particle.publish("sunUp", "The Sun is shining on your terrarium! \\(◦'⌣'◦)/");
    }
  }
  else {
    if (sunUp) {
      sunUp = FALSE;
      Particle.publish("sunUp", "The Sun has stopped shining on your terrarium. (-,-)…zzzZZZ ");
    }
  }

  delay(2000);
}