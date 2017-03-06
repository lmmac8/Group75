int ledpin = 13;
int inputpin = 2;
int pirstate = LOW;
int val = 0;

void setup() {
  //sets the output pin to 12 which is represented by the LED
  //Sets input to motion sensor in pin 2
  pinMode(ledpin,OUTPUT);
  pinMode(inputpin,INPUT);
  Serial.begin(9600);
  
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  //if motion is detected the LED is turned on and "Motion Detected" is printed in the console
    val = digitalRead(inputpin);
    if (val == HIGH) {
      digitalWrite(ledpin, HIGH);
      if (pirstate == LOW) {
        Serial.println("Motion Detected");
        pirstate = HIGH;
      }
    } else {
      //Once the motion detector senses no more motion the LED turns off and "Motion Ended" is printed
      digitalWrite(ledpin, LOW);
      if (pirstate == HIGH){
        Serial.println("Motion Ended");
        pirstate = LOW;
        }
      }
}


