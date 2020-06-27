## 设置编译器选项
---
### 如何工作
本例中，警告标志有-Wall、-Wextra和-Wpedantic，将这些标示添加到geometry目标的编译选项中； compute-areas和 geometry目标都将使用-fPIC标志。编译选项可以添加三个级别的可见性：INTERFACE、PUBLIC和PRIVATE。

可见行含义为：

* `PRIVATE`：编译选项会应用于给定的目标，不会传递给与目标相关的目标
* `INTERFACE`：给定的编译选项将只用于制定目标，并传递给与目标相关的目标
* `PUBLIC`：编译选项将应用于指定目标和使用它的目标

**NOTE**:我们推荐为每个目标设置编译器标志。使用target_compile_options()不仅允许对编译选项进行细粒度控制，而且还可以更好地与CMake的更高级特性进行集成