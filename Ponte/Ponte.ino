#include <AltSoftSerial.h>

//arduino uno tx 9 rx 8
//arduino mega tx 46 rx 88
AltSoftSerial mySerial;

void setup(){
  Serial.begin(115200);
  while(!Serial){
    ;
  }
  mySerial.begin(115200);
}

void loop(){
  if(mySerial.available()){
    String textoRecebido = mySerial.readString();
    Serial.println(textoRecebido);
  }
  if(Serial.available()){
    String textoEnviado = Serial.readString();
     Serial.println(textoEnviado);
     mySerial.println(textoEnviado);
  }
  
}
