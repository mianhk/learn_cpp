
> 涉及到函数之后，我认为已经是基础的较后面的部分，因为这开始慢慢涉及到了一门语言的思想观念，设计的想法，以及对编程人员的要求。所以这些部分不知道要知道怎么用，更要知道为什么会这样。当然第一遍看的时候，也没有多少编程经验，可能无法有更多的想法，只能跟着书里慢慢理解了。

# 6.1 函数基础
## 形参和实参：
实参是形参的初始值，函数的形参列表可以为空。
局部静态对象，定义成static类型，在程序的执行路径第一次经过对象定义语句时初始化，并且知道程序终止才被销毁，在此期间即使对象所在的函数结束执行也不会对它有影响。
# 6.2 参数传递
如果形参是引用类型，它将绑定到对应的实参上，称为引用传递；否则，将实参的值拷贝后赋给形参，称为值传递。
## 6.2.1 传值参数
将实参的值拷贝给形参。当是指针形参时，指针的行为和其他非引用类型一样，执行指针拷贝类型时，拷贝的是指针的值。拷贝之后是不同的指针，但是指向的是相同的值，我们可以在函数中修改指针所指对象的值。在C++中，建议使用引用类型的形参替代指针。
## 6.2.2 传引用参数
** 1.使用引用避免拷贝。 **因为有的类类型是不能拷贝的，或者在拷贝一些大的类类型对象或者容器对象比较低效。
如果函数不需要改变引用参数的值，最好将其声明为常量引用。
** 2.使用引用形参返回额外信息。**由于函数不能有多个返回值，在我们需要返回多个值的时候，可以额外传一个引用参数。
** 3.可以直接操作引用形参所引的对象。 **
## 6.2.3 const形参和实参
和其它初始化一样，当用实参初始化形参时会忽略掉顶层const。也就是，形参的顶层const会被忽略掉。（这个可以思考一下，我们可以通过形参的const在参数中控制是否需要改变形参，以及对应的实参，这样更方便我们传参数。当然有了这个我们就不能重载有无const的两个函数了，因为会被编译器相同对待。）
尽量使用常量引用，除了在使用的时候，无法把常量引用初始化为引用（很简单的道理），另外，也会给调用者一种误导。
## 6.2.4 数组形参
无法以值传递的方式使用数组参数。数组的特点：不允许拷贝、使用数组会将其转化为指针。
```
void print(const int*);
void print(const int[]);
void print(const int[10]);  //这里的维度表示我们期望数组含有多少个元素，实际不一定
```
### 关于数组长度
由于传递数组引用的时候，只是数组的首元素指针，所以有时候我们需要在形参定义的时候，就将数组大小传递给形参。这里有几种方式。
## 6.2.5 mian处理命令行选项
当使用argv[]中的实参时，第一个实参保存的是程序名，所以应该从第二个开始。
## 6.2.6 含有可变形参的函数
有时候我们预先不知道向函数传递几个实参。1.如果所有的实参类型相同，可以传递名为initializee_list的标准库类型；2.如果实参类型不同，可以编写一种特殊的函数，也就是所谓的可变参数模板。
# 6.3 返回类型和return语句
return语句终止当前执行的函数，并将控制权返回到调用该函数的地方。
return语句不要返回局部对象的引用或引用（因为局部对象会在函数调用完成后删除，会产生未定义的结果）。
c++11新标准中函数可以返回花括号包围的值列表，主函数main的返回值，非0的返回值由机器决定。
# 6.4 函数重载
拥有顶层const不影响传入函数的对象。另外，如果形参是某种类型的指针或引用，则通过区分其指向的是常量对象还是非常量对象可以实现函数重载，此时的const是底层的。
不能仅仅通过函数的返回值区分两个同名的函数
## 重载与作用域
一般来说，将函数声明置于局部作用域内不是一个明智的选择。在不同的作用域中无法重载函数名。
在c++中，名字查找发生在类型检查之前。
# 6.5 特殊用途语言特性
大多数程序都有用的特性：默认实参、内联函数、constexpr函数。
## 默认实参
一旦某个形参赋予了默认值，后面的所有形参必须有默认值。函数调用时，实参按其位置进行解析，只能省略尾部的实参。
一个函数被声明多次的时候，在给定的作用域中一个形参只能被赋予一次默认实参，也就是函数的后续声明。
## 内联函数inline
将它在每个调用点上“内联的”展开，一般来说用于优化规模较小、流程直接、频繁调用的函数。
## constexpr函数
constexpr函数指能用于常量表达式的函数。函数的返回值及所有形参的类型都得是字面值类型，并且函数体中必须有且只有一条return语句。
编译器把对constexpr函数的调用替换成其结果值。为了能在编译过程中随时展开，constexpr函数被隐式的指定 为内联函数.
内联函数和constexpr函数通常定义在头文件中.
## 调试帮助
assert预处理宏,以一个表达式作为条件.
我们可以使用一个#define 语句定义NDEBUG，关闭调试状态
# 6.6 函数匹配
当几个重载函数的形参数量相等以及某些形参的类型可以由其它类型转换得来时。
## 确定候选函数和可行函数
函数匹配第一步：选定本次调用对应的重载函数集。
候选函数的两个特征：与被调用的函数同名，其声明在调用点可见。
第二步考察本次调用提供的实参，从候选函数中选出能被这组实参调用的函数。
## 实参类型转换
确定最佳匹配的排序：
* 1.精确匹配：实参形参类型相同，实参从数组或函数类型转化为对应的指针类型，实参添加顶层const或者从实参中删除顶层const。
* 2.通过const转换实现的匹配。
* 3.通过类型提升实现的匹配。
* 4.通过算术类型转换或指针转换实现的匹配。
* 5.通过类类型转换实现的匹配。
# 6.7 函数指针
函数指针指向的是函数而非对象。和其他指针一样，函数指针指向某种特定类型。函数的类型由它的返回类型和形参类型共同决定，与函数名无关。
## 重载函数的指针
编译器通过指针类型决定选用哪个函数，指针类型必须与重载函数中的某一个精确匹配。
## 函数指针形参
和数组类似，虽然不能定义函数类型的形参，但是形参可以是指向函数的指针。此时，形参看起来是函数类型，实际上是被当成指针使用。
可以直接把函数当成实参使用，会自动转换成指针。