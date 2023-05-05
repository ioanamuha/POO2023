#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <queue>
struct Cmp {
    bool operator()(const std::pair<std::string, int>& left, const std::pair<std::string, int>& right) const {
        if (left.second == right.second)
            return left.first > right.first;
        else
            return left.second < right.second;
    }
};
int main()
{
   std::ifstream input ("item.txt");
    std::string s = "";
   if (input.is_open())
       std::getline(input, s);
   else {
        std::cout << "Error at opening the file";
        return 1;
   }
   std::map<std::string, int> m;
   std::string word = "";
   for (auto it = s.begin(); it != s.end(); ++it) {
        if (it == ' ' ||it == ','  *it == '.'  it == '!' ||it == '?') {
            if (!word.empty()) {
                m[word]++;
                word.clear();
            }
        } else {
            word.push_back(std::tolower(*it));
        }
   }
   if (!word.empty()) {
        m[word]++;
        word.clear();
   }
   std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, Cmp> q;
   for (const auto& pair : m)
       q.push(pair);
   while (!q.empty()) {
       std::cout << q.top().first << " => " << q.top().second << std::endl;
       q.pop();
   }
   return 0;

}
