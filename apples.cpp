#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> searchApples(vector<int>& appleWeights, int share) {
    sort(appleWeights.begin(), appleWeights.end(), greater<int>());
    vector<int> ans;
    int currentSum = 0;

    for (int i = 0; i < appleWeights.size(); i++) {
        if (currentSum + appleWeights[i] <= share) {
            currentSum += appleWeights[i];
            ans.push_back(appleWeights[i]);
        }
    }

    return ans;
}

void findShares(vector<int>& appleWeights, vector<int>& ram, vector<int>& sham, vector<int>& rahim) {
    int totalWeight = 0;
    for (int i = 0; i < appleWeights.size(); i++) {
        totalWeight += appleWeights[i];
    }

    int ramShareInGrams = (50.0 / 100.0) * totalWeight;
    int shamShareInGrams = (30.0 / 100.0) * totalWeight;
    int rahimShareInGrams = (20.0 / 100.0) * totalWeight;

    ram = searchApples(appleWeights, ramShareInGrams);
    for (int weight : ram) {
        auto it = find(appleWeights.begin(), appleWeights.end(), weight);
        if (it != appleWeights.end()) {
            appleWeights.erase(it);
        }
    }

    sham = searchApples(appleWeights, shamShareInGrams);
    for (int weight : sham) {
        auto it = find(appleWeights.begin(), appleWeights.end(), weight);
        if (it != appleWeights.end()) {
            appleWeights.erase(it);
        }
    }

    rahim = searchApples(appleWeights, rahimShareInGrams);
}

void printValues(const vector<int>& vct) {
    for (int i = 0; i < vct.size(); i++) {
        cout << vct[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> appleWeights;
    int weight;
    cout << "Enter apple weight in gram (-1 to stop): ";
    cin >> weight;
    while (weight != -1) {
        appleWeights.push_back(weight);
        cout << "Enter apple weight in gram (-1 to stop): ";
        cin >> weight;
    }

    vector<int> ram;
    vector<int> sham;
    vector<int> rahim;

    findShares(appleWeights, ram, sham, rahim);

    
    cout << "Ram: ";
    printValues(ram);

    cout << "Sham: ";
    printValues(sham);

    cout << "Rahim: ";
    printValues(rahim);

    return 0;
}
