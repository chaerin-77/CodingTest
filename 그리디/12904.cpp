/*
A와 B

문제
수빈이는 A와 B로만 이루어진 영어 단어가 존재한다는 사실에 놀랐다.
대표적인 예로 AB (Abdominal의 약자), BAA (양의 울음 소리), AA (용암의 종류), ABBA (스웨덴 팝 그룹)이 있다.

이런 사실에 놀란 수빈이는 간단한 게임을 만들기로 했다.
두 문자열 S와 T가 주어졌을 때, S를 T로 바꾸는 게임이다.
문자열을 바꿀 때는 다음과 같은 두 가지 연산만 가능하다.

문자열의 뒤에 A를 추가한다.
문자열을 뒤집고 뒤에 B를 추가한다.
주어진 조건을 이용해서 S를 T로 만들 수 있는지 없는지 알아내는 프로그램을 작성하시오.

입력
첫째 줄에 S가 둘째 줄에 T가 주어진다.
(1 ≤ S의 길이 ≤ 999, 2 ≤ T의 길이 ≤ 1000, S의 길이 < T의 길이)

출력
S를 T로 바꿀 수 있으면 1을 없으면 0을 출력한다.
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string input1, input2;
    cin >> input1 >> input2;

    int length1 = input1.size();
    int length2 = input2.size();

    if (length2 < length1)
    {
        cout << 0;
        return 0;
    }

    // 두 문자열이 같아지도록 비교
    while (length2 > length1)
    {
        if (input2.back() == 'A')
        {
            input2.pop_back();
        }
        else
        {
            input2.pop_back();
            reverse(input2.begin(), input2.end());
        }
        length2--;
    }

    // 두 문자열이 같다면 S를 T로 바꿀 수 있음
    if (input2 == input1)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }

    return 0;
}