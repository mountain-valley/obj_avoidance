#define trigPin 7  // These lines assign names to values
#define echoPin 6  // so they can be easily identified.
#define buzzer 2  // These are set before the code
#define vibrator 3
const int low_range = 60;
const int max_range = 120;
//bool beep = true;

void setup() {
  Serial.begin (9600); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);  
  pinMode(buzzer, OUTPUT);
  pinMode(vibrator, OUTPUT);
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
//      if (beep){
//        do_beep(1);
//      }
//      else {
//        do_vibrate();
//      }
      do_vibrate();
      do_beep(1);
      delay(200);
  }
  else if (distance > 0 and distance < low_range) 
  { 
//      if (beep){
//        do_beep(0);
//      }
//      else {
//        do_vibrate();
//      }

      do_vibrate();
      do_beep(0);
  }
  else
  {
    noTone(buzzer);
    digitalWrite(vibrator, LOW);
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
  Serial.print(distance);
  Serial.println(" cm");
  // For gathering sensor signal data
//  Serial.print(distance);
//  Serial.print(", ");
  return distance;
}

void do_beep(int range){
  /*
   * this beeps differently based on the range value. 
   * "Range" is an int where 0 is the closest range
   */
  if (range == 0){
    tone(buzzer, 35, 50);  // (pin, frequency, duration milliseconds)
  }
  else if (range == 1){
    tone(buzzer, 35, 50);
//    delay(200);
  }
}

void do_vibrate(){
  digitalWrite(vibrator, HIGH);
}
