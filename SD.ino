#include <SD.h>
#include <SPI.h>
                                                                                
File myFile;
int pinoSS = 53;            
String file = "NOME1.TXT" , msg = "";
String file2 = "A3" ;
String stgTeste = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Cras consectetur at mauris vel aliquam. Proin vitae nisl fringilla, porta mauris lacinia, ornare nisl. Fusce nulla odio, sodales sit amet rhoncus ut, placerat vitae est. Sed euismod, dolor nec accumsan efficitur, erat leo porta mauris, sed faucibus quam mi vestibulum nibh. Sed varius leo sit amet tortor volutpat, nec pulvinar augue fringilla. Duis id pellentesque odio. Cras scelerisque pulvinar mi, in auctor erat dapibus ut. In ac metus placerat, consequat quam ut, pretium nunc. Phasellus facilisis eu dolor id molestie. In vulputate, nibh eget scelerisque blandit, diam libero vulputate est, non sagittis urna lacus a libero. Fusce scelerisque orci nibh, ac interdum quam efficitur id. Quisque venenatis dolor neque, convallis pharetra ex eleifend nec. Suspendisse sed efficitur lectus. Quisque tempor, nisl et cursus sagittis, elit est consectetur tortor, eu ullamcorper dolor purus id massa. Proin auctor urna vel neque interdum, suscipit facilisis mauris rhoncus. Donec viverra tristique tortor vel bibendum. Aliquam eleifend placerat gravida. Donec urna orci, facilisis eu purus a, luctus consequat ligula. Sed sagittis urna et erat commodo, vitae porttitor lectus pulvinar. Proin eget rutrum sapien, tristique finibus quam. Mauris et sagittis risus, ac vehicula turpis. Donec eros elit, aliquet quis feugiat vitae, malesuada eu nibh. Phasellus vitae placerat justo. Proin pharetra nunc nisi.  Aenean nec urna pharetra, bibendum dui eu, sagittis augue. Proin convallis risus mi, nec volutpat ante pellentesque nec. Vivamus a odio dui. Ut erat ligula, lobortis nec commodo quis, sollicitudin id purus. Suspendisse potenti. Pellentesque elementum urna vitae turpis faucibus, non luctus orci pellentesque. Nunc maximus tempor lacus id iaculis. Nullam sed euismod est. Integer ultrices varius imperdiet. Suspendisse enim dui, volutpat et urna et, maximus rhoncus enim. Suspendisse convallis lacus et tellus placerat consectetur.  Proin metus augue, dictum at lectus et, imperdiet ornare urna. Maecenas porttitor, elit at commodo mollis, sem mi gravida nibh, in congue dolor felis eget nunc. Mauris orci lorem, vulputate a pellentesque ut, bibendum eget elit.";
int cont = 0;
#define numGravacoes 2000
String recebido = "";

void readSD(String nomeArq ) {
  if (SD.exists(nomeArq)) {
    // imprime arquivo
    myFile = SD.open(nomeArq); // Abre o Arquivo

    if (myFile) {
      //Serial.println("Conteúdo do Arquivo:"); // Imprime na tela

      while (myFile.available()) { // Exibe o conteúdo do Arquivo
        /*
        msg = "";
        msg = (char)myFile.read();
        //if(msg != " ")Serial.print(msg);
        Serial.print(msg);*/

        Serial.write(myFile.read());
      }
      myFile.close(); // Fecha o Arquivo após ler
      //Serial.println("isso é td q tem no arquivo");
    }
  } else {
    Serial.println((String) nomeArq + " não foi encontrado");
  }


}
void writeSD(String nomeArq , String dados) {
  

  if (SD.exists(nomeArq)) {
    /* como a função de escrita está apenas inserindo no final do arquivo
       se o arquivo já existir, deleta e cria um novo com o conteudo atual
    */
  removeSD(nomeArq);
  }

  myFile = SD.open(nomeArq, FILE_WRITE); // Cria / Abre arquivo .txt

  if (myFile) {
    //Se o Arquivo abrir imprime:
    myFile.println(dados); // Escreve no Arquivo
    myFile.close(); // Fecha o Arquivo após escrever
  }
  else {
    //Se o Arquivo não abrir
    Serial.println((String)"Erro ao Abrir Arquivo " + nomeArq ); // Imprime na tela
  }
}
void writeSD_2(String nomeArq , String dados) {
  

  myFile = SD.open(nomeArq, FILE_WRITE); // Cria / Abre arquivo .txt

  if (myFile) {
    //Se o Arquivo abrir imprime:
    myFile.print(cont); // Escreve no Arquivo o contador
    myFile.println(dados); // Escreve no Arquivo o dado
    myFile.close(); // Fecha o Arquivo após escrever
  }
  else {
    //Se o Arquivo não abrir
    Serial.println((String)"Erro ao Abrir Arquivo " + nomeArq ); // Imprime na tela
  }
}
void removeSD(String nomeArq) {
  if (SD.exists(nomeArq)){
    SD.remove(nomeArq); 
    Serial.println((String)"Removido arquivo " +  nomeArq);
  }
  else{
    Serial.println((String) nomeArq +" não encontrado");
    }
}
void beginSD() {

  SPI.begin();
  pinMode(pinoSS, OUTPUT); // Declara pinoSS como saída

  if (SD.begin()) {
    // Inicializa o SD Card
    Serial.println("SD Card ok"); // Imprime na tela
  }
  else {
    Serial.println("Falha na inicialização do SD Card.");
    return;
  }
}

void setup() {
  Serial.begin(115200);
  beginSD();
  //Serial.println((String) "lendo cartão: Verificando se o arquivo " + file + " está no cartão");
  
  //readSD(file);
  /*
  Serial.println("granvando no sd");
  writeSD("a666" , "insere texto pequeno" );
  Serial.println("agora vou ler o arquivo criado");
  readSD("a666");
Serial.println("\n_________");
*//*
  removeSD(file2);
  Serial.println("segunda gravação ");
  cont = 0;
  
  while(cont<numGravacoes){
    writeSD_2(file2 , stgTeste );
    cont++;
  }
  
  //Serial.println("gravou ?");
  */
  //removeSD("A5");
  readSD("A5");
  //Serial.println("ok");


}

void loop() {
  if(Serial.available()){
    while(Serial.available()){
      recebido=Serial.readString();
      writeSD_2("A5" , recebido );
      }
  }
}
