#include <stdio.h>
int main() {
  int i = 3;
  // ���� i �O�_���_��
  if (i % 2 == 1) // ���\
    i++;

  i *= 5; // �ܦ����ƫ�A���H 5
  printf("%d\n", i);
}
