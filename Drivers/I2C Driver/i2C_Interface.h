#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H


#define GENERAL_CALL						0		//Toggle response to master's general call [0: disable, 1: enable]
#define TRANSMITTER							1		
#define RECEIVER							2
#define BIT_RATE_GENERATOR					0		//Set bit rate(TWBR) [0:255] 
#define PRESCALER_SELECTOR_1				0		//Select prescaler for SCL [0, 0, 1, 1] >> [1, 4 , 16, 64] 
#define PRESCALER_SELECTOR_2				0		//Select prescaler for SCL [0, 1, 0, 1] >> [1, 4 , 16, 64]    SCL_freq = F_CPU/(16+2(TWBR).Prescaler)



void I2C_init(void);
void I2C_init_As_Master(char slaveAddress,char mode);
void I2C_init_As_Slave(char slaveAddress);


//unsigned char I2C_Master_read_byte(void);
void I2C_Master_write_byte(unsigned char data);
void I2C_Slave_read_addr(void);
unsigned char I2C_Slave_read_byte(void);
//void I2C_Slave_write_byte(unsigned char data);
void I2C_Slave_read_arr(unsigned char* arr, int arrSize);
void I2C_Stop();

#endif