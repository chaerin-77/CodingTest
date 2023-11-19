/*
문제명 : 1+1
 
[제한 조건]
실행시간 : 50개의 테스트 케이스를 합쳐서 C/C++의 경우 1초, JAVA의 경우 1초, Python 2초
메 모 리 : Heap, Global, Stack 등을 모두 합해 최대 256MB까지 사용 가능 (단, 스택은 최대 1MB까지 사용 가능)
제출 횟수 제한: 제한 없음

[채점]
Accept : 정상적으로 제출되었다는 의미 (컴파일 에러 등 없다는 의미이며 점수는 공개하지 않음)
Fail : 컴파일, 런타임 에러 등으로 0점

[평가]
sample_input은 편의를 위해 제공하며, 실제 채점은 별도의 평가용 input으로 이루어진다.


어떤 가게에서 N개의 물건을 사려고 한다.
각 물건의 가격이 주어진다. 이 가게는 1+1 제도를 운영한다.
1+1제도에서는 어떤 물건을 하나 사면 다른 물건을 하나 무료로 준다.
단, 무료로 주는 물건의 조건은 돈을 내고 산 물건보다 가격이 낮아야 한다.
이 조건에 맞는 물건이 없는 경우 무료로 주는 물건은 없다.
철수는 다음과 같은 작전을 물건이 떨어질 때까지 반복하기로 했다.

1. 현재 있는 물건들 중 가장 가격이 비싼 것을 산다.
2. 무료로 받을 수 있는 물건이 있는 경우 가능한 가장 비싼 것을 받는다.

N개의 물건의 가격이 주어질 때 철수가 모든 물건을 사는 비용을 계산하는 프로그램을 작성하라.

예를 들어, N = 4이고 물건들의 가격이 각각 5, 3, 4, 3인 경우를 생각하자.
작전에 따라 가격이 5인 물건을 사고 가격이 4인 물건을 무료로 받는다.
남은 두개의 물건은 1+1 조건에 맞지 않아 가격을 지불하고 사야 한다.
따라서 총 비용은 5+3+3 = 11이다.

[제약사항]
1. 물건의 개수 N은 1 이상 500 이하이다. (1 ≤ N ≤ 500)
2. 물건의 가격은 1 이상 1,000 이하의 정수이다.

[입력]
가장 첫 줄에는 테스트 케이스의 총 수가 주어진다.
그 다음 줄부터 각 테스트 케이스가 주어지며, 각 테스트 케이스는 2 줄로 구성된다. 각
테스트 케이스의 첫 줄에는 N이 주어진다. 다음 줄에는 물건들의 가격 N개가 주어진다.

[출력]
출력의 각 줄은 ‘#x’로 시작하고, 공백을 한 칸 둔 다음 모든 물건을 사는데 필요한 비용을 출력한다. 단, x는 테스트 케이스의 번호이다.

[입력 예]
3                    // 테스트 케이스의 수
4                          // N = 4, 테스트 케이스 #1
5 3 4 3
4                          // N = 4, 테스트 케이스 #2
1 2 3 4
4                          // N = 4, 테스트 케이스 #3
5 2 5 1

[출력 예]
#1 11
#2 6
#3 10
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int N, result = 0;
		cin >> N;
		vector<int> obj(N, 0);
		int check[1001] = { 0, };
		check[0] = 1001;

		for (int j = 0; j < N; j++)
		{
			cin >> obj[j];
			check[obj[j]]++;
		}
		sort(obj.begin(), obj.end(), greater<int>());
		
		int buy_idx = 0, service_idx = 0;
		for (int j = 0; j < N; j++)
		{
			buy_idx = obj[j];
			service_idx = obj[j] - 1;

			while (check[buy_idx] > 0)
			{
				check[buy_idx]--;
				result += buy_idx;

				while (!check[service_idx]) service_idx--;
				check[service_idx]--;

				if (service_idx == 0 && check[buy_idx] > 0)
				{
					result += buy_idx * check[buy_idx];
					check[buy_idx] = 0;
					break;
				}
			}
		}

		cout << "#" << i + 1 << " " << result << endl;
	}
	return 0;
}