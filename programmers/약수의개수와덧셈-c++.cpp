using namespace std;

int answer;

int denominatorCnt(int num){
    int cnt = 0;
    
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            cnt += 1;
        }
    }
    if (cnt % 2 == 0) {
        return 0;
    }
    return 1;
}

int solution(int left, int right) {
    answer = 0;
    
    for (int num = left; num <= right; num++) {
        if (!denominatorCnt(num)) {
            answer += num;
        }
        else{
            answer -= num;
        }
    }
    return answer;
}
