#include <iostream>
class A {
private:
  static int count;
public:
  A(){count++;}
  static int getCount() {
    return count;
  }
};
int A::count = 0;
int main() {
  A a1;
  A::getCount();
  return 0;
}
