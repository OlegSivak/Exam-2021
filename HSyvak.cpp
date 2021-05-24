#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
string A(int n){
    ostringstream B; B << n;
    return B.str();
}
int position_number(char D){
    if (D == '+' or D == '-') return 0;
    if (D == '*' or D == '/') return 1;
    return -1;
}
string operand(string oper, string f1, string f2){
    int E = stoi(f1.c_str()), D = stoi(f2.c_str());
    if (oper == "+") return A(E + D);
    if (oper == "-") return A(E - D);
    if (oper == "*") return A(E * D);
    if (oper == "/"){
        if (E * D > 0 or E % D == 0) return A(E / D);
        else return A(E / D - 1);
    }
    return "";
}
bool fun(string crutch) {
    if (crutch == "+" or crutch == "-" or crutch == "/" or crutch == "*") return 1;
    else return 0;
}
string striped(string h){
    while (true){
        if (h[0] != '(' || h[h.size() - 1] != ')')
        return h;
        int z = 1;
        for (int i = 0; i < h.size(); i++){
            char c = h[i];
            if (c == '(')
            z++;
            else if (c == ')'){
                z--;
                if (z == 1 && i != h.size() - 1){
                    return h;
                }
            }
        }
        h = h.substr(1, h.size() - 2);
    }
}
string convert(string h){
    h = striped(h);
    int n = -1, n_priority = -1, z = 1;
    for (int i = 0; i < h.size(); i++) {
        char c = h[i];
        if (c == '(') {
            z++;
            continue;
        }
        if (c == ')') {
            z--;
            continue;
        }
        if (z != 1)
        continue;
        int priority = position_number(c);
        if (priority == -1)
        continue;
        if (n == -1 || priority <= n_priority) {
            n = i;
            n_priority = priority;
        }
    }
    return ((n == -1) ? h : convert(h.substr(0, n)) + " " + convert(h.substr(n + 1, h.size())) + " " + h.substr(n, 1));
}
int main(){
    ifstream cin; cin.open("input.txt");
    ofstream cout; cout.open("output.txt");
    vector<string> v; string h; getline(cin, h);
    h = convert(h) + " ";
    while (true) {
        if (h.find(' ') == -1) break;
        else {
            v.push_back(h.substr(0, h.find(' ')));
            h = h.substr(h.find(' ') + 1);
        }
    }
    while (true) {
        int i = -1;
        for (int j = 0; j < v.size(); j++) {
            if (fun(v[j])) {
                i = j; break;
            }
        }
        if (i != -1) {
            string ans = operand(v[i], v[i - 2], v[i - 1]);
            v.insert(v.begin() + i + 1, ans);
            v.erase(v.begin() + i - 2, v.begin() + i + 1);
        }
        else break;
    }
    cout << v[0];
}