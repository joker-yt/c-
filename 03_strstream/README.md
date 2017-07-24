03_ostrstream, istrstream Q1.
=============================

1.	binaryデータの書き込み
2.	no error
3.	end of file
4.	i/o error
5.	write/read result
6.	ifstreamでシーク
7.	ifstreamで位置
8.	open時のパラメータ
9.	oepn失敗する例, open error check example
10.	constructor paremeter
11.	ofstreamでシーク
12.	ofstreamで位置
13.	追記モード、末尾モード、切り捨て（破棄）モード
14.	ファイル有無チェック ---

03_ofstream, ifstream Hint1.
============================

1.	std::ofstream ofs("test.dt", std::ios::out | std::ios::binary); ofs.write((char\*)data, size);
2.	ofs.good()
3.	ofs.eof()
4.	ofs.fail()
5.	ofs.rdstate() -> std::ios::goodbit, eofbit, failbit, badbit
6.	ifs.seekg(0) std::ios_base::beg, cur, end ifs.endもOK？
7.	ifs.tellg()
8.	in out binary app trunc ate(at end)
9.	app && trunc, ofs.rdstate() & std::ios::failbit
10.	in, out, binary, ate, app, trunc
11.	ofs.seekp(pos) or ofs.seekp(off, dir)
12.	ofs.tellp()
13.	std::ios_base::app(append), std::ios_base::ate(at end), std::ios_base::trunc(truncate)
14.	std::ifstream("path").good() true:exist false:not exist
