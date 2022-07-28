#ifndef NTCReader_h
#define NTCReader_h

#include "Arduino.h"

class NTCReader {
	public:
		NTCReader(int _pin, double _K);
		double read();
		double getMin();
		double getMax();
		double R1=10000.0;
		double V_IN=5.0;
	private:
		int pin;
		double K;
		double tmin=1000;
                double tmax=0;
		double A=1.189148e-3;
		double B=2.34125e-4;
		double C=8.76741e-8;
		double SteinhartHart(double R) {
			double logR=log(R);
			double logR3=logR*logR*logR;
			return 1.0/(A+B*logR+C*logR3);
		};
};

#endif
