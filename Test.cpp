#include <iostream>
#include <chrono>
using namespace std;
auto main(void) -> int
{
    auto startTime = std::chrono::steady_clock::now(); // steady_clock은 물리적 시간
    // system_clock::time_point startTime = system_clock::now(); 컴퓨터 시스템 시간
    int n = 10;
    float k = 3.0f;
    while(n--)
    {
        auto endTime = std::chrono::steady_clock::now();
        std::chrono::duration<float> elapsed_seconds = endTime - startTime;
        cout << elapsed_seconds.count()<< endl;
        cout << elapsed_seconds.count() - k << endl;
        cout << 'l' << endl;

    }
}
