/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Practica_3 Bimestre II
   Dev: Sebastian Enrique Lemus Salvador
   Fecha: 02 de mayo de 2024
   
   Link de la simulación en Tinkercad: https://www.tinkercad.com/things/7O4lBu4a2Rl-parte-4-practica-4-bimestre-ii?sharecode=Y07zC7h8j4ol7GMzG_zNnRrva5BBZVQvIASQuRBDoW4
   
*/
 
int numero =  0;
 
 
void setup(){
 
Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  Serial.println("Contador de 0 a 99");
  Serial.println("Presione el primer boton para seguir y segundo para regresar");
}
 
void loop(){ 
  if(digitalRead(2) == HIGH){
    numero++;
    Serial.println(numero);
    if(numero >= 99){
      numero = 0;
    }
    delay(200);
  }
  if(digitalRead(3) == HIGH){
    numero--;
    Serial.println(numero);
    if(numero <=0){
      numero = 99;
    }
    delay(200);
  }
}
