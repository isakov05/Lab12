#include <iostream>
#include <vector>
using namespace std;
int evenCount(const int* a, int size){
    int count=0;
    for(int i=0;i<size;i++){
        if(*a%2==0){
            count++;
        }
        a++;
    }
    return count;
}
int singleNumber(vector<int>& vec) {
    int n;
    for(int i=1;i<vec.size();i++){
        n=vec[0];
        if(n==vec[i]){
            vec.erase(vec.begin()+i);
            vec.erase(vec.begin());
            i=0;
        }
    }
    return vec[0];
}

void power(double* n,const int* p){
    int i=1;
    double num=*n;
    while(i<*p){
        *n*=num;
        i++;
    }
}

bool is_in(const int* arr1,const int* arr2, int size1,int size2){
    const int *p1=arr1;
    const int *p2=arr2;
    int sum=0;
    for(int i=0;i<size1;i++){
        for(int j=0;j<size2;j++){
            if(*p1==*p2){
                sum++;
                break;
            }
            p2++;
        }
        p1++;
        p2=arr2;
    }
    return (sum==size1);
}
bool is_mirrored(const int* a, const int* b,int size){
    for(int i=0;i<size;i++){
        if(*a!=*b){
            return false;
        }
        a++;
        b--;
    }
    return true;
}
void normalize(string &str){
    if(str[0]>='a'&&str[0]<='z'){
        str[0]-=32;
    }
    for (int i=1;i<str.length();i++) {
        if(str[i]>='A'&&str[i]<='Z'){
            str[i]+=32;
        }
    }
}

void sumArrays(const double* arr1,const double* arr2, double* sum,int size){
    for(int i=0;i<size;i++){
        *sum=*arr1+*arr2;
        sum++;
        arr1++;
        arr2++;
    }
}
void swap1(int* arr1,int* arr2,int size){
    int temp;
    for(int i=0;i<size;i++){
        temp=*arr1;
        *arr1=*arr2;
        *arr2=temp;
        arr1++;
        arr2++;
    }
}
vector<int> addOne(vector<int>& v) {
    long int n=v.size()-1;
    v[n]++;
    for(int i=n;i>=0;i--){
        if(v[i]>=10){
            if(i!=0){
                v[i]%=10;
                v[i-1]+=1;}
            else{
                v[i]%=10;
                v.insert(v.begin(),1);
            }
        }
    }
    return v;
}

int main()
{
    cout<<"Problem 1"<<endl;
    const int SIZE = 10;
    float *ptr, arr[SIZE];
    ptr = arr;
    while(ptr < arr+SIZE)
    {
        cin >> *ptr;
        *ptr=*ptr*0.3;
        ptr++;
    }
    ptr--;
    while(ptr >= arr)
    {
        cout << *ptr << ' ';
        ptr--;
    }
    cout<<"Problem 2 "<<endl;
    int n;
    cin>>n;
    int arrr[n];
    for(int i=0;i<n;i++){
        cin>>arrr[i];
    }
    cout<<evenCount(arrr,n);

    cout<<endl;
    cout<<"Problem 3"<<endl;
    cin>>n;
    int arr1[n];
    int arr2[n];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<n;i++){
        cin>>arr2[i];
    }
    cout<<is_mirrored(arr1,&arr2[4],5);
    cout<<endl;
    cout<<"Problem 4"<<endl;
    int size1;
    cin>>size1;
    double arrr1[size1];
    for(int i=0;i<size1;i++){
        cin>>arrr1[i];
    }
    double arrr2[size1];
    for(int i=0;i<size1;i++){
        cin>>arrr2[i];
    }
    double arrr3[size1];
    sumArrays(arrr1,arrr2,arrr3,size1);
    for(int i=0;i<size1;i++){
        cout<<arrr3[i]<<" ";
    }
    cout<<endl;
    cout<<"Problem 5"<<endl;
    cin>>size1;
    int arrs1[size1];
    for(int i=0;i<size1;i++){
        cin>>arrs1[i];
    }
    int arrs2[size1];
    for(int i=0;i<size1;i++){
        cin>>arrs2[i];
    }
    swap1(arrs1,arrs2,size1);
    for(int i:arrs1){
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i:arrs2){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Problem 6"<<endl;
    int size2;
    cin>>size1;
    int arrd1[size1];
    for(int i=0;i<size1;i++){
        cin>>arrd1[i];
    }
    cin>>size2;
    int arrd2[size2];
    for(int i=0;i<size2;i++){
        cin>>arrd2[i];
    }
    cout<<is_in(arrd1,arrd2,size1,size2);
    cout<<endl;
    cout<<"Problem 7"<<endl;
    double num;
    int p;
    cin>>num>>p;
    power(&num,&p);
    cout<<num;
    cout<<endl;
    cout<<"Problem 8"<<endl;
    vector<int> v={9,9,9};
    for(int i: addOne(v)){
        cout<<i;
    }
    cout<<endl;
    cout<<"Problem 9"<<endl;
    string s;
    cin>>s;
    normalize(s);
    cout<<s<<endl;
    cout<<"Problem 10"<<endl;
    vector<int> v2;
    int t;
    while(cin>>t){
        v2.push_back(t);
    }
    cout<<singleNumber(v);
    cout<<endl;

    return 0;
}

