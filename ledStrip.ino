/*
  12V LED Light Strip Controller 
  Andrew Munt 12/5/21
  This script is used to automate an LED strip attatched to a hallway ceiling
  A photoresistor is attached to the A0 pin of an Arduino to detect for darkness 
  and a PIR motion detector is used to detect human movement to turn the light on
  when someone approaches in the dark
*/

// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A0;  // Analog input pin for the LDR
const int photoThresh = 110;	// Threshold hold for darkness

// Pin declerations
const int relayOut = 3;	
const int pirIn = 2;
bool pirVal = 0;

int photoVal = 0;        // value read from the pot

void setup() {
	// initialize serial communications at 9600 bps:
	Serial.begin(9600);
	pinMode(relayOut, OUTPUT);
	pinMode(pirIn, INPUT);
	pinMode(analogInPin, INPUT);
}

void loop() {
	// Read the LDR and motion detector inputs
	photoVal = analogRead(analogInPin);
	pirVal = digitalRead(pirIn);

	// Turn on the light strip if motion is detected and it is dark
	if((photoVal > photoThresh) && pirVal)
	{
		Serial.println("Turning light on");
		digitalWrite(relayOut, HIGH);  
	}
	else
	{
		Serial.println("Turning light off");
		digitalWrite(relayOut, LOW); 
	}
}
