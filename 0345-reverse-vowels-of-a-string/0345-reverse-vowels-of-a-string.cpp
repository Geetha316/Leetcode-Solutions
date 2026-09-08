class Solution {
public:
  bool vowel(char c)
  {
    return string("aeiouAEIOU").find(c)!=string::npos;
  }
  string reverseVowels(string s){
    int i=0,j=s.size()-1;
    while(i<j){
        while(i<j&&!vowel(s[i]))i++;
        while(i<j&&!vowel(s[j]))j--;
        swap(s[i],s[j]);
        i++;
        j--;
            }
            return s;
  }
  };