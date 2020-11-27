# Wrapper or Abstraction Layer

经常发现一些简单的函数被包起来，封装成另一个函数，比如

```c
FILE *My_Open(const char *name)
{
    return fopen(name, "r");
}
```

有两种可能，

- 其一与设计模式无关，作者可能想创造自己的库，所以希望所有的函数都以某个特定的前缀开头。
- 其二是从设计模式的角度考虑。

调用wrapper的函数称之为client或者consumer，wrapper内的是implementation，这样，implementation对于client来说是透明的，即client不知道implementation是什么，implementation将自己**隐藏**了起来。这样做，表面的好处是，client一端会非常的**清晰**，不会被某个具体的细节而打破自己整体的逻辑流程。

再往深处讲，如果将来可以预见会改动该implementation，那么所有的修改只会涉及一处（wrapper内），client端不会察觉因而也无须修改。所以wrapper相当于abstraction layer，它的作用是提供**接口**（输入和输出），通过间接调用其它“实现”的方式，达到**解耦**的目的。

# Improvement to The Example

示例中，只是把从函数名的角度隐藏了实现方式，一个好的wrapper应该将输入输出都进行一下包装，比如

```c
struct context * My_Open(const char *name);
```

原来我们可以prototype猜测出该函数一定是打开一个文件，但现在不好说，它可以是文件、数据库、二进制等等（当然可以称它们都为文件，但不要太泛化），而“实现”可以灵活地利用这些结构，既保证更新自己又能解耦client。

# Concrete Example

See `wrapper.c`.

*Note*: I know the file has many flaws, such as source release problem. But it's only used to demonstrate and suffice. Improve later.