#include <iostream>

using namespace std;

class Temperature {
	private:
		double degKelvin,
		       degFahrenheit,
		       degCelsius;
	public:
		void setTempKelvin(double degreesKelvin) {degKelvin = degreesKelvin;}
		double getTempKelvin() { return degKelvin; }
		void setTempCelsius() {degCelsius = degKelvin - 273.15; }
		double getTempCelsius() { return degCelsius; } 
		void setTempFahrenheit() {degFahrenheit = degCelsius*9/5.0 + 32;  }
		double getTempFahrenheit() { return degFahrenheit;}
};

int main() {
	double dK;
	
	Temperature temp1;

	cout << "Input a temperature in Kelvin:";
	cin >> dK;

	temp1.setTempKelvin(dK);
	temp1.setTempCelsius();
	temp1.setTempFahrenheit();

	cout << "Temperature in Kelvin: " << temp1.getTempKelvin() << " K" << endl;
	cout << "Temperature in Fahrenheit: " << temp1.getTempFahrenheit() << " degrees Fahrenheit" << endl;
	cout << "Temperature in Celsius: " << temp1.getTempCelsius() << " degrees Celsius" << endl;

	return 0;
}
