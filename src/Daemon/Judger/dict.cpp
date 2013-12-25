//
//  main.cpp
//  permulation_test
//
//  Created by pengfeituan on 10/8/13.
//  Copyright (c) 2013 pengfeituan. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <stdio.h>
using namespace std;
#define N 25

string perm_dict(string now,int len){
    bool has=false;
    string ret=now;
    int i;
    for(i=len-1;i>0;i--)if(now[i-1]<now[i]){
        has=true;
        break;
    }
    if(!has)return string();
    int j;
    for(j=len-1;j>=i;j--)if(now[i-1]<now[j]){
        break;
    }
    swap(ret[i-1],ret[j]);
    int k;
    for(k=0;k<=(len-1-i)/2;k++)swap(ret[i+k],ret[len-1-k]);
   // cout<<i<<'\t'<<j<<endl;
    return ret;
}


int main(int argc, const char * argv[])
{
	int in_len;
	scanf("%d",&in_len);
	char schar[N];
	int i;
	for(i=0;i<in_len;i++)schar[i]=i+'a';
	schar[i]=0;
	string s1=string(schar);
    while(s1.length()){
		printf("%s\n",s1.c_str());
		s1=perm_dict(s1,in_len);
	}
    return 0;
}

