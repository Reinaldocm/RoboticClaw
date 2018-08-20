#include <Bounce2.h>
#include <Servo.h>

#define BOUNCE_TIME 250;

Servo servoBase;
int pinServoBase = 10;
int girobase = 90;
int pinButtonBaseUP = 2;
Bounce buttonBaseUP = Bounce();
int  pinButtonBaseDOWN = 3;
Bounce buttonBaseDOWN = Bounce();

Servo servoHorizontal;
int pinServoHorizontal = 11;
int giroH = 90;
int pinButtonHUP = 4;
Bounce buttonHUP = Bounce();
int pinButtonHDOWN = 5;
Bounce buttonHDOWN = Bounce();

Servo servoElevacao;
int pinServoElevacao = 12;
int giroE = 90;
int pinButtonEUP = 6;
Bounce buttonEUP = Bounce();
int pinButtonEDOWN = 7;
Bounce buttonEDOWN = Bounce();

int sensibilidade = 10;

void setup() {
  servoBase.attach(pinServoBase);
  buttonBaseUP.attach(pinButtonBaseUP, INPUT_PULLUP);
  buttonBaseDOWN.attach(pinButtonBaseDOWN, INPUT_PULLUP);
  servoHorizontal.attach(pinServoHorizontal);
  buttonHUP.attach(pinButtonHUP, INPUT_PULLUP);
  buttonHDOWN.attach(pinButtonHDOWN, INPUT_PULLUP);
  servoElevacao.attach(pinServoElevacao);
  buttonEUP.attach(pinButtonEUP, INPUT_PULLUP);
  buttonEDOWN.attach(pinButtonEDOWN, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  if (buttonBaseUP.update()) {
    if (buttonBaseUP.read() == LOW) {
      girobase = limiteServoBase(girobase, 1);
    }
  }
  if (buttonBaseDOWN.update()) {
    if (buttonBaseDOWN.read() == LOW) {
      girobase = limiteServoBase(girobase, 0);
    }
  }
  Serial.print(" BASE: ");
  Serial.print(girobase);
  servoBase.write(girobase);

  if (buttonHUP.update()) {
    if (buttonHUP.read() == LOW) {
      giroH = limiteServoHorizontal(giroH, 1);
    }
  }
  if (buttonHDOWN.update()) {
    if (buttonHDOWN.read() == LOW) {
      giroH = limiteServoHorizontal(giroH, 0);
    }
  }
  Serial.print(" H: ");
  Serial.print(giroH);
  servoHorizontal.write(giroH);

  if (buttonEUP.update()) {
    if (buttonEUP.read() == LOW) {
      giroE = limiteServoElevacao(giroE, 1);
    }
  }
  if (buttonEDOWN.update()) {
    if (buttonEDOWN.read() == LOW) {
      giroE = limiteServoElevacao(giroE, 0);
    }
  }
  Serial.print(" E: ");
  Serial.print(giroE);
  servoHorizontal.write(giroE);
  Serial.println ("");
}

int limiteServoBase(int valor, bool operacao) {
  if (operacao == 1) {
    if (valor + sensibilidade > 180) {
      return (180);
    } else {
      return (valor + sensibilidade);
    }
  } else if (operacao == 0) {
    if (valor - sensibilidade < 0) {
      return (0);
    } else {
      return (valor - sensibilidade);
    }
  }
}


int limiteServoHorizontal(int valor, bool operacao) {
  if (operacao == 1) {
    if (valor + sensibilidade > 180) {
      return (180);
    } else {
      return (valor + sensibilidade);
    }
  } else if (operacao == 0) {
    if (valor - sensibilidade < 0) {
      return (0);
    } else {
      return (valor - sensibilidade);
    }
  }
}

int limiteServoElevacao(int valor, bool operacao) {
  if (operacao == 1) {
    if (valor + sensibilidade > 180) {
      return (180);
    } else {
      return (valor + sensibilidade);
    }
  } else if (operacao == 0) {
    if (valor - sensibilidade < 0) {
      return (0);
    } else {
      return (valor - sensibilidade);
    }
  }
}

