/*
스도쿠 검증

스도쿠는 숫자퍼즐로, 가로 9칸 세로 9칸으로 이루어져 있는 표에 1 부터 9 까지의 숫자를 채워넣는 퍼즐이다.

같은 줄에 1 에서 9 까지의 숫자를 한번씩만 넣고,
3 x 3 크기의 작은 격자 또한, 1 에서 9 까지의 숫자가 겹치지 않아야 한다.

입력으로 9 X 9 크기의 스도쿠 퍼즐의 숫자들이 주어졌을 때,
위와 같이 겹치는 숫자가 없을 경우, 1을 정답으로 출력하고 그렇지 않을 경우 0 을 출력한다.

[제약 사항]
1. 퍼즐은 모두 숫자로 채워진 상태로 주어진다.
2. 입력으로 주어지는 퍼즐의 모든 숫자는 1 이상 9 이하의 정수이다.

[입력]
입력은 첫 줄에 총 테스트 케이스의 개수 T가 온다.
다음 줄부터 각 테스트 케이스가 주어진다.
테스트 케이스는 9 x 9 크기의 퍼즐의 데이터이다.

[출력]
테스트 케이스 t에 대한 결과는 “#t”을 찍고, 한 칸 띄고, 정답을 출력한다.
(t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)
*/
#include <iostream>
using namespace std;

// int main()
// {
//     int test_case;
//     int T;
//     cin >> T;

//     for (test_case = 1; test_case <= T; ++test_case)
//     {
//         int puzzle[9][9] = {
//             0,
//         };
//         int box_check[9][9] = {
//             0,
//         };
//         int row_check[9][9] = {
//             0,
//         };
//         int col_check[9][9] = {
//             0,
//         };

//         for (int i = 0; i < 9; i++)
//             for (int j = 0; j < 9; j++)
//                 cin >> puzzle[i][j];

//         int count = 0;
//         int ans = 1;
//         for (int i = 0; i < 9; i++)
//         {
//             count = (i / 3) * 3;
//             for (int j = 0; j < 9; j++)
//             {
//                 row_check[i][puzzle[i][j]]++;
//                 col_check[j][puzzle[i][j]]++;
//                 box_check[count + (j / 3)][puzzle[i][j]]++;
//                 if (row_check[i][puzzle[i][j]] > 1 || box_check[count + (j / 3)][puzzle[i][j]] > 1)
//                 {
//                     ans = 0;
//                     break;
//                 }
//             }
//             if (ans == 0)
//                 break;
//         }
//         cout << "#" << test_case << " " << ans << "\n";
//     }
//     return 0;
// }
int main()
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int map[9][9];
        bool result = true;

        // 입력
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cin >> map[i][j];
            }
        }

        // 가로
        for (int i = 0; i < 9; i++)
        {
            if (!result)
                break; // 앞에서 한번이라도 불만족시 break
            int check[9] = {
                0,
            };
            for (int j = 0; j < 9; j++)
            {
                if (check[map[i][j] - 1] > 0)
                {
                    result = false;
                    break;
                }
                else
                    check[map[i][j] - 1] += 1;
            }
        }

        // 세로
        for (int i = 0; i < 9; i++)
        {
            if (!result)
                break; // 앞에서 한번이라도 불만족시 break
            int check[9] = {
                0,
            };
            for (int j = 0; j < 9; j++)
            {
                if (check[map[j][i] - 1] > 0)
                {
                    result = false;
                    break;
                }
                else
                    check[map[j][i] - 1] += 1;
            }
        }

        // 3*3 사각형
        for (int i = 0; i < 3; i++)
        {
            if (!result)
                break; // 앞에서 한번이라도 불만족시 break
            for (int j = 0; j < 3; j++)
            {
                int check[9] = {
                    0,
                };
                for (int k = 0; k < 3; k++)
                {
                    for (int s = 0; s < 3; s++)
                    {
                        if (check[map[3 * i + k][3 * j + s] - 1] > 0)
                        {
                            result = false;
                            break;
                        }
                        else
                            check[map[3 * i + k][3 * j + s] - 1] += 1;
                    }
                }
            }
        }

        cout << "#" << test_case << " " << result << "\n";
    }
    return 0;
}