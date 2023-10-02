#include<bits/stdc++.h>
using namespace std;
const int N = 1000;

int n, frame_size, pages[N];

void LastRecentlyUsedReplacementAlogorithm(){
    unordered_set<int> s;
    unordered_map<int, int> indexs;
    int page_faults = 0;

    for(int i=0;i<n;i++){
        if(s.find(pages[i]) != s.end()){

        }else{
            if(s.size() < frame_size){
                s.insert(pages[i]);
                page_faults++;
            }else{
                int lru = INT_MAX, val;
                for(auto it: s){
                    if(indexs[it]< lru){
                        lru = indexs[it];
                        val = it;
                    }
                }
                s.erase(val);
                s.insert(pages[i]);
                page_faults++;
            }
        }
        indexs[pages[i]] = i;
    }

    cout<<"\nTotal Page Faults: "<<page_faults;
}

int main()
{
    LastRecentlyUsedReplacementAlogorithm();
}
