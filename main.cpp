//This code is an implementation of a Car Rental System. It allows users to select a car based on various criteria such as car type, capacity, price range, and transmission type. The program then compares the user's filters with a predefined set of cars and displays the available options. After selecting a car, the user can input the rental duration in hours, and the program calculates the total price based on the hourly rate of the chosen car.

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

int index=0;
int code=0;
string visitorName,visitorEmail;

class Car {
private:
	string name[33];
	int hourlyRate[33];
	int type;
	int capacity;
	int trans;
	int passenger;
	int bag;
	int price_range;


public:

	/*this constructor initializes the member variables of the Car class with default values and interacts with the user to gather information such as their name and email. It also calls the applyFilters function to apply car selection filters based on the user's preferences.*/

	Car(): type(0), capacity(0), trans(0), passenger(0), bag(0), price_range(0) //Setting the initial
	{
		cout << "Instantly book cars near you.\nNeed a car? Oh, you have come to the right place. Book cars on demand by the hour or day." << endl;
		cout << "\nName: ";
		getline(cin, visitorName);
		cout << "\nEmail (To contact you): ";
		getline(cin, visitorEmail);
		cout << "\n\aWelcome Mr/Mrs " << visitorName;
	}

	void input_data()
	{
		ifstream inputFile("cars.txt");

		for (int i = 0; i < 33; ++i) {
			inputFile >> name[i] >> hourlyRate[i];
		}
		inputFile.close();
	}
	void hours_input(int *hAdd)
	{
		cout << "Enter the number of hours you will rent the car: ";
		cin >>*hAdd ;
	}
	int calculatePrice(int *hAdd) {
		int totalPrice = hourlyRate[index-1] * (*hAdd);
		return totalPrice;
	}

public:


	void selectCarType() {
		cout << endl;
		cout << "Car type (1-Economy 2-Van): ";
		cin >> type;
		if (type != 1 && type != 2) {
			cout << "Invalid car type. Please select again." << endl;
			selectCarType();
		}
	};

	void selectCapacity() {
		if (type == 1) {
			cout << "\nCapacity (Passengers: 1 to 4, Bags: 1 to 3)" << endl;
		}
		else /*if (type == 2) */{
			cout << "\nCapacity (Passengers: 1 to 6, Bags: 1 to 6)" << endl;
		}
		cout << "\t\t";
		cin >> passenger;
		cout << "\t\t\t\t ";
		cin >> bag;
		if ( ( (passenger<=4 && passenger>=1) && (bag<=3 && bag>=0) ) && type==1 )
			{
			    capacity=1;
            }
		else if ( ( (passenger <=6 && passenger>=1) && (bag<=6 && bag>=0) ) && type==2 )
			{
			    capacity=2;
            }
		else
			{
            cout << "Invalid capacity. Please select again." << endl;
            selectCapacity(); //Calling the function again to set an available capacity
            }
	};

	void selectPriceRange() {
		cout << "\nAverage Price is $28" << endl;
		cout << "Select price range (1- 12 to 22$ 2- 23 to 32$ 3- 33 to 42$): ";
		cin >> price_range;
		if (price_range != 1 && price_range != 2 && price_range != 3) {
			cout << "Invalid price range. Please select again." << endl;
			selectPriceRange(); //Calling the function again to set an available price range
		}
	};

	void selectTransmissionType() {
		cout << "\nTransmission Type (1-Automatic 2-Manual): ";
		cin >> trans;
		if (trans != 1 && trans != 2) {
			cout << "Invalid transmission type. Please select again." << endl;
			selectTransmissionType(); //Calling the function again to select an available transmission type
		}
	};

	void mergeCode() //to get the car_code
{
    int merged=0,arr[4]={type,capacity,price_range,trans};
    for (char i=0;i<4;i++)
        merged=(merged+arr[i])*10;
    code= merged/10;
    cout<<"Car_Code: "<<code<<endl;
}


	void applyFilters() {   //Calling the 4-filteration-functions
		cout << "\n\nFiltration\n\n";
		selectCarType();
		selectCapacity();
		selectPriceRange();
		selectTransmissionType();
		mergeCode();
	};
	void compare()
	{
		if (code == 1111)
		{
		    cout<<"Here are the types of cars for this category: \n";
			cout<<"\n 1-Ford Puma( $19/h & 0.44 l/km) \n 2-MG ZS( $14/h & 0.2 l/km) \n 3-Toyota Corolla( $18/h & 0.078 l/km) \n 4-Subaru Impreza ( $20/h & 0.066 L/km) \n 5-Hyundai Elantra GT( $19/h & 0.17l /km)\n Select the number of the car: ";
			cin>>index;
			if (index>5 || index<1)
                {
                    cout<<"Please select a number from the cars list: \n";
                    compare();
                }
		}
		else if (code == 2211)
		{
            cout<<"Here are the types of cars for this category: \n";
			cout<<"\n6-BMW 2211 Series Active Tourer ( $17/h & 0.013 l/km) \n 7-Toyota Coaster ( $16/h & 0.51 l/km) \n 8-Chrysler Pacifica ( $17/h & 0.935 l/km) \n 9-Volkswagen Transporter ( $19/h & 0.06 l/km)\n Select the number of the car: ";
			cin>>index;
			if (index>9 || index<6)
                {
                    cout<<"Please select a number from the cars list: \n";
                    compare();
                }
		}
		else if (code == 1211)
		{
		    cout<<"Here are the types of cars for this category: \n";
			cout<<"\n10-Nissan�Sunny ( $17/h & 0.22 l/km)\n ";
			cin>>index;
			if (index!=10)
                {
                    cout<<"Please select a number from the cars list: \n";
                    compare();
                }
		}
		else if (code == 1221)
		{
		    cout<<"Here are the types of cars for this category: \nSelect the number of the car: ";
			cout<<"\n11-Chevrolet Aveo�Sedan ( $24/h & 0.076 l/km) \n 12-Hyundai�Elantra ( $26/h & 0.17 l/km)\n 13-Peugeot�508 ( $27/h & 0.53 l/km) \n Select the number of the car: ";
			cin>>index;
			if (index>13 || index<11)
                {
                    cout<<"Please select a number from the cars list: \n";
                    compare();
                }
		}
		else if (code == 1121)
		{
		    cout<<"Here are the types of cars for this category: \n";
			cout<<"\n 14-Hyundai�i10 ( $24/h & 0.0.62 l/k)\n 15-Intermediate car ( $27/h & 0.46 l/k)\n 16-Nissan�Qashqai ( $30/h & 0.66 l/k)\n Select the number of the car:  ";
			cin>>index;
			if (index>16 || index<14)
                {
                    cout<<"Please select a number from the cars list: \n";
                    compare();
                }
		}
		else if (code == 1222)
		{
		    cout<<"Here are the types of cars for this category: \n";
			cout<<"\n17-Audi�A5 ( $27/h & 0.099 l/k)\nSelect the number of the car: ";
			cin>>index;
			if (index!=17)
                {
                    cout<<"Please select a number from the cars list: \n";
                    compare();
                }
		}
		else if (code == 2122)
		{
		    cout<<"Here are the types of cars for this category: \n";
			cout<<"\n18-Peugeot 5008 ( $26/h & 0.07 l/k) \n 19-Toyota Fortuner ( $21/h & 0.1427 l/k) \n 20-Fiat 500 ( $32/h & 0.084 l/k) \n 21-Renault Kwid ( $29/h & 0.22 l/k)\n Select the number of the car: ";
			cin>>index;
			if (index>21 || index<18)
                {
                    cout<<"Please select a number from the cars list: \n";
                    compare();
                }
		}
		else if (code == 2232)
		{
		    cout<<"Here are the types of cars for this category: \n";
			cout<<"\n22-Toyota Sienna ( $34/h &/h 0.065 l/k)\n 23-Mercedes-Benz Metris ( $37/h & 0.114 l/k)\n 24-Chrysler Pacifica Hybrid ( $39/h & 0.08 l/k)\n 25-Chrysler Voyager ( $40/h & 0.077 l/k)\n 26-Chrysler Pacifica Hybrid ( $38/h & 0.08 l/k)\n 27-Chrysler Pacifica ( $36/h & 0.084 l/k)\n 28-Mercedes-Benz Metris ( $38/h & 0.123 l/k)\n 29-Vauxhall Vivaro ( $41/h & 0.0789 l/k)\n 30-Citroen SpaceTourer ( $36 & 0.056 l/k)\n 31-Mercedes Vito Tourer ( $38/h & 0.062 l/k)\n 32-Renault Trafic Passenger ( $34/h & 0.102 l/k)\n 33-Nissan NV300 Combi ( $36/h & 0.072 l/k) \n Select the number of the car: ";
			cin>>index;
			if (index>33 || index<22)
                {
                    cout<<"Please select a number from the cars list: \n";
                    compare();
                }
		}

		else
		{
			cout<<"No match to your filters, please try again";
			index=0;
		}
	};
};


int main() {
	int hours=0;
	Car ob;
	while (!index){
		ob.applyFilters();
		ob.compare();
	}
	ob.input_data();
	ob.hours_input(&hours);
	cout<<"Total Price: "<<ob.calculatePrice(&hours);
	cout << "\nThank you Mr./Mrs."<<visitorName<< " for visiting our website and considering our car rental services\nWe hope you found the perfect car that suits your needs\nShould you have any further inquiries or require assistance, please don't hesitate to contact us\nWe look forward to serving you and providing a seamless car rental experience\n\nSafe travels!";
	return 0;
}
