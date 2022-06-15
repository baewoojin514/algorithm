using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    
    long long tempSum = 0;
    
    for (int i = 1; i <= count; i++) {
        tempSum += price * i;
    }
    
    if (tempSum <= money) {
        answer = 0;
    }
    else{
        answer = tempSum - money;
    }

    return answer;
}
