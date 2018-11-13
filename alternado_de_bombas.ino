
// Este programa esta encargado de sensar los estados de los flotantes y alternar el uso de las bombas de agua entre la principal y secundaria. 






#define bomba1 6
#define bomba2 7
#define sensT 3   // flotante del tanque
#define sensC 4   // flotante de la cisterna
#define ledP  2   // leds indicadores de uso 
#define ledS  5  // 
int Tanque = 0;
int Cisterna = 0;
int dato = 1; //  el dato que se va a utilizar para alternar las bombas

void setup() {
  pinMode(bomba1,OUTPUT);
  pinMode(bomba2,OUTPUT);
  pinMode(ledP,OUTPUT);
  pinMode(ledS,OUTPUT);
  pinMode(sensT,INPUT);
  pinMode(sensC,INPUT);
  Serial.begin(9600);
}

void loop() {

Tanque = digitalRead(sensT);    // 
                                // Senso los flotantes T y C
Cisterna = digitalRead(sensC);  //                          
  
          while(Tanque == 0){      // cuando el tanque pida agua ingresa a ese loop.
            Serial.println("tank0");
          Cisterna = digitalRead(sensC); // sensa que valor tiene la cisterna ( Si es 1 o 0).
          Serial.println(Cisterna);
          
                switch(Cisterna){
                        Serial.println("cisterna1");
                       case 0:                // si el valor es 0 no prende ninguna bomba. Si estan en uso las apaga de inmediato.
                              digitalWrite(bomba1 , LOW);
                              digitalWrite(bomba2 , LOW);
                              digitalWrite(ledS , LOW);
                              digitalWrite(ledP , LOW);
                              break;

                       case 1:switch(dato){   // si la cisterna es 1 entra acá y pregunta que bomba se prende, depende de la variable "Dato".

                              case 1: // prendo la bomba 1 y led indicador del mismo.
                                    digitalWrite(bomba1 , HIGH);
                                    digitalWrite(ledP , HIGH);
                                    break;
                              case 2: // prendo la bomba 2 y led indicador del mismo.
                                     digitalWrite(bomba2 ,HIGH);
                                     digitalWrite(ledS , HIGH);
                                     break;
                       
                       }
                }  
                               delay(2000);
                              Tanque = digitalRead(sensT);
                               if (Tanque == 1){          // pregunta el estado del tanque, si esta lleno apaga la bomba que se estaba usando.
                                Serial.println("llegue");
                                                switch(dato){               // acá es cuando hacemos el alternado de las bombas
                                                    
                                                            case 1:             // cuando el tanque este lleno y se haya usado la bomba 1 esta misma cambia su valor y apaga la bomba.
                                                                    dato = dato + 1;          
                                                                    digitalWrite (bomba1, LOW);
                                                                    digitalWrite(ledP , LOW);
                                                                    break;
                                                            case 2:             // cuando el tanque este lleno y se haya usado la bomba 2 esta misma cambia su valor y apaga la bomba
                                                                    dato = dato - 1;
                                                                    digitalWrite (bomba2, LOW);   
                                                                    digitalWrite(ledS , LOW);
                                                                    break;
                           }  
                      }       
                                                                      // finaliza acá el Programa y regresa arriba y repite el proceso hasta sea apagado
          
    }
}


