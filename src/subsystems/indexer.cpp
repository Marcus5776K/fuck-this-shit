#include "main.h"

using namespace okapi;

pros::ADIDigitalOut indexer(indexerPort);


void updateIndexer() {

   if (controller.getDigital(ControllerDigital::A) == 1) {
       indexer.set_value(false);
       pros::delay(100);
       indexer.set_value(true);
   }

}