
/***********Master**************/
#define SCK_Mater 25
#define	MOSI_Master 26
#define MISO_Master 27
#define SS_Master 14

/***********Slave**************/
#define SCK_Slave 19
#define	MOSI_Slave 18
#define MISO_Slave 17
#define SS_Slave 16

#define num_slave_send 255
#define num_master_send 10

int nums_byte_read = 0;
int nums_byte_slave_send = 0;
uint8_t number_slave_read = 0x00;
uint8_t number_master_read = 0x00;

uint8_t is_read_or_write = 0;

enum READWRITE{
	READ = 0,
	WRITE
};

void IRAM_ATTR Read_SPI(){
	if(digitalRead(SS_Slave) == 1) return;
	number_slave_read <<= 1;
	number_slave_read |= (digitalRead(MOSI_Slave));
	++nums_byte_read;
	digitalWrite(MISO_Slave, ((num_slave_send >> (7-nums_byte_slave_send))&0x01) ? HIGH : LOW);
	++nums_byte_slave_send;
	
}



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  pinMode(SCK_Mater, OUTPUT);
  pinMode(MOSI_Master, OUTPUT);
  pinMode(MISO_Master, INPUT);
  pinMode(SS_Master, OUTPUT);
  digitalWrite(SS_Master, HIGH);
  digitalWrite(SCK_Mater, LOW);
  
  pinMode(SCK_Slave, INPUT);
  pinMode(MOSI_Slave, INPUT);
  pinMode(MISO_Slave, OUTPUT);
  pinMode(SS_Slave, INPUT);
  attachInterrupt(SCK_Slave, Read_SPI, RISING);
  digitalWrite(MISO_Slave, ((num_slave_send >> (7-nums_byte_slave_send))&0x01) ? HIGH : LOW);
  ++nums_byte_slave_send;
  delay(3000);
  Serial.println("Bat dau truyen data");

}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(nums_byte_read == 8){
	  Serial.printf("Number slave read : %d\n", number_slave_read);
	  Serial.printf("Number master read : %d\n", number_master_read);
	  nums_byte_read = 0;
	  nums_byte_slave_send = 0;
	  digitalWrite(MISO_Slave, ((num_slave_send >> (7-nums_byte_slave_send))&0x01) ? HIGH : LOW);
	  ++nums_byte_slave_send;
  }
  if(nums_byte_read == 0){
	  number_master_read = SPI_Transmit_Receive(num_master_send);
  }
	delay(2000);
}

void Clock(){
	digitalWrite(SCK_Mater, HIGH);
	asm volatile("nop"::);
	digitalWrite(SCK_Mater, LOW);
	asm volatile("nop"::);
}

uint8_t SPI_Transmit_Receive(uint8_t data){
	digitalWrite(SS_Master, LOW);
	uint8_t _data = 0x00;
	for(int i=0; i<8; i++){
		digitalWrite(MOSI_Master, ((data >> (7-i))&0x01) ? HIGH : LOW);
		_data <<= 1;
		_data |= digitalRead(MISO_Master); 
		Clock();
	}
	digitalWrite(SS_Master, HIGH);
	return _data;
}
