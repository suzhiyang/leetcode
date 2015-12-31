#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>

using namespace std;

class LRUCache{
public:
    int c;
    list<pair<int, int> > l;
    unordered_map<int, list<pair<int, int> >::iterator > kl;
    
    LRUCache(int capacity) {
        c = capacity;
    }

    int get(int key) {
        if (kl.find(key) != kl.end())
        {
            l.push_front(*kl[key]);
            l.erase(kl[key]);
            kl[key] = l.begin();
            return (*kl[key]).second;
        }
        return -1;
    }

    void set(int key, int value) {
        if (kl.find(key) != kl.end())
        {
            l.erase(kl[key]);
        }
        else
        {
            if (kl.size() >= c)
            {
                kl.erase(l.back().first);
                l.pop_back();
            }
        }
        l.push_front(make_pair(key, value));
        kl[key] = l.begin();
    }
};

int main()
{
    LRUCache lc(3);
    cout<<lc.get(3)<<endl;
    lc.set(1,1);
    lc.set(2,2);
    lc.set(3,3);
    lc.set(4,4);
    cout<<lc.get(1)<<endl;
    cout<<lc.get(2)<<endl;
    cout<<lc.get(3)<<endl;
    cout<<"###################"<<endl;
    LRUCache tc1(1);
    lc.set(2,1);
    cout<<lc.get(2)<<endl;
}
