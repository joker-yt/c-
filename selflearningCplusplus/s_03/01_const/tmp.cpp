#include <cassert>
#include <optional>

int main()
{
  std::optional<int> p;
  assert(!p); // デフォルトでは有効な値を持たない (nullopt状態)

  p = 3; // 有効値を代入
  assert(p); // 有効な値を持つ

  p = std::nullopt; // 無効値を代入
  assert(!p); // 有効な値を持たない
}
