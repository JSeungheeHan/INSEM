
#include <iostream>

using namespace std;


class LightBox {
public:
    LightBox() {
        return;
    }

    LightBox(string n, int p, string d)
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
    int price;
    int height;
    int length;
    string description;
    int display[10][10];
};

class Lights {
public:
    Lights() {
        return;
    }
    Lights(string n, int p, string d, int l, int w)
    {
        name = n;
        price = p;
        description = d;
        length = l;
        watts = w;
    }
    string name;
    int price;
    int length;
    int watts;
    string description;
};

int main() {


    int height;
    int lenght;
    int number;

    cout << "Type in the height of the light box: ";
    cin >> height;
    cout << "Type in the length of the light box: ";
    cin >> length;
    cout << "How many light boxes are you ordering?";
    cin >> number;




}
