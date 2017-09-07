//Henry Allen
#include <iostream>

using namespace std;

const int n=10;
int counter=0;

void output(int arry[n]){
    for(int i=0;i<n;i++){
        cout<<arry[i]<<" ";
    }
    cout<<endl;
}

void Qsort(int p,int s,int e,int arry[n]){
    counter++;
    int f=p+1;
    int l=e;
    if(s==e){
        if(arry[p]>arry[s]){
            int temp=arry[p];
            arry[p]=arry[s];
            arry[s]=temp;
        }
    }
    else if(s<e){
        while(arry[p]>=arry[f]){
            f++;
        }
        while(arry[p]<arry[l]){
            l--;
        }
        if(f==e+1){
            int temp=arry[p];
            arry[p]=arry[e];
            arry[e]=temp;
            Qsort(p,s,e-1,arry);
        }
        else if(l==p){
            Qsort(p+1,s+1,e,arry);
        }
        else{
            if((l>f)&&(f<e)){
                int temp=arry[f];
                arry[f]=arry[l];
                arry[l]=temp;
                Qsort(p,s,e,arry);
            }
            else if((l<f)&&(l>p)){
                int temp=arry[p];
                arry[p]=arry[l];
                arry[l]=temp;
                Qsort(p,s,l-1,arry);
                Qsort(l+1,l+2,e,arry);
            }
        }
    }
}

int main(){
    int p,s,e;
    p=0;
    s=p+1;
    e=n-1;
    int arry[n]={15,22,28,2,45,1235,4,123,12,22};
    Qsort(p,s,e,arry);
    output(arry);
    cout<<"count: "<<counter<<endl;
    return 0;
}
