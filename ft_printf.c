#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/ft_printf.h"


//仕様
///引き数
//・変換指定子(format)
//・変換指定子に対応する引数 ...
//・変換指定子は%で始まる

int	ft_printf(const char *format, ...)
{
    va_list ap;//char*型
    va_start(ap,format);//可変個引数配列の先頭を指してくれる.（現在のところ）

    //formatの文字列を解析
    ///出力する変数の数と種類を特定する。
    ///変数の数と可変個引数の数が一致する場合の処理、そうでない場合の処理
    ///一致する場合、formatと表示する引数の値が対応しているかを確認？

    明日は,Va_argの続きから　


}