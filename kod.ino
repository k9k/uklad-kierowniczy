int motorPin1 = 4;
int motorPin2 = 5;
int motorPin3 = 6;
int motorPin4 = 7;
int motorPin5 = 8;
int motorPin6 = 9;
int motorPin7 = 10;
int motorPin8 = 11;
int delayTime = 2;

int kierownica = 533;  //potencjometr 
int kierownica1 = 80;
int kierownica2 = 80;

int poz_silnika1 = 80;
int roznica1 = 0;
int kierownica_prawo1 = 80;
int kierownica_lewo1 = 80;

int poz_silnika2 = 80;
int roznica2 = 0;
int kierownica_prawo2 = 80;
int kierownica_lewo2 = 80;

int L1 = 12;
int L2 = 13;
int P1 = 3;
int P2 = 2;

void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(P1, OUTPUT);
  pinMode(P2, OUTPUT);
  Serial.begin(9600);
}

void diody_przy_skrecie(void)
 {
  if(kierownica >= 43 && kierownica < 288)
  {
    digitalWrite(L1, HIGH);
    digitalWrite(L2, HIGH);
    digitalWrite(P1, LOW);
    digitalWrite(P2, LOW);
  }
  if(kierownica >= 288 && kierownica < 530)
  {
    digitalWrite(L1, LOW);
    digitalWrite(L2, HIGH);
    digitalWrite(P1, LOW);
    digitalWrite(P2, LOW);
  }
  if(kierownica >= 530 && kierownica < 537)
  {
    digitalWrite(L1, LOW);
    digitalWrite(L2, LOW);
    digitalWrite(P1, LOW);
    digitalWrite(P2, LOW);
  }
  if(kierownica >= 538 && kierownica < 778)
  {
    digitalWrite(L1, LOW);
    digitalWrite(L2, LOW);
    digitalWrite(P1, HIGH);
    digitalWrite(P2, LOW);
  }
  if(kierownica >= 779 && kierownica < 1024)
  {
    digitalWrite(L1, LOW);
    digitalWrite(L2, LOW);
    digitalWrite(P1, HIGH);
    digitalWrite(P2, HIGH);
  }
 }

void loop() {
  kierownica = analogRead(0);
  if (kierownica > 530 && kierownica < 534)  //zabezpieczenie przed niedok³adnoœci¹ potencjometru
  {
    kierownica = 533;
  }
  if (kierownica < 63)
  {
    kierownica = 63;
  }
  
  diody_przy_skrecie();
    
  kierownica_prawo1 = map(kierownica, 63, 533, 40, 80);
  kierownica_lewo1 = map(kierownica, 533, 1023, 80, 130);
  
  kierownica_prawo2 = map(kierownica, 63, 533, 30, 80);
  kierownica_lewo2 = map(kierownica, 533, 1023, 80, 120);
  
  if (kierownica < 533)
  {
    kierownica1 = kierownica_prawo1;
    kierownica2 = kierownica_prawo2;
  }
  else
  {
    kierownica1 = kierownica_lewo1;
    kierownica2 = kierownica_lewo2;
  }
  
  roznica1 = kierownica1 - poz_silnika1;
  roznica2 = kierownica2 - poz_silnika2;
 
  if (roznica1 > 0)  //w prawo
  {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(delayTime);
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, HIGH);
  delay(delayTime);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(delayTime);
  poz_silnika1++;
  }
  if (roznica1 < 0)  //w lewo
  {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(delayTime);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(delayTime);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, HIGH);
  delay(delayTime);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);
  poz_silnika1--;
  }
  
  if (roznica1 == 0)
  {
    //delay(1);
  }
  
  if (roznica2 > 0)  //w prawo
  {
  digitalWrite(motorPin5, HIGH);
  digitalWrite(motorPin6, LOW);
  digitalWrite(motorPin7, LOW);
  digitalWrite(motorPin8, HIGH);
  delay(delayTime);
  digitalWrite(motorPin5, HIGH);
  digitalWrite(motorPin6, LOW);
  digitalWrite(motorPin7, LOW);
  digitalWrite(motorPin8, LOW);
  delay(delayTime);
  digitalWrite(motorPin5, HIGH);
  digitalWrite(motorPin6, HIGH);
  digitalWrite(motorPin7, LOW);
  digitalWrite(motorPin8, LOW);
  delay(delayTime);
  digitalWrite(motorPin5, LOW);
  digitalWrite(motorPin6, HIGH);
  digitalWrite(motorPin7, LOW);
  digitalWrite(motorPin8, LOW);
  delay(delayTime);
  digitalWrite(motorPin5, LOW);
  digitalWrite(motorPin6, HIGH);
  digitalWrite(motorPin7, HIGH);
  digitalWrite(motorPin8, LOW);
  delay(delayTime);
  digitalWrite(motorPin5, LOW);
  digitalWrite(motorPin6, LOW);
  digitalWrite(motorPin7, HIGH);
  digitalWrite(motorPin8, LOW);
  delay(delayTime);
  digitalWrite(motorPin5, LOW);
  digitalWrite(motorPin6, LOW);
  digitalWrite(motorPin7, HIGH);
  digitalWrite(motorPin8, HIGH);
  delay(delayTime);
  digitalWrite(motorPin5, LOW);
  digitalWrite(motorPin6, LOW);
  digitalWrite(motorPin7, LOW);
  digitalWrite(motorPin8, HIGH);
  delay(delayTime);
  poz_silnika2++;
  }
  if (roznica2 < 0)  //w lewo
  {
  digitalWrite(motorPin5, HIGH);
  digitalWrite(motorPin6, HIGH);
  digitalWrite(motorPin7, LOW);
  digitalWrite(motorPin8, LOW);
  delay(delayTime);
  digitalWrite(motorPin5, HIGH);
  digitalWrite(motorPin6, LOW);
  digitalWrite(motorPin7, LOW);
  digitalWrite(motorPin8, LOW);
  delay(delayTime);
  digitalWrite(motorPin5, HIGH);
  digitalWrite(motorPin6, LOW);
  digitalWrite(motorPin7, LOW);
  digitalWrite(motorPin8, HIGH);
  delay(delayTime);
  digitalWrite(motorPin5, LOW);
  digitalWrite(motorPin6, LOW);
  digitalWrite(motorPin7, LOW);
  digitalWrite(motorPin8, HIGH);
  delay(delayTime);
  digitalWrite(motorPin5, LOW);
  digitalWrite(motorPin6, LOW);
  digitalWrite(motorPin7, HIGH);
  digitalWrite(motorPin8, HIGH);
  delay(delayTime);
  digitalWrite(motorPin5, LOW);
  digitalWrite(motorPin6, LOW);
  digitalWrite(motorPin7, HIGH);
  digitalWrite(motorPin8, LOW);
  delay(delayTime);
  digitalWrite(motorPin5, LOW);
  digitalWrite(motorPin6, HIGH);
  digitalWrite(motorPin7, HIGH);
  digitalWrite(motorPin8, LOW);
  delay(delayTime);
  digitalWrite(motorPin5, LOW);
  digitalWrite(motorPin6, HIGH);
  digitalWrite(motorPin7, LOW);
  digitalWrite(motorPin8, LOW);
  delay(delayTime);
  poz_silnika2--;
  }
  
  if (roznica2 == 0)
  {
    //delay(1);
  }
}