#include<iostream>
#include<string>
#include<map>

bool judge(char &word)
{
    if(word>='0'&&word<='9')
        return true;
    if(word>='a'&&word<='z')
        return true;
    if(word>='A'&&word<='Z')
    {
        word += 32;
        return true;
    }
    return false;
}

int main()
{
    std::string s, word;
    std::getline(std::cin, s);
    std::map<std::string, int> ans;
    int i = 0;
    while (i<s.size())
    {
        while (i<s.size()&&judge(s[i]))
        {
            word += s[i];
            i++;
        }
        if(word!="")
        {
            ans[word]++;
            word.clear();
        }
        while (i<s.size()&&!judge(s[i]))
        {
            i++;
        }
    }
    int max = 0;
    std::string t;
    for (std::map<std::string,int>::iterator it=ans.begin(); it!=ans.end(); it++)
    {
        if(it->second>max)
        {
            max = it->second;
            t = it->first;
        }
    }
    std::cout << t << " " << max;

    return 0;
}