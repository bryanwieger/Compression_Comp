//Bryan Wieger
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>
using namespace std;


void filemaker(string [],long long, long long, long long); //used to make the file
string randStr(long long, long long); //out puts a random string from 4-7 characters in length
string getfilename(); //creates a string ending in .txt


int main()
{
	srand(time(NULL));
	string repeat[26]={"anna","bryan","cynthia","dylan","euler","fred","gregory","helen","ivana",
					"jazzy","keller","larry","maggie","nolan","oculus","peter","queen","rick",
					"stacy","tumath","ulrich","vicki","wieger","xavier","yeah","zaiah"};
	while(true){
		cout<<"Number of lines: ";
		unsigned long long S,min,max;
		cin>>S;
		cout<<"\nMin Char per line: ";
		cin>>min;
		cout<<"\nMax Char per line: ";
		cin>>max;
		for(int i=0; i<26; i++){
			repeat[i]=randStr(min,max);
		}
		filemaker(repeat,S,min,max);
	}
	return 0;	
}

string getfilename(){
	string res="";
	cout<<"Filename: ";
	cin>>res;
	res+=".txt";
	return res;
}

void filemaker(string repeat[], long long S, long long min, long long max){
	ofstream out;
	out.open(getfilename().c_str());
	int c,d;
	for(unsigned long long i=0; i<S; i++){
		c=rand()%12;
		c/=11; //1 out of twelve that randStr() will be called
		switch(c){
			case 0:
				d=rand()%26;
				out<<repeat[d]<<endl;
				break;
			case 1:
				out<<randStr(min,max)<<endl;
				break;
			default:;
		}
	}
	out.close();	
}

string randStr(long long min, long long max){
	string res="";
	int l=rand()%(max-min+1)+min;
	while(res.length()<l) res+=((char)((rand()%26+(int)'a')));
	return res;
}
