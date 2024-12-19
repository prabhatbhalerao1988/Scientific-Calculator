#include<iostream>
#include<cmath>
#include<limits>
#include<stdlib.h>
#include<string>
using namespace std;

class ScientificCalculator 
{
    public:
    
    ScientificCalculator() //constructor
	{	
        cout<<"Welcome to the Scientific Calculator!"<<endl;
    }

    ~ScientificCalculator() //destructor
	{
        cout<<"Cleaning up resources..." <<endl;
    }

    double add(double a,double b)
	 {
        return a+b;
     }

    double subtract(double a, double b) 
	{
        return a-b;
    }

    double multiply(double a, double b) 
	{
        return a*b;
    }

    double divide(double a, double b) 
	{
        if (b!=0) 
		{
            return a/b;
        }
		 else 
		 {
            cout<<"Error: Division by zero!"<<endl;
            return numeric_limits<double>::quiet_NaN(); // Return NaN
        }
    }

    // Scientific operations
    double sine(double angle) 
	{
        return sin(angle);
    }

    double cosine(double angle) 
	{
        return cos(angle);
    }

    double tangent(double angle) 
	{
        return tan(angle);
    }

    double logarithm(double value) 
	{
        if (value>0)
		 {
            return log(value);
        }
		 else 
		 {
            cout<<"Error: Logarithm of a non-positive number!"<<"\n";
            return numeric_limits<double>::quiet_NaN(); // Return NaN
        }
    }

    // Display the menu
    void displayMenu() 
	{
        cout<<"\nScientific Calculator\n";
        cout<<"1. Add\n";
        cout<<"2. Subtract\n";
        cout<<"3. Multiply\n";
        cout<<"4. Divide\n";
        cout<<"5. Sine\n";
        cout<<"6. Cosine\n";
        cout<<"7. Tangent\n";
        cout<<"8. Logarithm\n";
        cout<<"9. Exit\n";
        cout<<"Select an operation: ";
    }

    // AI-like feature: Error handling and suggestion for invalid inputs
    bool isValidInput(double&num) 
	{
        if(!(cin>>num)) 
		{
            cout<<"Invalid input! Please enter a valid number."<<endl;
            cin.clear();  // Clear error flag
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');  // Discard invalid input
            return false;
        }
        return true;
    }

    bool isValidChoice(int& choice) 
	{
        if (!(cin>>choice) ||choice<1||choice>9) 
		{
            cout << "Invalid choice! Please select a valid operation." <<endl;
            cin.clear();  // Clear error flag
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard invalid input
            return false;
        }
        return true;
    }
};

int main() 
{
    ScientificCalculator c;
    int choice;
    double num1,num2,result;

    while(1)
	 {
        c.displayMenu();

        if (!c.isValidChoice(choice)) 
		{
            continue;
        }

        switch (choice) 
		{
            case 1: // add
                cout<<"Enter two numbers: ";
                if (c.isValidInput(num1)&&c.isValidInput(num2))
				 {
                    result=c.add(num1, num2);
                    cout<<"Sum: "<<result<<"\n";
                }
                break;

            case 2: // subtract
                cout<<"Enter two numbers: ";
                if (c.isValidInput(num1)&&c.isValidInput(num2))
				 {
                    result=c.subtract(num1, num2);
                    cout<<"Sub: "<<result<<"\n";
                }
                break;

            case 3: // multiply
                cout<<"Enter two numbers: ";
                if (c.isValidInput(num1)&&c.isValidInput(num2)) 
				{
                    result = c.multiply(num1,num2);
                    cout<<"Product: "<<result<<endl;
                }
                break;

            case 4: // divide
                cout<<"Enter two numbers: ";
                if (c.isValidInput(num1) &&c.isValidInput(num2)) 
				{
                    result = c.divide(num1,num2);
                    if (!isnan(result)) 
					{
                        cout<<"Divide: "<<result<<endl;
                    }
                }
                break;

            case 5: // sine
                cout<<"Enter the angle in radians: ";
                if (c.isValidInput(num1)) 
				{
                    result = c.sine(num1);
                    cout<<"Result: "<<result<<endl;
                }
                break;

            case 6: // cosine
                cout<<"Enter the angle in radians: ";
                if (c.isValidInput(num1))
				 {
                    result = c.cosine(num1);
                    cout<<"Result: "<<result<<endl;
                }
                break;

            case 7: // tangent
                cout<<"Enter the angle in radians: ";
                if (c.isValidInput(num1))
				{
                    result = c.tangent(num1);
                    cout<<"Result: "<<result<<endl;
                }
                break;

            case 8: // logarithm
                cout<<"Enter a number: ";
                if (c.isValidInput(num1)) 
				{
                    result = c.logarithm(num1);
                    if (!isnan(result)) 
					{
                        cout<<"Result: "<<result<<"\n";
                    }
                }
                break;

            case 9: // exit
                cout<<"Exiting the calculator.\n";
                exit(0);
                return 0; 

            default:
            cout<<"Invalid option! Please try again.\n";
            break;
        }
    }

    return 0;
}

