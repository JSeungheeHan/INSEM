
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class LightBox {
public:
    LightBox() {
        return;
    }

    LightBox(string n, double p, string d)
    {
        name = n;
        price = p;
        description = d;
    }

    void setDisplay(int input[][10])
    {
        for (int i = 0; i < 10; i++)
        {
            for (int k = 0; k < 10; k++)
            {
                display[i][k] = input[i][k];
            }
        }
    }

    void printDisplay() {
        for (int i = 0; i < 10; i++)
        {
            for (int k = 0; k < 10; k++)
            {
                cout << display[i][k];
            }
            cout << endl;
        }
    }
    string name;
    double price;
    double height;
    double length;
    string description;
    int display[10][10];
};

class Lights {
public:
    Lights() {
        return;
    }
    Lights(string n, double p , string d, double l, int w)
    {
        name = n;
        price = p;
        description = d;
        length = l;
        watts = w;
    }
    string name;
    double price;
    double length;
    int watts;
    string description;
};


void printhelp(string name, string description, int quantity, int price) {
    cout << name;
    for (unsigned int i = 0; i < (20 - name.size()); i++)
    {
        cout << " ";
    }
    cout << description;
    for (unsigned int i = 0; i < 64 - description.size(); i++)
    {
        cout << " ";
    }

    cout << quantity;
    int l = 0;
    int hold = quantity;
    while (hold != 0)
    {
        hold = hold / 10;
        l++;
    }

    for (int i = 0; i < 16 - l; i++)
    {
        cout << " ";
    }
    cout << price << ".00";

    l = 0;
    hold = price;
    while (hold != 0)
    {
        hold = hold / 10;
        l++;
    }
    for (int i = 0; i < 13 - l; i++)
    {
        cout << " ";
    }
    cout << price * quantity << ".00" << endl;
}


int main() {

    vector<LightBox> Boxes;
    LightBox LF_Fifty("LF-0050-SWSV-3000", 18, "Lightbox fixture, 50mm, Single side, Wall mount, Silver");
    LightBox LF_SixtyFive("LF-0065-SWSV-3000", 21.5, "Lightbox fixture, 65mm, Single side, Wall mount, Silver");
    LightBox LF_Ninty("LF-0090-SWSV-3000", 25.8, "Lightbox fixture, 90mm, Single side, Wall mount, Silver");
    LightBox LF_Hundred("LF-0100-SWSV-3000", 25.8, "Lightbox fixture, 100mm, Single side, Wall mount, Silver");
    LightBox LF_HundredTwenty("LF-0120-SWSV-3000", 27.5, "Lightbox fixture, 120mm, Single side, Wall mount, Silver");
    LightBox LF_HundredTwentyD("LF-0120-DSSV-3000", 28, "Lightbox fixture, 120mm, Double side, Standing use, Silver");
    LightBox LF_HundredFiftyD("LF-0156-DSSV-3000", 29.5, "Lightbox fixture, 156mm, Double side, Standing use, Silver");

    Boxes.push_back(LF_Fifty);
    Boxes.push_back(LF_HundredTwentyD);
    Boxes.push_back(LF_Fifty);
    Boxes.push_back(LF_HundredTwentyD);
    Boxes.push_back(LF_Fifty);
    Boxes.push_back(LF_HundredTwentyD);


    double height;
    double length;
    int index;
    int number;
    int sides;

    bool reading = true;

    while (reading)
    {

        //Input Reading
        bool valid = false;
        double total = 0;

        cout << "Type in the height of the light box: ";
        cin >> height;
        cout << "Type in the length of the light box: ";
        cin >> length;
        while (!valid)
        {
            cout << "How many sides? (1, 2, or 4): ";
            cin >> sides;
            if (sides == 1 || sides == 2 || sides == 4)
            {
                valid = true;
                break;
            }
            cout << "Invalid number of slides" << endl;
        }
        cout << "How many light boxes are you ordering: ";
        cin >> number;
        cout << "Please choose one of the following boxes, or type 0 to go back" << endl;
        //Printing Boxes
        for (unsigned int i = 0; i < Boxes.size(); i++)
        {
            cout << i+1 << ") " << Boxes[i].name << endl;
        }
        cout << "Enter your choice: ";
        cin >> index;
        if (index < 1 || index > (int) Boxes.size())
        {
            continue;
        }

        //Setting values
        index--;
        Boxes[index].height = height;
        Boxes[index].length = length;

        //Print the top row
        cout << "Item                Description                                                     Quantity        Price           Total" << endl;


        //Print the price of the box:
        int price = (int) (Boxes[index].price * height /12 * length /12) + 1;
        
        string lengthstr = std::to_string(length);
        lengthstr.erase(lengthstr.find_last_not_of('0') + 1, std::string::npos);

        string heightstr = std::to_string(height);
        heightstr.erase(heightstr.find_last_not_of('0') + 1, std::string::npos);

        string save = "Custom AL frame for " + lengthstr + "\" " + heightstr + "\" ";
        total = total + price * number;
        printhelp("Custom", save, number, price);
        cout << "                    " << Boxes[index].name << endl;


        //Calculating lights
        //8.625, 14.38, 17.25
        int three = 0;
        int five = 0;

        double bigger = height;
        double smaller = length;
        if (length > height)
        {
            bigger = length;
            smaller = height;
        }

        if (sides == 4)
        {
            double remainder = 100;
            int threes = 0;
            int fives = 0;
            while (fives * 14.38 < smaller)
            {
                fives++;
            }
            fives--;
            if ((smaller - fives * 14.38) < remainder)
            {
                five = fives;
                remainder = (smaller - fives * 14.38);
            }
            while (fives > 0)
            {
                while (fives * 14.38 + threes * 8.625 < smaller)
                {
                    threes++;
                }
                threes--;
                if (smaller - (fives * 14.38 + threes * 8.625) < remainder)
                {
                    five = fives;
                    three = threes;
                    remainder = smaller - (fives * 14.38 + threes * 8.625);
                }
                fives--;
            }
            //while (three * 8.6 + five * 14.38 > smaller)
            //{
            //    three--;
            //}
        }

        

        int threehold;
        int fivehold;
        double remainder = 100;
        int threes = 0;
        int fives = 0;
        while (fives * 14.38 < bigger)
        {
            fives++;
        }
        fives--;
        if (bigger - fives * 14.38 < remainder)
        {
            fivehold = fives;
            remainder = bigger - fives * 14.38;
        }
        while (fives > 0)
        {
            while (fives * 14.38 + threes * 8.625 < bigger)
            {
                threes++;
            }
            threes--;
            if (bigger - (fives * 14.38 + threes * 8.625) < remainder)
            {
                fivehold = fives;
                threehold = threes;
                remainder = bigger - (fives * 14.38 + threes * 8.625);
            }
            fives--;
        }

        //while (threehold * 8.6 + fivehold * 14.38 > bigger)
        //{
        //    threehold--;
        //}

        three = three + threehold;
        five = fivehold + five;


        int six = three / 2;
        three = three % 2;

        if (sides != 1)
        {
            three = three * 2;
            five = five * 2;
            six = six * 2;
        }
        three = three * number;
        five = five * number;
        six = six * number;

        //Printing the lights
        if (three != 0)
        {
            printhelp("PER-3-G2", "InSem Perimeter 3 DIODE LED (6000K)", three, 27);
        }
        if (five != 0)
        {
            printhelp("PER-5-G2", "InSem Perimeter 5 DIODE LED (6000K)", five, 30);
        }
        if (six != 0)
        {
            printhelp("PER-6-G2", "InSem Perimeter 6 DIODE LED (6000K)", six, 35);
        }
        total = total + three * 27 + five * 30 + six * 35;


        //Power supply
        double watts = (three * 8.16 + five * 13.5 + six * 15.6) / (double) number;
        string supplyname;
        int supplyprice;
        int supplyquantity;
        string supplydescription;
        if ((fmod(watts, 76) / 76) < (fmod(watts, 96) / 96))
        {
            supplyname = "SMPS-120A-24";
            supplyquantity = (watts / 96) + 1;
            supplydescription = "24V DC 120W SWICHING MODE POWER SUPPLY";
            supplyprice = 85;
        }
        else
        {
            supplyname = "SMPS-96Q-24";
            supplyquantity = (watts / 76) + 1;
            supplydescription = "24V DC 96W SWICHING MODE POWER SUPPLY";
            supplyprice = 68;
        }
        supplyquantity = supplyquantity * number;
        total = total + supplyquantity * supplyprice;

        //Printing cable

        printhelp("INT-MJ-MF-18", "5.5/2.1mm jack to harness female interconnector, 48\"", supplyquantity, 3);
        printhelp(supplyname, supplydescription, supplyquantity, supplyprice);
        cout << endl;
        printhelp(" ", "Total: ", 1, total);

        //Quitting
        cout << "Type Y to continue, or N to quit: ";
        char input;
        cin >> input;
        if (input == 'N')
        {
            break;
        }
        cout << endl << endl;

    }
    



}
