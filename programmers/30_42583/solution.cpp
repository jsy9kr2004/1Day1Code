#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
  int answer = 0;
  int remain_weight = weight;
  queue<int> bridge;
  for (int i = 0 ; i < truck_weights.size() ; i++) {
    while (1) {
      if (bridge.size() == bridge_length) {
        remain_weight +=
          bridge.front();
        bridge.pop();
      }
      if (remain_weight >=
          truck_weights[i]) {
        bridge.push(truck_weights[i]);
        remain_weight
          -=
          truck_weights[i];
        answer++;
        break;
      }
      else {
        bridge.push(0);
        answer++;
      }
    }
  }
  return  answer + bridge_length;
}
