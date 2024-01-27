#include <iostream>
#include <vector>

using namespace std;

int main() {

    string message;
    getline(cin, message);
    int storeBytes[message.size()]; //array for storing byte message

    cout << message << endl;

    vector<int> toBytes(message.begin(), message.end());

    for (int i = 0; i < toBytes.size(); i++) {

        storeBytes[i] = (int)toBytes[i];
        cout << storeBytes[i] << endl;

    }

    return 0;
}