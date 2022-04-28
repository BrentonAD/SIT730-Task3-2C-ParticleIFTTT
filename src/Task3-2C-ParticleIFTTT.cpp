/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/brent/OneDrive/Documents/_UNIVERSITY/_MASTEROFAI/2022Tri1/SIT730-EmbeddedSystemDevelopment/Tasks/3/SIT730-Task3-2C-ParticleIFTTT/src/Task3-2C-ParticleIFTTT.ino"
/*
 * Project Task3-2C-ParticleIFTTT
 * Description:
 * Author:
 * Date:
 */

void setup();
void loop();
#line 8 "c:/Users/brent/OneDrive/Documents/_UNIVERSITY/_MASTEROFAI/2022Tri1/SIT730-EmbeddedSystemDevelopment/Tasks/3/SIT730-Task3-2C-ParticleIFTTT/src/Task3-2C-ParticleIFTTT.ino"
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