#include<bits/stdc++.h>

using namespace std;

int main(){
	
	//Placed 8 at the end and 16 at the beginning of the array to avoid the confusion when one of 
	// the numbers (in the product a[x]*a[y]) is 16 (product will also be divisible by 8)
	//But still 80 will be a problem (divisible by 16 but expected pair is 10,8)
	
	int arr1[] = {16,10,7,9,43,8};
	int *a,product,result[6];
	a = new int[2];
	for(int i=0;i<=4;i++){
	 
	    //query asked using positions (not indices)
	    printf("%d %d\n",i+1,i+2);
	    fflush(stdout);
		scanf("%d",&product);
		int k=0;
		
		//The resulting array is considered as two halves with size 3 each
		for(int j=0;j<6;j++){
			if(product%arr1[j]==0){
				a[k] = arr1[j];
				k++;
			}
			if(k==2)
			  break;
	    }
	    
	    //The only case where 16 interferes (undesirable)
	    if(product == 80){
	    	a[0] = 8;
	    	a[1] = 10;
		}
        
		
		//Storing the first two numbers disregarding their actual order	
		if(i%3==0){
	   		result[i]=a[0];
	    	result[i+1]=a[1];
	    }
    	
    	//Finding the order in which the 3 numbers 
		// (of one half of the resultant array) appear and storing them 
		else{
	   		if(result[i]==a[0])
	    	  result[i+1] = a[1];
    		else if(result[i]==a[1])
	   		  result[i+1] = a[0];
	   		else{
	   			int t = result[i-1];
	   			result[i-1] = result[i];
    			result[i] = t;
		
    			if(result[i]==a[0])
	   		      result[i+1] = a[1];
	        	else if(result[i]==a[1])
		          result[i+1] = a[0];
	   		}
	    }
	   	
		if(i==1)
            i++; //Because of queries
              
    }
    
    //Output
    for(int i=0; i<6; i++){
	    printf("%d ",result[i]);
	    fflush(stdout);
	}
		
}
	
