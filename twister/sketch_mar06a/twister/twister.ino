int led13=13;
int led12=12;
String estado="";
int releeCDI=7;
int releeEncendido=8;
boolean  flag = false;

void setup(){
  Serial.begin(9600);
  pinMode(led13,OUTPUT);
  pinMode(led12,OUTPUT);
  pinMode(releeCDI,OUTPUT);
  //pinMode(releeEncendido,OUTPUT);
  //digitalWrite(releeEncendido, HIGH);  
  digitalWrite(releeCDI, HIGH);  
}



void loop(){

 if(Serial.available() > 0){
   estado = Serial.readString();
   Serial.println(estado);
 }
  if(estado == "8923"){
    flag = true;
    digitalWrite(led12,HIGH);
    
  }

  if (flag){
      if(estado == "1597" ){
        //on CDI
        digitalWrite(releeCDI,LOW);
        digitalWrite(led13,HIGH);
      }

      if(estado == "3765"){
          //OFF cdi
          digitalWrite(releeCDI,HIGH);
          digitalWrite(led13,LOW);
      }

      if(estado == "7986"){
          //prender moto
          digitalWrite(led12,LOW);
          delay(1000);
          digitalWrite(led12,HIGH);
      }

      if(estado == "0000"){
          digitalWrite(led12,LOW);
          digitalWrite(led13,LOW);
          digitalWrite(releeCDI,HIGH);
      }
  }
  
}  


void encenderLED(){
    digitalWrite(led12,HIGH);
    delay(100); 
    digitalWrite(led12,LOW);
    delay(1000);
    digitalWrite(led13,HIGH);
    delay(100); 
    digitalWrite(led13,LOW);
    delay(1000);
  }
