
#include "MOD1005.h"
#include "Wire.h"

uns8 MOD1005Class::bcdToDec(uns8 bcd) {
	return (bcd & 0x0F) + ((bcd >> 4) * 10);
}

uns8 MOD1005Class::decToBCD(uns8 dec) {
	return ((dec / 10) << 4) + (dec % 10);
}

uns8 MOD1005Class::readRegister(uns8 addr) {
	uns8 data;
	Wire.beginTransmission(mod1005_addr);
	Wire.write(addr);
	Wire.endTransmission();
	
	Wire.requestFrom(mod1005_addr, 8);
	if (Wire.available()) {
		data = Wire.read(); 
	}
	return data;
}

void MOD1005Class::init() {
	Wire.beginTransmission(mod1005_addr);
	Wire.write(0x0C);
	Wire.write(0x3F);
	Wire.endTransmission();
}

void MOD1005Class::reset() {
	Wire.beginTransmission(mod1005_addr);
	Wire.write(0x00);  
	Wire.write(0x00);  //psecs
	Wire.write(0x00);  //Secs
	Wire.write(0x00);  //mins
	Wire.write(0x00);  //hrs
	Wire.endTransmission();
}

uns8 MOD1005Class::getPartSeconds() {
	uns8 psecs = readRegister(mod1005_pseconds_reg);
	return (psecs & 0x0F) + (((psecs >> 4) & 0x0F) * 10);
}

uns8 MOD1005Class::getSeconds() {
	uns8 sec = readRegister(mod1005_seconds_reg);
	return bcdToDec(sec & 0x7F);
}

uns8 MOD1005Class::getMinutes() {
	uns8 min = readRegister(mod1005_minutes_reg);
	return bcdToDec(min & 0x7F);
}

uns8 MOD1005Class::getHours() {
	uns8 hr = readRegister(mod1005_hours_reg);
	return bcdToDec(hr & 0x3F);
}

uns8 MOD1005Class::getDayOfWeek() {
	uns8 day = readRegister(mod1005_dow_reg);
	return bcdToDec(day & 0x07);
}

uns8 MOD1005Class::getDate() {
	uns8 date = readRegister(mod1005_date_reg);
	return bcdToDec(date & 0x3F);
}

uns8 MOD1005Class::getMonth() {
	uns8 month = readRegister(mod1005_month_reg);
	return bcdToDec(month & 0x1F);
}

uns8 MOD1005Class::getYear() {
	uns8 year = readRegister(mod1005_year_reg);
	return bcdToDec(year);
}

void MOD1005Class::setSeconds(uns8 secs) {
	Wire.beginTransmission(mod1005_addr);
	Wire.write(mod1005_seconds_reg);  
	Wire.write(decToBCD(secs));
	Wire.endTransmission();
}

void MOD1005Class::setMinutes(uns8 mins) {
	Wire.beginTransmission(mod1005_addr);
	Wire.write(mod1005_minutes_reg);  
	Wire.write(decToBCD(mins));
	Wire.endTransmission();
}

void MOD1005Class::setHours(uns8 hrs) {
	Wire.beginTransmission(mod1005_addr);
	Wire.write(mod1005_hours_reg); 
	Wire.write(decToBCD(hrs));
	Wire.endTransmission();
}

void MOD1005Class::setDayOfWeek(uns8 dow) {
	Wire.beginTransmission(mod1005_addr);
	Wire.write(mod1005_dow_reg);  
	Wire.write(decToBCD(dow));
	Wire.endTransmission();
}

void MOD1005Class::setDate(uns8 date) {
	Wire.beginTransmission(mod1005_addr);
	Wire.write(mod1005_date_reg);  
	Wire.write(decToBCD(date));
	Wire.endTransmission();
}

void MOD1005Class::setMonth(uns8 month) {
	Wire.beginTransmission(mod1005_addr);
	Wire.write(mod1005_month_reg);  
	Wire.write(decToBCD(month) & 0x1F);
	Wire.endTransmission();
}

void MOD1005Class::setYear(uns8 year) {
	Wire.beginTransmission(mod1005_addr);
	Wire.write(mod1005_year_reg);  
	Wire.write(decToBCD(year));
	Wire.endTransmission();
}

MOD1005Class mod1005;