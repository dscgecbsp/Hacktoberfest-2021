include <bits/stdc++.h>
using namespace std;

int quickSort(vector<int> &V, int low, int high) {

    int pivot = V[low];
    int index = low;

    for (int i = low + 1; i <= high; i++) {

        if (V[i] <= pivot) {
            index += 1;
            swap(V[index], V[i]);
        }
    }

    swap(V[low], V[index]);
    return index;
}

void partition(vector<int> &V, int low, int high) {

    if (low < high) {

        int pos = quickSort(V, low, high);
        partition(V, low, pos - 1);
        partition(V, pos + 1, high);

    } else
        return;
}

int main() {

    // array size
    int N;
    cin >> N;
    // vector of size N
    vector<int> V(N);

    for (int i = 0; i < N; i++)
        cin >> V[i];

    partition(V, 0, N - 1);
    for (int i = 0; i < N; i++)
        cout << V[i] << " ";
    cout << "\n";

    return 0;
}
