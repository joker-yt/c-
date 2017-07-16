XX_const
========

-	const 宣言したClassではメンバ変数の変更ができない。

	-	唯一、constructor時のInitializer listでは値を設定することが可能  

-	const objectからはconst methodしか呼べない

	-	当然、そのmethodではメンバ変数の変更ができない。ローカル変数などはOK。
	-	ただし、constの性質上、引数として受けた値は変更すべきではない

	---

	XX_const Q.
	===========

-	create "const" object, and call method

---

XX_lambda
=========

-	std::function<return type(parameter type)> variable = lambda;

---

XX_lambda Q.
============

1.	create lambda by for_each
2.	use std::functon by lambda
3.	use std::functon by functional object

---

XX_ptr  
 ===========

-	auto_ptr has a resk, so must NOT use.

	-	if pointer would not be shared, use unique pointer  
	-	if pointer would be shared, use shared pointer

---

XX_ptr Q.
=========

-	make unique pointer
-	make shared pointer
