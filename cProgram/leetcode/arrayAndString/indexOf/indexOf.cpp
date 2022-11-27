#include <malloc.h>
#include <vector>
#include <string>
using std::string;
using std::vector;
class Solution {
public:
    int strStr(string hayStack, string needle) {
            hayStack.insert(0,1,'t');
            needle.insert(0,1,'t');
            int i=0,j=0,len=hayStack.size()-1,subLen=needle.size()-1;
            int nextArr[subLen+2];
            getNext(needle,nextArr);
            while (i<=len&&j<=subLen)
            {
                if(j==0||hayStack[i]==needle[j]){
                    ++i;
                    ++j;
                }else{
                    j=nextArr[j];
                }
            }
            if(j>subLen){
                return i-subLen-1;
            }else{
                return -1;
            }
        }
        void getNext(string hayStack,int nextArr[]){
            int i=1,j=0,len=hayStack.size()-1;
            nextArr[1]=0;
            while (i<len)
            {
                if(j==0||hayStack[i]==hayStack[j]){
                    ++i;
                    ++j;
                    nextArr[i]=j;
                }else{
                    j=nextArr[j];
                }
            }
        }
};