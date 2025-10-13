# include <iostream>
# include <vector>
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
