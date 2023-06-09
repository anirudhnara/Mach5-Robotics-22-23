using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor l1;
extern motor l2;
extern motor l3;
extern motor r1;
extern motor r2;
extern motor r3;
extern inertial Inertial;
extern digital_out shoota;
extern digital_out DigitalOutH;
extern encoder lEncoder;
extern encoder rEncoder;
extern encoder mEncoder;
extern triport Expander8;
extern motor flywheel;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );