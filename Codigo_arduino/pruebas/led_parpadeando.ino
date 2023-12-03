int led=13;

void setup() {
  pinMode(led, OUTPUT); // Initialize the GPIO2 pin as an output
}

void loop() {
  digitalWrite(led, HIGH); // Turn the LED on (Note that LOW is the voltage level, but actually, the LED is on)
  delay(1500); // Wait for a second
  digitalWrite(led, LOW); // Turn the LED off by making the voltage HIGH
  delay(500); // Wait for two seconds
}