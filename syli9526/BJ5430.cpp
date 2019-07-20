#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

string func, list;
int T, N;
bool loc, error;
deque<int> dq;


int main() {

    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> T;

    while (T--) {
        cin >> func >> N >> list;
        loc = true;
        error = false;

        string temp;
        for (int i = 0; i < list.length(); i++) {
            if (list[i] >= '0' && list[i] <= '9') {
                temp += list[i];
            } else if (list[i] == ',' || list[i] == ']') {
                if (temp.size() > 0) dq.push_back(stoi(temp));
                temp.clear();
            } else {
                continue;
            }
        }

        for (int i = 0; i < func.length(); ++i) {
            if (func[i] == 'R') loc = !loc;
            else {
                if (dq.empty()) {
                    error = true, cout << "error\n";
                    break;
                } else {
                    if (loc) dq.pop_front();
                    else dq.pop_back();
                }
            }
        }

        if (!error) {

            cout << "[";
            while (!dq.empty()) {
                if (loc) cout << dq.front(), dq.pop_front();
                else cout << dq.back(), dq.pop_back();

                if (!dq.empty()) cout << ",";
            }
            cout << "]\n";
        }


    }
}

