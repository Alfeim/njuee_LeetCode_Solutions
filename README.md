# 本项目为Njueers所共享

仓库内容主要为平时刷题的submit、遇到的一些经典题解、coding时所作的笔记等

Basic Knowledge文件夹下为一些基础但相对重要的C++知识点/笔记

Cpp文件夹下主要为本人提交记录

Leukart文件夹下为合作者Leukart的提交记录


# 重要记录

2019/07/06 新增 164. Maximum Gap,如果对排序时间复杂度要求为O(N),考虑空换时的方式,典型代表为桶排序

2019/07/10 新增 214. Shortest Palindrome,为了满足时间复杂度要求,这里求回文串使用Manacher算法

2019/07/11 新增 224. Basic Calculator,求表达式的值,一般思路是把常规的“中缀表达式”转换为“逆波兰式”(后缀表达式),然后计算(用栈很方便)
转换方法可见:https://oi-wiki.org/basic/expression/

2019/07/11 新增 229. Majority Element II,类似求一个数组中,超过一定重复次数的数,可以考虑摩尔投票算法

2019/07/17 新增 307. Range Sum Query - Mutable,在求解类似动态连续区间问题时,树状数组和线段树十分高效,相关内容见:https://www.cnblogs.com/TenosDoIt/p/3453089.html(线段树)      https://www.cnblogs.com/xenny/p/9739600.html(树状数组)

2019/07/23 新增 382. Linked List Random Node,在求很大状态空间数据的随机抽样问题时,可以利用蓄水池抽样法,见https://www.jianshu.com/p/7a9ea6ece2af

2019/07/25 新增363. Max Sum of Rectangle No Larger Than K,求解矩阵的最大区域和类型问题可以参考
https://www.cnblogs.com/huashanqingzhu/p/8684624.html

2019/08/03 新增456. 132 Pattern 巧妙利用栈来解决问题,可以学习一下思维

2019/08/04 新增464. Can I Win 是一道记忆化搜索的典型题目

2019/08/05 吔*啦 梁非凡！

2019/08/06 新增478. Generate Random Point in a Circle 一道典型的拒绝采样的应用.其思想是要在限制条件内随机采样,只需要先随机采样再判断是否满足限制条件即可,如果不满足就重新再采

2019/08/09 新增480. Sliding Window Median 很多情况下,中位数问题都可以用大小堆来做.只需要维护小顶堆的元素个数不少于大堆的元素个数,也不必大堆的元素个数多1以上即可.

2019/08/14 新增493. Reverse Pairs 类似逆序对的问题(即first的下标小于second的小标但是满足first的条件优于second的条件),都可以用分治(类似归并排序)的方法来做

2019/08/16 更新《动态规划问题集合》,新增比较典型的  542. 01 Matrix 与 514. Freedom Trail

2019/08/18 新增496. Next Greater Element.cpp ; 类似地,要找右边比当前元素大的第一个元素使用递减栈,反之,如果时第一个更小的元素则用递增栈 

2019/08/19 更新《tips》,新增位运算技巧 :   大写变小写、小写变大写  :  字符 ^= 32;        大写变小写、小写变小写  :  字符 |= 32;
小写变大写、大写变大写  :  字符 &= -33;

2019/08/23 更新《动态规划问题集合》,新增600. Non-negative Integers without Consecutive Ones

2019/08/24 新增629. K Inverse Pairs Array,需要注意的是,这种因为结果很大要对一个大数取模的题,应当先加上模的值再取模防止出现负数!

2019/08/29 新增684. Redundant Connection,本体使用了一种巧妙的数据结构(DSU)用于并查集,该结构主要包含两个方法:find(查找公共祖先)和merge(合并两个分支).同时维护一个数组parents[i]记录i节点的父元素.而祖先节点的父元素即是本身.为了简化复杂度,使用了按秩合并的方法,即用rank[i]表示i节点的孩子量级,每次合并时总是让小的量级作为大量级的孩子.

2019/09/03 新增679. 24 Game 这是表达式求解一类的经典和基石的问题，通过这个问题，我们可以解决更多其他问题，如给表达式添加优先级等。

2019/09/10 更新《设计模式笔记》,新增工厂方法模式
