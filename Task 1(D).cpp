#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int n,r,x,y,final_r;
	cin>>n>>r>>x>>y;

        //Dynamic arrays to store contest and SCN eating information
	int *contest = new int[n];
	int *scn = new int[n];
        final_r = r; //Final rating

	for(int i=0; i<n; i++)
	   cin>>contest[i];
	for(int i=0; i<n; i++)
	   cin>>scn[i];
	   
	for(int i=0;i<n;i++){
	    if(contest[i]==1){
	 	if(scn[i]==1)
	   	   final_r += x;  //Increasing rating as he would perform well in contest
		else  
		   final_r -= y;  //Decreasing rating otherwise
	     }
	 }
	
	 if(final_r > r)
	    cout<<"promoted";
	 else if(final_r < r)
	    cout<<"demoted";
	 else
	    cout<<"no change";
}
