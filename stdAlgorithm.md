## 常用的一些stl中的算法

- `iota`：以始于`value`并重复地求值`++value`的顺序递增值填充范围`[first, last)`
```
void iota( ForwardIterator first, ForwardIterator last, T value )
```

- `lcm`与`gcd`：最小公倍数与最大公约数，（`c++17` 起）

- `upper_bound`和`lower_bound`：二分查找
```
ForwardIt upper_bound( ForwardIt first, ForwardIt last, const T& value, Compare comp );
ForwardIt lower_bound( ForwardIt first, ForwardIt last, const T& value, Compare comp );
```
`upper_bound`：返回指向范围`[first, last)`中首个大于`value`的元素的迭代器，或若找不到这种元素则返回`last`。
`lower_bound`：返回指向范围`[first, last)`中首个不小于（即大于或等于`>=`）`value`的元素的迭代器，或若找不到这种元素则返回`last`。

注1：使用上述两个函数可以找到数据中等于某个值的区间（左闭右开，默认只能按照升序进行比较）
注2：当然也可以使用`lower_bound`来进行普通的精确二分查找操作

- `distance`与`advance`：迭代器距离
```
void advance( InputIt& it, Distance n );
typename std::iterator_traits<InputIt>::difference_type distance( InputIt first, InputIt last );
```
`advance`：增加给定的迭代器`it`以`n`个元素的步长。（如何`it`为`begin`迭代器，则`n`就为走到的索引）
`distance`：返回从`first`到`last`的路程。（也可以是负数）

- `accumulate`：求和
```
T accumulate( InputIt first, InputIt last, T init, BinaryOperation op );
```
`accumulate`：计算给定值`init`与给定范围`[first, last)`中元素的和

- `unique`：去重
```
ForwardIt unique( ForwardIt first, ForwardIt last );
```
`unique`：从来自范围`[first, last)`的相继等价元素组消除首元素外的元素，并返回范围的新逻辑结尾的尾后迭代器。

注1：相继等价元素，也就是说必须得先排序
注2：返回的是尾部迭代器，因此可以方便的使用`arr.erase(unique(arr.begin(), arr.end(), arr.end())`删除数组中重复元素。

- `all_of`,`any_of`,`none_of`
```
bool all_of( InputIt first, InputIt last, UnaryPredicate p );
bool any_of( InputIt first, InputIt last, UnaryPredicate p );
bool none_of( InputIt first, InputIt last, UnaryPredicate p );
```
`all_of`：检查一元谓词`p`是否对范围`[first, last)`中所有元素返回`true`。
`any_of`：检查一元谓词`p`是否对范围`[first, last)`中至少一个元素返回`true`。
`none_of`：检查一元谓词`p`是否不对范围`[first, last)`中任何元素返回`true`。

注1：`p`可以是个`lambda`函数，类似sort中使用的那个


