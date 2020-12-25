#include "i2C_Interface.h"
#include "i2C_Private.h"
#include "i2C_Config.h"
#include "avr/io.h"


unsigned char status =0;


void I2C_init(void){
	TWBR = BIT_RATE_GENERATOR;
	TWSR = (PRESCALER_SELECTOR_1 << TWPS1)| (PRESCALER_SELECTOR_2 << TWPS0);
}


void I2C_init_As_Master(char slaveAddress,char mode){
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	while ( ! (TWCR & (1 << TWINT)));
	status = TWSR & 0xF8;
	if (status == 0x08 || status == 0x10) //A start or a repeated start has been transmitted 
	{
		switch (mode){
			case TRANSMITTER:
			TWDR = slaveAddress + 0;
			break;
			case RECEIVER:
			TWDR = slaveAddress + 1;
			break;
			default:
			break;
		}
		TWCR = (1 << TWINT) | (1 << TWEN);
		while ( ! (TWCR & (1 << TWINT)));
	}
	
	
}


void I2C_init_As_Slave(char slaveAddress){
	
	TWAR = slaveAddress | (GENERAL_CALL << TWGCE);
	TWCR = (1 << TWINT) | (1 << TWEA) | (0 << TWSTA) | (0 << TWSTO) | (1 << TWEN);
	while ( ! (TWCR & (1 << TWINT)));
}


//Not Tested
//unsigned char I2C_Master_read_byte(void){
	//status = TWSR & 0xF8;
	//switch (status){
		//case 0x38:
		//case 0x48:
			//TWCR =  (1 << TWSTA) | (0 << TWSTO) | (1 << TWINT);
			//return 0;
		//break;
		//case 0x40:
			//TWCR = (1 << TWINT) | (1 << TWEA);
			//return 0;
		//break;
		//case 0x50:
			//while ( ! (TWCR & (1 << TWINT)));
			//TWCR =  (0 << TWSTA) | (0 << TWSTO) | (1 << TWINT) | (1 << TWEA);
			//return TWDR;
		//break;
		//case 0x58:
			//TWCR |=  (1 << TWSTA) | (0 << TWSTO) | (1 << TWINT);
			//return 0;
		//break;
		//default:
			//return 0;
		//break;
	//}
//}


void I2C_Master_write_byte(unsigned char data){
	status = TWSR & 0xF8;
	switch (status){
		case 0x18:													//SLA+W has been transmitted. ACK has been received.
		case 0x28:													//Data byte has been transmitted. ACK has been received.
			TWDR = data;
			TWCR =  (0 << TWSTA) | (0 << TWSTO) | (1 << TWINT) | (1 << TWEN);
			while ( ! (TWCR & (1 << TWINT)));
			
		break;
		case 0x20:													//SLA+W has been transmitted. NOT ACK has been received.
		case 0x30:													//Data byte has been transmitted. NOT ACK has been received.
			while ( ! (TWCR & (1 << TWINT)));
			TWCR =  (0 << TWSTA) | (1 << TWSTO) | (1 << TWINT);
			return;
		break;
		case 0x38:													//Arbitration lost in SLA+W or data bytes.
			while ( ! (TWCR & (1 << TWINT)));
			TWCR =  (1 << TWSTA) | (0 << TWSTO) | (1 << TWINT);
			return;
		break;
		default:
		break;
	}
	return;
}


void I2C_Slave_read_addr(void){
	status = TWSR & 0xF8;
	switch (status){
		case 0x60:											//Own SLA+W has been received.Ack has been returned.
		case 0x68:											//Arbitration lost in SLA+R/W as Master; own SLA+W has been received; ACK has been returned.
		case 0x70:											//General call address has been received; ACK has been returned.
		case 0x78:											//Arbitration lost in SLA+R/W as Master; General call address has been received; ACK has been returned.
		TWCR =  (1 << TWEN) | (1 << TWINT) | (1 << TWEA);
		while ( ! (TWCR & (1 << TWINT)));
		return;
		break;
		default:
		return;
		break;
	}
}


unsigned char I2C_Slave_read_byte(void){
	unsigned char data = 0;
	status = TWSR & 0xF8;
	switch (status){
		case 0x80:						//Previously addressed with own SLA+W. Data has been received. ACK has been returned.
		case 0x90:						//Previously addressed with general call. Data has been received. ACK has been returned.
			data = TWDR;
			TWCR =  (0 << TWSTO) | (1 << TWINT) | (1 << TWEA) | (1 << TWEN);
			while ( ! (TWCR & (1 << TWINT)));
			return data;
		break;
		case 0x98:						//Previously addressed with general call. Data has been received. NOT ACK has been returned.
		case 0x88:						//Previously addressed with own SLA+W. Data has been received. NOT ACK has been returned.
			data = TWDR;
			TWCR =  (0 << TWSTA) | (0 << TWSTO) | (1 << TWINT) | (1 << TWEA);
			while ( ! (TWCR & (1 << TWINT)));
			return data;
		break;
		case 0xA0:						//A stop condition or repeated start condition has been received while still addressed as slave.
			TWCR =  (0 << TWSTA) | (0 << TWSTO) | (1 << TWINT) | (1 << TWEA) | (1 << TWEN);	
			while ( ! (TWCR & (1 << TWINT)));
			return data;
		break;
		default:
			return data;
		break;
	}
}


void I2C_Slave_read_arr(unsigned char* arr, int arrSize)
{
	int i;
	 for(i=0; i < arrSize;i++)
	 {
		 I2C_Slave_read_addr();
		 arr[i] = I2C_Slave_read_byte();
	 }
}


//NOT Tested
//void I2C_Slave_write_byte(unsigned char data){
	//status = TWSR & 0xF8;
	//switch (status){
		//case 0xA8:
		//case 0xB0:
		//case 0xB8:
			//while ( ! (TWCR & (1 << TWINT)));
			//TWDR = data;
			//TWCR = (0 << TWSTO) | (1 << TWINT) | (1 << TWEA);
		//break;
		//case 0xC0:
		//case 0xC8:
			//TWCR = (1 << TWSTA) | (0 << TWSTO) | (1 << TWINT) | (1 << TWEA);
		//break;
		//default:
		//break;
	//}
//}


void I2C_Stop()					
{
	TWCR=(1<<TWSTO)|(1<<TWINT)|(1<<TWEN);		
	while(TWCR&(1<<TWSTO));
}
