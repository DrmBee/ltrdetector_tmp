#include<unordered_map>
#include<string>
#include<map>

using namespace std;

string sequence;    //原始序列

//LTR存在范围，默认范围为100~6000
int minLenLTR = 100;
int maxLenLTR = 6000;

struct node{
    int index;
    int distance;
};

unordered_map<string,struct node>hashtable; 
//key ：string ; value: int(index and distance)?
map<int,int> index_map_distance;
//
