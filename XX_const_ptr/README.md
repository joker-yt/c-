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
