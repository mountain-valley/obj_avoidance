#define trigPin 11  // These lines assign names to values
#define echoPin 10  // so they can be easily identified.
#define ultrasonic 12  // These are set before the code
const int low_range = 30;
const int max_range = 100;

void setup() {
  Serial.begin (9600); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);  
  pinMode(ultrasonic, OUTPUT);
  //pinMode(buttonPin, INPUT);
}

/* The remaining part of the code runs in a constant loop.
 * It triggers the ultrasonic sensor and calculates the
 * time it took for the sound waves to return.  It converts
 * the time in milliseconds into distance in centimeters.
 */
void loop() { 
  long distance = get_distance();
  
  // This part of the code below determines whether to
  // beep depending on the distance detected. If the object
  // is within 62 start the beeps.
    
  if(distance > low_range and distance < max_range) { 
      tone(ultrasonic, 35, 50);  // (pin, frequency, duration milliseconds)
      delay(200);
  }
  else if (distance > 0 and distance < low_range) 
  { 
      tone(ultrasonic, 35, 50);
  }
  else
  {
    noTone(ultrasonic);
  }
} 

long get_distance() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2)* 0.035;
//  Serial.print(distance);
//  Serial.println(" cm");
  // For gathering sensor signal data
  Serial.print(distance);
  Serial.print(", ");
  return distance;
}
