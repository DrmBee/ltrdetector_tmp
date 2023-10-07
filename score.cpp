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
#include<map>

using namespace std;

string sequence;
unordered_map<int,int>hashtable;
map<int, int> index2distanceMap = {};


string get_k_mer(int i,int k);
int k_mer_4to10(string k_mer);
void update_hashtable(int num_10,int index);
int get_value();

int main()
{
    string input_path = "./Arabidopsis_thaliana.TAIR10.dna.chromosome.1.fa";
    ifstream infile;
    cout<<"**********************"<<endl;
    infile.open(input_path,ios::in);
    if(!infile.is_open()){
        cout<<"文件读取失败"<<endl;
        exit(1);
    }
    cout<<"**********************"<<endl;
    string s;
    vector<string>v1;
    while(getline(infile,s)){
        infile >> s;
        v1.push_back(s);
    }
    // cout<<"**********************"<<v1.size()<<endl;
    // cout<<v1.at(0)<<(v1.at(0)).size()<<endl;
    for(int i = 0; i < v1.size(); i++){
        sequence = sequence + v1.at(i);
    }
    cout<<sequence;
    //k存在范围


    
    int num_10,maxLenLTR=6000;
    string k_mer;
    for(int k = 13;k<maxLenLTR;k++){
        for(int i=0;i<sequence.size();i++){
            k_mer = get_k_mer(i,k);
            num_10 = k_mer_4to10(k_mer);
            update_hashtable(num_10,i);
            get_value();

        }
    }


    // string temp = v1.at(0);
    // cout<<temp<<endl;
    // for(int i = 0;i<(temp).size();i++){
    //     cout<<temp[i];
    // }
    infile.close();
    return 0;
}


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