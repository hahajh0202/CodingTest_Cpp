#include <iostream>

using namespace std;

/*=================call by value 예제=================
void modify_callbyvalue(int value)
{
    value = 10;
    cout << "주소 " << &value << endl;
    cout << "값: " << value << endl;
}
*/

/*=================call by reference 예제=================*/
void modify_callbyreference(int & value)
{
    value = 10;
    cout << "주소 " << &value << endl;
    cout << "값: " << value << endl;
}

int main()
{
    int value = 5;
    cout << "주소 " << &value << endl;
    cout << "값: " << value << endl;
    //modify_callbyvalue(value);
    modify_callbyreference(value);
    cout << "값: " << value << endl;

    return 0;
}