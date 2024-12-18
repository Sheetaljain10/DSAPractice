#include <bits/stdc++.h>
using namespace std;

bool fun(string a, string b){
    // sort(a.begin(),a.end()); // TC: O(nlogn) SC: O(1);
    // sort(b.begin(),b.end()); // 
    map<int,int>p; // TC: O(N) SC: O(N);
    int n1 = a.length(), n2 = b.length();
    if(n1!=n2)return false;
    for(int i=0;i<n1;i++){ 
        p[a[i]]++;
        p[b[i]]--;
    }
    
    for(auto x:p){
        if(x.second!=0)return false;
    }
    return true;
}

vector<int> fun1(vector<vector<int>>& a){
    //TC: O(N), SC: O(N)
    if(a.empty())return {};
    unordered_set<int> common(a[0].begin(),a[0].end()); // To convert vector to set.
    
    for(int i=1;i<a.size();i++){
        unordered_set<int> curr(a[i].begin(),a[i].end());
        for(auto j = common.begin();j!= common.end();){
            if(curr.find(*j) == curr.end()){
                j = common.erase(j);
            }
            else{
                j++;
            }
        }
    }
    return vector<int> (common.begin(),common.end());
}

string fun2(string s){
    string s1 = "";
    vector<string>p;
    for(int i=0;i<s.length();i++){
        if(s[i]!=' '){
            s1+=s[i];
        }
        else{
            p.push_back(s1);
            s1 = " ";
        }
    }  

    if(!s1.empty()){
        p.push_back(s1);
    }  

    sort(p.begin(),p.end());
    s1 = "";
    for(auto i:p){
        s1 += i;
        s1 += ' ';
    }
    return s1;
}

string fun3(string s){
    string dup="", unique = "", grouped = "";
    unordered_map<char,int>p;
    for(auto i : s)p[i]++;

    for(auto& [c, count] : p){
        if(count>1) dup+=c;
        else unique += c;
        grouped += string(count,c);
    }

    return dup + " | "+ unique + " | " + grouped;
}

int GCD(int a, int b){
    return b? GCD(b,a%b):a;
}

string rev_fun(string s){
    if(s.empty()) return "";
    return rev_fun(s.substr(1)) + s[0];
}

void rev_arr(vector<int>& v, int l, int r){
    if(l<r){
        swap(v[l],v[r]);
        rev_arr(v,l+1,r-1);
    }
}

bool fun4(string s){
    unordered_set<char>p;
    for(auto i:s)
        if(i!=' ') p.insert(tolower(i));
    return p.size() == 26;
}
int main()
{
    vector<vector<int>> a = {
        {1,2,3,4,5},
        {4,5,8,3,6,11},
        {11,31,5,4}
    };
    cout<<fun("listen","silent")<<endl;
    vector<int> res = fun1(a);
    for(auto i:res) cout<<i<<" ";
    cout<<endl;

    string s = "This is a wonderfull morning with sun above head";
    cout<<fun2(s)<<endl;

    string s1 = "geeks for geeks";
    cout<<fun3(s1)<<endl;

    int num1 = 39, num2 = 117;
    cout<<GCD(num1,num2)<<endl;

    cout<<rev_fun(s1)<<endl;

    vector<int>arr = {1,2,3,4,5};
    rev_arr(arr,0,arr.size()-1);
    for(int i:arr){
        cout<<i<<" ";
    }

    string s2 = "The quick brown fox jumps over the lazy dog";
    cout<<'\n'<<(fun4(s2)?"TRUE":"FALSE");

    return 0;
}