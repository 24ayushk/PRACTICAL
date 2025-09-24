#include<stdio.h>
#include<string.h>
#define Max 100

void printCost(char a[],char b[],int x,int y,int cost[Max][Max],char dir[Max][Max]) {
    printf("      ");
    for(int j = 0; j < y; j++) {
        printf(" %c  ", b[j]);
    }
    printf("\n");

    for(int i = 0; i <= x; i++) {
        if(i == 0) 
            printf("  ");
        else
            printf("%c ", a[i-1]);

        for(int j = 0; j <= y; j++) {
            printf("%2d%c ", cost[i][j], dir[i][j]);
        }
        printf("\n");
    }
}


void printLCS(char a[],char b[],int i, int j,int cost[Max][Max],char dir[Max][Max]){
        if(i==0||j==0) return;
        else{
            if(dir[i][j]=='D'){
                printLCS(a,b,i-1,j-1,cost,dir);
                printf("%c",a[i-1]);
            }
            else if(dir[i][j]=='S'){
                printLCS(a,b,i,j-1,cost,dir);
            }
            else{
                printLCS(a,b,i-1,j,cost,dir);
            }
        }
} 

void LCS(char a[],char b[],int x,int y){

    int cost[Max][Max];
    char dir[Max][Max];

    for (int i = 0; i <= x; i++){
        cost[i][0]=0;
        dir[i][0]='-';
    }
    for (int j = 0; j <= y; j++){
        cost[0][j]=0;
        dir[0][j]='-';
    }

    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            if(a[i-1]!=b[j-1]){
                if(cost[i][j-1]>=cost[i-1][j]){
                    cost[i][j]=cost[i][j-1];
                    dir[i][j]='S';
                }
                else{
                    cost[i][j]=cost[i-1][j];
                    dir[i][j]='U';
                }
            }
            else{
                cost[i][j]=1+cost[i-1][j-1];
                dir[i][j]='D';
            }
        }
    }
    printf("Length of longest common subsequence is : %d\n",cost[x][y]);
    printf("Longest common subsequence : ");
    printLCS(a,b,x,y,cost,dir);
    printf("\n\n\n");
    printCost(a,b,x,y,cost,dir);
}

int main(){
    char a[]= "AGCCCTAAGGGCTACCTAGCTT";
    char b[]="GACAGCCTACAAGCGTTAGCTTG";
    int x=strlen(a);
    int y=strlen(b);
    LCS(a,b,x,y);
    return 0;
}