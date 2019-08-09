#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {

    vector<string> data = {"Hello World!", "Goodbye World!"};

    for (string d : data) {
        cout << d << endl;
    }
//	for (vector<string>::iterator t = data.begin(); t != data.end(); ++t) {
//		cout << t->c_str() << endl;
//	}
    return 0;
}
