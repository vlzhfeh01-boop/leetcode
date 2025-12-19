#include <string>
#include <algorithm>
#include <iostream>
using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        
        for (char c :s){
            if ((65<=c && c<=90)){
                c += 32;
                temp += c;
            }
            else if ((48<=c && c<=57)||(97<=c&&c<=122))
            {
                temp += c;
            }
            
        }
        string original = temp;
        reverse(temp.begin(),temp.end());

        if(original == temp)
            return true;
        return false;

        // Two Pointer
        int start = 0;
        int end = s.size() -1 ;

        while(start <= end){
            if(!isalnum(s[start])){
                start++;
                continue; 
                // 아래 비교문 까지 내려가지 않고 다시 while문으로 올라가기 때문에, 불필요한 체크를 줄일 수 있다.
            }
            if(!isalnum(s[end])){
                end--;
                continue;
            }
            // unsigned char로 static cast를 하는게 더 안전하다.
            // unsigned char a = static_cast<unsigned char>(s[start]);

            if(tolower(s[start]) != tolower(s[end])){
                return false;
            }
            else {
                start++;
                end --;
            }
        }
        return true;
    }
};
int main(){
    Solution sol1;

    string s = "0P";

    cout << sol1.isPalindrome(s) << endl;
    return 0;
}
