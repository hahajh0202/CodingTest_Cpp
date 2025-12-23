#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1;                    // 빈 문자열 선언
    string str2 = "Hello, World!";  // 문자열 직접 초기화
    string str3(str2);              // 문자열 복사
    string str4(str2, 0, 5);        // 문자열 부분 복사 초기화 (arg1=문자열, arg2=복사할 첫 index, arg3=이 인덱스 전까지)
    string str5(10, 'a');           // 반복 문자열 초기화 (arg1=int라면 횟수, arg2=반복할 문자)
    /* str5에 문자열이 아닌 문자만 들어가야 함. 
    문자열이 들어가면 마지막에 잡힌 문자가 반복됨. (ex. 'ad'로 하면 dddddddd) */
    string str6 = "Hello";
    string str7 = "World";
    string str8(str6 + ", " + str7 + "!");
    cout << str8 << endl;
    /* 
    string내부는 동적 배열로 이루어져있어서 크기를 동적으로 변경할 수 있음. 
    '\0' 문자로 종료되지 않음
    */


    /* ========================= */
    /* string 관련 매서드 1) find() */
    string str = "Hello, C++ World!";

    /* (1) "Hello" 문자열을 찾아라 */
    size_t pos1 = str.find("Hello");
    // size_t: 객체의 크기나 개수를 나타내기 위해 정의된 unsigned int type
    // int와 비교했을 때, 아주 긴 문자열(20먹자 이상)을 다룰 때 int로 인덱스를 표현하면 오버플로우 발생
    // size_t를 인덱스로 썼을 때는 unsigned int이기 때문에 시스템의 메모리 한계까지 안전하게 표현 가능함.

    if (pos1 != string::npos)
    {
        cout << "찾은 위치: " << pos1 << endl;
    }
    else
    {
        cout << "문자열 탐색 불가" << endl;
    }

    /* (2) "C" 문자를 찾아라 */
    size_t pos2 = str.find("C");

    if (pos2 != string::npos)
    {
        cout << "찾은 위치: " << pos2 << endl;
    }
    else
    {
        cout << "문자열 탐색 불가" << endl;
    }

    /* (3) "Hello" 문자열을 찾아라 (시작인덱스: 2) */
    size_t start_index = 2;
    size_t pos3 = str.find("Hello", start_index);

    if (pos3 != string::npos)
    {
        cout << "찾은 위치: " << pos3 << endl;
    }
    else
    {
        cout << "문자열 탐색 불가" << endl;
    }

    /* (4) 존재하지 않는 문자열 찾기 */
    size_t pos4 = str.find("Python");
    cout << pos4 << endl;
    // string::npos의 값: 184457440....

    return 0;
}