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

    cout << str5 << endl;

    return 0;
}