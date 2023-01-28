#include "functions.h"

using namespace vex;

void Skills(){
  thread display(printHeading);
  
  vex::task runPId(startup);
  
  fullDrive.spinFor(reverse, 0.25, sec, 50, rpm);
  fullDrive.stop(hold);
  wait(0.15, sec);
  rollToColor();
  
  rightDrive.spinFor(150, degrees, 60, rpm);
  Intake.spin(forward, 100,percent);
  turn(-36);
  cosdrive(26, 35);
  turn(90);
  Intake.stop();
  fullDrive.spinFor(reverse, 0.675, sec, 40, rpm);
  fullDrive.stop();
  wait(0.15, sec);
  rollToColor();
  
  enableFlyPID = true;
  rotateSpeed = 2300;
  enableLogistic = false;
  
  vex::task runPID(FlyWheelPIDRPM);
  
  cosdrive(16, 25);
  Intake.spin(forward, 100, percent);
  turn(0);
  cosdrive(48, 68);
  Flap.set(true);
  turn(-11);
  Intake.stop();
  tripleshot();
  enableFlyPID = false;
  
  cosdrive(-3.5, 10);
  turn(87);
  Intake.spin(forward, 100, percent);
  cosdrive(103, 65);
  turn(0);
  cosdrive(56, 65);
  wait(1, sec);
  cosdrive(-13, 30);
  turn(-90);

  vex::task runpId(startup);
  cosdrive(-10, 20);
  Intake.stop();
  fullDrive.spinFor(reverse, 0.95, sec, 25, rpm);
  fullDrive.stop(hold);
  rollToColor();
  wait(0.2, seconds);
  
  cosdrive(21, 30);
  //Intake.spin(forward, 100, percent);
  turn(-180);
  cosdrive(-17, 30);
  //Intake.stop();
  fullDrive.spinFor(reverse, 1, sec, 25, rpm);
  fullDrive.stop();
  rollToColor();
  

  enableFlyPID = true;
  rotateSpeed = 2300;
  vex::task runpID(FlyWheelPIDRPM);
  cosdrive(71, 68);
  rotateSpeed = 2300;
  Flap.set(true);
  turn(-197.5);
  tripleshot();

  
  turn(-180);
  cosdrive(-57, 80);
  turn(-135);
  cosdrive(-12, 20);

  Expansion.set(true);


}

//------------------- 15 Seconds -----------------------------------------------------------


void OnRoller(){
  vex::task runPId(startup);
  
  fullDrive.spinFor(reverse, 0.25, sec, 50, rpm);
  fullDrive.stop(hold);
  wait(0.15, sec);
  Intake.spinFor(0.3, seconds);
  Intake.stop();
  rollToColor();
  cosdrive(8, 20);
  turn(-10);
  rotateSpeed = 2650;
  vex::task RunPid(FlyWheelPIDRPM);
  wait(4, seconds);
  //tripleshot();
  Intake.spinFor(reverse, 0.9, seconds, 50, rpm);
  wait(3.5, seconds);
  Intake.spinFor(reverse, 0.9, seconds, 50, rpm);
  rotateSpeed = 2000;
}

void OffRoller(){
  vex::task runPID(startup);
  Intake.spin(forward, 100, percent);
  cosdrive(33, 70);
  //turn(20);
  rotateSpeed = 2755;
  vex::task RUNPID(FlyWheelPIDRPM);
  //wait(4, seconds);
  //tripleshot();
  turn(-45);
  cosdrive(-43, 60);
  turn(0);
  Intake.stop();

  fullDrive.spinFor(reverse, 0.355, sec, 50, rpm);
  fullDrive.stop(hold);
  wait(0.15, sec);
  rollToColor();
  cosdrive(7, 20);
  turn(8);

  Intake.spinFor(reverse, 0.9, seconds, 50, rpm);
  wait(2, seconds);
  Intake.spinFor(reverse, 0.9, seconds, 50, rpm);
  wait(2, seconds);
  Intake.spinFor(reverse, 0.9, seconds, 50, rpm);
  Flywheel.spin(forward, 2000, rpm);
  rotateSpeed = 2000;
  
}

timer time15;
void Win(){
  time15.reset();
  task runPID(startup);
  fullDrive.spinFor(reverse, 0.25, sec, 50, rpm);
  fullDrive.stop(hold);
  rollToColor();
  fullDrive.spinFor(forward, 0.20, sec, 80, rpm);
  turn(44, true);
  cosdrive(146, 100);

  rotateSpeed = 2730;
  task RUNPID(FlyWheelPIDRPM);

  rightDrive.spinFor(forward, 0.2, sec, 90, rpm);
  fullDrive.spinFor(reverse, 0.20, sec, 50, rpm);
  turn(-90, true);
  cosdrive(-13, 40);
  fullDrive.spinFor(reverse, 0.25, sec, 50, rpm);
  fullDrive.stop();
  rollToColor();

  cosdrive(10, 30);
  turn(-83, true);
  Intake.spinFor(reverse, 0.9, seconds, 50, rpm);
  waitUntil(time15.time(sec) > 14);
  Intake.spinFor(reverse, 0.9, seconds, 50, rpm);
  Flywheel.spin(forward, 2000, rpm);
  rotateSpeed = 2000;
}