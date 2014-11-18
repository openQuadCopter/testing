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
	
	// openning i2c bus at address 0x04
	int addr = 0x04;          // The I2C address of the ADC
	if (ioctl(file, I2C_SLAVE, addr) < 0) {
		printf("Failed to acquire bus access and/or talk to slave.\n");
		/* ERROR HANDLING; you can check errno to see what went wrong */
		exit(1);
	}
	printf("I2C bus well opened\n");
	
	unsigned char values[5];
	int reg = 0x04;
	values[0] = 1;
	values[1] = 67;
	values[2] = 67;
	values[3] = 67;
	values[4] = 67;
	i2c_smbus_write_i2c_block_data(file, addr, 5, values);
	close(file);
}

