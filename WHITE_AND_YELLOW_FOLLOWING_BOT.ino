const int s0 = 8;  
const int s1 = 9;  
const int s2 = 12;  
const int s3 = 11;  
const int out = 10;   
// LED pins connected to Arduino 
// Variables  
int red = 0;  
int green = 0;  
int blue = 0;  
#define M1 4  // left motor M1a
#define M2 5 // left motor M2a
#define M3 6 // right motor M2a
#define M4 7 // right motor M2b
    
void setup()   
{  
  Serial.begin(9600); 
  //colour sensor pins
  pinMode(s0, OUTPUT);  
  pinMode(s1, OUTPUT);  
  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(out, INPUT);  
  digitalWrite(s0, HIGH);  
  digitalWrite(s1, HIGH);  
  
  //Motor Driver pins  
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);
}  
    
void loop() 
{  
  color(); 
  //Serial.print("R Intensity:");  
  //Serial.print(red, DEC);  
  //Serial.print(" G Intensity: ");  
  //Serial.print(green, DEC);  
  //Serial.print(" B Intensity : ");  
  //Serial.print(blue, DEC);  
  //Serial.println();  

  if(red < blue && green < blue)
  {
    if(-15<=red-green || red-green <=15)
    {
      Serial.println("Yellow colour");
      digitalWrite(M1, HIGH);
      digitalWrite(M2, LOW);
      digitalWrite(M3, HIGH);
      digitalWrite(M4, LOW);
    }
  }
  if(red <=20  || blue <= 20 || green <= 20)
  {
    Serial.println("White colour");
    digitalWrite(M1, HIGH);
    digitalWrite(M2, LOW);
    digitalWrite(M3, HIGH);
    digitalWrite(M4, LOW);
  }
  else{
  Serial.println("NO COLOUR");  
  }
  delay(300);   
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  digitalWrite(M3, LOW);
  digitalWrite(M4, LOW);
 }  
    
void color()  
{    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
  //count OUT, pRed, RED  
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);  
  //count OUT, pBLUE, BLUE  
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);  
  //count OUT, pGreen, GREEN  
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
}
