/*
string get_k_mer(int i,int k);
int k_mer_4to10(string k_mer);
void update_hashtable(int num_10,int index);
int get_value();
*/
#include<iostream>
#include<cmath>
#include"score.h"
#include"main.h"

using namespace std;

void seq_score(){
    string k_mer;
    for(int k = minLenLTR; k <= maxLenLTR; k++){
        for(int i = 0; i + k < sequence.size(); i++){
         //   cout<<k<<"->"<<i<<endl;
            k_mer = get_k_mer(i,k);
           // cout<<'('<<k_mer<<')';
            if(k_mer == "ATGGGCGAACG"){
                cout<<k_mer<<endl;
            }
            update_hashtable(k_mer,i);
        }
    }
    //添加hash表中的数据到字典中
    /* 因为在更新hash表的时候，每次都是确定的前一个copy对应的数据，即当前的k-mer对应的index相关数据是在下一次遇到同样的k-mer时才会确定*/
   // update_map();

}

string get_k_mer(int i,int k)
{
    string k_mer;
    k_mer = sequence.substr(i,k);
    return k_mer;
}
/*
 * hash表只是一个工具，在更新过程中需要记录每个index对应的distance!!!
 *
*/
void update_hashtable(string k_mer,int index)
{
    //第一次遇到该k_mer,用初始位置填充hash表
    if(hashtable.find(k_mer) == hashtable.end()){
        hashtable[k_mer].index = index;
        hashtable[k_mer].distance = 0;
      //  index_map_distance[index] = 0;  //第一次遇到该k-mer，set distance=0
    }
    else{//其他情况遇到该k_mer
        int index_former = hashtable[k_mer].index;
        int distance_former = hashtable[k_mer].distance;
        int index_now = index;
        int distance_now;
        int abs_distance = abs(distance_former);
        /*
        之前的distance可能不是0
        distance:表示与当前index开始的k_mer与其最近的拷贝的距离
        其有正值也有负值；
        但是index只有正值；
        更新包括：之前的distance【字典index_map_distance中的距离】、当前的distance【hash表】、当前的index【hash表】、当前的distance【字典index_map_distance中的距离】
        
        */
        distance_now = index - index_former; //一定为正值

        if(index < hashtable[k_mer].index + k_mer.size()){  //排除两个重复序列交叉的情况
            return;
        }
        //字符串  a****b****c
        /*
         比较b与c之间的距离（distance_now） VS 距离b最近k-mer之间的距离（abs_distance）
         存在的问题：两者相等的时候如何选择？？？
        */
        if(distance_now > abs_distance && distance_former != 0){
            /*如果b与c之间的距离更大，则
            对于hash表：k-mer处更新为新的index和对应的distance
            对于字典：确定b处的distance值，值为hash表中原来的值
            */
            //确定b处的字典值，即距离b处最近的k-mer距离为hash表中对应的index处的distance值
            index_map_distance[index_former].distance = distance_former;
            index_map_distance[index_former].ltrlen = k_mer.size();
            //更新hash
            hashtable[k_mer].index = index;
            hashtable[k_mer].distance = -abs_distance;//负值表示序列的前端有当前k-mer的copy
        }
        else{//distance_now < abs_distance
            /*如果b与c之间的距离更小，则
            对于hash表：k-mer处更新为新的index和对应的distance
            对于字典：确定b处的distance值，值为b与c之间的距离，值为正值
            */
            //更新字典
            index_map_distance[index_former].distance = distance_now;
            index_map_distance[index_former].ltrlen = k_mer.size();
            //更新hash
            hashtable[k_mer].index = index;
            hashtable[k_mer].distance = -distance_now;
        }
    }
    return;
}



/* test */
void Get_value()
{
    map<int,struct node2>::iterator iter;
    iter = index_map_distance.begin();
    cout<<"__________________________________"<<endl;
    while(iter != index_map_distance.end()){
     //   cout << iter->first << ":"<<iter->second.distance<<":"<<iter->second.ltrlen << "//";
        if(iter->second.distance != 0){
            cout << iter->first << ":"<<iter->second.distance<<":"<<iter->second.ltrlen <<endl;
        }
        iter ++;
    }
}