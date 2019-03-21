/* Arduino code for determining the basic 
RED, GREEN and BLUE colors and printing the 
detected color on serial monitor */

// TCS3200 pins wiring to Arduino
const int S0 = 4, S1 = 5, S2 = 6, S3 = 7;
const int sensorOut = 8;

// Stores frequency read by the photodiodes
int redF = 0;
int greenF = 0;
int blueF = 0;

void setup() 
{
  // Setting the outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  
  // Setting the sensorOut as an input
  pinMode(sensorOut, INPUT);
  
  // Setting frequency scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
   // Begins serial communication 
  Serial.begin(9600);
}

void loop() 
{
  // Setting RED (R) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  redF = pulseIn(sensorOut,LOW);
  
  // Setting GREEN (G) filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  greenF = pulseIn(sensorOut,LOW);
 
  // Setting BLUE (B) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  blueF = pulseIn(sensorOut,LOW);

  if(greenF > redF && blueF > redF && redF <= 35)
  {
    Serial.println("RED color detected");
  }

  else if(greenF > blueF && redF > blueF && blueF <= 35)
  {
    Serial.println("BLUE color detected");
  }
  
  else if(blueF <= 45 && redF > greenF && greenF <= 50)
  {
    Serial.println("GREEN color detected");
  }
  
  else
    ;
}
