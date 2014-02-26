#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string cur, r;
        stack<string> s;
        path += '/';
        for (int i = 0; i < path.size(); ++i)
        {
            if (path[i] == '/')
            {
                if (cur == "..") {if (!s.empty()) s.pop();}
                else if (cur != "." && cur != "") s.push(cur);
                cur = "";
            }
            else cur = cur + path[i];
        }
        r = "";
        while(!s.empty())
        {
            r = "/" + s.top() + r;
            s.pop();
        }
        if (r == "") r = "/";
        return r;
    }
};

int main()
{
    Solution s;
    string str = "/a/./b/../../c/";
    cout<<str<<"    "<<s.simplifyPath(str)<<endl;
    str = "/home/";
    cout<<str<<"    "<<s.simplifyPath(str)<<endl;
    str = "./home/dd/";
    cout<<str<<"    "<<s.simplifyPath(str)<<endl;
    str = "./home/../dd/kdjf/..";
    cout<<str<<"    "<<s.simplifyPath(str)<<endl;
    str = "/../";
    cout<<str<<"    "<<s.simplifyPath(str)<<endl;
    str = "/home//foo/";
    cout<<str<<"    "<<s.simplifyPath(str)<<endl;
}
