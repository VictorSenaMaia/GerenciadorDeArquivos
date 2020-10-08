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
  //escreverArquivo("12345620.txt","");
//  escreverArquivo("teste3.txt","");
//  escreverArquivo("teste4.txt","");
//  escreverArquivo("teste5.txt","");
  
  //abrirArquivo("teste1.txt");
      listarArquivos();
 
      //escreverArquivo("TESTE51.TXT","asjdkfjnsdfnajsdfnz\n");
      //escreverArquivo("TESTE5334.TXT","asjdkfjnsdfnajsdfnz\n");
      //abrirArquivo("TESTE32.TXT");
      //escreverArquivo("TESTE65.TXT","asjdkfjnsdfnajsdfnz\n");
      //abrirArquivo("TESTE51.TXT");
      SD.remove("TESTE51.TXT");
      //myFile.close();
      listarArquivos();
  
}
 
void loop() {
//  String recebido,comando,parametro;
//  if(Serial.available()){
//    while(Serial.available()){
//      recebido=Serial.readString();
//      comando=recebido.substring(0,1);
//      parametro=recebido.substring(1,(recebido.length()-1));
//   
//      if(comando=="0") {
//         listarArquivos();
//      }
//      if(comando=="2") {
//         abrirArquivo(parametro);
//      }
//      if(comando=="3"){
//        byte tam=(parametro.length()+1);
//        char aux[tam];
//            parametro.toCharArray(aux,tam);
//            
//              if(SD.remove(aux)){
//                Serial.println("Arquivo removido com sucesso!");
//                }else{
//                  Serial.println("Não foi possível remover o arquivo!");
//                  }  
//              listarArquivos();      
//        }
//      else{
//         Serial.println("Comando não reconhecido");
//        }
//      }
//    
//    }

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
