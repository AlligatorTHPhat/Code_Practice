#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Work
{
    private:
        int timeStart, timeEnd;
    public:
        Work() {}
        Work(int st, int ed)
        {
            timeStart = st;
            timeEnd = ed;
        }
    
        friend istream& operator >> (istream& is, Work& work)
        {
            is >> work.timeStart >> work.timeEnd;
            return is;
        }
        
        friend ostream& operator << (ostream& os, Work work)
        {
            os << work.timeStart << " " << work.timeEnd << "\n";
            return os;
        }
        
        int getSt() { return this->timeStart; }
        int getEd() { return this-> timeEnd; }
        void setSt(int st) { timeStart = st; }
        void setEd(int ed) { timeEnd = ed; }
        
        static bool compare(Work&a, Work& b)
        {
            return a.getEd() < b.getEd();
        }
};

int main()
{
    int n; cin >> n;
    
    vector<Work> works(n);

    for(int i = 0; i < n; i++)
        cin >> works[i];
        
    sort(works.begin(), works.end(), Work::compare);
    
    int cnt = 1;
    int lastTimeEnd = works[0].getEd();
    
    for(int i = 1; i < n; i++)
        if(works[i].getSt() >= lastTimeEnd)
        {
            lastTimeEnd = works[i].getEd();
            cnt++;
        }   
    cout << cnt << "\n";
    
    return 0;
}
