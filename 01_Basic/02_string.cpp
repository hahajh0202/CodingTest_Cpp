#include <iostream>
#include <string>

using namespace std;


/* ==================================================================================================================== */
/* 문자열(string)이란?                                                                                                     */
/* 클래스로 구현된 객체 타입이라고 볼 수 있음. (정의 범위: std::string)                                                              */
/* STL에서 제공하는 컨테이너이자 클래스                                                                                         */
/* 내부 구조: 내부 구조적으로는 char 타입의 배열을 동적으로 관리하는 구조(char 동적 배열)                                                 */
/* 추상화: 사용자는 배열의 크기를 직접 조절할 필요 없이, 마치 하나의 변수처럼 더하거나(+) 비교(==)할 수 있게 "타입처럼" 보이도록 설계된 것.           */
/* (1) 연속된 메모리 구조: std::vector<char>와 유사한 구조임.                                                                   */
/* (1.1) 메모리 상에 연속적으로 데이터가 배치돼서, 인덱스(str[i])를 통한 접근이 가능하고, 포인터 연산이 가능하다.                              */
/* (1.2) 자료구조 시간 복잡도                                                                                                */
/*      - 맨 뒤에 추가(push_back): 평균적으로 O(1)                                                                           */
/*      - 중간에 삽입 및 삭제: 데이터를 한 칸씩 밀거나 당겨야 하므로 O(n)                                                            */
/*      - 찾기(find): 최악의 경우 문자열 전체를 훑어야 하므로 O(n)                                                                */
/* (1.3) Small string optimization (SSO)                                                                                */
/*      - 현대 c++의 string은 성능 최적화를 위해 아주 짧은 문자열(보통 15~23바이트 이하)은 Heap memory를 할당하지 않고,                    */
/*      객체 자체의 스택(Stack) 공간에 저장한다.                                                                                */
/*      - 자료구조를 공부할 때 "메모리 할당 비용"을 줄이는 기법 중 하나로 알아두면 좋을 듯.                                               */
/* (1.4) Capacity vs Size (string에서의 두 가지의 크기 개념)                                                                  */
/*      - size: 실제 들어있는 문자의 개수.                                                                                    */
/*      - capacity: 메모리에 할당된 총 공간. 문자열이 길어질 때마다 매번 메모리를 새로 할당하면 느려지기 때문에, 보통 필요한 것보다 더 큰 공간 확보   */
/* (2) string의 크기 (size, capacity, \0(null) 문자)                                                                       */
/* (2.1) string의 문자열 끝에도 '\0'(null)이 들어간다. "Hello, World!"의 size는 13이지만, 내부적으로는 \0이 있어서 14이다. (길이는 13맞음) */
/*      - 문자열 중간에 \0을 삽입한다면?: 데이터의 일부로 취급. c랑 달리 문자열이 잘리지는 않음.                                           */
/*      - 문자열의 끝을 찾을 때에는 size변수를 보고 판단하기 때문.                                                                  */

int main()
{
    /* 1. 문자열의 선언 및 초기화 방식 */
    // 1.1 방법 1: 문자열 리터럴로 초기화
    string str1 = "Hello, World!";
    cout << str1 << endl;
    // 시간 복잡도: O(n)

    // 1.2 방법 2: 생성자 및 인자로 초기화
    string str2("Hello");
    cout << str2 << endl;
    // 시간 복잡도: O(n)
    
    // 1.3 방법 3: 생성자에 초기화된 변수를 인자로 전달하여 초기화
    string str3(str2);
    cout << str3 << endl;
    // 시간 복잡도: O(n)

    // 1.4 방법 4: 문자열 부분 복사 초기화
    string str4(str1, 7, 5);
    cout << str4 << endl;
    // 시간 복잡도: O(m), m은 복사할 부분 문자열의 길이

    // 1.5 방법 5: argument 및 + 연산자를 사용한 초기화
    string str5(str3 + ", " + str4 + "!");
    cout << str5 << endl;
    // 시간 복잡도: O(n + m), n과 m은 각각 str3과 str4의 길이

    // 1.6 방법 6: 반복되는 문자와 개수를 사용한 초기화
    string str6(5, 'A');
    cout << str6 << endl;
    // 시간 복잡도: O(k), k는 반복되는 문자의 개수
    // 주의, 문자열을 반복시킬 수는 없음
    // string str(5, "Hi"); // 오류 발생. 문자는 가능하지만 문자열은 불가능

    // 1.7 방법 7: 대입 연산자 및 + 연산자를 사용한 초기화
    string str7 = str3 + ", " + str4 + "!";
    cout << str7 << endl;
    // 시간 복잡도: O(n + m), n과 m은 각각 str3과 str4의 길이

    /* 2. 문자열 길이와 접근 */
    cout << "Length of str1: " << str1.length() << endl; // 길이 반환
    // str1의 길이: 13
    // 시간 복잡도: O(1)

    cout << str1.size() << endl; // size()도 길이 반환
    cout << str1.length() << endl; // length()도 길이 반환
    cout << str1.capacity() << endl; // capacity()는 할당된 메모리 크기 반환
    cout << str1.data() << endl; // data()는 내부 문자 배열의 포인터 반환

    cout << "Character at index 7: " << str1[7] << endl; // 인덱스를 통한 접근

    /* 3. 문자열 탐색 */
    // 특정 문자나 문자열을 찾을 때는 find() 메서드를 사용
    // - find(찾을 문자열): 문자열의 처음부터 탐색
    // - find(찾을 문자열, 탐색 시작 위치): 특정 위치부터 탐색 시작
    // - returns: 찾은 문자열의 시작 인덱스, 못 찾으면 string::npos 반환
    // - 시간 복잡도: O(n) (탐색하는 문자열의 길이가 n일 때)
    size_t pos1 = str1.find("World");
    cout << "Position of 'World' in str1: " << pos1 << endl; // 7 (Hello, World!에서 World의 시작 위치)

    size_t pos2 = str2.find('l');
    cout << "Position of 'l' in str2: " << pos2 << endl; // 2 (Hello에서 첫 번째 l의 위치)

    size_t start_index = 2;
    size_t pos3 = str3.find("Hello", start_index);
    if (pos3 != string::npos)
    {
        cout << "'Hello' found in str3 at position: " << pos3 << endl;
    }
    else
    {
        cout << "'Hello' not found in str3 starting from index " << start_index << endl;
    }

    /* 3.1 문자열 부분 문자열 */
    string str8 = str1.substr(7, 5);
    cout << "Substring: " << str8 << endl;

    /* 4. 문자열 추가 및 수정 */
    /*
    추가: '+' 연산자 혹은 '+=' 연산자를 사용
    특정 문자 수정: [] 연산자를 사용해서 임의 접근 후 수정하거나 혹은 replace() 메서드를 사용
    - replace(시작 인덱스, 시작 위치부터 몇 개의 문자열을 대체할 것인지, 대체할 문자열)
    - 시간 복잡도: O(n + m) (n은 대체할 문자열의 길이, m은 대체되는 문자열의 길이)
    */

   str3 += ", Universe!";
   cout << "After += : " << str3 << endl;

   str3[7] = 'W';
   cout << "After modification: " << str3 << endl;

   str3.replace(7, 8, "World!");
   cout << "After replace: " << str3 << endl;

    return 0;
}