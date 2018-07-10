#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int largestRectangleArea(vector<int> A) {
	stack<int> s;
    int max_area=0,top,area_top;
    int i=0;
    while(i<A.size()) {
        if(s.empty() || A[s.top()]<=A[i]) s.push(i++);
        else {
            top=s.top();
            s.pop();
            area_top=A[top]*(s.empty() ? i:i-s.top()-1);
            max_area=max(max_area,area_top);
        }
    }
    while(!s.empty()) {
        top=s.top();
        s.pop();
        area_top=A[top]*(s.empty()?i:i-s.top()-1);
        max_area=max(max_area,area_top);
    }
    return max_area;
}
int main() {
	vector<int> v = {2, 1, 5, 6, 2, 3};
	cout<<largestRectangleArea(v)<<endl;
	return 0;
}
