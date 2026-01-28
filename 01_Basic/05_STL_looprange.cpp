#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

/*
** 범위 기반 반복문 (Range-based for loop) **
** - 배열이나 컨테이너의 모든 원소를 순회할 때 사용한다.
** - 기본 반복문보다 구현이 쉽고 가독성이 좋다.
** - 문법: for (자료형 변수명 : 컨테이너) { ... }
*/

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};
    for(int num : vec)
    {
        cout << num << " ";
    }
    cout << endl;

    map<string, int> fruitMap = {{"apple", 1}, {"banana", 2}, {"cherry", 3}};
    for (const auto& pair : fruitMap)
    {
        cout << pair.first << "=" << pair.second << " ";
    }
    cout << endl;

    set<string> fruitSet = {"apple", "banana", "cherry"};
    cout << "Set: ";
    for (const auto& fruit : fruitSet)
    {
        cout << fruit << " ";
    }
    cout << endl;

    return 0;
}

/* 
- STL 컨테이너와 사용할 때는 값을 수정할 필요가 없으므로 auto 대신 상수 레퍼런스를 적용한 const auto&를 사용했다.
- 컨테이너를 반복문에서 사용하거나 함수의 인수로 넘길 때는 항상 복사하는 비용을 고려해야 한다.
- 수정해야 할 때는 레퍼런스를, 수정하지 않아야 할 때는 상수 레퍼런스 적용을 권장한다.
*/