/*
 * Get the button correspondent to message
 * @param message
 * @return charactere of button
 */
char control(long int message){
  int message1 = (message >> 16) & 0b1111111111111111;
  int message2 =  message & 0b1111111111111111;
  
  if(message1 == 0x3434){
    if(message2 == 0xD22D){
      return '0';
    }
    if(message2 == 0x827D){
      return '1';
    }
    if(message2 == 0x42BD){
      return '2';
    }
    if(message2 == 0xC23D){
      return '3';
    }
    if(message2 == 0x22DD){
      return '4';
    }
    if(message2 == 0xA25D){
      return '5';
    }
    if(message2 == 0x629D){
      return '6';
    }
    if(message2 == 0xE21D){
      return '7';
    }
    if(message2 == 0x12ED){
      return '8';
    }
    if(message2 == 0x926D){
      return '9';
    }
    if(message2 == 0x7887){
      return 'P';
    }
    if(message2 == 0x55AA){
      return 'M';
    }
    if(message2 == 0XE817){
      return 'U';
    }
    if(message2 == 0x6897){
      return 'D';
    }
    if(message2 == 0x748B){
      return '#';
    }
    if(message2 == 0x33CC){
      return 'S';
    }
    if(message2 == 0x9A65){
      return 'B';
    }
    if(message2 == 0xC53A){
      return 'T';
    }
  }
  if(message1 == 0x4AB0){
    return '.';
  }
}

/*
 * Get from control a pwm number
 * @return number between 0 and 255
 */
 int pwmNumber(){
    int cont = 0;
    int pwm = 0;
    
    while(cont<3)
    {
      if (irrecv.decode(&results)) {
        int number = (int)control(results.value) - 48;
        if(number >= 0 && number < 10){
          if(cont == 0){
            Serial.print(">>");
            Serial.print(number);
            pwm = 100*number;
          }
          if(cont == 1){
            Serial.print(number);
            pwm = pwm + (number*10);
          }
          if(cont == 2){
            Serial.println(number);
            pwm = pwm + number;
          }
          cont++;

        }
        irrecv.resume();
      }
    }
    if (pwm < 0){
      return 0;
    }
    else if (pwm > 255){
      return 255;
    }
    else{     
      return pwm;
    }
 } 

