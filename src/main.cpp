/*
 * score the input sequence
 *
 * 对输入序列进行score
 * 
*/
#include<fstream>
#include<iostream>
#include<vector>
#include<typeinfo>
#include<string>
#include<unordered_map>

#include"main.h"
#include"score.h"

using namespace std;

/* 一些全局变量 */
string sequence;    //原始序列

//LTR存在范围，默认范围为100~6000
int minLenLTR = 10;
int maxLenLTR = 20;

unordered_map<string,struct node>hashtable; 
//key ：string ; value: int(index and distance)?
map<int,struct node2> index_map_distance;
//字典，记录更新hash过程中的distance和index对应的值

int main(int argc,char **argv)
{
    //打开文件
    //example: rabidopsis_thaliana.TAIR10.dna.chromosome.Pt.fa.gz
    ifstream infile;
    infile.open(argv[1]);
    cout<<"******************************************"<<endl;
    cout<<"The path is:"<<argv[1]<<endl;
    if(!infile.is_open()){
        cout<<"Opening file failed!"<<endl;
        exit(1);
    }
    else{
        cout<<"Opening file succeed!"<<endl;
    }
    cout<<"******************************************"<<endl;

    //获取序列
    string seq;
    vector<string>v1;
    while(getline(infile,seq)){
        infile >> seq;
        v1.push_back(seq);
    }
    for(int i = 0; i < v1.size(); i++){
        sequence = sequence + v1.at(i);
    }
    //cout<<sequence<<endl;
    for(int i = 0; i < sequence.size(); i++){
        cout<<'('<<sequence[i]<<','<<i<<')';
    }
    seq_score();
    Get_value();//test
    infile.close();
    return 0;
}

/*
string get_k_mer(int i,int k)
{
    string k_mer;
    k_mer = sequence.substr(i,k);
    return k_mer;
}


int k_mer_4to10(string k_mer)
{
    string s;
    for(int i=0;i<k_mer.size();i++){
        switch(k_mer[i]){
            case 'A':s[i]='0';break;
            case 'T':s[i]='1';break;
            case 'C':s[i]='2';break;
            case 'G':s[i]='3';break;
        }
    }
    int ans=0;
	for(int i=0;i<s.size();i++)
	{
		char t=s[i];
		if(t>='0'&&t<='9') ans=ans*4+t-'0';
		else ans=ans*4+t-'a'+10;
	}
	return ans;
}

void update_hashtable(int num_10,int index)
{
 //   hashtable[num_10];
    if(hashtable.find(num_10)==hashtable.end()){
        hashtable[num_10] = index;
    }
    else{
        int tmp = hashtable[num_10];
        hashtable[num_10] = tmp - index;
        //同时也需要更新之前的k_mer的距离值
        index2distanceMap[index] = hashtable[num_10];
        index2distanceMap[tmp] = index - tmp;
    }
    return;
}
*/
/*

	int main（）
	{
	ifstream infile;
	infile.open("qqzl.txt", ios::in);
	if (!infile.is_open())
	{
		cout << "读取文件失败" << endl;
		return;
	}
	string s;
	vector<string>v1;
	while (getline(infile,s))
	{
		infile >> s;
		v1.push_back(s);
	}
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i);
		cout << endl;
	}
		infile.close();
	}
*/