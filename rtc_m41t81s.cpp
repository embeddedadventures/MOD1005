
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

#include "rtc_m41t81s.h"
#include "Wire.h"

char reg_data[8];

void updateTimeData() {
	int i = 0; 
	sendAddress();
	Wire.requestFrom(m41t81s_device_addr, 8);
	while (Wire.available())    // slave may send less than requested
	{
		reg_data[i] = Wire.read();    // receive a byte as character
		i++;
	}
}

uns8 bcdToDec(uns8 bcd) {
	return (bcd & 0x0F) + ((bcd >> 4) * 10);
}

uns8 decToBCD(uns8 dec) {
	return ((dec / 10) << 4) + (dec % 10);
}

void sendAddress() {
	Wire.beginTransmission(m41t81s_device_addr);
	Wire.write(0);
	Wire.endTransmission();
}

void rtc_init() {
	Wire.begin();
	Wire.beginTransmission(m41t81s_device_addr);
	Wire.write(0x0C);
	Wire.write(0x3F);
	Wire.endTransmission();
}

void resetClock() {
	Wire.beginTransmission(m41t81s_device_addr);
	Wire.write(0x00);  //Reg Address
	Wire.write(0x00);  //psecs
	Wire.write(0x00);  //Secs
	Wire.write(0x00);  //mins
	Wire.write(0x00);  //hrs
	Wire.endTransmission();
}

uns8 getSeconds() {
	updateTimeData();
	return bcdToDec(reg_data[1] & 0x7F);
}

uns8 getMinutes() {
	updateTimeData();
	return bcdToDec(reg_data[2] & 0x7F);
}

uns8 getHours() {
	updateTimeData();
	return bcdToDec(reg_data[3] & 0x3F);
}

uns8 getDayOfWeek() {
	updateTimeData();
	return bcdToDec(reg_data[4] & 0x07);
}

uns8 getDate() {
	updateTimeData();
	return bcdToDec(reg_data[5] & 0x3F);
}

uns8 getMonth() {
	updateTimeData();
	return bcdToDec(reg_data[6] & 0x1F);
}

uns8 getYear() {
	updateTimeData();
	return bcdToDec(reg_data[7]);
}

void setSeconds(uns8 secs) {
	Wire.beginTransmission(m41t81s_device_addr);
	Wire.write(m41t81s_seconds_reg);  //Reg Address
	Wire.write(decToBCD(secs));
	Wire.endTransmission();
}

void setMinutes(uns8 mins) {
	Wire.beginTransmission(m41t81s_device_addr);
	Wire.write(m41t81s_minutes_reg);  //Reg Address
	Wire.write(decToBCD(mins));
	Wire.endTransmission();
}

void setHours(uns8 hrs) {
	Wire.beginTransmission(m41t81s_device_addr);
	Wire.write(m41t81s_hours_reg);  //Reg Address
	Wire.write(decToBCD(hrs));
	Wire.endTransmission();
}

void setDayOfWeek(uns8 dow) {
	Wire.beginTransmission(m41t81s_device_addr);
	Wire.write(m41t81s_dow_reg);  //Reg Address
	Wire.write(decToBCD(dow));
	Wire.endTransmission();
}

void setDate(uns8 date) {
	Wire.beginTransmission(m41t81s_device_addr);
	Wire.write(m41t81s_date_reg);  //Reg Address
	Wire.write(decToBCD(date));
	Wire.endTransmission();
}

void setMonth(uns8 month) {
	Wire.beginTransmission(m41t81s_device_addr);
	Wire.write(m41t81s_month_reg);  //Reg Address
	Wire.write(decToBCD(month) & 0x1F);
	Wire.endTransmission();
}

void setYear(uns8 year) {
	Wire.beginTransmission(m41t81s_device_addr);
	Wire.write(m41t81s_year_reg);  //Reg Address
	Wire.write(decToBCD(year));
	Wire.endTransmission();
}