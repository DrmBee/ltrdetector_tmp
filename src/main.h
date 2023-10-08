#include<unordered_map>
#include<string>
#include<map>

using namespace std;




extern string sequence;    //原始序列

//LTR存在范围，默认范围为100~6000
extern int minLenLTR;
extern int maxLenLTR;

struct node{
    int index;
    int distance;
};

struct node2{
    int distance;
    int ltrlen;
    bool keep;
};

extern unordered_map<string,struct node>hashtable; 
//key ：string ; value: int(index and distance)?
extern map<int,struct node2> index_map_distance;

//