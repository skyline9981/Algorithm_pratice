#include <stdio.h>
int main() {
  int i = 3;
  // 檢驗 i 是否為奇數
  if (i % 2 == 1) // 成功
    i++;

  i *= 5; // 變成偶數後再乘以 5
  printf("%d\n", i);
}
