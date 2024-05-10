//Tercera parte de la practica numero cinco.
/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Relevadores y visualizadores
   Dev: Damasco Oxcal Vasquez
   Fecha: 10 de mayo
*/
// Definimos los pines conectados al 7448
int a = 4;
int b = 5;
int c = 6;
int d = 7;

const int pinBuzzer = 8;//pin 8 para el pinBuzzer.
int RELE=2; //PIN IN DE MODULO A PIN DIGITAL 2 DE ARDUINO

void setup() {
  // Configuramos los pines de datos como salida
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(RELE, OUTPUT);//pin 2 como salida

}

void loop() {
  // Mostramos los números del 9 al 0
  for (int i = 9; i >= 0; i--) {
    mostrarNumero(i);
    delay(1000); // Esperamos 1 segundo entre cada número
  }
  tone(pinBuzzer, 250);//generar tono de 250Hz durante 500 ms.
  delay(500);//durante 500 ms.
  noTone(pinBuzzer);//detener tono
  digitalWrite(RELE, LOW);//activacion del modulo del rele con un nivel bajo.
  delay(5000);//demora 5 sugundos
  digitalWrite(RELE, HIGH);//apagado del modulo del rele con un nivel alto.
  delay(10000);//demora 10 segundos
}

// Función para mostrar un número en el display de 7 segmentos
void mostrarNumero(int numero) {
  // Definimos el BCD correspondiente a cada número
  const int bcd[10] = {
    B0000, // 0
    B0001, // 1
    B0010, // 2
    B0011, // 3
    B0100, // 4
    B0101, // 5
    B0110, // 6
    B0111, // 7
    B1000, // 8
    B1001  // 9
  };
  
  // Configuramos los pines de datos según el BCD del número
  digitalWrite(a, bitRead(bcd[numero], 0)); // Configuramos a según el bit menos significativo del BCD
  digitalWrite(b, bitRead(bcd[numero], 1)); // Configuramos b según el segundo bit del BCD
  digitalWrite(c, bitRead(bcd[numero], 2)); // Configuramos c según el tercer bit del BCD
  digitalWrite(d, bitRead(bcd[numero], 3)); // Configuramos d según el bit más significativo del BCD
}
