#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor L3 = motor(PORT10, ratio18_1, false);
motor L2 = motor(PORT12, ratio18_1, false);
motor L1 = motor(PORT14, ratio18_1, false);
motor R1 = motor(PORT9, ratio18_1, false);
motor R2 = motor(PORT19, ratio18_1, false);
motor R3 = motor(PORT20, ratio18_1, false);
encoder LEncoder = encoder(Brain.ThreeWirePort.A);
encoder REncoder = encoder(Brain.ThreeWirePort.C);
encoder MEncoder = encoder(Brain.ThreeWirePort.E);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}