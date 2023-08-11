#include <AFMotor.h>
#include <IRremote.h>
#include <Servo.h>

AF_DCMotor motor1(3);
AF_DCMotor motor2(4);

IRrecv IR(A0);
decode_results result;

int Speed = 255;


#define up 10368
#define up2 14464
#define down 10371
#define down2 14467
#define left 10374
#define left2 14470
#define right2 10373
#define right 14469
#define Stop 14494
#define Stop2  10398
#define plus 14530
#define plus2 10434
#define minus 14484
#define minus2 10388
#define SERVO_PIN 10

int RECV_PIN = 3;
Servo servo;

int currentPosition = 0;
const int minPosition = 0;
const int maxPosition = 90;
const int increment = 10;

// Function prototypes
void incrementPosition();
void decrementPosition();


bool validIRSignalReceived = false;

void setup() {


  Serial.begin(9600);
  motor1.setSpeed(Speed);
  motor2.setSpeed(Speed);
  IR.enableIRIn();
  
  servo.attach(SERVO_PIN);
  servo.write(currentPosition);
}

void loop() {
  Serial.println(result.value);
  if (IR.decode(&result)) {
    if (result.value == up) {
      motor1.run(FORWARD);
      motor2.run(BACKWARD);
      validIRSignalReceived = true;
    }
    else if (result.value == up2) {
      motor1.run(FORWARD);
      motor2.run(BACKWARD);
      validIRSignalReceived = true;
    }
    else if (result.value == down) {
      motor1.run(BACKWARD);
      motor2.run(FORWARD);
      validIRSignalReceived = true;
    }
    else if (result.value == down2) {
      motor1.run(BACKWARD);
      motor2.run(FORWARD);
      validIRSignalReceived = true;
    }
    else if (result.value == Stop) {
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      validIRSignalReceived = true;
    }
    else if (result.value == Stop2) {
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      validIRSignalReceived = true;
    }
    else if (result.value == left) {
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      validIRSignalReceived = true;
    }
    else if (result.value == left2) {
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      validIRSignalReceived = true;
    }
    else if (result.value == right) {
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
      validIRSignalReceived = true;
    }
    else if (result.value == right2) {
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
      validIRSignalReceived = true;
    }
    
  if (irrecv.decode()) {
    switch (results.value) {
      case 14530:  // IR code for the + button
        incrementPosition();
        break;
      case 14484:  // IR code for the - button
        decrementPosition();
        break;
      default:
        // Ignore other IR codes (optional)
        break;
    }
    irrecv.resume();
  }
  void incrementPosition() {
  if (currentPosition + increment <= maxPosition) {
    currentPosition += increment;
    servo.write(currentPosition);
    delay(100); // Give the servo some time to move to the new position
  }
}

void decrementPosition() {
  if (currentPosition - increment >= minPosition) {
    currentPosition -= increment;
    servo.write(currentPosition);
    delay(100); // Give the servo some time to move to the new position
  }
}
}

      IR.resume();
    }
  }
}
