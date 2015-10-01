/*

Copyright (c) 2015, Embedded Adventures
All rights reserved.

Contact us at source [at] embeddedadventures.com
www.embeddedadventures.com

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

- Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.

- Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.

- Neither the name of Embedded Adventures nor the names of its contributors
  may be used to endorse or promote products derived from this software
  without specific prior written permission.
 
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
THE POSSIBILITY OF SUCH DAMAGE.

*/

// M41T81S MOD-1005 real-time clock Arduino library
// Written originally by Embedded Adventures


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