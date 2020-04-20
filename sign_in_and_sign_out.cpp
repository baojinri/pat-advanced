#include<iostream>
#include<string>
struct record
{
    std::string name;
    std::string sign_in;
    std::string sign_out;
};
int main()
{
    int M;
    std::cin >> M;
    record *r = new record[M];
    for (int i = 0; i < M; i++)
    {
        std::cin >> r[i].name >> r[i].sign_in >> r[i].sign_out;
    }
    std::string estr, lstr,temp_in,temp_out;
    temp_in = "23:59:59", temp_out = "00:00:00";
    for (int i = 0; i < M; i++)
    {
        if(temp_in>r[i].sign_in)
            estr = r[i].name,temp_in=r[i].sign_in;
        if(temp_out < r[i].sign_out)
            lstr = r[i].name,temp_out=r[i].sign_out;
    }
    std::cout << estr << " " << lstr << std::endl;
    system("pause");
    return 0;
}


#include<iostream>
#include<string>
int main(){
    int M;
    std::cin >> M;
    std::string estr,lstr,sign_in,sign_out,temp_in,temp_out,name;
    temp_in="23:59:59",temp_out="00:00:00";
    for (int i = 0; i < M; i++)
    {   std::cin>>name>>sign_in>>sign_out;
        if(sign_in<temp_in) temp_in=sign_in,estr=name;
        if(sign_out>temp_out) temp_out=sign_out,lstr=name;}
    std::cout << estr << " " << lstr << std::endl;}