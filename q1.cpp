#include <iostream>
#include <iomanip>

using namespace std;

class GasPump {
	private:
		double amountDispensed,
		       amountCharged,
			   rate,
		       costPerGallon;
		

	public:
		double getAmountDispensed() { return amountDispensed; }
		double getAmountCharged() { return amountCharged; }
		double getCostPerGallon() { return costPerGallon; }
		void setCostPerGallon(double cpg) { costPerGallon = cpg; }
        
		void dispense(int seconds) {
			
			rate = 0.1;
			amountDispensed = rate * seconds;
			
			amountCharged = amountDispensed * costPerGallon;
		}
		void reset() {
            
			amountDispensed = 0.0;
			amountCharged = 0.0;
		}		
};
	
int main() {
	
    //Define variables
	int sec = -1, pumpAgain = 1;
	double costPerGallon = 0, amountCharged, amountDispensed;

    // Define Class Object
	GasPump pump1;

    // Call Functions
	do{
		do{
			cout << "How long do you want to pump gas (in seconds)? ";
			cin >> sec;
		}while(sec <= 0);

		do{
			cout << "Insert the price of gas per gallon:";
			cin >> costPerGallon;
		} while (costPerGallon <= 0);

		pump1.setCostPerGallon(costPerGallon);
		pump1.dispense(sec);
		cout << "Amount Dispensed: " << pump1.getAmountDispensed() << " gallons" << endl;
		cout << "Amount Charged: $" << pump1.getAmountCharged() << endl;
		cout << "Cost Per Gallon: $" << pump1.getCostPerGallon() << " per gallon" << endl;
		
		pump1.reset();

		cout << "Would you like to pump gas again? Enter 1 for yes and 0 for no:";
		cin >> pumpAgain;
	} while(pumpAgain == 1);
		
	return 0;
}
