
/*
Copyright (c) 2015, Embedded Adventures, www.embeddedadventures.com
All rights reserved.
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
Contact us at source [at] embeddedadventures.com
*/

//Arduino library for using the m41t81s real-time clock module


#ifndef __rtc_m41t81s_h
#define __rtc_m41t81s_h 

#include <Arduino.h>

#define uns8 unsigned int
#define m41t81s_device_addr 0x68

/** m41t81s tenths and hundreths of seconds register */
#define m41t81s_part_seconds_reg 0x00
/** m41t81s seconds register (D7=ST)*/
#define m41t81s_seconds_reg 0x01
/** m41t81s minutes register */
#define m41t81s_minutes_reg 0x02
/** m41t81s hours register (D7=CEB, D6=CB) */
#define m41t81s_hours_reg   0x03
/** m41t81s day of week register */
#define m41t81s_dow_reg     0x04
/** m41t81s date in month register */
#define m41t81s_date_reg    0x05
/** m41t81s month register */
#define m41t81s_month_reg   0x06
/** m41t81s year register */
#define m41t81s_year_reg  0x07

uns8 bcdToDec(uns8 bcd);
uns8 decToBCD(uns8 dec);

/*Send address of RTC*/
void sendAddress();
/*Updates all info in the array*/
void updateTimeData();
/*Reset registers 0-7 in RTC*/
void resetClock();
void rtc_init();
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
void setSeconds(uns8 sec);
void setMinutes(uns8 mins);
void setHours(uns8 hrs);
void setDayOfWeek(uns8 dow);
void setDate(uns8 date);
void setMonth(uns8 month);
void setYear(uns8 year);

#endif