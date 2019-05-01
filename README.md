### **这两段代码的起源**
<p>昨晚（2019.4.30）吃完饭上楼，有一同事说了个问题，然后大家就饭后闲聊讨论了一下。下班回来之后，就写了代码验证了一下是否就是计算的那样。写好验证完毕，跟舍友提起这个问题，他看了代码之后，写出了一个另一个版本的。看了他写的代码，突然觉得很震惊，虽然大家工作时间说久不久，但是已经开始产生因为环境和目的性带来的差异。</p>
<p>两人背景，我个人一直写工程代码做项目，可读性维护性，团队协同效率是最优先。他从研究生到现在都是在做算法相关，读论文学算法（AI相关），然后写代码快速验证和实现。</p>
<p>虽然也是我们昨晚写代码本来目的性就不同，他就是为了快速写出来，并尽量简短，而我本来在目的 就是跟几个同事展示模拟的流程，快速review，检查流程漏洞。但还是Be Shocked，想一下我居然已经开始潜移默化的思维习惯固化，自己却没有认识到。还有一个点，对于矩阵的使用，我居然在自己脑海中扼杀了这么好的数据结构，而只把它作为一个数学工具。</p>

### **昨天那个问题**
一个简单的概率问题（只是大家长时间不接触，很多都忘记了）
* 有红球3个，蓝球3个
* 3个桶
    * 一个桶2个红球
    * 一个桶2个蓝球
    * 一个桶1红1蓝
* 随机摸一个球，摸出了红球，问桶中第二个球是红球的概率？

### **补充**
* 两个源代码文件
    * c.cpp
    * p.py
* 直接点击.sln执行就可以看到模拟结果
* 也可以用CMakeLists.txt自己生成
* 工程里面有截图，是两段代码跑出来的模拟数据

### **PS**
认识这么久，还不知道原来挺厉害的至少比某个写JS的不知道强多少