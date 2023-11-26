#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int countABC(string fname) {
    ifstream file(fname);
    if (!file.is_open()) {
        cout << "Cannot open file.\n";
        return -1;
    }

    string str;
    int count = 0;

    while (getline(file, str)) {
        size_t pos = str.find("abc");
        while (pos != string::npos) {
            count++;
            pos = str.find("abc", pos + 1);
        }
    }

    file.close();
    return count;
}

int main() {
    string fname;
    cout << "Type filename: ";
    cin >> fname;

    int count = countABC(fname);
    if (count != -1) {
        cout << "Count of 'abc': " << count << endl;
    }

    return 0;
}
