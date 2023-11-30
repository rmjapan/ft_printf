# ft_printf

## スケジュール
- [man](https://scrapbox.io/readmemo1/man:printf)を読み解きながらprintf関数の全体像を理解する。→終了（2023/11/30）
- 擬似コードの実装（2023/12/01〜）
## 位置指定子の処理(＄）
- 処理しない方針

## 変換仕様について
- [変換仕様の説明](http://www9.plala.or.jp/sgwr-t/detail/FormatString.html)を参考に理解する。
- [subject.pdf](https://cdn.intra.42.fr/pdf/pdf/109720/en.subject.pdf)に、対応する変換指定子は明示されている。
- -、0フラグ、 最小フィールド幅、 精度., cspdiuxX%変換指定子に対応だけしとけばいいっぽい。
### フォーマット
- %[フラグ] [フィールド幅].[精度][長さ修飾子（無視してOK）][変換指定子]
- %[flags][width].[precision][length][specifier]
- [フラグ]
 - "-"（マイナスフラグ）と "0"（ゼロフラグ）
 - 最小フィールド幅
 - "."（精度）
 - 変換指定子
- フラグの種類
  - -,0,+,(space),#
- [具体例](https://zenn.dev/hosu/articles/54022040cb64c8)

### フォーマットの組み合わせ
 - マイナスフラグ＞ゼロフラグ
 - 精度＞ゼロフラグ
 - 精度とマイナスフラグ（先に精度→マイナスフラグの順で処理するので、結果的にマイナスフラグはつける意味無し）
 - 精度と最小フィールド幅（先に精度→フィールド幅の順で処理する。）
 - マイナスフラグとゼロフラグは、最小フィールド幅に影響を与える
  
 - [マイナスフラグ、ゼロフラグ][フィールド幅].[精度][変換指定子]の組み合わせを考える必要がある。
 - マイナスフラグは、フィールド幅を左に揃えることができる。ゼロフラグは、与えられた桁文字文の左側の余剰スペースに0を埋める。
  - マイナスフラグとゼロフラグの組み合わせ
  - [Wformat]で警告でる。[Werror]つけるのでコンパイルエラー
  - 一方で、マイナスフラグとゼロフラグならば  -0  -が優先されるため、左揃えになるというDiscordもあった。
  - manによれば、マイナスフラグが優先されるそうなのでそうしとく。
 　　 - '0' フラグとの関係:'-' が '0' よりも優先されます。両方が指定されている場合、'-' フラグに従って左寄せが行われ、ゼロ埋めは無視されます。
  - マイナスフラグと精度
    -　精度→マイナスフラグの順番で処理される。
    - マイナスフラグは無効化されると考えてよい。
  
  - ゼロフラグと精度
    - manによれば、数値変換（d、i、o、u、i、x、X）に精度が与えられている場合、0 フラグは無視される。
      - printf("[%.10d]\n", -1234567);		//[-0001234567](精度）
      - printf("[%010d]\n", -1234567);		//[-001234567]（ゼロフラグ）
      - printf("[%0.10d]\n", -1234567);		//[-0001234567](精度かつゼロフラグ１）
      - printf("[%010.10d]\n", -1234567);		//[-0001234567]（精度かつゼロフラグ２）
  - ゼロフラグと最小フィールド幅
  　-先に最小フィールド幅→ゼロ 
      - 基本的にSpaceが0になっただけである。
       - printf("[%010d]\n", 1234567);		//[0001234567]
      - 負の数への対応は少しことなる。（[00-1234567]ではないことに注意、逆に[-  1234567]でないことにも注意
      　- printf("[%10d]\n", -1234567);		//[  -1234567]
      　- printf("[%010d]\n", -1234567);		//[-001234567]       
  - 最小フィールド幅と精度
    - 先に精度への処理→最小フィールド幅への処理
    - printf("[%1.10d]\n", 1234567);	//[0001234567]
  
  - マイナスフラグと最小フィールド幅
    -　先に最小フィールド幅→マイナスフラグ
   
  
        
### 0フラグ
- ゼロのパディング。n を除くすべての変換において，変換後の値は空白ではなくゼロで左詰めされる。数値変換（d，i，o，u，i，x，X）で精度が与えられる場合，0フラグは無視される。
- %05dみたいなやつ
  - 例
  - 普通の処理
  　- printf("%05d\n", 123); // 00123
  　- printf("%05d\n", -123); // -0123
  - 指定桁より大きな場合
    - printf("%05d\n", 123456); // 123456
  - マイナスの値の場合
  　- printf("%05d\n", -1234); // -01234
  - 文字列の場合
   - printf("%05s\n", "aaa"); // 00aaa
   - ただし、'0' results in undefined behavior with 's' conversion specifieと文字列の場合の振る舞いは未定義
   - 対応しなくていいっぽい


### 最小フィールド幅
- %[最小フィールド幅]変換指定子の形式で記述します。
- 例えば、%5dと指定した場合、整数を出力する際に最低でも5文字分のスペースを確保します。値が5文字未満の場合、残りのスペースは空白で埋められます。
例:
  - printf("%5d", 123); → 出力: " 123"（123の前に2つの空白がある）
  - printf("%8s", "test"); → 出力: " test"（testの前に4つの空白がある）
  - 最小フィールド幅を指定すると、出力がより読みやすく、フォーマットされた形で表示されます。

- 出力内容が指定桁数を超える場合、変化なし。（文字列、数値）
- 出力内容が指定桁数に満たない場合、左側をスペースで埋める。（文字列、数値）

### 精度
- 「精度」は変換指定子によって意味が異なる。直前にある.（ピリオド）と合わせて記述する必要が有る。
- ピリオドに続く任意の数字の文字列で表される任意の精度。
- 整数変換の場合
  - フィールド幅と同様、出力内容が指定桁数を超える場合、変化なし。
   - printf("[%.0d]\n", 1234567);		[1234567]
   - printf("[%.5d]\n", 1234567);		[1234567]
  - 出力内容が指定桁数に満たない場合、左側を0で埋める。　フィールド幅は(space)だったので注意。
  - -の場合、フィールド幅は指定桁数に-の一文字分を含むが、精度は-を指定桁数に含めない。
    - printf("[%.10d]\n", 1234567);		[0001234567]
    - printf("[%.10d]\n", -1234567);		[-0001234567]
- 文字列の場合
  - 最大表示文字数を表し、数値以上の文字列は切り捨てられる。
    - printf("[%.1s]\n", "apple");		[a]
    - printf("[%.3s]\n", "apple");		[app]
  - 最大表示文字数が出力内容よりも多い場合は、最大表示文字数は無視される。
    - printf("[%.10s]\n", "apple");		[apple]
 
  - 数字の文字列が省略された場合、精度はゼロとして扱われます。
    - これは、d、i、o、u、x、X 変換の場合に表示される最小桁数
     - printf("[%.d]\n", 1234567);		[1234567]
     - printf("[%.d]\n",0);	[空文字]

    - s 変換の場合には文字列から印刷される最大文字数を与えます。(つまり何も印字されない）
  

  



  
