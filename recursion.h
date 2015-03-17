//
// Created by santiago on 3/17/15.
//

#include <cstdlib>
#include <string>
#include <vector>
#include <string.h>

#ifndef _RECURSIONPROBLEMS_RECURSION_H_
#define _RECURSIONPROBLEMS_RECURSION_H_

#define NOT_IN_ARRAY (-1)


void permutations_of_string(std::string text){

}



int factorial_recursive(int num){

    if(num==0 || num==1){
        return 1;
    }

    int aux=num-1;

    return factorial_recursive(aux)*num;

}

int factorial_iterative(int num){
    int result=1;
    for(;num>0;num--){
        result*=num;
    }

    return result;
}

int binary_search(int *array,int start,int end,int target){

    int range=end-start;

    int half=(range>>1)+start;

    if(range<0){
        return 0;
    }

    if(range==0 && target!=array[start]){
        return 0;
    }

    //base
    if(array[half]==target){
        //Dont look for more, we reached the base case
        return half;
    }else if(target < array[half]){
        //lets search in the lower half
        int newupper=half-1;
        return binary_search(array,start,newupper,target);
    }else{
        //lets search in the upper half
        int newlower=half+1;
        return binary_search(array,newlower,end,target);
    }

}

int binary_search_iterative(int *array,int start,int end,int target){


    while(true){
        int range=end-start;
        int half=(range>>1)+start;

        if(range<0){
            //no space to search
            return 0;
        }

        if(range==0 && target!=array[start]){
            return 0;
        }

        if(target==array[half]){
            //we found the number
            return 1;

        }else if(target < array[half]){
            end=half-1;

        }else{
            start=half+1;

        }


    }

}

bool binary_search(int *array,int looking,int size){

    if(looking<array[0]){
        return false;
    }

    if(looking>array[size]){
        return false;
    }

    return binary_search(array,0,size,looking);
}


void permuta_all(char *word,std::string out,bool *used,int len,int level,std::vector<std::string> & storage){

    if(len==level){
        storage.push_back(out);
        return;
    }

    for(int i=0;i<len;i++){
        if(used[i]){
            continue;
        }

        out+=word[i];
        used[i]=true;
        int newlevel=level+1;
        permuta_all(word,out,used,len,newlevel,storage);
        used[i]=false;
        out.pop_back();
    }
}

void permute(char *word,std::vector<std::string> & storage){

    int len=strlen(word);
    std::string out;
    bool *used=(bool*)malloc(sizeof(bool)*len);
    int level=0;
    permuta_all(word,out,used,len,level,storage);
}

void permute_order(char *word,int current,int per_level){

    if(per_level==strlen(word)){
        //base case
        return;
    }

    std::string aux="";
    for(int i=current;i<=per_level;i++){
        aux+=word[i];
    }

    printf("%s\n",aux.c_str());


    int new_per_level=per_level+1;

    permute_order(word,current,new_per_level);

}

void permute_order(char *word){

    int size=strlen(word);
    for(int i=0;i<size;i++){
        permute_order(word,i,i);
    }

}



char getCharKey(int key,int place){
    char *pointer;
    switch(key){
        case 0:
            return '0';
        case 1:
            return '1';
        case 2: {
            char aux[] = "ABC";
            pointer=aux;
            break;
        }
        case 3: {
            char aux[] = "DEF";
            pointer=aux;
            break;
        }
        case 4: {
            char aux[]="GHI";
            pointer=aux;
            break;
        }
        case 5: {
            char aux[]="JKL";
            pointer=aux;
            break;
        }
        case 6: {
            char aux[]="MNO";
            pointer=aux;
            break;
        }
        case 7: {
            char aux[]="PRS";
            pointer=aux;
            break;
        }
        case 8: {
            char aux[]="TUV";
            pointer=aux;
            break;
        }
        case 9: {
            char aux[]="WXY";
            pointer=aux;
            break;
        }
    }

    return pointer[place];
}

void telephone_words(int *number){

}













#endif //_RECURSIONPROBLEMS_RECURSION_H_
