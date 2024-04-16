#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string s1, string s2){
    int temp1 = stoi(s1+s2);
    int temp2 = stoi(s2+s1);
    
    return temp1 > temp2;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> nums;
    for(int num: numbers)
        nums.push_back(to_string(num));
    
    sort(nums.begin(), nums.end(), comp);
    for(string num: nums)
        answer += num;
    
    if(answer[0] == '0')
        answer = "0";
    
    return answer;
}