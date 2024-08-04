#include<iostream>
using namespace std;
	

int lower_bound(int arr[],int n,int key){
	//Implement binary search
	int s = 0;
	int e = n - 1;
    int ans {-1} ;
	while(s<=e){
		int mid = (s+e)/2;

		if(arr[mid] == key){
			ans = mid;
            e = mid -1 ;
		}
		else if(arr[mid] > key){
			e = mid - 1;
		}
		else{

			s = mid + 1;
		}
	}

	return ans;
}
int upper_bound(int arr[],int n,int key){
	//Implement binary search
	int s = 0;
	int e = n - 1;
    int ans {-1} ;
	while(s<=e){
		int mid = (s+e)/2;

		if(arr[mid] == key){
			ans = mid;
            s = mid + 1 ;
		}
		else if(arr[mid] > key){
			e = mid - 1;
		}
		else{

			s = mid + 1;
		}
	}

	return ans;
}


int main(){

	int arr[] = {0 ,1,1,1,2,2,2,3,3,3,4};
	int n = sizeof(arr)/sizeof(int);

	int key;
	cin>>key;

	int index = upper_bound(arr,n,key);
	if(index!=-1){
		cout<<key <<" is present at index "<< index <<endl;
	}
	else{
		cout<<key <<" is NOT Found!" <<endl;
	}


	return 0;
}