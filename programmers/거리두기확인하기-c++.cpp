#include <string>
#include <vector>

using namespace std;

vector<vector<string>> cpPlaces;

int route[12][2][2] = {{{-1, 0}, {-1, 0}}, {{-1, 0}, {0, 1}}, {{0, 1}, {-1, 0}}, {{0, 1}, {0, 1}}, {{0, 1}, {1, 0}}, {{1, 0}, {0, 1}}, {{1, 0}, {1, 0}}, {{0, -1}, {1, 0}}, {{1, 0}, {0, -1}}, {{0, -1}, {0, -1}}, {{0, -1}, {-1, 0}}, {{-1, 0}, {0, -1}}};

bool inRange(int X, int Y){
    return X >= 0 && X < 5 && Y >= 0 && Y < 5;
}

bool canBePlace(string place){
    if (place == "PPO") {
        return false;
    }
    else if (place == "PPx"){
        return false;
    }
    else if (place == "PPP"){
        return false;
    }
    else if (place == "POP"){
        return false;
    }
    else if (place == "OPP"){
        return false;
    }
    else if (place == "XPP"){
        return false;
    }
    return true;
}

bool checkDis(vector<string> place){
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k1 = 0; k1 < 12; k1++) {
                string temp = "";
                temp += place[i][j];
                int cx = i;
                int cy = j;
                for (int k2 = 0; k2 <2; k2++) {
                    int nx = cx + route[k1][k2][0];
                    int ny = cy + route[k1][k2][1];
                    if (inRange(nx, ny)) {
                        temp += place[nx][ny];
                        cx = nx;
                        cy = ny;
                    }
                }
                if (temp.size() == 3) {
                    if (!canBePlace(temp)) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    cpPlaces = places;
    vector<int> answer;
    for (int i = 0; i < places.size(); i++) {
        if (checkDis(cpPlaces[i])) {
            answer.push_back(1);
        }
        else{
            answer.push_back(0);
        }
    }

    return answer;
}
