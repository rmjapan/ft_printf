# ft_printf

## スケジュール
- [man](https://scrapbox.io/readmemo1/man:printf)を読み解きながらprintf関数の全体像を理解する。
## 位置指定子の処理(＄）
- すべての変換仕様で位置指定を使うか、または一切使わないかのどちらかに統一する必要がある。[man]
- 但しDiscordでは位置指定子に関する議論がなかったので、これを処理するかは確認が必要。
-　subject.pdfを見ても記載がない。他の人の実装例を見ても対応していない。
  →位置指定子は処理しない。
  

## 変換仕様について
- [変換仕様の説明](http://www9.plala.or.jp/sgwr-t/detail/FormatString.html)を参考に理解する。
- [subject.pdf](https://cdn.intra.42.fr/pdf/pdf/109720/en.subject.pdf)に、対応する変換指定子は明示されている。

  
