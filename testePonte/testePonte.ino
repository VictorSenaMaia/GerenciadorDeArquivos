


int cont=0;
void setup() {
Serial.begin(115200);
while(!Serial);
}
void loop() {
  Serial.print(cont);
  Serial.print(" ");
  cont++;
  if(cont>100){
    cont=0;
    }
  delay(100);
}
