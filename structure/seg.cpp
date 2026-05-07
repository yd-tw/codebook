#define cl(x) (x<<1)
#define cr(x) (x<<1)+1
const int N;
int seg[4*N];
void pull(int id){
    seg[id]=max(seg[cl(id)],seg[cr(id)])
}
void build(int id,int l,int r){
    if(l==r){
        seg[id]=arr[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(cl(id),l,mid);
    build(cr(id),mid+1,r);
    pull(id);
}
void update(int id,int l,int r,int x,int v){
    if(l==r){
        seg[id]=v;
        return ;
    }
    int mid=(l+r)>>1;
    if(x<=mid){
        update(cl(id),l,mid,x,v);    
    }
    if(mid<x){
        update(cr(id),mid+1,r,x,v);  
    }
    pull(id);
}
int query(int id,int l,int r,int sl,int sr){
    if(sl<=l&&r<=sr){//目前這個區間在查詢區間內
        return seg[id];
    }
    int mid=(l+r)>>1,res=0;
    if(sl<=mid){//左區間跟查詢區間有交集
        res=max(res,query(cl(id),l,mid,sl,sr));
    }
    if(mid<sr){//右區間跟查詢區間有交集
        res=max(res,query(cr(id),mid+1,r,sl,sr));
    }
    return res;
}
struct node{
    int sum,pre,suf,ans;//總和、最大前綴、最大後綴、當前區間答案
}seg[4*N];
void pull(int id){
    int l=cl(id),r=cr(id);//左右兩個子區間的index
    seg[id].sum=seg[l].sum+seg[r].sum;
    seg[id].pre=max(seg[l].pre,seg[l].sum+seg[r].pre);
    seg[id].suf=max(seg[r].suf,seg[r].sum+seg[l].suf);
    seg[id].ans=max({seg[l].ans,seg[r].ans,seg[l].suf+seg[r].pre});
}