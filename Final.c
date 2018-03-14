#include<stdio.h>

int main()
{
int i,j,A[8],B[92][8],C[8][8],s,g,flag,end,c,k,l,m,issame,exit;

for(i=0;i<=7;i++){A[i]=16;for(j=0;j<=91;j++){B[j][i]=0;}}
c=0;
s=0;
g=0;
end=0;

do{
flag=1;

if((g==0)&&(s==8)){for(i=0;i<=7;i++){/*printf("[%d] ",A[i]);*/B[c][i]=A[i];}c++;s=s-2;g=A[s]+1;A[7]=16;A[6]=16;/*printf("%d\n",c);*/}

if((s==0)&&(g==8)){end=1;}

if(s>0){for(i=0;i<=(s-1);i++){if((g==A[i])||(g==A[i]+(s-i))||(g==A[i]-(s-i))){flag=0;}}}
else{flag=1;}

if(g==8){A[s]=16;s--;g=A[s];}
else if(flag==1){A[s]=g;s++;g=-1;}

g++;
}while(end==0);

for(k=0;k<=90;k++){
if(B[k][0]!=16){
for(i=0;i<=7;i++){C[0][i]=B[k][i];C[1][7-B[k][i]]=i;C[2][7-i]=7-B[k][i];C[3][B[k][i]]=7-i;
		  C[4][7-i]=B[k][i];C[5][i]=7-B[k][i];C[6][7-B[k][i]]=7-i;C[7][B[k][i]]=i;}
for(l=91;l>k;l--){for(m=1;m<=7;m++){issame=1;for(i=0;i<=7;i++){if(B[l][i]!=C[m][i]){issame=0;}}if(issame==1){for(i=0;i<=7;i++){B[l][i]=16;}}}}
	       }
                  }
for(i=0;i<=91;i++){if(B[i][0]!=16){for(j=0;j<=7;j++){printf("[%d] ",B[i][j]);if(j==7){printf("\n");}}}}
exit=0;
do{printf("Enter 1 to exit: ");scanf("%d",&exit);}while (exit==0);

return 0;
}
