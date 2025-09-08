//
// Word puzzle: The input consists of a twodimensional array of letters and a list of words. The object is to find the words in the puzzle.
// These words may be horizontal, vertical, or diagonal in any direction. As an example, the
// puzzle shown in Figure 1.1 contains the words this, two, fat, and that. The word this begins
// at row 1, col 1, or (1,1), and extends to (1,4); two goes from (1,1) to (3,1); fat goes
// from (4,1) to (2,3); and that goes from (4,4) to (1,1).
//

# include <iostream>
# include <vector>
# include <string>
#include <bits/stdc++.h>
using namespace std;

template <typename Object>
class matrix {
public:
matrix(int rows, int cols) : array(rows) {
  for (auto& thisRow : array)
  thisRow.resize(cols);
}
matrix(const vector<vector<Object>>& v) : array{v} {
}
matrix(vector<vector<Object>>&& v) : array{move(v)} {
}
const vector<Object>& operator[](int row) const {
  return array[row];
}
vector<Object>& operator[](int row) {
  return array[row];
}
int numrows() const {
  return array.size();
}
int numcols() const {
  return numrows() ? array[0].size() : 0;
}
void show() const {
  if(numcols() && numrows()){
    for(int i = 0; i<numrows(); i++) {
      for(int j = 0; j<numcols();j++) {
        cout<<array[i][j];
        if(j+1 < numcols()) cout<<" ";
      }
      if(i+1 < numrows()) cout<<endl;
    }
    cout<<endl;
  }
}
private:
  vector<vector<Object>> array;
};

string searchWord(matrix<string> mat ,string word) {
  int n = mat.numcols();
  int m = mat.numrows();
  for (int i=0; i<mat.numrows(); i++) {
    for (int j=0; j<mat.numcols(); j++) {
      string extractedR, extractedU, extractedL, extractedD;
      string extractedRU, extractedLU, extractedRD, extractedLD;
      for (
      int shift = 0;
      shift < word.length();
      shift++) {
        if (j+shift < n) extractedR+= mat[i][j+shift];
        if (i+shift < m) extractedD+= mat[i+shift][j];
        if (j-shift >= 0) extractedL+= mat[i][j-shift];
        if (i-shift >= 0) extractedU+= mat[i-shift][j];
        if (i+shift < m && j+shift < n) extractedRD+= mat[i+shift][j+shift];
        if (i+shift < m && j-shift >= 0) extractedLD+= mat[i+shift][j-shift];
        if (i-shift >= 0 && j+shift < n) extractedRU+= mat[i-shift][j+shift];
        if (i-shift >= 0 && j-shift >= 0) extractedLU+= mat[i-shift][j-shift];
      };
      int ind = i + 1;
      int col = j + 1;
      if (word==extractedR) {return to_string(ind)+","+to_string(col)+": Right";}
      if (word==extractedU) {return to_string(ind)+","+to_string(col)+": Up";}
      if (word==extractedL) {return to_string(ind)+","+to_string(col)+": Left";}
      if (word==extractedD) {return to_string(ind)+","+to_string(col)+": Down";}
      if (word==extractedRU) {return to_string(ind)+","+to_string(col)+": Right Up";}
      if (word==extractedLU) {return to_string(ind)+","+to_string(col)+": Left Up";}
      if (word==extractedRD) {return to_string(ind)+","+to_string(col)+": Right Down";}
      if (word==extractedLD) {return to_string(ind)+","+to_string(col)+": Left Down";}
    }
  }
  return "Not Found";
}

int main() {
  vector<vector<string>> matrix_temp {
    {"t", "h", "i", "s"},
    {"w", "a", "t", "s"},
    {"o", "a", "h", "g"},
    {"f", "g", "d", "t"}
  };
  matrix<string> wordMatrix (matrix_temp);
  string words[4] = {"this", "two", "fat", "that"};
  for (string w : words) {
    string res = searchWord(wordMatrix,w);
    cout << "\"" << w << "\" is at " << res << endl;
  }
  return 0;
}
