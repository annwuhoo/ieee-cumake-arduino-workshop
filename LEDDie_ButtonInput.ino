/* IEEE Arduino Workshop - LED Die (April 2017)
 *  
 *  Generates a random number upon a button press and displays onto the seven segment display.
 *  Also utilizes button debouncing as described in: https://www.arduino.cc/en/Tutorial/Debounce
 *  
 */

#define TOP_BAR       13
#define TOPRIGHT_BAR  12
#define TOPLEFT_BAR   11
#define MIDDLE_BAR    10
#define BOTRIGHT_BAR  9
#define BOTLEFT_BAR   8
#define BOT_BAR       7

#define BUTTON        2

boolean buttonState = LOW;
boolean lastButtonState = LOW;
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

int randNum = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(TOP_BAR, OUTPUT);
  pinMode(TOPRIGHT_BAR, OUTPUT);
  pinMode(TOPLEFT_BAR, OUTPUT);
  pinMode(MIDDLE_BAR, OUTPUT);
  pinMode(BOTRIGHT_BAR, OUTPUT);
  pinMode(BOTLEFT_BAR, OUTPUT);
  pinMode(BOT_BAR, OUTPUT);
  
  pinMode(BUTTON, INPUT);

  randomSeed(analogRead(0));
  
  Serial.begin(9600); //initializes serial monitor 
  Serial.println("Initialized LED Die. Press the push button to roll the die!");
}

void loop() {
  int reading = digitalRead(BUTTON);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH),  and you've waited
  // long enough since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only generate new random number if buttonState is high
      if (buttonState == HIGH) {
        randNum = random(1, 7); // minimum is inclusive, maximum is exclusive
        Serial.println("Die rolled:");
        Serial.println(randNum);
      }
    }
  }

  // Mirror Die Number onto LEDs
  displayLEDNumber(randNum);

  // Save the reading as lastButtonState
  lastButtonState = reading;

}

// Display the number onto seven segment display
void displayLEDNumber(int num) {
  switch (num) {
    case 1:
      digitalWrite(TOP_BAR, LOW);
      digitalWrite(TOPRIGHT_BAR, HIGH);
      digitalWrite(TOPLEFT_BAR, LOW);
      digitalWrite(MIDDLE_BAR, LOW);
      digitalWrite(BOTRIGHT_BAR, HIGH);
      digitalWrite(BOTLEFT_BAR, LOW);
      digitalWrite(BOT_BAR, LOW);
      break;
      
    case 2:
      digitalWrite(TOP_BAR, HIGH);
      digitalWrite(TOPRIGHT_BAR, HIGH);
      digitalWrite(TOPLEFT_BAR, LOW);
      digitalWrite(MIDDLE_BAR, HIGH);
      digitalWrite(BOTRIGHT_BAR, LOW);
      digitalWrite(BOTLEFT_BAR, HIGH);
      digitalWrite(BOT_BAR, HIGH);
      break;

     case 3:
      digitalWrite(TOP_BAR, HIGH);
      digitalWrite(TOPRIGHT_BAR, HIGH);
      digitalWrite(TOPLEFT_BAR, LOW);
      digitalWrite(MIDDLE_BAR, HIGH);
      digitalWrite(BOTRIGHT_BAR, HIGH);
      digitalWrite(BOTLEFT_BAR, LOW);
      digitalWrite(BOT_BAR, HIGH);
      break;

     case 4:
      digitalWrite(TOP_BAR, LOW);
      digitalWrite(TOPRIGHT_BAR, HIGH);
      digitalWrite(TOPLEFT_BAR, HIGH);
      digitalWrite(MIDDLE_BAR, HIGH);
      digitalWrite(BOTRIGHT_BAR, HIGH);
      digitalWrite(BOTLEFT_BAR, LOW);
      digitalWrite(BOT_BAR, LOW);
      break;

     case 5:
      digitalWrite(TOP_BAR, HIGH);
      digitalWrite(TOPRIGHT_BAR, LOW);
      digitalWrite(TOPLEFT_BAR, HIGH);
      digitalWrite(MIDDLE_BAR, HIGH);
      digitalWrite(BOTRIGHT_BAR, HIGH);
      digitalWrite(BOTLEFT_BAR, LOW);
      digitalWrite(BOT_BAR, HIGH);
      break;

     case 6:
      digitalWrite(TOP_BAR, HIGH);
      digitalWrite(TOPRIGHT_BAR, LOW);
      digitalWrite(TOPLEFT_BAR, HIGH);
      digitalWrite(MIDDLE_BAR, HIGH);
      digitalWrite(BOTRIGHT_BAR, HIGH);
      digitalWrite(BOTLEFT_BAR, HIGH);
      digitalWrite(BOT_BAR, HIGH);
      break; 

    default: // clear LEDs
      digitalWrite(TOP_BAR, LOW);
      digitalWrite(TOPRIGHT_BAR, LOW);
      digitalWrite(TOPLEFT_BAR, LOW);
      digitalWrite(MIDDLE_BAR, LOW);
      digitalWrite(BOTRIGHT_BAR, LOW);
      digitalWrite(BOTLEFT_BAR, LOW);
      digitalWrite(BOT_BAR, LOW);
      break;
      
  }
  
}

