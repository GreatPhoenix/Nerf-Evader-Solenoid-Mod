// Created by Bridget Whitacre (^▽^)
// Software to run a full auto solinoid kit for the Nerf Evader

int fireMode = 1;
bool isReleased = true;

int push = 30;
int pull = 100;

void setup() {
  // put your setup code here, to run once:
  pinMode(12,OUTPUT); // Solinod setup
  pinMode(9,OUTPUT); // trigger setup
  pinMode(10, INPUT_PULLUP); // trigger
  
  pinMode(4, INPUT_PULLUP);// Single fire (this needs to be rerighten the way the switch works is supper gay)
  //pinMode(5, INPUT_PULLUP); // double shot
  pinMode(6, INPUT_PULLUP); // Full Auto
  digitalWrite(12,LOW); // solinod controll (This is reversed for some unknown reason you should look into the issue)
  digitalWrite(9,LOW);
  Serial.begin(9600);
  Serial.print("Start Code");
 
}

void loop() {
  selectFireSwitch();
  Serial.println(digitalRead(4));
  //delay(100);
  Serial.println(digitalRead(6));

  
  if (digitalRead(10) == LOW and isReleased == true){
    if (fireMode == 1){
      digitalWrite(12,HIGH);
      delay(push);
      digitalWrite(12,LOW);
      isReleased = false;
    }
    if (fireMode == 2){
      digitalWrite(12,HIGH);
      delay(push);
      digitalWrite(12,LOW);
      delay(pull);
      digitalWrite(12,HIGH);
      delay(push);
      digitalWrite(12,LOW);
      delay(pull);
      isReleased = false;
    }  
    
  }
  if (digitalRead(10) == HIGH){
    isReleased = true;
  }
  if (digitalRead(10) == LOW and fireMode == 3){ //full auto stuff
    Serial.print("HI2");
      digitalWrite(12,HIGH);
      delay(push);
      digitalWrite(12,LOW);
      delay(pull);
      
    }
}

void selectFireSwitch(){
  
  if (digitalRead(4) == LOW){
    fireMode = 2;
  }
//  else if (digitalRead(5) == LOW){
//    fireMode = 2;
//  }
  else if (digitalRead(6) == LOW){
    fireMode = 3;
  }
  else{
    fireMode = 1;
  
  }
}
