vector<int> build_lps(string s){
    int n = s.size();
    vector<int> lps(n);
    for(int i=1,j=0;i<n;i++){
        while(j>0 && s[i]!=s[j]) j=lps[j-1];
        if(s[i]==s[j]) j++;
        lps[i]=j;
    }
    return lps;
}
