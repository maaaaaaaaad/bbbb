#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int index=0;
map<string, int> m;
vector<int>cnt_menu;
int course_cnt;

void make_menu(int length, string order, int cnt, int point, string &word, vector<int>visited){
    if(cnt==length){
        if(m.find(word)==m.end()){
            m[word]=index;
            index++;
            cnt_menu.push_back(1);
            cout<<word<<" ";
        }
        else{
            cnt_menu[m[word]]++;
        }
        if(course_cnt<cnt_menu[m[word]])
            course_cnt=cnt_menu[m[word]];
        return;
    }
    
    for(int i=point; i<order.size(); i++){
        if(visited[i]==1)
            continue;
        visited[i]=1;
        word+=order[i];
        make_menu(length,order,cnt+1,i,word,visited);
        visited[i]=0;
        word.pop_back();
    }
}


vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    string word;
    vector<int>visited(21,0);
    vector<int>cnt_max(course.size(),0);
    string copy;
    
    map<string, int>::iterator itr;
    
    for(int i=0; i<orders.size(); i++){
        sort(orders[i].begin(), orders[i].end());
        for(int j=0; j<course.size(); j++){
            if(course[j]>orders[i].size())
                break;
            course_cnt=0;
            make_menu(course[j], orders[i], 0, 0, word, visited);
            if(cnt_max[j]<course_cnt)
                cnt_max[j]=course_cnt;
        }
    }    
      
    for(itr=m.begin(); itr!=m.end(); itr++){
        string a=itr->first;
        index=itr->second;
        
        for(int j=0; j<course.size(); j++){
            if(course[j]==a.size() && cnt_max[j]==cnt_menu[index]&& cnt_max[j]>1 )
                answer.push_back(a);
        }
    }
    
    return answer;
}