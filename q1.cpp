#include <iostream>
#include <iomanip>

using namespace std;

class GasPump {
	private:
		double amountDispensed,
		       amountCharged,
		       costPerGallon;

	public:
		double getAmountDispensed() { return amountDispensed; }
		double getAmountCharged() { return amountCharged; }
		double getCostPerGallon() { return costPerGallon; }
		void setCostPerGallon(double cpg) { costPerGallon = cpg; }
        
		void dispense(int seconds) {


			
			amountCharged = amountDispensed * costPerGallon;
		}
		void reset() {
            
			amountDispensed = 0.0;
			amountCharged = 0.0;
		}		
};
	
int main() {
	
    //Define variables

    // Define Class Object

    // Call Functions
	

	return 0;
}
