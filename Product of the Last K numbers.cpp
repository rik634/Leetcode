//level: medium
//link: https://leetcode.com/problems/product-of-the-last-k-numbers/description/?envType=daily-question&envId=2025-02-14
//solution

class ProductOfNumbers {
public:
    vector<int> v;
    ProductOfNumbers() {
        v.clear();
        
    }
    
    void add(int num) {
        v.push_back(num);
    }
    
    int getProduct(int k) {
        int p=1;
        int index=v.size()-1;
        while(k>0)
        {
            p=p*v[index];
            index--;
            k--;
        }
        return p;
    }
};
