#include <bits/stdc++.h>
using namespace std;
int countA[26];
int out=0;
int countB[26];
vector <int> op;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a;
    cin>>a;
    string l;
    cin>>l;
    memset(countA, 0, 25);
    memset(countB,0,25);
    long long nowhash=0;
    if(a.length()>l.length()){
        cout<<0;
        return 0;
    }
    long long h=1;
    for(int i=0;i<a.length()-1;i++){
        countA[int(a[i] - 97)]++;
        nowhash+=long(long(l[a.length()-i-1]-97) * h);
        nowhash%=2000003353;
        h= (h * 31) % 2000003353;
    }
    countA[int(a[a.length() - 1] - 97)]++;
    nowhash+=long(long(l[0]-97) * h);
    nowhash%=2000003353;
    for(int i=0;i<a.length();i++){
        countB[int(l[i]-97)]++;
    }
    bool k;
    for(int cur=0;cur+a.length()<=l.length();cur++){
        k=true;
        for(int i=0;i<26;i++){
            if(countA[i] != countB[i]){
                k=false;
                break;
            }
        }
        if(k){
            out++;
            op.push_back(nowhash);
        }
        if(cur+a.length()!=l.length()){
            countB[int(l[cur]-97)]--;
            countB[int(l[cur+a.length()]-97)]++;
            nowhash-=long(long(l[cur]-97) * h);
            nowhash*=31;
            nowhash+=long(l[cur+a.length()]-97);
            nowhash%=2000003353;
            if(nowhash<0){
                nowhash+=2000003353;
            }
        }
    }
    sort(op.begin(),op.end());
    for(int i=1;i<op.size();i++){
        if(op[i]==op[i-1]){
            out--;
        }
    }
    cout << out;
}