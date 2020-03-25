#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

// to find the unique no in a set where each no occur twice except one no.
void unique_number(){
    int y=0;
    vector<int> g={1,2,3,4,3,2,1};
    for(int c:g)
        y^=c;
    cout<<"unique element = "<<y; 
}

// to find how many bits to change in 'a' to make a number 'b'
void bit_change_count(){
    int a=10; // 10 = 1010
    int b=13; // 13 = 1101
    int ans = a^b;
    int count=0;
    while(ans){ 
        count+=(ans&1);
        ans=ans>>1;
    }
    cout<<"\ncount = "<<count;
}

void bit_change_count_fast(){
    int count=0;
    int a=10; // 10 = 1010
    int b=13; // 13 = 1101
    int ans=a^b;
    while(ans){
        count++;
        ans=ans&(ans-1);
    }
    cout<<"\ncount = "<<count;
}

// find if ith bit of a number is '1' or '0'.
void get_ith_bit(int n, int i){ // n = 10 -> 1010
    n = (n>>i & 1)==1 ? 1 : 0;
    cout<<"\ni'th bit = "<<n;
}

// to flip the i'th bit of a number
void flip_ith_bit(int n, int i){
    int mask = 1<<i;
    cout<<"\nith bit flipped "<<n; // 10 = 1010
    n=(n ^ mask);                  //        |
    cout<<"\nith bit flipped "<<n;  // 8 = 1000
}

// print all subsets of a string
void all_subsets(){
    string a;
    cin>>a;
    int len=a.length();
    for(int i=0;i<pow(2,len);i++){
        int current_bit=i;
        for(int j=0;j<len;j++){
            if(current_bit&1){
                cout<<a[j]<<" ";   
            }
            current_bit=current_bit>>1;
        }
        cout<<"\n";
    }
}

int main(){
    int a=10,b=10;
    a=a<<1; // left shift means multiplying 'a' by 2^bit .
    b=b>>1; // left shift means dividing 'a' by 2^bit .
    cout<<a<<endl;
    cout<<b<<endl;
    
    unique_number();
    
    bit_change_count();
    
    bit_change_count_fast();
    
    get_ith_bit(10, 0);  
    
    flip_ith_bit(10, 1);
    
    all_subsets();
    
    // two_unique_numbers();
    
    return 0;
}

