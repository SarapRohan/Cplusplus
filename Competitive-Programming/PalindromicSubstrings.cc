#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "aabcacbaa";
    
    size_t n = s.length();
    //expand around centre
    for (int center = 0; center <= 2*n-1; center++) {
        int left = center / 2;
        int right = left + center % 2;
        while(left >= 0 and right < n and s[left] == s[right]) {
            cout<<s.substr(left, right - left + 1)<<endl;
            left--;
            right++;
        }
    }
    
    int res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; i - j >=0 and i + j < n
            and s[i - j] == s[i + j]; j++)          
                res++;
        for(int j = 0; i - j - 1 >= 0 and
            i + j < n and 
            s[i - j -1] == s[i + j]; j++) 
                res++;
    }
    cout<<res<<endl;
    
    return 0;
}
