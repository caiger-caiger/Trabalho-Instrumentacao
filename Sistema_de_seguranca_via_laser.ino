//Para esse programa funcionar é necessario compilar o arquivo pelo Arduino IoT Cloud
//Esse sketch deve ser acrescentado ao sketch gerado no Arduino IoT Cloud em seus devidos lugares

//Incluir fora dos comados void
#include <Servo.h> //Inclusão da biblioteca do servo
Servo SERVOMOTOR; //Nomeação do servo motor
int ESTADO = 0;
int LDR = A4;
int OPE = 8;
int ACI = 7;
int LASER = 12;

//Incluir no setup
pinMode(ACI, OUTPUT); //Pino ligado ao led vermelho que representa que o sistema foi acionado
pinMode(OPE, OUTPUT); //Pino ligado ao led verde que representa que o sistema esta operante
pinMode(LASER, OUTPUT); //Pino ligado ao laser
pinMode(LDR, INPUT); //Pino de leitura do LDR
SERVOMOTOR.attach(3); //Pino da saida do servo motor

//Incluir no loop
ESTADO = 0+ONOFF;
if (ESTADO==0){
  digitalWrite(ACI, LOW);
  digitalWrite(OPE, LOW);
  digitalWrite(LASER, LOW);
  delay(5000); //Desligamento de todas as entradas durante 5 minutos 
  ONOFF = 1;
}
else {
  digitalWrite(OPE, HIGH);
  digitalWrite(LASER, HIGH);
  if(LDR>100 & ACI==0){
    delay(10);
  }
  else{
    SERVOMOTOR.write(180);
    digitalWrite(LASER, LOW);
    digitalWrite(ACI,  HIGH);
  }
}
