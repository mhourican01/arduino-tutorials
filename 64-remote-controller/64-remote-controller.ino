#include <IRremote.h>
int irPin = 9;
int delayT = 1500;
String myCmd;
IRrecv ir(irPin);
decode_results cmd;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ir.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
  while (ir.decode(&cmd) == 0) {
    
  }

  Serial.println(cmd.value, HEX);
  delay(delayT);
  ir.resume();

  if (cmd.value == 0xFF6897) {
    Serial.println("You pressed 0.");
  } else if (cmd.value == 0xFF30CF) {
    Serial.println("You pressed 1."); 
  }
  // etc.
}
