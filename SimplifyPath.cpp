class Solution {
public:
    string simplifyPath(string path) {
        if (path == "") return "";
        deque<string> dq;
        string t, r;
        size_t cur = path.find_first_of("/"), pos;
        while(cur != string::npos)
        {
            pos = path.find_first_of("/", cur + 1);
            if (pos != string::npos) t = path.substr(cur + 1, pos - cur - 1);
            else t = path.substr(cur + 1);
            if (t == "..") {if (!dq.empty()) dq.pop_back();}
            else if (t != "." && t != "") dq.push_back(t);
            cur = pos;
        }
        while(!dq.empty())
        {
            r = r + "/" + dq.front();
            dq.pop_front();
        }
        if (r == "") return "/";
        return r;
    }
};
