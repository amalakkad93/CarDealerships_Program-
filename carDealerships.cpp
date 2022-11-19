#include<iostream>
#include<cctype>
#include<string>
#include<iomanip>
#include<vector>
#include<fstream>
using namespace std;

class Automobile
{
private:
    string make;
    string model;
    int  year;
    int mileage;
    float price;
    string color;
    string classification;
public:
    Automobile();
    Automobile(string, string, int, int, float, string, string);
    string getMake() const;
    string getModel() const;
    int getYear()const;
    int getMileage() const;
    float getPrice() const;
    string getColor()const;
    string getClassification()const;

    virtual void setMake(string);
    virtual void setModel(string);
    virtual void setYear(int);
    virtual void setMileage(int);
    virtual void setPrice(float);
    virtual void setClassification(string);
    virtual void print();
    void setColor(string);

    friend ostream& operator<< (ostream& output, const vector<Automobile>& autolist);
    friend ostream& operator<<(ostream& output, const Automobile& automobileObject);
};

Automobile::Automobile()
{
    make = " ";  model = " ";  year = 0;  mileage = 0;  price = 0.000;  color = " ";  classification = " ";
}

Automobile::Automobile(string autoMake, string autoModel, int autoYear, int autoMileage, float autoPrice, string autoColor, string autoClassification)
{
    make = autoMake;
    model = autoModel;
    year = autoYear;
    mileage = autoMileage;
    price = autoPrice;
    color = autoColor;
    classification = autoClassification;
}

string Automobile::getMake() const
{
    return make;
}

string Automobile::getModel() const
{
    return model;
}

int Automobile::getYear()const
{
    return year;
}

int Automobile::getMileage() const
{
    return mileage;
}

float Automobile::getPrice() const
{
    return price;
}

string Automobile::getColor()const
{
    return color;
}

string Automobile::getClassification()const
{
    return classification;
}



void Automobile::setMake(string autoMake)
{
    make = autoMake;
}

void Automobile::setModel(string autoModel)
{
    model = autoModel;
}

void Automobile::setYear(int autoYear)
{
    year = autoYear;
}

void Automobile::setMileage(int autoMileage)
{
    mileage = autoMileage;
}

void Automobile::setPrice(float autoPrice)
{
    price = autoPrice;
}

void Automobile::setColor(string autoColor)
{
    color = autoColor;
}

void Automobile::setClassification(string autoClassification)
{
    classification = autoClassification;
}
ostream& operator<<(ostream& output, const vector<Automobile> autolist)
{
    for (int i = 0; i < autolist.size(); i++)
        output << autolist[i] << endl;
    output << "\n";
    return output;
}

ostream& operator<<(ostream& output, const Automobile& automobileObject)
{

    output << automobileObject.make << " ";
    output << automobileObject.model << " ";
    output << automobileObject.year << " ";
    output << automobileObject.mileage << " ";
    output << automobileObject.price << " ";
    output << automobileObject.color << " ";
    output << automobileObject.classification << " ";
    return output;
}

void Automobile::print()
{
    cout << left << fixed << showpoint << setprecision(2);

    cout << left << fixed << setw(15) << make << setw(25) << model << setw(25) << year <<
        setw(15) << mileage << setw(15) << price << setw(15) << color << setw(25) << classification;
}









class Car : public Automobile
{
private:
    int doors;

public:
    Car() :Automobile()
    {
        doors = 0;
    }
    Car(string, string, int, int, float, string, string, int);
    int getDoors() const;
    void setDoors(int);
    void print();

    friend ostream& operator<<(ostream& output, const Car& carObject);


};
Car::Car(string carMake, string carModel, int carYear, int carMileage, float carPrice, string carColor, string carClassification, int carDoors) :
    Automobile(carMake, carModel, carYear, carMileage, carPrice, carColor, carClassification)
{
    doors = carDoors;
}

int Car::getDoors() const
{
    return doors;
}

void Car::setDoors(int carDoors)
{
    doors = carDoors;
}

void Car::print()
{
    Automobile::print();
    cout << fixed << showpoint << left << "            " << setw(18) << doors << endl;
}

ostream& operator<<(ostream& output, const Car& automobileObject)
{
    output << automobileObject.doors;
    return output;
}



class Truck : public Automobile
{
private:
    string driveType;

public:
    Truck() : Automobile()
    {
        driveType = " ";
    }
    Truck(string, string, int, int, float, string, string, string);

    string getDriveType() const;
    void print();
    void setDriveType(string);
    friend ostream& operator<<(ostream& output, const Truck& automobileObject);
};
Truck::Truck(string truckMake, string truckModel, int truckYear, int truckMileage, float truckPrice, string truckColor, string truckClassification, string truckDriveType) :
    Automobile(truckMake, truckModel, truckYear, truckMileage, truckPrice, truckColor, truckClassification)
{
    driveType = truckDriveType;
}

string Truck::getDriveType() const
{
    return driveType;
}

void Truck::setDriveType(string truckDriveType)
{
    driveType = truckDriveType;
}

void Truck::print()
{
    Automobile::print();
    cout << showpoint << setprecision(2);
    cout << showpoint << fixed << left << setw(15) << driveType << "     None" << endl;
}

ostream& operator<<(ostream& output, const Truck& automobileObject)
{
    output << automobileObject.driveType;
    return output;
}

class SUV : public Automobile
{
private:
    int passengers;

public:
    SUV() : Automobile()
    {
        passengers = 0;
    }

    SUV(string, string, int, int, float, string, string, int);
    int getPassengers() const;

    void print();
    void setPassengers(int);
    friend ostream& operator<<(ostream& output, const SUV& automobileObject);
};
SUV::SUV(string suvMake, string suvModel, int suvYear, int suvMileage, float suvPrice, string suvColor, string suvClassification, int suvPassengers) :
    Automobile(suvMake, suvModel, suvYear, suvMileage, suvPrice, suvColor, suvClassification)
{
    passengers = suvPassengers;
}

int SUV::getPassengers() const
{
    return passengers;
}

void SUV::setPassengers(int suvPassengers)
{
    passengers = suvPassengers;
}

void SUV::print()
{
    Automobile::print();
    cout << showpoint << setprecision(2);
    cout << showpoint << fixed << left << setw(15) << passengers << "     None" << endl;
}

ostream& operator<<(ostream& output, const SUV& automobileObject)
{
    output << automobileObject.passengers;
    return output;
}


//void catalog123(vector<car*>&carlist2);


void convertString(string& st);


void CarCatalog123(vector<Automobile*>& carlist1, vector<Automobile*>& carlist2);
void SearchCarInventory(vector<Automobile*>& carlist3, vector<Automobile*>& carlist4);
void showCarWithinPrange(vector <Automobile*>& carlist5, vector<Automobile*>& carlist6);
void printCarDataIntoFile(vector<Automobile*>& carlist7, vector<Automobile*>& carlist8);
void readCarDataFromFile(vector<Automobile*>& carlist10, vector<Automobile*>& carlist11);


void TruckCatalog123(vector<Automobile*>& trucklist1, vector<Automobile*>& trucklist2);
void SearchTruckInventory(vector<Automobile*>& trucklist3, vector<Automobile*>& trucklist4);
void showTruckWithinPrange(vector<Automobile*>& trucklist5, vector<Automobile*>& trucklist6);
void printTruckDataIntoFile(vector<Automobile*>& trucklist7, vector<Automobile*>& trucklist8);
void readTruckDataFromFile(vector<Automobile*>& trucklist9, vector<Automobile*>& trucklist10);


void SUVCatalog123(vector<Automobile*>& suvlist1, vector<Automobile*>& suvlist2);
void SearchSUVInventory(vector<Automobile*>& suvlist3, vector<Automobile*>& suvlist4);
void showSUVWithinPrange(vector<Automobile*>& suvlist5, vector<Automobile*>& suvlist6);
void printSUVDataIntoFile(vector<Automobile*>& suvlist7, vector<Automobile*>& suvlist8);
void readSUVDataFromFile(vector<Automobile*>& suvlist9, vector<Automobile*>& suvlist10);



int main()
{

    //( suvMake, suvModel, suvYear, suvMileage, suvPrice, suvColor, suvClassification )

    cout << fixed << showpoint << setprecision(2);
    vector<Automobile*>carListNew;
    vector<Automobile*>carListUsed;

    Car* C_Toyota = new Car("TOYOTA", "COROLLA", 2019, 70000, 28000.00, "Black", "Used", 4);
    carListUsed.push_back(C_Toyota);

    Car* C_Toyota1 = new Car("TOYOTA", "CAMRY", 2014, 280000, 10000.00, "White", "Used", 4);
    carListUsed.push_back(C_Toyota1);

    Car* C_Honda = new Car("HONDA", "ACCORD", 2020, 0000, 21000.00, "Silver", "New", 2);
    carListNew.push_back(C_Honda);

    Car* C_Ford = new Car("FORD", "Focus ST", 2010, 60000, 7000.00, "Black", "Used", 4);
    carListUsed.push_back(C_Ford);

    Car* C_Nissan1 = new Car("NISSAN", "ALTIMA", 2011, 100000, 12000.00, "Dark Blue", "Used", 4);
    carListUsed.push_back(C_Nissan1);

    Car* C_Nissan = new Car("NISSAN", "GT-R", 2018, 5776, 94999.00, "Grey", "Used", 2);
    carListUsed.push_back(C_Nissan);

    Car* C_Audi = new Car("AUDI", "A5", 2019, 0000, 45000.00, "White", "New", 4);
    carListNew.push_back(C_Audi);

    Car* C_Audi2 = new Car("AUDI", "A4", 2017, 40000, 37000.00, "Yellow", "Used", 4);
    carListUsed.push_back(C_Audi2);

    Car* C_Charger = new Car("CHRYSLER", "CHARGER", 2013, 15000, 280000.00, "Black", "Used", 4);
    carListUsed.push_back(C_Charger);

    Car* C_BMW = new Car("BMW", "X5", 2019, 0000, 28000.00, "Silver", "New", 4);
    carListNew.push_back(C_BMW);

    cout << fixed << showpoint << setprecision(2);
    vector<Automobile*>truckListNew;
    vector<Automobile*>truckListUsed;


    Truck* T_Toyota = new Truck("TOYOTA", "Tundra", 2020, 0, 28000.00, "White", "New", " 4WD ");
    truckListNew.push_back(T_Toyota);

    Truck* T_GMC = new Truck("GMC", "Silverado", 2020, 0000, 10000.00, "Silver", "New", " 2WD ");
    truckListNew.push_back(T_GMC);

    Truck* T_Toyota1 = new Truck("TOYOTA", "Tacoma", 2020, 0000, 35000.00, "black", "New", " 2WD ");
    truckListNew.push_back(T_Toyota1);

    Truck* T_FORD = new Truck("FORD", "F-150", 2010, 200000, 15000.00, "black", "Used", " 4WD ");
    truckListUsed.push_back(T_FORD);

    Truck* T_Nissan = new Truck("NISSAN", "Titan", 2011, 100000, 12000.00, "Dark Blue", "Used", " 4WD ");
    truckListUsed.push_back(T_Nissan);

    Truck* T_Chevrolet = new Truck("Chevrolet", "Colorado", 2018, 50032, 21000.00, "black", "Used", " 4WD ");
    truckListUsed.push_back(T_Chevrolet);

    Truck* T_Dodge = new Truck("Dodge", "Ram-1500", 2017, 40000, 37000.00, "black", "Used", " 4WD ");
    truckListUsed.push_back(T_Dodge);

    Truck* T_GMC1 = new Truck("GMC", "Silverado", 2019, 0000, 280000.00, "Grey", "New", " 2WD ");
    truckListNew.push_back(T_GMC1);

    Truck* T_FORD1 = new Truck("FORD", "Ranger", 2020, 0000, 28000.00, "black", "New", " 2WD ");
    truckListNew.push_back(T_FORD1);

    Truck* T_FORD3 = new Truck("FORD", "Ranger", 2017, 50000, 28000.00, "Dark Grey", "Used", " 2WD ");
    truckListUsed.push_back(T_FORD3);


    cout << fixed << showpoint << setprecision(2);
    vector<Automobile*>suvListNew;
    vector<Automobile*>suvListUsed;

    SUV* S_Toyota = new SUV("TOYOTA", "Sequoia", 2019, 70000, 28000.00, "black", "Used", 7);
    suvListUsed.push_back(S_Toyota);

    SUV* S_Infiniti = new SUV("Infiniti", "QX80", 2020, 0000, 10000.00, "Silver", "New", 8);
    suvListNew.push_back(S_Infiniti);

    SUV* S_Honda = new SUV("HONDA", "Pilot", 2020, 5000, 35000.00, "black", "Used", 8);
    suvListUsed.push_back(S_Honda);

    SUV* S_Ford = new SUV("FORD", "Explorer", 2020, 0000, 7000.00, "Dark Blue", "New", 6);
    suvListNew.push_back(S_Ford);

    SUV* S_Lexus = new SUV("Lexus", "GX", 2011, 100000, 12000.00, "black", "Used", 8);
    suvListUsed.push_back(S_Lexus);

    SUV* S_MercedesBenz = new SUV("Mercedes Benz", "GLS", 2019, 0000, 94999.00, "Silver", "New", 7);
    suvListNew.push_back(S_MercedesBenz);

    SUV* S_Audi = new SUV("AUDI", "Q7", 2018, 50032, 45000.00, "black", "Used", 7);
    suvListUsed.push_back(S_Audi);

    SUV* S_Volkswagen = new SUV("Volkswagen", "A4", 2017, 40000, 37000.00, "black", "Used", 8);
    suvListUsed.push_back(S_Volkswagen);

    SUV* S_Cadillac = new SUV("Cadillac", "XT6", 2020, 0000, 280000.00, "White", "New", 7);
    suvListNew.push_back(S_Cadillac);

    SUV* S_BMW = new SUV("BMW", "X7", 2017, 50000, 28000.00, "black", "Used", 7);
    suvListUsed.push_back(S_BMW);


    int option1 = 0;

    do
    {
        cout << "===================================== MENU ==================================" << endl;
        cout << "*****************************************************************************" << endl;
        cout << left << "(1) For Cars" << endl;
        cout << left << "(2) For Trucks" << endl;
        cout << left << "(3) SUV" << endl;
        cout << left << "(4) Exit    " << endl;

        cout << "Please Choose The Menu Option You Want To Search: ";

        bool input1 = false;
        while (!input1)
        {
            input1 = true;
            cin >> option1;
            if (!cin) {

                cin.clear();
                cin.ignore(100, '\n');
                cout << "Please Choose Correct Menu Option." << endl;
                input1 = false;
            }
        }


        switch (option1)
        {

            //"============================================= MENU CAR ==============================================//
        case 1:
        {
            bool condition = true;
            while (condition)

            {

                cout << "===================================== CAR MENU ==================================" << endl;
                cout << "*****************************************************************************" << endl;

                cout << left << "(1) Display or Load Car Catalog" << endl;
                cout << left << "(2) Search Inventory    " << endl;
                cout << left << "(3) Search Car by Price Range" << endl;
                cout << left << "(4) Write Car Data into the File" << endl;
                cout << left << "(5) Read Car Data from the File" << endl;
                cout << left << "(6) Return to the main menu    " << endl;
                cout << "Please Choose The Menu Option You Want To Search: ";

                int option2 = 0;
                bool input2 = false;
                while (!input2)
                {
                    input2 = true;
                    cin >> option2;
                    if (!cin) {

                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Please Choose Correct Menu Option." << endl;
                        input2 = false;
                    }
                }
                // will print the cetelog
                if (option2 == 1)
                {
                    CarCatalog123(carListNew, carListUsed);
                }

                //Than provide a search option by make, model and category
                else if (option2 == 2)
                {
                    SearchCarInventory(carListNew, carListUsed);
                }

                // search by price range option
                else if (option2 == 3)
                {
                    showCarWithinPrange(carListNew, carListUsed);
                }

                // write Car  data into file option
                else if (option2 == 4)
                {
                    printCarDataIntoFile(carListNew, carListUsed);
                }

                //Read car data from file option
                else if (option2 == 5)

                {
                    readCarDataFromFile(carListNew, carListUsed);
                }

                // Exit from the menu option
                else if (option2 == 6)
                {
                    break;
                }//will break the loop

               // send the message if user choose wrong option
                else
                {
                    cout << "Please Choose Right Option!" << endl;
                }

            }

        }
        break;
        //*************************************End of CAR menu option******************************************//

        //******************************************************************************************************//

        //"============================================ MENU TRUCK =============================================//
        case 2:
        {
            bool condition1 = true;
            while (condition1)
            {

                cout << "===================================== TRUCK MENU  ==================================" << endl;
                cout << "*****************************************************************************" << endl;

                cout << left << "(1) Display or Load truck Catalog" << endl;
                cout << left << "(2) Search truck Inventory    " << endl;
                cout << left << "(3) Search Car by Price Range" << endl;
                cout << left << "(4) Write truck Data into the File" << endl;
                cout << left << "(5) Read truck Data from the File" << endl;
                cout << left << "(6) Return to the main menu     " << endl;
                cout << "Please Choose The Menu Option You Want To Search: ";

                int option3 = 0;
                bool input3 = false;
                while (!input3)
                {
                    input3 = true;
                    cin >> option3;
                    if (!cin) {

                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Please Choose Correct Menu Option." << endl;
                        input3 = false;
                    }
                }

                // will print the cetelog
                if (option3 == 1)
                {
                    TruckCatalog123(truckListNew, truckListUsed);
                }

                //Than provide a search option by make, model and category
                else if (option3 == 2)
                {
                    SearchTruckInventory(truckListNew, truckListUsed);
                }

                // search by price range option
                else if (option3 == 3)
                {
                    showTruckWithinPrange(truckListNew, truckListUsed);
                }

                // write Car  data into file option
                else if (option3 == 4)
                {
                    printTruckDataIntoFile(truckListNew, truckListUsed);
                }

                //Read car data from file option
                else if (option3 == 5)
                {
                    readTruckDataFromFile(truckListNew, truckListUsed);
                }

                // Exit from the menu option
                else if (option3 == 6)
                {
                    break;
                }

                // send the message if user choose wrong option
                else
                {
                    cout << "Please Choose Right Option!" << endl;
                }

            }
            break;

        }
        //*************************************End of TRUCK menu option******************************************//

        //******************************************************************************************************//

        //"============================================ MENU SUV =============================================//

        case 3:
        {
            bool condition2 = true;
            while (condition2)
            {

                cout << "===================================== SUV MENU ==================================" << endl;
                cout << "*****************************************************************************" << endl;

                cout << left << "(1) Display or Load SUV Catalog" << endl;
                cout << left << "(2) Search SUV Inventory    " << endl;
                cout << left << "(3) Search SUV by Price Range" << endl;
                cout << left << "(4) Write SUV Data into the File" << endl;
                cout << left << "(5) Read SUV Data from the File" << endl;
                cout << left << "(6) Return to the main menu   " << endl;
                cout << "Please Choose The Menu Option You Want To Search: ";

                int option4 = 0;
                bool input4 = false;
                while (!input4)
                {
                    input4 = true;
                    cin >> option4;
                    if (!cin) {

                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Please Choose Correct Menu Option." << endl;
                        input4 = false;
                    }
                }



                //will print the cetelog
                if (option4 == 1)
                {
                    SUVCatalog123(suvListNew, suvListUsed);
                }

                //Than provide a search option by make, model and category
                else if (option4 == 2)
                {
                    SearchSUVInventory(suvListNew, suvListUsed);
                }

                // search by price range option
                else if (option4 == 3)
                {
                    showSUVWithinPrange(suvListNew, suvListUsed);
                }

                // write Car  data into file option
                else if (option4 == 4)
                {
                    printSUVDataIntoFile(suvListNew, suvListUsed);
                }

                //Read car data from file option
                else if (option4 == 5)
                {
                    readSUVDataFromFile(suvListNew, suvListUsed);
                }

                // Exit from the menu option
                else if (option4 == 6)
                {
                    break;
                }
                // send the message if user choose wrong option
                else
                {
                    cout << "Please Choose Right Option!" << endl;
                }

            }

        }
        break;
        case 4:
            exit(1);
        default:
        {

            cout << "Thank you for visiting Alakkad Dealership\n" << " Have a nive day " << endl;
            break;
        }

        //*************************************End of CAR menu option******************************************//

        //******************************************************************************************************//

        //***************************************END OF THE ENTER MENU *********************************************//

        }// END OF SWITCH( option )

    } // END OF while( menuFor_Car_Truck_SUV )
    while (option1 != 4);


    system("PAUSE");
    return 0;
}
//***************************************END OF MAIN FUNCTION *********************************************//
//******************************************************************************************************//

//******************************************************************************************************//
//******************************************************************************************************//
//**************************************FUNCTIONS DEFINTION FOR CARS***********************************//
//******************************************************************************************************//
//******************************************************************************************************//

// **Function Defination that print out car catelog**
void CarCatalog123(vector<Automobile*>& carlist1, vector<Automobile*>& carlist2)
{
    cout << fixed << setprecision(2) << endl;
    cout << "****************************====Car Catelog====****************************\n\n";

    cout << setw(15) << "==Make==" << setw(15) << setw(15) << "==Model==" << setw(25) << "==Year==" << setw(15) << "==Mileage=="
        << setw(15) << "==Price==" << setw(15) << "==Color==" << setw(15) << "==Classification==" << setw(15) << "==Doors==\n" << endl;

    for (int i = 0; i < carlist1.size() || carlist2.size(); i++)
    {
        carlist1[i]->print();  carlist2[i]->print();
    }
}

// Function Defination that Search The specific Car from the Inventor
void SearchCarInventory(vector<Automobile*>& carlist3, vector<Automobile*>& carlist4)
{
    cout << "******************************************" << endl;
    cout << "(1)For Searching by Make of car enter 1" << endl;
    cout << "(2)For Searching by Model of car enter 2  " << endl;
    cout << "(3)For Searching by Classification car has enter 3 " << endl;
    cout << "*******************************************" << endl;

    bool pt = false;
    int input = 0;
    while (!pt)
    {
        pt = true;
        cin >> input;
        if (!cin) {

            cin.clear();
            cin.ignore(100, '\n');
            cout << "Please Choose correct option between 1 to 3: You entered ";
            pt = false;
        }
    }


    try
    {

        if (input == 1)
        {

            bool found = false;
            string carMake;
            cout << "Please Enter Car Make to search: ";
            cin >> carMake;
            convertString(carMake);

            for (int i = 0; i < carlist3.size() && carlist4.size(); i++)
            {

                if (carMake == carlist3[i]->getMake() && carMake == carlist4[i]->getMake()) {
                    cout << setw(15) << "==Make==" << setw(15) << setw(15) << "==Model==" << setw(25) << "==Year==" << setw(15) << "==Mileage=="
                        << setw(15) << "==Price==" << setw(15) << "==Color==" << setw(15) << "==Classification==" << setw(15) << "==Doors==\n" << endl;

                    carlist3[i]->print();
                    carlist4[i]->print();
                    found = true;
                }
            }

            if (found == false)
                cout << "Sorry! The Make you entered doesn't match with any Car in the Inventory." << endl;
        }



        else if (input == 2)
        {
            bool found = false;
            string car_MODEL;
            cout << "Enter Car Model to Search:";
            cin >> car_MODEL;
            convertString(car_MODEL);

            for (int i = 0; i < carlist3.size() && carlist4.size(); i++)
            {
                if (car_MODEL == carlist3[i]->getModel()) {
                    cout << setw(15) << "==Make==" << setw(15) << setw(15) << "==Model==" << setw(25) << "==Year==" << setw(15) << "==Mileage=="
                        << setw(15) << "==Price==" << setw(15) << "==Color==" << setw(15) << "==Classification==" << setw(15) << "==Doors==\n" << endl;

                    carlist3[i]->print();
                    carlist4[i]->print();
                    found = true;
                }
            }

            if (found == false)
                cout << "Sorry! The Model you entered doesn't match with any Car in the Inventory." << endl;
        }


        else if (input == 3)
        {
            bool found = true;
            string car_Classification;
            cout << "Enter Car Category to search either NEW or USED:";
            cin >> car_Classification;
            convertString(car_Classification);

            if (car_Classification != "NEW" && car_Classification != "USED")
                throw 99;

            cout << setw(15) << "==Make==" << setw(15) << setw(15) << "==Model==" << setw(25) << "==Year==" << setw(15) << "==Mileage=="
                << setw(15) << "==Price==" << setw(15) << "==Color==" << setw(15) << "==Classification==" << setw(15) << "==Doors==\n" << endl;

            for (int i = 0; i < carlist3.size() && i < carlist4.size(); i++)
            {
                if (car_Classification == carlist3[i]->getClassification()) {
                    carlist3[i]->print();
                }
                else
                {
                    carlist4[i]->print();
                }
            }
            found = true;

            if (found == false)
                cout << "Sorry! The Classification you entered doesn't match with any Car in the Inventory." << endl;
        }


        else

        {
            cout << "The Search Option you Entered is not Correct." << endl;
        }
    }//END OF try block


    catch (int t)
    {
        cout << "Exception found: Category must be NEW or USED" << endl;
    }

}
//*****************END OF Function Defination that Search The specific Car from the Inventor***************************//


// **Function Defination that SHOW CAR WITHIN THE RANDGE**
void showCarWithinPrange(vector <Automobile*>& carlist5, vector<Automobile*>& carlist6)
{
    bool carPrice = false;
    float  highestPrice;
    float lowestPrice;
    cout << "Please Enter the Car Price Range." << endl;

    cout << "Please Enter lowest price:";
    cin >> lowestPrice;

    cout << "Please Enter highest price:";
    cin >> highestPrice;
    cout << endl;
    cout << left << fixed << setprecision(2);

    cout << "==*****************************Car Catelog*****************************==" << endl << endl;

    cout << setw(15) << "==Make==" << setw(15) << setw(15) << "==Model==" << setw(25) << "==Year==" << setw(15) << "==Mileage=="
        << setw(15) << "==Price==" << setw(15) << "==Color==" << setw(15) << "==Classification==" << setw(15) << "==Doors==\n" << endl;

    for (int i = 0; i < carlist5.size() && i < carlist6.size(); i++)
    {
        if (carlist5[i]->getPrice() && carlist6[i]->getPrice() >= lowestPrice && carlist5[i]->getPrice() && carlist6[i]->getPrice() <= highestPrice)
        {
            carlist5[i]->print();
            carlist6[i]->print();
            carPrice = true;
        }

    }

    if (carPrice == false)
    {
        cout << "Sorry! No car found within this price range." << endl;
    }
}
//*****************END OF Function Defination that that SHOW CAR WITHIN THE RANDGE***************************//

    //Function Definationm write the Car data into the file Automobile
void printCarDataIntoFile(vector<Automobile*>& carlist7, vector<Automobile*>& carlist8)
{
    ofstream outData;
    outData.open("Car.txt");
    cout << endl << "Sending Data Into File...........  " << endl;
    for (int i = 0; i < carlist7.size() && i < carlist8.size(); i++)
    {

        outData << carlist7[i]->getMake() << " ";
        outData << carlist7[i]->getModel() << " ";
        outData << carlist7[i]->getColor() << " ";
        outData << carlist7[i]->getYear() << " ";
        outData << carlist7[i]->getPrice() << " " << endl;

        outData << carlist8[i]->getMake() << " ";
        outData << carlist8[i]->getModel() << " ";
        outData << carlist8[i]->getColor() << " ";
        outData << carlist8[i]->getYear() << " ";
        outData << carlist8[i]->getPrice() << " " << endl;

    }
    outData.close();
    cout << "........got it! Data Successfully sent to the file" << endl << endl;
}
//*****************END OF Function Definationm write the Car data into the file Automobile***************************//

    //Function Defination that read data from the file
void readCarDataFromFile(vector<Automobile*>& carlist10, vector<Automobile*>& carlist11)
{
    string  car_make, car_model; int car_year; double car_price; string car_Classification;
    ifstream inData;
    inData.open("Car.txt");
    if (!inData)
    {
        cout << "Failed to open file" << endl;
    }
    else if (inData)
    {
        int count = 0;
        cout << "Printing Car Data From the file" << endl << endl;
        while (!inData.eof())
        {
            count++;

            inData >> car_make;
            cout << "Car Make:";
            cout << car_make << endl;

            inData >> car_model;
            cout << "Car Model:";
            cout << car_model << endl;

            inData >> car_year;
            cout << "Car Year:";
            cout << car_year << endl;

            inData >> car_price;
            cout << "Car Price:";
            cout << car_price << endl;

            inData >> car_Classification;
            cout << "Car Classification:";
            cout << car_Classification << endl << endl;
        }
    }
    cout << endl << endl;
}
//*****************END OF Function Defination that read data from the file***************************//


//******************************************************************************************************//
//**************************************END OF FUNCTIONS DEFINTION FOR CARS***********************************//
//******************************************************************************************************//



//******************************************************************************************************//
//******************************************************************************************************//
//**************************************FUNCTIONS DEFINTION FOR TRUCKS***********************************//
//******************************************************************************************************//
//******************************************************************************************************//

    // **Function Defination that print out TRUCK catelog**
void TruckCatalog123(vector<Automobile*>& trucklist1, vector<Automobile*>& trucklist2)
{
    cout << fixed << setprecision(2) << endl;
    cout << "==**Truck Catelog**==" << endl << endl;
    cout << setw(15) << "==Make==" << setw(15) << setw(15) << "==Model==" << setw(25) << "==Year==" << setw(15) << "==Mileage=="
        << setw(15) << "==Price==" << setw(15) << "==Color==" << setw(15) << "==Classification==" << setw(15) << "==Drive type==\n" << endl;
    for (int i = 0; i < trucklist1.size() && trucklist2.size(); i++)
    {
        trucklist1[i]->print();  trucklist2[i]->print();
    }
}
//************************************END OF Function Defination that print out TRUCK catelog************************************//

    // Function Defination that Search The specific TRUCK from the Inventor
void SearchTruckInventory(vector<Automobile*>& trucklist3, vector<Automobile*>& trucklist4)
{
    cout << "******************************************" << endl;
    cout << "(1)For Searching by Make of truck enter 1" << endl;
    cout << "(2)For Searching by MODEL of truck enter 2  " << endl;
    cout << "(3)For Searching by Classification of truck enter 3 " << endl;
    cout << "(4)For Searching by drive type of truck enter 4 " << endl;
    cout << "*******************************************" << endl;
    bool pt = false;
    int input = 0;
    while (!pt)
    {
        pt = true;
        cin >> input;
        if (!cin)
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Please Choose correct option between 1 to 3: You entered ";
            pt = false;
        }
    }

    try {

        if (input == 1)
        {
            bool found = false;
            string truck_Make;
            cout << "Please Enter truck Make to search: ";
            cin >> truck_Make;
            convertString(truck_Make);
            for (int i = 0; i < trucklist3.size() && i < trucklist4.size(); i++)
            {
                if (truck_Make == trucklist3[i]->getMake() && truck_Make == trucklist4[i]->getMake())
                {

                    trucklist3[i]->print();
                    trucklist4[i]->print();
                    found = true;
                }
            }
            if (found == false)
                cout << "Sorry! The Make you entered doesn't match with any Car in the Inventory." << endl;
        }
        else if (input == 2)
        {
            bool found = false;
            string truck_MODEL;
            cout << "Enter truck Model to Search:";
            cin >> truck_MODEL;
            convertString(truck_MODEL);
            for (int i = 0; i < trucklist3.size() && i < trucklist4.size(); i++)
            {
                if (truck_MODEL == trucklist3[i]->getModel() && truck_MODEL == trucklist4[i]->getModel())
                {
                    cout << setw(15) << "==Make==" << setw(15) << setw(15) << "==Model==" << setw(25) << "==Year==" << setw(15) << "==Mileage=="
                        << setw(15) << "==Price==" << setw(15) << "==Color==" << setw(15) << "==Classification==" << setw(15) << "==Drive type==\n" << endl;

                    trucklist3[i]->print();
                    trucklist4[i]->print();
                    found = true;
                }
            }
            if (found == false)
                cout << setw(15) << "==Make==" << setw(15) << setw(15) << "==Model==" << setw(25) << "==Year==" << setw(15) << "==Mileage=="
                << setw(15) << "==Price==" << setw(15) << "==Color==" << setw(15) << "==Classification==" << setw(15) << "==Drive type==\n" << endl;
        }
        else if (input == 3)
        {
            bool found = true;
            string truck_Category;
            cout << "Enter truck Category to search either NEW or OLD:";
            cin >> truck_Category;
            convertString(truck_Category);
            if (truck_Category != "NEW" && truck_Category != "OLD")
                throw 99;

            cout << setw(15) << "==Make==" << setw(15) << setw(15) << "==Model==" << setw(25) << "==Year==" << setw(15) << "==Mileage=="
                << setw(15) << "==Price==" << setw(15) << "==Color==" << setw(15) << "==Classification==" << setw(15) << "==Drive type==\n" << endl;

            for (int i = 0; i < trucklist3.size(); i++)
            {
                if (truck_Category == trucklist3[i]->getClassification())
                {
                    trucklist3[i]->print();
                }
                else
                {
                    trucklist4[i]->print();;
                }

            }
            found = true;


            if (found == false)
                cout << "Sorry! The Category you entered doesn't match with any truck in the Inventory." << endl;
        }
        else
        {
            cout << "The Search Option you Entered is not Correct." << endl;
        }
    }
    catch (int t)
    {
        cout << "Exception found: Category must be NEW or OLD" << endl;
    }
}
//************************************END OF Function Defination that print out TRUCK catelog************************************//



// **Function Defination that SHOW TRUCK WITHIN THE RANDGE**
void showTruckWithinPrange(vector<Automobile*>& trucklist5, vector<Automobile*>& trucklist6)
{
    bool truckPrice = false;
    float  highestPrice1;
    float lowestPrice1;
    cout << "Please Enter the truck Price Range." << endl;

    cout << "Please Enter lowest price:";
    cin >> lowestPrice1;

    cout << "Please Enter highest price:";
    cin >> highestPrice1;

    cout << endl;
    cout << left << fixed << setprecision(2);
    cout << "==*Truck Catelog*==" << endl << endl;

    cout << setw(15) << "==Make==" << setw(15) << setw(15) << "==Model==" << setw(25)
        << "==Year==" << setw(15) << "==Mileage=="
        << setw(15) << "==Price==" << setw(15) << "==Color==" << setw(15) << "==Classification==" << setw(15) << setw(15) << "==Drive type==\n" << endl;
    for (int i = 0; i < trucklist5.size() && i < trucklist6.size(); i++)
    {
        if (trucklist5[i]->getPrice() && trucklist6[i]->getPrice() >= lowestPrice1 && trucklist5[i]->getPrice() && trucklist6[i]->getPrice() <= highestPrice1)
        {
            trucklist5[i]->print();
            trucklist6[i]->print();
            truckPrice = true;
        }

    }

    if (truckPrice == false)
    {
        cout << "Sorry! No truck found within this price range." << endl;
    }
}
//************************************END OF Function Defination that  SHOW TRUCK WITHIN THE RANDGE*************************************//

//Function Definationm write the TRUCK data into the file Automobile
void printTruckDataIntoFile(vector<Automobile*>& trucklist7, vector<Automobile*>& trucklist8)
{
    ofstream outData;
    outData.open("Truck.txt");
    cout << endl << "Sending Data Into File...........  " << endl;
    for (int i = 0; i < trucklist7.size(); i++)
    {

        outData << trucklist7[i]->getMake() << " ";
        outData << trucklist7[i]->getModel() << " ";
        outData << trucklist7[i]->getClassification() << " ";
        outData << trucklist7[i]->getYear() << " ";
        outData << trucklist7[i]->getColor() << " ";
        outData << trucklist7[i]->getPrice() << " " << endl;

        outData << trucklist8[i]->getMake() << " ";
        outData << trucklist8[i]->getModel() << " ";
        outData << trucklist8[i]->getClassification() << " ";
        outData << trucklist8[i]->getYear() << " ";
        outData << trucklist8[i]->getColor() << " ";
        outData << trucklist8[i]->getPrice() << " " << endl;
    }
    outData.close();
    cout << "........got it! Data Successfully sent to the file" << endl << endl;
}
//************************************END OF Function Defination that write the TRUCK data into the file Automobile*************************************//

//Function Defination that read TRUCK data from the file
void readTruckDataFromFile(vector<Automobile*>& trucklist9, vector<Automobile*>& trucklist10)
{
    string  tMake;
    string tModel;
    int tYear;
    double tPrice;
    string tCategory;

    ifstream inData;
    inData.open("Truck.txt");
    if (!inData)
    {
        cout << "Failed to open file" << endl;
    }
    else if (inData)
    {
        int count = 0;
        cout << "Printing Truck Data From the file" << endl << endl;
        while (!inData.eof())
        {
            count++;

            inData >> tMake;
            cout << "Truck Make:";
            cout << tMake << endl;

            inData >> tModel;
            cout << "Truck Model:";
            cout << tModel << endl;

            inData >> tYear;
            cout << "Truck Year:";
            cout << tYear << endl;

            inData >> tPrice;
            cout << "Truck Price:";
            cout << tPrice << endl;

            inData >> tCategory;
            cout << "Truck Category:";
            cout << tCategory << endl << endl;
        }
    }
    cout << endl << endl;
}
//************************************END OF Function Defination that read TRUCK data from the file*************************************//

//******************************************************************************************************//
//**************************************END OF FUNCTIONS DEFINTION FOR TRUCKS***********************************//
//******************************************************************************************************//
/*

 void SearchSUVInventory(vector<Automobile*>&suvlist3, vector<Automobile*>&suvlist4);
 void showSUVWithinPrange(vector<Automobile*>&suvlist5, vector<Automobile*>&suvlist6);
 void printSUVDataIntoFile(vector<Automobile*> &suvlist7, vector<Automobile*>&suvlist8);
 void readSUVDataFromFile(vector<Automobile*> &suvlist9, vector<Automobile*>&suvlist10);
 */


 //******************************************************************************************************//
 //******************************************************************************************************//
 //**************************************FUNCTIONS DEFINTION FOR SUV***********************************//
 //******************************************************************************************************//
 //******************************************************************************************************//

 // **Function Defination that print out SUV catelog**
void SUVCatalog123(vector<Automobile*>& suvlist1, vector<Automobile*>& suvlist2)
{
    cout << fixed << setprecision(2) << endl;
    cout << "====SUV Catelog====" << endl << endl;
    cout << setw(15) << "==Make==" << setw(15) << setw(15) << "==Model==" << setw(25) << "==Year==" << setw(15) << "==Mileage=="
        << setw(15) << "==Price==" << setw(15) << "==Color==" << setw(15) << "==Classification==" << setw(15) << "==passengers==\n"
        << endl;

    for (int i = 0; i < suvlist1.size() && i < suvlist2.size(); i++)
    {
        suvlist1[i]->print();
        suvlist2[i]->print();
    }
}
//**************************************END OF Function Defination that print out SUV catelog*************************************

// **Function Defination that Search SUV Inventory**
void SearchSUVInventory(vector<Automobile*>& suvlist3, vector<Automobile*>& suvlist4)
{
    cout << "******************************************" << endl;
    cout << "(1)For Searching by Make of SUV enter 1" << endl;
    cout << "(2)For Searching by MODEL of SUV enter 2  " << endl;
    cout << "(3)For Searching by Classification of SUV enter 3 " << endl;
    cout << "*******************************************" << endl;
    bool pt = false;
    int input2 = 0;
    while (!pt)
    {
        pt = true;
        cin >> input2;
        if (!cin)
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Please Choose correct option between 1 to 3: You entered ";
            pt = false;
        }
    }

    try {         //try block

        if (input2 == 1)
        {
            bool found = false;
            string suv_Make;
            cout << "Please Enter Car Make to search: ";
            cin >> suv_Make;
            convertString(suv_Make);
            for (int i = 0; i < suvlist3.size() && i < suvlist4.size(); i++)
            {
                if (suv_Make == suvlist3[i]->getMake() && suv_Make == suvlist4[i]->getMake())
                {
                    cout << setw(15) << "==Make==" << setw(15) << setw(15) << "==Model==" << setw(25) << "==Year==" << setw(15) << "==Mileage=="
                        << setw(15) << "==Price==" << setw(15) << "==Color==" << setw(15) << "==Classification==" << setw(15) << "==passengers==\n"
                        << endl;
                    //"FORD", "Explorer", 2020, 0, 7000.00,  "Dark Blue", "New"
                    suvlist3[i]->print();
                    suvlist4[i]->print();
                    found = true;
                }
            }
            if (found == false)
                cout << "Sorry! The Make you entered doesn't match with any Car in the Inventory." << endl;
        }
        else if (input2 == 2)
        {
            bool found = false;
            string suv_MODEL;
            cout << "Enter Car Model to Search:";
            cin >> suv_MODEL;
            convertString(suv_MODEL);
            for (int i = 0; i < suvlist3.size() && i < suvlist4.size(); i++)
            {
                if (suv_MODEL == suvlist3[i]->getModel() && suv_MODEL == suvlist4[i]->getModel())
                {
                    cout << setw(15) << "==Make==" << setw(15) << setw(15) << "==Model==" << setw(25) << "==Year==" << setw(15) << "==Mileage=="
                        << setw(15) << "==Price==" << setw(15) << "==Color==" << setw(15) << "==Classification==" << setw(15) << "==passengers==\n"
                        << endl;
                    suvlist3[i]->print();
                    suvlist4[i]->print();
                    found = true;
                }
            }
            if (found == false)
                cout << "Sorry! The Model you entered doesn't match with any Car in the Inventory." << endl;
        }
        else if (input2 == 3)
        {
            bool found = true;
            string suv_Category;
            cout << "Enter Car Category to search either NEW or OLD:";
            cin >> suv_Category;
            convertString(suv_Category);
            if (suv_Category != "NEW" && suv_Category != "OLD")
                throw 99;

            cout << setw(15) << "==Make==" << setw(15) << setw(15) << "==Model==" << setw(25) << "==Year==" << setw(15) << "==Mileage=="
                << setw(15) << "==Price==" << setw(15) << "==Color==" << setw(15) << "==Classification==" << setw(15) << "==passengers==\n"
                << endl;
            for (int i = 0; i < suvlist3.size() && i < suvlist4.size(); i++)
            {
                if (suv_Category == suvlist3[i]->getClassification())
                {
                    suvlist3[i]->print();
                }
                else
                {
                    suvlist4[i]->print();
                }
                found = true;

            }

            if (found == false)
                cout << "Sorry! The Category you entered doesn't match with any Car in the Inventory." << endl;
        }
        else
        {
            cout << "The Search Option you Entered is not Correct." << endl;
        }
    }
    catch (int t)
    {
        cout << "Exception found: Category must be NEW or OLD" << endl;
    }
}


//**************************************END OF Function Defination that Search SUV Inventory***************************************//
//"FORD", "Explorer", 2020, 0, 7000.00,  "Dark Blue", "New"
//Function Defination that SHOW SUV WITH IN THE RANGE
void showSUVWithinPrange(vector<Automobile*>& suvlist5, vector<Automobile*>& suvlist6)
{
    bool suv_Price = false;
    float highestPrice3;
    float lowestPrice3;
    cout << "Please Enter the Car Price Range." << endl;
    cout << "Please Enter lower price:";
    cin >> lowestPrice3;
    cout << "Please Enter the upper price:";
    cin >> highestPrice3;
    cout << endl;
    cout << left << fixed << setprecision(2);
    cout << "                                  ==*SUV Catelog*==" << endl << endl;
    cout << setw(15) << "==Make==" << setw(15) << setw(15) << "==Model==" << setw(25) << "==Year==" << setw(15) << "==Mileage=="
        << setw(15) << "==Price==" << setw(15) << "==Color==" << setw(15) << "==Classification==" << setw(15) << "==passengers==\n"
        << endl;
    for (int i = 0; i < suvlist6.size(); i++)
    {
        if (suvlist6[i]->getPrice() >= lowestPrice3 && suvlist6[i]->getPrice() <= highestPrice3)
        {
            suvlist6[i]->print();
            suv_Price = true;
        }

    }

    if (suv_Price == false)
    {
        cout << "Sorry! No car found within this price range." << endl;
    }
}
//************************************** END OF Function Defination that SHOW SUV WITH IN THE RANGE ***************************************//


    //Function Definationm write the Car data into the file Automobile
void printSUVDataIntoFile(vector<Automobile*>& suvlist7, vector<Automobile*>& suvlist8)
{
    ofstream outData;
    outData.open("SUV.txt");
    cout << endl << "Sending Data Into File...........  " << endl;
    for (int i = 0; i < suvlist7.size() && i < suvlist8.size(); i++)
    {

        outData << suvlist7[i]->getMake() << " ";
        outData << suvlist7[i]->getModel() << " ";
        outData << suvlist7[i]->getClassification() << " ";
        outData << suvlist7[i]->getYear() << " ";
        outData << suvlist7[i]->getColor() << " ";
        outData << suvlist7[i]->getPrice() << " " << endl;
        outData << suvlist8[i]->getMake() << " ";
        outData << suvlist8[i]->getModel() << " ";
        outData << suvlist8[i]->getClassification() << " ";
        outData << suvlist8[i]->getYear() << " ";
        outData << suvlist8[i]->getColor() << " ";
        outData << suvlist8[i]->getPrice() << " " << endl;
    }
    outData.close();
    cout << "........got it! Data Successfully sent to the file" << endl << endl;
}
//**************************************                          ***************************************//
    //Function Defination that read data from the file
void readSUVDataFromFile(vector<Automobile*>& suvlist9, vector<Automobile*>& suvlist10)
{
    string  suv_make, suv_model;
    int suv_year;
    double suv_price;
    string suv_Classification;
    ifstream inData;
    inData.open("Car_data.dat");
    if (!inData)
    {
        cout << "Failed to open file" << endl;
    }
    else if (inData)
    {
        int count = 0;
        cout << "Printing Car Data From the file" << endl << endl;
        while (!inData.eof())
        {
            count++;

            inData >> suv_make;
            cout << "Car Make:";
            cout << suv_make << endl;

            inData >> suv_model;
            cout << "Car Model:";
            cout << suv_model << endl;

            inData >> suv_year;
            cout << "Car Year:";
            cout << suv_year << endl;

            inData >> suv_price;
            cout << "Car Price:";
            cout << suv_price << endl;

            inData >> suv_Classification;
            cout << "Car Classification:";
            cout << suv_Classification << endl << endl;
        }
    }
    cout << endl << endl;
}
//**************************************                          ***************************************//

//******************************************************************************************************//
//**************************************END OF FUNCTIONS DEFINTION FOR SUV***********************************//
//******************************************************************************************************//

//************************************** function defination to make upper case string  ***************************************//

// function defination to make upper case string
void convertString(string& s)
{
    for (int i = 0; i < s.length(); i++)
    {
        s[i] = toupper(s[i]);
    }
}
