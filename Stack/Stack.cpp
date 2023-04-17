#include <clocale>
#include <iostream>
#include <random>
using namespace std;


struct stack {

    int Arr[1000];
    int item = -1;

    void push_back(int a) {
        item++;
        Arr[item] = a;
    }
    int pop_out() {
        if (item != -1) {
            item--;
            return Arr[item + 1];
        }

    }

    void show() {
        if (item != -1) {
            cout << "Stack elements: ";
            for (int i = 0; i <= item; i++) {
                cout << Arr[i] << " ";
            }
            cout << endl;
        }

    }
    void reverse() {
        int x;

        for (int i = 0, j = item; j > item / 2 - 1; i++, j--) {
            x = Arr[i];
            Arr[i] = Arr[j];
            Arr[j] = x;
        }
    }

    void push_back_range(int a, int b) {
        for (int i = a; i <= b; i++) {
            item++;
            Arr[item] = i;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Rus");
    int x;
    int items;
    stack main_stack;
    stack sorter;

    main_stack.push_back_range(-20, 60);
    items = main_stack.item;

    cout << "main "; main_stack.show();

    for (int j = 0; j <= items; j++) {
        x = main_stack.pop_out();
        if (x % 7 != 0) {
            sorter.push_back(x);
        }
    }

    sorter.reverse();
    main_stack = sorter;
    /*items = sorter.item;
    for (int j = 0; j <= items; j++) {
        x = sorter.pop_out();
        main_stack.push_back(x);
    }*/


    cout << endl << "main(after sorting(%7 != 0)) "; main_stack.show();


}
