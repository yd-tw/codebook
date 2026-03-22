# Codebook

#### 我隊友寫的 BIT

```cpp
#include <bits/stdc++.h>
using namespace std;
struct BIT{
    int n;
    vector<int> bit;
    void init(int a){
      n = a + 1;
      // n = (this->n)+1;
      // bit.resize(n);
      // fill(bit.begin(),bit.begin(),0);
      bit = vector<int> (n,0);
    }
    int lowbit(int x){
      if(x == 0){
        cerr << "you suck\n";
      }
      else return ((-x)&(x));
    }
    int query(int x){
        int ret = 0;
        for(;; n)
    }
}BIT;
```
