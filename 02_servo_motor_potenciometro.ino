#include <Servo.h>


const int potAngulo = A5;
const int potVelocidade = A4;

const int pinoServo = 9;

int leituraAngulo;
int leituraVelocidade;

int anguloMaximo;
int velocidade;

Servo servo_motor;

void setup() {
  pinMode(potAngulo, INPUT);
  pinMode(potVelocidade, INPUT);

  servo_motor.attach(pinoServo);
}

void loop() {
  // Le os dois potenciometros
  leituraAngulo = analogRead(potAngulo);
  leituraVelocidade = analogRead(potVelocidade);

  // Define o angulo maximo entre 10 e 170 graus
  anguloMaximo = map(leituraAngulo, 0, 1023, 0, 180);

  // Define o intervalo entre movimentos:
  // menor intervalo = movimento mais rapido
  velocidade = map(leituraVelocidade, 0, 1023, 2, 15);

  // Move o servo do angulo minimo ao maximo
  for (int angulo = 10; angulo <= anguloMaximo; angulo++) {
    servo_motor.write(angulo);
    delay(velocidade);
  }

  // Retorna do angulo maximo ao minimo
  for (int angulo = anguloMaximo; angulo >= 10; angulo--) {
    servo_motor.write(angulo);
    delay(velocidade);
  }
}
