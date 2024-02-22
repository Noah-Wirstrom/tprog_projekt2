// defines pins numbers
const int trigPin = 2;
const int echoPin = 3;
const int piezoPin = 9;
// defines variables
long duration;
int distance;
int previousNote = 0;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(piezoPin, INPUT); //Sets the piezoPin as an input
  Serial.begin(9600); // Starts the serial communication
}
void loop() {
  
updateDistance();

updatePiezo();

  }



 void updateDistance() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
}


void updatePiezo(){
  

  // Map distance to a note
  int note = map(distance, 0, 200, 100, 1000);

  // Change note every 5 centimeters
  if (abs(distance - previousNote) >= 5) {
   tone(piezoPin, note, 100);
    previousNote = distance;
    delay(200); // Wait for 200 milliseconds before the next tone
  
   
}
   
  }
  
