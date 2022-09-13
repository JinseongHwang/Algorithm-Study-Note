//
// Created by JinseongHwang on 2022/09/13.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// meta data
const string inputExt = ".inp";
const string outputExt = ".out";

const char *getPath(string ext);

// globals

int main() {
    freopen(getPath(inputExt), "r", stdin);
    freopen(getPath(outputExt), "w", stdout);

    int testcase;
    cin >> testcase;

    while (testcase--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0, input; i < n; i++) {
            cin >> input;
            v[i] = input;
        }
        sort(v.begin(), v.end());

        long answer = 0;
        answer += v[v.size() - 1] + v[v.size() - 2];
        answer -= v[0] + v[1];

        cout << answer << '\n';
    }

    return 0;
}

enum Profile {
    TEST, SUBMIT,
};

// meta data
const Profile profile = SUBMIT;
const string problemNumber = "4";
const string problemName = "gain";
const int testNumber = 1;

const char *getPath(string ext) {
    string *path = new string();
    if (profile == TEST) {
        string filename = ext == outputExt ? "my" : to_string(testNumber);
        *path = "/Users/jinseonghwang/CLionProjects/algorithm/assignment/" + problemNumber + "/sampleData" + problemNumber + "/" + filename + ext;
        return path->c_str();
    } else if (profile == SUBMIT) {
        *path = problemName + ext;
        return path->c_str();
    }
    throw invalid_argument("Unsupported profile");
}