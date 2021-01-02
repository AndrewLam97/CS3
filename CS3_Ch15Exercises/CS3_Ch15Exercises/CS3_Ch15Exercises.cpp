#include <iostream>
using namespace std;

//9
void PartFilledArray::addValue(double newEntry){
	if (numberUsed == maxNumber){
		cout << "Adding to a full array.\n";
		exit(1);
	}
	else{
		a[numberUsed] = newEntry;
		numberUsed++;
	}
}
PartFilledArray::PartFilledArray
(const PartFilledArray& object) : maxNumber(object.maxNumber), numberUsed(object.numberUsed){
	a = new double[maxNumber];
	for (int i = 0; i < numberUsed; i++)
		a[i] = object.a[i];
}
void PartFilledArray::operator =
(const PartFilledArray& rightSide){
	if (rightSide.maxNumber > maxNumber){
		delete[] a;
		maxNumber = rightSide.maxNumber;
		a = new double[maxNumber];
	}
	numberUsed = rightSide.numberUsed;
	for (int i = 0; i < numberUsed; i++) {
		a[i] = rightSide.a[i];
	}
}
PartFilledArray::~PartFilledArray(){
	delete[] a;
}

//10
class PartFilledArrayWMax : public PartFilledArray{
	public:
		PartFilledArrayWMax(int arraySize);
		PartFilledArrayWMax(const PartFilledArrayWMax& object);
		~PartFilledArrayWMax();
		void operator= (const PartFilledArrayWMax& rightSide);
		void addValue(double newEntry);
		double getMax();
	private:
		double maxValue;
};
PartFilledArrayWMax::PartFilledArrayWMax(int arraySize) : PartFilledArray(arraySize){}

PartFilledArrayWMax::PartFilledArrayWMax(const PartFilledArrayWMax& object) : PartFilledArray(object){
	if (object.numberUsed > 0){
		maxValue = a[0];
		for (int i = 1; i < numberUsed; i++)
			if (a[i] > maxValue)
				maxValue = a[i];
	}
}

PartFilledArrayWMax::~PartFilledArrayWMax(){}

void PartFilledArrayWMax::operator =(const PartFilledArrayWMax& rightSide){
	PartFilledArray::operator =(rightSide);
	maxValue = rightSide.maxValue;
}

void PartFilledArrayWMax::addValue(double newEntry){
	if (numberUsed == maxNumber)
	{
		cout << "Adding to a full array.\n";
		exit(1);
	}
	if ((numberUsed == 0) || (newEntry > maxValue))
		maxValue = newEntry;
	a[numberUsed] = newEntry;
	numberUsed++;
}
double PartFilledArrayWMax::getMax(){
	return maxValue;
}

int main()
{

}

/*
	1. Yes, an object of a derived class can be used as a parameter for the base class
	2. class SmartBut : public Smart {
		  public:
			SmartBut();
			SmartBut(int newA, int newB, bool newCrazy);
			bool isCrazy( ) const;
		  private:
			bool crazy;
		};
	3. It is possible because they are protected in the base class
	4. The function declaration is not given in the derived class because it is unchanged from the base class
	5. #include <iostream>
	   #include "salariedemployee.h"
	   using namespace std;
	   namespace employeessavitch {
		   class TitledEmployee : public SalariedEmployee {
				public:
					TitledEmployee();
					TitledEmployee(string theName, string theTitle, string theSSN, double theSalary);
					string getTitle() const;
					void setTitle(string theTitle);
					void setName(string theName);
				private:
					string title;
			};
	   }//employeessavitch
	6. TitledEmployee::TitledEmployee(string theName, string theTitle, string theSSN, double theSalary)
		:SalariedEmployee(theName,theSSN,theSalary), title(theTitle) {}
	7. No, defaults will be used instead
	8. Constructors are called from parent to child and destructors are called in reverse
	9. *see above
	10. *see above
	11. Discounted item is not cheaper
	12. No member to assign
	13. Technically legal but you would lose any members not defined in the base class
	14. Virtual allows the initializing object type to determine which member function is called.
*/