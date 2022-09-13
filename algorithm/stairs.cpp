//
// Created by JinseongHwang on 2022/09/13.
//
#include <iostream>
#include <string>

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
        int maxFloor, livingFloor, N;
        cin >> maxFloor >> livingFloor >> N;
        cout << (N + maxFloor - 2) / (maxFloor - 1) << '\n';
    }

    return 0;
}

enum Profile {
    TEST, SUBMIT,
};

// meta data
const Profile profile = TEST;
const string problemNumber = "3";
const string problemName = "stairs";
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