#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//选手人数
#define MAXNUM 8
//裁判人数
#define MAXJUD 7
//文件读入，读出//
ifstream Stu("/Users/s20181105882ASN/Desktop/选手信息.txt");
ifstream Jud("/Users/s20181105882ASN/Desktop/裁判打分.txt");
ofstream Gra("/Users/s20181105882ASN/Desktop/grade.txt");
//定义类 //
class Game{
private:
    double grade[MAXJUD];
    string number,name,college,judge[MAXJUD];
public:
    double average;
    double sum=0;
    Game(string num,string nam,string col);
    void play()
    {
        Gra<<number<<"  "<<name<<"  "<<college<<endl;
        Gra<<"裁判打分："<<endl;
        for(int i=0;i<MAXJUD;i++)
        {
            Gra<<judge[i]<<" "<<grade[i];
            if(i!=6)
                Gra<<" ";
        }
        Gra<<endl;
        Gra<<"平均分："<<average<<endl;
    }
};
//读入裁判信息，打分信息，计算平均分//
Game::Game(string num,string nam,string col):number(num),name(nam),college(col)
{
    for(int i=0;i<MAXJUD;i++)
    {
        Jud>>judge[i];
        Jud>>grade[i];
    }
    for(int i=0;i<MAXJUD-1;i++)
    {
        for(int j=0;j<MAXJUD-1-i;j++)
        {
            if(grade[j]>grade[j+1])
            {
                double m=grade[j];
                grade[j]=grade[j+1];
                grade[j+1]=m;
            }
        }
    }
    for(int i=1;i<MAXJUD-1;i++)
    {
        sum+=grade[i];
        
        average=sum/5.0;
    }
    //主函数//
    int main()
    {
        Gra<<"参赛选手得分："<<endl;
        string name,number,college;
        Game *ave[MAXNUM];
        for(int i=0;i<MAXNUM;i++)
        {
            Stu>>number>>name>>college;
            ave[i]=new Game(number,name,college);
        }
        //进行选手分数排序//
        for(int i=0;i<MAXNUM-1;i++)
        {
            for(int j=0;j<MAXNUM-1-i;j++)
            {
                if(ave[j]->average<ave[j+1]->average)
                {
                    Game *t=ave[j+1];
                    ave[j+1]=ave[j];
                    ave[j]=t;
                }
            }
        }
        for(int m=0;m<MAXNUM;m++)
        {
            ave[m]->play();
        }
        return 0;
    }
