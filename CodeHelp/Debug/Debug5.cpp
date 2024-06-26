#include <iostream>
#include <algorithm>
#include<cmath>
#include<limits.h>
#include <vector>
#include<string>
using namespace std;

int mystoi(string s) {
        int len = s.size();
        int num = 0;
        int i=0;
        while(i<len && s[i] == ' '){
            i++;
        }
        bool negative = s[i] == '-';
        negative == true ? i++ : i;
        while(i < len && s[i] >= '0' && s[i] <= '9'){
            num = num*10 + s[i]-'0';
            i++;
        }
        num = negative ? -num : num;
        num = (num > INT_MAX) ? INT_MAX : num;
        num = (num < INT_MIN) ? INT_MIN : num;
        return int(num);
    }

    string intToRoman(int num) {
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[] = {"","M","MM"};
        
        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[(num%10)];
}

string addBinary(string a, string b) {
    string ans;
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
      if (i >= 0)
        carry += a[i--] - '0';
      if (j >= 0)
        carry += b[j--] - '0';
      ans += carry % 2 + '0';
      carry /= 2;
    }

    reverse(begin(ans), end(ans));
    return ans;
  }

  void reverseString(char input[],int n,int start){
    for(int i=start,j=n-1+start; i<j; i++,j--){
        int temp = input[i];
        input[i] = input[j];
        input[j] = temp;
    }
}

void reverseEachWord(char input[]) {
    int start=0,count=1,i=0;
    while(input[i]!=0){
        i++;
        count++;
        if(input[i]==' '||input[i]=='\0'){
            reverseString(input,count-1,start);
            start = i+1;
            count = 0;
        }
    }
}

bool isVowel(char ch) {
        ch = toupper(ch);
        return (ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U');
    }
    
    string sortVowels(string s) {
        string t = s;
        vector<char> vowel;
        
        for(int i=0;i<s.length();i++){
            if(isVowel(s[i])) vowel.push_back(s[i]);
        }
        
        if(vowel.size()==0) return s;
        
        sort(vowel.begin(), vowel.end());
        
        int j=0;
        for(int i=0;i<t.length();i++){
            if(isVowel(t[i])) {
                t[i]=vowel[j++];
            }
        }
        
        return t;
    }

    /*
Test Case:
Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
*/
string mergeAlternately(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        string result = "";
        int i = 0, j = 0;

        while (i < m || j < n) {
            if (i <= j && i<m) {
                result.push_back(word1[i++]);
            }
            else if (j < i || j>=m) {
                result.push_back(word2[j++]);
            }
        }

        return result;
    }

    int main(){
        // string s;
        // getline(cin, s);
        // int converted=mystoi(s);
        // cout<<converted;

        // int num;
        // cin>>num;
        // string roman=intToRoman(num);
        // cout<<roman;
        
        // string a;
        // string b;
        // cout<<"Enter Number 1: ";
        // cin>>a;
        // cout<<"Enter Number 2: ";
        // cin>>b;
        // string add=addBinary(a,b);
        // cout<<add;

        // //Difficult to Understand
        // char input[100];
        // cin>>input;
        // reverseEachWord(input);
        // cout<<input;

        // string s;
        // getline(cin, s);
        // string sorted=sortVowels(s);
        // cout<<sorted;

        string word1;
        string word2;
        cout<<"Enter Word 1: ";
        cin>>word1;
        cout<<"Enter Word 2: ";
        cin>>word2;
        string mix=mergeAlternately(word1,word2);
        cout<<mix;

        return 0;
    }