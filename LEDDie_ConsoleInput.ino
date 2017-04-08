/* IEEE Arduino Workshop - LED Die (April 2017)
 *  
 *  Generates a random number upon a button press and displays onto the seven segment display.
 *  Uses console as input: https://www.arduino.cc/en/Serial/read
 *  
 */

#define TOP_BAR       13
#define TOPRIGHT_BAR  12
#define TOPLEFT_BAR   11
#define MIDDLE_BAR    10
#define BOTRIGHT_BAR  9
#define BOTLEFT_BAR   8
#define BOT_BAR       7

#define CR 13
char stringInput[10];

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
  
  randomSeed(analogRead(0));
  
  Serial.begin(9600); //initializes serial monitor 
  Serial.println("Initialized LED Die. Enter something in the console to roll the die!");
}

void loop() {

  // only generate new random number if there is console input
  if (Serial.available() > 0) {
    //Serial.readBytesUntil(CR, stringInput, 10); // flush string - slow!

    while (Serial.read() != -1) { // flush buffer byte by byte
      delay(10); // seems to need this to delay conditional check
    }
    
    randNum = random(1, 7); // minimum is inclusive, maximum is exclusive
    Serial.println("Die rolled:");
    Serial.println(randNum);

  }

  // Mirror Die Number onto LEDs
  displayLEDNumber(randNum);

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

