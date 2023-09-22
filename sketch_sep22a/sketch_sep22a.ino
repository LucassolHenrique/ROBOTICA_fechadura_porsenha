#include <Keypad.h>
#include <Servo.h>

#define linhas 4
#define colunas 3
#define led_vermelho 2 
#define led_verde 3 
#define led_amarelo 4
#define pinServo 5 //micro servo coisa que gira 
//função verificasenha não existe linha 30

//declaração ds numeros do KEypad
char mapaTeclas[linhas][colunas]={{'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}};
String senha="123";
String digitada;
int estado=0;
Servo s;
int pos;
byte pinos_linha[linhas]={6,7,8,9};
byte pinos_coluna[colunas]={10,11,12};

//declaração do teclado
Keypad teclado = Keypad(makeKeymap(mapaTeclas),pinos_linha,pinos_coluna,linhas,colunas); 

  void setup() {
    pinMode(led_vermelho,OUTPUT);
    pinMode(led_verde,OUTPUT);
    pinMode(led_amarelo,OUTPUT);
    s.attach(pinServo);
    Serial.begin(9600);
    s.write(0);
}
void loop() { //1
  char tecla=teclado.getKey();
  if(tecla != NO_KEY){ //2
  estado=1;
    if(tecla=='#') { //3
      if(verificaSenha(senha,digitada)) { //4
        estado=3;
        leds(estado);
        delay(3000);
        estado=0;
      } else{ //4   
         estado=2;
        leds(estado);
        delay(3000);
        estado=0;
      }     //3
      digitada="";
       } else{ 
    digitada+=tecla;
    } 
  leds(estado);
    }
} 
                        
bool verificaSenha(String sa, String sd) {
bool resultado=false;                  
  if(sa.compareTo(sd)==0) {
    resultado=true;
  }else{
  resultado=false;
  }
  return resultado;
  }                 
                        void leds(int e) { //0=aguardando / 1=digitando / 2=negado / 3=aceitado
                        if(e==0){
                        digitalWrite(led_vermelho,LOW);
                        digitalWrite(led_verde,LOW);
                        digitalWrite(led_amarelo,LOW);
                        } else if(e==1) {
                          digitalWrite(led_vermelho,LOW);
                          digitalWrite(led_verde,LOW);
                          digitalWrite(led_amarelo,HIGH);
                        }
                        else if(e==2) {
                          digitalWrite(led_vermelho,HIGH);
                          digitalWrite(led_verde,LOW);
                          digitalWrite(led_amarelo,LOW);
                        }
                        else if(e==3) {
                          digitalWrite(led_vermelho,LOW);
                          digitalWrite(led_verde,HIGH);
                          digitalWrite(led_amarelo,LOW);
                          
                        for(pos = 0; pos < 360; pos++){ //fechadura o 360 é o tempo que ele vai mover
                          Serial.println(pos);
                        s.write(pos);
                          delay(15);
                        }
                        delay(1000);
                        for(pos = 90; pos >= 0; pos--)
                        {
                        s.write(pos);
                        delay(15);
                        }
                          
                        }   
                        }
