// Projeto para Criar / Ler Arquivos .txt junto ao Cartão SD Arduino
// Visite nossa loja através do link www.usinainfo.com.br
// Mais projetos em www.www.usinainfo.com.br/blog/</pre>
#include <SD.h>
#include <SPI.h>
#include <MensagemDebug.h>

unsigned long tempoInicial=0;
unsigned int tempoPassado;
unsigned int espera=500;
File myFile;
 
int pinoSS = 53; // Pin 53 para Mega / Pin 10 para UNO

byte contador=0;

String recebido,comando,parametro;

void setup() { // Executado uma vez quando ligado o Arduino
  MensagemDebug m();
  SPI.begin();
  Serial.begin(9600); // Define BaundRate
  pinMode(pinoSS, OUTPUT); // Declara pinoSS como saída
   
  if (SD.begin()) { 
      // Inicializa o SD Card
      Serial.println("SD Card pronto para uso."); // Imprime na tela
      Serial.println("Aguardando Instrução...");     
  }   
  else {
      Serial.println("Falha na inicialização do SD Card.");
      return;
  }
//  escreverArquivo("teste2.txt","");
//  escreverArquivo("teste3.txt","");
//  escreverArquivo("teste4.txt","");
//  escreverArquivo("teste5.txt","");
  
  //abrirArquivo("teste1.txt");
  //listarArquivos();
} 
void loop() {
    
  if(Serial.available()){
    while(Serial.available()){
      recebido=Serial.readString();
      comando=recebido.substring(0,1);
      parametro=recebido.substring(1,(recebido.length()-1));
   
      if(comando=="0") {
         listarArquivos();
      }
      else if(comando=="1"){
           abrirArquivo(parametro);
//           tempoInicial=millis();
//           while(espera>(tempoPassado-tempoInicial){
//                                
//            }      
        }
      else if(comando=="2") {
         abrirArquivo(parametro);
      }
      else if(comando=="3"){
         deleteArquivo(parametro);
      }
       else if(comando=="4"){
        String aux="";
        Serial.println("O arquivo esta aguardando edição");         
         while(aux !="parou\n"){
            aux=Serial.readString();
            if(Serial.available()){
             escreverArquivo(parametro,aux);
             Serial.println("Aguardando Leitura");
            }
           
          }
           Serial.println("Saiu do while");  
      }
      else{
            Serial.println("Comando não reconhecido");
      }    
    }
  }
}
void listarArquivos(){
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
bool abrirArquivo(String nome){
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
bool escreverArquivo(String nome,String dado){
  myFile = SD.open(nome, FILE_WRITE); // Cria / Abre arquivo .txt
 
  if (myFile) { 
      //Se o Arquivo abrir imprime:
      Serial.println("Escrevendo no Arquivo .txt"); // Imprime na tela
      myFile.println(dado); // Escreve no Arquivo
      myFile.close(); // Fecha o Arquivo após escrever
      Serial.println("Terminado."); // Imprime na tela
      Serial.println(" ");
  } 
  else {
    //Se o Arquivo não abrir
    Serial.println("Erro ao Abrir Arquivo .txt"); // Imprime na tela
  } 
}
bool deleteArquivo(String nome){
    bool deletou=false;
    byte tam=(parametro.length()+1);
    char aux[tam];
    parametro.toCharArray(aux,tam);
      if(SD.exists(aux)){
        if(SD.remove(aux)){
        Serial.println("Arquivo removido com sucesso!");
        deletou=true;
        }
        else{
          Serial.println("Não foi possível remover o arquivo!");
          deletou=false;
          }               
        }
        else{
          Serial.println("Arquivo não existe!");
          deletou=false;
           }
      myFile.close(); 
      return deletou;
}
void editarArquivo(){
    
}
