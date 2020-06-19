文件操作常函数

fopen 函数 
    函数原型为：FILE *fopen(const char *filename,const char *mode);
          fopen(文件路径，文件使用方法)；
          fopen函数打开打开filename指定文件，返回一个指向FILE类型指针，无论使用哪种方式，当打开文件时出现了错误，fopen函数都将会返回NULL
常见的使用方式：
    "r" ---以只读的方式打开文件（该文件必须存在，不存在就会出错）
    "w" ---以只写的方式打开文件 （若文件存在则长度清零，即文件内容会消失，若不存在则建立该文件）
    "a" ---以只写的方式打开文本文件，位置指针移到文件末尾，向文件尾部添加数据，原文件数据保留，若文件不存在则报错
    "+" ---与上面的字符串组合，表示以读写的方式打开文本文件，即向文件中写入数据，也可以从文件中读取数据
    "b" ---与上面的字符串结合，表示打开二进制文件。

例： err =fopen_s(&fp,"E:\\ww.txt","w");

fclose()函数
    fclose(文件指针);
    若文件关闭成功则返回0，否则返回非0

fread()函数
        函数原型：unsigned int fread(void *buffer, unsigned int size, unsigned int count, FILE *fp)；

    函数功能：从fp所指的文件中读取数据块并存储到buffer所指向的内存中，buffer是待读入数据块存储的起始地址，size是每个数据块的大小（待读入的每个数据块的字节数），count是最多允许读取的数据块个数（每个数据块size个字节），函数返回的是实际读到的数据块个数。

fwrite()函数
    函数原型：unsigned int fwrite（const void *buffer, unsigned int size, unsigned int count, FILE *fp）；
    函数功能：将buffer指向的内存中的数据块写入fp所指的文件，buffer是待输出数据块的起始地址，size是每个数据块的大小（待输出的每个数据块的字节数），

　　count是最多允许写入的数据块个数（每个数据块size个字节），函数返回的是实际写入的数据块个数。

    fread（）函数和fwrite（）函数是按数据块的长度来处理输入/输出的，在用文本编辑器打开文本文件时可能因发生字符转换而出现莫名其妙的结果，所以这两个函数通常用于二进制文件的输入/输出。
fscanf()函数

　　函数原型：int fscanf (FILE *fp, const char *format, ……);

　　fscanf(文件指针, 格式字符, 输入列表);

　　第一个参数为文件指针，第二个参数为格式控制符，第三个参数为地址参数表列，后两个参数与函数scanf（）的参数相同
fprintf()函数

　　函数原型：int fprintf (FILE *fp, onst char *format, ……)；

　　fprintf(文件指针, 格式字符, 输出列表);

　　第一个参数为文件指针，第二个参数为格式控制参数，第三个参数为输出参数列表，后两个参数和返回值与函数printf（）相同

　 （用函数fscanf（）和fprintf（）进行文件的格式化读写，读写方便容易理解，但输入时要将ASCII字符转换成二进制数，输出时要将二进制数转换为ASCII字符，耗时较多）

fgets()函数

　　函数原型：char *fgets（char *s，int n，FILE *fp）；

　　函数功能：该函数从fp所指的文件中读取字符串并在字符串末尾添加‘\0’，然后存入s，最多读n-1个字符，当读到回车换行符、到达文件尾或读满n-1个字符时，就停止读取

　　函数返回该字符串的首地址，即指针s的值，读取失败返回空指针NULL

　　（与gets()不同的是，fgets()从指定的流读取字符串，读到换行符时将换行符也作为字符串的一部分读到字符串中来）
fputs()函数

　　函数原型：fputs(_In_z_ const char * _Str, _Inout_ FILE * _File);

　　str是要输出的字符串，fp是文件指针，字符串末尾'\0'不输出

　　函数功能：将字符串输出到指针fp所指的文件中

　　（与puts()不同的是，fputs()不会在写入文件的字符串末尾加上换行符'\n'）
   fgetc()函数

　　函数原型：int fgetc (FILE *fp);

　　函数功能：用于从一个以只读或读写方式打开的文件上读字符，从fp所值的文件中读取一个字符，并将位置指针指向下一个字符，若读取成功，则返回该字符，

　　若读取不成功则返回EOF（EOF是一个符号常量，stdio.h中定义为-1）
fputc()函数

　　函数原型：int fputc（int c, FILE *fp）；

　　fp是由函数fopen（）返回的文件指针，c是要输出的字符（尽管C定义为int型，但只写入低字节）

　　函数功能：该函数的功能是将字符c写到文件指针fp所指的文件上中，若写入错误返回EOF，否则返回字符c
 
    文件的定位

　　文件的随机读写：文件的随机访问允许在文件中随机定位，并在文件的任何位置直接读写数据，为了实现文件的定位，在每一个打开的文件中，都有一个文件位置指针，

　　也称为文件位置标记，用来指向当前读写文件的位置，它保存了文件中的位置信息，当文件进行顺序读写时，每读完一个字节后，该位置指针自动移到下一个字节的位置，

　　当需要随机读写文件数据时，则需强制移动文件位置指针指向特定的位置

 

　　fseek()函数

　　函数原型：int fseek（FILE *fp，long offset，int fromwhere）；

　　函数功能：将fp的文件位置指针从fromwhere开始移动offset个字节指示下一个要读取的数据的位置

　　offset是一个偏移量，它告诉文件位置指针要跳过多少字节，offset为正时，向后移动，为负时，向前移动，ANSIC要求位移量offset是长整型数据（常量数据后要加L），

　　这样当文件的长度大于64k时不至于出问题

　　fromwhere用于确定偏移量计算的起始位置，它的可能取值有3种，SEEK_SET或0，代表文件开始处，SEEK_CUR或1，代表文件当前位置，SEEK_END或2，代表文件结尾处，

　　通过指定fromwork和offset的值，可使位置指针移动到文件的任意位置，从而实现文件的随机读取，如果函数fseek（）调用成功，则返回0值，否则返回非0值

　　两种特殊使用方式：

　　将读写位置移动到文件开头:fseek(FILE *stream,0,SEEK_SET);
　　将读写位置移动到文件尾:fseek(FILE *stream,0,0SEEK_END);

　（fseek() 一般用于二进制文件，在文本文件中由于要进行转换，计算的位置有时会出错）

 

　　rewind()函数

　　函数原型：void rewind（FILE *fp）；

　　函数功能：将文件位置指针指向文件首字节，即重置位置指针到文件首部

 

　　ftell()函数

　　函数原型：long ftell（FILE *fp）；

　　函数功能：读取当前文件指针的位置,若函数调用成功，则返回文件的当前读写位置，否则返回-1L，函数ftell（）用于相对于文件起始位置的字节偏移量来表示返回的当前位置指针

　　（需要注意的是，当用err = fopen_s(&fp, "E:\\ww.txt", "a+");打开文件后文件指针移到文件末尾，此时文件起始位置还是为文件头部并不是文件末尾）

 

　　　文件检测

　　ferror()函数

　　函数原型：int ferror（FILE *stream）；

 　　函数功能：它的一般调用形式为 ferror(fp)；如果ferror返回值为0（假），表示未出错。如果返回一个非零值，表示出错。应该注意，对同一个文件 每一次调用输入输出函数，

　　均产生一个新的ferror函数值，因此，应当在调用一个输入输出函数后立即检 查ferror函数的值，否则信息会丢失。在执行fopen函数时，ferror函数的初始值自动置为0

 

　　feof()函数

　　函数原型：int feof（FILE *fp）；

　　函数功能：检测流上的文件结束符，如果文件结束，则返回非0值，否则返回0，文件结束符只能被clearerr()函数清除

　 （函数feof（）总是在读完文件所有内容后再执行一次读文件操作（将文件结束符读走，但不显示）才能返回真（非0）值）

 

　　C语言为了提高数据的输入/输出的速度，在缓冲型文件系统中，给打开的每一个文件建立一个缓冲区，文件内容先被批量地读入缓冲区，程序进行读操作时，实际上是从缓冲区中读取数据，

　　写入操作也是如此，首先将数据写入缓冲区，然后在适当的时候（例如关闭时）再批量写入磁盘，这样虽然可以提高I/O的性能，但也有一些副作用，例如在缓冲区内容还未写入磁盘时，

　　计算机突然死机或掉电，数据就会丢失，永远也找不回来，再如缓冲区被写入无用的数据时，如果不清除，其后的文件读操作都首先要读取这些无用的数据

　　为了解决这个问题C语言提供了fflush（）函数

 

　　fflush()函数

　　函数原型：int fflush（FILE *fp）；

　　函数功能：清除缓冲区的内容，对于输出流来说，fflush函数将已经写到缓冲区但尚未写入文件的所有数据写到文件中，对输入流来说，其结果是未定义的，

　　如果在写的过程中发生错误，则返回EOF，否则返回0，（函数功能的另一种描述：无条件的将缓冲区的所有数据写入物理设备，这样程序员可自己决定何时清除缓冲区中的数据，以确保输出缓冲区的内容写入文件）

　　ftell()函数

　　函数原型：long ftell（FILE *fp）；

　　函数功能：读取当前文件指针位置，若函数调用成功，则返回文件的当前读写位置，否则返回-1L

　　（函数ftell（）用于相对于文件起始位置的字节偏移量来表示返回的当前位置指针）

 

　　fflush(stdin)；刷新标准输入缓冲区，把输入缓冲区里的东西丢弃[非标准]

　　fflush(stdout)；刷新标准输出缓冲区，把输出缓冲区里的东西打印到标准输出设备上

　　fflush(NULL)；将清洗所有的输出流

 

　　由于ANSIC规定函数fflush（）处理输出数据流、确保输出缓冲区中的内容文件，但并未对清理输入缓冲区作出任何规定，只是部分编译器增加了此项功能，因此使用fflush(stdin)来清除缓冲区的内容，可能会带来移植性的问题

　　（fflush on input stream is an extension to the C standard（fflush 操作输入流是对 C 标准的扩充））

　　使用 fflush(stdin)是不正确的，至少是移植性不好的，因为那样的代码在一些环境下可能正常工作，但在另一些环境下则会出错，这导致程序不可移植，所以只能在写入文件的时候使用fflush

　　

    标准输入/输出重定向
实际上，对于终端设备，系统会自动打开3个标准文件：标准输入、标准输出和标准错误输出，相应的，系统定义了3个特别的文件指针常数：stdin、stdout、stderr，

分别指向标准输入、标准输出和标准错误文件，这3个文件都以标准终端设备作为输入/输出对象，在默认情况下，标准输入设备时键盘，标注输出设备是屏幕

fprintf（）是printf（）的文件操作版，二者的差别在于fprintf（）多了一个FILE *类型的参数fp，如果为其提供的第1个参数时stdout，那么它就和printf（）完全一样，

同理可推广到fputc（）和putchar（）等其他函数，

例如：

putchar（c）；和fputc（c，stdout）；等价

getchar（）；和fgetc（stdin）；等价

puts（str）和fputs（str，stdout）；等价

但函数fgets（）与gets（）不同，从如下函数原型可知其区别在于fgets（）还多了一个参数size

char *fgets（char *s，int size，FILE *stream）；

char *gets（char *s）；

fgets（）用其第二个参数size来说明输入缓冲区的大小，使读入的字符数不能超过限定缓冲区的大小，从而达到防止缓冲区溢出攻击的目的，

假如已定义一个有32字节的缓冲区buffer[32]，那么在下面两条读字符串的语句中，后者的安全性更高

gets（buffer）；

fgets（buffer，sizeof（buffer），stdin）；//安全性更高

虽然系统隐含的I/O是指终端设备，但其实标准输入和标准输出是可以重新定向的，操作系统可以重新定向它们到其他文件或具有文件属性的设备，只有标准错误输出不能进行一般的输出重定向，

例如，在没有显示器的主机上，把标准输出定向到打印机，各种程序不用做任何改变，输出内容就自动从打印机输出

 

这里用“<”表示输入重定向，用“>”表示输出重定向，例如：假设exefile时可执行程序文件名，执行该程序时，需要输入数据，现在如果要从文件file.in中读取数据，而非键盘输入，

那么在DOS命令提示符下，只要键入如下命令行即可

C:\exefile<file.in

于是exefile的标准输入就被“<”重定向到了file.in,c此时程序exefile只会专心致志地从文件file.in中读取数据，而不再理会你此后按下的任何一个按键，

再如，若键入如下命令行

C:\exefile>file.out

于是，exefile的标准输出就被“>”重定向到了文件file.out中，此时程序exefile的所有输出内容都被输出到了文件file.out中，而屏幕上没有任何显示

例：

复制代码


 1 #include <stdio.h>
 2 
 3 main()
 4 {
 5     int c;
 6 
 7     scanf_s("%d", &c);
 8     printf("%d", c);
 9 
10     return 0;
11 }


复制代码
 

将exe文件移到E盘，新建一个te.txt输入10然后保存，打开DOS命令行，转到E盘，输入test1.exe<te.txt回车，则te.txt文件中的10作为输入值，输出值为10



 

 

5、文件操作补充
因为在Microsoft Visual C++ 2010 Express中使用fopen,fscanf等函数编译器会显示警告，

This function or variable may be unsafe. Consider using fopen_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.

所有在文件操作时将改用fopen_s、fscanf_s等函数

　　fopen_s()函数

　　函数原型：errno_t fopen_s( FILE** pFile, const char *filename, const char *mode );

　　pFile----文件指针将接收到打开文件指针指向的指针

    infilename----文件名

    mode----允许访问的类型

　　fopen_s()打开文件成功返回0值，否则返回非0值

　　须定义另外一个变量errno_t err

　　例：



1 FILE *fp;
2 errno_t err;
3 err = fopen(&fp,"E:\\ww.txt","r");
 

 

这里的errno_t是int的别名，在编译器crtdef.h头文件中有typedef int errno_t;

　　fopen()与fopen_s()的区别

　　fopen_s()函数比fopen()函数多了一个溢出检测，安全性上有所提升,在使用形式上fopen_s()比fopen()多使用了一个参数，

　　需要特别注意的是：

　　fopen的返回值是FILE *，返回的是指向结构体类型的指针

　　而fopen_s的返回值是errno_t，返回的是errno_t(int)类型的数值

　　例：fopen()函数


1 fp = fopen("E:\\ww.txt", "r");
　　　　fopen_s()函数


1 errno_t err;
2 err = fopen_s(&fp,"E:\\ww.txt","r");
 

　　fscanf_s()函数

　　函数原型：fscanf_s(_Inout_ FILE * _File, _In_z_ _Scanf_s_format_string_ const char * _Format, ...);

　　fscanf_s和fscanf的区别

　　在使用形式上fopen_s()比fopen()多使用了一个参数,第四个参数是字节数（注意长度（strlen）和字节数（sizeof）的区别）



　　例：fscanf()函数

1 fscanf(fp, "%c", &c);
　　　　　fscanf_s()函数

1 fscanf_s(fp, "%c", &c,sizeof(char));
 

6、上述文件操作函数代码示例
（前提条件：在E盘根目录下新建一个txt文档命名为ww.txt，内容输入about保存）

　

fopen()函数----fopen(文件路径, 文件使用方式);

1 FILE *fp;
2 fp = fopen("E:\\ww.txt", "r");
　

fopen_s()函数----fopen_s(指向该文件指针的指针, 文件路径, 文件使用方式);

1 errno_t err;
2 err = fopen_s(&fp, "E:\\ww.txt", "r");
　

fread()函数----fread(内存首地址, 数据块大小, 数据块个数, 文件指针);

1 char ss[20];
2 fread(ss, sizeof(char), 4, fp);
　

fwrite()函数----fwrite(内存首地址, 数据块大小, 数据块个数, 文件指针);

1 char ss[20] = "aabb";
2 fwrite(ss, sizeof(char), 4, fp);
　

fscanf_s()函数----fscanf_s(文件指针, 格式参数, 存入地址, 字节数)

1 fscanf_s(fp, "%c", &c,sizeof(char));
 

fprintf()函数----fprintf(文件指针, 格式参数, 输出列表)

1 char c = 'a';
2 fprintf(fp, "%c", c);
 

fseek()函数----fseek(文件指针, 指针偏移量, 起始位置);

1 fseek(fp, sizeof(char), SEEK_SET);
　

fgets()函数----fgets(内存首地址, 字符数, 文件指针);

1 char ss[20];
2 fgets(ss, 20, fp);
 　

fgetc()函数----fgetc(文件指针);

1 char ss[20];
2 ss[0] = fgetc(fp);
3 printf("%c", ss[0]);
 　

fputc()函数----fputc(变量名, 文件指针)

1 int c = 'a';
2 fputc(c, fp);
也可写成

fputc('c', fp);
　　

fputs()函数----fputs(字符串, 文件指针)

1 char ss[20] = "aaaa";
2 fputs(ss, fp);
 也可写成

1 fputs("aaaa", fp);






















