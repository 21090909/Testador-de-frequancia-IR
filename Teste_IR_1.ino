// Arduino Controle Remoto IR - LEDs coloridos
// https://blog.eletrogate.com/guia-completo-do-controle-remoto-ir-receptor-ir-para-arduino
// Baseado em https://hetpro-store.com/TUTORIALES/control-ir-con-arduino/
#include <IRremote.h>                              // Biblioteca IRemote
int RECV_PIN = 11;                                 // Arduino pino D11 conectado no Receptor IR
IRrecv irrecv(RECV_PIN);                           // criando a instância
decode_results results;                            // declarando os resultados
bool  LED7  = false;                    // estado dos LEDs
int atraso = 300; 
int conta = 0;                                 // atraso após ligar LED
void setup()
{
  Serial.begin(9600);                              // Monitor velocidade 9600 bps
  pinMode(13, OUTPUT);  
  digitalWrite(13, false);                            // LED vermelho no pino D07
  irrecv.enableIRIn();                             // Inicializa a recepção de códigos
}
void loop()
{
  results.value = 0;                               // zera os registradores
  if (irrecv.decode(&results))                     // se algum código for recebido
  {
    Serial.println(results.value, HEX);            // imprime o HEX Code
    irrecv.resume();                               // reinicializa o receptor
  }
  if (results.value > 888888 )                   // pressione tecla 3 para controlar LED vermelho (D07)
  {
    LED7 = !LED7;                                  // alterna o estado do LED D07
    // digitalWrite(7, LED7);                         // acende ou apaga LED vermelho (D07)
    // delay(atraso);
     delay(200);
    // digitalWrite(7,LOW);                              // atraso de 250 ms
  }
  if (LED7==true) { digitalWrite(13, true); } else { digitalWrite(13, false); }
  delay(atraso);
  Serial.println(LED7);
}