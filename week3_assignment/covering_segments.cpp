#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

vector<Segment> bubble_fast(vector<Segment> input){
  int n = input.size();
  while(true){
    int newn = 0;
    for(int i=1; i<=n-1; i++){
      if(input[i-1].start > input[i].start){
        std::swap(input[i-1], input[i]);
        newn = i;
      }
    }
    n = newn;
    if(n==0) break;
  }
  return input;
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  
  segments = bubble_fast(segments);
  
  int index = 0;
  while(true){
    if(index >= segments.size()-1) break;
    
    Segment range;
    range.start = segments[index].start;
    range.end = segments[index].end;
    
    for(int i = index; i < segments.size(); ++i){
      index = i;
      
      if(segments[i].start < range.end){
        if(segments[i].start > range.start){
          range.start = segments[i].start;
        }
        //segments is sorted accroding to its starts
        
        if(segments[i].end < range.end){
          range.end = segments[i].end;
        }
      }else{
        break;
      }
    }
    points.push_back(range.end);
  }
  
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (int i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (int i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
  std::cout << std::endl;
}
