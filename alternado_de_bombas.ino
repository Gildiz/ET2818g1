#define bomba1 6
#define bomba2 7
#define sensT 3
#define sensC 4
int Tanque = 0;
int Cisterna = 0;
int dato = 1; 

void setup() {
  pinMode(bomba1,OUTPUT);
  pinMode(bomba2,OUTPUT);
  pinMode(sensT,INPUT);
  pinMode(sensC,INPUT);
  Serial.begin(9600);
}

void loop() {

Tanque = digitalRead(sensT);
Cisterna = digitalRead(sensC);                            
  
          while(Tanque == 0){
            Serial.println("tank0");
          Cisterna = digitalRead(sensC);
          Serial.println(Cisterna);
          
                switch(Cisterna){
                        Serial.println("cisterna1");
                       case 0:
                              digitalWrite(bomba1 , LOW);
                              digitalWrite(bomba2 , LOW);
                              break;

                       case 1:switch(dato){

                              case 1: 
                                    digitalWrite(bomba1 , HIGH);
                                    break;
                              case 2: 
                                     digitalWrite(bomba2 ,HIGH);
                                     break;
                       
                       }
                }  
                               delay(2000);
                              Tanque = digitalRead(sensT);
                               if (Tanque == 1){
                                Serial.println("llegue");
                                                switch(dato){
                                                    
                                                            case 1:
                                                                    dato = dato + 1;
                                                                    digitalWrite (bomba1, LOW);
                                                                    break;
                                                            case 2:
                                                                    dato = dato - 1;
                                                                    digitalWrite (bomba2, LOW);   
                                                                    break;
                           }  
                      }       
                
          
    }
}


