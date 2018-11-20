#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 3;

int green = 12;
int red = 13;
int yellow = 4;
int counter = 0;

String codeString;
String correctString = "8008135";

char code[5];

char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = {5,6,7,8};
byte colPins[COLS] = {9,10,11};


Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);  
   pinMode(green, OUTPUT);  
   pinMode(red, OUTPUT);  
   pinMode(yellow, OUTPUT);  
}
  
void loop(){
  char key = keypad.getKey();
    // just print the pressed key
   if (key){
    Serial.println(key);
    counter++;
    code[counter] = key;
    codeString = codeString + code[counter];
    Serial.println(codeString);
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);  
    digitalWrite(yellow, LOW);  
  } 
  
  if (codeString == correctString){
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);    
    digitalWrite(yellow, LOW);
    Serial.println("CORRECT!");   
  }

  if(codeString.length() >= correctString.length() && codeString != correctString){    
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);    
    digitalWrite(yellow, LOW);  
    Serial.println("error!");   
    codeString = "";
    }

    else{      
    digitalWrite(green, LOW);
    digitalWrite(red, LOW);    
    digitalWrite(yellow, HIGH);  
      }


   

}
    
