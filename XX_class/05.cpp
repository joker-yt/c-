#include <iostream>

using namespace std;

/*! \class Base
 * @brief brief comment
 */
class Base {
  virtual void vir_fin_method() final { std::cout << __FUNCTION__ << "\n"; }
  virtual void vir_over_method() { std::cout << __FUNCTION__ << "\n"; }
};

/*! \class Derive
 * @brief brief comment
 */

class Derive : public Base {
  // NG. keyword "final" is defined in Base class.
  // void vir_fin_method()

  void vir_over_method() override{};
};

class QuackBehavior {
public:
  virtual ~QuackBehavior() {}
  virtual void quack() const = 0; //純粋仮想関数(派生クラスに)
};
class Quack : public QuackBehavior {
public:
  void quack() const { cout << "gua-gua" << endl; }
};

class Duck {
protected:
  QuackBehavior *q;

public:
  virtual ~Duck() { delete q; };

  //仮想関数
  virtual void quack() const { q->quack(); }
  // virtual void quack() const { q->quack(); }
};
class RedHeadDuck : public Duck {
private:
public:
  RedHeadDuck() { q = new Quack(); }

  // overrideを付けることで、仮想関数であることを明示する。
  //もちろん、overrideを外しても、コンパイルできる
  void quack() const override { q->quack(); }
};

int main(int argc, char *argv[]) {
  Base *p = new Derive();
  Duck *p2 = new RedHeadDuck;

  p2->quack();

  return 0;
}
