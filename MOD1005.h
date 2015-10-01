#ifndef __MOD1005_h
#define __MOD1005_h 

#include "Arduino.h"

#define uns8 unsigned int
#define mod1005_addr 0x68

/*Register address definitions*/
#define mod1005_pseconds_reg	0x00
#define mod1005_seconds_reg		0x01
#define mod1005_minutes_reg		0x02
#define mod1005_hours_reg 		0x03
#define mod1005_dow_reg 		0x04
#define mod1005_date_reg 		0x05
#define mod1005_month_reg 		0x06	
#define mod1005_year_reg		0x07

class MOD1005Class 
{
private: 
	uns8 bcdToDec(uns8 bcd);
	uns8 decToBCD(uns8 dec);
	uns8 readRegister(uns8 addr);
	char reg_data[8];

public:	
	/*Reset registers 0-7 in RTC*/
	void reset();
	
	void init();
	
	/*Returns seconds as int*/
	uns8 getSeconds();
	
	/*Returns minutes as int*/
	uns8 getMinutes();
	
	/*Returns hours as int*/
	uns8 getHours();
	
	/*Returns day of the week as int. 1 = Sunday, 2 = Monday, etc*/
	uns8 getDayOfWeek();
	
	/*Returns date of month*/
	uns8 getDate();
	
	/*Returns month as int*/
	uns8 getMonth();
	
	/*Returns last two digits of current year as int*/
	uns8 getYear();
	
	/*Returns 0.01 seconds*/
	uns8 getPartSeconds();
	
	void setSeconds(uns8 sec);
	void setMinutes(uns8 mins);
	void setHours(uns8 hrs);
	void setDayOfWeek(uns8 dow);
	void setDate(uns8 date);
	void setMonth(uns8 month);
	void setYear(uns8 year);
};

extern MOD1005Class mod1005;

#endif