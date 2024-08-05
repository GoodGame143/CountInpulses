volatile int gg = 1;
volatile int valid = 1;

volatile int val = 1;

bool flag = true;
//453 68
const int d37 = 37;
const int d50 = 50;
const int d75 = 75;
const int d100 = 100;
const int d200 = 200;
const int d1k = 1000;
const int d5k = 5000;

int d_default = 200;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), countPlus, RISING);
  attachInterrupt(digitalPinToInterrupt(3), countMinus, RISING);
}

void loop() {
  if(Serial.available() > 0){
    String input  = Serial.readStringUntil('\n');
    request(input);
    while(Serial.available()){
      Serial.read();  
    }
  }
  if(gg != valid){
    Serial.println(gg);
    valid = gg;
  }
  else {
      
  }
  
  delay(d_default);
}
void countPlus(){
  if(digitalRead(2) == HIGH && digitalRead(3) == HIGH){
    gg++;
    val++;
  }
  //gg++; // && Serial.println(gg);
 // return;
}
void countMinus(){
  if(digitalRead(3) == HIGH && digitalRead(2) == HIGH){
    gg--;
    val--;
  }
}
void request(String input){
  if(input == "l"){
    d_default = d37;
  }
  else if(input == "k"){
    d_default = d50;
  }
  else if(input == "j"){
    d_default = d75;
  }
  else if(input == "h"){
    d_default = d100;
  }
  else if(input == "g"){
    d_default = d200;
  }
  if(input == "f"){
    d_default = d1k;
  }
  else if(input == "d"){
    d_default = d5k;
  }
  else if(input == "r"){
    Serial.println(gg);
  }
  else if(input == "a"){
    gg = val;
    Serial.println(gg);
  }
  else{
    
     gg = input.toInt();
     val=gg;
  }
}
