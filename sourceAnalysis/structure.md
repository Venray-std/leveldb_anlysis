./include/leveldb
#### slice.h
为操作数据的方便，将数据和长度包装成 Slice 使用，直接操控指针避免不必要的数据拷贝。
维护data("")和size(n)。slice.h相当于内含字符串。

#### export.h
预编译LEVELDB_EXPORT

#### status.h
It may indicate success, or it may indicate an error with an associated error message.
返回状态及状态码，维护一个成员变量state

#### iterator.h
以yield的形式返回source的key/value对

#### c.h
暴露接口

#### cache.h
声明缓冲区

#### comparator.h
slice的比较器
```
virtual void FindShortestSeparator(std::string* start,
                                     const Slice& limit) const = 0;
```
切割字符串 
If *start < limit, changes *start to a short string in [start,limit).

```
virtual void FindShortSuccessor(std::string* key) const = 0;
```
#### options.h
some options
DB存储在块中，数据被压缩再存储。enum CompressionType声明压缩方法
控制db的行为，例如块数量，最大文件数等。

#### db.h
数据库操作功能
virtual Status Put(const WriteOptions& options, const Slice& key,
                     const Slice& value) = 0;
#### filter_policy.h
```
virtual void CreateFilter(const Slice* keys, int n,
                            std::string* dst) const = 0;
virtual bool KeyMayMatch(const Slice& key, const Slice& filter) const = 0;
```
Slice包含keys list, 通过comparator进行排序
通过Slice& filter对 Slice& key进行过滤

#### env.h
连接操作系统函数，例如filesystem.
virtual Status NewRandomAccessFile(const std::string& fname,
                                     RandomAccessFile** result) = 0;
Create an object supporting random-access reads from the file with the
specified name.  On success, stores a pointer to the new file in
*result and returns OK.  On failure stores nullptr in *result and
returns non-OK.




