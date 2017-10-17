//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>

using namespace std;
int cow[1005], a[1005][1005];

int main()
{
    int n, l[1005], m[1005], lar=0;
    int i, j, k;
    
    cin >> n;
    for(i=0;i<n;i++){
        cin >> l[i] >> m[i];
        for(j=0;j<m[i];j++){
            cin >> a[i][j];
        }
    }
    if(n==1){
        cout << l[0] << endl;
        return 0;
    }
    
    for(i=0;i<500;i++){
        for(j=0;j<n;j++){
            for(k=0;k<m[j];k++){
                if((cow[a[j][k]]==0 && (cow[j+1]!=0 || j==0)) || (cow[j+1]+l[j]<cow[a[j][k]] && cow[j+1]!=0)){
                    cow[a[j][k]]=cow[j+1]+l[j];
                }
            }
        }
    }
    for(i=2;i<=n;i++){
        cow[i]+=l[i-1];
    }
    for(i=2;i<=n;i++){
        if(cow[i]>lar)
            lar=cow[i];
    }
    
    cout << lar << endl;
    
    return 0;
}
