class MedianFinder {
private:
    multiset<int> mul_set;
    multiset<int>::iterator itrtr = mul_set.begin();
    bool checkodd = false;
    
public:
    MedianFinder() {}
    
    void addNum(int num) {
        mul_set.insert(num);
        checkodd = !checkodd;
        
        if (mul_set.size()==1 || (!checkodd && (*itrtr) <= num)) itrtr++;
        if (checkodd && (*itrtr) > num) itrtr--;
    }
    
    double findMedian() {
        return (checkodd)? *itrtr : (*itrtr + *prev(itrtr)) / 2.0;
    }
    
};
