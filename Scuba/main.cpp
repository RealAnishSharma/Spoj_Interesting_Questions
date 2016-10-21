#include <bits/stdc++.h>

using namespace std;
int ZZ=INT_MAX-800000;
int wt[1001],vox[1001],vng[1001];
int n,marro[1001][22];int marrn[1001][80];

void mino(int b,int ox,int ng)
{
    if(b==n-1) {if(ox-vox[b]>0||ng-vng[b]>0) {if(ox>=0)marro[b][ox]=ZZ;if(ng>=0)marrn[b][ng]=ZZ;return;}
                else {if(ox>=0)marro[b][ox]=wt[b];if(ng>=0)marrn[b][ng]=wt[b];return;}}

    if(ox<0&&ng<0) return;

    if(ox-vox[b]<=0&&ng-vng[b]<=0)
    {
        if(marro[b+1][ox]==ZZ&&marrn[b+1][ng]==ZZ) mino(b+1,ox,ng);

        marro[b][ox]=min(wt[b],marro[b+1][ox]);
        marrn[b][ng]=min(wt[b],marrn[b+1][ng]);
        return;
    }
    if(ox-vox[b]>0&&ng<=0)
    {
        if(marro[b+1][ox-vox[b]]==ZZ&&marrn[b+1][ng-vng[b]]==ZZ) mino(b+1,ox-vox[b],ng-vng[b]);
        if(marro[b+1][ox]==ZZ&&marrn[b+1][ng]==ZZ) mino(b+1,ox,ng);
        marro[b][ox]=min(marro[b+1][ox-vox[b]]+wt[b],marro[b+1][ox]);
        return;
    }
    if(ox<=0&&ng-vng[b]>0)
    {
        if(marro[b+1][ox-vox[b]]==ZZ&&marrn[b+1][ng-vng[b]]==ZZ) mino(b+1,ox-vox[b],ng-vng[b]);
        if(marro[b+1][ox]==ZZ&&marrn[b+1][ng]==ZZ) mino(b+1,ox,ng);
        marrn[b][ng]=min(marrn[b+1][ng-vng[b]]+wt[b],marrn[b+1][ng]);
        return;
    }

    if(marro[b+1][ox-vox[b]]==ZZ&&marrn[b+1][ng-vng[b]]==ZZ) mino(b+1,ox-vox[b],ng-vng[b]);
    if(marro[b+1][ox]==ZZ&&marrn[b+1][ng]==ZZ) mino(b+1,ox,ng);

    marro[b][ox]=min(marro[b+1][ox-vox[b]]+wt[b],marro[b+1][ox]);
    marrn[b][ng]=min(marrn[b+1][ng-vng[b]]+wt[b],marrn[b+1][ng]);
    return;
}

int main()
{
    int c;
    scanf("%d",&c);
    while(c--)
    {
        int ox,ng,ans;
        scanf("%d %d %d",&ox,&ng,&n);
        for(int i=0;i<n;i++) scanf("%d %d %d",&vox[i],&vng[i],&wt[i]);

        for(int i=0;i<1001;i++)for(int j=0;j<22;j++)marro[i][j]=ZZ;
        for(int i=0;i<1001;i++)for(int j=0;j<80;j++)marrn[i][j]=ZZ;

        mino(0,ox,ng);

        if(marro[0][ox]>marrn[0][ng]) ans=marro[0][ox];
        else ans=marrn[0][ng];

        printf("%d\n",ans);
    }
    return 0;
}


/*
int mino(int b,int e,int ox,int ng)
{
    if(ox<=0&&ng<=0) return 0;
    if(b==e) {if(ox-vox[b]>0||ng-vng[b]>0)return INT_MAX;else return wt[b];}
    return min(mino(b+1,e,ox-vox[b],ng-vng[b])+wt[b],mino(b+1,e,ox,ng));
}
*/
