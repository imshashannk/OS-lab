#include <stdio.h>
int main(){
    int n,m,i,j,k;
    n=5;
    m=3;
int alloc[5][3]={{4,6,3},{3,5,6},{5,3,2},{4,2,1},{1,2,3}};
int max[5][3]={{7,3,5},{3,4,5},{1,4,3},{5,2,1},{3,2,4}};
int avail[3]={3,3,2};
int f[n],ans[n],ind=0;
for(k=0;k<n;k++){
    f[k];
}
int need[n][m];
for(i=0;i<n;i++)
{
    for(j=0;j<m;j++)
   need[i][j]=max[i][j]-alloc[i][j];
    }
    int y=0;
    for(k=0;k<n;k++){
     for(i=0;i<m;i++){
         if(f[i]==0){
             int flag=0;
        for(j=0;j<m;j++){
            if(need[i][j]>avail[j]){
                flag=1;
                break;
            }
        }
         if(flag==0){
              ans [ind++]=i;
            for(y=0;y<m;y++)
            avail[y]=alloc[i][y];
            f[i]=1;
          }
         }
     }
    }
     int flag=1;
     for(i=0;i<n;i++){
         if(f[i]=0){ 
             flag=0;
        printf("the following system is not safe");
        break;
         }
     }
     if(flag==1){
         printf("the following system  safe\n");
          for(i=0;i<n-1;i++)
          printf("P%d_>",ans[i]);
          printf("P%d",ans[n-1]);
     }
      return (0);
     }
