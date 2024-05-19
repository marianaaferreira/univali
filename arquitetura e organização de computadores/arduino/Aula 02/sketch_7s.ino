//DISPLAY de 7 SEGMENTOS 

  int   button      = 2;  //Botão
  int   contador    = 0;  //Contador
  bool  change      = 0;  //
  int   bitPosition = 0;  //
  bool  bitValue    = 0;  //

// Códigos para o Display de Sete Segmentos:
//int segmentos[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};
  int segmentos[] = {0x40,0x79,0x24,0x30,0x99,0x12,0x02,0x78,0x00,0x10};

//----------------------------------------------------------------------
void setup()
{
  pinMode(13,     OUTPUT);//LED a saída
  pinMode(12,     OUTPUT);//LED b saída 
  pinMode(11,     OUTPUT);//LED c saída
  pinMode(10,     OUTPUT);//LED d saída
  pinMode( 9,     OUTPUT);//LED e saída
  pinMode( 8,     OUTPUT);//LED f saída
  pinMode( 7,     OUTPUT);//LED g saída
  pinMode(button,   INPUT );//Entrada
  Serial.begin(9600);//Comunicação serial 
  imprime();
  delay(1000);
}
//----------------------------------------------------------------------
void imprime (){
  for ( bitPosition = 0; bitPosition <=6; bitPosition++){
        bitValue = bitRead(segmentos[contador], bitPosition);
        digitalWrite(13-bitPosition, bitValue); 
  }
      Serial.println(contador);//Imprime o valor do contador
      Serial.println(segmentos[contador], HEX);
}
//----------------------------------------------------------------------
void chave(){
                          //Chave presionada
  if(digitalRead(button) == 0){
    delay(10);
                          //Aguarda liberar
      if(digitalRead(button) == 0){
         while (digitalRead(button) == 0);
         change = 1;      //Sinaliza mudança
      }
  } 
}
//----------------------------------------------------------------------
void contagem(){
  if (change ==1){
      contador++;           //Incrementa contador
        if (contador >= 10) {// 0 a 9
          contador = 0;     //Retorna a zero
        }
    imprime();              //Visualiza
    change = 0;
  }
}
//----------------------------------------------------------------------
void loop()
{
  chave();                  //Chave pressionada?
  contagem();               //Se sim, contar
  delay(100);               //Demora
}
//----------------------------------------------------------------------