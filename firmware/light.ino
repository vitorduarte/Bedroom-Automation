  int vRed = 0;
  int vGreen = 0;
  int vBlue = 0;
  int cont = 0;

/*
 * send pwm parameters to Led
 * @param pwm led red, pwm led green, pwm led blue
 */
void writeLed(int r, int g, int b){  
  analogWrite(pinRed,r);
  analogWrite(pinGreen, g);
  analogWrite(pinBlue, b); 
}

void lightOn(char button){
  if(button == 'P'){
    Serial.print("[LED VERMELHO]");
    vRed = pwmNumber();
  }
  if(button == 'M'){
    Serial.print("[LED VERDE]");
    vGreen = pwmNumber();
  }
  if(button == 'U'){
    Serial.print("[LED AZUL]");
    vBlue = pwmNumber();

  }
  if(button == 'D'){
    if(cont%2 == 0){
        digitalWrite(pinLight, HIGH);
        Serial.print(cont);
        Serial.println(")Luz acionada");
      }
      else if (cont%2 == 1){
        digitalWrite(pinLight, LOW);
        Serial.print(cont);
        Serial.println(")Luz acionada");
      }
      cont++;
    }
  
  writeLed(vRed, vGreen, vBlue);
}

