
//---------------Variable for doccambien function----------------//
#define socambien 10
int lastButtonState[socambien];
int lastCBState[socambien]; 
int tatcathungday = 0;
unsigned long lastDebounceTime[socambien] = {0,0,0,0,0};

#define LED 13
#define BUTTON 7

uint8_t ui8_is_not_run_led = 0;

void setup() {
  // put your setup code here, to run once:
	pinMode(LED, OUTPUT);
	pinMode(BUTTON, INPUT_PULLUP);
	initInterrupt_timer();
}

void loop() {
  // put your main code here, to run repeatedly:
	if(Read_Button(BUTTON, 0) == 1){
		ui8_is_not_run_led = 1;
	}
	else ui8_is_not_run_led = 0;
}


void initInterrupt_timer(){
    noInterrupts();
    cli(); //Stop all Interrupt
    
    //---------Reset Timer/Counter1------------//
    TCCR1A = 0;  //reset register of TIM1/CNT1 
    TCCR1B = 0;  //reset register of TIM1/CNT1
    TIMSK1 = 0; 
    TIFR1 = 0;   //reset flag interrupt
    
    
    /*----Config Timer interrupt------*/
    /*
        Interrupt do after 200ms. Use timer 1
        Arduino Mega run on 16Mhz. Set prescale 256 => 256/16Mhz = 16uS (1 tick ui64_cnt)
        so if ui64_cnt from 0 to 65535 = 65536 * 16us = 1,048s > 0.2s
        If interrupt do after 0.2s => 0.2s/16us = 12500 ui64_cnt => 65536 - 12500 = 53036
        => value of TCNT1 = 53036.
    */
     TCCR1B |= (1<<CS12);  //set bit CS12 to set prescale is 256
     TCNT1 = 53036;        //Set TCNT1 register ui64_cnt from 53036 to 65535
     TIMSK1 = (1<<TOIE1);  //Set bit TOIE1 to 1 to enable overflow interrupt
     // OCR1B = 12500;
     sei(); //Start All Interrupt
     interrupts();
    
}

ISR(TIMER1_OVF_vect){  //ISR(Vector_name) Vector_name must be right name of interrupt. TIMER1_OVF_vect is Overflow interrupt Timer1
    TCNT1 = 53036;
	if(ui8_is_not_run_led == 1) return;
	digitalWrite(LED, !digitalRead(LED));
}

int Read_Button(int pin, int index){
   int reading = digitalRead(pin);

  if (reading != lastButtonState[index]) {		
			lastDebounceTime[index] = millis();	
  }

  if ((millis() - lastDebounceTime[index]) > 100) {
	if(reading == LOW){
        return 1;
    }	
  }

  lastButtonState[index] = reading;
  return 0;
}