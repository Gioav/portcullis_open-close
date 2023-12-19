/*With this code i can check if an object has passed in between the receiver and the emitter
if an object pass then the motor start and open the portcullis*/

#include <IRremote.h>

// Define IR receiver pin
#define IR_RECEIVER_PIN 2
// Define motor control pins
#define MOTOR_PIN 3
// Define IR emitter pin
#define IR_EMITTER_PIN 4

// Create an IRremote object
IRrecv irrecv(IR_RECEIVER_PIN);
decode_results results;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  // Initialize IR receiver
  irrecv.enableIRIn();
  // Initialize motor control pin
  pinMode(MOTOR_PIN, OUTPUT);
  // Initialize IR emitter pin
  pinMode(IR_EMITTER_PIN, OUTPUT);
}

void loop() {
  // Check if IR signal is received
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);

    if (results.value == 0x12345678) {  // Replace with your actual IR code
      digitalWrite(MOTOR_PIN, HIGH);
      delay(2000);
      digitalWrite(MOTOR_PIN, LOW);

      // Turn on IR emitter
      digitalWrite(IR_EMITTER_PIN, HIGH);
      delay(1000);
      digitalWrite(IR_EMITTER_PIN, LOW);
    }
    irrecv.resume();
  }
}
