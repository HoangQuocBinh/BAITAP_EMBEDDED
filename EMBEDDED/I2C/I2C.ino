
/*
* File: I2C.ino
* Author: HOANG QUOC BINH
* Date: 12/04/2023
* Description: This is file for I2C using ESP8266
*/

/***********Master**************/
#define SCK_Master D5
#define	SDA_Master D6

/***********Slave**************/
#define SCK_Slave D7
#define	SDA_Slave D8

#define addr_slave 0x20
#define addr_slave_wrong 0x21

#define data_master_send 255
#define data_slave_send 196

uint8_t bitStart = 0; //BIT BAT DAU GIAO TIEP I2C
uint8_t data_temp_read = 0x00; // DATA TAM SLAVE DOC DATA TU MASTER
uint8_t num_byte_slave = 0; //SO BYTE SLAVE DA DOC HOAC TRUYEN`
uint8_t data_slave_read = 0; // DATA SLAVE DOC TU MASTER
uint8_t data_master_read = 0; // DATA MASTER DOC TU SLAVE
uint8_t is_right_addr = 0; // BIT KIEM TRA DIA CHI DUOC TRUYEN TU MASTER
uint8_t is_master_read_or_write; // BIT KIEM TRA MASTER DOC HAY TRUYEN DU LIEU
uint8_t is_send_ACK = 0; // BIT KIEM TRA TRUYEN ACK
uint8_t printfirsttime = 0; //IN DU LIEU RA MAN HINH 
uint8_t wait_ACK = 0; // BIT CHO ACK CHO SLAVE
uint8_t readwrite = 0; //BIT XU LY TRUYEN DOC DU LIEU LUAN PHIEN TU MASTER
uint8_t is_master_read_done = 0;

uint32_t ui32_timeout_sendread_data = 0; //TIME OUT GIAO TIEP I2C
uint32_t ui32_timeout_master_read_send_data = 0; //TIME 

#define READ_ACK(pin)										\
	pinMode(pin, INPUT);									\
	timeout = millis() + 100;								\
	while(digitalRead(pin) == HIGH){						\
		if(timeout <= millis()){							\
			Serial.println("KHONG GIAO TIEP DUOC I2C");	    \
			return;											\
		}													\
	}

#define READ_ACK_NOT_VOID(pin)										\
	pinMode(pin, INPUT);									\
	timeout = millis() + 100;								\
	while(digitalRead(pin) == HIGH){						\
		if(timeout <= millis()){							\
			Serial.println("KHONG GIAO TIEP DUOC I2C");	    \
			return 0;											\
		}													\
	}
	
#define SEND_DATA(pin, data)											\
	for(int i=0; i<8; i++){												\
		digitalWrite(SDA_Master, ((data >> (7-i))&0x01) ? HIGH : LOW);	\
		Clock();														\
	}
	
#define READ_DATA(pin)				\
	uint8_t data = 0x00;			\
	for(int i=0; i<8; i++){			\
		data <<= 1;					\
		data |= digitalRead(pin);	\
		Clock();					\
	}
enum Read_Write{
	WRITE = 0,
	READ
};

enum State_Addr{
	NOTCORRECT = 1,
	CORRECT
};

/*
* Function: I2C_Handle
* Description: This function is interrupt handle that use for slave read or send data
* Input:
*   input: None
* Output:
*   return: None
*/
void IRAM_ATTR I2C_Handle(){
	
	if(digitalRead(SDA_Slave) == HIGH && bitStart == 0) return;
	if(is_right_addr == NOTCORRECT) return;
	if(is_master_read_done == 1) return;
	
	
	if(bitStart == 1){ 
	
		if(is_send_ACK == 0){
			if(is_master_read_or_write == WRITE){
				pinMode(SDA_Slave, INPUT);
				data_temp_read <<= 1;
				data_temp_read |= digitalRead(SDA_Slave);
				++num_byte_slave;
			}
			else{
				if(wait_ACK != 1){
					digitalWrite(SDA_Slave, ((data_slave_send >> (7-num_byte_slave))&0x01) ? HIGH : LOW);
					++num_byte_slave;
				}
			}
		}
		
		else{
			if(is_master_read_or_write == WRITE) {
				pinMode(SDA_Slave, INPUT);
				num_byte_slave = 0;
			}
			else {
				if(wait_ACK == 1){
					pinMode(SDA_Slave, INPUT);
					if(digitalRead(SDA_Slave) == HIGH) {
						is_master_read_done = 1;
						return;
					}
				}
				pinMode(SDA_Slave, OUTPUT);
				num_byte_slave = 0;
				digitalWrite(SDA_Slave, ((data_slave_send >> (7-num_byte_slave))&0x01) ? HIGH : LOW);
				++num_byte_slave;
				wait_ACK = 0;
			}
			
			is_send_ACK = 0;
			data_slave_read = data_temp_read;
			data_temp_read = 0x00;
		}
		
		if(num_byte_slave == 8){
			if(is_right_addr == 0){
				pinMode(SDA_Slave, OUTPUT);
				digitalWrite(SDA_Slave, HIGH);
				register uint8_t temp = data_temp_read >> 1;
				if(temp == (uint8_t)addr_slave) is_right_addr = CORRECT;
				else {
					is_right_addr = NOTCORRECT;
					return;
				}
				is_master_read_or_write = data_temp_read - ((uint8_t)addr_slave << 1);
				Send_ACK((uint8_t)WRITE);
				is_send_ACK = 1;
			}
			else if(is_master_read_or_write == WRITE){
				Send_ACK((uint8_t)WRITE);
				is_send_ACK = 1;
				printfirsttime = 0;  //IN RA MAN HINH 1 LAN
			}
			else if(is_master_read_or_write == READ){
				if(wait_ACK == 1) is_send_ACK = 1;
				wait_ACK = 1;
				printfirsttime = 0;  //IN RA MAN HINH 1 LAN
			}
		}
	}
	
	bitStart = 1; //BAT DAU DOC DU LIEU
	ui32_timeout_sendread_data = millis() + 100; //TIMEOUT KET THUC GIAO TIEP I2C
}

void setup() {
  // put your setup code here, to run once:
	Serial.begin(115200);
	
	I2C_Init();
	
	// Master_Send_Data(addr_slave, (uint8_t)data_master_send);
	delay(2000);
	printfirsttime =1;
	ui32_timeout_master_read_send_data = millis() + 1000;
}



void loop() {
  // put your main code here, to run repeatedly:
	if(ui32_timeout_sendread_data <= millis()){
		if(printfirsttime == 0){
			if(readwrite == READ) Serial.printf("Data Master Read = %d\n", data_master_read);
			else Serial.printf("Data Slave Read = %d\n", data_slave_read);
			printfirsttime = 1;
		}
		
		bitStart = 0;
		is_send_ACK = 0;
		num_byte_slave = 0;
		data_temp_read = 0x00;
		is_right_addr = 0;
		is_master_read_or_write = WRITE;
		is_master_read_done = 0;
	}
	
	if(ui32_timeout_master_read_send_data <= millis()){
		readwrite = 1 - readwrite;
		if(readwrite == WRITE) Master_Send_Data(addr_slave, data_master_send);
		else data_master_read = Master_Read_Data(addr_slave);
		ui32_timeout_master_read_send_data = millis() + 2000;
	}
	
	
}

/*
* Function: I2C_Init
* Description: This function use for init Software I2C
* Input:
*   input: None
* Output:
*   return: None
*/
void I2C_Init(){
	pinMode(SCK_Master, OUTPUT);
	digitalWrite(SCK_Master, HIGH);
	pinMode(SCK_Slave, INPUT);

	attachInterrupt(SCK_Slave, I2C_Handle, FALLING);
}

/*
* Function: Clock
* Description: This function use for creatting clock for I2C
* Input:
*   input: None
* Output:
*   return: None
*/
void Clock(){
	digitalWrite(SCK_Master, HIGH);
	delayMicroseconds(5);
	digitalWrite(SCK_Master, LOW);
	delayMicroseconds(5);
}

/*
* Function: Master_Send_Data
* Description: This function use for sending data to Slave
* Input:
*   addr: address of slave
*	data: data want to send
* Output:
*   return: None
*/
void Master_Send_Data(uint8_t addr, uint8_t data){
	
	uint32_t timeout = 0;
	Send_Bit_Start();
	
	addr <<= 1;
	addr |= (uint8_t)WRITE;
	SEND_DATA(SDA_Master, addr);
	READ_ACK(SDA_Master);
	Clock();

	delayMicroseconds(5);
	pinMode(SDA_Master, OUTPUT);
	SEND_DATA(SDA_Master, data);
	READ_ACK(SDA_Master);
	Clock();
	
	Send_Bit_Stop();
	
}

/*
* Function: Master_Read_Data
* Description: This function use for reading data from Slave
* Input:
*   addr: address of slave
* Output:
*   return: data from slave
*/
uint8_t Master_Read_Data(uint8_t addr){
	
	uint32_t timeout = 0;
	
	Send_Bit_Start();
	addr <<= 1;
	addr |= (uint8_t)READ;
	SEND_DATA(SDA_Master, addr);
	READ_ACK_NOT_VOID(SDA_Master);
	Clock();
	
	delayMicroseconds(5);
	READ_DATA(SDA_Master);
	Send_NACK();
	
	Send_Bit_Stop();
	return data;
	
}

/*
* Function: Send_Bit_Start
* Description: This function use for sending bit start to start I2C
* Input:
*   input: None
* Output:
*   return: None
*/
void Send_Bit_Start(){
	pinMode(SDA_Master, OUTPUT);
	digitalWrite(SDA_Master, HIGH);
	digitalWrite(SCK_Master, HIGH);
	// pinMode(SDA_Slave, INPUT);
	delayMicroseconds(5);
	digitalWrite(SDA_Master, LOW);
	delayMicroseconds(5);
	digitalWrite(SCK_Master, LOW);
}

/*
* Function: Send_Bit_Stop
* Description: This function use for sending bit stop to stop I2C
* Input:
*   input: None
* Output:
*   return: None
*/
void Send_Bit_Stop(){
	// pinMode(SDA_Master, OUTPUT);
	digitalWrite(SDA_Master, LOW);
	digitalWrite(SCK_Master, LOW);
	// pinMode(SDA_Slave, INPUT);
	digitalWrite(SCK_Master, HIGH);
	delayMicroseconds(5);
	digitalWrite(SDA_Master, HIGH);
}

/*
* Function: Send_ACK
* Description: This function use for sending bit ACK
* Input:
*   mode: master send or receive 
* Output:
*   return: None
*/
void Send_ACK(uint8_t mode){
	if(mode == WRITE){
		pinMode(SDA_Slave, OUTPUT);
		digitalWrite(SDA_Slave, LOW);
	}
	else if(mode == READ){
		pinMode(SDA_Master, OUTPUT);
		digitalWrite(SDA_Master, LOW);
		Clock();
	}
	
}

/*
* Function: Send_NACK
* Description: This function use for sending bit NAck
* Input:
*   input: None
* Output:
*   return: None
*/
void Send_NACK(){
	pinMode(SDA_Master, OUTPUT);
	digitalWrite(SDA_Master, HIGH);
	Clock();
}