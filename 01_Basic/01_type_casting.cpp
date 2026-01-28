#include <iostream>

using namespace std;

int main()
{
    int i = 65;
    float f = 5.2f;

    // 암시적 형 변환 (덧셈 연산 시 숫자 표현 범위가 더 넓은 float로 형 변환됨)
    double d = i + f;
    cout << d << endl;

    // 명시적 형 변환 (double -> int)
    cout << static_cast<int>(d) << endl;

    // 명시적 형 변환 (int -> char)
    cout << static_cast<char>(i) << endl;

    return 0;

    /* 왜 float f = 5.2f 에 f를 붙였는가? */
    /* C++ 컴파일러는 소수점이 붙은 숫자를 기본적으로 double type으로 인식한다. (5.2: double / 5.2f: float) 
    따라서, float f = 5.2 를 하게 되면, 암시적 형 변환 (double -> float) 
    8바이트인 double을 4바이트인 float 변수에 집어넣기 위해 스스로 크기를 줄임. 
    
    따라서 f를 붙이는 이유는, 컴파일러에게 float용 데이터니까 안심하라는 의미로 붙임. 
    
    추가+) 임베디드나 게임 프로그래밍처럼 성능이 중요한 분야에서는 메모리를 적게 사용하는 float 연산이 유리할 때가 많음. 
    소수점을 f없이 그냥 쓰게 되면 double로 암시적 형 변환했다가, float로 바꾸는 불필요한 과정을 거치게 됨. 
    
    추가+) 부동 소수점은 컴퓨터 내부에서 근사치로 저장됨. 
    아주 미세한 소수점 연산을 할 때, f를 붙인 것과 안붙인 것을 비교(==)하면 결과가 다르게 나올 수 있음. */
}