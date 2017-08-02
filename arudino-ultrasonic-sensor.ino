/*This function returns the distance from an ultranonic sensor. It 
takes three aruments: the trigger pin, echo pin, and unit of 
measurement. Use "in" for inches, "cm" for centimeters or anything
else for microseconds. This modified from the Ping sketch in the 
Arudino example files.
*/

int getDistance(int trig, int echo, int unit) {

  long duration;
  
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);



  if (unit == "in") {
    return duration / 74 / 2;
  }

  else if (unit == "cm") {
    return duration / 29 / 2; 
  }

  else {
    return duration;
  }
  
  
}


/*This example sets a variable as the distance reading and then
prints it to the serial monitor every second.
*/
void setup() {
  pinMode(7, OUTPUT); //trigger pin
  pinMode(6, INPUT); //echo pin
  Serial.begin(9600); // initialize serial communication:
}

void loop() {
  /* initializes variable distance and sets it to the ultrasonic
  value */ 
  int distance = getDistance(7, 6, "cm");
  Serial.print(distance);
  Serial.println(" centimeters");
}

