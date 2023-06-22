#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int MAX = 1e5 + 1;

const int NUMBER_MAX = 10;

const int steps[NUMBER_MAX][NUMBER_MAX] = {
    {1, 7, 6, 7, 5, 4, 5, 3, 2, 3}, {7, 1, 2, 4, 2, 3, 5, 4, 5, 6},
    {6, 2, 1, 2, 3, 2, 3, 5, 4, 5}, {7, 4, 2, 1, 5, 3, 2, 6, 5, 4},
    {5, 2, 3, 5, 1, 2, 4, 2, 3, 5}, {4, 3, 2, 3, 2, 1, 2, 3, 2, 3},
    {5, 5, 3, 2, 4, 2, 1, 5, 3, 2}, {3, 4, 5, 6, 2, 3, 5, 1, 2, 4},
    {2, 5, 4, 5, 3, 2, 3, 2, 1, 2}, {3, 6, 5, 4, 5, 3, 2, 4, 2, 1}};
int cache[MAX][NUMBER_MAX][NUMBER_MAX];

string copyNumbers;

int func(int idx, int left, int right) {
  if (idx == copyNumbers.length()) {
    return 0;
  }

  int &result = cache[idx][left][right];

  if (result != -1) {
    return result;
  }

  int cur = copyNumbers[idx] - '0';
  if (left == cur || right == cur) {
    return result = 1 + func(idx + 1, left, right);
  }
  return result = min(func(idx + 1, cur, right) + steps[left][cur],
                      func(idx + 1, left, cur) + steps[right][cur]);
}

int solution(string numbers) {
  memset(cache, -1, sizeof(cache));
  copyNumbers = numbers;

  return func(0, 4, 6);
}