// Projeto para Criar / Ler Arquivos .txt junto ao Cartão SD Arduino
// Visite nossa loja através do link www.usinainfo.com.br
// Mais projetos em www.www.usinainfo.com.br/blog/</pre>
#include <SD.h>
#include <SPI.h>
 
File myFile;
 
int pinoSS = 53; // Pin 53 para Mega / Pin 10 para UNO
 
void setup() { // Executado uma vez quando ligado o Arduino

SPI.begin();
Serial.begin(9600); // Define BaundRate
pinMode(pinoSS, OUTPUT); // Declara pinoSS como saída
 
if (SD.begin()) { 
    // Inicializa o SD Card
    Serial.println("SD Card pronto para uso."); // Imprime na tela
}
 
else {
    Serial.println("Falha na inicialização do SD Card.");
    return;
}
listarArquivos();
//SD.remove("TESTE4.TXT");
lerArquivo("TESTE2.TXT");

}
 
void loop() {
}

bool lerArquivo(String nome){
  myFile = SD.open(nome); // Abre o Arquivo
   
  if (myFile) {
  Serial.println("Conteúdo do Arquivo:"); // Imprime na tela
   
  while (myFile.available()) { // Exibe o conteúdo do Arquivo
  Serial.write(myFile.read());
  }
   
  myFile.close(); // Fecha o Arquivo após ler
  return true;
  }
   
  else {
  Serial.println("Erro ao Abrir Arquivo .txt"); // Imprime na tela
  return false;
  } 
}
bool escreveArquivo(String nome){
  myFile = SD.open("usina.txt", FILE_WRITE); // Cria / Abre arquivo .txt
 
  if (myFile) { 
      //Se o Arquivo abrir imprime:
      Serial.println("Escrevendo no Arquivo .txt"); // Imprime na tela
      myFile.println("Usinainfo 1, 2 ,3 ..."); // Escreve no Arquivo
      myFile.close(); // Fecha o Arquivo após escrever
      Serial.println("Terminado."); // Imprime na tela
      Serial.println(" ");
  } 
  else {
    //Se o Arquivo não abrir
    Serial.println("Erro ao Abrir Arquivo .txt"); // Imprime na tela
  } 
}
void listarArquivos() {
  File raiz=SD.open("/");
  int numTabs=0;
  while (true) {
    File entry =  raiz.openNextFile();
    if (! entry) {
      // no more files
      break;
    }
   for (uint8_t i = 0; i < numTabs; i++) {
      Serial.print('\t');
    } 
    Serial.println(entry.name());
  }
}
