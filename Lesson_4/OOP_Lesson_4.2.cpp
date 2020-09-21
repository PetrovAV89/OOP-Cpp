#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

void print(vector<int>& arr) {
    cout << "The length is: " << arr.size() << '\n';
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';

    cout << endl;
}

void different(vector<int>& arr) {
    int count = 1;
    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i] != arr[i + 1])
            count++;
    }
    cout << "Different numbers in the vector: " << count << endl << endl;
}

int main() {
	vector<int> array {3, 4, 6, 2, 4, 7, 8, 2, 8, 2, 9};
    print(array);

    sort(array.begin(), array.end());
    different(array);

	return 0;
}