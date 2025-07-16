#include<iostream> 
#include<vector> 
#include<set> 
#include<unordered_map> 
#include<algorithm> 
#include<map>

using namespace std; 

class Solution{
public: 
     vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website){
       vector<tuple<int, string, string>> data; 
       int m = username.size(); 
       
       for(int i=0; i<m; ++i){
         data.emplace_back(timestamp[i], username[i], website[i]); 
       }
       sort(data.begin(), data.end()); 

       unordered_map<string, vector<string>> userSites; 

       for(auto [time, user, site]:data){
         userSites[user].push_back(site); 
       }
       map<vector<string>, int> freqSites; 
       for(auto [user, sites]: userSites){
         int m = sites.size(); 
         set<vector<string>> seen; 
         for(int i=0; i<m; ++i){
           for(int j=i+1; j<m; ++j){
             for(int k=j+1; k<m; ++k){
               seen.insert({sites[i],sites[j],sites[k]}); 
             }
           }
         }
         for(auto seq:seen){
           freqSites[seq]++; 
         }
       }
       vector<string> res; 
       int maxFreq = 0; 
       for(auto [patt, freq]: freqSites){
         if(freq> maxFreq || (maxFreq == freq && patt < res)) {
           res = patt; 
           maxFreq = freq; 
         } 
         
       }
       return res; 
       
     }
};
int main(){
  vector<string> username = {"joe","joe","joe","james","james","james","james","mary","mary","mary"}; 
  vector<int> timestamp = {1,2,3,4,5,6,7,8,9,10}; 
  vector<string> sites = {"home","about","career","home","cart","maps","home","home","about","career"};
  Solution sol; 
  vector<string> res= sol.mostVisitedPattern(username, timestamp, sites); 
  for(string s: res){
    cout <<  s << "," ; 
    
  }
  cout << endl; 
  return 0; 
}
