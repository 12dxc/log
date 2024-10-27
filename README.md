## 异步流式日志库

### 支持四种日志级别
+ debug
+ info
+ warring
+ error

### 有两种使用方式
```cpp
LOG(INFO) << "hello" << ENDL;
LOG_INFO << "hello" << ENDL;
``` 
### 后期扩展
- [ ] 支持C++23 的`print`式风格
- [ ] 支持写入文件

