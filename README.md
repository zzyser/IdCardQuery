# IdCardQuery
通过in.txt的身份证号生成对应身份信息到out.txt

**一、设计目标**

​		设计一个身份证类，类里包含对应要求的函数方法，在主函数里每读写一次就调用一次身份证类对应的实体。

​		in.txt文件记录将查询的身份证号，

​		out.txt文件为所生成的文件，记录所输出信息

​		身份证归属地数据库.txt	中记录所有合法的身份证号码前6位所对应的户口所在地信息	

**二、运行环境**

**Visual studio 2022  C++11**

**三、实现功能**

​		类中方法实现：读取对应文件中的身份证号码，并判断是否正确，然后在另一个文本文件中输出 身份证号码、户口所在地、性别、出生日期、农历日期、年龄、距离下一次生日的天数、星座以及生肖。

​	通过读取in.txt的每一行身份证号，先判断是否为合法身份证号，再根据号码输出所有信息到out.txt文件中
