/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Dev: Sebastian Enrique Lemus Salvador
   Fecha: 02 de mayo 2024
   
   link de la simulacion: https://www.tinkercad.com/things/cs3iMhhzlPf-parte-3-practica-4-bimestre-ii?sharecode=mUbWuGCJpTLpcRqoio1KJzPj7sHaisyGf3_VRFmz9oU
*/


int leds[] = {13, 14, 15, 16, 17, 18, 19};
int contador_de_leds = 0;
int tiempo = 500;

void setup(){
  Serial.begin(9600);
  for (contador_de_leds = 0;contador_de_leds <= 6;contador_de_leds++) {              
    pinMode(leds[contador_de_leds], OUTPUT);
  }
  
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
}

int funcionamiento(){
  if(digitalRead(2)==LOW){
    Serial.println("Practica no.4");
    Serial.println("Sebastian Enrique Lemus Salvador \n");
  }
  if(digitalRead(3)==LOW){
    Serial.println("Secuencia de luces leds auto-fantastico \n");
    for (contador_de_leds = 0;contador_de_leds <= 6;contador_de_leds++) { 
      digitalWrite(leds[contador_de_leds], HIGH);
      delay(tiempo);
      digitalWrite(leds[contador_de_leds + 1], HIGH);
      delay(tiempo);
      digitalWrite(leds[contador_de_leds], LOW);
      delay(tiempo);
    }
    for (contador_de_leds = 6;contador_de_leds >= 0;contador_de_leds--) {
      digitalWrite(leds[contador_de_leds], HIGH);
      delay(tiempo);
      digitalWrite(leds[contador_de_leds - 1], HIGH);
      delay(tiempo);
      digitalWrite(leds[contador_de_leds], LOW);
      delay(tiempo);
    }
  }
  if(digitalRead(4)==LOW){
    Serial.println("Se imprimira la palabra cuatro en letra minuscula en el display letra por letra cada 2s \n");
    CUATRO();
    
  }
  if(digitalRead(2)==LOW && digitalRead(4)==LOW){
    Serial.println("Gracias por su atencion \n");
  }
  if(digitalRead(3)==LOW && digitalRead(5)==LOW){
    Serial.println("Gracias por su atencion \n");
  }
}

void CUATRO(){
  //C
  delay(1000);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  delay(2000);
  //U
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  delay(2000);
  //A
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  delay(2000);
  //T
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  delay(2000);
  //R
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  delay(2000);
  //O
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  delay(2000);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
}

void loop(){
  funcionamiento();
  delay(tiempo/2);
}
