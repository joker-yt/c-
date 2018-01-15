06_array, forward_list（単方向リンクリスト）、list(双方向リンクリスト), map, hash(unordered_map)
===
### Sequencial Container
##### array
- 固定長の配列
- random access:O(1) 任意位置への追加:O(N)
##### vector
- stack的な可変長リスト
- random access:O(1) 任意位置への追加:O(N)
##### forward_list
- 単方向リスト
- random access:O(N) 任意位置への追加:O(1)
##### list
- 双方向リスト
- random access:O(N) 任意位置への追加:O(1)

---

06_array, forward_list（単方向リンクリスト）、list(双方向リンクリスト), map, hash(unordered_map)
===
### Container Adapter
#####
- 固定長の配列
#####
- stack的な可変長リスト
#####

---


06_array, forward_list（単方向リンクリスト）、list(双方向リンクリスト), map, hash(unordered_map) Q.1
===
1. データ判定
 - 空
 - エントリ数
 - swap
2. イテレータアクセス
3. array生成（初期データ静的指定）、参照、先頭、末尾、先頭ポインタ
4. list生成（初期データ静的指定）、追加、削除、挿入、値削除、全削除 サイズ変更
5. mapとunordered_mapの違い
6. forward_list, list生成
7. list系で先頭に追加、場所指定の挿入,削除（場所に注意。iterator指定の場合、first, lastは含まれない）
8. list系での検索, エントリ数の取得
9. list系で戦闘の前



---

06_array, list, map, hash Hint.1
===
1. データ判定/共通操作
 - empty()
 - size()
 - v.swap(&other)
2. auto it = ar.begin();, .end()
3. std::array<int, 3> ar{1,2,3}; at(pos), front() back() data()
4. std::list\<int\> li {1,2,3}  push_front() push_back() pop_front() pop_back() insert() erase(pos) clear(pos, value) resize(count)
5. mapは平衡２分探索木で実装、unordered_mapはハッシュテーブルで実装。キーの順番を保持したい場合はmapが早いが、それ以外はunordered_mapが早い（保持しない＝iteratorするとバラバラ）
6. std::forward_list<int>、std::list<int>
7. li.push_front(), li.insert_after(it, val)、pop_front(), li.erase_after()
8. std::find(li.begin(), li.end(), val)、std::distance(li.begin(), li.end())
9. std::forward_list.splice_after(it.before_begin(),


---



06_array, list, map, hash(unordered_map) Q.2
===
10. (unordered_)mapでの値の追加
11. (unordered_)mapでのキー、値へのアクセス
12. (unordered_)mapでのキーによる検索
13. (unordered_)mapでの削除
14. 値からのキー検索
15. std::sort(list, forward_list以外)
16. list::sort
17. for(type var : list)の使い方
18. autoを使ったiteratorの実装

---

06_array, list, map, hash Hint.2
===
10. std::map<std::string, int> mp; mp["first"] = 0; mp["second"] = 2;
11. auto it = mp.begin(); it->first, it->second
12. auto it = mp.find("key"); if(it == mp.end()) -> not found
13. mp.erase("key")
14. iteratorで全検索し、if文でit->secondのチェックをする
15. std::sort(begin(), end())
lambda使用時は
```
std::sort(begin(), end(), [](const int &x, const int &y){
  if(x < y) return true; else return false;});
```
16. std::list li; li.sort(); // パラメータ無し
17.
```
std::array<std::string > ar = {"apple", "orange", "grape"};
for(const auto var : ar){}
```
---
