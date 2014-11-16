#include <i2cCom.h>

i2ccom::i2ccom()
{
	init();
}

i2ccom::~i2ccom()
{
	
}

void i2ccom::init()
{
	// Openning i2c device
	int file;
	char *filename = "/dev/i2c-1";
	if ((file = open(filename, O_RDWR)) < 0) {
		/* ERROR HANDLING: you can check errno to see what went wrong */
		perror("Failed to open the i2c bus");
		exit(1);
	}
	printf("I2C device well opened\n");
	
	// openning i2c bus at address 0x11
	int addr = 0x11;          // The I2C address of the ADC
	if (ioctl(file, I2C_SLAVE, addr) < 0) {
		printf("Failed to acquire bus access and/or talk to slave.\n");
		/* ERROR HANDLING; you can check errno to see what went wrong */
		exit(1);
	}
	printf("I2C bus well opened\n");
	
}