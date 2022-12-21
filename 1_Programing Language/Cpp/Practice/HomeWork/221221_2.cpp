/*
Description

对于字符串，实现以下函数，并编写main函数测试这些函数：

padLeft函数：

功能：将一字符串左填充（在左边填充指定字符）至n个字符的长度，可指定填充字符，比如填充“*”，如果不指定填充字符，则填充空格。

提示：为实现以上功能，函数原型可为：

void  padLeft(char string1[], char string2[],  int n, char padding=' ')

或:

string padLeft(string string1, int n, char padding=' ')

这里使用了默认形参。

string1是原字符串，string2是填充之后的结果。



以下函数都不规定函数原型，请自行设计。

padRight函数：

功能：将一字符串右填充至n个字符的长度，可指定填充字符，比如填充“*”，如果不指定填充字符，则填充空格。

cpy函数：

功能：从第一个字符串复制字符到第二个字符串。可指定复制的起始位置和结束位置，即从startIndex到endIndex之间的所有字符都复制到第二个字符串中。startIndex默认为0， endIndex默认为到字符串尾部。

比如，

cpy(src, dest)： 将src的所有字符都复制到dest

cpy(src, dest, 3)：将src从下标为3的位置直到结尾的所有字符都复制到dest

cpy(src, dest, 3, 5)：将src的第3、4、5个字符复制到dest中

remove函数：

从形参传入一个字符，将该字符从字符串中删除。

remove函数：

从形参传入一个下标index，将index处的字符从字符串中删除。

remove函数：

从形参传入两个下标startIndex和endIndex，将从startIndex到endIndex范围内的字符从字符串中删除。


Input
输入时，每组测试数据包含两行，第一行输入一个整数，代指需要完成的操作，第二行为该操作需要的数据。

对于每个整数对应的操作及其相应数据的输入方式如下（输入的字符串中不包含空格）：

11：对应padLeft，第二行输入字符串string1、整数n，其间以空格分隔（由于没指定填充字符，所以填充空格）

异常处理：如果string1的长度大于等于n，则不填充任何字符。

12：对应padLeft，第二行输入字符串string1、整数n、一个填充字符，其间以空格分隔（填充字符不为空格）

异常处理：如果string1的长度大于等于n，则不填充任何字符。

21：对应padRight，第二行输入字符串string1、整数n，其间以空格分隔（由于没指定填充字符，所以填充空格）

异常处理：如果string1的长度大于等于n，则不填充任何字符。

22：对应padRight，第二行输入字符串string1、整数n、一个填充字符，其间以空格分隔（填充字符不为空格）

异常处理：如果string1的长度大于等于n，则不填充任何字符。

31：对应cpy，第二行输入字符串src

32：对应cpy，第二行输入字符串src和整数startIndex，以空格分隔。复制从startIndex开始的子字符串，下标从0开始。

异常处理：如果startIndex不合法，则不复制任何字符，结果为空字符串。

33：对应cpy，第二行输入字符串src和整数startIndex、endIndex，以空格分隔。

异常处理：如果startIndex、endIndex不合法，则不复制任何字符，结果为空字符串。

41：对应remove，第二行输入字符串和一个字符（以空格分隔），将字符从字符串中删除。

异常处理：如果字符不存在于字符串？如果字符串含多个该字符？如果字符串全是该字符？

42：对应remove，第二行输入字符串和index（以空格分隔），将index处的字符从字符串中删除。

异常处理：如果index不合法，则不删除字符。

43：对应remove，第二行输入字符串和startIndex、endIndex（以空格分隔），将从startIndex到endIndex范围内的字符从字符串中删除。

异常处理：如果startIndex、endIndex不合法，则不删除字符。


Output
对于每组测试数据，输出对应的结果。如果结果为空字符串，则输出一个空行。

Description

对于字符串，实现以下函数，并编写main函数测试这些函数：

padLeft函数：

功能：将一字符串左填充（在左边填充指定字符）至n个字符的长度，可指定填充字符，比如填充“*”，如果不指定填充字符，则填充空格。

提示：为实现以上功能，函数原型可为：

void  padLeft(char string1[], char string2[],  int n, char padding=' ')

或:

string padLeft(string string1, int n, char padding=' ')

这里使用了默认形参。

string1是原字符串，string2是填充之后的结果。



以下函数都不规定函数原型，请自行设计。

padRight函数：

功能：将一字符串右填充至n个字符的长度，可指定填充字符，比如填充“*”，如果不指定填充字符，则填充空格。

cpy函数：

功能：从第一个字符串复制字符到第二个字符串。可指定复制的起始位置和结束位置，即从startIndex到endIndex之间的所有字符都复制到第二个字符串中。startIndex默认为0， endIndex默认为到字符串尾部。

比如，

cpy(src, dest)： 将src的所有字符都复制到dest

cpy(src, dest, 3)：将src从下标为3的位置直到结尾的所有字符都复制到dest

cpy(src, dest, 3, 5)：将src的第3、4、5个字符复制到dest中

remove函数：

从形参传入一个字符，将该字符从字符串中删除。

remove函数：

从形参传入一个下标index，将index处的字符从字符串中删除。

remove函数：

从形参传入两个下标startIndex和endIndex，将从startIndex到endIndex范围内的字符从字符串中删除。


Input
输入时，每组测试数据包含两行，第一行输入一个整数，代指需要完成的操作，第二行为该操作需要的数据。

对于每个整数对应的操作及其相应数据的输入方式如下（输入的字符串中不包含空格）：

11：对应padLeft，第二行输入字符串string1、整数n，其间以空格分隔（由于没指定填充字符，所以填充空格）

异常处理：如果string1的长度大于等于n，则不填充任何字符。

12：对应padLeft，第二行输入字符串string1、整数n、一个填充字符，其间以空格分隔（填充字符不为空格）

异常处理：如果string1的长度大于等于n，则不填充任何字符。

21：对应padRight，第二行输入字符串string1、整数n，其间以空格分隔（由于没指定填充字符，所以填充空格）

异常处理：如果string1的长度大于等于n，则不填充任何字符。

22：对应padRight，第二行输入字符串string1、整数n、一个填充字符，其间以空格分隔（填充字符不为空格）

异常处理：如果string1的长度大于等于n，则不填充任何字符。

31：对应cpy，第二行输入字符串src

32：对应cpy，第二行输入字符串src和整数startIndex，以空格分隔。复制从startIndex开始的子字符串，下标从0开始。

异常处理：如果startIndex不合法，则不复制任何字符，结果为空字符串。

33：对应cpy，第二行输入字符串src和整数startIndex、endIndex，以空格分隔。

异常处理：如果startIndex、endIndex不合法，则不复制任何字符，结果为空字符串。

41：对应remove，第二行输入字符串和一个字符（以空格分隔），将字符从字符串中删除。

异常处理：如果字符不存在于字符串？如果字符串含多个该字符？如果字符串全是该字符？

42：对应remove，第二行输入字符串和index（以空格分隔），将index处的字符从字符串中删除。

异常处理：如果index不合法，则不删除字符。

43：对应remove，第二行输入字符串和startIndex、endIndex（以空格分隔），将从startIndex到endIndex范围内的字符从字符串中删除。

异常处理：如果startIndex、endIndex不合法，则不删除字符。


Output
对于每组测试数据，输出对应的结果。如果结果为空字符串，则输出一个空行。

Description

对于字符串，实现以下函数，并编写main函数测试这些函数：

padLeft函数：

功能：将一字符串左填充（在左边填充指定字符）至n个字符的长度，可指定填充字符，比如填充“*”，如果不指定填充字符，则填充空格。

提示：为实现以上功能，函数原型可为：

void  padLeft(char string1[], char string2[],  int n, char padding=' ')

或:

string padLeft(string string1, int n, char padding=' ')

这里使用了默认形参。

string1是原字符串，string2是填充之后的结果。



以下函数都不规定函数原型，请自行设计。

padRight函数：

功能：将一字符串右填充至n个字符的长度，可指定填充字符，比如填充“*”，如果不指定填充字符，则填充空格。

cpy函数：

功能：从第一个字符串复制字符到第二个字符串。可指定复制的起始位置和结束位置，即从startIndex到endIndex之间的所有字符都复制到第二个字符串中。startIndex默认为0， endIndex默认为到字符串尾部。

比如，

cpy(src, dest)： 将src的所有字符都复制到dest

cpy(src, dest, 3)：将src从下标为3的位置直到结尾的所有字符都复制到dest

cpy(src, dest, 3, 5)：将src的第3、4、5个字符复制到dest中

remove函数：

从形参传入一个字符，将该字符从字符串中删除。

remove函数：

从形参传入一个下标index，将index处的字符从字符串中删除。

remove函数：

从形参传入两个下标startIndex和endIndex，将从startIndex到endIndex范围内的字符从字符串中删除。


Input
输入时，每组测试数据包含两行，第一行输入一个整数，代指需要完成的操作，第二行为该操作需要的数据。

对于每个整数对应的操作及其相应数据的输入方式如下（输入的字符串中不包含空格）：

11：对应padLeft，第二行输入字符串string1、整数n，其间以空格分隔（由于没指定填充字符，所以填充空格）

异常处理：如果string1的长度大于等于n，则不填充任何字符。

12：对应padLeft，第二行输入字符串string1、整数n、一个填充字符，其间以空格分隔（填充字符不为空格）

异常处理：如果string1的长度大于等于n，则不填充任何字符。

21：对应padRight，第二行输入字符串string1、整数n，其间以空格分隔（由于没指定填充字符，所以填充空格）

异常处理：如果string1的长度大于等于n，则不填充任何字符。

22：对应padRight，第二行输入字符串string1、整数n、一个填充字符，其间以空格分隔（填充字符不为空格）

异常处理：如果string1的长度大于等于n，则不填充任何字符。

31：对应cpy，第二行输入字符串src

32：对应cpy，第二行输入字符串src和整数startIndex，以空格分隔。复制从startIndex开始的子字符串，下标从0开始。

异常处理：如果startIndex不合法，则不复制任何字符，结果为空字符串。

33：对应cpy，第二行输入字符串src和整数startIndex、endIndex，以空格分隔。

异常处理：如果startIndex、endIndex不合法，则不复制任何字符，结果为空字符串。

41：对应remove，第二行输入字符串和一个字符（以空格分隔），将字符从字符串中删除。

异常处理：如果字符不存在于字符串？如果字符串含多个该字符？如果字符串全是该字符？

42：对应remove，第二行输入字符串和index（以空格分隔），将index处的字符从字符串中删除。

异常处理：如果index不合法，则不删除字符。

43：对应remove，第二行输入字符串和startIndex、endIndex（以空格分隔），将从startIndex到endIndex范围内的字符从字符串中删除。

异常处理：如果startIndex、endIndex不合法，则不删除字符。


Output
对于每组测试数据，输出对应的结果。如果结果为空字符串，则输出一个空行。

Description

对于字符串，实现以下函数，并编写main函数测试这些函数：

padLeft函数：

功能：将一字符串左填充（在左边填充指定字符）至n个字符的长度，可指定填充字符，比如填充“*”，如果不指定填充字符，则填充空格。

提示：为实现以上功能，函数原型可为：

void  padLeft(char string1[], char string2[],  int n, char padding=' ')

或:

string padLeft(string string1, int n, char padding=' ')

这里使用了默认形参。

string1是原字符串，string2是填充之后的结果。



以下函数都不规定函数原型，请自行设计。

padRight函数：

功能：将一字符串右填充至n个字符的长度，可指定填充字符，比如填充“*”，如果不指定填充字符，则填充空格。

cpy函数：

功能：从第一个字符串复制字符到第二个字符串。可指定复制的起始位置和结束位置，即从startIndex到endIndex之间的所有字符都复制到第二个字符串中。startIndex默认为0， endIndex默认为到字符串尾部。

比如，

cpy(src, dest)： 将src的所有字符都复制到dest

cpy(src, dest, 3)：将src从下标为3的位置直到结尾的所有字符都复制到dest

cpy(src, dest, 3, 5)：将src的第3、4、5个字符复制到dest中

remove函数：

从形参传入一个字符，将该字符从字符串中删除。

remove函数：

从形参传入一个下标index，将index处的字符从字符串中删除。

remove函数：

从形参传入两个下标startIndex和endIndex，将从startIndex到endIndex范围内的字符从字符串中删除。


Input
输入时，每组测试数据包含两行，第一行输入一个整数，代指需要完成的操作，第二行为该操作需要的数据。

对于每个整数对应的操作及其相应数据的输入方式如下（输入的字符串中不包含空格）：

11：对应padLeft，第二行输入字符串string1、整数n，其间以空格分隔（由于没指定填充字符，所以填充空格）

异常处理：如果string1的长度大于等于n，则不填充任何字符。

12：对应padLeft，第二行输入字符串string1、整数n、一个填充字符，其间以空格分隔（填充字符不为空格）

异常处理：如果string1的长度大于等于n，则不填充任何字符。

21：对应padRight，第二行输入字符串string1、整数n，其间以空格分隔（由于没指定填充字符，所以填充空格）

异常处理：如果string1的长度大于等于n，则不填充任何字符。

22：对应padRight，第二行输入字符串string1、整数n、一个填充字符，其间以空格分隔（填充字符不为空格）

异常处理：如果string1的长度大于等于n，则不填充任何字符。

31：对应cpy，第二行输入字符串src

32：对应cpy，第二行输入字符串src和整数startIndex，以空格分隔。复制从startIndex开始的子字符串，下标从0开始。

异常处理：如果startIndex不合法，则不复制任何字符，结果为空字符串。

33：对应cpy，第二行输入字符串src和整数startIndex、endIndex，以空格分隔。

异常处理：如果startIndex、endIndex不合法，则不复制任何字符，结果为空字符串。

41：对应remove，第二行输入字符串和一个字符（以空格分隔），将字符从字符串中删除。

异常处理：如果字符不存在于字符串？如果字符串含多个该字符？如果字符串全是该字符？

42：对应remove，第二行输入字符串和index（以空格分隔），将index处的字符从字符串中删除。

异常处理：如果index不合法，则不删除字符。

43：对应remove，第二行输入字符串和startIndex、endIndex（以空格分隔），将从startIndex到endIndex范围内的字符从字符串中删除。

异常处理：如果startIndex、endIndex不合法，则不删除字符。


Output
对于每组测试数据，输出对应的结果。如果结果为空字符串，则输出一个空行。

每行行首与行尾无多余空格，第一行之前与最后一行之后无多余空行。

Sample Input 1 

11
abcdefgh 10
12
abcdefgh 10 *
21
abcdefgh 10
22
abcdefgh 10 *
31
abcdefgh
32
abcdef 1
33
abcdef 1 5
41
abcdef a
42
abcdef 1
43
abcdef 1 4

Sample Output 1

  abcdefgh
**abcdefgh
abcdefgh  
abcdefgh**
abcdefgh
bcdef
bcdef
bcdef
acdef
af
*/

#include <iostream>

using namespace std;

int main() {


    return 0;
}