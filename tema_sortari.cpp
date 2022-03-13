#include <bits/stdc++.h>

using namespace std;

ifstream f("input.in");

vector<int> res;
vector<int> v;
int t, i;

void mergesort(vector<int> &v, int l, int r){
    if(l<r)
    {
        int mid = (l+r)/2;
        mergesort(v, l, mid);
        mergesort(v, mid+1, r);
        merge(v.begin() + l, v.begin() + mid + 1, v.begin() + mid + 1, v.begin() + r + 1, res.begin());
    }

}
void shellSort(vector<int> &v)
{
	for (int gap=v.size()/2; gap>=1; gap= gap/2)
	{
		for (int i=gap; i<v.size(); i++)
		{
			for (int j=i-gap; j>=0; j=j-gap)
			    if(v[j+gap]>v[j])
			    {break;}
			    else{
			        swap(v[i],v[j]);
			    }
		}
	}
}

void countsort(vector<int> &v){

    int n=v.size();
    vector<int> fr(v.size()), rez(v.size());
    for (int i = 0; i < n; i++)
        fr[v[i]]++;
  
    for (int i = 1; i < fr.size(); i++)
        fr[i] += fr[i - 1];
  
    for (int i = n - 1; i >= 0; i--)  {
        rez[fr[v[i]] - 1] = v[i];
        fr[v[i]]--;
    }
    for (int i = 0; i < n; i++)
        v[i] = rez[i];
}

void countsort_with_exp(vector<int> &v, int exp)
{
    vector<int> fr(10), rez(v.size());
    
    for (int i = 0; i < v.size(); i++)
        fr[(v[i]/exp) % 10]++;
 
    for (int i = 1; i < 10; i++)
        fr[i]=fr[i - 1]+fr[i];
 
    for (int i = v.size() - 1; i >= 0; i--) {
        rez[fr[(v[i]/exp) % 10] - 1] = v[i];
        fr[(v[i]/exp) % 10]--;
    }
    for (int i = 0; i < v.size(); i++)
        v[i] = rez[i];
}
void radixsort(vector<int> &v){
    int maxim = *max_element(v.begin(), v.end());
    for (int exp=1; maxim/exp>0; exp=exp*10)
        countsort_with_exp(v, exp);
}

void bubblesort(vector<int> &v){
    bool swp = true;
      while(swp){
        swp = false;
        for (int i = 0; i < v.size()-1; i++) {
            if (v[i]>v[i+1] ){
                {swap(v[i], v[i+1]);
                swp = true;}
            }
        }
    }
}

void nativesort(vector<int> &v){
    sort(v.begin(), v.end());
}

void sorting(string algoritm, vector<int> v){
    auto begin = std::chrono::high_resolution_clock::now();

    if(algoritm=="shell") 
        shellSort(v);
        
    else if(algoritm=="merge") {
        res.resize(v.size());
        mergesort(v, 0, v.size()-1);
    }
    
    else if(algoritm=="radix") 
        radixsort(v);
        
    else if(algoritm=="count") 
        countsort(v);
        
    else if(algoritm=="bubble") 
        {   if(v.size()>10000)
                {cout<<'\n'<<"Too many numbers for bubblesort";
                return;}
            else if(v.size()<=10000)
                bubblesort(v);
            
        }
        
    else if(algoritm=="native") 
        nativesort(v);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    cout<< "\n"+algoritm+" sort takes -> "<< elapsed.count() << " nanoseconds";
}

int main() {
    cout<<"Wait for the sortings:";
    f>>t;
    int i=1;
    while(i<=t){
        int n, max;
        f>>n>>max;
        for(int i=0;i<n;i++)
            v.push_back(rand()%max);
            
        cout<<'\n';
        cout<<'\n';
        cout<<"List number "<<i<<":"<<'\n';
        
        sorting("shell", v);
        sorting("merge", v);
        sorting("radix", v);
        sorting("count", v);
        sorting("bubble", v);
        sorting("native", v);
        i++;
    }

    return 0;
}