#include "List.h"
#include <iostream>
using namespace std;



int main()
{
    List<string> list;
    list.Add("one");
    list.Add("two");
    list.Add("three");
    cout << "Original List: "; list.PrintAllValue();

    cout << endl;
    list.Add("Six");
    cout << "List after add value in begin: "; list.PrintAllValue();

    cout << endl;
    list.Insert(3,"Seven");
    cout << "List after add value in specific place: "; list.PrintAllValue();

    cout << endl;
    list.AddAfter("Five");
    cout << "List after add value in end: "; list.PrintAllValue();

    cout << endl;
    cout << "Value in 2 place in list: " << list.Print(2);

    cout << endl << endl;
    cout << "Value in 7 place in list: " << list.Print(7);

    cout << endl << endl;
    list.Remove();
    cout << "Remove first value in list: "; list.PrintAllValue();

    cout << endl << endl;
    cout << "Find word \"three\": " << list.Find("three");

    cout << endl << endl;
    cout << "Word before finder word \"three\": " << list.FindPrev("three");

    cout << endl << endl;
    cout << "Word after finder word \"three\": " << list.FindAfter("three");

    cout << endl << endl;
    cout << "List before clear: "; list.PrintAllValue();
    list.Clear();
    cout << endl;
    cout << "List after clear: "; list.PrintAllValue();

    return 0;
}
