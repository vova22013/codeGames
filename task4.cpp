#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n; 
    cin >> n; cin.ignore();
    int closestTemp = 5526;
    if (n == 0) closestTemp = 0;
    bool positive = true;
    
    for (int i = 0; i < n; i++) {
        int t; 
        cin >> t; cin.ignore();
        
        if (abs(t) < closestTemp) {
            closestTemp = abs(t);
            if (t < 0) positive = false;
            else positive = true;
        }
        else if (abs(t) == closestTemp && positive==false && t > 0){
            positive = true;
        }
    }

    if (positive) cout << closestTemp << std::endl;
    else cout << -closestTemp << std::endl;
    
}
