#include "Arduino.h"
#include "NTCReader.h"

NTCReader::NTCReader(int _pin, double _K) {
	pin=_pin;
	K=_K;
}

double NTCReader::read() {
	double adc_raw=analogRead(pin);
	delay(10);
	adc_raw+=analogRead(pin);
	delay(10);
	adc_raw=(analogRead(pin)+adc_raw)/3;
	double V=adc_raw/1024*V_IN;
	double R_th=(R1*V)/(V_IN-V);
	double kelvin=SteinhartHart(R_th)-V*V/(K*R_th);
	double celsius=kelvin-273.15;
	if(celsius>tmax) {
		tmax=celsius;
	}
	if(celsius<tmin) {
		tmin=celsius;
	}
	return celsius;
}

double NTCReader::getMin() {
	return tmin;
}

double NTCReader::getMax() {
	return tmax;
}

void NTCReader::setR(double r) {
	R1=r;
}

void NTCReader::setV(double v) {
	V_IN=v;
}
