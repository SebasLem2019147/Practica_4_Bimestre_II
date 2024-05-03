/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Dev: Sebastian Enrique Lemus Salvador
   Fecha: 02 de mayo de 2024
   
   link de la simulacion: https: https://www.tinkercad.com/things/gCr2IWTgZh9-parte-2-practica-4-bimestre-ii?sharecode=Ahn6FeTNXpPL08l5X-dcojNQ3QvY6PAqxWIEMpAeb-c
   
*/

int leds[] = {4, 5, 6, 7, 8, 9, 10};  // declaro todos los pins de las leds juntos          
int contador_de_leds = 0;             //contador para sumar luego las leds de 1 en 1                       
int tiempo = 500;                  // tiempo para prender y apagar leds


void setup(){
  Serial.begin(9600); //inicio la comunicacion serial
  pinMode(2, INPUT);  // los 2 botones como input
  pinMode(3, INPUT);

  //para que las leds se definan como salida cuado se usen en el contador
  for (contador_de_leds = 0;contador_de_leds <= 6;contador_de_leds++) {              
    pinMode(leds[contador_de_leds], OUTPUT);
  }
  //envio mensajes al monitor serial
  Serial.println("Presionar el 1er boton para secuencia de leds auto-fantastico a 500ms");
  Serial.println("Presionar el 2do boton para secuencia de leds auto-fantastico el doble de rapido que el primero \n");
}

//codigo principal
void secuencia_De_Luces(){
  //si el pulsador 1 se presiona se ejecutara lo de adentro del if
  if(digitalRead(2)==HIGH){
    //mando mensajes al monitor serial
    Serial.println("-----Secuancia de velocidad 1-----");
    Serial.println("\n");
    //un for para prender las leds iniciando desde la 1era
    for (contador_de_leds = 0; contador_de_leds <= 6; contador_de_leds++) { 
      //se prende la primera led
      digitalWrite(leds[contador_de_leds], HIGH);
      delay(tiempo);
      //va sumando el contador para ir de led en led encendiendo y apagando
      digitalWrite(leds[contador_de_leds + 1], HIGH);
      delay(tiempo);
      digitalWrite(leds[contador_de_leds], LOW);
      delay(tiempo);
    }
    //for para hacer lo mismo que el anterior pero esta vez desde la ultima led a la primera
    for (contador_de_leds = 6; contador_de_leds >= 0; contador_de_leds--) {
      digitalWrite(leds[contador_de_leds], HIGH);
      delay(tiempo);
      digitalWrite(leds[contador_de_leds - 1], HIGH);
      delay(tiempo);
      digitalWrite(leds[contador_de_leds], LOW);
      delay(tiempo);
    }
  }
  /* si se pulsa el boton 3 se ejecutara lo mismo que el 
     primer boton pero el doble de rapido
  */
  if(digitalRead(3)==HIGH){
    Serial.println("-----Secuancia de velocidad 2-----");
    Serial.println("\n");
    for (contador_de_leds = 0; contador_de_leds <= 6; contador_de_leds++) { 
      digitalWrite(leds[contador_de_leds], HIGH);
      delay(tiempo/2);
      digitalWrite(leds[contador_de_leds + 1], HIGH);
      delay(tiempo/2);
      digitalWrite(leds[contador_de_leds], LOW);
      delay(tiempo/2);
    }
    for (contador_de_leds = 6; contador_de_leds >= 0; contador_de_leds--) {
      digitalWrite(leds[contador_de_leds], HIGH);
      delay(tiempo/2);
      digitalWrite(leds[contador_de_leds - 1], HIGH);
      delay(tiempo/2);
      digitalWrite(leds[contador_de_leds], LOW);
      delay(tiempo/2);
    }
  }
  delay(1000);
}

void loop() {
  //llamo a la funcion secuencia de luces antes establecida
  secuencia_De_Luces();
}
