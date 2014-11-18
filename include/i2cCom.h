#ifndef I2CCOM_H
#define I2CCOM_H

#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c-dev-user.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


class i2ccom
{
	public:
	i2ccom();
	~i2ccom();
	
	void init();
	
	private:
	
	
};

#endif /* I2CCOM_H */
