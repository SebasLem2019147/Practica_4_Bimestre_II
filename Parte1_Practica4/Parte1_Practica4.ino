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
   
   Link de la simulación en Tinkercad: https://www.tinkercad.com/things/hWYohlHpFmm-parte-1-practica-4-bimestre-ii?sharecode=ugtb0PZjEeeK-fJnafkwPFo1ffb_9G8AcR03yGUEPzA
   
*/

int tiempo = 1000;
int i = 0;

const int A = 2;
const int B = 3;
const int C = 4;
const int D = 5;

const int N = 4;
const int entradas[N] = {A, B, C, D};

const int numeros[10][N] = {
  {0, 0, 0, 0},
  {1, 0, 0, 0},
  {0, 1, 0, 0},
  {1, 1, 0, 0},
  {0, 0, 1, 0},
  {1, 0, 1, 0},
  {0, 1, 1, 0},
  {1, 1, 1, 0},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};

void setup(){
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  for (i = 0; i < N; i++) {              
    pinMode(entradas[i], OUTPUT);
    digitalWrite(entradas[i], HIGH);
  }
}

void loop(){
  if(digitalRead(6) == HIGH){
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < N; k++) { 
        digitalWrite(entradas[k], numeros[j][k]);
      }
      delay(tiempo);
    }
    for (int k = 0; k < N; k++) { 
      digitalWrite(entradas[k], HIGH);
    }
  }
  if(digitalRead(7) == HIGH){
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < N; k++) { 
        digitalWrite(entradas[k], numeros[j][k]);
      }
      delay(tiempo+1000);
    }
    for (int k = 0; k < N; k++) { 
      digitalWrite(entradas[k], HIGH);
    }
  }
  if(digitalRead(8) == HIGH){
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < N; k++) { 
        digitalWrite(entradas[k], numeros[j][k]);
      }
      delay(tiempo+2000);
    }
    for (int k = 0; k < N; k++) { 
      digitalWrite(entradas[k], HIGH);
    }
  }
  else{
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < N; k++) { 
        digitalWrite(entradas[k], numeros[j][k]);
      }
      delay(tiempo/2);
    }
    for (int k = 0; k < N; k++) { 
      digitalWrite(entradas[k], HIGH);
    }
  }
} 
