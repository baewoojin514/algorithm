//방문길이(programmers)
//skill.1 - 현재 지점에서 다음 지점 좌표 즉 cxcynxny 형태의 string을 key로 하는 map을 통해 방문 여부를 판단한다.
//skill.2 - 처음 방문하는 경우 answer += 1한다.
//skill.3 - inRange 함수를 통해 범위를 벗어나는 경우는 answer += 1 하지 않는다.

#include <string>
#include <map>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
//R, L, D, U 순서이다.

bool inRange(int X, int Y){
    return X >= -5 && X <= 5 && Y >= -5 && Y <= 5;
}

int charToInt(char dir){
    if (dir == 'R') {
        return 0;
    }
    else if (dir == 'L') {
        return 1;
    }
    else if (dir == 'D') {
        return 2;
    }
    return 3;
}

int solution(string dirs) {
    map<string, int> m;
    
    int answer = 0;
    int stx = 0;
    int sty = 0;
    
    for (int i = 0; i < dirs.size(); i++) {
        int cdir = charToInt(dirs[i]);
        string check1 = "";
        string check2 = "";
        if (inRange(stx + dx[cdir], sty + dy[cdir])) {
            int nx, ny;
            nx = stx + dx[cdir];
            ny = sty + dy[cdir];
            check1 += stx + '0';
            check1 += sty + '0';
            check1 += nx + '0';
            check1 += ny + '0';
            check2 += nx + '0';
            check2 += ny + '0';
            check2 += stx + '0';
            check2 += sty + '0';
            if (m[check1] == 0 && m[check2] == 0) {
                m[check1] += 1;
                m[check2] += 1;
                stx = nx;
                sty = ny;
                answer += 1;
            }
            else {
                stx = nx;
                sty = ny;
                continue;
            }
        }
        else if (!inRange(stx + dx[cdir], sty + dy[cdir])){
            stx = stx;
            sty = sty;
            continue;
        }
    }
    return answer;
}
