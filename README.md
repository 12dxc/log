## 支持C++20fmt风格的日志库

### 支持四种日志级别
+ debug
+ info
+ warning
+ error

### 使用方式
```cpp
info("hello{}", 123);
```

### 设置过滤日志等级
```cpp
setLevel(level::debug);
```

### 后期扩展

- [ ] 支持流式风格日志
- [ ] 支持写入文件

