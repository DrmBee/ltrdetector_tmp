/*
只要基因组中有显著的重复，就会有一个相似分数的扩展的半连续序列，但是突变的存在会导致延伸段出现缺口。
识别所有非零分数的连续延伸，并将其分为两类：keep和delete；

前向合并（如果D区段与相邻的K区段被小于一定大小的间隙分隔开，则将其合并）
属于D部分的分数被相邻K部分的中值分数覆盖，该D部分被重新归类为K部分；
相邻的K部分将通过使用两个K部分的一个中值分数来对间隙部分重新赋值。

反向合并
合并出现在K片段上游并且被正向合并步骤遗漏的所有D个片段。
在两次合并之后，所有剩余的D部分被覆盖为0。
0:60:12
1:60:11
2:60:10
60:-60:11
61:-60:10
136:46:11
137:46:10

*/
#include<iostream>

#include"main.h"

using namespace std;

int seed = 10;
bool keep = true;
/*
处理的对象是map字典
第一步：将所有
*/
void merge()
{
    
    Forward_merge();
    Reverse_merge();
}
void Forward_merge()
{

}
void Reverse_merge()
{

}