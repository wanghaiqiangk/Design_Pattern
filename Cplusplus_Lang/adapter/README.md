# Client & Adapter & Adaptee

Client是希望调用某个方法的一方，它一般不能修改。

Adaptee是希望被Client调用使用的一方，由于接口不一致等原因，不能直接被使用。

Adapter是通过适配，既符合Client的接口要求，又可以调用Adaptee的功能，的一方，也是我们要写代码实现的内容。

也就是说，Client和Adaptee都已经有了，本来应该相互交互，但接口不匹配。通过Adapter如何让水火不融的两者能够和谐共处呢？

两种方法：

- Object Adapter
- Class Adapter

首先，Adapter要**继承Client定义的接口**，这样就符合Client的要求因而Client就可以操作Adapter。

然后，如果是object adapter，那么Adapter的内部成员之一是Adaptee；如果是class adapter，那么Adapter也会继承Adaptee。选择哪种，据说有compile-time和run-time上的差异。无论如何，这样Adapter总是可以调用Adaptee的方法。

