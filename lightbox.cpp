
#include <iostream>

using namespace std;
struct IntItem {
    int value;
    IntItem* next;
    IntItem(int v, IntItem* n) { value = v; next = n; }
};

IntItem* mystery1(int start, int end) {
    if (start < end) return new IntItem(start, mystery1(start + 1, end));
    else return nullptr;
}

IntItem* mystery2(IntItem* head, IntItem* prev) {
    if (head != nullptr) return mystery2(head->next, new IntItem(head->value, prev));
    else return prev;
}

//void printLL(IntItem* a)
//{
//    while (a != NULL)
//    {
//        cout << a->value << " ";
//        a = a->next;
//    }
//    cout << endl;
//}

int main() {
    IntItem* p1 = mystery1(0, 5);
    printLL(p1);
    IntItem* p2 = mystery2(p1, nullptr);
    printLL(p2);
    return 0;
}
