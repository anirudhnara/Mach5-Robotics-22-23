/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*  r  Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// L3                   motor         10              
// L2                   motor         12              
// L1                   motor         14              
// R1                   motor         9               
// R2                   motor         19              
// R3                   motor         20              
// LEncoder             encoder       A, B            
// REncoder             encoder       C, D            
// MEncoder             encoder       E, F            
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// hello
// A global instance of competition
competition Competition;

motor_group leftDrive(L1, L2, L3);
motor_group rightDrive(R1, R2, R3);
double Rw = 7.2;
double LPrevPos;
double LCurrentPos=0;
double RPrevPos;
double RCurrentPos=0;
double MPrevPos;
double MCurrentPos = 0;
double angle;
double angleChange;
double totalDistance;
double fieldX;
double fieldY;
double changeFieldX;
double changeFieldY;
double dR;
double d;
double dL;
double dM;
double wheelCircum = 2.75 * 3.1415 / 360;


void OdonTracking(){
  while (true){
    LPrevPos = LCurrentPos;
    RPrevPos = RCurrentPos;
    MPrevPos = MCurrentPos;
    
    LCurrentPos = LEncoder.position(degrees) * 3.1415/180;
    RCurrentPos = REncoder.position(degrees) * -1 * 3.1415/180;  
    MCurrentPos = MEncoder.position(degrees) * 3.1415/180;

    dL = LCurrentPos - LPrevPos;
    dR = RCurrentPos - RPrevPos;
    dM = MCurrentPos - MPrevPos;

    angleChange = ((dR - dL)/Rw) ;
    angle += angleChange;
    d = wheelCircum* (dR+dL)/2;

    fieldX += d * cos(angle);
    //fieldX += dM;
    fieldY += d * sin(angle);

    Brain.Screen.clearLine();
    Brain.Screen.print(fieldX);
    //Brain.Screen.print("--------");
    //Brain.Screen.print(fieldY);

    vex::task::sleep(10);
  }

}

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {

  OdonTracking();
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
