class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
          int stream=1;
          int i=0;
          vector<string> result;
          while(i<target.size() && stream<=n){
              result.push_back("Push");    //push after every read from stream
              if(stream==target[i]){
                  i++;                      //increase counteer if stream element equal to target element
              }
              else{
                  result.push_back("Pop");    //pop is not equal to stream element
              }
              stream++;
          }
          return result;
    }
};